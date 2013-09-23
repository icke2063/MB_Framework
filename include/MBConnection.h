/**
 * @file   MBConnection.h
 * @Author icke2063
 * @date   26.05.2013
 * @brief  Modbus Connection class which shall to be used with high performance communication
 * 		   implementation.
 * 		   The Modbus Server shall create a specialized object of this class
 * 		   on each new accepted client connection.
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

namespace MB_Framework {

class MBConnection{
public:
	enum conn_status{
		init = 0x00,
		open,
		busy,
		closed
	};

public:
	MBConnection():m_status(init){};
	virtual ~MBConnection(){};

	enum conn_status getStatus( void ){return m_status;}
	void setStatus(enum conn_status status){m_status = status;}

protected:
	enum conn_status m_status;
};
} /* namespace MB_Framework */
#endif /* MBCONNECTION_H_ */
