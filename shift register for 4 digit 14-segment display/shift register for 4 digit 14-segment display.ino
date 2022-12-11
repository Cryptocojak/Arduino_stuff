/*
2-Digit, 14-Segment Display CC (KWA-541CVB)

  < [-----A-----] >          < [-----A-----] > 
 [ \ \   | |   / / ]        [ \ \   | |   / / ]
 [ ]\H\  | |  /K/[ ]        [ ]\H\  | |  /K/[ ]      
 [F] \ \ |J| / / [B]        [F] \ \ |J| / / [B]       
 [ ]  \ \| |/ /  [ ]        [ ]  \ \| |/ /  [ ]
  v    \ | | /    v          v    \ | | /    v
  <[ G1 ]> <[ G2 ]>          <[ G1 ]> <[ G2 ]> 
  ^    / | | \    ^          ^    / | | \    ^
 [ ]  / /| |\ \  [ ]        [ ]  / /| |\ \  [ ]
 [E] / / |M| \ \ [C]        [E] / / |M| \ \ [C]
 [ ]/L/  | |  \N\[ ]        [ ]/L/  | |  \N\[ ] 
 [ / /   | |   \ \ ]        [ / /   | |   \ \ ]
  < [-----D-----] >  (DP)    < [-----D-----] >  (DP)   
       
  |A|B|C|D|E|F|G1|G2|H|J|K|L|M|N|DP|0|  / segment    /  binary            /  hex    /
-------------------------------------------------------------------------------------  
1=|0|1|1|0|0|0|0 |0 |0|0|0|0|0|0|0 |0|  / BC         /  0110000000000000  /  0x6000 /
2=|1|1|0|1|1|0|1 |1 |0|0|0|0|0|0|0 |0|  / ABDEG1G2   /  1101101100000000  /  0xdb00 /
3=|1|1|1|1|0|0|1 |1 |0|0|0|0|0|0|0 |0|  / ABCDG1G2   /  1111001100000000  /  0xf300 /
4=|0|1|1|0|0|1|1 |1 |0|0|0|0|0|0|0 |0|  / BCFG1G2    /  0110011100000000  /  0x6700 /
5=|1|0|1|1|0|1|1 |1 |0|0|0|0|0|0|0 |0|  / ACDFG1G2   /  1011011100000000  /  0xb700 /
6=|1|0|1|1|1|1|1 |1 |0|0|0|0|0|0|0 |0|  / ACDEFG1G2  /  1011111100000000  /  0xbf00 /
7=|1|1|1|0|0|0|0 |0 |0|0|0|0|0|0|0 |0|  / ABC        /  1110000000000000  /  0xe000 /
8=|1|1|1|1|1|1|1 |1 |0|0|0|0|0|0|0 |0|  / ABCDEFG1G2 /  1111111100000000  /  0xff00 /
9=|1|1|1|0|0|1|1 |1 |0|0|0|0|0|0|0 |0|  / ABCFG1G2   /  1110011100000000  /  0xe700 /
0=|1|1|1|1|1|1|0 |0 |0|0|1|1|0|0|0 |0|  / ABCDEF     /  1111110000110000  /  0xfc30 /
.=|0|0|0|0|0|0|0 |0 |0|0|0|0|0|0|1 |0|  / DP         /  0000000000000010  /  0x0002 /
A=|1|1|1|0|1|1|1 |1 |0|0|0|0|0|0|0 |0|  / ABCEFG1G2  /  1110111100000000  /  0xef00 /
B=|0|0|1|1|1|1|1 |1 |0|0|0|0|0|0|0 |0|  / CDEFG1G2   /  0011111100000000  /  0x3f00 /
C=|1|0|0|1|1|1|0 |0 |0|0|0|0|0|0|0 |0|  / ADEF       /  1001110000000000  /  0x9c00 /
D=|0|1|1|1|1|0|1 |1 |0|0|0|0|0|0|0 |0|  / BCDEG1G2   /  0111101100000000  /  0x7b00 /
E=|1|0|0|1|1|1|1 |1 |0|0|0|0|0|0|0 |0|  / ADEFG1G2   /  1001111100000000  /  0x9f00 /
F=|1|0|0|0|1|1|1 |0 |0|0|0|0|0|0|0 |0|  / AEFG1      /  1000111000000000  /  0x8e00 /
G=|1|0|1|1|1|1|0 |1 |0|0|0|0|0|0|0 |0|  / ACDEFG2    /  1011110100000000  /  0Xbd00 /
H=|0|1|1|0|1|1|1 |1 |0|0|0|0|0|0|0 |0|  / BCEFG1G2   /  0110111100000000  /  0x6f00 /
I=|1|0|0|1|0|0|0 |0 |0|1|0|0|1|0|0 |0|  / ADJM       /  1001000001001000  /  0x9048 /
J=|0|1|1|1|1|0|0 |0 |0|0|0|0|0|0|0 |0|  / BCDE       /  0111100000000000  /  0x7800 /
K=|0|0|0|0|1|1|1 |0 |0|0|1|0|0|1|0 |0|  / EFG1KN     /  0000111000100100  /  0x0e24 /
L=|0|0|0|1|1|1|0 |0 |0|0|0|0|0|0|0 |0|  / DEF        /  0001110000000000  /  0x1c00 /
M=|0|1|1|0|1|1|0 |0 |1|0|1|0|0|0|0 |0|  / BCEFHK     /  0110110010100000  /  0x6ca0 /
N=|0|1|1|0|1|1|0 |0 |1|0|0|0|0|1|0 |0|  / BCEFHN     /  0110110010000100  /  0x6c84 /
O=|1|1|1|1|1|1|0 |0 |0|0|0|0|0|0|0 |0|  / ABCDEF     /  1111110000000000  /  0xfc00 /
P=|1|1|0|0|1|1|1 |1 |0|0|0|0|0|0|0 |0|  / ABEFG1G2   /  1100111100000000  /  0xcf00 /
Q=|1|1|1|1|1|1|0 |0 |0|0|0|0|0|1|0 |0|  / ABCDEFN    /  1111110000000100  /  0xfc04 /
R=|1|1|0|0|1|1|1 |1 |0|0|0|0|0|1|0 |0|  / ABEFG1G2N  /  1100111100000100  /  0xcf04 /
S=|1|0|1|1|0|1|1 |1 |0|0|0|0|0|0|0 |0|  / ACDFG1G2   /  1011011100000000  /  0xb700 /
T=|1|0|0|0|0|0|0 |0 |0|1|0|0|1|0|0 |0|  / AJM        /  1000000001001000  /  0x8048 /
U=|0|1|1|1|1|1|0 |0 |0|0|0|0|0|0|0 |0|  / BCDEF      /  0111110000000000  /  0x7c00 /
V=|0|0|0|0|1|1|0 |0 |0|0|1|1|0|0|0 |0|  / EFKL       /  0000110000110000  /  0x0c30 /
W=|0|1|1|0|1|1|0 |0 |0|0|0|1|0|1|0 |0|  / BCEFLN     /  0110110000010100  /  0x6c14 /
X=|0|0|0|0|0|0|0 |0 |1|0|1|1|0|1|0 |0|  / HKLN       /  0000000010110100  /  0x00b4 /
Y=|0|0|0|0|0|0|0 |0 |1|0|1|0|1|0|0 |0|  / HKM        /  0000000010101000  /  0x00a8 /
Z=|1|0|0|1|0|0|0 |0 |0|0|1|1|0|0|0 |0|  / ADKL       /  1001000000110000  /  0x9030 /
*/

#define SHIFT_DATA 2
#define SHIFT_CLK 3
#define SHIFT_LATCH 4

#define DIGIT_1 10
#define DIGIT_2 11
#define DIGIT_3 12
#define DIGIT_4 13

int _1 = 0x6000; int _2 = 0xdb00; int _3 = 0xf300; int _4 = 0x6700; int _5 = 0xb700;
int _6 = 0xbf00; int _7 = 0xe000; int _8 = 0xff00; int _9 = 0xe700; int _0 = 0xfc30;

int _DP = 0x0002;

int _A = 0xef00; int _B = 0x3f00; int _C = 0x9c00; int _D = 0x7b00; int _E = 0x9f00; int _F = 0x8e00; int _G = 0Xbd00; int _H = 0x6f00; int _I = 0x9048;
int _J = 0x7800; int _K = 0x0e24; int _L = 0x1c00; int _M = 0x6ca0; int _N = 0x6c84; int _O = 0xfc00; int _P = 0xcf00; int _Q = 0xfc04; int _R = 0xcf04;
int _S = 0xb700; int _T = 0x8048; int _U = 0x7c00; int _V = 0x0c30; int _W = 0x6c14; int _X = 0x00b4; int _Y = 0x00a8; int _Z = 0x9030; int __ = 0x0000;

const int frameRate = 1;
const int scrollSpeed = 55;

void setSegments(int segments) {
  shiftOut(SHIFT_DATA, SHIFT_CLK, LSBFIRST, segments);
  shiftOut(SHIFT_DATA, SHIFT_CLK, LSBFIRST, (segments >> 8));
  digitalWrite(SHIFT_LATCH, LOW);
  digitalWrite(SHIFT_LATCH, HIGH);
  digitalWrite(SHIFT_LATCH, LOW);
}

void clearSegments() {
  shiftOut(SHIFT_DATA, SHIFT_CLK, LSBFIRST, 0x0000);
  shiftOut(SHIFT_DATA, SHIFT_CLK, LSBFIRST, 0x0000);
  digitalWrite(SHIFT_LATCH, LOW);
  digitalWrite(SHIFT_LATCH, HIGH);
  digitalWrite(SHIFT_LATCH, LOW);
}

void mux(int one, int two, int three, int four) {
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
mux(__, __, __, __); mux(__, __, __, _A); mux(__, __, _A, _B); mux(__, _A, _B, _C); mux(_A, _B, _C, _D);
mux(_B, _C, _D, _E); mux(_C, _D, _E, _F); mux(_D, _E, _F, _G); mux(_E, _F, _G, _H); mux(_F, _G, _H, _I);
mux(_G, _H, _I, _J); mux(_H, _I, _J, _K); mux(_I, _J, _K, _L); mux(_J, _K, _L, _M); mux(_K, _L, _M, _N); 
mux(_L, _M, _N, _O); mux(_M, _N, _O, _P); mux(_N, _O, _P, _Q); mux(_O, _P, _Q, _R); mux(_P, _Q, _R, _S);
mux(_Q, _R, _S, _T); mux(_R, _S, _T, _U); mux(_S, _T, _U, _V); mux(_T, _U, _V, _W); mux(_U, _V, _W, _X);
mux(_V, _W, _X, _Y); mux(_W, _X, _Y, _Z); mux(_X, _Y, _Z, __); mux(_Y, _Z, __, __); mux(_Z, __, __, __);

}
