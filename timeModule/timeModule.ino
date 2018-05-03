//Library voor het uitlezen van de time module (ds3231)
#include <DS3231.h>
DS3231  rtc(SDA, SCL);

void setup() {

 //Beginnen van time module
 rtc.begin();
  Serial.begin(9600);
 //Code om de datum en tijd in te stellen
 //rtc.setDOW(THURSDAY);     // Set Day-of-Week to SUNDAY
 // rtc.setTime(12, 14, 0);     // Set the time to 12:00:00 (24hr format)
 // rtc.setDate(03, 05, 2018);   // Set the date to January 1st, 2014

}

void loop() {

  //Leest de waarden van de time module uit
Serial.println(rtc.getDateStr());
Serial.println(rtc.getTimeStr());

}
