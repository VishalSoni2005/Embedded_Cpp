//! ascending
#include <xc.h>
void delay (void) {
  for(int i = 0; i < 1000; i++)
    for(int j = 0; j < 1000; j++);
}

void main(void) {
  int temp;
  int arr[7] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07};

  for(int i=0; i<7; i++) {
    for(int j=0; j<7-i; j++) {
      if(arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }

  TRISD = 0;
  for(int i=0; i<7; i++) {
    PORTD = arr[i];
    delay();
  }
}

//! descending
#include <xc.h>

void delay (void) {
  for(int i = 0; i < 1000; i++)
    for(int j = 0; j < 1000; j++);
}

void main(void) {
  int temp;
  int brr[7] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07};

  for(int i=0; i<7; i++) {
    for(int j=0; j<7-i; j++) {
      if(brr[j] < brr[j+1]) {
        temp = brr[j];
        brr[j] = brr[j+1];
        brr[j+1] = temp;
      }
    }
  }
  TRISD = 0;
  for(int i=0; i<7; i++) {
    PORTD = brr[i];
    delay();
  }
}