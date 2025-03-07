#include <Arduino.h>
#include "pins.h"
#include "power.h"

const float voltage_sleep = 3.3;

void power_init (void)
{
  pinMode(LED_RED, OUTPUT);
  digitalWrite(LED_RED, HIGH);
  analogRead(BATT_PIN);
}

void power_shutdown (void)
{
  pinMode(LED_RED, INPUT);
  digitalWrite(TRELLIS_EN_PIN, LOW);
  digitalWrite(ANALOG_REF_PIN, LOW);
  pinMode(I2C_SDA_PIN, INPUT);
  pinMode(I2C_SCL_PIN, INPUT);
  sd_power_system_off();
}

void power_check (void)
{
  // battery voltage
  int adc_value = analogRead(BATT_PIN);
  const float adc_ref_voltage = 3.6;
  const float divider_gain = 2;
  const float adc_range = 1 << 10;
  float voltage = adc_value * divider_gain / adc_range * adc_ref_voltage;

  if (voltage < voltage_sleep)
    power_shutdown();
}