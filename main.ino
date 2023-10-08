                 
  int stop_distance = 12;// Obstacle detection distance

  const int trigPin = 11; 
  const int echoPin = 12; 

//L298 
  const int motorA1      = 3;  //  IN1 -> 3 arduino
  const int motorA2      = 4;  //  IN2 -> 4 arduino
  const int motorAspeed  = 5;  //  ENA -> 5 arduino
  const int motorB1      = 7; //  IN3 -> 7 arduino
  const int motorB2      = 8; //  IN4 -> 8 arduino
  const int motorBspeed  =6;  //  ENB -> 6 arduino

//sensor
  const int L_S =9;  
  const int S_S =2;  
  const int R_S =10; 
  
  int left_sensor_state;
  int s_sensor_state;   
  int right_sensor_state;

  long duration; // time
  int distance;  // distance
  

void setup() {
  pinMode(L_S,INPUT); 
  pinMode(R_S,INPUT);
  pinMode(S_S,INPUT);
  pinMode(motorA1, OUTPUT); 
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(motorAspeed, OUTPUT);
   pinMode(motorBspeed, OUTPUT);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
    
  Serial.begin(9600); 
  analogWrite(motorAspeed, 120); 
  analogWrite(motorBspeed, 120);
  delay(3000);                              
  
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);

   left_sensor_state = digitalRead(L_S);
   s_sensor_state = digitalRead(S_S);
   right_sensor_state = digitalRead(R_S);

if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 0)){forword();}

if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 0)){turnLeft();} 
if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) ==0)&&(digitalRead(R_S) == 0)) {turnLeft();} 

if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 1)){turnRight();} 
if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 1)){turnRight();}

if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 1)){Stop();} 


if(distance < stop_distance) 
 {

  digitalWrite (motorA1,HIGH);// back
  digitalWrite(motorA2,LOW);                       
  digitalWrite (motorB1,LOW);
  digitalWrite(motorB2,HIGH);
  delay(200);
  analogWrite (motorAspeed, 0);
  analogWrite (motorBspeed, 0);
  delay(200);
  digitalWrite (motorA1,HIGH);// turn R
  digitalWrite(motorA2,LOW);                       
  digitalWrite (motorB1,HIGH);
  digitalWrite(motorB2,LOW);
  analogWrite (motorAspeed, 90);
  analogWrite (motorBspeed, 90);
  delay(400);

  digitalWrite (motorA1,LOW); // go straight
  digitalWrite(motorA2,HIGH);                       
  digitalWrite (motorB1,HIGH);
  digitalWrite(motorB2,LOW);
  analogWrite (motorAspeed, 90);
  analogWrite (motorBspeed, 90);
  delay(600);


  digitalWrite (motorA1,LOW);// turn left
  digitalWrite(motorA2,HIGH);                       
  digitalWrite (motorB1,LOW);
  digitalWrite(motorB2,LOW);
  analogWrite (motorAspeed, 110);
  analogWrite (motorBspeed, 110);
  delay(1000);
 
 
   digitalWrite (motorA1,LOW); //straight
  digitalWrite(motorA2,HIGH);                       
  digitalWrite (motorB1,HIGH);
  digitalWrite(motorB2,LOW);
  analogWrite (motorAspeed, 100);
  analogWrite (motorBspeed, 100);
  delay(300);


  digitalWrite (motorA1,LOW); //turn left
  digitalWrite(motorA2,HIGH);                       
  digitalWrite (motorB1,LOW);
  digitalWrite(motorB2,LOW);
  analogWrite (motorAspeed, 100);
  analogWrite (motorBspeed, 100);
  delay(500);
  digitalWrite (motorA1,LOW); //straight
  digitalWrite(motorA2,HIGH);                       
  digitalWrite (motorB1,HIGH);
  digitalWrite(motorB2,LOW);
  analogWrite (motorAspeed, 90);
  analogWrite (motorBspeed, 90);

  while(left_sensor_state == LOW){

  left_sensor_state = digitalRead(L_S);
  s_sensor_state = digitalRead(S_S);
  right_sensor_state = digitalRead(R_S);
  Serial.println("in the first while");
  
 }

}
}

void forword(){ 

  digitalWrite (motorA1,LOW);
  digitalWrite(motorA2,HIGH);                       
  digitalWrite (motorB1,HIGH);
  digitalWrite(motorB2,LOW);
}


void turnRight(){

  digitalWrite (motorA1,LOW);
  digitalWrite(motorA2,LOW);                       
  digitalWrite (motorB1,HIGH);
  digitalWrite(motorB2,LOW);
}

void turnLeft(){

  digitalWrite (motorA1,LOW);
  digitalWrite(motorA2,HIGH);                       
  digitalWrite (motorB1,LOW);
  digitalWrite(motorB2,LOW);
}

void Stop(){

  digitalWrite (motorA1,LOW);
  digitalWrite(motorA2,LOW);                       
  digitalWrite (motorB1,LOW);
  digitalWrite(motorB2,LOW);
}







 
