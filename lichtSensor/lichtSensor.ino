
//Analoge pin waarop de ldr is bevestigd
int ldr = A11;


void setup() {

//Begint de console en stelt de pin in als input
  pinMode(ldr, INPUT);
  Serial.begin(9600);

}

void loop() {

  //Print de waarde van de ldr
Serial.println(analogRead(ldr));
delay(2000);

}
