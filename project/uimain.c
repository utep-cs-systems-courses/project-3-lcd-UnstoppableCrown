#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

#define LED BIT6

#define SW1 1
#define SW2 2
#define SW3 4
#define SW4 8

#define SWITCHES 15


short redrawScreen = 1;

void wdt_c_handler()
{
  
}

void drawSquare(int x, int y, int size) {
  for (int i = 0; i<size; i++) {
    drawPixel(x-(size/2),y-(size/2)+i,COLOR_RED);
    drawPixel(x+(size/2),y-(size/2)+i,COLOR_RED);
    drawPixel(i+x-(size/2),y-(size/2),COLOR_RED);
    drawPixel(i+x-(size/2),y+(size/2),COLOR_RED);
  }
}

void drawTriangle(int x, int y, int size) {
  //drawPixel(screenWidth/2, screenHeight/2-10, COLOR_RED);
  for (int i = 0; i<size; i++) {
    drawPixel(x-i,y-(size/2)+i, COLOR_RED);
    drawPixel(x+i, y-(size/2)+i, COLOR_RED);
    drawPixel(x-i, y+(size/2), COLOR_RED);
    drawPixel(x+size-i, y+(size/2), COLOR_RED);
  }
}

void drawX(int x, int y, int size) {
  for (int i = 0; i<size; i++) {
    drawPixel(x-i+(size/2), y+i, COLOR_RED);
    drawPixel(x+i-(size/2), y+i, COLOR_RED);
  }
}

void drawRectangle(int x, int y, int size) {
  for (int i = 0; i<size; i++) {
    drawPixel(x-(size/2),y-(size/2)+i,COLOR_RED);
    drawPixel(x+(size/2),y-(size/2)+i,COLOR_RED);
    drawPixel(x-(size/2),y+i,COLOR_RED);
    drawPixel(x+(size/2),y+i,COLOR_RED);
    drawPixel(i+x-(size/2),y-(size/2),COLOR_RED);
    drawPixel(i+x-(size/2),y+size,COLOR_RED);
  }
}

void 
main()
{
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_BLUE);

  drawSquare(15, screenHeight-15, 14);
  drawTriangle(45,screenHeight-15, 12);
  drawX(75, screenHeight-22, 14);
  drawRectangle(105, screenHeight-22, 14);
}
