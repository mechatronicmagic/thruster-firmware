#include <Arduino.h>
#include "pins.h"
#include "blue.h"
#include "power.h"


//#define __SERIAL

void setup ()
{
#ifdef __SERIAL
  Serial.begin(115200);
  while(!Serial) delay(10);
#endif

  power_init();
  blue_init();
}


void loop ()
{
  ble_cmd_t static data = {0};

  // set thruster speeds

  uint8_t thrust = 55;

  uint8_t static thruster_id = 7;

  switch (thruster_id) {
    case 0 ... 6:
    data.thrusters[thruster_id] = thrust;
    break;

    case 7:
    for (int i=0; i<7; i++)
      data.thrusters[i] = thrust;
    break;
  }

  blue_send(&data);

  power_check();

#ifdef __SERIAL
//  Serial.printBuffer((const uint8_t *) &data, sizeof(ble_cmd_t));
//  Serial.printf("\n");
//  Serial.printf("%.3f\n", analogRead(BATT_PIN) * 2.0f / (1<<10) * 3.6);
#endif

  delay(100);
}
