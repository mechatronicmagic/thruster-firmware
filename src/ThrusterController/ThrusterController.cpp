// ----------------------------------------------------------------------------
// ThrusterController.cpp
//
// Authors:
// Peter Polidoro peter@polidoro.io
// ----------------------------------------------------------------------------
#include "ThrusterController.hpp"
#include "Constants.hpp"
#include "Ble.hpp"


void ThrusterController::setup()
{
  pca9685_.setupSingleDevice(Wire, constants::device_address);
  pca9685_.setToServoFrequency();

  position_ = constants::position_mid;
  position_inc_ = constants::position_inc_default;
  position_inc_sign_ = 1;

  pinMode(constants::stop_pin, INPUT);

  ble_init();
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
    position_inc_sign_ = 1;
    return;
  }
  if (position_ > constants::position_max_pos)
  {
    position_ = constants::position_max_pos;
    position_inc_sign_ = -1;
  }
  else if (position_ < constants::position_max_neg)
  {
    position_ = constants::position_max_neg;
    position_inc_sign_ = 1;
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

  // check for ble command
  unsigned long ble_cmd_timestamp = ble_command_timestamp();
  unsigned long time_now = millis();
  if (time_now < (ble_cmd_timestamp + constants::ble_idle_duration_ms))
  {
    ble_cmd_t ble_cmd = ble_command();
    int16_t ble_speed = ble_cmd.thrusters[0];
    position_inc_ = map(ble_speed,
      constants::ble_speed_min,
      constants::ble_speed_max,
      constants::position_inc_min,
      constants::position_inc_max);
  }
  else
  {
    position_inc_ = constants::position_inc_default;
  }

  position_ += position_inc_ * position_inc_sign_;

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

long ThrusterController::map(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
