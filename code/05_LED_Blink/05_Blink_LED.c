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
