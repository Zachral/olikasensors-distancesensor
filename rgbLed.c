#include <avr/io.h>
#include "rgbLed.h"


void init_Rgb_Led(){
    BIT_SET(DDRB, BLUE_PIN);
    BIT_SET(DDRB, GREEN_PIN);
    BIT_SET(DDRB, RED_PIN); 
    return; 
}