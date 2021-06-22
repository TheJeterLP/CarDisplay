#ifndef SENSORS_BOOST
#define SENSORS_BOOST

#include <Arduino.h>

//Sensor
#include <sensors/Sensor.h>

class Boost : public Sensor
{

public:
    Boost(void);
    String getFormatedValue(void);
    float getValue(void);
    boolean valueHasChanged(void); 

private:
    void setupSensor(void);
    double zero;
    float lastValue;
};

#endif
