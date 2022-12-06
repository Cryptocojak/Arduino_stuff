/*
7-Segment Display CC (5611AS) controlled with 74HC595N shift register :)

  < [  A  ] >       
 [ ]       [ ]            
 [F]       [B]             
 [ ]       [ ]             
  < [  G  ] >            
 [ ]       [ ]            
 [E]       [C]             
 [ ]       [ ]            
  < [  D  ] >  (DP)   
       
  |A|B|C|D|E|F|G|DP| 
1=|0|1|1|0|0|0|0| 0|  / BC      /  01100000  /  0x60
2=|1|1|0|1|1|0|1| 0|  / ABDEG   /  11011010  /  0xda
3=|1|1|1|1|0|0|1| 0|  / ABCDG   /  11110010  /  0xf2
4=|0|1|1|0|0|1|1| 0|  / BCFG    /  01100110  /  0x66
5=|1|0|1|1|0|1|1| 0|  / ACDFG   /  10110110  /  0xb6
6=|1|0|1|1|1|1|1| 0|  / ACDEFG  /  10111110  /  0xbe
7=|1|1|1|0|0|0|0| 0|  / ABC     /  11100000  /  0xe0
8=|1|1|1|1|1|1|1| 0|  / ABCDEFG /  11111110  /  0xfe
9=|1|1|1|0|0|1|1| 0|  / ABCFG   /  11100110  /  0xe6
0=|1|1|1|1|1|1|0| 0|  / ABCDEF  /  11111100  /  0xfc
.=|0|0|0|0|0|0|0| 1|  / DP      /  00000001  /  0x01
A=|1|1|1|0|1|1|1| 0|  / ABCEFG  /  11101110  /  0xee
B=|0|0|1|1|1|1|1| 0|  / CDEFG   /  00111110  /  0x3e
C=|1|0|0|1|1|1|0| 0|  / ADEF    /  10011100  /  0x9c
D=|0|1|1|1|1|0|1| 0|  / BCDEG   /  01111010  /  0x7a
E=|1|0|0|1|1|1|1| 0|  / ADEFG   /  10011110  /  0x9e
F=|1|0|0|0|1|1|1| 0|  / AEFG    /  10001110  /  0x8e
*/

#define SHIFT_DATA 2
#define SHIFT_CLK 3
#define SHIFT_LATCH 4

#define DIGIT_1 10
#define DIGIT_2 11
#define DIGIT_3 12
#define DIGIT_4 13

byte _1  = 0x60;
byte _2  = 0xda;
byte _3  = 0xf2;
byte _4  = 0x66;
byte _5  = 0xb6;
byte _6  = 0xbe;
byte _7  = 0xe0;
byte _8  = 0xfe;
byte _9  = 0xe6;
byte _0  = 0xfc;
byte _DP = 0x01;
byte _a  = 0xee;
byte _b  = 0x3e;
byte _c  = 0x9c;
byte _d  = 0x7a;
byte _e  = 0x9e;
byte _f  = 0x8e;

const int frameRate = 1;
const int scrollSpeed = 55;

void setSegments(byte segments) {
  shiftOut(SHIFT_DATA, SHIFT_CLK, LSBFIRST, segments);
  digitalWrite(SHIFT_LATCH, LOW);
  digitalWrite(SHIFT_LATCH, HIGH);
  digitalWrite(SHIFT_LATCH, LOW);
}

void clearSegments() {
  shiftOut(SHIFT_DATA, SHIFT_CLK, LSBFIRST, 0x00);
  digitalWrite(SHIFT_LATCH, LOW);
  digitalWrite(SHIFT_LATCH, HIGH);
  digitalWrite(SHIFT_LATCH, LOW);
}

void mux(byte one, byte two, byte three, byte four) {
  for (int i = 0; i < scrollSpeed; i++) {
    digitalWrite(DIGIT_1, HIGH); setSegments(one);
    delay(frameRate); clearSegments(); digitalWrite(DIGIT_1, LOW);
    

    digitalWrite(DIGIT_2, HIGH); setSegments(two);
    delay(frameRate); clearSegments(); digitalWrite(DIGIT_2, LOW);
   

    digitalWrite(DIGIT_3, HIGH); setSegments(three);
    delay(frameRate); clearSegments(); digitalWrite(DIGIT_3, LOW);
    

    digitalWrite(DIGIT_4, HIGH); setSegments(four);
    delay(frameRate); clearSegments(); digitalWrite(DIGIT_4, LOW);
  }
}

void setup() {
pinMode(SHIFT_DATA, OUTPUT);
pinMode(SHIFT_CLK, OUTPUT);
pinMode(SHIFT_LATCH, OUTPUT);
}

void loop() {
  
  //Test loop//

  mux(_1, _3, _3, _7);
  mux(_3, _3, _7, _DP);
  mux(_3, _7, _DP, _DP);
  mux(_7, _DP, _DP, _a);
  mux(_DP, _DP, _a, _c);
  mux(_DP, _a, _c, _a);
  mux(_a, _c, _a, _b);
  mux(_c, _a, _b, _DP);
  mux(_a, _b, _DP, _DP);
  mux(_b, _DP, _DP, _1);
  mux(_DP, _DP, _1, _3);
  mux(_DP, _1, _3, _3);

}
