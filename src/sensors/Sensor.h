#ifndef SENSOR
#define SENSOR

enum SensorMode
{
    BOOST,
    EXHAUST_GAS
};

class Sensor
{

public:
    virtual ~Sensor() = default;

    const SensorMode getMode()
    {
        return mode;
    }

    const String getUnit()
    {
        return unit;
    }

    const String getName()
    {
        return name;
    }
    const long getMinValue()
    {
        return min;
    }

    const long getMaxValue()
    {
        return max;
    }

    const float getScaling()
    {
        return scale;
    }

    float getDifference(float x, float y)
    {
        if (x > y)
        {
            return x - y;
        }
        else
        {
            return y - x;
        }
    }

    virtual String getFormatedValue() = 0;
    virtual float getValue() = 0;
    virtual boolean valueHasChanged() = 0;

private:
protected:
    virtual void setupSensor() = 0;

    String name;
    String unit;
    long min;
    long max;
    SensorMode mode;
    float scale;
};

#endif
