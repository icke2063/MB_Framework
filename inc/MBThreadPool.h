/**
 * @file   MBThreadPool.h
 * @Author icke
 * @date   26.05.2013
 * @brief  Framework for Threadpool. Therefore within this file the MBThreadPool and MBFunctor
 * 		   class is defined. The MBThreadpool shall be used to handle MBFunctor
 * 		   objects.
 * 		   The inherit class has to define the abstract functions with own or external thread
 * 		   implementations (e.g. boost).
 *
 * Copyright © 2013 icke2063 <icke2063@gmail.com>
 *
 * This framework is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This framework is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef MBTHREADPOOL_H_
#define MBTHREADPOOL_H_

#ifndef MBTHREADPOOL_MAX
	#define MBTHREADPOOL_MAX	40
#endif

//std libs
#include <stdint.h>
#include <deque>
#include <set>
using namespace std;

//MB_Framework
#include <MBMutex.h>

namespace MB_Framework {

/**
 * @class Functor class for MBThreadPool
 * inherit class has to implement runable function
 */

class MBFunctor {
public:
	MBFunctor(){};
	virtual ~MBFunctor(){};
	/**
	 * functor function which shall called by Thread
	 */
	virtual void functor_function(void) = 0;
};


class MBWorkerThread {
public:
	MBWorkerThread(){};
	virtual ~MBWorkerThread(){};

};
class MBThreadPool {
public:
	MBThreadPool() :
			HighWatermark(1), LowWatermark(1) {
	}
	;
	virtual ~MBThreadPool(){};

	void setLowWatermark(uint8_t low) {
		LowWatermark =
				((low > 0) && (low < HighWatermark)) ? low : LowWatermark;
	}
	uint8_t getLowWatermark(void){return LowWatermark;}

	void setHighWatermark(uint8_t high){
		HighWatermark =
				((high > LowWatermark) && (high < MBTHREADPOOL_MAX)) ? high : HighWatermark;
	}
	uint8_t getHighWatermark(void){return HighWatermark;}
	virtual void scheduler(void) = 0;
	virtual void addFunctor(MBFunctor *work) = 0;

protected:
	set<MBWorkerThread *> 	m_workerThreads;
	MBMutex* 			p_worker_lock;

	deque<MBFunctor *> 	m_functor_queue;
	MBMutex*			p_functor_lock;

private:
	uint8_t HighWatermark;
	uint8_t LowWatermark;

};

} /* namespace MB_Framework */
#endif /* MBTHREADPOOL_H_ */
