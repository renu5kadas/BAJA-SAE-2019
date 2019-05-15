float t1 = 0, t10 = 0, t9 = 0, t = 0, x1 = 0, t7 = 0, x = 0, t8 = 0, c = 0, d = 0, e = 0, f = 0;
float  rps = 0, rps1 = 0,speed1=0;
int rpm = 0, rpm1 = 0;
int flag = 0, flag1 = 0;
double dunit = 0;
void setup()
{
  Serial.begin(9600);
  attachInterrupt(2, ISR0, RISING);
  attachInterrupt(3, ISR1, RISING);
}
void loop()
{
  if (t9 != t10)
  {
    Serial.print('<');
    Serial.print(rpm);
    Serial.print(',');
    Serial.print(rpm1);
    Serial.print(',');
    Serial.print(dunit);
    Serial.print(',');
    Serial.print(t10);
    Serial.print(',');
    Serial.print(speed1);
    Serial.println('>');
    t9 = t10;
  }
}
void ISR0()
{
  c = millis();
  if (c - d > 12)
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
    }
  }
  d = millis();
}
void ISR1()
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
      rpm1 = 60.0 * rps1 * 8.5;
      speed1=(rpm1/8.5)*0.111,
      dunit = dunit + 1.7907;
      flag1 = 0;
    }
  }
  f = millis();
}
