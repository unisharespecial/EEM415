// Header file
#ifndef ICD2_DEBUG
 #pragma chip PIC18F1230, core 16, code 2048, ram 0 : 0xFF

#else
 #pragma chip PIC18F1230, core 16, code 0x6E0, ram 0 : 0xFF
 // NOTE: last 288 words are reserved for ICD2 debugging

 char reservedICD2[5] @ 0xFB;  // reserved RAM for ICD2

 #pragma stackLevels 29   // reserve two levels for debugging
#endif

// Extended Instruction Set

/* Predefined:
TOSU,TOSH,TOSL,
STKPTR,
PCLATU,PCLATH,PCL,
TBLPTRU,TBLPTRH,TBLPTRL,TBLPTR,TABLAT,
PRODH,PRODL,
INTCON,INTCON2,INTCON3,
INDF0,POSTINC0,POSTDEC0,PREINC0,PLUSW0,FSR0H,FSR0L,FSR0,
WREG,
INDF1,POSTINC1,POSTDEC1,PREINC1,PLUSW1,FSR1H,FSR1L,FSR1,
BSR,BSRL,
INDF2,POSTINC2,POSTDEC2,PREINC2,PLUSW2,FSR2H,FSR2L,FSR2,
STATUS,
Carry,DC,Zero_,Overflow,Negative,
*/

char TMR0H    @ 0xFD7;
char TMR0L    @ 0xFD6;
char T0CON    @ 0xFD5;

char OSCCON   @ 0xFD3;
char LVDCON   @ 0xFD2;
char WDTCON   @ 0xFD1;
char RCON     @ 0xFD0;
char TMR1H    @ 0xFCF;
char TMR1L    @ 0xFCE;
char T1CON    @ 0xFCD;

char ADRESH   @ 0xFC4;
char ADRESL   @ 0xFC3;
char ADCON0   @ 0xFC2;
char ADCON1   @ 0xFC1;
char ADCON2   @ 0xFC0;

char BAUDCON  @ 0xFB8;

char CVRCON   @ 0xFB5;
char CMCON    @ 0xFB4;

char SPBRGH   @ 0xFB0;
char SPBRG    @ 0xFAF;
char RCREG    @ 0xFAE;
char TXREG    @ 0xFAD;
char TXSTA    @ 0xFAC;
char RCSTA    @ 0xFAB;

char EEADR    @ 0xFA9;
char EEDATA   @ 0xFA8;
char EECON2   @ 0xFA7;
char EECON1   @ 0xFA6;
char IPR3     @ 0xFA5;
char PIR3     @ 0xFA4;
char PIE3     @ 0xFA3;
char IPR2     @ 0xFA2;
char PIR2     @ 0xFA1;
char PIE2     @ 0xFA0;
char IPR1     @ 0xF9F;
char PIR1     @ 0xF9E;
char PIE1     @ 0xF9D;

char OSCTUNE  @ 0xF9B;
char PTCON0   @ 0xF9A;
char PTCON1   @ 0xF99;
char PTMRL    @ 0xF98;
char PTMRH    @ 0xF97;
char PTPERL   @ 0xF96;
char PTPERH   @ 0xF95;

char TRISB    @ 0xF93;
char TRISA    @ 0xF92;
char PDC0L    @ 0xF91;
char PDC0H    @ 0xF90;
char PDC1L    @ 0xF8F;
char PDC1H    @ 0xF8E;
char PDC2L    @ 0xF8D;
char PDC2H    @ 0xF8C;
char FLTCONFIG @ 0xF8B;
char LATB     @ 0xF8A;
char LATA     @ 0xF89;
char SEVTCMPL @ 0xF88;
char SEVTCMPH @ 0xF87;
char PWMCON0  @ 0xF86;
char PWMCON1  @ 0xF85;
char DTCON    @ 0xF84;
char OVDCOND  @ 0xF83;
char OVDCONS  @ 0xF82;
char PORTB    @ 0xF81;
char PORTA    @ 0xF80;

bit RBIF    @ INTCON.0;
bit INT0IF  @ INTCON.1;
bit TMR0IF  @ INTCON.2;
bit RBIE    @ INTCON.3;
bit INT0IE  @ INTCON.4;
bit TMR0IE  @ INTCON.5;
bit PEIE    @ INTCON.6;
bit GIEL    @ INTCON.6;
bit GIE     @ INTCON.7;
bit GIEH    @ INTCON.7;

bit RBIP    @ INTCON2.0;
bit INT3IP  @ INTCON2.1;
bit TMR0IP  @ INTCON2.2;
bit INTEDG3 @ INTCON2.3;
bit INTEDG2 @ INTCON2.4;
bit INTEDG1 @ INTCON2.5;
bit INTEDG0 @ INTCON2.6;
bit RBPU    @ INTCON2.7;

bit INT1IF  @ INTCON3.0;
bit INT2IF  @ INTCON3.1;
bit INT3IF  @ INTCON3.2;
bit INT1IE  @ INTCON3.3;
bit INT2IE  @ INTCON3.4;
bit INT3IE  @ INTCON3.5;
bit INT1IP  @ INTCON3.6;
bit INT2IP  @ INTCON3.7;

bit PSA     @ T0CON.3;
bit T0SE    @ T0CON.4;
bit T0CS    @ T0CON.5;
bit T016BIT @ T0CON.6;
bit TMR0ON  @ T0CON.7;

bit SCS0    @ OSCCON.0;
bit SCS1    @ OSCCON.1;
bit IOFS    @ OSCCON.2;
bit OSTS    @ OSCCON.3;
bit IDLEN   @ OSCCON.7;

bit LVDEN   @ LVDCON.4;
bit IRVST   @ LVDCON.5;

bit SWDTEN  @ WDTCON.0;

bit BOR_    @ RCON.0;
bit POR_    @ RCON.1;
bit PD      @ RCON.2;
bit TO      @ RCON.3;
bit RI_     @ RCON.4;
bit SBOREN  @ RCON.6;
bit IPEN    @ RCON.7;

bit TMR1ON  @ T1CON.0;
bit TMR1CS  @ T1CON.1;
bit T1SYNC_ @ T1CON.2;
bit T1OSCEN @ T1CON.3;
bit T1CKPS0 @ T1CON.4;
bit T1CKPS1 @ T1CON.5;
bit T1RUN   @ T1CON.6;
bit RD16    @ T1CON.7;

bit ADON    @ ADCON0.0;
bit GO      @ ADCON0.1;
bit CHS0    @ ADCON0.2;
bit CHS1    @ ADCON0.3;
bit SEVTEN  @ ADCON0.7;

bit VCFG0   @ ADCON1.4;

bit ADCS0   @ ADCON2.0;
bit ADCS1   @ ADCON2.1;
bit ADCS2   @ ADCON2.2;
bit ADFM    @ ADCON2.7;

bit ABDEN   @ BAUDCON.0;
bit WUE     @ BAUDCON.1;
bit BRG16   @ BAUDCON.3;
bit SCKP    @ BAUDCON.4;
bit RCIDL   @ BAUDCON.6;
bit ABDOVF  @ BAUDCON.7;

bit CVRSS   @ CVRCON.4;
bit CVRR    @ CVRCON.5;
bit CVREN   @ CVRCON.7;

bit CMEN0   @ CMCON.0;
bit CMEN1   @ CMCON.1;
bit CMEN2   @ CMCON.2;
bit C0OUT   @ CMCON.5;
bit C1OUT   @ CMCON.6;
bit C2OUT   @ CMCON.7;

bit TX9D    @ TXSTA.0;
bit TRMT    @ TXSTA.1;
bit BRGH    @ TXSTA.2;
bit SENDB   @ TXSTA.3;
bit SYNC    @ TXSTA.4;
bit TXEN    @ TXSTA.5;
bit TX9     @ TXSTA.6;
bit CSRC    @ TXSTA.7;

bit RX9D    @ RCSTA.0;
bit OERR    @ RCSTA.1;
bit FERR    @ RCSTA.2;
bit ADDEN   @ RCSTA.3;
bit CREN    @ RCSTA.4;
bit SREN    @ RCSTA.5;
bit RX9     @ RCSTA.6;
bit SPEN    @ RCSTA.7;

bit RD      @ EECON1.0;
bit WR      @ EECON1.1;
bit WREN    @ EECON1.2;
bit WRERR   @ EECON1.3;
bit FREE    @ EECON1.4;
bit CFGS    @ EECON1.6;
bit EEPGD   @ EECON1.7;

bit PTIP    @ IPR3.4;

bit PTIF    @ PIR3.4;

bit PTIE    @ PIE3.4;

bit LVDIP   @ IPR2.2;
bit EEIP    @ IPR2.4;
bit OSCFIP  @ IPR2.7;

bit LVDIF   @ PIR2.2;
bit EEIF    @ PIR2.4;
bit OSCFIF  @ PIR2.7;

bit LVDIE   @ PIE2.2;
bit EEIE    @ PIE2.4;
bit OSCFIE  @ PIE2.7;

bit TMR1IP  @ IPR1.0;
bit CMP0IP  @ IPR1.1;
bit CMP1IP  @ IPR1.2;
bit CMP2IP  @ IPR1.3;
bit TXIP    @ IPR1.4;
bit RCIP    @ IPR1.5;
bit ADIP    @ IPR1.6;

bit TMR1IF  @ PIR1.0;
bit CMP0IF  @ PIR1.1;
bit CMP1IF  @ PIR1.2;
bit CMP2IF  @ PIR1.3;
bit TXIF    @ PIR1.4;
bit RCIF    @ PIR1.5;
bit ADIF    @ PIR1.6;

bit TMR1IE  @ PIE1.0;
bit CMP0IE  @ PIE1.1;
bit CMP1IE  @ PIE1.2;
bit CMP2IE  @ PIE1.3;
bit TXIE    @ PIE1.4;
bit RCIE    @ PIE1.5;
bit ADIE    @ PIE1.6;

bit PLLEN   @ OSCTUNE.6;
bit INTSRC  @ OSCTUNE.7;

bit PTMOD0  @ PTCON0.0;
bit PTMOD1  @ PTCON0.1;
bit PTCKPS0 @ PTCON0.2;
bit PTCKPS1 @ PTCON0.3;

bit PTDIR   @ PTCON1.6;
bit PTEN    @ PTCON1.7;

bit FLTAEN  @ FLTCONFIG.0;
bit FLTAMOD @ FLTCONFIG.1;
bit FLTAS   @ FLTCONFIG.2;
bit BRFEN   @ FLTCONFIG.7;

bit OSYNC   @ PWMCON1.0;
bit UDIS    @ PWMCON1.1;
bit SEVTDIR @ PWMCON1.3;

bit DTPS0   @ DTCON.6;
bit DTPS1   @ DTCON.7;
