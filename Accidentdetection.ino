/*************************************************************

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT DebugSerial


// You could use a spare Hardware Serial on boards that have it (like Mega)
#include <SoftwareSerial.h>
SoftwareSerial DebugSerial(2, 3); // RX, TX

#include <BlynkSimpleStream.h>
int gas_pin=7;
int tilt_pin=A1;
int motor=8;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
//char auth[] = "H2ajExldKt1umhBDhToljgeQePp_ojem";
char auth[]="dM8segwoDyAoHHlbI2w2rizWVGs6Q-2X";

void setup()
{
  // Debug console
  DebugSerial.begin(9600);
  pinMode(motor,OUTPUT);
  // Blynk will work through Serial
  // Do not read or write this serial manually in your sketch
  Serial.begin(9600);
  Blynk.begin(Serial, auth);
  
}

void loop()
{
  Blynk.run();
  tilt();
  alcohol();
}

void alcohol(){
  if(digitalRead(gas_pin)){
    digitalWrite(motor,LOW);
  }else{
    digitalWrite(motor,HIGH);
  }
}

void tilt(){
  int val=analogRead(tilt_pin);
  //Serial.println(val);
  Blynk.virtualWrite(V9,val);
  if(val<339){
    //digitalWrite();
    Blynk.virtualWrite(V10,"happen");
  }else{
    Blynk.virtualWrite(V10,".....");
  }
}
