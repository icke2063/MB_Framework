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

#ifndef ICKE2063_MBFRAMEWORK_NO_CPP11
	#include <memory>
	#define MBVIRTUALRTUSLAVE_H_NS std
#else
	#include <boost/shared_ptr.hpp>
	#define MBVIRTUALRTUSLAVE_H_NS boost
#endif

#include <MBHandlerInt.h>
#include <MBDatabase.h>

namespace icke2063 {
namespace MB_Framework {

class MBVirtualRTUSlave {
public:
	MBVirtualRTUSlave(uint8_t SlaveAddr):_SlaveAddr(SlaveAddr){}
	virtual ~MBVirtualRTUSlave(){};
	uint8_t getSlaveAddr(void){return _SlaveAddr;}
	virtual uint8_t getType( void ){return 0xFF;}

	MBVIRTUALRTUSLAVE_H_NS::shared_ptr<MB_Database> getDB(){return db;}

	/**
	 * In these lists are the handler objects stored which are called on each
	 * Modbus request. The handler are indexed by their register address. So the same
	 * handler object could be used for more than one register.
	 */

	std::map<uint16_t,MBVIRTUALRTUSLAVE_H_NS::shared_ptr<MBHandlerInt> > m_discrete_input_handlerlist;
	std::map<uint16_t,MBVIRTUALRTUSLAVE_H_NS::shared_ptr<MBHandlerInt> > m_coil_handlerlist;

	std::map<uint16_t,MBVIRTUALRTUSLAVE_H_NS::shared_ptr<MBHandlerInt> > m_input_handlerlist;
	std::map<uint16_t,MBVIRTUALRTUSLAVE_H_NS::shared_ptr<MBHandlerInt> > m_holding_handlerlist;

protected:
	/*
	 * Associated database object.
	 * This should be used if there is some data which has to be stored between
	 * the modbus/TCP requests. If the response is created on the fliy there is not
	 * used.
	 */
	MBVIRTUALRTUSLAVE_H_NS::shared_ptr<MB_Database> db;

private:
	/**
	 * Address of associated RTU slave
	 */
	uint8_t _SlaveAddr;
};

} /* namespace MB_Framework */
} /* namespace icke2063 */
#endif /* MBVIRTUALRTUSLAVE_H_ */
