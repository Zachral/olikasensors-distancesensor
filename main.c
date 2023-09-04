#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "uart.h"
#include "ultrasonic_trigger_echo.h"

#define RIGHT  1
#define LEFT   2
#define FRONT  3
//https://wokwi.com/projects/290056311044833800

char data_buffer[4],buffer[50];

int leftDistance = 0, rightDistance = 0, frontDistance = 0,c_m=0,m_m=0;

int convert_cm(int value)
{
 c_m = value/10;
 //m_m = value%10;


  integer_to_char(c_m,data_buffer,3);
  printf(data_buffer);
  /*send2uart(".");
  integer_to_char(m_m,data_buffer,2);
  usart_putchar(data_buffer[1]);*/
  printf("cm\r\n");
  if(c_m< 010)
  {
    sprintf(buffer,"OBSTACLE DETECTED\r\n");
	printf(buffer);
   }
   return 0;
}


int main(void)
{

_delay_ms(1000);
init_serial();


// DDRB&=~(BIT3);
// PORTB |= BIT3;

init_Ultrasonic_sensor();



while(1)
{
   rightDistance = get_distance_Ultrasonic_sensor(Right_Ultrasonic_Echo_pin); 
   leftDistance = get_distance_Ultrasonic_sensor(Left_Ultrasonic_Echo_pin);
   frontDistance = get_distance_Ultrasonic_sensor(Front_Ultrasonic_Echo_pin); 
   convert_cm(leftDistance);
   convert_cm(rightDistance);
   convert_cm(frontDistance); 
	_delay_ms(100);
}

}