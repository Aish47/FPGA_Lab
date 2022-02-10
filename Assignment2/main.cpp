#include <Arduino.h>

// Seven segment numbers to display 0-7
const int num[8] = {0b1000000, 0b1111001, 0b0100100, 0b0110000, 0b0011001, 0b0010010, 0b0000010, 0b1111000};
// Input values
const int input[8] = {0b000, 0b001, 0b010, 0b011, 0b100, 0b101, 0b110, 0b111};

void setup() {                
// initialize the digital pins as outputs.
  pinMode(3, OUTPUT);     
  pinMode(4, OUTPUT);     
  pinMode(4, OUTPUT);     
  pinMode(5, OUTPUT);     
  pinMode(6, OUTPUT);     
  pinMode(7, OUTPUT);     
  pinMode(8, OUTPUT);   
  pinMode(9, OUTPUT);
  pinMode(12, OUTPUT);   

}



void loop() {
  int i, pin, a;
  //To loop through all possible inputs
  for(i=0; i<8; i++)
  {
    //Display input on seven segment
   for(pin=3,a=0; pin<10 ;pin++,a++)
   {
    digitalWrite(pin, bitRead(num[i],a));
   }
    byte A = bitRead(input[i],0);
    byte B = bitRead(input[i],1);
    byte C = bitRead(input[i],2);
    //Calculate output
    byte OUT = ((A)&&((!A)||B)&&(C)&&(A||B));
    byte OUT2 = A&&B&&C;
    //display output for input given on LED (on = 1, off=0)
    digitalWrite(12,OUT2);
    delay(1000);
  }
  
  
}
