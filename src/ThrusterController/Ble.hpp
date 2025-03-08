#ifndef __BLE_HPP
#define __BLE_HPP

#include <stdint.h>

typedef struct __attribute__((packed)) {
  int8_t drives [3];
  uint8_t thrusters [7];
  int8_t spinners [3];
  uint8_t actions;
} ble_cmd_t;

void ble_init (void);
ble_cmd_t ble_command (void);
unsigned long ble_command_timestamp (void);

#endif // __BLE_HPP
