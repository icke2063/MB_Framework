/**
 * @file   MBDatabase.h
 * @Author icke2063
 * @date   29.07.2013
 * @brief  Framework for simple database.
 *
 * Detailed description of file.
 */

#ifndef MBDATABASE_H_
#define MBDATABASE_H_

#include <stddef.h>

#include <auto_ptr.h>
using namespace std;

//MB_Framework
#include <MBMutex.h>

namespace MB_Framework {

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

	/**
	 * initialize DB
	 * - add reference to storage object
	 * - add reference to lock object
	 */

	MB_DB_Storage *getStorage(void){return _db_storage.get();}
	MBMutex* getLock(void){return _db_lock.get();}

	/**
	 * lock database until unlock function is called or block until current lock is cleared
	 */
	virtual void lockDB() = 0;

	/**
	 * unlock database access
	 */
	virtual void unlockDB() = 0;

protected:

	virtual void initDB( void ){}

	/**
	 * auto ptr to Mutex Object
	 */
	auto_ptr<MBMutex> _db_lock;

	/**
	 * auto pointer to storage class (depends on implementation
	 */
	auto_ptr<MB_DB_Storage> _db_storage;

};

} /* namespace MB_Framework */
#endif /* MBDATABASE_H_ */
