/*
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4 (for MKRZero SD: SDCARD_SS_PIN)
*/
#include <SPI.h>
#include <SD.h>
const int chipSelect = 4;
void setup() {
  SD.begin(chipSelect);
}
void loop() {
  File dataFile = SD.open("dat.csv", FILE_WRITE);
  dataFile.print("1234");
  dataFile.print(",");
  dataFile.println("5674");
  dataFile.close();
}









