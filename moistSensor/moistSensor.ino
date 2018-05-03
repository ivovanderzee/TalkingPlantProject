//Variabelen voor de moistsensor
int moist;
int moistSensor = A10;

void setup() {
  
//Start de console
 Serial.begin(9600);


 pinMode(sensorMoist, INPUT);


}

void loop() {

moist = analogRead(moistSensor);
Serial.println(moist);

}
