#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>

int ena = 9;
int m1p1 = 4;
int m1p2 = 5;

int enb = 10;
int m2p1 = 6;
int m2p2 = 7;

void setup()
{
  Serial.begin(9600);
  Dabble.begin(9600);
}

void loop()
{
  Dabble.processInput();

  if (GamePad.isUpPressed())
  {
    Serial.println("forward");
    digitalWrite(m1p1, HIGH);
    digitalWrite(m1p2, LOW);
    digitalWrite(m2p1, LOW);
    digitalWrite(m2p2, HIGH);
    analogWrite(ena, 255);
    analogWrite(enb, 255);
  }
  if (GamePad.isDownPressed())
  {
    Serial.println("backward");
    digitalWrite(m1p1, LOW);
    digitalWrite(m1p2, HIGH);
    digitalWrite(m2p1, HIGH);
    digitalWrite(m2p2, LOW);
    analogWrite(ena, 255);
    analogWrite(enb, 255);
  }
  if (GamePad.isRightPressed())
  {
    Serial.println("right");
    digitalWrite(m1p1, LOW);
    digitalWrite(m1p2, HIGH);
    digitalWrite(m2p1, LOW);
    digitalWrite(m2p2, LOW);
    analogWrite(ena, 255);
    analogWrite(enb, 0);
  }
  if (GamePad.isLeftPressed())
  {
    Serial.println("left");
    digitalWrite(m1p1, LOW);
    digitalWrite(m1p2, LOW);
    digitalWrite(m2p1, HIGH);
    digitalWrite(m2p2, LOW);
    analogWrite(ena, 0);
    analogWrite(enb, 255);
  }
  else
  {
    Serial.println("stop");
    digitalWrite(m1p1, LOW);
    digitalWrite(m1p2, LOW);
    digitalWrite(m2p1, LOW);
    digitalWrite(m2p2, LOW);
    analogWrite(ena, 0);
    analogWrite(enb, 0);
  }
}
