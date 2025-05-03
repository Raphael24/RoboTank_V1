#include <Arduino.h>
#include <BTS7960.h> // Include the BTS7960 header file
#include <PWMServo.h>

#include <LowpassFilter.h> // Include the LowpassFilter header file
#include <ledcontrol.h>    // Include the ledcontrol header file

#define M1_ENABLE 0
#define M1_RPWM 9
#define M1_LPWM 10

#define M2_ENABLE 0
#define M2_RPWM 4
#define M2_LPWM 5

BTS7960 M1_motorController(M1_ENABLE, M1_LPWM, M1_RPWM);
BTS7960 M2_motorController(M2_ENABLE, M2_LPWM, M2_RPWM);

PWMServo myservo; // create servo object to control a servo

int ach0, ach1, ach2, ach3, ach4, ach5, ach6, ach7;
int analogValue0, analogValue1, analogValue2, analogValue3;
int analogValue4, analogValue5, analogValue6, analogValue7;

float motorSpeed, steeringValue, leftMotorSpeed, rightMotorSpeed = 0.0f;
float RUDD = 0.0f; // Rudder value

LowpassFilter filter1;                       // Create an instance of the LowpassFilter class
const float PERIOD1 = 0.01;                  // Sampling period in seconds (10 ms)
const float LOWPASS_FILTER_FREQUENCY1 = 100; // Cutoff frequency in Hz

LowpassFilter filter2;                       // Create an instance of the LowpassFilter class
const float PERIOD2 = 0.01;                  // Sampling period in seconds (10 ms)
const float LOWPASS_FILTER_FREQUENCY2 = 100; // Cutoff frequency in Hz

// Funktionen definitionen
float mapWithHysteresis(int input); // Function prototype for mapWithHysteresis

// Lokale VAriablen
int initdone = 0;        // Variable to check if the setup is done
int deviceConnected = 0; // Variable to check if the device is connected

void setup()
{

  Serial.begin(9600);

  // Filter for Forward/Backward (THROW) and Left/Right (AILE)
  filter1.setPeriod(PERIOD1);
  filter1.setFrequency(LOWPASS_FILTER_FREQUENCY1);
  filter1.reset();

  // Filter for Left/Right (AILE)
  filter2.setPeriod(PERIOD2);
  filter2.setFrequency(LOWPASS_FILTER_FREQUENCY2);
  filter2.reset();

  // Enable the motor controller
  M1_motorController.Enable();
  M2_motorController.Enable();

  // Init Servo
  myservo.attach(13); // attaches the servo on pin 9 to the servo object
  myservo.write(90);
  delay(1000);

  // init LED's
  initled();

  delay(5000); // Warten bis die Verbindung hergestellt ist
  initdone = 1;


}

void loop()
{
  // put your main code here, to run repeatedly:
  // ach0 = pulseIn(A0, HIGH);
  while (mapWithHysteresis(pulseIn(A4, HIGH)) < 230)
  {
    // Wait until the RUDD value is above 230
    delay(100); // Add a small delay to avoid busy-waiting
    Serial.println("Wait for connection...");
  }

  Serial.println("Connected!");
  while (1)
  {

    ach1 = pulseIn(A1, HIGH);
    ach2 = pulseIn(A2, HIGH);
    ach3 = pulseIn(A3, HIGH);
    ach4 = pulseIn(A4, HIGH);
    ach5 = pulseIn(A5, HIGH);
    ach6 = pulseIn(A6, HIGH);

    // analogValue0 = map(ach0, 1000, 2000, -255, 255) - 23;
    analogValue1 = map(ach1, 1000, 2000, 0, 255) - 24;    // THROW = Vorwärts
    analogValue2 = map(ach2, 1000, 2000, -255, 255) - 15; // AILE = Rechts-Links
    analogValue3 = map(ach3, 1000, 2000, -255, 255) - 25; // ELEVE
    analogValue4 = map(ach4, 1000, 2000, -255, 255) - 38; // RUDD
    analogValue5 = map(ach5, 1100, 1900, 0, 1);           // GEAR = Gear control
    analogValue6 = map(ach6, 1100, 1900, 0, 1);           // AUX1 = LED control

    // convert the incoming date into suitable PWM value
    steeringValue = mapWithHysteresis(ach2);
    steeringValue = filter1.filter(steeringValue);

    motorSpeed = constrain(map(ach1, 1120, 1930, 0, 255), 0, 255);
    motorSpeed = filter2.filter(motorSpeed);

    RUDD = mapWithHysteresis(ach4);

    // check if Transmitter is connected
    // Serial.print(motorSpeed);
    Serial.print("RUDD");
    Serial.print(ach4);
    // Serial.print(" ");
    // Serial.print(analogValue3);
    Serial.print(" ");
    Serial.println(RUDD);
    // Serial.print(" ");
    // Serial.print(analogValue5);
    // Serial.print(" ");
    // Serial.println(analogValue6);

    if (RUDD >= 230)
    {
      deviceConnected = 1;
    }

    leftMotorSpeed = motorSpeed + steeringValue;
    rightMotorSpeed = motorSpeed - steeringValue;

    // Serial.print("steeringValue: ");
    // Serial.print(filter1.filter(steeringValue));
    // Serial.print(" ");
    // Serial.print(steeringValue);
    // Serial.print(" ");
    // Serial.print(ach2);
    // Serial.print(" motorSpeed: ");
    // Serial.print(motorSpeed);
    // Serial.print(" ");
    // Serial.print(filter2.filter(motorSpeed));
    // Serial.print(" ");
    // Serial.println(ach1);
    // Serial.print(" MotorSpeedLeft: ");
    // Serial.print(leftMotorSpeed);
    // Serial.print(" MotorSpeedRight: ");
    // Serial.println(rightMotorSpeed);

    if (leftMotorSpeed < 0)
    {
      M1_motorController.TurnLeft(abs(leftMotorSpeed)); // Set the motor to turn left with the filtered steering value
    }
    else if (leftMotorSpeed > 0)
    {
      M1_motorController.TurnRight(abs(leftMotorSpeed)); // Set the motor to turn right with the filtered steering value
    }
    else
    {
      M1_motorController.Stop(); // Stop the motor if the speed is zero
    }

    if (rightMotorSpeed < 0)
    {
      M2_motorController.TurnLeft(abs(rightMotorSpeed)); // Set the motor to turn left with the filtered steering value
    }
    else if (rightMotorSpeed > 0)
    {
      M2_motorController.TurnRight(abs(rightMotorSpeed)); // Set the motor to turn right with the filtered steering value
    }
    else
    {
      M2_motorController.Stop(); // Stop the motor if the speed is zero
    }

    //======= Gear shift ====
    if (abs(rightMotorSpeed) > 40 && abs(leftMotorSpeed) > 40)
    {
      if (analogValue5 == 0)
      {
        myservo.write(140);
      }
      if (analogValue5 == 1)
      {
        myservo.write(40);
      }
    }

    // LED control
    ledcontrol(analogValue6); // Call the ledcontrol function with the analog value for LED control
  }
}

float mapWithHysteresis(int input)
{
  if (input < 1490)
  {
    return constrain(map(input, 1230, 1490, -255, 0), -255, 0);
  }
  else if (input >= 1490 && input <= 1540)
  {
    return 0;
  }
  else
  {
    return constrain(map(input, 1540, 1850, 0, 255), 0, 255);
  }
}
