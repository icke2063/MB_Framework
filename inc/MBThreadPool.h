/**
 * @file   MBThreadPool.h
 * @Author icke2063
 * @date   26.05.2013
 *
 * @brief  Framework for a "Threadpool". Therefore within this file the MBThreadPool, MBWorkerThread and MBFunctor
 * 		   classes are defined. The MBThreadpool shall be used to handle MBFunctor
 * 		   objects. These functors are handled by MBWorkerThreads.
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
///MBFunctor for MBThreadPool
/**
 * Inherit from this class then it can be added by MBThreadPool::addFunctor with an implementation
 * of the MBThreadPool class. This class has to implement the functor_function. All member functions and variables
 * are accesable by the functor_function. This function will be executed by the MBWorkerThreads
 * and after execution this object will be deleted. Make sure that this object is dynamically created and is
 * not referenced after adding to MBThreadPool.
 *
 * @todo make sure that it cannot declared as static variable
 */
class MBFunctor {
public:
	MBFunctor(){};
	virtual ~MBFunctor(){};
	/**
	 * Function called by MBWorkerThread
	 * @brief This function will be called by MBWorkerThread of MBThreadPool
	 */
	virtual void functor_function(void) = 0;
};

///WorkerThread of MBThreadPool
/**
 * The inherit objects of this class are used to get new Functors from functor_queue
 * and call their functor function.
 * The implementation has to create for each object of this class an own thread.
 */

enum worker_status{
	idle=0x00,
	running=0x01,
	finished=0x02
};
class MBWorkerThread {
public:
	MBWorkerThread(deque<MBFunctor *> *functor_queue, MBMutex *functor_lock):
		p_functor_queue(functor_queue),p_functor_lock(functor_lock),m_status(idle){};
	virtual ~MBWorkerThread(){};
	worker_status m_status;					//status of current thread

protected:
	deque<MBFunctor *> *p_functor_queue;	//pointer to queue of MBThreadPool functor list
	MBMutex *p_functor_lock;				//pointer to lock for MBThreadPool functor list

	/**
	 * Abstract function which has to be implemented and used with
	 * thread implementation. It has to get the next functor from functor queue and
	 * call the functor_function.
	 * After execution finished -> delete functor object
	 */
	virtual void thread_function (void) = 0;

};
///Abstract ThreadPool interface
class MBThreadPool {
public:
	MBThreadPool() :
			HighWatermark(1), LowWatermark(1) {
	}
	;
	virtual ~MBThreadPool(){};

	/**
	 * set low watermark
	 * @param low: low count of MBWorkerThreads
	 */
	void setLowWatermark(uint8_t low) {
		LowWatermark =
				((low < HighWatermark)) ? low : HighWatermark;
	}
	/**
	 * get low count of WorkerThreads
	 * @return lowWatermark
	 */
	uint8_t getLowWatermark(void){return LowWatermark;}

	/**
	 * set high watermark
	 * @param high: high count of MBWorkerThreads
	 */
	void setHighWatermark(uint8_t high){
		HighWatermark =
				((high > LowWatermark) && (high < MBTHREADPOOL_MAX)) ? high : MBTHREADPOOL_MAX;
	}

	/**
	 * Get high count of WorkerThreads
	 * @return highWatermark
	 */
	uint8_t getHighWatermark(void){return HighWatermark;}

	/**
	 * 	This function is used to create needed MBWorkerThreads
	 * 	and to destroy (really) not needed MBWorkerThreads.
	 * 	MUST be implemented by inherit class
	 */
	virtual void scheduler(void) = 0;

	/**
	 * 	Add new functor to queue
	 * 	this function MUST be implemented by inherit class
	 * 	IMPORTANT: don't forget to lock the queue with Mutex (depends on implementation)
	 * @param work
	 */
	virtual void addFunctor(MBFunctor *work) = 0;

protected:
	///list of used MBWorkerThreads
	set<MBWorkerThread *> 	m_workerThreads;

	///lock worker queue
	MBMutex* 				p_worker_lock;

	///list of waiting functors
	deque<MBFunctor *> 		m_functor_queue;

	///lock functor queue
	MBMutex*				p_functor_lock;

private:
	uint8_t LowWatermark;	//low count of worker threads
	uint8_t HighWatermark;	//high count of worker threads
};

} /* namespace MB_Framework */
#endif /* MBTHREADPOOL_H_ */
