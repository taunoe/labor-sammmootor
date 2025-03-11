#ifndef TAUNOSTEPPERMOTOR_H
#define TAUNOSTEPPERMOTOR_H

#include <Arduino.h>

class TaunoStepperMotor
{
  private:
    int _pulse_pin;
    int _direction_pin;
    int _speed;

  public:
    // Constructor
    TaunoStepperMotor(int pulse_pin, int direction_pin, int speed);

    // Set the speed of the motor
    void set_speed(int speed);

    // Run the motor for a specific number of steps
    void run_steps(int dir, int steps, int speed);

    void set_direction(int dir);
    // Run the motor continuously
    void run();

    // Stop the motor
    void stop();

};

#endif
