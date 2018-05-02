//Library voor de DHT temperatuursensor
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

 //Variabelen voor de dht temperatuursensor
int dht22 = 22;
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(dht22, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

int chk;
float temp; //Stores temperature value

void setup() {
  

//Begin voor de dht temperatuursensor
 dht.begin();
 Serial.begin(9600);

}

void loop() {


   //Leest de data uit van de dht temperatuursensor en plaatst deze in de variabelen
   
    temp= dht.readTemperature();
    
    //Print de waarden naar de console
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println(" Celsius");
    delay(2000); //Delay 2 sec.

}
