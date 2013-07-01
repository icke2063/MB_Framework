/**
 * @file   MBSlaveList.h
 * @Author icke
 * @date   02.06.2013
 * @brief  Simple interface class for the "MBVirtualRTUSlave"-list of this framework.
 * 		   In the implementation here all associated virtual slaves shall be stored in
 * 		   this global list.
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

#include "stdint.h"
#include "map"
using namespace std;

#include <MBVirtualRTUSlave.h>
#include <MBMutex.h>

namespace MB_Framework {

class MBSlaveList {
public:
	MBSlaveList(){};
	virtual ~MBSlaveList(){};


	/**
	 * map of virtual slave object pointers addressed by slaveID
	 */
	map<uint8_t,MBVirtualRTUSlave*> slavelist;
	/**
	 * lock for slavelist
	 */
	MBMutex* 						p_slavelist_lock;
};

} /* namespace MB_Framework */
#endif /* MBSLAVELIST_H_ */
