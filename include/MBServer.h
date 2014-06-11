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

#ifndef ICKE2063_MBFRAMEWORK_NO_CPP11
	#include <memory>
	#include <mutex>
	#define MBSERVER_H_NS std
#else
	#include <boost/shared_ptr.hpp>
	#include <boost/scoped_ptr.hpp>
	#include <boost/thread/mutex.hpp>
	#define MBSERVER_H_NS boost
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
	std::list<MBSERVER_H_NS::shared_ptr<MBConnection> > openConnections;

	/**
	 * lock for open connection list
	 */

#ifndef ICKE2063_MBFRAMEWORK_NO_CPP11
	std::unique_ptr<std::mutex> m_conn_lock;
#else
	boost::scoped_ptr<boost::mutex> m_conn_lock;
#endif
};

} /* namespace MB_Framework */
} /* namespace icke2063 */
#endif /* MBSERVER_H_ */
