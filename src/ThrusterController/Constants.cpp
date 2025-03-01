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

const PCA9685::Channel channel = 0;

const PCA9685::DurationMicroseconds servo_pulse_duration_min = 900;
const PCA9685::DurationMicroseconds servo_pulse_duration_max = 2100;
const PCA9685::DurationMicroseconds servo_pulse_duration_mid = 1500;
const PCA9685::DurationMicroseconds servo_pulse_duration_inc = 10;
}
