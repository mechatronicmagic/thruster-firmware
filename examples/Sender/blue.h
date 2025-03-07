#ifndef __BLUE_H
#define __BLUE_H
#include <Arduino.h>
#include <bluefruit.h>


typedef struct __attribute__((packed)) {
  int8_t drives [3];
  uint8_t thrusters [7];
  int8_t spinners [3];
  uint8_t actions;
} ble_cmd_t;

void blue_init (void);
void blue_send (ble_cmd_t * data);

#endif // __BLUE_H
