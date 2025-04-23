*-> NOTES: 

a> we just use hex array so that hardware can easily read it we can even use decimal array.

b> we can use any values in array as between 
  1 byte = 8 bits → values from 0x00 to 0xFF (0 to 255 in decimal)

c> we can use int and unsigned char any this 
    just difference is that int is 2 bytes and unsigned char is 1 byte.

    Data Type     | Size (on PIC18)   | Range
    int           | 2 bytes (16 bits) | -32,768 to 32,767
    unsigned char | 1 byte (8 bits)   | 0 to 255

d> we can provide any value to array <= 0xff

//! DESCENDING

#include <xc.h>
#include <pic18f4550.h>

void delay(void) {
    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 100; j++);
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void main(void) {
    // int a[] = {0x45, 0x03, 0x06, 0x13, 0x32, 0x02, 0x05, 0x23};
    int a[] = {0x43, 0x12, 0x03, 0x43, 0x23, 0x02, 0x05, 0x23};
    int i, j;
    int size = sizeof(a) / sizeof(a[0]);

    // Bubble sort (descending)
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            if (a[j] < a[j + 1]) {
                swap(&a[j], &a[j + 1]);
            }
        }
    }

    TRISD = 0x00; // Set PORTD as output

    for (i = 0; i < size; i++) {
        PORTD = a[i];
        delay();
    }

    while (1); // Infinite loop
}



//! ASSENDING

#include <xc.h>
#include <pic18f4550.h>

void delay(void) {
    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 100; j++);
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void main(void) {
    int a[] = {0x45, 0x03, 0x06, 0x13, 0x32, 0x02, 0x05, 0x23};
    int i, j;
    int size = sizeof(a) / sizeof(a[0]);

    // Bubble sort (ascending)
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
            }
        }
    }

    TRISD = 0x00; // Set PORTD as output

    for (i = 0; i < size; i++) {
        PORTD = a[i];
        delay();
    }

    while (1); // Infinite loop
}
