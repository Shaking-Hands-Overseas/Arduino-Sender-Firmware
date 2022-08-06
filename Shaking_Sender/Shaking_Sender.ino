#include <WiFi.h>
#include <HTTPClient.h>
#include <Arduino_JSON.h>
#include "SensorUtilities.h"
#include "WifiUtilities.h"
#include <ESP32Servo.h>

Servo servo1, servo2, servo3,servo4, servo5;
const char* ssid = "CONVIDAT_1";
const char* password = "Aribau*2015";
const char* serverGET = "https://development-sho.herokuapp.com/1/receiver";
const char* serverPOST = "https://development-sho.herokuapp.com/1/servo";

#define S1    1
#define S2    2
#define S3    3
#define S4    4
#define S5    5

#define OPEN_ANGLE 0

int A[] = {36, 39, 32, 34, 35};
int maxes[] = {0, 0, 0, 0, 0};
int mins[] = {180,180,180,180,180};

String sensorReadings;

void initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  } 
  Serial.println(WiFi.localIP());
}
void setup() {
  servo1.attach(S1);
  servo2.attach(S2);
  servo3.attach(S3);
  servo4.attach(S4);
  servo5.attach(S5);
  Serial.begin(115200);
  initWiFi();
  Serial.print("RRSI: ");
  Serial.println(WiFi.RSSI());
}

void loop() {
  int s[] = {analogRead(A[0]), analogRead(A[1]), analogRead(A[2]), analogRead(A[3]), analogRead(A[4])}; //Reading data from Analog ports A0-A4
  sensorReadings = httpGETRequest(serverGET);
  Serial.println(sensorReadings);
  JSONVar myObject = JSON.parse(sensorReadings);
  int b1 = int(myObject["b1"]);
  int b2 = int(myObject["b2"]);

  if (b1 == 1){
    servo1.write(s[0]);
    }else{
    servo1.write(OPEN_ANGLE);
      }
  if (b2 == 1){
    servo2.write(s[1]);
    servo3.write(s[2]);
    servo4.write(s[3]);
    servo5.write(s[4]);
    }else{
    servo2.write(OPEN_ANGLE);
    servo3.write(OPEN_ANGLE);
    servo4.write(OPEN_ANGLE);
    servo5.write(OPEN_ANGLE);
    }

  for (int i = 0; i < 5; i++){
    if (s[i] > maxes[i])
      maxes[i] = s[i];
    if (s[i] < mins[i])
      mins[i] = s[i];
    s[i] = map(s[i], mins[i], maxes[i], 0, 4095); 
}
  String httpRequestData = " {\"s1\":\"" + String(reverse(s[0])) + "\",\"s2\":\"" + String(normal(s[1])) + "\"\"s3\":\"" + String(normal(s[2])) + "\",\"s4\":\"" + String(reverse(s[3])) + "\",\"s5\":\"" + String(normal(s[4])) + "\"}";

  HTTPClient http2;
  WiFiClient client2;
  http2.begin(client2, serverPOST);
  int httpResponseCode = http2.POST(httpRequestData);
  Serial.println(httpResponseCode);
}
