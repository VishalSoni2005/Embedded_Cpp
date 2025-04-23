#include <xc.h>
#include <pic18f4550.h>

// Configuration Bits (adjust as needed)
#pragma config FOSC = HS    // High-Speed Oscillator
#pragma config WDT = OFF    // Watchdog Timer Disabled
#pragma config LVP = OFF    // Low-Voltage Programming Disabled
#pragma config PBADEN = OFF // PORTB<4:0> configured as digital on reset

#define _XTAL_FREQ 8000000  // 6->0 Define clock frequency (for __delay_ms)

//* LATAbits.LAx is bitwise access to LAT register for PORTA pins
#define LCD_EN LATAbits.LA1 // Enable pin for LCD
#define LCD_RS LATAbits.LA0 // Register Select pin
#define LCDPORT LATB        // LCD Data lines D0-D7

//* we are using PortA because we are using LATAbits.LAx for RS and EN pins and PortB is used  for data lines

// Software delay function
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
// Send character data to LCD
void SendData(unsigned char LcdData)
{
  LCD_RS = 1; // Data mode
  LCDPORT = LcdData;
  LCD_EN = 1;

  lcd_delay(10);
  LCD_EN = 0;
  lcd_delay(10);
}

// Send command to LCD
void SendInstruction(unsigned char command)
{
  LCD_RS = 0;        // Instruction mode
  LCDPORT = command; // Put command on data lines
  LCD_EN = 1;        // EN = High

  lcd_delay(10);
  LCD_EN = 0; // EN = Low (Latch command)
  lcd_delay(10);
}

// Initialize LCD
void initLCD(void)
{
  ADCON1 = 0x0F;     // All pins digital
  TRISB = 0x00;      // Port B as output (LCD data lines)
  TRISAbits.RA0 = 0; // RS pin as output
  TRISAbits.RA1 = 0; // EN pin as output

  SendInstruction(0x38); // 8-bit mode, 2 lines, 5x7 font
  SendInstruction(0x06); // Entry mode: increment cursor
  SendInstruction(0x0C); // Display ON, cursor OFF
  SendInstruction(0x01); // Clear display
  SendInstruction(0x80); // Cursor to beginning (line 1)
}

// Main Program
void main(void)
{
  initLCD(); // Initialize LCD

  unsigned char *string1 = "Microchip";
  unsigned char *string2 = "PIC18F4550";

  // Print first line
  while (*string1)
  {
    SendData(*string1);
    string1++;
  }

  SendInstruction(0xC0); // Move cursor to 2nd line

  // Print second line
  while (*string2)
  {
    SendData(*string2);
    string2++;
  }

  while (1)
    ; // Infinite loop to keep displaying
}
