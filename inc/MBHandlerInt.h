/**
 * @file   MBHandlerInt.h
 * @Author icke2063
 * @date   02.06.2013
 * @brief  Handler Interface for modbus tcp requests. *
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

#ifndef MBHANDLERINT_H_
#define MBHANDLERINT_H_

namespace MB_Framework {

class MBHandlerInt {
public:
	MBHandlerInt(){};
	virtual ~MBHandlerInt(){};

	/**
	 * request handler function interface
	 * This function shall be called at each associated modbus request
	 * @return
	 */
	virtual int handleQuery() = 0;
};

} /* namespace MB_Framework */
#endif /* MBHANDLERINT_H_ */
