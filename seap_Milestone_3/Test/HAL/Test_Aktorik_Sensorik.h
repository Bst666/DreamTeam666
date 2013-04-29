/*
 * Test_Aktorik_Sensorik.h
 *
 *  Created on: 22.04.2013
 *      Author: H.Bani
*/

#ifndef TEST_AKTORIK_SENSORIK_H_
#define TEST_AKTORIK_SENSORIK_H_


#include <unistd.h>
#include "Common/HWaccess.h"
#include "Common/HAWThread.h"
#include "HAL/Aktorik/LEDS.cpp"
#include "HAL/Aktorik/Motor.cpp"
#include "HAL/Aktorik/Ampel.cpp"
#include "HAL/Aktorik/Weiche.cpp"

#include "HAL/Sensorik/Werkstueck_Position.cpp"
#include "HAL/Sensorik/Tasten_Sensor.cpp"
#include "HAL/Sensorik/Rutsche_Voll.cpp"
#include "HAL/Sensorik/Weiche_Position.cpp"
#include <HAL/Aktorik/HALAktorik.cpp>

namespace thread {
class Test_Aktorik_Sensorik: public HAWThread {
public:
	Test_Aktorik_Sensorik();
	virtual ~Test_Aktorik_Sensorik();
	virtual void execute(void*arg);
	virtual void shutdown();
};
}
#endif /* TEST_AKTORIK_SENSORIK_H_ */
