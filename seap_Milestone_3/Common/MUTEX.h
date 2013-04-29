/*
 * MUTEX.h
 *
 *  Created on: 22.04.2013
 *      Author: H.Bani
 */

#ifndef MUTEX_H_
#define MUTEX_H_

class MUTEX {
public:

	/**
	 * Init Mustex
	 */
	MUTEX();

	/**
	 * Destroy  Mutex
	 */
	virtual ~MUTEX();

	/**
	 * Lock Mutex
	 */
	virtual void lock() const;

	/**
	 * Unlock Mutex
	 */
	virtual void unlock() const;

	private:
		pthread_mutex_t mutex;
};

#endif /* MUTEX_H_ */
