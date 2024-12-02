#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>

String serial = "";
String terminal = "";
bool df = 0;

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

 if (Terminal.available())
  {
    while (Terminal.available() != 0)
    {
      Dabble.processInput();
      terminal = Terminal.readString();
      Serial.println(terminal);
      Terminal.println("received");
      
      if (terminal == "forward" || terminal == "Forward")
      {
         Dabble.processInput();
        Serial.println("forward");
        digitalWrite(m1p1, HIGH);
        digitalWrite(m1p2, LOW);
        digitalWrite(m2p1, LOW);
        digitalWrite(m2p2, HIGH);
        analogWrite(ena, 255);
        analogWrite(enb, 255);
        delay(2000);
      }
      if (terminal == "back" || terminal == "Back" )
      {
         Dabble.processInput();
        Serial.println("backward");
        digitalWrite(m1p1, LOW);
        digitalWrite(m1p2, HIGH);
        digitalWrite(m2p1, HIGH);
        digitalWrite(m2p2, LOW);
        analogWrite(ena, 255);
        analogWrite(enb, 255);
        delay(2000);
      }
      if (terminal == "right" || terminal == "Right" )
      {
        Serial.println("right");
        digitalWrite(m1p1, LOW);
        digitalWrite(m1p2, HIGH);
        digitalWrite(m2p1, LOW);
        digitalWrite(m2p2, LOW);
        analogWrite(ena, 255);
        analogWrite(enb, 0);
        delay(2000);
      }
      if (terminal == "left" || terminal == "Left")
      {
        Serial.println("left");
        digitalWrite(m1p1, LOW);
        digitalWrite(m1p2, LOW);
        digitalWrite(m2p1, HIGH);
        digitalWrite(m2p2, LOW);
        analogWrite(ena, 0);
        analogWrite(enb, 255);
        delay(2000);
      }
      if (terminal == "stop" || terminal == "Stop")
      {
        Serial.println("Stop");
        digitalWrite(m1p1, LOW);
        digitalWrite(m1p2, LOW);
        digitalWrite(m2p1, LOW);
        digitalWrite(m2p2, LOW);
        analogWrite(ena, 0);
        analogWrite(enb, 0);
      }
      terminal="";
      
    }
  }

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
