  #include "18F452cfg.h"
  #pragma config[2] = _HS_OSC_2    //HS oscillator
  #pragma config[3] = _PWRT_ON_3 & _BOR_ON_3 & _BORV_42_3 //Reset
  #pragma config[4] = _WDT_OFF_4   //Watchdog timer disabled
  #pragma config[6] = _CCP2MX_ON_6 //CCP2 to RC1 (rather than to RB3)
  #pragma config[7] = _LVP_OFF_7   //RB5 enabled for I/O
/**************
Serial Transmit/Receive in C

A switch connected on RB4 of this processor
  controls a LED on RB0 of the USART-connected processor

**************/

char  WS,WT, // Temporary WorkRegister
         PS; // Present State of FSM

void XmitCh( char Ch);
char RecvCh( void );

void fsm(void){
  char    WF ; // TempWorkFile
  WS = PORTB;
  if(PS.4==0) if(WS.4==1) XmitCh('B');
  if(PS.4==1) if(WS.4==0) XmitCh('A');
  WF = RecvCh();
  if(WF=='A') WS.0 = 0;
  if(WF=='B') WS.0 = 1;
  PORTB=WS;
  PS=WS;
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
  PS=PORTB;
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

void XmitCh( char Ch){
do{}while(TXIF==0); //wait until TXREG is empty
TXREG = Ch;
}
char RecvCh( void ){
char WX=0;
if(RCIF==1) { WX=RCREG; RCIF=0;}
return WX;
}

void main(void){
 init();
 do{
   fsm();
   }while(1);
 }
