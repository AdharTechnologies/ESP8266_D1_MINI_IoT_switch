//Required to be on top for Blynk
#define BLYNK_TEMPLATE_ID "TxxxxxxxxxxP"
#define BLYNK_TEMPLATE_NAME "IoT Switch"
#define BLYNK_AUTH_TOKEN "RxxxxxxxxxxxxxxxxxxUd-PLu"

#include "config.h"

void connection_status(){

  // Check if connected to Blynk server
  if (Blynk.connected() && !isConnected) {
    isConnected = true;
    //Serial.println("ESP8266 is connected to Blynk!");
    analogWrite(status_led, 30);
  }
  else if (!Blynk.connected() && isConnected){
    isConnected = false;
    analogWrite(status_led, 0);
  }

}

BLYNK_WRITE(V0){
  if(param.asInt() == 1){
    // execute this code if the switch widget is now ON
    digitalWrite(relay_pin, 1);  
  }
  else{
    // execute this code if the switch widget is now OFF
    digitalWrite(relay_pin, 0);  
  }
}

void setup() {
  // Start the Serial Monitor for debugging
  Serial.begin(9600);
  delay(1000);
  Serial.print(version);

  // Setting up pinMode 
  pinMode(relay_pin, OUTPUT); digitalWrite(relay_pin, 0);
  pinMode(power_led, OUTPUT); analogWrite(power_led, 30);
  pinMode(status_led, OUTPUT); analogWrite(status_led, 0);

  Blynk.begin(auth, ssid, pass);

}

void loop() {

  Blynk.run();
  connection_status();

}




