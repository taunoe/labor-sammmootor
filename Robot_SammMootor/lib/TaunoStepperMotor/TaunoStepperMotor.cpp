#include "TaunoStepperMotor.h"

// Constructor
TaunoStepperMotor::TaunoStepperMotor(int pulse_pin, int direction_pin, int speed) {
  this->_pulse_pin = pulse_pin;
  this->_direction_pin = direction_pin;
  this->_speed = speed;

  // Set pin modes
  pinMode(this->_pulse_pin, OUTPUT);
  pinMode(this->_direction_pin, OUTPUT);
}

// Set the speed of the motor
void TaunoStepperMotor::set_speed(int speed) {
  this->_speed = speed;
}

// Run the motor for a specific number of steps
void TaunoStepperMotor::run_steps(int dir, int steps, int speed) {
  digitalWrite(this->_direction_pin, dir);  // Set direction

  for (int i = 0; i < steps; i++) {
    digitalWrite(this->_pulse_pin, HIGH);
    delayMicroseconds(this->_speed);  // Pulse width
    digitalWrite(this->_pulse_pin, LOW);
    delayMicroseconds(this->_speed);  // Delay between steps
  }
}

void TaunoStepperMotor::set_direction(int dir) {
  digitalWrite(this->_direction_pin, dir);  // Set direction
}

// Run the motor continuously
void TaunoStepperMotor::run() {

    digitalWrite(this->_pulse_pin, HIGH);
    delayMicroseconds(this->_speed);  // Pulse width
    digitalWrite(this->_pulse_pin, LOW);
    delayMicroseconds(this->_speed);  // Delay between steps

    // Exit the loop if a stop condition is met (e.g., button released)
    //if (digitalRead(BTN_LEFT) == HIGH && digitalRead(BTN_RIGHT) == HIGH) {
    //  break;
    //}
}

// Stop the motor
void TaunoStepperMotor::stop() {
  // Implement stopping logic if needed
}
