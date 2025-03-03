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
  int16_t position_;
  int16_t position_inc_;

  PCA9685::DurationMicroseconds positionToServoPulseDuration(int16_t position);
  void setChannelServoPosition(PCA9685::Channel channel, int16_t position);
};

#endif
