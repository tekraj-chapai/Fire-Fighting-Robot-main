
int buzzer=10;                //Defining variable and the GPIO pin on Arduino
void setup() 
{
  pinMode(buzzer, OUTPUT);    //Defining the pin as OUTPUT
  //put your setup code here:
}

void loop() 
{

  digitalWrite(buzzer, HIGH);   //Setting the pin HIGH
  delay(2000);
  digitalWrite(buzzer, LOW);    //Setting the pin HIGH
  delay(2000);
  //put your main code here, to run repeatedly:
}
