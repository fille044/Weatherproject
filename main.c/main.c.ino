#include <SD.h>
#include <dht.h>
#include <DS3231.h>
#include <string.h>

#define DHT11 2
#include <weather_library.h>
/*typedef struct _weather_S{
  int temp, humidity, timme;
} weather;
weather space[100];*/

DS3231 rtc(SDA,SCL);
dht DHT;

int old_hour;
const byte chipSelect = 10;


void setup() {
  Serial.begin(9600);
  pinMode(8, INPUT);
  rtc.begin();
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
}

void loop() {
  int temp = DHT.read11(DHT11);

  int new_hour,i=0;
  new_hour = atoi(rtc.getTimeStr());
  
  if(new_hour!=old_hour){
    space[i].timme=new_hour;
    old_hour=new_hour;
    space[i].temp=DHT.temperature;
    space[i].humidity=DHT.humidity;
    i++;

    Serial.println(new_hour);
  }

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
  delay(500);
}
