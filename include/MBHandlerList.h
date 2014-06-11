/**
 * @file   MBHandlerList.h
 * @Author icke
 * @date   07.06.2013
 * @brief 	List of all common handler objects. So all slaves can reuse them.
 * 			Therefore the slave can check this list for the listed handler
 * 			objects and get the pointer value.
 *
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

#ifndef MBHANDLERLIST_H_
#define MBHANDLERLIST_H_

#include "stddef.h"
#include "stdint.h"
#include "list"

#ifndef ICKE2063_MBFRAMEWORK_NO_CPP11
	#include <memory>
	#include <mutex>
	#define MBHANDLERLIST_H_NS std
#else
	#include <boost/shared_ptr.hpp>
	#include <boost/scoped_ptr.hpp>
	#define MBHANDLERLIST_H_NS boost
#endif

#include <MBHandlerInt.h>

namespace icke2063 {
namespace MB_Framework {

class MBHandlerList {
public:
	MBHandlerList(){}
	virtual ~MBHandlerList(){}

	/**
	 * list of known handler objects
	 */
	std::list<MBHANDLERLIST_H_NS::shared_ptr<MBHandlerInt> >			m_handlerlist;
	/**
	 * lock for handler list
	 */
#ifndef ICKE2063_MBFRAMEWORK_NO_CPP11
	std::unique_ptr<std::mutex> 			m_handlerlist_lock;		// lock for slavelist
#else
	boost::scoped_ptr<boost::mutex> 			m_handlerlist_lock;		// lock for slavelist
#endif
};

} /* namespace MB_Framework */
} /* namespace icke2063 */
#endif /* MBHANDLERLIST_H_ */
