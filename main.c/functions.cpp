#include <stdio.h>
#include <stdlib.h>
#include <SPI.h>
#include <SD.h>
#include "library.h"

// Prints the result to results.txt on SD-card
void print_to_SD(int measured_hour, int temp, int humidity){
  // Opens file in write-mode and prints
  File dataFile = SD.open("results.txt", FILE_WRITE);
  if(dataFile){
    dataFile.print("Timme: ");
    dataFile.print(measured_hour);
    dataFile.print(" | Temp: ");
    dataFile.print(temp);
    dataFile.print(" | Fuktighet: ");
    dataFile.println(humidity);
    dataFile.close();
  }
  else
    Serial.println("error opening the file.");
}

// Prints the same text to serial monitor
void print_to_serial(int measured_hour, int temp, int humidity){
  Serial.print("Timme: ");
  Serial.print(measured_hour);
  Serial.print(" | Temp: ");
  Serial.print(temp);
  Serial.print(" | Fuktighet: ");
  Serial.println(humidity);
}

int print_high_temp(int space){
  
}

