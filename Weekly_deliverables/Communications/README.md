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
