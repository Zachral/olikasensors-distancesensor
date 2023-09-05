#ifndef _H_RGB_LED__
#define _H_RGB_LED__

#define BLUE_PIN 9
#define GREEN_PIN 10
#define RED_PIN 11

#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))

void init_Rgb_Led(); 
#endif