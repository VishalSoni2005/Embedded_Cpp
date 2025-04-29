#include <xc.h>

void main(void) {
  int sum = 0;
  int arr[5] = {0x01, 0x02, 0x03, 0x04, 0x05}; // Array of integers

  for(int i = 0; i < 5; i++) {
    sum += arr[i]; // Sum the elements of the array
  }

  trisd = 0;
  latd = 0;
  portd = sum; // Store the sum in PORTD

  while (1)
  {
    /* code */
  }
  return;
}