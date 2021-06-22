#include <sensors/Boost.h>

//public
Boost::Boost(void)
{
    mode = BOOST;
    name = String("Boost");
    unit = String("Bar");
    min = -80;
    max = 150;
    scale = 5;

    zero = -100;
    lastValue = -100000;
    setupSensor();
}

String Boost::getFormatedValue(void)
{
    String bar = String(getValue() / 100);

    unsigned int desiredLength = 5;
    String spaces = "";

    if (bar.length() < desiredLength)
    {
        int toAdd = desiredLength - bar.length();
        for (int i = 1; i <= toAdd; i++)
        {
            spaces += " ";
        }
    }

    return " " + spaces + bar + " ";
}

//return in kpa
float Boost::getValue(void)
{
    //in kPa
    float pressure = map(analogRead(34), 0.0, 4095, -80.0, 150.0);
    if (zero != -100)
    {
        if (zero > 0)
        {
            pressure += zero;
        }
        else
        {
            pressure -= zero;
        }
    }

    if (getDifference(lastValue, pressure) > scale)
    {
        lastValue = pressure;
        return pressure;
    }
    else
    {
        return lastValue;
    }
}

boolean Boost::valueHasChanged(void)
{
    return lastValue != getValue();
}

//private
void Boost::setupSensor(void)
{
    Serial.println("Setting up Boost sensor");

    pinMode(34, INPUT);

    zero = getValue();
    Serial.println("Zero:");
    Serial.println(zero);
}