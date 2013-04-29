

#include "SEAP.h"





using namespace test;
using namespace std;

int main(int argc, char *argv[]) {

TestSuite* test = new TestSuite();

//------------------------------------------------Test----------------------------//
//Test HAL
//********
test->test_Aktorik_Sensorik();

//Test IISR
//*********
//test->test_IISR();

/*

string quit;
Lampensteuerung *ampel;
ampel = new Lampensteuerung();
ampel->start(NULL);


    do{
    	cin >> quit;
    }while(quit != "q");

   // sens->shutdown();

    ampel->stop();
    ampel->join();

*/


	cout << " done." << endl;
return EXIT_SUCCESS;

}



