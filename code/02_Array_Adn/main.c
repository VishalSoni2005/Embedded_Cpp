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
