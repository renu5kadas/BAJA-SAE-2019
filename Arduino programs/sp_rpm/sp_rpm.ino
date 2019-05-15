#include "TM1637.h"
#define CLK 7
#define DIO 8
TM1637 tm1637(CLK, DIO);
double t1 = 0, t = 0, x, rps = 0, rpm = 0;
int flag = 0, speed1 = 0, speed2 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, c = 0, d = 0;
void setup()
{
  tm1637.init();
  tm1637.set(BRIGHTEST);
  attachInterrupt(2, ISR0, RISING);
  tm1637.display(2, 0);
  tm1637.display(3, 0);
  tm1637.display(0, 0);
  tm1637.display(1, 0);
  Serial.begin(9600);
}
void loop()
{
  if (millis() - t1 > 3000)
  {
    tm1637.display(2, 0);
    tm1637.display(3, 0);
  }
}
void ISR0()
{
  c = millis();
  if (c - d > 10)
  {
    ++flag;
    if (flag == 1)
    {
      t1 = millis();
    }
    if (flag == 2)
    {
      flag = 0;
      t = millis() - t1;
      x = t / 1000;
      rps = 1.0 / x;
      rpm = 60 * rps;
      Serial.println(rpm*8.45);
      speed1 = 0.1101 * rpm;
      s1 = speed1 / 10;
      s2 = speed1 % 10;
      if (s1 < 6)
      {
        tm1637.display(2, s1);
        tm1637.display(3, s2);
        if (speed1 > speed2)
        {
          speed2 = speed1;
          s3 = speed2 / 10;
          s4 = speed2 % 10;
          tm1637.display(0, s3);
          tm1637.display(1, s4);
        }
      }
    }
  }
  d = millis();
}

