//! one
#include <xc.h>

void main(void)
{
  int x, y, z;
  TRISC = 0;
  LATC = 0;
  x = 0x02;
  y = 0x05;
  z = x + y;
  PORTA = x;
  PORTB = y;
  PORTC = z;
  return;
}






//! two
#include <xc.h>

void main(void)
{
  int i, sum;
  sum = 0;
  int num[] = {1, 2, 3, 4, 5};
  for (i = 0; i <= 4; i++)
  {
    sum = sum + num[i];
  }
  PORTA = sum;
  return;
}






//! three
#include <xc.h>

void main(void)
{
  int i;
  int arr1[] = {0x21, 0x22, 0x23, 0x24, 0x25};
  int arr2[] = {0x00, 0x00, 0x00, 0x00, 0x00};

  for (i = 0; i <= 5; i++)
  {
    arr1[i] = arr2[i];
  }

  return;
}






//! four

//! DESCENDING

#include <xc.h>
#include <pic18f4550.h>

void delay(void)
{
  for (int i = 0; i < 1000; i++)
    for (int j = 0; j < 100; j++)
      ;
}

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

void main(void)
{
  // int a[] = {0x45, 0x03, 0x06, 0x13, 0x32, 0x02, 0x05, 0x23};
  int a[] = {0x43, 0x12, 0x03, 0x43, 0x23, 0x02, 0x05, 0x23};
  int i, j;
  int size = sizeof(a) / sizeof(a[0]);

  // Bubble sort (descending)
  for (i = 0; i < size - 1; i++)
  {
    for (j = 0; j < size - 1 - i; j++)
    {
      if (a[j] < a[j + 1])
      {
        swap(&a[j], &a[j + 1]);
      }
    }
  }

  TRISD = 0x00; // Set PORTD as output

  for (i = 0; i < size; i++)
  {
    PORTD = a[i];
    delay();
  }

  while (1)
    ; // Infinite loop
}

//! ASSENDING

#include <xc.h>
#include <pic18f4550.h>

void delay(void)
{
  for (int i = 0; i < 1000; i++)
    for (int j = 0; j < 100; j++)
      ;
}

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

void main(void)
{
  int a[] = {0x45, 0x03, 0x06, 0x13, 0x32, 0x02, 0x05, 0x23};
  int i, j;
  int size = sizeof(a) / sizeof(a[0]);

  // Bubble sort (ascending)
  for (i = 0; i < size - 1; i++)
  {
    for (j = 0; j < size - 1 - i; j++)
    {
      if (a[j] > a[j + 1])
      {
        swap(&a[j], &a[j + 1]);
      }
    }
  }

  TRISD = 0x00; // Set PORTD as output

  for (i = 0; i < size; i++)
  {
    PORTD = a[i];
    delay();
  }

  while (1)
    ; // Infinite loop
}







//! five
#include <xc.h>

void delay(unsigned int me)
{
  unsigned int i, j;
  for (i = 0; i < me; i++)
  {
    for (j = 0; j < 5000; j++)
    {
      // Simple delay loop
    }
  }
}

void main(void)
{
  TRISD = 0x00; // Set PORTD as output
  LATD = 0xFF;  // Turn ON all LEDs connected to PORTD

  while (1)
  {
    LATD = ~LATD; // Toggle LEDs (invert all bits)
    delay(200);   // Delay
  }

  return;
}








//! six
#include <xc.h>
#include <pic18f4550.h>

#define Buzzer LATAbits.LATA5

unsigned int count = 0;

// Timer1 Interrupt Service Routine
void interrupt Timer1_ISR()
{
  if (TMR1IF == 1)
  {               // Check if Timer1 interrupt occurred
    TMR1L = 0x20; // Reload Timer1 low byte
    TMR1H = 0xD1; // Reload Timer1 high byte
    count++;      // Increment count

    if (count >= 1000)
    {                   // After 1000 overflows
      Buzzer = ~Buzzer; // Toggle buzzer state
      count = 0;        // Reset count
    }

    TMR1IF = 0; // Clear Timer1 interrupt flag
  }
}

void main(void)
{
  TRISB = 0;            // Set PORTB as output (optional for buzzer)
  TRISAbits.TRISA5 = 0; // Set RA5 (Buzzer pin) as output

  GIE = 1;    // Global Interrupt Enable
  PEIE = 1;   // Peripheral Interrupt Enable
  TMR1IE = 1; // Enable Timer1 interrupt
  TMR1IF = 0; // Clear Timer1 interrupt flag

  T1CON = 0x20; // Timer1 settings (prescaler 1:4)
  TMR1L = 0x20; // Load Timer1 low byte
  TMR1H = 0xD1; // Load Timer1 high byte
  TMR1ON = 1;   // Turn ON Timer1

  while (1)
    ; // Infinite loop (do nothing, ISR handles buzzer)

  return;
}










//! seven
#include <xc.h>
#include <pic18f4550.h>

// Configuration Bits (adjust as needed)
#pragma config FOSC = HS    // High-Speed Oscillator
#pragma config WDT = OFF    // Watchdog Timer Disabled
#pragma config LVP = OFF    // Low-Voltage Programming Disabled
#pragma config PBADEN = OFF // PORTB<4:0> configured as digital on reset

#define _XTAL_FREQ 8000000 // 6->0 Define clock frequency (for __delay_ms)

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










//! eight
#include <pic18f4550.h>
#include <xc.h>

unsigned char count = 0;
bit TIMER2_SPEED_UP;

void timer2Init(void)
{
  T2CON = 0b00000110; // Timer2 ON, Prescaler 1:16
  PR2 = 255;          // Set period register
}

void delay(unsigned int time)
{
  unsigned int i, j;
  for (i = 0; i < time; i++)
  {
    for (j = 0; j < 1000; j++)
      ;
  }
}

void main(void)
{
  unsigned int i;

  TRISCbits.TRISC2 = 0; // Set RC2 as output (PWM output)
  TRISAbits.TRISA0 = 0; // Set RA0 as output (Motor direction control)
  LATA = 0b00001100;    // Set some initial value on Port A

  CCP1CON = 0b00001100; // Configure CCP1 in PWM mode

  CCPR1L = 0x0F; // Set initial PWM duty cycle
  timer2Init();  // Initialize Timer2
  TMR2ON = 1;    // Turn ON Timer2

  while (1)
  {
    for (i = 1; i < 150; i++)
    {
      CCPR1L = i; // Increase speed
      delay(100);
    }

    for (i = 150; i > 1; i--)
    {
      CCPR1L = i; // Decrease speed
      delay(100);
    }
  }
}












//! nine

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
