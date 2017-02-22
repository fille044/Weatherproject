#include <stdio.h>
#include <stdlib.h>
#include <SPI.h>
#include <SD.h>
#include "library.h"

File dataFile;
// Prints the result to results.txt on SD-card
void print_to_SD(int measured_hour, int temp, int humidity){
  // Opens file in write-mode and prints
  dataFile = SD.open("final.txt", FILE_WRITE);
  if(dataFile){
    dataFile.print("Hour: ");
    dataFile.print(measured_hour);
    dataFile.print(" | Temp: ");
    dataFile.print(temp);
    dataFile.print(" | Humidity: ");
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
  dataFile = SD.open("final.txt");   // Opens up test.txt
  if (dataFile){
    Serial.println("Opening final.txt");
    while (dataFile.available()){
      Serial.write(dataFile.read());
    }
    dataFile.close();
  }
  else{
    Serial.println("Error reading from final.txt");
  }

}


void print_high_temp(weather* space, int array_size){ 
    int current, next, place;
    int temporary = space[0].temp; // initiates temporary with the first value of array
    for (current = 0; current < array_size; current++) {
      //Compares the value of temp with the value in temporary
      if (space[current].temp > temporary) { 
        //  If the new value is higher than the last, save the new to 
        //  temporary and save the position in the array
          temporary =  space[current].temp; 
          place = current;
      }
    }
    Serial.print("The highest temperature measured is: "); 
    Serial.print(temporary); 
    Serial.print(" degrees at "); 
    Serial.println(space[place].measured_hour); 
} 

