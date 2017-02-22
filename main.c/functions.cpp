#include <stdio.h>
#include <stdlib.h>
#include <SPI.h>
#include <SD.h>
#include "library.h"

File dataFile;
// Prints the result to final_S.txt on SD-card
void print_to_SD(int measured_hour, int temp, int humidity){
  // Opens file in write-mode and prints
  dataFile = SD.open("final_S.txt", FILE_WRITE);
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
  dataFile = SD.open("final_S.txt");   // Opens up final_S.txt
  if (dataFile){
    Serial.println("Opening final_S.txt");
    while (dataFile.available()){
      Serial.write(dataFile.read());
    }
    dataFile.close();
  }
  else{
    Serial.println("Error reading from final_S.txt");
  }

}

void print_high_low_temp(weather* space, int array_size){ 
    int current, next, place_h, place_l;
    int temporary_h = 0; // initiates temporary_h to something unusually low
    int temporary_l = 100; // initiates temporary_l to something unusually high
    for (current = 0; current < array_size; current++) {
      //Compares the value of temp with the value in temporary
      if (space[current].temp > temporary_h) { 
        //  If the new value is higher than the last, save the new to 
        //  temporary and save the position in the array
          temporary_h =  space[current].temp; 
          place_h = current;
      }
      if (space[current].temp < temporary_l && space[current].temp > 0) { 
        //  If the new value is higher than the last, save the new to 
        //  temporary and save the position in the array
          temporary_l =  space[current].temp; 
          place_l = current;
      }
    }
    Serial.print("The highest temperature measured the last 24h is: "); 
    Serial.print(temporary_h); 
    Serial.print(" degrees at "); 
    Serial.println(space[place_h].measured_hour); 
    Serial.print("The lowest temperature measured the last 24h is: "); 
    Serial.print(temporary_l); 
    Serial.print(" degrees at "); 
    Serial.println(space[place_l].measured_hour); 
} 



