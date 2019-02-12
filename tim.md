### 11/02/2019

Team Bravo has finished making the battery indicator of the lipo battery pack

This battery indicator reads the voltage of the battery and shows its state by lighting up an LED in three different states

When we measured the battery at full charge, it reads 11.1V

We found that 3 batteries are in a lipo battery pack, hence the nominal voltage of one battery is 3.7V 

Components needed: 
                   
                   Stripboard
                   
                   Jumper wires
                   
                   82k resistor
                   
                   100k resistor 
                   
                   1 green led 
                   

Since 11.1V cannot be supplied to the analog pin of the arduino, we have decided to build a voltage divider with two resistors

Schematic of the circuit when simulated with a breadboard:

<img src="images/capture 4.JPG" alt="schematic">

```#define green 8

#define lipo  A1
 
float lipoV = 0;
 
 
 
 
 
void setup() {
 

pinMode(green,OUTPUT);
pinMode(lipo,INPUT);
Serial.begin(9600);
}
 
void loop() {
 
lipoV = analogRead(A1);
 
 
Serial.println(lipoV);
 
if(lipoV>777 && lipoV<838){
  digitalWrite(green, HIGH);   
  delay(250);                       
  digitalWrite(green, LOW);   
  delay(250);                       
}
if(lipoV>838 && lipoV<899){
  digitalWrite(green, HIGH);   
  delay(500);                     
  digitalWrite(green, LOW);    
  delay(500);                       
}
if(lipoV>899 && lipoV<1023){
 digitalWrite(green, HIGH);   
  delay(1000);                     
  digitalWrite(green, LOW);    
  delay(1000);    
}
}```


