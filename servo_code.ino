#include <Servo.h> 
Servo myservo;
void setup() {
  
myservo.attach(9);
}

void loop() {
  myservo.write(180);                   
 delay(15);  // put your main code here, to run repeatedly:

}
