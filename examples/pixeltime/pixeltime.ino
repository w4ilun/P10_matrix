//for P10 16x32
#define PATTERN4
//uncomment for P5 32x64
//#define P5_PATTERN16
#include <Ticker.h>
#include <P10_matrix.h>

Ticker display_ticker;

// Pins for LED MATRIX
#define P_LAT 16
#define P_A 5
#define P_B 4
#define P_C 15
#define P_OE 2
//uncomment for P5 32x64
//#define P_D 12
//for P10 16x32
P10_MATRIX display( P_LAT, P_OE,P_A,P_B,P_C);
//uncomment for P5 32x64
//P10_MATRIX display( P_LAT, P_OE,P_A,P_B,P_C,P_D);

// Some standard colors
uint16_t myRED = display.color565(255, 0, 0);
uint16_t myGREEN = display.color565(0, 255, 0);
uint16_t myBLUE = display.color565(0, 0, 255);
uint16_t myWHITE = display.color565(255, 255, 255);
uint16_t myYELLOW = display.color565(255, 255, 0);
uint16_t myCYAN = display.color565(0, 255, 255);
uint16_t myMAGENTA = display.color565(255, 0, 255);
uint16_t myBLACK = display.color565(0, 0, 0);

uint16 myCOLORS[8]={myRED,myGREEN,myBLUE,myWHITE,myYELLOW,myCYAN,myMAGENTA,myBLACK};

uint8_t weather_icons[]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0xff,0xe0,0x00,0x00,0x00,0x00,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xff,0x07,0xff,0x07,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x07,0xff,0x07,0xff,0x07,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xff,0x07,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xdf,0x07,0xdf,0x07,0xdf,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x20,0x07,0xff,0x07,0xff,0x07,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xff,0x00,0x00,0x00,0x00,0x07,0xff,0x07,0xff,0x07,0xdf,0x00,0x00,0x00,0x00,0x07,0xff,0x00,0x00,0x00,0x00,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0xff,0xe0,0x00,0x00,0xff,0xe0,0xff,0xe0,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xff,0x07,0xdf,0x07,0xff,0x07,0xff,0x07,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x00,0x00,0x00,0x00,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xff,0x07,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xff,0x07,0xff,0x00,0x00,0x00,0x00,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0x00,0x00,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0x00,0x00
,0x00,0x20,0x00,0x00,0x00,0x00,0xff,0xe0,0xff,0xe0,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xff,0x07,0xff,0x07,0xff,0xff,0xe0,0xff,0xe0,0xff,0xe0,0x00,0x00,0xff,0xe0,0x00,0x00,0x07,0xff,0x07,0xff,0x07,0xdf,0x07,0xff,0x07,0xdf,0x07,0xff,0x07,0xff,0x00,0x00,0x00,0x00,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x00,0x00,0x00,0x00,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xdf,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x00,0x00,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xdf,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xff,0x00,0x00,0x07,0xff,0x07,0xff,0x07,0xff,0x00,0x00,0x07,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0x00,0x00,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0x07,0xdf,0x07,0xdf,0x07,0xff,0xff,0xe0,0xff,0xe0,0x00,0x00
,0x00,0x00,0xff,0xe0,0x00,0x00,0xff,0xe0,0xff,0xe0,0xff,0xe0,0x00,0x00,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xff,0x07,0xdf,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0xff,0xe0,0x00,0x20,0x00,0x00,0x07,0xdf,0x07,0xdf,0x07,0xdf,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x00,0x00,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x00,0x00,0x00,0x00,0x07,0xff,0x07,0xff,0x07,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xdf,0x07,0xdf,0x07,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0x00,0x00,0x00,0x00,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0xff,0xff,0x07,0xff,0x07,0xff,0x07,0xdf,0x07,0xff,0x00,0x00,0x07,0xff,0x00,0x00,0x00,0x00,0x07,0xff,0x07,0xff,0x07,0xdf,0x00,0x00,0x00,0x00,0x07,0xff,0x00,0x00,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0x00,0x00,0xff,0xe0,0xff,0xe0,0xff,0xe0,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xe0,0xff,0xe0,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xdf,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x00,0x00,0x00,0x00,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x00,0x00,0x00,0x00,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x07,0xff,0x00,0x20,0xff,0xff,0x00,0x00,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xff,0x00,0x00,0xff,0xff,0x00,0x00,0xff,0xff,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xdf,0x00,0x00,0x07,0xff,0x07,0xff,0x07,0xdf,0x00,0x00,0x07,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xff,0x07,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xff,0x07,0xdf,0x00,0x00,0x00,0x00,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0x00,0x00,0xff,0xe0,0xff,0xe0,0x07,0xdf,0x07,0xdf,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x00,0x00
,0x00,0x00,0x00,0x00,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x00,0x00,0x00,0x00,0xff,0xe0,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0x00,0x00,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xe0,0x00,0x00,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0x00,0x00,0xff,0xe0,0xff,0xe0,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xdf,0x07,0xdf,0x07,0xff,0x07,0xff,0x07,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0x00,0x00,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0x00,0x00,0xff,0xff,0x00,0x00,0x00,0x00,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x07,0xff,0x07,0xff,0x07,0xff,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xff,0x00,0x00,0x00,0x00,0x07,0xff,0x07,0xdf,0x07,0xff,0x00,0x00,0x00,0x00,0x07,0xff,0x00,0x00,0x00,0x00,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xe0,0xff,0xe0,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xff,0x07,0xff,0x07,0xff,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x07,0xff,0x07,0xdf,0x07,0xdf,0x07,0xff,0x07,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0x00,0x00,0xff,0xff,0x00,0x00,0x00,0x00,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xff,0x07,0xdf,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xff,0x07,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xe0,0xff,0xe0,0x07,0xdf,0x07,0xff,0x07,0xff,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};


// ISR for display refresh
void display_updater()
{
  display.display(70);
  //shows the icons on P5
  //display.display(30);
}
void setup() {
  // put your setup code here, to run once:

  display.begin();
  display.clearDisplay();
  display.setTextColor(myCYAN);
  display.setCursor(2,0);
  display.print("Pixel");
  display.setTextColor(myMAGENTA);
  display.setCursor(2,8);
  display.print("Time");

  Serial.begin(9600);
  display_ticker.attach(0.001, display_updater);
  yield();
  delay(3000);
  display.clearDisplay();
}
union single_double{
  uint8_t two[2];
  uint16_t one;
} this_single_double;

// This draws the weather icons
void draw_weather_icon (uint8_t icon)
{
  if (icon>10)
  icon=10;
  for (int yy=0; yy<10;yy++)
  {
    for (int xx=0; xx<10;xx++)
    {
      uint16_t byte_pos=(xx+icon*10)*2+yy*220;
      this_single_double.two[1]=weather_icons[byte_pos];
      this_single_double.two[0]=weather_icons[byte_pos+1];
      display.drawPixel(1+xx,yy,this_single_double.one);
    }
  }
}


uint8_t icon_index=0;
void loop() {

  display.clearDisplay();
  draw_weather_icon(icon_index);
  icon_index++;
  if (icon_index>10)
    icon_index=0;
  delay(3000);
}
