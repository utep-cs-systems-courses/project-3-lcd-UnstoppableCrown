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

main()
{
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_BLUE);

  for (int i=0; i< 20; i++) {
    drawPixel(i,i,COLOR_RED);
  }
}
