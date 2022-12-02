// 4 digits (pins 10-13) //

#define DIGIT_1 10
#define DIGIT_2 11
#define DIGIT_3 12
#define DIGIT_4 13

// Digital out pins 2-9 from arduino //
// Bottom 4 pins in on the 7 segment display (left to right), then top 4 pins (left to right) //
// (2, 3, 4, 5, 6, 7, 8, 9) //
//  |  |  |  |  |  |  |  |  //
// (E, D, C, ., G, F, A, B) // 

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

// global delay between digits (framerate) //
int D = 1;

// time constant for each 4-digit "message" (scroll speed) //
int time = 55;

// functions //

void outputMode() {
   for (int pin = 2; pin <=13; pin +=1) {
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

void mux(int num1[], int length1, int num2[], int length2, int num3[], int length3, int num4[], int length4) {
  for (long i = 0; i < time; i++) {
    digitalWrite(DIGIT_1, HIGH); printDigit(num1, length1); digitalWrite(DIGIT_1, LOW);
    digitalWrite(DIGIT_2, HIGH); printDigit(num2, length2); digitalWrite(DIGIT_2, LOW);
    digitalWrite(DIGIT_3, HIGH); printDigit(num3, length3); digitalWrite(DIGIT_3, LOW);
    digitalWrite(DIGIT_4, HIGH); printDigit(num4, length4); digitalWrite(DIGIT_4, LOW);
  }
}

void setup() {
  outputMode();
}

void loop() {

  mux(n_1, 2, n_3, 5, n_3, 5, n_7, 3);
  mux(n_3, 5, n_3, 5, n_7, 3, dot_, 1);
  mux(n_3, 5, n_7, 3, dot_, 1, dot_, 1);
  mux(n_7, 3, dot_, 1, dot_, 1, dot_, 1);
  mux(dot_, 1, dot_, 1, dot_, 1, dot_, 1);
  mux(dot_, 1, dot_, 1, dot_, 1, l_A, 6);
  mux(dot_, 1, dot_, 1, l_A, 6, l_C, 4);
  mux(dot_, 1, l_A, 6, l_C, 4, l_A, 6);
  mux(l_A, 6, l_C, 4, l_A, 6, l_B, 5);
  mux(l_C, 4, l_A, 6, l_B, 5, dot_, 1);
  mux(l_A, 6, l_B, 5, dot_, 1, dot_, 1);
  mux(l_B, 5, dot_, 1, dot_, 1, dot_, 1);
  mux(dot_, 1, dot_, 1, dot_, 1, dot_, 1);
  mux(dot_, 1, dot_, 1, dot_, 1, n_1, 2);
  mux(dot_, 1, dot_, 1, n_1, 2, n_3, 5);
  mux(dot_, 1, n_1, 2, n_3, 5, n_3, 5);
   
}
