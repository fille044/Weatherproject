#include <dht.h>
#include <DS3231.h>
#include <string.h>

//#include "weather_library.h"

DS3231 rtc(SDA,SCL);
dht DHT;
#define DHT11 2

void setup() {
  Serial.begin(9600);
  rtc.begin();
}

void loop() {
  int temp = DHT.read11(DHT11);
  
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  Serial.print(rtc.getDateStr());
  Serial.print(" ");
  Serial.println(rtc.getTimeStr());
  
  Serial.print("TEMPERATURE: ");
  Serial.println(DHT.temperature);
  Serial.print("HUMIDITY: ");
  Serial.println(DHT.humidity);
  Serial.print("\n");

  int hour = atoi(rtc.getTimeStr());
  Serial.println(hour);

  delay(3000);

}
