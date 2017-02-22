#include <stdlib.h>
#include <stdio.h>
#include <SD.h>    //Temperature and humidity sensor-library
#include <DS3231.h>    //Library for real-time-clock
#include <dht.h>
#include "library.h"
#define DHT11 2
#define Button 8
#define chipSelect 10
#define backlog 6
#define array_size 25

DS3231 rtc(SDA,SCL);
dht DHT;


weather space[array_size];

void setup() {
  Serial.begin(9600);
  pinMode(Button, INPUT);
  rtc.begin();

  // wait for serial port to connect. Needed for native USB port only
  while (!Serial) {
    Serial.println("Serial port connects");
  }
  // see if the card is present and can be initialized:
  Serial.print("Initializing SD card...");

  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
  space[12].temp = 26;
  space[12].measured_hour = 12;
  space[13].temp = 20;
  space[13].measured_hour = 13;
  space[14].temp = 21;
  space[14].measured_hour = 14;
  space[17].temp = 24;
  space[17].measured_hour = 17;
}


void loop() {

  for (int k=0;k<array_size;k++){ 
    Serial.print(space[k].measured_hour); 
    Serial.print(" --- "); 
    Serial.print(space[k].temp); 
    Serial.print(" --- "); 
    Serial.print(space[k].humidity); 
    Serial.println(" --- "); 
  } 
  
  int temp = DHT.read11(DHT11);
  //Transforms string of time to int, where only the hour is collected
  int new_hour = atoi(rtc.getTimeStr());
  
  static int i = 0;
  static int old_hour;

    /*Serial.print(" *** "); 
    Serial.print(i); 
    Serial.println(" *** "); */
  // If the hour variable has been changed, read new values
 if (new_hour<old_hour || new_hour>old_hour){
    space[new_hour].measured_hour = new_hour;
    old_hour = new_hour;
    space[new_hour].temp = DHT.temperature;
    space[new_hour].humidity = DHT.humidity;
    print_to_SD(space[new_hour].measured_hour, space[new_hour].temp, space[new_hour].humidity);
    i++;
  }

  // If button is pressed
  if (digitalRead(Button)){
    print_to_serial();
    Serial.println("----------------------");
  }

  print_high_temp(space, array_size); 
  
  delay(10000);
}
