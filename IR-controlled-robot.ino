/************IR (TV REMOTE) CONTROLLED ROBOT  *************/
#include <LiquidCrystal.h>
#include <IRremote.h>
#include <NewPing.h>
#include <Servo.h>

#define TRIGGER_PIN  6  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     7  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
int RECV_PIN = 13;
IRrecv irrecv(RECV_PIN);
decode_results results;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // sets the interfacing pins
Servo myservo;

void setup() {
lcd.begin(16, 2);
irrecv.enableIRIn();
myservo.attach(8);
}
/*pins:servo-8;IR-13;sonar-6,7;LCD-12,11,5,4,3,2;motor1-A0,A1;motor2-A2,A3;*/
void loop() {
if (irrecv.decode(&results)) {
                                  //  Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
   }
  delay(100);
}
