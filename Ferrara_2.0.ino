
#define sensor1 2
#define sensor2 3 
#define sensor3 4 
#define sensor4 5 
#define sensor5 6

void setup() {
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(sensor5, INPUT);
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
}
void loop() {
  String sensors_reading[] = {"0", "1", "2", "3", "4"};

  //Data Transmission to the python code via serial port
  String Read = String(Serial.read());
  if (Read = "A"){
  String Info = "  " + sensors_reading[0] + "  " + sensors_reading[1] + "  " +  sensors_reading[2] + "  " + sensors_reading[3] + "  " + sensors_reading[4] + "  ";
  Serial.println(Info); 
  }
  delay(100);
} 
