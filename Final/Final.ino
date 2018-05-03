

//Library voor het uitlezen van de time module (ds3231)
#include <DS3231.h>
DS3231  rtc(SDA, SCL);




char daysOfTheWeek[7][12] = {"Zondag", "Maandag", "Dinsdag", "Woensdag", "Donderdag", "Vrijdag", "Zaterdag"};


//Library voor de dht temperatuursensor 
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

//Library voor het aansturen van het LED matrix
#include <LedControl.h>


//Variabelen voor het opmeten van de vochtigheid
int moist;
int sensorMoist = A10;


//Variabelen voor de dht temperatuursensor
int dht22 = 22;
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(dht22, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

int chk;
float temp; //Stores temperature value

//Variabelen voor de ldr
int ldr = A11;
int ldrValue;



//Variabelen voor het LED matrix
int DIN = 26;
int CS =  28;
int CLK = 30;

byte c[8]=     {0x7E,0x7E,0x60,0x60,0x60,0x60,0x7E,0x7E};
byte eight[8]= {0x7E,0x7E,0x66,0x7E,0x7E,0x66,0x7E,0x7E};
byte s[8]=     {0x7E,0x7C,0x60,0x7C,0x3E,0x06,0x3E,0x7E};
byte dot[8]=   {0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18};
byte o[8]=     {0x7E,0x7E,0x66,0x66,0x66,0x66,0x7E,0x7E};

//Configureert het led matrix paneel
LedControl lc=LedControl(DIN,CLK,CS,0);
void setup() {

lc.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
 lc.setIntensity(0,15);      // Set the brightness to maximum value
 lc.clearDisplay(0);         // and clear the display

 //Begin voor de dht temperatuursensor
 dht.begin();
 Serial.begin(9600);


 pinMode(sensorMoist, INPUT);
 pinMode(ldr, INPUT);

 //Beginnen van time module
 rtc.begin();

 //Code om de datum en tijd in te stellen
 //rtc.setDOW(THURSDAY);     // Set Day-of-Week to SUNDAY
 // rtc.setTime(12, 14, 0);     // Set the time to 12:00:00 (24hr format)
 // rtc.setDate(03, 05, 2018);   // Set the date to January 1st, 2014

}

void loop() {


//Matrix voor het verdrietig gezicht
 byte verdrietig[8] = {

B00000000,
  B01000110,
  B00100110,
  B00100000,
  B00100000,
  B00100110,
  B01000110,
  B00000000
};

//Matrix voor het blij gezicht
    byte blij[8] = {

  B00000000,
  B00100110,
  B01000110,
  B01000000,
  B01000000,
  B01000110,
  B00100110,
  B00000000


};


    //Print het blije gezicht
    printByte(blij);
     



    //Leest de data uit van de dht temperatuursensor en plaatst deze in de variabelen

   
    temp= dht.readTemperature();
    
    //Print de waarden naar de console
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println(" Celsius");
    delay(2000); //Delay 2 sec.
    


    //Leest de waarden van de vochtigheid uit
      moist = analogRead(sensorMoist);
  Serial.println(moist);
  delay(2000);
Serial.println(rtc.getDateStr());
Serial.println(rtc.getTimeStr());


//Leest de waarden van de ldr uit
ldrValue = analogRead(ldr);
Serial.println(ldrValue);
  
}


//Methode voor het tekenen van het led matrix
void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}
