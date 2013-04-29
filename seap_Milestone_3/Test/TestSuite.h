/*
 * TestSuite.h
 *  Created on: 22.04.2013
 *      Author: H.Bani
 *
 */

#ifndef TESTSUITE_H_
#define TESTSUITE_H_

#include <Common/HAWThread.h>
#include <Common/HAWThread.cpp>

#include "Test/HAL/Test_ISR_PulseMsg.h"
#include "Test/HAL/Test_ISR_PulseMsg.cpp"
#include "Test/HAL/Test_Aktorik_Sensorik.h"
#include "Test/HAL/Test_Aktorik_Sensorik.cpp"
#include"Ampel/Lampensteuerung.h"
#include"Ampel/Lampensteuerung.cpp"

#include "HAL/IIS/PulseCode.h"
#include <HAL/Sensorik/HALSensorik.cpp>
#include"HAL/IIS/InputInterruptService.cpp"



//#include"Test/Synchronisation/CommunicationsTest.h"
//#include"Test/Synchronisation/CommunicationsTest.cpp"



//---------------Neu Controller



namespace test{
class TestSuite {
public:
	TestSuite();
	virtual ~TestSuite();
	void test_Aktorik_Sensorik(void);
	void test_IISR(void);
};}
#endif /* TESTSUITE_H_ */
