// 3)Internal to External Memory Transfer
// INPUT :
// OUTPUT:FILE REGISTER
#include <xc.h>

void main(void)
{

  static int arr1[5] = {0x01, 0x02, 0x03, 0x04, 0x05}; // 0x01 to 0x05
  static int arr2[5] = {0x06, 0x07, 0x08, 0x09, 0x10}; // 0x06 to 0x10
  int temp;

  for (int i = 0; i < 5; i++)
  {
    temp = arr1[i];
    arr1[i] = arr2[i];
    arr2[i] = temp;
  }
  while (1)
    ;
}

// second part
// interanl to internal memory transfer

#include <xc.h>

void main(main)
{
  static int arr1[5] = {0x01, 0x02, 0x03, 0x04, 0x05}; // 0x01 to 0x05
  static int arr2[5] = {0x06, 0x07, 0x08, 0x09, 0x10}; // 0x06 to 0x10
  int temp;

  for (int i = 0; i < 5; i++)
  {

    arr1[i] = arr2[i];
  }
  while (1)
    ;
}