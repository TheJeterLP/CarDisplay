#include <sensors/EGT.h>

//public
EGT::EGT(void) : sensor(12, 14, 27)
{
    mode = EXHAUST_GAS;
    name = "EGT";
    unit = "°C";
    min = -50.0;
    max = 1200.0;
    scale = 5;
    lastValue = -1000;
    setupSensor();
}

String EGT::getFormatedValue(void)
{
    unsigned int desiredLength = 4;
    int value = getValue();
    String ret = String(value);
    String spaces = "";

    if (ret.length() < desiredLength)
    {
        int toAdd = desiredLength - ret.length();
        for (int i = 1; i <= toAdd; i++)
        {
            spaces += "0";
        }
    }

    return spaces + ret;
}

float EGT::getValue(void)
{
    int clear = sensor.readCelsius();
    if (getDifference(lastValue, clear) > scale)
    {
        lastValue = clear;
        return clear;
    }
    else
    {
        return lastValue;
    }
}

boolean EGT::valueHasChanged(void)
{
    return lastValue != getValue();
}

//private
void EGT::setupSensor(void)
{
    Serial.println("Setting up EGT sensor");
}