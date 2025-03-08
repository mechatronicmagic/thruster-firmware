// ----------------------------------------------------------------------------
// Constants.hpp
//
//
// Authors:
// Peter Polidoro peter@polidoro.io
// ----------------------------------------------------------------------------
#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP
#include <Arduino.h>
#include <PCA9685.h>


namespace constants
{
extern const PCA9685::DeviceAddress device_address;
extern const size_t stop_pin;

extern const size_t loop_delay;

extern const PCA9685::Channel channel_min;
extern const PCA9685::Channel channel_max;

extern const PCA9685::DurationMicroseconds servo_pulse_duration_min;
extern const PCA9685::DurationMicroseconds servo_pulse_duration_max;
extern const PCA9685::DurationMicroseconds servo_pulse_duration_mid;

extern const int16_t position_max_neg;
extern const int16_t position_max_pos;
extern const int16_t position_mid;

extern const int16_t position_inc_default;
extern const int16_t position_inc_min;
extern const int16_t position_inc_max;

extern const int16_t ble_speed_min;
extern const int16_t ble_speed_max;

extern const unsigned long ble_idle_duration_ms;
}
#endif
