#include <CapacitiveSensor.h>

// resistor between pins 4 and 2, foil connected to wire which is connected to pin 2
// wiring diagram for hand is in separate diagram

// threshold that determines when sensor is touched; depends on value of resistor
#define THRESHOLD 200

// output current to transistor 
#define MOTOR_PIN 3

// time it takes hand to clench; will increase over time as bands on fingers loosen
#define MOVE_TIME 2250 
#define WAIT_TIME 3000

//resistor between pins 4 & 2, pin 2 is sensor pin, add wire, foil
CapacitiveSensor cs_4_2 = CapacitiveSensor(4, 2);

void setup() {
  cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
 Serial.begin(9600);
  pinMode(MOTOR_PIN, OUTPUT); 
}

void loop() {
  long sensor =  cs_4_2.capacitiveSensor(30);
  Serial.println(sensor);
  if (sensor > THRESHOLD) {
    digitalWrite(MOTOR_PIN, HIGH); // 
    delay(MOVE_TIME); // let motor run to clench hand
    digitalWrite(MOTOR_PIN, LOW); 
    delay(WAIT_TIME); // turn motor off, let tension on rubber bands pull motor back
  } 
  
  delay(500);
}
