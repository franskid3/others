// TCS230 or TCS3200 pins wiring to Arduino
#define s0 4
#define s1 5
#define s2 6
#define s3 7
#define outPin 8

boolean DEBUG = true;

// Variables
int red;
int grn;
int blu;
String color ="";
int small = 1000;
int count0 = 0;//WHITE
int count1 = 0;//BLACK
int count2 = 0;//RED
int count3 = 0;//GREEN
int count4 = 0;//YELLOW
int count5 = 0;//BLUE
long startTiming = 0;
long elapsedTime =0;
