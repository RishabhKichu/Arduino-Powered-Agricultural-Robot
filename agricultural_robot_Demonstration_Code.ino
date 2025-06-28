// Generic catch-all implementation.
template <typename T_ty> struct TypeInfo { static const char * name; };
template <typename T_ty> const char * TypeInfo<T_ty>::name = "unknown";

// Handy macro to make querying stuff easier.
#define TYPE_NAME(var) TypeInfo< typeof(var) >::name

// Handy macro to make defining stuff easier.
#define MAKE_TYPE_INFO(type)  template <> const char * TypeInfo<type>::name = #type;

// Type-specific implementations.
MAKE_TYPE_INFO( int )
MAKE_TYPE_INFO( float )
MAKE_TYPE_INFO( short )
MAKE_TYPE_INFO( String )


/*
Drive
ena = Purple
in1 - orange
in2 - white
in3 - brown
in4 - greyish
enb - white (marked)

Actuator and Pump
ena - orange
in 1 - white
in2 - yellow
in 3 - green
in4 - red
enb - orange-yellow

*/
#include <Servo.h>

Servo seed;  


int LP1 = 2;
int LP2 = 3;
int RP1 = 4;
int RP2 = 5;

int PumpP1 = 13;
int PumpP2 = 7;
int ActuatorP1 = 8;
int ActuatorP2 = 12;

int DrivePWM = 6;
int PumpPWM = 10;
int ActuatorPWM = 11;

int DriveSpeed = 225;
int PumpSpeed = 0;
int ActuatorSpeed = 0;

int ActuatorTime = 2000;
int option = 0;

void setup() {
  Serial.begin(9600);  

  seed.attach(9);   

  //drive motors
  pinMode(LP1, OUTPUT);
  pinMode(LP2, OUTPUT);
  pinMode(RP1, OUTPUT);
  pinMode(RP2, OUTPUT);

  //Actuator and Pump 
  pinMode(PumpP1, OUTPUT);
  pinMode(PumpP2, OUTPUT);
  pinMode(ActuatorP1, OUTPUT);
  pinMode(ActuatorP2, OUTPUT);

  //Pwm for actuator and pump
  pinMode(PumpPWM, OUTPUT);
  pinMode(ActuatorPWM, OUTPUT);
}

void loop() {
  seed.write(40);
  Serial.println("What would you like to demonstrate?");
  Serial.println("1. Basic Drive( Front and Back for 1 second each)");
  Serial.println("2. Basic Turning( Turns Left and then turns Right)");
  Serial.println("3. Seed Dispensing (Slow: 1 dispense per 1s for 5 seconds");
  Serial.println("4. Seed Dispensing (Fast: 1 dispense per 0.5s for 5 seconds");
  Serial.println("5. Lowering Humidity Sensor");
  Serial.println("6. Water Pumping (For two seconds)");
  while (Serial.available() == 0)   
    {}  
  option = Serial.parseInt();
  

  if (option == 1){
    Serial.println("Executing Option 1..");
    analogWrite(DrivePWM, DriveSpeed);
    digitalWrite(LP1, HIGH);
    digitalWrite(LP2, LOW);
    // digitalWrite(RP1, HIGH);
    // digitalWrite(RP2, LOW);
    delay(1000);
    digitalWrite(LP1, LOW);
    digitalWrite(LP2, HIGH);
    // digitalWrite(RP1, LOW);
    // digitalWrite(RP2, HIGH);
    delay(1000);
    analogWrite(DrivePWM, 0);
    option = 0;
  }
  else if(option == 2){
    Serial.println("Executing Option 2..");
    analogWrite(DrivePWM, DriveSpeed);
    digitalWrite(LP1, HIGH);
    digitalWrite(LP2, HIGH);
    digitalWrite(RP1, LOW);
    digitalWrite(RP2, LOW);
    delay(1000);
    digitalWrite(LP1, LOW);
    digitalWrite(LP2, LOW);
    digitalWrite(RP1, HIGH);
    digitalWrite(RP2, HIGH);
    delay(1000);
    analogWrite(DrivePWM, 0);
    option = 0;
  }
  else if(option == 3){
    Serial.println("Executing Option 3..");
    for(int i = 0; i<=5;i++){
    seed.write(10);
    delay(500);
    seed.write(40);
    delay(500);
    }
  //delay(5000);2
  option = 0;
  }
  else if(option == 4){
    Serial.println("Executing Option 4..");
    for(int i = 0; i<=10;i++){
    seed.write(0);
    delay(250);
    seed.write(40);
    delay(250);
    }
  //delay(5000);
  option = 0;
  }
  else if(option == 5){
    Serial.println("Executing Option 5..");
    analogWrite(ActuatorPWM, ActuatorSpeed);
    digitalWrite(ActuatorP1, HIGH);
    digitalWrite(ActuatorP2, LOW);
    delay(ActuatorTime);
    analogWrite(ActuatorPWM, 0);
    delay(5000);
    analogWrite(ActuatorPWM, ActuatorSpeed);
    digitalWrite(ActuatorP1, LOW);
    digitalWrite(ActuatorP2, HIGH);
    delay(ActuatorTime);
    analogWrite(ActuatorPWM, 0);
    option = 0;
  }
  else if(option == 6){
    Serial.println("Executing Option 6..");
    analogWrite(PumpPWM, PumpSpeed);
    digitalWrite(PumpP1, HIGH);
    digitalWrite(PumpP2, LOW);
    delay(2000);
    analogWrite(PumpPWM, 0);
    option = 0;
  }
  else if(option == 7){
    delay(20000000000000000);

  }


}
