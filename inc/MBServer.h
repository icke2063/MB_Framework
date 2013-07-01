/**
 * @file   MBServer.h
 * @Author icke2063
 * @date   25.05.2013
 * @brief  Modbus Server class which has to be used as MBFunctor with MBTreadpool.
 * 		   Modbus Gateway app shall create a specialized object of this class on each
 * 		   listen port of a server application. The implementation of the functor_function
 * 		   shall be usedfor the modbus tcp accept handling.
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

#ifndef MBSERVER_H_
#define MBSERVER_H_

//std libs
#include <stdint.h>
#include <list>

#include <MBThreadPool.h>
#include <stddef.h>

namespace MB_Framework {

class MBServer : public MBFunctor{
public:
	/**
	 *
	 * @param pool: pointer to ThreadPool (for connection functors)
	 * @param port: modbus TCP listen port
	 */
	MBServer(MBThreadPool *pool,uint16_t port):p_pool(pool),m_port(port){}
	virtual ~MBServer(){};

protected:
	/**
	 * pointer to associated ThreadPool
	 */
	MBThreadPool *p_pool;

	/**
	 * port of modbus server
	 */
	uint16_t m_port;
};

} /* namespace MB_Framework */
#endif /* MBSERVER_H_ */
