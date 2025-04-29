#include <xc.h>
void main(void) {
  int i, j, k;
  i = 0x01;
  j = 0x02;
  k = i + j;

  trisd = 0x00; // Set PORTD as output
  latd = 0x00; // Initialize PORTD to 0
  portd = k;    // Store the sum in PORTD
  porta = i; // Set PORTA as output
  portb = j; // Set PORTB as output
}