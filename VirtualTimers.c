#include <avr/io.h>
#include "Timer0.h"
/* incluir lo necesario para hacer uso de UART0 */

// Example callback function
void timer1s_callback(void) 
{
    char str[8];
    static uint8_t counter = 0;
    counter++;
    UART_gotoxy(0,5,2);
    itoa(counter,str,10);
    UART_puts(0,str);
}

// Example callback function
void timer5s_callback(void) 
{
    char str[8];
    static uint8_t counter = 0;
    counter+=5;
    UART_gotoxy(0,5,3);
    itoa(counter,str,10);
    UART_puts(0,str);
}

int main() {
    // Timer0 Init
    // Uart0 Init

    // Register a one-shot timer for 5000ms
    if (register_timer(5000, TIMER_ONE_SHOT, timer5s_callback) == -1) {
        UART_puts(0,"Failed to register continuous timer\n");
    }

    // Register a continuous timer for 1000ms
    if (register_timer(1000, TIMER_CONTINUOUS, timer1s_callback) == -1) {
        UART_puts(0,"Failed to register one-shot timer\n");
    }

    UART_gotoxy(0,1,1);
    UART_puts(0,"Virtual Timers are running");
    while (1) {
        // wait until timers expire
    }

    return 0;
}