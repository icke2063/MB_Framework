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
#include <auto_ptr.h>
using namespace std;

#include <MBHandlerInt.h>
#include <MBDatabase.h>

namespace MB_Framework {

class MBVirtualRTUSlave {
public:
	MBVirtualRTUSlave(uint8_t SlaveAddr):_SlaveAddr(SlaveAddr){}
	virtual ~MBVirtualRTUSlave(){};
	uint8_t getSlaveAddr(void){return _SlaveAddr;}
	virtual uint8_t getType( void ){return 0xFF;}

	/**
	 * local list of used handler addressed by MB register
	 */
	map<uint16_t,MBHandlerInt*> *getInputHList(void){return &m_input_handlerlist;}
	map<uint16_t,MBHandlerInt*> *getHoldingHList(void){return &m_holding_handlerlist;}

protected:
	auto_ptr<MB_Database> db;
	map<uint16_t,MBHandlerInt*> m_input_handlerlist;
	map<uint16_t,MBHandlerInt*> m_holding_handlerlist;

private:
	/**
	 * Address of associated RTU slave
	 */
	uint8_t _SlaveAddr;
};

} /* namespace MB_Framework */
#endif /* MBVIRTUALRTUSLAVE_H_ */
