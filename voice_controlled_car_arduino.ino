#include <AFMotor.h>
#include <Servo.h>
#include <SoftwareSerial.h>

char c;
SoftwareSerial EEBlue(0,1);
String voice = "*forward";

AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR12_1KHZ); 
AF_DCMotor motor4(4, MOTOR12_1KHZ);
Servo myServo;

void setup()
{
  Serial.begin(9600); 
  EEBlue.begin(9600); 
  myServo.attach(10); 
  myServo.write(90);  
}

void loop() 
{
  while (Serial.available()){ 
    delay(500);//bluetooth code here
    if (EEBlue.available())
     c = EEBlue.read(); 
    if (c == '#') {break;} 
    voice += c; 
  }
  if (voice.length() > 0){
    if(voice == "*forward"){
      forward();
      }
    else if(voice == "*reverse"){
      reverse();
      }
    else if(voice == "*right") {
      right();
    }
    else if(voice == "*left") {
      left();
    }
    else if(voice == "*stop") {
      Stop();
    }
    
  voice=""; 
  }
}

void forward()
{
motor1.setSpeed(255); 
motor1.run(FORWARD); 
motor2.setSpeed(255); 
motor2.run(FORWARD); 
motor3.setSpeed(255); 
motor3.run(FORWARD); 
motor4.setSpeed(255); 
motor4.run(FORWARD);
delay(1200);
motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(RELEASE);
motor4.run(RELEASE);
}

void reverse()
{
motor1.setSpeed(255); 
motor1.run(BACKWARD); 
motor2.setSpeed(255); 
motor2.run(BACKWARD); 
motor3.setSpeed(255); 
motor3.run(BACKWARD); 
motor4.setSpeed(255); 
motor4.run(BACKWARD); 
delay(1200);
motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(RELEASE);
motor4.run(RELEASE);
}

void left()
{
myServo.write(180);
delay(1000);
myServo.write(90);
delay(1000);
motor1.setSpeed(255); 
motor1.run(FORWARD); 
motor2.setSpeed(255); 
motor2.run(FORWARD); 
motor3.setSpeed(0);
motor3.run(RELEASE); 
motor4.setSpeed(0);
motor4.run(RELEASE);
delay(350);
motor1.run(RELEASE);
motor2.run(RELEASE);
}

void right()
{
myServo.write(0);
delay(1000);
myServo.write(90);
delay(1000);
motor1.setSpeed(0);
motor1.run(RELEASE); 
motor2.setSpeed(0);
motor2.run(RELEASE); 
motor3.setSpeed(255); 
motor3.run(FORWARD); 
motor4.setSpeed(255); 
motor4.run(FORWARD); 
delay(350);
motor3.run(RELEASE);
motor4.run(RELEASE);
}

void Stop()
{
motor1.setSpeed(0);
motor1.run(RELEASE); 
motor2.setSpeed(0);
motor2.run(RELEASE); 
motor3.setSpeed(0);
motor3.run(RELEASE);
motor4.setSpeed(0);
motor4.run(RELEASE); 
}
