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

extern const PCA9685::Channel channel;

extern const PCA9685::DurationMicroseconds servo_pulse_duration_min;
extern const PCA9685::DurationMicroseconds servo_pulse_duration_max;
extern const PCA9685::DurationMicroseconds servo_pulse_duration_mid;
extern const PCA9685::DurationMicroseconds servo_pulse_duration_inc;
}
#endif
