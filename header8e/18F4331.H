// Header file
#ifndef ICD2_DEBUG
 #pragma chip PIC18F4331, core 16, code 4096, ram 0 : 0x2FF

#else
 #pragma chip PIC18F4331, core 16, code 0x0EE0, ram 0 : 0x2FF
 // NOTE: last 288 words are reserved for ICD2 debugging

 char reservedICD2[12] @ 0x2F4;  // reserved RAM for ICD2

 #pragma stackLevels 29   // reserve two levels for debugging

#endif


#pragma accessGPR 0x60

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

char TMR0H   @ 0xFD7;
char TMR0L   @ 0xFD6;
char T0CON   @ 0xFD5;

char OSCCON  @ 0xFD3;
char LVDCON  @ 0xFD2;
char WDTCON  @ 0xFD1;
char RCON    @ 0xFD0;
char TMR1H   @ 0xFCF;
char TMR1L   @ 0xFCE;
char T1CON   @ 0xFCD;
char TMR2    @ 0xFCC;
char PR2     @ 0xFCB;
char T2CON   @ 0xFCA;
char SSPBUF  @ 0xFC9;
char SSPADD  @ 0xFC8;
char SSPSTAT @ 0xFC7;
char SSPCON  @ 0xFC6;

char ADRESH  @ 0xFC4;
char ADRESL  @ 0xFC3;
char ADCON0  @ 0xFC2;
char ADCON1  @ 0xFC1;
char ADCON2  @ 0xFC0;
char CCPR1H  @ 0xFBF;
char CCPR1L  @ 0xFBE;
char CCP1CON @ 0xFBD;
char CCPR2H  @ 0xFBC;
char CCPR2L  @ 0xFBB;
char CCP2CON @ 0xFBA;
char ANSEL1  @ 0xFB9;
char ANSEL0  @ 0xFB8;
char T5CON   @ 0xFB7;
char QEICON  @ 0xFB6;

char SPBRGH  @ 0xFB0;
char SPBRG   @ 0xFAF;
char RCREG   @ 0xFAE;
char TXREG   @ 0xFAD;
char TXSTA   @ 0xFAC;
char RCSTA   @ 0xFAB;
char BAUDCTL @ 0xFAA;
char EEADR   @ 0xFA9;
char EEDATA  @ 0xFA8;
char EECON2  @ 0xFA7;
char EECON1  @ 0xFA6;
char IPR3    @ 0xFA5;
char PIR3    @ 0xFA4;
char PIE3    @ 0xFA3;
char IPR2    @ 0xFA2;
char PIR2    @ 0xFA1;
char PIE2    @ 0xFA0;
char IPR1    @ 0xF9F;
char PIR1    @ 0xF9E;
char PIE1    @ 0xF9D;

char OSCTUNE @ 0xF9B;
char ADCON3  @ 0xF9A;
char ADCHS   @ 0xF99;

char TRISE   @ 0xF96;
char TRISD   @ 0xF95;
char TRISC   @ 0xF94;
char TRISB   @ 0xF93;
char TRISA   @ 0xF92;
char PR5H    @ 0xF91;
char PR5L    @ 0xF90;

char LATE    @ 0xF8D;
char LATD    @ 0xF8C;
char LATC    @ 0xF8B;
char LATB    @ 0xF8A;
char LATA    @ 0xF89;
char TMR5H   @ 0xF88;
char TMR5L   @ 0xF87;

char PORTE   @ 0xF84;
char PORTD   @ 0xF83;
char PORTC   @ 0xF82;
char PORTB   @ 0xF81;
char PORTA   @ 0xF80;
char PTCON0  @ 0xF7F;
char PTCON1  @ 0xF7E;
char PTMRL   @ 0xF7D;
char PTMRH   @ 0xF7C;
char PTPERL  @ 0xF7B;
char PTPERH  @ 0xF7A;
char PDC0L   @ 0xF79;
char PDC0H   @ 0xF78;
char PDC1L   @ 0xF77;
char PDC1H   @ 0xF76;
char PDC2L   @ 0xF75;
char PDC2H   @ 0xF74;
char PDC3L   @ 0xF73;
char PDC3H   @ 0xF72;
char SEVTCMPL @ 0xF71;
char SEVTCMPH @ 0xF70;
char PWMCON0 @ 0xF6F;
char PWMCON1 @ 0xF6E;
char DTCON   @ 0xF6D;
char FLTCONFIG @ 0xF6C;
char OVDCOND @ 0xF6B;
char OVDCONS @ 0xF6A;
char CAP1BUFH @ 0xF69;
char CAP1BUFL @ 0xF68;
char CAP2BUFH @ 0xF67;
char CAP2BUFL @ 0xF66;
char CAP3BUFH @ 0xF65;
char CAP3BUFL @ 0xF64;
char CAP1CON @ 0xF63;
char CAP2CON @ 0xF62;
char CAP3CON @ 0xF61;
char DFLTCON @ 0xF60;

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
bit TMR0IP  @ INTCON2.2;
bit INTEDG2 @ INTCON2.4;
bit INTEDG1 @ INTCON2.5;
bit INTEDG0 @ INTCON2.6;
bit RBPU    @ INTCON2.7;

bit INT1IF  @ INTCON3.0;
bit INT2IF  @ INTCON3.1;
bit INT1IE  @ INTCON3.3;
bit INT2IE  @ INTCON3.4;
bit INT1IP  @ INTCON3.6;
bit INT2IP  @ INTCON3.7;

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
bit WDTW    @ WDTCON.7;

bit BOR_    @ RCON.0;
bit POR_    @ RCON.1;
bit PD      @ RCON.2;
bit TO      @ RCON.3;
bit RI_     @ RCON.4;
bit IPEN    @ RCON.7;

bit TMR1ON  @ T1CON.0;
bit TMR1CS  @ T1CON.1;
bit T1SYNC_ @ T1CON.2;
bit T1OSCEN @ T1CON.3;
bit T1CKPS0 @ T1CON.4;
bit T1CKPS1 @ T1CON.5;
bit T1RUN   @ T1CON.6;
bit RD16    @ T1CON.7;

bit T2CKPS0 @ T2CON.0;
bit T2CKPS1 @ T2CON.1;
bit TMR2ON  @ T2CON.2;

bit BF      @ SSPSTAT.0;
bit UA      @ SSPSTAT.1;
bit RW_     @ SSPSTAT.2;
bit S       @ SSPSTAT.3;
bit P       @ SSPSTAT.4;
bit DA_     @ SSPSTAT.5;
bit CKE     @ SSPSTAT.6;
bit SMP     @ SSPSTAT.7;

bit CKP     @ SSPCON.4;
bit SSPEN   @ SSPCON.5;
bit SSPOV   @ SSPCON.6;
bit WCOL    @ SSPCON.7;

bit ADON    @ ADCON0.0;
bit GO      @ ADCON0.1;
bit ACMOD0  @ ADCON0.2;
bit ACMOD1  @ ADCON0.3;
bit ACSCH   @ ADCON0.4;
bit ACONV   @ ADCON0.5;

bit ADPNT0  @ ADCON1.0;
bit ADPNT1  @ ADCON1.1;
bit FFOVFL  @ ADCON1.2;
bit BFEMT   @ ADCON1.3;
bit FIFOEN  @ ADCON1.4;
bit VCFG0   @ ADCON1.6;
bit VCFG1   @ ADCON1.7;

bit ADCS0   @ ADCON2.0;
bit ADCS1   @ ADCON2.1;
bit ADCS2   @ ADCON2.2;
bit ADFM    @ ADCON2.7;

bit DC1B0   @ CCP1CON.4;
bit DC1B1   @ CCP1CON.5;

bit DC2B0   @ CCP2CON.4;
bit DC2B1   @ CCP2CON.5;

bit ANS8    @ ANSEL1.0;

bit TMR5ON  @ T5CON.0;
bit TMR5CS  @ T5CON.1;
bit T5SYNC_ @ T5CON.2;
bit T5PS0   @ T5CON.3;
bit T5PS1   @ T5CON.4;
bit T5MOD   @ T5CON.5;
bit RESEN_  @ T5CON.6;
bit T5SEN   @ T5CON.7;

bit PDEC0   @ QEICON.0;
bit PDEC1   @ QEICON.1;
bit DOWN_   @ QEICON.5;
bit ERROR   @ QEICON.6;
bit VELM_   @ QEICON.7;

bit TX9D    @ TXSTA.0;
bit TRMT    @ TXSTA.1;
bit BRGH    @ TXSTA.2;
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

bit ABDEN   @ BAUDCTL.0;
bit WUE     @ BAUDCTL.1;
bit BRG16   @ BAUDCTL.3;
bit SCKP    @ BAUDCTL.4;
bit RCIDL   @ BAUDCTL.6;

bit RD      @ EECON1.0;
bit WR      @ EECON1.1;
bit WREN    @ EECON1.2;
bit WRERR   @ EECON1.3;
bit FREE    @ EECON1.4;
bit CFGS    @ EECON1.6;
bit EEPGD   @ EECON1.7;

bit TMR5IP  @ IPR3.0;
bit IC1IP   @ IPR3.1;
bit IC2QEIP @ IPR3.2;
bit IC3DRIP @ IPR3.3;
bit PTIP    @ IPR3.4;

bit TMR5IF  @ PIR3.0;
bit IC1IF   @ PIR3.1;
bit IC2QEIF @ PIR3.2;
bit IC3DRIF @ PIR3.3;
bit PTIF    @ PIR3.4;

bit TMR5IE  @ PIE3.0;
bit IC1IE   @ PIE3.1;
bit IC2QEIE @ PIE3.2;
bit IC3DRIE @ PIE3.3;
bit PTIE    @ PIE3.4;

bit CCP2IP  @ IPR2.0;
bit LVDIP   @ IPR2.2;
bit EEIP    @ IPR2.4;
bit OSFIP   @ IPR2.7;

bit CCP2IF  @ PIR2.0;
bit LVDIF   @ PIR2.2;
bit EEIF    @ PIR2.4;
bit OSFIF   @ PIR2.7;

bit CCP2IE  @ PIE2.0;
bit LVDIE   @ PIE2.2;
bit EEIE    @ PIE2.4;
bit OSFIE   @ PIE2.7;

bit TMR1IP  @ IPR1.0;
bit TMR2IP  @ IPR1.1;
bit CCP1IP  @ IPR1.2;
bit SSPIP   @ IPR1.3;
bit TXIP    @ IPR1.4;
bit RCIP    @ IPR1.5;
bit ADIP    @ IPR1.6;

bit TMR1IF  @ PIR1.0;
bit TMR2IF  @ PIR1.1;
bit CCP1IF  @ PIR1.2;
bit SSPIF   @ PIR1.3;
bit TXIF    @ PIR1.4;
bit RCIF    @ PIR1.5;
bit ADIF    @ PIR1.6;

bit TMR1IE  @ PIE1.0;
bit TMR2IE  @ PIE1.1;
bit CCP1IE  @ PIE1.2;
bit SSPIE   @ PIE1.3;
bit TXIE    @ PIE1.4;
bit RCIE    @ PIE1.5;
bit ADIE    @ PIE1.6;

bit GASEL0  @ ADCHS.0;
bit GASEL1  @ ADCHS.1;
bit GCSEL0  @ ADCHS.2;
bit GCSEL1  @ ADCHS.3;
bit GBSEL0  @ ADCHS.4;
bit GBSEL1  @ ADCHS.5;
bit GDSEL0  @ ADCHS.6;
bit GDSEL1  @ ADCHS.7;

bit PTDIR   @ PTCON1.6;
bit PTEN    @ PTCON1.7;

bit OSYNC   @ PWMCON1.0;
bit UDIS    @ PWMCON1.1;
bit SEVTDIR @ PWMCON1.3;

bit FLTAEN  @ FLTCONFIG.0;
bit FLTAMOD @ FLTCONFIG.1;
bit FLTAS   @ FLTCONFIG.2;
bit FLTCON  @ FLTCONFIG.3;
bit FLTBEN  @ FLTCONFIG.4;
bit FLTBMOD @ FLTCONFIG.5;
bit FLTBS   @ FLTCONFIG.6;

bit CAP1REN @ CAP1CON.6;

bit CAP2REN @ CAP2CON.6;

bit CAP3REN @ CAP3CON.6;

bit FLT1EN  @ DFLTCON.3;
bit FLT2EN  @ DFLTCON.4;
bit FLT3EN  @ DFLTCON.5;
bit FLT4EN  @ DFLTCON.6;
