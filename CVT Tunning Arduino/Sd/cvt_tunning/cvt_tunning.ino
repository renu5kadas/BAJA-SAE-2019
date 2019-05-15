#include <SPI.h>
#include <SD.h>
const int chipSelect = 10;
double t1 = 0, t2 = 0, t = 0, x2, x1, tp = 0, ts = 0;
double rps1 = 0, rps2 = 0;
float rpm1 = 0, rpm2 = 0;
int flag = 0, flag1 = 0;
double dunit = 0;
void setup()
{
  Serial.begin(9600);
  attachInterrupt(0, PRM, RISING);
  attachInterrupt(3, ISR0, RISING);
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    return;
  }
  Serial.println("card initialized.");
}
void loop()
{
  File file = SD.open("data.csv", FILE_WRITE);
  file.print(rpm1);
  file.print(',');
  file.print(rpm2);
  file.print(',');
  file.print(dunit);
  file.print(',');
  file.println(t);
  file.close();
}
void PRM()
{
  flag++;
  if (flag == 1)
    tp = millis();
  if (flag == 2)
  {
    detachInterrupt(0);
    t = millis();
    t1 = t - tp;
    x1 = t1 / 1000;
    rps1 = 1.0 / x1;
    rpm1 = 60.0 * rps1;
    flag = 0;
    Serial.println(rpm1);
    attachInterrupt(0, PRM, RISING);
  }
}
void ISR0()
{
  flag1++;
  if (flag1 == 1)
    ts = millis();
  if (flag1 == 2)
  {
    detachInterrupt(3);
    t = millis();
    t2 = t - ts;
    x2 = t2 / 1000;
    rps2 = 1.0 / x2;
    rpm2 = 60.0 * rps2;
    flag1 = 0;
    dunit = dunit + 1.7907;
    attachInterrupt(3, ISR0, RISING);
  }
}

