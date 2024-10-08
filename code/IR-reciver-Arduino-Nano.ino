#include <ir_Lego_PF_BitStreamEncoder.h>
#include <boarddefs.h>
#include <IRremoteInt.h>
#include <IRremote.h>

// Use 7 pin to received IR
const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;

int ledState = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(10, OUTPUT);
  digitalWrite(10, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  // You can change to your remote HEX code
  if(irrecv.decode(&results)){
    Serial.println(results.value, HEX);
    if(results.value == 0x807FC03F){
      if(ledState == 0){
        digitalWrite(10, HIGH);
        ledState = 1;
      }else{
        digitalWrite(10, LOW);
        ledState = 0;
      }
    }else if(results.value == 0x807FE01F){
      digitalWrite(10, HIGH);
      delay(100);
      digitalWrite(10, LOW);
      delay(100);
      digitalWrite(10, HIGH);
      delay(100);
      digitalWrite(10, LOW);
      delay(100);
      digitalWrite(10, HIGH);
      delay(100);
      digitalWrite(10, LOW);
      delay(500);
    }
    irrecv.resume();
  }
}
 
