#include <xc.h>

#define Buzzer LATAbits.LATA5
int count = 0;

void interrupt timer() {

  iF(TMR1IF = 1) {
    TMR1L = 0X20;
    TMR1H = 0XD1;
    count++;
    if (count == 10) {
      count = 0;
      Buzzer = ~Buzzer; // Toggle the buzzer state
    }
    TMR1IF = 0; // Clear the interrupt flag
  }
}

void main(void) {

  TRISB = 0; 
  LATAbits.LATA5 = 0;

  GIE = 1; 
  PEIE = 1;

  TMR1IE = 1; // Enable Timer1 interrupt
  TMR1IF = 0; // Clear Timer1 interrupt flag

  T1CON = 0X20;
  TMR1L = 0X20; // Load the timer value
  TMR1H = 0XD1; // Load the timer value

  TMR1ON = 1; // Start Timer1

  while (1) {
    // Main loop does nothing, all work is done in the interrupt
  }
  return;


}