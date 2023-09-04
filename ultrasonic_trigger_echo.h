#ifndef _ULTRASONIC_TRIGGER_ECHO_H___
#define _ULTRASONIC_TRIGGER_ECHO_H___


#define SCALE_FACTOR      2.5
#define    BIT7    0x80
#define    BIT6    0x40
#define    BIT5    0x20
#define    BIT4    0x10
#define    BIT3    0x08
#define    BIT2    0x04
#define    BIT1    0x02
#define    BIT0    0x01
/* Defines common macro*/
#define CON_CAT(a,b)                a ## b
#define DDR_(name)        CON_CAT(DDR,name)
#define PORT_(name)       CON_CAT(PORT,name)
#define PIN_(name)        CON_CAT(PIN,name)
#define BIT_(name)        CON_CAT(BIT,name)

/*Need to change according to connections*/
#define ULTRASONIC_PORT_IND        D            /*need to configure here */
#define LEFT_ULTRASONIC_TRIGGER         3               /*need to configure trigger pin(0-7) */
#define LEFT_ULTRASONIC_ECHO            2               /*need to configure echo pin(0-7) */
#define RIGHT_ULTRASONIC_TRIGGER         5               /*need to configure trigger pin(0-7) */
#define RIGHT_ULTRASONIC_ECHO            4 
#define FRONT_ULTRASONIC_TRIGGER         7               /*need to configure trigger pin(0-7) */
#define FRONT_ULTRASONIC_ECHO            6
/*  ULTRASONIC 1  */

#define Ultrasonic_Triger_Port_Direction            DDR_(ULTRASONIC_PORT_IND)
#define Ultrasonic_Triger_Port                      PORT_(ULTRASONIC_PORT_IND)
#define Left_Ultrasonic_Trigger_pin                  BIT_(LEFT_ULTRASONIC_TRIGGER)
#define Right_Ultrasonic_Trigger_pin                  BIT_(RIGHT_ULTRASONIC_TRIGGER)
#define Front_Ultrasonic_Trigger_pin                  BIT_(FRONT_ULTRASONIC_TRIGGER)

#define Ultrasonic_Echo_Port_Direction              DDR_(ULTRASONIC_PORT_IND)
#define Ultrasonic_Echo_Port                        PORT_(ULTRASONIC_PORT_IND)
#define Ultrasonic_Echo_Input                       PIN_(ULTRASONIC_PORT_IND)
#define Left_Ultrasonic_Echo_pin                    BIT_(LEFT_ULTRASONIC_ECHO)
#define Right_Ultrasonic_Echo_pin                    BIT_(RIGHT_ULTRASONIC_ECHO)
#define Front_Ultrasonic_Echo_pin                    BIT_(FRONT_ULTRASONIC_ECHO)

void init_Ultrasonic_sensor(void);
void trigger_Ultrasonic_sensor(void);
unsigned int read_Ultrasonic_sensor(unsigned int ultrasonicEchoPin);
unsigned int get_distance_Ultrasonic_sensor(unsigned int ultrasonicEchoPin);

#endif /* _ULTRASONIC_TRIGGER_ECHO_H___ */