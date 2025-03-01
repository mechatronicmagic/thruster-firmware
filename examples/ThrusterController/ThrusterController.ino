#include <ThrusterController.hpp>


ThrusterController thruster_controller;

void setup()
{
  thruster_controller.setup();
}

void loop()
{
  thruster_controller.update();
}
