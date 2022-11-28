//Digital out pins 2-9 from arduino.
//Bottom 4 pins in on the 7 segment display,
//then top 4 pins (left to right) 

int n_1[2] = { 4, 9 };
int n_2[5] = { 2, 3, 6, 8, 9 };
int n_3[5] = { 3, 4, 6, 8, 9 };
int n_4[4] = { 4, 6, 7, 9 };
int n_5[5] = { 3, 4, 6, 7, 8 };
int n_6[6] = { 2, 3, 4, 6, 7, 8 };
int n_7[3] = { 4, 8, 9 };
int n_8[7] = { 2, 3, 4, 6, 7, 8, 9 };
int n_9[5] = { 4, 6, 7, 8, 9 };
int n_0[6] = { 2, 3, 4, 7, 8, 9 };

int l_A[6] = { 2, 4, 6, 7, 8, 9 };
int l_B[5] = { 2, 3, 4, 6, 7 };
int l_C[4] = { 2, 3, 7, 8 };
int l_D[5] = { 2, 3, 4, 6, 9 };
int l_E[5] = { 2, 3, 6, 7, 8 };
int l_F[4] = { 2, 6, 7, 8 };

int dot_[1] = { 5 };

// global delay between digits
long D = 250;

// functions 

void outputMode() {
   for (int pin = 2; pin <=9; pin +=1) {
    pinMode(pin, OUTPUT);
  }
}

void clearDisplay() {
  delay(D);
  for (int pin = 2; pin <=9; pin +=1) {
    digitalWrite(pin, LOW);
  }
}

void printDigit(int num[], int length) {
  for (byte i = 0; i < length; i++) {
    digitalWrite(num[i], HIGH);
  }
clearDisplay();
}

void setup() {
  outputMode();

  printDigit(n_0, 6);
  printDigit(n_1, 2);
  printDigit(n_2, 5);
  printDigit(n_3, 5);
  printDigit(n_4, 4);
  printDigit(n_5, 5);
  printDigit(n_6, 6);
  printDigit(n_7, 3);
  printDigit(n_8, 7);
  printDigit(n_9, 5);
  printDigit(dot_, 1);
  printDigit(l_A, 6);
  printDigit(l_C, 4);
  printDigit(l_A, 6);
  printDigit(l_B, 5);
  printDigit(dot_, 1);
}

void loop() {}
