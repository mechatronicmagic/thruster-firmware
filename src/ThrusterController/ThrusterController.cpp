// ----------------------------------------------------------------------------
// ThrusterController.cpp
//
// Authors:
// Peter Polidoro peter@polidoro.io
// ----------------------------------------------------------------------------
#include "ThrusterController.hpp"
#include "Constants.hpp"


void ThrusterController::setup()
{
  pca9685_.setupSingleDevice(Wire, constants::device_address);
  pca9685_.setToServoFrequency();

  position_ = constants::position_mid;
  position_inc_ = constants::position_inc_default;

  pinMode(constants::stop_pin, INPUT);
}

void ThrusterController::update()
{
  if (digitalRead(constants::stop_pin))
  {
    for (PCA9685::Channel channel=constants::channel_min; channel<=constants::channel_max; ++channel)
    {
      setChannelServoPosition(channel, constants::position_mid);
    }
    position_ = constants::position_mid;
    position_inc_ = constants::position_inc_default;
    return;
  }
  if (position_ > constants::position_max_pos)
  {
    position_ = constants::position_max_pos;
    position_inc_ = -constants::position_inc_default;
  }
  else if (position_ < constants::position_max_neg)
  {
    position_ = constants::position_max_neg;
    position_inc_ = constants::position_inc_default;
  }
  for (PCA9685::Channel channel=constants::channel_min; channel<=constants::channel_max; ++channel)
  {
    if ((channel % 2) == 0)
    {
      setChannelServoPosition(channel, position_);
    }
    else
    {
      setChannelServoPosition(channel, -position_);
    }
  }
  position_ += position_inc_;

  delay(constants::loop_delay);
}

PCA9685::DurationMicroseconds ThrusterController::positionToServoPulseDuration(int16_t position)
{
  return position + (int16_t)constants::servo_pulse_duration_mid;
}

void ThrusterController::setChannelServoPosition(PCA9685::Channel channel, int16_t position)
{
  PCA9685::DurationMicroseconds servo_pulse_duration = positionToServoPulseDuration(position);
  pca9685_.setChannelServoPulseDuration(channel, servo_pulse_duration);
}
