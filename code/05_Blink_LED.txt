#include <xc.h>
#include <util/delay.h>  // Built-in delay function

void main(void) {
    TRISD = 0x00;
    LATD = 0xFF;

    while (1) {
        LATD = ~LATD;
        __delay_ms(200);  // More accurate 200ms delay
    }
}
