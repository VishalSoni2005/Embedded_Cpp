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
//! two
#include <xc.h>

void main(void)
{
  int temp, i;
  int arr1[] = {0x21, 0x22, 0x23, 0x24, 0x25};
  int arr2[] = {0x99, 0x99, 0x99, 0x99, 0x99};

  for (i = 0; i <= 4; i++)
  {
    temp = arr1[i];
    arr1[i] = arr2[i];
    arr2[i] = temp;
  }

  return;
}
