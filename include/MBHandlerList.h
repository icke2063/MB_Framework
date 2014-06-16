/**
 * @file   MBHandlerList.h
 * @Author icke
 * @date   07.06.2013
 * @brief 	List of all common handler objects. So all slaves can reuse them.
 * 			Therefore the slave can check this list for the listed handler
 * 			objects and get the pointer value.
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

#ifndef MBHANDLERLIST_H_
#define MBHANDLERLIST_H_

#include <MB_Framework_config.h>

#include "stddef.h"
#include "stdint.h"
#include "list"

#ifdef MBHL_NS
#error "namespace constant 'MBHL_NS' already defined"
#endif

#ifndef ICKE2063_MBFRAMEWORK_NO_CPP11
	#include <memory>
	#include <mutex>
	#define MBHL_NS std
#else
	#include <boost/shared_ptr.hpp>
	#include <boost/scoped_ptr.hpp>
	#define MBHL_NS boost
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
	std::list<MBHL_NS::shared_ptr<MBHandlerInt> >			m_handlerlist;
	/**
	 * lock for handler list
	 */
	MBHL_NS::shared_ptr<MBHL_NS::mutex> 			m_handlerlist_lock;		// lock for slavelist

};

} /* namespace MB_Framework */
} /* namespace icke2063 */
#endif /* MBHANDLERLIST_H_ */
