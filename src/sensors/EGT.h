#ifndef SENSORS_EGT
#define SENSORS_EGT

#include <Arduino.h>

//Sensor
#include <sensors/Sensor.h>
//Librarys
#include <max6675.h>

class EGT : public Sensor
{

public:
    EGT(void);
    String getFormatedValue(void);
    float getValue(void);
    boolean valueHasChanged(void);

private:
    void setupSensor(void);
    MAX6675 sensor;
    float lastValue;
};

#endif
