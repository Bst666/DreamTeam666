/*
 * MUTEX.cpp
 *
 *  Created on: 22.04.2013
 *      Author: H.Bani
 */

#ifndef MUTEX_CPP_
#define MUTEX_CPP_
#include "MUTEX.h"

MUTEX::MUTEX() {
	pthread_mutex_init( &mutex, NULL);
}

MUTEX::~MUTEX() {
	pthread_mutex_destroy(&mutex);
}

void MUTEX::lock()const {
	pthread_mutex_lock((pthread_mutex_t*)&mutex);
}

void MUTEX::unlock()const {
	pthread_mutex_unlock((pthread_mutex_t*)&mutex);
}

#endif /* MUTEX_CPP_ */
