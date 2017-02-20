#include <stdio.h>
#include <stdlib.h>
#include <SPI.h>
#include <SD.h>
#include <weather_library.h>

void print_to_SD(int hour, int temp, int humidity){
  File dataFile = SD.open("results.txt", FILE_WRITE);
  if(dataFile){
    dataFile.print("Timme: ");
    dataFile.print(hour);
    dataFile.print(" | Temp: ");
    dataFile.print(temp);
    dataFile.print(" | Fuktighet: ");
    dataFile.println(humidity);
    dataFile.close();
  }
  else
    Serial.println("error opening the file.");
}

/*void send_to_print(int hour, int temp, int humidity){
  if(digitalRead(8)){
     for(int j=0;j<12;j++){
        Serial.print("Timme: ");
        Serial.print(space[j].timme);
        Serial.print(" | Temp: ");
        Serial.print(space[j].temp);
        Serial.print(" | Fuktighet: ");
        Serial.println(space[j].humidity);
        print_to_SD(space[j].timme,space[j].temp,space[j].humidity);
    }
  }
}*/
