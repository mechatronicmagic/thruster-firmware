#include "blue.h"

#define BLE_MESSAGE_TYPE 0xDA

typedef struct __attribute__((packed)) {
  uint8_t length;
  uint8_t header;
  ble_cmd_t cmd;
} ble_packet_t;


void blue_init (void)
{
  ble_cmd_t empty_command = {0};

  Bluefruit.begin();
  Bluefruit.setTxPower(8);
  Bluefruit.autoConnLed(false);
  Bluefruit.Advertising.setType(BLE_GAP_ADV_TYPE_NONCONNECTABLE_SCANNABLE_UNDIRECTED);
  Bluefruit.Advertising.clearData();
  Bluefruit.Advertising.addData(BLE_MESSAGE_TYPE, &empty_command, sizeof(ble_cmd_t));
  Bluefruit.Advertising.restartOnDisconnect(true);
  Bluefruit.Advertising.setInterval(80, 80); // units of 0.625 ms
  Bluefruit.Advertising.start(0);
}


void blue_send (ble_cmd_t * data)
{
  Bluefruit.Advertising.clearData();
  Bluefruit.Advertising.addData(BLE_MESSAGE_TYPE, data, sizeof(ble_cmd_t));
}
