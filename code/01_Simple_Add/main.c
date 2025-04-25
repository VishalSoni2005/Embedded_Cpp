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
