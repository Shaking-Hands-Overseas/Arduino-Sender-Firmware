int A[] = {36, 39, 32, 34, 35};
int maxes[] = {0, 0, 0, 0, 0};
int mins[] = {180,180,180,180,180};

void setup() {
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
}
String reverse(int x){
    return String(map(x, 0, 4095, 180, 0)); // Reversing the values if needed
  };

String normal(int s){
  return String(map(s, 0, 4095, 0, 180)); // Converting voltage to degrees 
};

void loop() {
  int s[] = {analogRead(A[0]), analogRead(A[1]), analogRead(A[2]), analogRead(A[3]), analogRead(A[4])}; //Reading data from Analog ports A0-A4

  for (int i = 0; i < 5; i++){
    if (s[i] > maxes[i])
      maxes[i] = s[i];
    if (s[i] < mins[i])
      mins[i] = s[i];

    s[i] = map(s[i], mins[i], maxes[i], 0, 4095); 
  }
  
  String sensors_reading[] = {reverse(s[0]), normal(s[1]), normal(s[2]), reverse(s[3]), normal(s[4])}; // Creating a dictionary where we have stored each value, 
                                                                                        // with reversed values included
  //Data Transmission to the python code via serial port
  char Read[100];
  Serial.readBytesUntil('A', Read, 100);
  
  String Info = "  " + sensors_reading[0] + "  " + sensors_reading[1] + "  " +  sensors_reading[2] + "  " + sensors_reading[3] + "  " + sensors_reading[4] + "  ";
  Serial.println(Info); //We Send the data
  
  delay(150); // 1s of delay, to avoid overflow
} 
