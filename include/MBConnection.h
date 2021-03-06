/**
 * @file   MBConnection.h
 * @Author icke2063
 * @date   26.05.2013
 * @brief  Modbus Connection class which shall to be used with high performance communication
 * 		   implementation ;-).
 * 		   The Modbus Server shall create a specialized object of this class
 * 		   on each new accepted client connection.
 * 		   Every incoming Modbus/TCP packet has to be handled by this class. How
 * 		   this handling works depends on the implementation.
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

namespace icke2063 {
namespace MB_Framework {

class MBConnection{
public:
	enum conn_status{
		init = 0x00,
		open,
		wait,
		busy,
		closed
	};

public:
	MBConnection(){
		m_status = MBConnection::open;
	};
	virtual ~MBConnection(){};

	/**
	 * get current connection status
	 * @return
	 */
	enum conn_status getStatus( void ){return m_status;}

	/**
	 * Set connection status
	 * The connection status shows the connection handler what's going on within here.
	 * @return
	 */
	void setStatus(enum conn_status status){m_status = status;}

protected:
	/**
	 * Connection status member variable
	 */
	enum conn_status m_status;
};

} /* namespace MB_Framework */
} /* namespace icke2063 */
#endif /* MBCONNECTION_H_ */
