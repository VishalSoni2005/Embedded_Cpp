#include <xc.h>

void delay(void) {
    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 1000; j++); // Simple delay loop
}

void main(void) {
  TRISD = 0;
  LATD = 1;
  while(1) {
    LATD =~ LATD; // Toggle the LED state
    delay(); // Call the delay function
  }
} 