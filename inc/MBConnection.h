/**
 * @file   MBConnection.h
 * @Author icke2063
 * @date   26.05.2013
 * @brief  Modbus Connection class which has to be used as MBFunctor with MBTreadpool.
 * 		   Modbus Server shall create a specialized object of this class on each new accept
 * 		   of a client connection. The implementation of the functor_function shall be used
 * 		   for the modbus tcp request handling.
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
 *
 */

#ifndef MBCONNECTION_H_
#define MBCONNECTION_H_

#include <MBThreadPool.h>

namespace MB_Framework {

class MBConnection :public MB_Framework::MBFunctor{
public:
	MBConnection(){};
	virtual ~MBConnection(){};
};
} /* namespace MB_Framework */
#endif /* MBCONNECTION_H_ */
