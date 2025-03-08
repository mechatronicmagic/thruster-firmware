#include <Arduino.h>
#include <bluefruit.h>
#include "Ble.hpp"

#define BLE_MESSAGE_TYPE 0xDA

typedef struct __attribute__((packed)) {
  uint8_t length;
  uint8_t header;
  ble_cmd_t cmd;
} ble_packet_t;


ble_cmd_t volatile static _ble_command = {0};
unsigned long volatile static _ble_command_ms = 0;

void ble_scan_callback (ble_gap_evt_adv_report_t * report)
{
  if (
    (report->data.len > 1) &&
    (report->data.p_data[0] >= sizeof(ble_cmd_t) + 1) &&
    (report->data.p_data[1] == BLE_MESSAGE_TYPE)
  ) {
    memcpy((void *) &_ble_command, &report->data.p_data[2], sizeof(ble_cmd_t));
    _ble_command_ms = millis();
  }
  Bluefruit.Scanner.resume();
}


void ble_init (void)
{
  Bluefruit.begin(0, 1);
  Bluefruit.setTxPower(0);
  Bluefruit.autoConnLed(false);
  Bluefruit.Scanner.setRxCallback(ble_scan_callback);
  Bluefruit.Scanner.restartOnDisconnect(true);
  Bluefruit.Scanner.setInterval(3200, 3200); // units of 0.625 ms
  Bluefruit.Scanner.start(0);
}


ble_cmd_t ble_command (void)
{
  return * (ble_cmd_t *) &_ble_command;
}


unsigned long ble_command_timestamp (void) {
  return _ble_command_ms;
}
