#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

//#define trigPin  12
//#define echoPin  14

// decleration variable 

//int Ki = 1;
//int Kd = 1;
//int Kp = 1;
//unsigned long Time ;
//unsigned long Last_time = 0;
//unsigned long Delta_time;
//
//float Setpoint;
//float Height_1;
//float Error;
//float I_Error;
//float D_Error;
//float Last_error;
//int mypid = 0;


const char* ssid = "PID_Contoroler" ;  // Enter SSID here
const char* password = "123456789" ;  //Enter Password here

 
/* Put IP Address details */
IPAddress local_ip(192,168,4,1);
IPAddress gateway(192,168,4,1);
IPAddress subnet(255,255,255,0);
 
ESP8266WebServer server(80);
 
void setup() {
  Serial.begin(115200);
  Serial.print("Setting soft-AP ... ");
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  WiFi.softAP(ssid, password);
 
  server.on("/", handle_OnConnect);
  server.begin();
  Serial.println("HTTP server started");
}
void loop() {
   server.handleClient();
  
  // server.handleClient();
  //   digitalWrite(trigPin, LOW);
  // delayMicroseconds(3);
  // // Sets the trigPin on HIGH state for 10 micro seconds
  // digitalWrite(trigPin, HIGH);
  // delayMicroseconds(15);
  // digitalWrite(trigPin, LOW);
  // noInterrupts();
  // // Reads the echoPin, returns the sound wave travel time in microseconds
  // distance = pulseIn(echoPin, HIGH);
  // interrupts();
  // // Calculate the distance
  // distance = 30.28 - (distance / 58);
 
  //  delay(1000);
}

//unsigned PID(float error){
//  Time = millis();
//  Delta_time = Time - Last_time;
//  I_Error += error * Delta_time;
//  D_Error = (error - Last_error) / Delta_time;
//  
//  Last_error = error;
//  Last_time = Time;
//  int output = Kp * error + Ki*I_Error + Kd * D_Error;
//  output = constrain(output,0,1023);
//  return output;
//}
//
//float Height(int Trig,int Echo){
//  float H = 0 ;
//  for(int i = 0; i<10 ; i++){
//    H += Distance(Trig,Echo);
//  }
//  return (30.28 - (H/10));
//}
//
//float Distance(int trig,int echo){
//  digitalWrite(trig, LOW);
//  delayMicroseconds(3);
//  digitalWrite(trig, HIGH);
//  delayMicroseconds(15);
//  digitalWrite(trig, LOW);
//  noInterrupts();
//  float distance = pulseIn(echo, HIGH); 
//  interrupts();
//  distance = distance / 58;
//  return distance;
//}
