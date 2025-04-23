#include <xc.h>
#include <pic18f4550.h>

#pragma config FOSC = HS    // High-Speed Oscillator
#pragma config WDT = OFF
#pragma config LVP = OFF
#pragma config PBADEN = OFF // PORTB<4:0> configured as digital on reset

#define _XTAL_FREQ 8000000  // Define clock frequency (for __delay_ms)
#define LCDPORT LATB        // LCD Data lines D0-D7
#define LCD_EN LATAbits.LA1 // Enable pin for LCD
#define LCD_RS LATAbits.LA0 // Register Select pin

void lcd_delay(unsigned int time)
{
  unsigned int i, j;
  for (i = 0; i < time; i++)
  {
    for (j = 0; j < 100; j++)
    {
      // Do nothing - simple delay loop
    }
  }
}