#include <stdio.h>
#include <stdlib.h>
#include <SPI.h>
#include <SD.h>
#include "library.h"

File dataFile;
// Prints the result to results.txt on SD-card
void print_to_SD(int measured_hour, int temp, int humidity){
  // Opens file in write-mode and prints
  dataFile = SD.open("test.txt", FILE_WRITE);
  if(dataFile){
    dataFile.print("Timme: ");
    dataFile.print(measured_hour);
    dataFile.print(" | Temp: ");
    dataFile.print(temp);
    dataFile.print(" | Fuktighet: ");
    dataFile.println(humidity);
    dataFile.println('\0');
    dataFile.close();
    return;
  }
  else
    Serial.println("error opening the file.");
}

// Prints the same text to serial monitor
void print_to_serial(void){
  dataFile = SD.open("test.txt");
  if (dataFile){
    Serial.println("Opening test.txt");
    while (dataFile.available()){
      Serial.write(dataFile.read());
    }
    dataFile.close();
  }
  else{
    Serial.println("Error reading from test.txt");
  }

}

int print_high_temp(int space){
  
}

