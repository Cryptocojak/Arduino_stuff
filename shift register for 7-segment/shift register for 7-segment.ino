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

/*

7-Segment Display (5611AS) = Pinout  
                         A = 7
                         B = 6
                         C = 4        
                         D = 2         
                         E = 1         
                         F = 9         
                         G = 10
                        DP = 5

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

*/

void setSegments(byte segments) {
  shiftOut(SHIFT_DATA, SHIFT_CLK, LSBFIRST, segments);
  digitalWrite(SHIFT_LATCH, LOW);
  digitalWrite(SHIFT_LATCH, HIGH);
  digitalWrite(SHIFT_LATCH, LOW);
}

void setup() {
pinMode(SHIFT_DATA, OUTPUT);
pinMode(SHIFT_CLK, OUTPUT);
pinMode(SHIFT_LATCH, OUTPUT);
}

void loop() {
 //test display 66 
  
  digitalWrite(DIGIT_1, HIGH); setSegments(_6);
  delay(5);
  digitalWrite(DIGIT_1, LOW);

  digitalWrite(DIGIT_2, HIGH); setSegments(_6);
  delay(5);
  digitalWrite(DIGIT_2, LOW);

}
