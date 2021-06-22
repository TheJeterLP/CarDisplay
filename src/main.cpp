/* PINOUT:

*   EGT SENSOR: 
      GND - GND
      VCC - 3.3V
      SCK - 12
       CS - 14
       SO - 27

    MPX4250AP Sensor:
      Vout - 34
      GND  - GND
      VCC  - 5V

    Big 3.5" ILI9488 Display:
      VCC - 3.3V
      GND - GND
      CS - 15
      RESET - 4
      DC - 2
      SDI - 23
      SCK - 18
      LED - not connected
      SDO - not connected
      T_CLK - not connected
      T_CS - 21
      T_DIN - 23
      T_DO - 19
      T_IRQ - not connected
*/

#include <Arduino.h>

//include Displays
#include <displays/DisplayDriver.h>
#include <displays/DisplayDriverBig.h>

DisplayDriver *driver;

void setup()
{
  Serial.begin(115200);
  Serial.println("initializing...");

  driver = new DisplayDriverBig();

  driver->setupDisplay();

  Serial.println("Initializing done!");
}

void loop()
{
  driver->loopDisplay();
}