//https://talkingstuff.net/water-level-indicator-ultrasonic/
const int trigPin = 2;
const int echoPin = 3;
int ledA=13;
int ledB=11;
int ledC=10;
int ledD=8;
int a=4;
int b=3;
int c=2;
int d=1;
int max_distance = 200;
void setup() {
Serial.begin(9600);
pinMode (ledA,OUTPUT);
pinMode (ledB,OUTPUT);
pinMode (ledC,OUTPUT);
pinMode (ledD,OUTPUT);
digitalWrite(ledA, LOW);
digitalWrite(ledB, LOW);
digitalWrite(ledC, LOW);
digitalWrite(ledD, LOW);
}
void loop() {
long duration, inches, cm;
pinMode(trigPin,OUTPUT);
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);
//cm = ( duration / 29 ) / 2;
//inches = cm * 0.393701;
inches = microsecondsToInches(duration);
cm = microsecondsToCentimeters(duration);
if (inches <max_distance){Serial.print(inches); Serial.print(" in"); Serial.print(cm); Serial.print(" cm"); Serial.println(); delay(100); }
 if (inches >=a) {digitalWrite (ledA,HIGH);digitalWrite (ledB,LOW); digitalWrite (ledC,LOW); digitalWrite (ledD,LOW); Serial.println("Cond1"); }

else if (inches >=b){digitalWrite (ledA,LOW);digitalWrite (ledB,HIGH); digitalWrite (ledC,LOW); digitalWrite (ledD,LOW); Serial.println("Cond2");}

else if (inches >=c){digitalWrite (ledA,LOW);digitalWrite (ledB,LOW); digitalWrite (ledC,HIGH); digitalWrite (ledD,LOW); Serial.println("Cond3");}

else if (inches >=d){digitalWrite (ledA,LOW);digitalWrite (ledB,LOW); digitalWrite (ledC,LOW); digitalWrite (ledD,HIGH); Serial.println("Cond4"); }

//else {digitalWrite (ledA,HIGH);digitalWrite (ledB,HIGH); digitalWrite (ledC,HIGH); digitalWrite (ledD,HIGH); }
}
long microsecondsToInches(long microseconds) {
// According to Parallax's datasheet for the PING))), there are
// 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
// second). This gives the distance travelled by the ping, outbound
// and return, so we divide by 2 to get the distance of the obstacle.
// See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
return (microseconds / 74) / 2;
}
long microsecondsToCentimeters(long microseconds) {
// The speed of sound is 340 m/s or 29 microseconds per centimeter.
// The ping travels out and back, so to find the distance of the
// object we take half of the distance travelled.
return (microseconds / 29) / 2;
}
