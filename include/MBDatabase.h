/**
 * @file   MBDatabase.h
 * @Author icke
 * @date   29.07.2013
 * @brief 	This class is used to representate the ModbusTCP typical
 * 			database. Therefore here is a MB_DB_Storage class itself and
 * 			a pointer to a lock mechanism (to make the application
 * 			thread save)
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

#ifndef MBDATABASE_H_
#define MBDATABASE_H_

#include <stddef.h>

#if defined(__GXX_EXPERIMENTAL_CXX0X__) || (__cplusplus >= 201103L)
  #include <memory>
  #include <mutex>
  using namespace std;
#else
	#include <boost/shared_ptr.hpp>
	#include <boost/scoped_ptr.hpp>
	#include <boost/thread/mutex.hpp>
  	using namespace boost;
#endif

namespace icke2063 {
namespace MB_Framework {

/**
 * Storage object for Database. Here should be the storage implementation
 * located.
 */
class MB_DB_Storage {
public:
	MB_DB_Storage(){};
	virtual ~MB_DB_Storage(){};
};

class MB_Database {
public:
	MB_Database(){
		initDB();
	}
	virtual ~MB_Database(){};

	MB_DB_Storage *getStorage(void){return _db_storage.get();}
	shared_ptr<mutex> getLock(void){return _db_lock;}

	/**
	 * lock database until unlock function is called or block until current lock is cleared
	 */
	virtual void lockDB(){}

	/**
	 * unlock database access
	 */
	virtual void unlockDB(){}

protected:
	/**
	 * initialize DB
	 * - should add reference to storage object
	 * - should add reference to lock object
	 */
	virtual void initDB( void ){};

	/**
	 * ptr to MBMutex Object (depends on implementation)
	 *
	 */
	shared_ptr<mutex> _db_lock;

	/**
	 * pointer to storage object (depends on implementation)
	 */
#if defined(__GXX_EXPERIMENTAL_CXX0X__) || (__cplusplus >= 201103L)
	unique_ptr<MB_DB_Storage> _db_storage;
#else
	scoped_ptr<MB_DB_Storage> _db_storage;
#endif



};

} /* namespace MB_Framework */
} /* namespace icke2063 */
#endif /* MBDATABASE_H_ */
