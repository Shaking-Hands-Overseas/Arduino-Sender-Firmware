void setup() {
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
}
String reverse(int x){
    return String(map(x, 0, 180, 180, 0)); // Reversing the values if needed
  };

void loop() {
  int y = int(analogRead(A0)); // Reading data from Analog port A0
  int x = map(y, 0, 1023, 0, 180); // Converting voltage to degrees 
  String sensors_reading[] = {reverse(x), reverse(x), String(x), String(x), String(x)}; // Creating a dictionary where we have stored each value, 
                                                                                        // with reversed values included

  //Data Transmission to the python code via serial port
  String Read = String(Serial.read()); // reading the serial port
  if (Read = "A"){                     // If we recieve an "A" through the serial port, we send the data
  String Info = "  " + sensors_reading[0] + "  " + sensors_reading[1] + "  " +  sensors_reading[2] + "  " + sensors_reading[3] + "  " + sensors_reading[4] + "  ";
  Serial.println(Info); //We Send the data
  }
  delay(1000); // 1s of delay, to avoid overflow
} 

