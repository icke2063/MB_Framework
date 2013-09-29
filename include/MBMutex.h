/**
 * @file   MBMutex.h
 * @Author icke2063
 * @date   29.05.2013
 * @brief  Mutex Interface
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

#ifndef MBMUTEX_H_
#define MBMUTEX_H_

namespace icke2063 {
namespace MB_Framework {

class MBMutex {
public:
	MBMutex(){};
	virtual ~MBMutex(){};
};

} /* namespace MB_Framework */
} /* namespace icke2063 */
#endif /* MBMUTEX_H_ */
