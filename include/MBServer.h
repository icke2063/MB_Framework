/**
 * @file   MBServer.h
 * @Author icke2063
 * @date   25.05.2013
 * @brief 	Modbus Server class which shall be used to create new MBConnections
 * 			and handle the already created ones. A big select or an own handlerclass
 * 			could be used (or whatever else ;-) )
 * 		  	Modbus Gateway app shall create a specialized object of this class on each
 * 		  	listen port of a server application.
 *
 * Namespace switching: see README.md
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

#include <MB_Framework_config.h>

//std libs
#include <stdint.h>
#include <list>

#ifdef MBSRV_NS
#error "namespace constant 'MBSRV_NS' already defined"
#endif

#ifndef ICKE2063_MBFRAMEWORK_NO_CPP11
	#include <memory>
	#include <mutex>
	#define MBSRV_NS std
#else
	//c++03
	#include <auto_ptr.h>
	//boost
	#include <boost/shared_ptr.hpp>
	#include <boost/thread/mutex.hpp>
	#define MBSRV_NS boost
#endif

#include <stddef.h>

#include "MBConnection.h"

namespace icke2063 {
namespace MB_Framework {

class MBServer{
public:
	/**
	 *
	 * @param port: modbus TCP listen port(default: 502)
	 */
	MBServer(uint16_t port = 502):m_port(port){}
	virtual ~MBServer(){}

protected:
	/**
	 * port of modbus server
	 */
	uint16_t m_port;

	/**
	 * List of all open connections
	 */
	std::list<MBSRV_NS::shared_ptr<MBConnection> > openConnections;

	/**
	 * lock for open connection list
	 */
	std::auto_ptr<MBSRV_NS::mutex> m_conn_lock;

};

} /* namespace MB_Framework */
} /* namespace icke2063 */
#endif /* MBSERVER_H_ */
