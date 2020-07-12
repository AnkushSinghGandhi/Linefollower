
#include <AFMotor.h>
AF_DCMotor motor1(4, MOTOR12_8KHZ); 
AF_DCMotor motor2(3, MOTOR12_8KHZ);


void setup() {
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  Serial.begin(9600);
}

void loop(){
  Serial.println(analogRead(A4));
  Serial.println(analogRead(A5));

  if(analogRead(A4)<=400 && analogRead(A5)<=400){
    motor1.run(RELEASE);
    motor2.run(RELEASE);
  }
  else if(analogRead(A4)<=400 && !analogRead(A5)<=400){
    // jis direction m turn karna h us direction wali motor rukegi or dusri sidhi aage chlegi
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
  }
  else if(!analogRead(A4)<=400 && analogRead(A5)<=400){
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
  }
  else if(!analogRead(A4)<=400 && !analogRead(A5)<=400){
    motor1.run(FORWARD);
    motor2.run(FORWARD);
  }
  
}


