/*
 * File:   T001GPIOmain.c
 * Author: Daniel Marquina
 *
 * This is meant as a tutorial/reminder of basic GPIO usage.
 * 
 * Created on 2/10/2017
 */


#include "T001GPIOmain.h"

// Variables
bit flag = 0; // "bit" variables must be global or static

void main() {
    // Ports configuration    
    TRISB = 0xFF;
    TRISD = 0x00;
    // Ports initial values
    PORTB = 0x00;
    PORTD = 0x00;
    
    // Initialization signal
    __delay_ms(500);
    PORTD = 0xFF;
    __delay_ms(500);
    PORTD = 0x00;
    
    // Infinite loop
    while (1){
        // Light a LED while pressing a button with pull-up
        if(BUT_1 != 1){
            LED_1 = 1;
            __delay_ms(150);
        }else{
            LED_1 = 0;
        }
        // Toggle a LED after pressing a button with pull-up
        if(BUT_2 != 1){
            if(LED_2 == 1){
                LED_2 = 0;
            }else{
                LED_2 = 1;
            }
            __delay_ms(300);
        }
        // Turn off everything, a flag is used
        if(BUT_3 != 1){
            flag = 1;
        }
        if(flag){
            PORTD = 0x00;
            flag = 0;
        }
    }
}
