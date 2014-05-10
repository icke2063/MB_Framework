/**
 * @file   MBHandlerInt.h
 * @Author icke2063
 * @date   02.06.2013
 * @brief  Handler Interface for modbus tcp requests. *
 * Copyright © 2013 icke2063 <icke2063@gmail.com>
 *
 * Interface class for all Handler objects. Handler objects are used to
 * handle the data transfer of each addressable Modbus/TCP register in
 * each Slave DB. Each VirtualRTUSlave object must hold a mapping list
 * to connect these handler objects with the Modbus/TCP register.
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

#ifndef MBHANDLERINT_H_
#define MBHANDLERINT_H_
#include <stdint.h>

namespace icke2063 {
namespace MB_Framework {

/**
 *
 * @class Parameter object
 *
 * With this class it is possible to implement
 * individual parameter object with the same base type.
 * So it is referenceable within this framework.
 */
class MBHandlerParam {
public:
	MBHandlerParam() {}
	virtual ~MBHandlerParam() {}
};


/**
 * @class Handler Interface class
 *
 * Each access to a modbus register has to be handled by
 * a specific handler function. This class is the base interface
 * for all inherit handler objects.
 */
class MBHandlerInt {
public:
	MBHandlerInt() :
		enableReadInpReg(true),
		enableReadHolReg(true),
		enableWriteHolReg(true),
		enableWriteSHolReg(true),
		rstart(1), rstop(1){

	}
	virtual ~MBHandlerInt() {};


	/**
	 * This function shall be called at each associated modbus request which
	 * is associated to a read register function code.
	 *
	 * Read access has to collect all requested register data
	 * @return handled register count or 0 for error -> force modbus exception
	 */
	virtual int handleReadAccess(MBHandlerParam *param) = 0;

	/**
	 * This function shall be called at each associated modbus request which
	 * is associated to a write register function code.
	 *
	 * On Modbus function codes to write data it is important to check
	 * all requested register on whether it is allowed to write them.
	 * If one register is not allowed to write the whole request must be
	 * rejected.
	 *
	 * After all register been checked the used Modbus/TCP implementation
	 * can write the included data into the associated database.
	 * @param param parameter object (handler specific)
	 * @return count of positiv checked register or 0 on failure
	 */
	virtual int checkWriteAccess(MBHandlerParam *param) = 0;

	/**
	 * This function shall be called at each associated modbus request which
	 * is associated to a write register function code.
	 *
	 * Handle Modbus/TCP write requests
	 * @param param parameter object (handler specific)
	 * @return count of handled register
	 */
	virtual int handleWriteAccess(MBHandlerParam *param) = 0;

	/**
	 * @brief set range of associated handler area
	 * @param start	:	start register of associated area
	 * @param stop	:	stop register of associated area
	 * @return		:	if range settings useable -> true else false
	 */
	virtual bool setRange(uint16_t start, uint16_t stop) {
		if (stop >= start) {
			rstart = start;
			rstop = stop;
			return true;
		}
		return false;
	}

	/**
	 * @brief check if given address and count fit in current range
	 * @param address	:	start address of requested area
	 * @param count		:	requested register count
	 * @return			:
	 */
	virtual bool checkRange(uint16_t address, uint16_t count) {
		/* check range */
		if (address >= rstart && address <= rstop) {
			/* check count */
			if (count >= 1 && count <= (rstop - address + 1)) {
				return true;
			}
		}
		return false;
	}

	uint16_t getRStart(void){return rstart;}
	uint16_t getRStop(void){return rstop;}
protected:
	/**
	 * flag to enable read input register function code
	 * @def true
	 */
	bool enableReadInpReg;
	/**
	 * flag to enable read holding register function code
	 * @def true
	 */
	bool enableReadHolReg;
	/**
	 * flag to enable write holding register function code
	 * @def true
	 */
	bool enableWriteHolReg;
	/**
	 * flag to enable write single holding register function code
	 * @def true
	 */
	bool enableWriteSHolReg;

private:
	/**
	 * start of handler associated area
	 */
	uint16_t rstart;
	/**
	 * stop of handler associated area
	 */
	uint16_t rstop;
};

} /* namespace MB_Framework */
} /* namespace icke2063 */
#endif /* MBHANDLERINT_H_ */
