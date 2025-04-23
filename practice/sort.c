*=> TRISx sfr: 
  simply assign wheather the pin is input or output

  0-> output
  1-> input

  for example:

  TRISD = 0x00; // Set PORTD as output
  TRISD = 0xFF; // Set PORTD as input


#include <xc.h>
#include <pic18f4550.h>

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void delayLoop(void) {
  for(int i=0; i<1000, i++) {
    for(int j=0; j<100; j++);
      // Empty loop for delay
    
  }
}
void main(void) {
  int a[] = {0x45, 0x03, 0x06, 0x13, 0x32, 0x02, 0x05, 0x23};
  int size = sizeof(a) / sizeof(a[0]);

  // Bubble sort (ascending)
  for(int i=0; i<size-1; i++) {
    for(int j=0; j<size-1-i; j++) {
      if(a[j] > a[j+1]) {
        swap(&a[j], &a[j+1]);
      }
    }
  }
  // array is sorted uptill now

}