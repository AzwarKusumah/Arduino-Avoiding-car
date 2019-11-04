//////////////////////////////////////////////////////////////////
//                   Obstacle Avoiding Robot                    //
//                      Created by Azware                       //
//   FB: https://www.facebook.com/cerzht.cerzht (Azwar Kusumah) //
//                           Enjoyed                            //
//////////////////////////////////////////////////////////////////
#include <AFMotor.h>
#include <Servo.h>
#include <NewPing.h>
#define trig_pin A0
#define echo_pin A1
#define max_distance 200
#define max_speed 200
#define max_speed_offset 20

Servo myservo;

NewPing sonar (trig_pin,echo_pin,max_distance); //Ultrasonic
AF_DCMotor motor1(1,MOTOR12_1KHZ);
AF_DCMotor motor2(2,MOTOR12_1KHZ);
AF_DCMotor motor3(3,MOTOR34_1KHZ);
AF_DCMotor motor4(4,MOTOR34_1KHZ);
boolean goesForward = false; 
int distance = 100;
int speedset = 0;
int lookRight(){
    myservo.write(50);
    delay(500);
    int distance = readPing();
    delay(100);
    return distance;
}
int lookLeft(){
    myservo.write(170);
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(115);
    return distance;
    delay(100);



}
int readPing(){
    delay(70);
    int cm = sonar.ping_cm();
    if (cm==0)
    {
       cm = 250; 
    }
    return cm;
}
void moveStop(){
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
}
void moveBackward(){
    goesForward = true;
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
    for(speedset = 0; speedset < max_speed; speedset =+2){
        motor1.setSpeed(speedset);
        motor2.setSpeed(speedset);
        motor3.setSpeed(speedset);
        motor4.setSpeed(speedset);
        delay(5);
    }

}
void moveForward(){
    if(!goesForward){
    goesForward = true;
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
    }
    for(speedset = 0; speedset < max_speed; speedset =+2){
        motor1.setSpeed(speedset);
        motor2.setSpeed(speedset);
        motor3.setSpeed(speedset);
        motor4.setSpeed(speedset);
        delay(5);
    }
}
void turnRight(){
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
    delay(500);
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
}
void turnLeft(){
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
    delay(500);
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
}

void setup() {
myservo.attach(10);  
    myservo.write(115); 
delay(2000);
    distance = readPing();
delay(100);
    distance = readPing();
delay(100);
    distance = readPing();
delay(100);
    distance = readPing();
delay(100);

}

void loop() {
int distanceR = 0;
    int distanceL = 0;
      delay(45);
        if(distance<=20){
          moveStop();
          delay(100);
          moveBackward();
          delay(300);
          moveStop();
          delay(200);
          distanceR = lookRight();
          delay(200);
          distanceL = lookLeft();
          delay(200);

          if(distanceR >= distanceL){
                turnRight();
                moveStop();     
        }else{
                turnLeft();
                moveStop();
             }

        }else{
                moveForward();
             }

    distance = readPing();

}

//////////////////////////////////////////////////////////////////
//                                                              //
//                           Thanks                             //
//                                                              //
//////////////////////////////////////////////////////////////////
