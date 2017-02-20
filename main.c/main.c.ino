#include <stdlib.h>
#include <stdio.h>
#include <SD.h>    //Temperature and humidity sensor-library
#include <DS3231.h>    //Library for real-time-clock
#include <dht.h>
#include "library.h"
#define DHT11 2
#define Button 8
#define chipSelect 10
#define backlog 12
#define array_size 100

DS3231 rtc(SDA,SCL);
dht DHT;

int old_hour;
int i = 0;

typedef struct _weather_S{
  int temp;
  int humidity; 
  int measured_hour;
} weather;
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
}


void loop() {
  int temp = DHT.read11(DHT11);
  //Transforms string of time to int, where only the hour is collected
  int new_hour = atoi(rtc.getTimeStr());  

  // If the hour variable has been changed, read new values
  if (new_hour != old_hour){
    space[i].measured_hour = new_hour;
    old_hour = new_hour;
    space[i].temp = DHT.temperature;
    space[i].humidity = DHT.humidity;
    i++;
    Serial.println(new_hour);
  }

  // If button is pressed
  if (digitalRead(Button)){
    for (int j=0 ; j<backlog ; j++){  
      print_to_SD(space[j].measured_hour, space[j].temp, space[j].humidity); 
      print_to_serial(space[j].measured_hour, space[j].temp, space[j].humidity);
    }
  }

  print_high_temp(space);
  delay(2000);
}
