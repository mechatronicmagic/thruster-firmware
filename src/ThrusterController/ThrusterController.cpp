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

  servo_pulse_duration_ = constants::servo_pulse_duration_mid;
  servo_pulse_duration_inc_ = constants::servo_pulse_duration_inc;

  pinMode(constants::stop_pin, INPUT);
}

void ThrusterController::update()
{
  if (digitalRead(constants::stop_pin))
  {
    pca9685_.setChannelServoPulseDuration(constants::channel, constants::servo_pulse_duration_mid);
    servo_pulse_duration_ = constants::servo_pulse_duration_mid;
    servo_pulse_duration_inc_ = constants::servo_pulse_duration_inc;
    return;
  }
  if (servo_pulse_duration_ > constants::servo_pulse_duration_max)
  {
    servo_pulse_duration_ = constants::servo_pulse_duration_max;
    servo_pulse_duration_inc_ = -constants::servo_pulse_duration_inc;
  }
  else if (servo_pulse_duration_ < constants::servo_pulse_duration_min)
  {
    servo_pulse_duration_ = constants::servo_pulse_duration_min;
    servo_pulse_duration_inc_ = constants::servo_pulse_duration_inc;
  }
  pca9685_.setChannelServoPulseDuration(constants::channel, servo_pulse_duration_);
  servo_pulse_duration_ += servo_pulse_duration_inc_;

  delay(constants::loop_delay);
}
