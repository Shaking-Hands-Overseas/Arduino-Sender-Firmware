void setup() {
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
}
String reverse(int x){
    return String(map(x, 0, 1023, 180, 0)); // Reversing the values if needed
  };

String normal(int s){
  return String(map(s, 0, 1023, 0, 180)); // Converting voltage to degrees 
};

void loop() {
  int s1 = int(analogRead(A0)); // Reading data from Analog port A0
  int s2 = int(analogRead(A1)); // Reading data from Analog port A1
  int s3 = int(analogRead(A2)); // Reading data from Analog port A2
  int s4 = int(analogRead(A3)); // Reading data from Analog port A3
  int s5 = int(analogRead(A4)); // Reading data from Analog port A4
  String sensors_reading[] = {reverse(s1), reverse(s2), normal(s3), normal(s4), normal(s5)}; // Creating a dictionary where we have stored each value, 
                                                                                        // with reversed values included
  //Data Transmission to the python code via serial port
  String Read = String(Serial.read()); // reading the serial port
  
  if (Read = "A"){                     // If we recieve an "A" through the serial port, we send the data
  String Info = "  " + sensors_reading[0] + "  " + sensors_reading[1] + "  " +  sensors_reading[2] + "  " + sensors_reading[3] + "  " + sensors_reading[4] + "  ";
  Serial.println(Info); //We Send the data
  }
  
  delay(150); // 1s of delay, to avoid overflow
} 
