int flag1 = 0;
int flag2 = 0;
float t1 = 0;
float t2 = 0;
float t3 = 0;
void setup()
{
  Serial.begin(9600);
  attachInterrupt(0, ISR0, FALLING);
  attachInterrupt(1, ISR1, FALLING);
}

void loop()
{
  t3 = t2 - t1;
  Serial.print("t1=");
  Serial.println(t1);

  Serial.print("t2=");
  Serial.println(t2);
  Serial.print("t3=");
  Serial.println(t3);
  Serial.println("==========================");
}
void ISR0()
{
  if (flag1 == 0)
  {
    flag1 = 1;
    t1 = millis();
  }
}
void ISR1()
{
  if (flag2 == 0)
  {
    flag2 = 1;
    t2 = millis();
  }
}
