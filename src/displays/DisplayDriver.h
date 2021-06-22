#ifndef DISPLAY_DRIVER
#define DISPLAY_DRIVER

class DisplayDriver
{

public:
    virtual void setupDisplay() = 0;
    virtual void loopDisplay() = 0;
    virtual void onTouch() = 0;

private:

protected:
};
#endif
