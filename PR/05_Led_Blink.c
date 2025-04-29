#include <xc.h>
void delay(unsigned int time)
{

  for (int i = 0; i < time; i++)
  {
    for (int j = 0; j < 5000; j++)
    {
    }
  }
}
void main(void)
{
  TRISD = 0x00;
  LATD = 0xff;
  while (1)
  {
    LATD = ~LATD;
    delay(200);
  }
  return;
}
