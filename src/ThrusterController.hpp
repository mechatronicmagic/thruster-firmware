// ----------------------------------------------------------------------------
// ThrusterController.hpp
//
// Authors:
// Peter Polidoro peter@polidoro.io
// ----------------------------------------------------------------------------

#ifndef THRUSTER_CONTROLLER_HPP
#define THRUSTER_CONTROLLER_HPP
#include <Arduino.h>
#include <PCA9685.h>


class ThrusterController
{
public:
  void setup();
  void update();
private:
  PCA9685 pca9685_;
  PCA9685::DurationMicroseconds servo_pulse_duration_;
  int16_t servo_pulse_duration_inc_;
};

#endif
