#ifndef DISPLAY_DRIVER_BIG
#define DISPLAY_DRIVER_BIG

#include <Arduino.h>
//DisplayDriver
#include <displays/DisplayDriver.h>
//Sensors
#include <sensors/Sensor.h>
#include <sensors/EGT.h>
#include <sensors/Boost.h>
//display
#include "SPI.h"
#include <TFT_eSPI.h>

class DisplayDriverBig : public DisplayDriver
{

public:
	DisplayDriverBig(void);

	void setupDisplay(void);
	void loopDisplay(void);
	void onTouch(void);

protected:
	TFT_eSPI tft = TFT_eSPI();

private:
	Sensor *egt;
	Sensor *boost;
	Sensor *target;
	SensorMode displayMode = BOOST;
	int fontSize;

	void print();
};

#endif
