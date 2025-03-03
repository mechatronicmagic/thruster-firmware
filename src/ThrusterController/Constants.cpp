// ----------------------------------------------------------------------------
// Constants.cpp
//
//
// Authors:
// Peter Polidoro peter@polidoro.io
// ----------------------------------------------------------------------------
#include "Constants.hpp"


namespace constants
{
const PCA9685::DeviceAddress device_address = 0x40;
const size_t stop_pin = 14;

const size_t loop_delay = 10;

const PCA9685::Channel channel_min = 0;
const PCA9685::Channel channel_max = 5;

const PCA9685::DurationMicroseconds servo_pulse_duration_min = 900;
const PCA9685::DurationMicroseconds servo_pulse_duration_max = 2100;
const PCA9685::DurationMicroseconds servo_pulse_duration_mid = 1500;

const int16_t position_max_neg = -600;
const int16_t position_max_pos = 600;
const int16_t position_mid = 0;
const int16_t position_inc_default = 12;
// const int16_t position_inc_default = 1;
// const int16_t position_inc_default = 120;
}
