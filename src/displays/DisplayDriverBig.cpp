#include <displays/DisplayDriverBig.h>

DisplayDriverBig::DisplayDriverBig(void)
{
}

void DisplayDriverBig::setupDisplay(void)
{
    Serial.println("DisplayDriverBig");
    egt = new EGT();
    boost = new Boost();

    target = boost;

    delay(10);
    tft.init();         /* TFT init */
    tft.setRotation(1); /* Landscape orientation */

    uint16_t calData[5] = {401, 3363, 395, 3315, 7};
    tft.setTouch(calData);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextFont(4);
    tft.setTextSize(5);
    tft.setTextDatum(MC_DATUM);
    tft.fillScreen(TFT_BLACK);
    print();
}

void DisplayDriverBig::loopDisplay(void)
{
    uint16_t x, y;
    if (tft.getTouch(&x, &y))
    {
        onTouch();
    }
    if (displayMode != target->getMode())
    {
        switch (displayMode)
        {
        case BOOST:
            target = boost;
            break;
        case EXHAUST_GAS:
            target = egt;
            break;
        default:
            Serial.println("Error switching sensors!");
            break;
        }
        tft.fillScreen(TFT_BLACK);
        print();
    }
    else
    {
        if (target->valueHasChanged())
        {
            print();
        }
    }
    delay(10);
}

void DisplayDriverBig::onTouch(void)
{
    switch (displayMode)
    {
    case BOOST:
        displayMode = EXHAUST_GAS;
        break;
    case EXHAUST_GAS:
        displayMode = BOOST;
        break;
    default:
        Serial.println("Error!");
        break;
    }
}

void DisplayDriverBig::print()
{
    tft.drawString(target->getName(), 240, 65);
    tft.drawString(target->getFormatedValue(), 240, 165);
    tft.drawString(target->getUnit(), 240, 265);
}
