/*
 * Test_ISR_PulseMsg.h

#ifndef TEST_ISR_PULSEMSG_H_
#define TEST_ISR_PULSEMSG_H_

#include "Common/HWaccess.h"
#include "Common/HAWThread.h"
#include "HAL/IIS/PulseCode.h"

namespace thread {
class Test_ISR_PulseMsg: public HAWThread {
public:
	Test_ISR_PulseMsg();
	virtual ~Test_ISR_PulseMsg();
	int getInputInterruptChannelID_DISPATCH();
	virtual void execute(void*arg);
	virtual void shutdown();

};
}
#endif /* TEST_ISR_PULSEMSG_H_ */