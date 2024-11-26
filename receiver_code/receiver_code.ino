#include <esp_now.h>
#include <WiFi.h>

#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4
#define FORWARD_LEFT 5
#define FORWARD_RIGHT 6
#define BACKWARD_LEFT 7
#define BACKWARD_RIGHT 8
#define TURN_LEFT 9
#define TURN_RIGHT 10
#define STOP 0

#define BACK_RIGHT_MOTOR 0
#define BACK_LEFT_MOTOR 1
#define FRONT_RIGHT_MOTOR 2
#define FRONT_LEFT_MOTOR 3

struct MOTOR_PINS
{
  int pinIN1;
  int pinIN2;
  int pinEn; 
  int pwmSpeedChannel;
};

std::vector<MOTOR_PINS> motorPins = 
{
  {16, 17, 22, 4},  //BACK_RIGHT_MOTOR
  {18, 19, 23, 5},  //BACK_LEFT_MOTOR
  {26, 27, 14, 6},  //FRONT_RIGHT_MOTOR
  {33, 25, 32, 7},  //FRONT_LEFT_MOTOR   
};

#define MAX_MOTOR_SPEED 200

const int PWMFreq = 1000; /* 1 KHz */
const int PWMResolution = 8;

#define SIGNAL_TIMEOUT 1000  // This is signal timeout in milli seconds. We will reset the data if no signal
unsigned long lastRecvTime = 0;

struct PacketData
{
  byte xAxisValue;
  byte yAxisValue;
  byte zAxisValue;
};
PacketData receiverData;
