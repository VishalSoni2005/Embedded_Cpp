#include <pic18f4550.h>
#include <xc.h>
#include <stdio.h>

#define LCD_EN LATAbits.LA1
#define LCD_RS LATAbits.LA0
#define LCDPORT LATB

unsigned char str[16];

// Delay for LCD
void lcd_delay(unsigned int time)
{
  unsigned int i, j;
  for (i = 0; i < time; i++)
  {
    for (j = 0; j < 100; j++)
    {
    }
  }
}

// Send Command to LCD
void SendInstruction(unsigned char command)
{
  LCD_RS = 0;
  LCDPORT = command;
  LCD_EN = 1;
  lcd_delay(10);
  LCD_EN = 0;
  lcd_delay(10);
}

// Send Data to LCD
void SendData(unsigned char lcddata)
{
  LCD_RS = 1;
  LCDPORT = lcddata;
  LCD_EN = 1;
  lcd_delay(10);
  LCD_EN = 0;
  lcd_delay(10);
}

// Initialize LCD
void InitLCD(void)
{
  ADCON1 = 0x0F;     // Set all AN pins as digital
  TRISB = 0x00;      // Port B as output for LCD
  TRISAbits.RA0 = 0; // RS pin as output
  TRISAbits.RA1 = 0; // EN pin as output

  SendInstruction(0x38); // 8-bit, 2 line, 5x7 dots
  SendInstruction(0x06); // Entry mode
  SendInstruction(0x0C); // Display ON, cursor OFF
  SendInstruction(0x01); // Clear display
  SendInstruction(0x80); // Cursor to beginning
}

// Display String on LCD
void LCD_display(unsigned int row, unsigned int pos, unsigned char *ch)
{
  if (row == 1)
  {
    SendInstruction(0x80 | (pos - 1));
  }
  else
  {
    SendInstruction(0xC0 | (pos - 1));
  }
  while (*ch)
  {
    SendData(*ch++);
  }
}

// Initialize ADC
void ADCInit(void)
{
  TRISEbits.RE2 = 1;   // RE2/AN7 as input
  ADCON0 = 0b0000111;  // Select channel AN7
  ADCON2 = 0b10101110; // Right justified, Tacq=12TAD, Fosc/64
}

// Read Temperature Value
unsigned short Read_Temp(void)
{
  ADCON0 = 0b00011101; // Start conversion on AN7
  GODONE = 1;
  while (GO_DONE == 1)
    ;
  return ADRES;
}

// Main Function
void main(void)
{
  unsigned int temp;

  InitLCD();
  ADCInit();
  LCD_display(1, 1, "Temp Hinjawadi");

  while (1)
  {
    temp = Read_Temp();
    temp = ((temp * 500) / 1023); // Convert ADC value to temperature
    sprintf(str, "%d", temp);     // Store temperature in string
    LCD_display(2, 1, str);       // Display temperature
    lcd_delay(9000);              // Wait
  }
}
