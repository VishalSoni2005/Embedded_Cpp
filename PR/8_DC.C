#include <xc.h>

void timer2Init(void)
{
  T2CON = 0x02; // Timer2 ON with prescaler
  PR2 = 0x90;   // PWM period setting
}

void delay(unsigned int time)
{
  for (unsigned int i = 0; i < time; i++)
  {
    for (unsigned int j = 0; j < 1000; j++)
    {
      __nop(); // No Operation (optional, to hint compiler)
    }
  }
}

void main(void)
{
  TRISCbits.TRISC2 = 0; // Set RC2 as output (PWM output)
  CCP1CON = 0x0C;       // Configure CCP1 for PWM mode
  CCPR1L = 15;          // Initial low duty cycle

  timer2Init();
  T2CONbits.TMR2ON = 1; // Turn on Timer2

  while (1)
  {
    for (unsigned int i = 15; i < 150; i++)
    {
      CCPR1L = i;
      delay(100);
    }
    for (unsigned int i = 150; i > 15; i--)
    {
      CCPR1L = i;
      delay(100);
      
    }
  }
}