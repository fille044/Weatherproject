#include <DS3231.h>


DS3231 rtc(SDA,SCL);

void setup() {
  Serial.begin(115200);

  rtc.begin();


  /*rtc.setDOW(THURSDAY);
  rtc.setTime(14, 39, 00);
  rtc.setDate(16,2,2017);*/
  
}

void loop() {
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");

  Serial.println(rtc.getDateStr());
  Serial.print(" ");
  
  
  Serial.println(rtc.getTimeStr());
  Serial.print(" -- ");
  delay(2000);

}
