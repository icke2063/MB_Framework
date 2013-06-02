/**
 * @file   MBVirtualRTUSlave.h
 * @Author icke
 * @date   02.06.2013
 * @brief  virtual modbus rtu slave interface
 * 		   handlerlist shall hold for each used register the pointer to the associated
 * 		   handlerobject
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

#ifndef MBVIRTUALRTUSLAVE_H_
#define MBVIRTUALRTUSLAVE_H_

#include "stdint.h"
#include <map>
using namespace std;

#include <MBHandlerInt.h>

namespace MB_Framework {

class MBVirtualRTUSlave {
public:
	MBVirtualRTUSlave(uint8_t SlaveID):SlaveID(255){}
	virtual ~MBVirtualRTUSlave();
	uint8_t SlaveID;							// ID of associated RTU slave
	map<uint16_t,MBHandlerInt*> handlerlist;	// list of used handler addressed by mbregister

};

} /* namespace MB_Framework */
#endif /* MBVIRTUALRTUSLAVE_H_ */
