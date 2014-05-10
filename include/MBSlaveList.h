/**
 * @file   MBSlaveList.h
 * @Author icke
 * @date   02.06.2013
 * @brief  Simple interface class for the "MBVirtualRTUSlave"-list of this framework.
 * 		   In the implementation here all associated virtual slaves shall be stored in
 * 		   this global list -> e.g. use Singleton
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

#ifndef MBSLAVELIST_H_
#define MBSLAVELIST_H_

#include "stddef.h"
#include "stdint.h"
#include "map"

#if defined(__GXX_EXPERIMENTAL_CXX0X__) || (__cplusplus >= 201103L)
  #include <memory>
  #include <mutex>
  using namespace std;
#else
  #include <boost/shared_ptr.hpp>
  #include <boost/thread/mutex.hpp>
  using namespace boost;
#endif

#include <MBVirtualRTUSlave.h>

namespace icke2063 {
namespace MB_Framework {

class MBSlaveList {
public:
	MBSlaveList(){}
	virtual ~MBSlaveList(){};

	/**
	 * Add new slave object to internal list
	 * @param newSlave:	pointer to slave object
	 */
	virtual bool addSlave(shared_ptr<MBVirtualRTUSlave> newSlave) = 0;

	/**
	 * Remove slave object from internal list
	 * @param index:	index of slave to remove
	 * @return	pointer of removed object
	 */
	virtual shared_ptr<MBVirtualRTUSlave> removeSlave(uint8_t index) = 0;

	/**
	 * Remove all slave object from internal list
	 */
	void removeAllSlaves(){
		lock_guard<mutex> lock(*m_slavelist_lock.get()); //lock isMBSlaveList
		m_slavelist.clear();
	}

	/**
	 * Get pointer to slave object from internal list
	 * @param index:	index of requested slave
	 * @return			pointer to slave object
	 */
	virtual shared_ptr<MBVirtualRTUSlave> getSlave(uint8_t index) = 0;

	/**
	 * Get pointer to whole slavelist
	 * @return
	 */
	virtual map<uint8_t,shared_ptr<MBVirtualRTUSlave> > *getList( void ){return &m_slavelist;}
	

protected:
	/**
	 * map of virtual slave object pointers addressed by slaveID
	 */
	map<uint8_t,shared_ptr<MBVirtualRTUSlave> > m_slavelist;
	typedef map<uint8_t, shared_ptr<MBVirtualRTUSlave> >::iterator m_slavelist_it;
	
	/**
	 * lock for slavelist
	 */
	shared_ptr<mutex> 						m_slavelist_lock;
};

} /* namespace MB_Framework */
} /* namespace icke2063 */
#endif /* MBSLAVELIST_H_ */
