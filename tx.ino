int xPin=A0;
int yPin=A1;
int zPin=A2;


int out1=2;     //AD8 for HT12E IC
int out2=3;     //AD9 for HT12E IC
int out3=4;    //AD10 for HT12E IC
int out4=5;    //AD11 for HT12E IC


int Initialxval,Initialyval;
int xAxis,yAxis;
int xval,yval;


void setup(){
  pinMode(xPin,INPUT);
  pinMode(yPin,INPUT);
  pinMode(yPin,INPUT);


  pinMode(out1,OUTPUT);
  pinMode(out2,OUTPUT);
  pinMode(out3,OUTPUT);
  pinMode(out4,OUTPUT);
  Serial.begin(9600);
  Serial.println("Starting...... ");
  Initialxval=analogRead(xPin);
  Initialyval=analogRead(yPin);
}




void loop(){
    
    xval=analogRead(xPin);
    yval=analogRead(yPin);

    xAxis=Initialxval - xval;
    yAxis=Initialyval - yval;

    if (yAxis>=30 ) //forward
    {
     forward();
   }
   else if (yAxis<=-39 ) //backward
   {
     backward(); 
   }   
  else if (xAxis<=-37 ) //left
   {
     left(); 
   }
   else if (xAxis>=58)//right
   {
     right();
   }
   else{
     stopCar();
   }
}


  void forward(){
    Serial.println("Forward........ ");
     digitalWrite(out1,HIGH);  
     digitalWrite(out2,LOW);   
     digitalWrite(out3,HIGH);  
     digitalWrite(out4,LOW);
  }


  void backward(){
    Serial.println("backward..... ");
   digitalWrite(out1,LOW);   
   digitalWrite(out2,HIGH);  
   digitalWrite(out3,LOW);   
   digitalWrite(out4,HIGH);
  }


  void left(){
    Serial.println("Left......... ");
      digitalWrite(out1,HIGH);  
      digitalWrite(out2,LOW);   
      digitalWrite(out3,LOW);   
      digitalWrite(out4,LOW);
  }


  void right(){
    Serial.println("right......... ");
      digitalWrite(out1,LOW);  
      digitalWrite(out2,LOW);   
      digitalWrite(out3,HIGH);   
      digitalWrite(out4,LOW);
  }


  void stopCar(){
      Serial.println("Stop..... ");
        digitalWrite(out1,LOW);  
        digitalWrite(out2,LOW);   
        digitalWrite(out3,LOW);   
        digitalWrite(out4,LOW);
    }
