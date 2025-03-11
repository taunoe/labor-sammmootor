/**
 * Arduino Uno
 * Stepper motor 17HS8401
 * Driver TB6600
 * 
 * Author: Tauno Erik
 * Started 20.02.2025
 * Edited  06.03.2025
 */
#include <Arduino.h>
//#include "TaunoStepperMotor.h"

#define CW  0 // clockwise
#define CCW 1 // counterclockwise

// BTN pins
const int BTN_RIGHT_PIN = 4;
const int BTN_LEFT_PIN = 5;

// Motor 1 pins
const int M1_PULSE_PIN = 2;
const int M1_DIRECTION_PIN = 3;
const int M1_SPEED = 500;  // Speed of the motor

// Motor 2 pins
const int M2_PULSE_PIN = 6;
const int M2_DIRECTION_PIN = 7;
const int M2_SPEED = 500;  // Speed of the motor


// Function prototypes
void run_steps(int dir, int steps, int speed, int pulse_pin, int direction_pin);
void run(int speed, int pulse_pin);

void setup()
{
  Serial.begin(9600);

  // Stepper motor pins
  pinMode(M1_PULSE_PIN, OUTPUT);
  pinMode(M1_DIRECTION_PIN, OUTPUT);
  pinMode(M2_PULSE_PIN, OUTPUT);
  pinMode(M2_DIRECTION_PIN, OUTPUT);

  // BTN pins
  pinMode(BTN_LEFT_PIN, INPUT);
  pinMode(BTN_RIGHT_PIN, INPUT);
}

void loop()
{
  // If Button LEFT is pressed (LOW because of pull-up)
  if (digitalRead(BTN_LEFT_PIN) == LOW)
  {
    Serial.println("left");

    //digitalWrite(M1_DIRECTION_PIN, CCW);
    //run(M1_SPEED, M1_PULSE_PIN);

    digitalWrite(M2_DIRECTION_PIN, CCW);
    run(M2_SPEED, M2_PULSE_PIN);
  }

  // If Button RIGHT is pressed (LOW because of pull-up)
  if (digitalRead(BTN_RIGHT_PIN) == LOW)
  {
    Serial.println("right");
    digitalWrite(M1_DIRECTION_PIN, CW);
    run(M1_SPEED, M1_PULSE_PIN);
    
    // See kood ei tööta samal ajal kui eelmine!!!
    //digitalWrite(M2_DIRECTION_PIN, CW);
    //run(M2_SPEED, M2_PULSE_PIN);
  }

  /*
  run_steps(CCW, 100, 500, M1_PULSE_PIN, M1_DIRECTION_PIN);
  delay(1000);
  run_steps(CW, 200, 500, M1_PULSE_PIN, M1_DIRECTION_PIN);
  delay(1000);
  */
}


/**********************************************************************
 * Run the stepper motor for a number of steps
 * @param dir   Direction (CW or CCW)
 * @param steps Number of steps
 * @param speed Speed of the motor
 **********************************************************************/

void run_steps(int dir, int steps, int speed, int pulse_pin, int direction_pin)
{
  digitalWrite(direction_pin, dir);  // Set direction

  for (int i = 0; i < steps; i++)
  {
    digitalWrite(pulse_pin, HIGH);
    delayMicroseconds(speed);  // Pulse width (adjust for speed)
    digitalWrite(pulse_pin, LOW);
    delayMicroseconds(speed);  // Delay between steps (adjust for speed)
  }
}


/**********************************************************************
 * Run the stepper motor forever until both buttons are unpressed
 * @param speed Speed of the motor
 **********************************************************************/
void run(int speed, int pulse_pin)
{
  while (true)
  {
    digitalWrite(pulse_pin, HIGH);
    delayMicroseconds(speed);  // Pulse width (adjust for speed)
    digitalWrite(pulse_pin, LOW);
    delayMicroseconds(speed);  // Delay between steps (adjust for speed)

    // Exit the loop if neither button is unpressed
    if (digitalRead(BTN_LEFT_PIN) == HIGH && digitalRead(BTN_RIGHT_PIN) == HIGH)
    {
      break;
    }
  }
}

