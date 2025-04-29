// internal RAM to external RAM
#include <xc.h>

void main(void ) {
  int temp;
  int arr1[5] = {0x01, 0x02, 0x03, 0x04, 0x05}; // Array of integers
  int arr2[5] = {0x00, 0x00, 0x00, 0x00, 0x00}; // Array of integers

  for(int i = 0; i < 5; i++) {
    arr2[i] = arr1[i]; // Copy elements from arr1 to arr2
  }
  trisd = 0; // Set PORTD as output
  latd = 0; // Initialize PORTD to 0
  for(int i = 0; i < 5; i++) {
    temp = arr2[i]; // Store the value of arr2 in temp
    portd = temp; // Output the value of temp to PORTD
    for(int j = 0; j < 1000; j++) {
      for(int k = 0; k < 100; k++) {
        // Delay loop
      }
    }
  }
  return;
}

// internal RAM to external RAM

#include <xc.h>
void main(void) {
  int temp;
  int arr1[5] = {0x01, 0x02, 0x03, 0x04, 0x05}; // Array of integers
  int arr2[5] = {0x06, 0x07, 0x08, 0x09, 0x0A}; // Array of integers

  for(int i=0; i<5; i++) {
    temp = arr1[i];
    arr1[i] = arr2[i]; // Copy elements from arr2 to arr1
    arr2[i] = temp; // Copy elements from arr1 to arr2
  }
  while(1) {
    // Infinite loop to keep the program running
  }
  return;
}