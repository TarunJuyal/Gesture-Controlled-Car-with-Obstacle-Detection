int readPin1=16;    //D11 for HT12D IC
int readPin2=5;     //D10 for HT12D IC
int readPin3=4;     //D9 for HT12D IC
int readPin4=0;     //D8 for HT12D IC

//Pins towards motor driver
int enA=1;
int enB=10;
int out1=2;         //To in1 of L298D
int out2=14;        //To in2 of L298D
int out3=12;        //To in3 of L298D
int out4=13;        //To in4 of L298D

// Ultarsonic Pins
int trigPin=15;
int echoPin=3;

void setup() {
  pinMode(readPin1,INPUT);
  pinMode(readPin2,INPUT);
  pinMode(readPin3,INPUT);
  pinMode(readPin4,INPUT);
  pinMode(enA,OUTPUT);
  pinMode(enB,OUTPUT);
  pinMode(out1,OUTPUT);
  pinMode(out2,OUTPUT);
  pinMode(out3,OUTPUT);
  pinMode(out4,OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
}

void loop() {
  int duration,distance;

  analogWrite(enA,255);
  analogWrite(enB,255);
  
  digitalWrite(trigPin,HIGH);
  delay(1);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = (duration/2)/29.1;                                  //in cm
  
  if(distance<=15 && distance>=0){                              //if distance less than 15cm stop the car.
        digitalWrite(out1,LOW);  
        digitalWrite(out2,LOW);   
        digitalWrite(out3,LOW);   
        digitalWrite(out4,LOW);
    }
  else{                                                         //otherwise work normally
        digitalWrite(out1,digitalRead(readPin1));  
        digitalWrite(out2,digitalRead(readPin2));   
        digitalWrite(out3,digitalRead(readPin3));   
        digitalWrite(out4,digitalRead(readPin4));       
    }

}
