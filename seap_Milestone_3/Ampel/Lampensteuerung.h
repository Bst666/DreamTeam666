/*
 * Lampensteuerung.h
 *
 *  Created on: 22.04.2013
 *      Author: H.Bani
*/

#ifndef LAMPENSTEUERUNG_H_
#define LAMPENSTEUERUNG_H_


#include <iostream>
#include <unistd.h>
#include "Common/HWaccess.h"
#include "Common/HAWThread.h"
#include "HAL/Aktorik/Ampel.h"



namespace thread {

class Lampensteuerung : public HAWThread {
public:
	  Lampensteuerung();
	  virtual ~Lampensteuerung();

	  virtual void execute(void*arg);
	  virtual void shutdown();
	  virtual void stop();
private:
	bool  running;
	int   period;
	int   action;
};
}
#endif /* LAMPENSTEUERUNG_H_ */
