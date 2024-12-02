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

  int a = GamePad.getAngle();
  int r = GamePad.getRadius();

  if ((a > 0 && a <= 90) && r > 1)
  {
    Serial.println("forward");
    digitalWrite(m1p1, HIGH);
    digitalWrite(m1p2, LOW);
    digitalWrite(m2p1, LOW);
    digitalWrite(m2p2, HIGH);
    analogWrite(ena, 255);
    analogWrite(enb, 255);
  }
  if ((a > 165 && a <= 270) && r > 1)
  {
    Serial.println("backward");
    digitalWrite(m1p1, LOW);
    digitalWrite(m1p2, HIGH);
    digitalWrite(m2p1, HIGH);
    digitalWrite(m2p2, LOW);
    analogWrite(ena, 255);
    analogWrite(enb, 255);
  }
  if ((a >= 0 && a <= 0) && r > 1)
  {
    Serial.println("right");
    digitalWrite(m1p1, LOW);
    digitalWrite(m1p2, HIGH);
    digitalWrite(m2p1, LOW);
    digitalWrite(m2p2, LOW);
    analogWrite(ena, 255);
    analogWrite(enb, 0);
  }
  if ((a > 90 && a <= 165) && r > 1)
  {
    Serial.println("left");
    digitalWrite(m1p1, LOW);
    digitalWrite(m1p2, LOW);
    digitalWrite(m2p1, HIGH);
    digitalWrite(m2p2, LOW);
    analogWrite(ena, 0);
    analogWrite(enb, 255);
  }
  else if (a == 0 && r == 0)
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
