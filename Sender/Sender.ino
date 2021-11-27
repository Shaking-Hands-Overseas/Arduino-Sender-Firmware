void setup() {
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
}
String reverse(int x){
    return String(map(x, 0, 180, 180, 0));
  };

void loop() {
  int y = int(analogRead(A0));
  int x = map(y, 0, 1023, 0, 180);
  String sensors_reading[] = {reverse(x), reverse(x), String(x), String(x), String(x)};

  //Data Transmission to the python code via serial port
  String Read = String(Serial.read());
  if (Read = "A"){
  String Info = "  " + sensors_reading[0] + "  " + sensors_reading[1] + "  " +  sensors_reading[2] + "  " + sensors_reading[3] + "  " + sensors_reading[4] + "  ";
  Serial.println(Info); 
  }
  delay(1000);
} 
