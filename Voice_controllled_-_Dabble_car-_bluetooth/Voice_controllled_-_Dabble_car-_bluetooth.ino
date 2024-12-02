#define CUSTOM_SETTINGS
#define INCLUDE_TERMINAL_MODULE
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
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(m1p1, OUTPUT);
  pinMode(m1p2, OUTPUT);
  pinMode(m2p1, OUTPUT);
  pinMode(m2p2, OUTPUT);

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
}
