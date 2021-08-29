  #include "18F452cfg.h"
  #pragma config[2] = _HS_OSC_2    //HS oscillator
  #pragma config[3] = _PWRT_ON_3 & _BOR_ON_3 & _BORV_42_3 //Reset
  #pragma config[4] = _WDT_OFF_4   //Watchdog timer disabled
  #pragma config[6] = _CCP2MX_ON_6 //CCP2 to RC1 (rather than to RB3)
  #pragma config[7] = _LVP_OFF_7   //RB5 enabled for I/O
/**************
Serial Transmit/Receive in C through interrupt services

A switch connected on RB4 of this processor
  controls a LED on RB0 of the serial-connected processor

RB4-RB7 pins invoke a change-on-level interrupt (low-priority)
Serial Receive invokes a high priority interrupt.

**************/

char  WP, WRc; // Temporary WorkRegister

void XmitCh( char Ch);
char RecvCh( void );

void HPISR(void); // HP Interrupt Service Routine Prototype
#pragma origin 0x08   // LP Interrupt Service Vector
void HPISVector(void){ HPISR(); } // linked to LPISR procedure

#pragma origin 0x18   // LP Interrupt Service Vector
void LPISR(void){ // low priority interrupt service routine
  /*  Low Priority Interrupt is invoked by
      Change-on-RB4-RB7 pins.                         */
  WP = PORTB;
  if(WP.4==0) TXREG='B';
  if(WP.4==1) TXREG='A';
  RBIF=0;
  retint(); } // return from interrupt

void HPISR(void){ // high priority interrupt service routine
  /* High Priority Interrupt is invoked by the
       Received Character from USART.                */
  WP  = PORTB;
  WRc = RCREG;
  if(WRc=='A') WP.0 = 1;
  if(WRc=='B') WP.0 = 0;
  PORTB=WP;
  RBIF=0;
  retint(); } // return from interrupt

void initIS(void){ // initialize interrupt servicing
   RCIP=1 ; // high priority interrupt on receive
   RCIE=1 ; // interrupt on received serial-char

   RBIP=0 ; // low priority interrupt on change
   RBIE=1 ; // interrupt on change enabled

   GIE =1 ; // unmasked interrupts enabled
   PEIE=1 ; // all interrupts low priority
   IPEN=1 ;
   }

void init(void){
// initialize RA0 for ADC
  ADCON1= 0b10001110;
// initialize io ports
  TRISA = 0b11100001;
  PORTA = 0;
  TRISB = 0b11011010;
  PORTB = 0;
  TRISC = 0b10010000; // RC7 is RC, RC6 is TX
  TRISD = 0b11111111; // RD0-1 switch, RD2-7 LCD
  PORTD = 0xFF;
  TRISE = 0b00000000;
  PORTE = 0xFF;
// Processor Clock 2.5MHz (Xtal 10MHz)
// BRGH = 0;  SPBRG = Fosc/(Baud*64) - 1  = 3.07
// BRGH = 1;  SPBRG = Fosc/(Baud*16) - 1  = 15.3
  SPBRG = 15.3;

  TXSTA = 0;
  BRGH = 1;
  TXEN = 1;

  RCSTA = 0;
  CREN = 1;
  SPEN = 1;

  TXIF = 1;
  RCIF = 0;
  }

void main(void){
 init();
 initIS();
 do{
   }while(1);
 }
