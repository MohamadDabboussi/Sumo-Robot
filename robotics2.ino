#include <Ultrasonic.h>
int value;//IR value
int irPin = 2;
  Ultrasonic ultrasonic(A0, A1); // (Trig PIN,Echo PIN)
int distance;
//Motor A
int motorPin1  = 5;
int motorPin2  = 6;
//Motor B
int motorPin3  = 7;
int motorPin4  = 8;
int motor11;
int motor12;
int motor21;
int motor22;

void drive(speed1,speed2)//direction
{ 
  if(speed1<0){motor11=0;motor12=-speed1;}
  else {motor11=speed1;motor12=0;};
  if(speed2<0){motor21=0;motor22=-speed2;}
  else {motor21=speed2;motor22=0;};
  analogWrite(motorPin1, motor11);
  analogWrite(motorPin2, motor12);
  analogWrite(motorPin3, motor21);
  analogWrite(motorPin4, motor22);
  }

void setup() {
  pinMode(irPin,INPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  
  Serial.begin(9600);
}
void loop() {
  value = digitalRead(irPin);
   if (value ==0) //White
   {
  drive(-130,-130)
  }

  
   else {
   distance = ultrasonic.read();
   if(distance<15)
   {
 drive(130,130)
   }

   else{
 drive(130,-50)
  }
   
 drive(30,30)
   }
  delay(10);
}
