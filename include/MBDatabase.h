/**
 * @file   MBDatabase.h
 * @Author icke
 * @date   29.07.2013
 * @brief 	This class is used to representate the Modbus typical
 * 			Database. Therefore here is a MB_DB_Storage itself and
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
#include <auto_ptr.h>
using namespace std;

//MB_Framework
#include "MBMutex.h"

namespace icke2063 {
namespace MB_Framework {

class MB_DB_Storage {
public:
	MB_DB_Storage();
	virtual ~MB_DB_Storage();
};

class MB_Database {
public:
	MB_Database(){
		initDB();
	}
	virtual ~MB_Database();

	MB_DB_Storage *getStorage(void){return _db_storage.get();}
	MBMutex* getLock(void){return _db_lock.get();}

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
	 * auto ptr to MBMutex Object (depends on implementation)
	 */
	auto_ptr<MBMutex> _db_lock;

	/**
	 * auto pointer to storage class (depends on implementation)
	 */
	auto_ptr<MB_DB_Storage> _db_storage;

};

} /* namespace MB_Framework */
} /* namespace icke2063 */
#endif /* MBDATABASE_H_ */
