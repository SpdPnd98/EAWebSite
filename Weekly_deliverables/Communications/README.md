# Method of Communication

The method of communication we have chosen is wifi communication. This is because it allows any device to be able to access a single endpoint.

This experiment was done without supervision with and ESP8266

The tutorial that was followed can be found [here](https://www.youtube.com/watch?v=TnWDlHpY56o)

```
#include <ESP8266WiFi.h>

const char* ssid="Your SSID";
const char* password = "Your Password";

int ledPin = 13;

void setup() {
  
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,LOW);

  Serial.begin(115200);
  Serial.println();
  Serial.print("Wifi connecting to ");
  Serial.println( ssid );

  WiFi.begin(ssid,password);

  Serial.println();
  Serial.print("Connecting");

  while( WiFi.status() != WL_CONNECTED ){
      delay(500);
      Serial.print(".");        
  }

  digitalWrite( ledPin , HIGH);
  Serial.println();

  Serial.println("Wifi Connected Success!");
  Serial.print("NodeMCU IP Address : ");
  Serial.println(WiFi.localIP() );

}

void loop() {
  // put your main code here, to run repeatedly:

}
```

We were satisfied when we saw that the connection was successful.

## Further thinking

Upon further discussion, we have decided that a wired communication may be a viable option as we may need the connection to be secure.(Unique to only one user at a time)

Hence, we tried a simple software serial tutorial. Links to the video we followed can be found [here](https://www.youtube.com/watch?v=zYWUVMwSxHw)

The reason we followed this tutorial is because we did not have a proper controller at hand. We improvised by using an arduino as a "mock" controller.

We were able to achieve satisfying results.

Reading from external sensor and sending to next Arduino (Controller)
```
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
SoftwareSerial mySerial(8, 9);//rx tx
LiquidCrystal lcd(12, 10, 11, 5, 4, 3, 2);
int i, MessageLength, Message[100], PWM_Value;
byte low, high, datacheck;
void setup(){
 lcd.begin(16,2); 
 mySerial.begin(9600);
  
}


void loop(){

  if(mySerial.read() == '$'){
    for(i=0; i<100; i++){
       delay(1);
     Message[i] = mySerial.read();
     if(Message[i]=='#')
     break;
    }
  MessageLength = i;
  delay(1);
  low = mySerial.read();
  delay(1);
  high = mySerial.read();  
  lcd.clear();
  for(i=0; i<MessageLength; i++){
  lcd.print(char(Message[i]));
  delay(2);}
  lcd.setCursor(0,1);
  lcd.print(high);
  lcd.print(" ");
  lcd.print(low);
  lcd.print(" ");
  lcd.print(word(high, low));  
  PWM_Value = analogRead(0);
  mySerial.print('$');
  mySerial.print(char(lowByte(PWM_Value)));
  mySerial.print(char(highByte(PWM_Value)));

   
  }//serialavailable
  


}
```

Receiving code and executing proper commands

```
#include <SoftwareSerial.h>
SoftwareSerial mySerial(8, 9);//rx tx
byte counter;
byte PWM_Input=128, low, high;
int dataIn;
long Start;
void setup(){
pinMode(3, OUTPUT);
mySerial.begin(9600);
}


void loop(){

analogWrite(3, PWM_Input);
mySerial.print("$I'm counting ");
mySerial.print(counter);
mySerial.print('#');
mySerial.print(char(low));
mySerial.print(char(high));
counter++;
Start = millis();
while(millis()-Start<100){
  delay(1);
if(mySerial.read()=='$'){
  delay(1);
  low = mySerial.read();
  delay(1);
  high = mySerial.read();
  break;}}

  dataIn = word(high, low);
  
 if(dataIn>680)
 dataIn=680;
 if(dataIn<400)
 dataIn=400;
 PWM_Input =  map(dataIn, 400, 680, 0, 255);




}
```
