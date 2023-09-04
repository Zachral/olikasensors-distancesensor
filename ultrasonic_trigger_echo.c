#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "ultrasonic_trigger_echo.h"


unsigned int echo_duration;

void init_Ultrasonic_sensor(void)
{
  Ultrasonic_Triger_Port_Direction |= (Left_Ultrasonic_Trigger_pin);    // Ultrasonic Trigger pin
  Ultrasonic_Triger_Port &= ~(Left_Ultrasonic_Trigger_pin);   // Ultrasonic pin set to low

  Ultrasonic_Triger_Port_Direction |= (Front_Ultrasonic_Trigger_pin);    // Ultrasonic Trigger pin
  Ultrasonic_Triger_Port &= ~(Front_Ultrasonic_Trigger_pin);   // Ultrasonic pin set to low

  Ultrasonic_Triger_Port_Direction |= (Right_Ultrasonic_Trigger_pin);    // Ultrasonic Trigger pin
  Ultrasonic_Triger_Port &= ~(Right_Ultrasonic_Trigger_pin);   // Ultrasonic pin set to low
  
  Ultrasonic_Echo_Port_Direction &= ~(Left_Ultrasonic_Echo_pin);   // Ultrasonic Echo pin set to input
  Ultrasonic_Echo_Port |= Left_Ultrasonic_Echo_pin; 
  
  Ultrasonic_Echo_Port_Direction &= ~(Front_Ultrasonic_Echo_pin);   // Ultrasonic Echo pin set to input
  Ultrasonic_Echo_Port |= Front_Ultrasonic_Echo_pin;      // Enable pullup

  Ultrasonic_Echo_Port_Direction &= ~(Right_Ultrasonic_Echo_pin);   // Ultrasonic Echo pin set to input
  Ultrasonic_Echo_Port |= Right_Ultrasonic_Echo_pin; 
}

void trigger_Ultrasonic_sensor(void)
{
    Ultrasonic_Triger_Port |= (Left_Ultrasonic_Trigger_pin);
    Ultrasonic_Triger_Port |= (Front_Ultrasonic_Trigger_pin);
    Ultrasonic_Triger_Port |= (Right_Ultrasonic_Trigger_pin);
    _delay_us(10);
    Ultrasonic_Triger_Port &= ~(Left_Ultrasonic_Trigger_pin);
    Ultrasonic_Triger_Port &= ~(Front_Ultrasonic_Trigger_pin);
    Ultrasonic_Triger_Port &= ~(Right_Ultrasonic_Trigger_pin);
    printf("In trigger");
}

unsigned int read_Ultrasonic_sensor(unsigned int Ultrasonic_echo_pin)
{
    printf("in read");
    echo_duration = 0;   
    while((Ultrasonic_Echo_Input&Ultrasonic_echo_pin) != Ultrasonic_echo_pin);
    while(((Ultrasonic_Echo_Input&Ultrasonic_echo_pin) == Ultrasonic_echo_pin) && (echo_duration<20000))
    {
      printf("In echo");
      _delay_us(1);
      echo_duration++;
    }
    return echo_duration;
}


unsigned int get_distance_Ultrasonic_sensor(unsigned int Ultrasonic_echo_pin)
{
  printf("IN getDistance");
  trigger_Ultrasonic_sensor();
  return (read_Ultrasonic_sensor(Ultrasonic_echo_pin)/SCALE_FACTOR) + 20;
  ;
}