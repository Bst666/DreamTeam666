/*
 * TestSuite.cpp
 *  Created on: 22.04.2013
 *      Author: H.Bani
 */

#include "TestSuite.h"
using namespace thread;



using namespace hal;

namespace test{
TestSuite::TestSuite() {}
TestSuite::~TestSuite() {}

void TestSuite::test_Aktorik_Sensorik(){
	cout << "Aktorik & Sensorik Test" << endl;
	cout << "|---------------------|" << endl;
	Test_Aktorik_Sensorik aktSens;
	aktSens.start(NULL);
	cout << "Quitting...";
	aktSens.stop();
	aktSens.join();
}

void TestSuite::test_IISR(){
	cout << "IISR Test" << endl;
	cout << "|---------------------|" << endl;
	Test_ISR_PulseMsg* iisr = new Test_ISR_PulseMsg();
	iisr->start(NULL);
	string quit;

	iisr->stop();
	iisr->join();

}

}
