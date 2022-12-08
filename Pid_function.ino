
unsigned PID(float error){
  Time = millis();
  Delta_time = Time - Last_time;
  I_Error += error * Delta_time;
  D_Error = (error - Last_error) / Delta_time;
  
  Last_error = error;
  Last_time = Time;
  int output = Kp * error + Ki*I_Error + Kd * D_Error;
  output = constrain(output,0,1023);
  return output;
}

float Height(int Trig,int Echo){
  float H = 0 ;
  for(int i = 0; i<10 ; i++){
    H += Distance(Trig,Echo);
  }
  return (30.28 - (H/10));
}

float Distance(int trig,int echo){
  digitalWrite(trig, LOW);
  delayMicroseconds(3);
  digitalWrite(trig, HIGH);
  delayMicroseconds(15);
  digitalWrite(trig, LOW);
  noInterrupts();
  float distance = pulseIn(echo, HIGH); 
  interrupts();
  distance = distance / 58;
  return distance;
}
