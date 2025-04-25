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
