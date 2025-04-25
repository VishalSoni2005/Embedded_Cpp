#include <xc.h>
#include <pic18f4550.h>

#define Buzzer LATAbits.LATA5

unsigned int count = 0;

// Timer1 Interrupt Service Routine
void interrupt Timer1_ISR()
{
  if (TMR1IF == 1)
  {               // Check if Timer1 interrupt occurred
    TMR1L = 0x20; // Reload Timer1 low byte
    TMR1H = 0xD1; // Reload Timer1 high byte
    count++;      // Increment count

    if (count >= 1000)
    {                   // After 1000 overflows
      Buzzer = ~Buzzer; // Toggle buzzer state
      count = 0;        // Reset count
    }

    TMR1IF = 0; // Clear Timer1 interrupt flag
  }
}

void main(void)
{
  TRISB = 0;            // Set PORTB as output (optional for buzzer)
  TRISAbits.TRISA5 = 0; // Set RA5 (Buzzer pin) as output

  GIE = 1;    // Global Interrupt Enable
  PEIE = 1;   // Peripheral Interrupt Enable
  TMR1IE = 1; // Enable Timer1 interrupt
  TMR1IF = 0; // Clear Timer1 interrupt flag

  T1CON = 0x20; // Timer1 settings (prescaler 1:4)
  TMR1L = 0x20; // Load Timer1 low byte
  TMR1H = 0xD1; // Load Timer1 high byte
  TMR1ON = 1;   // Turn ON Timer1

  while (1)
    ; // Infinite loop (do nothing, ISR handles buzzer)

  return;
}

// #include <xc.h>
// #include <pic18f4550.h>

// #define Buzzer LATAbits.LATA5  // Define Buzzer pin

// unsigned int count = 0;  // Counter for toggling the buzzer

// // Interrupt Service Routine (ISR) for Timer1
// void __interrupt() Timer1_ISR() {
//     if (TMR1IF) {  // Check if Timer1 overflowed
//         TMR1L = 0x20;  // Reload Timer1 Low byte
//         TMR1H = 0xD1;  // Reload Timer1 High byte

//         count++;  // Increment count
//         if (count >= 1000) {  // Toggle buzzer every 1000 overflows
//             Buzzer = ~Buzzer;
//             count = 0;
//         }
//         TMR1IF = 0;  // Clear Timer1 interrupt flag
//     }
// }

// void main(void) {
//     TRISB = 0x00;  // Set PORTB as output (if needed)
//     TRISAbits.TRISA5 = 0;  // Set RA5 (Buzzer) as output
//     Buzzer = 0;  // Initially turn off buzzer

//     // Enable Global and Peripheral Interrupts
//     GIE = 1;
//     PEIE = 1;

//     // Enable Timer1 Interrupt
//     TMR1IE = 1;
//     TMR1IF = 0;

//     // Configure Timer1
//     T1CON = 0x31;  // Prescaler 1:8, Timer1 ON, Internal Clock (Fosc/4)
//     TMR1L = 0x20;  // Load Timer1 Low byte
//     TMR1H = 0xD1;  // Load Timer1 High byte

//     while (1) {
//         // Infinite loop - Buzzer toggling happens in ISR
//     }
// }
