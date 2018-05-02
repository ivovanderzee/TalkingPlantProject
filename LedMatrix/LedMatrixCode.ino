//Bibliotheek voor het aansturen van het LED matrix
#include <LedControl.h>



//Variabelen voor het LED matrix
int DIN = 26;
int CS =  28;
int CLK = 30;

byte c[8]=     {0x7E,0x7E,0x60,0x60,0x60,0x60,0x7E,0x7E};
byte eight[8]= {0x7E,0x7E,0x66,0x7E,0x7E,0x66,0x7E,0x7E};
byte s[8]=     {0x7E,0x7C,0x60,0x7C,0x3E,0x06,0x3E,0x7E};
byte dot[8]=   {0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18};
byte o[8]=     {0x7E,0x7E,0x66,0x66,0x66,0x66,0x7E,0x7E};


LedControl lc=LedControl(DIN,CLK,CS,0);
void setup() {

lc.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
 lc.setIntensity(0,15);      // Set the brightness to maximum value
 lc.clearDisplay(0);         // and clear the display

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


    
    printByte(blij);
     
   

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
