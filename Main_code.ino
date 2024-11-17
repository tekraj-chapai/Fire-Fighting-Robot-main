#include <Servo.h>  //include servo.h library
int waterstate=1;
const int IN1=12;
const int IN2=4;
const int ENA=3;
const int IN3=7;
const int IN4=2;
const int ENB=5;
Servo myservo;
const int buzzer = 0;
const int FloatSensor = 13;
int pos = 0;
int motor_speed = 200;  
boolean fire = false;
#define Left 9      // left sensor
#define Right 10    // right sensor
#define Forward 8   //front sensor
#define pump 6
void setup() {
  Serial.begin(9600);
pinMode(Left, INPUT);
pinMode(Right, INPUT);
pinMode(Forward, INPUT);
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(ENA, OUTPUT);
pinMode(IN4, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(ENB, OUTPUT);
pinMode(pump, OUTPUT);
pinMode(buzzer, OUTPUT);
pinMode(FloatSensor, INPUT_PULLUP);
  myservo.attach(11);
  myservo.write(90);
}
void put_off_fire() {
    delay (500);  
   digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
   digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
   digitalWrite(pump, HIGH);
   delay(500);
    for (pos = 50; pos <= 130; pos += 1) {
    myservo.write(pos);
    delay(10);  
  }
  for (pos = 130; pos >= 50; pos -= 1) {
    myservo.write(pos);
    delay(10);
  }
  digitalWrite(pump,LOW);
  myservo.write(90);
  fire=false;
} 
void loop() {
   myservo.write(90); //Sweep_Servo();  
  if (digitalRead(Left) == 1 && digitalRead(Forward) == 1 || digitalRead(Right)== 1 && digitalRead(Forward) == 1 || digitalRead(Left)== 1 && digitalRead(Forward)== 1&& digitalRead(Right)== 1) {   
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  fire = true;
    }  
  else  if (digitalRead(Left) ==0 && digitalRead(Right)==0 && digitalRead(Forward) ==1) {   
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  }
  else if (digitalRead(Left) ==1 && digitalRead(Right)==0 && digitalRead(Forward) ==0) {   
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  }
  else if (digitalRead(Left) ==0 && digitalRead(Right)==1 && digitalRead(Forward) ==0) {   
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  }
  delay(300);//change this value to increase the distance  
   waterstate=digitalRead(FloatSensor); 
   while (waterstate==HIGH)
   {  tone(buzzer, 1000);
   Serial.println("Low Pump is Detected.");
   }
   while (fire == true) {
   put_off_fire();
   Serial.println("Fire is Detected.");
   }
}
