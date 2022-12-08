#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// define pin for ultrasonic sensor
#define motor_pin 14 //D5
#define trigPin  12 //D6
#define echoPin  13 //D7


// decleration variable for PID contorol
int Ki = 0.7;
int Kd = 5;
int Kp = 20;
float Setpoint = 20;
float Height_1;
float Error ;
float I_Error ;
float D_Error ;
float Last_error ;
unsigned long Time ;
unsigned long Last_time = 0;
unsigned long Delta_time;
unsigned output;

const char* ssid = "PID_Contoroler" ;  // Enter SSID here
const char* password = "123456789" ;  //Enter Password here

 
/* Put IP Address details */
IPAddress local_ip(192,168,4,1);
IPAddress gateway(192,168,4,1);
IPAddress subnet(255,255,255,0);
 
ESP8266WebServer server(80);
 
void setup() {
//  Serial.begin(115200);
//  Serial.print("Setting soft-AP ... ");
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  WiFi.softAP(ssid, password);
 
  server.on("/", handle_OnConnect);
  server.begin();
//  Serial.println("HTTP server started");
}
void loop() {
   Height_1 = Height(trigPin,echoPin);
   Error = Setpoint - Height_1;
   output = PID(Error);
   analogWrite(motor_pin,output);
   delay(50);
   server.handleClient();
   
}
