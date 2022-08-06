String reverse(int x){
    return String(map(x, 0, 4095, 180, 0)); // Reversing the values if needed
    };

String normal(int s){
  return String(map(s, 0, 4095, 0, 180)); // Converting voltage to degrees 
};
