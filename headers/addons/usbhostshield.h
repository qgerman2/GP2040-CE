#pragma once
#include "gpaddon.h"

class USBHostShield : public GPAddon {
public:
	virtual bool available();
	virtual void setup();
	virtual void preprocess() {};
	virtual void process();
	virtual std::string name() { return "USB Host Shield 2.0"; }
};
