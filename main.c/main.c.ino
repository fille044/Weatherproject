#include <dht.h>
//#include "weather_library.h"

dht DHT;
#define DHT11 2

void setup() {
  Serial.begin(9600);
}

void loop() {
  int temp = DHT.read11(DHT11);
  Serial.print("TEMPERATURE: ");
  Serial.println(DHT.temperature);
  Serial.print("HUMIDITY: ");
  Serial.println(DHT.humidity);
  delay(3000);

}
