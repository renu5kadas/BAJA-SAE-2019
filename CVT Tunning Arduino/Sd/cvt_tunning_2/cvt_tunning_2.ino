#include <SPI.h>
#include <SD.h>
const int chipSelect = 10;
float t1 = 0, t10 = 0, t9 = 0, t = 0, x1 = 0, t7 = 0, x = 0, t8 = 0, c = 0, d = 0, e = 0, f = 0;
float  rps = 0, rps1 = 0;
float rpm = 0, rpm1 = 0;
int flag = 0, flag1 = 0;
double dunit = 0;
void setup()
{
  Serial.begin(74880);
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    return;
  }
  Serial.println("card initialized.");
  attachInterrupt(1, ISR0, RISING);
  //attachInterrupt(3, ISR1, RISING);
}
void loop()
{
  if (t9 != t10)
  {
    File file = SD.open("data.csv", FILE_WRITE);
    file.println(rpm);
    //file.print(',');
    //file.print(rpm1);
    //file.print(',');
    //file.print(dunit);
    //file.print(',');
    //file.println(t10);
    file.close();
    t9 = t10;
  }
}
void ISR0()
{
  c = millis();
  if (c - d > 9)
  {
    flag++;
    if (flag == 1)
    {
      t1 = millis();
    }
    if (flag == 2)
    {
      t10 = millis();
      t = t10 - t1;
      x = t / 1000;
      rps = 1 / x;
      rpm = 60.0 * rps;
      flag = 0;
      Serial.println(rpm);
    }
  }
  d = millis();
}
/*void ISR1()
{
  e = millis();
  if (e - f > 50)
  {
    flag1++;
    if (flag1 == 1)
    {
      t7 = millis();
    }
    if (flag1 == 2)
    {
      t10 = millis();
      t8 = t10 - t7;
      x1 = t8 / 1000;
      rps1 = 1 / x1;
      rpm1 = 60.0 * rps1;
      dunit = dunit + 1.7907;
      flag1 = 0;
    }
  }
  f = millis();
}*/
