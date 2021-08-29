// Header file
#ifndef ICD2_DEBUG
 #pragma chip PIC18F44K20, core 16, code 8192, ram 0 : 0x2FF

#else
 #pragma chip PIC18F44K20, core 16, code 0x1EE0, ram 0 : 0x2FF
 // NOTE: last 288 words are reserved for ICD2 debugging

 char reservedICD2[12] @ 0x2F4;  // reserved RAM for ICD2

 #pragma stackLevels 29   // reserve two levels for debugging
#endif

// Extended Instruction Set

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

char TMR0H    @ 0xFD7;
char TMR0L    @ 0xFD6;
char T0CON    @ 0xFD5;

char OSCCON   @ 0xFD3;
char HLVDCON  @ 0xFD2;
char WDTCON   @ 0xFD1;
char RCON     @ 0xFD0;
char TMR1H    @ 0xFCF;
char TMR1L    @ 0xFCE;
char T1CON    @ 0xFCD;
char TMR2     @ 0xFCC;
char PR2      @ 0xFCB;
char T2CON    @ 0xFCA;
char SSPBUF   @ 0xFC9;
char SSPADD   @ 0xFC8;
char SSPSTAT  @ 0xFC7;
char SSPCON1  @ 0xFC6;
char SSPCON2  @ 0xFC5;
char ADRESH   @ 0xFC4;
char ADRESL   @ 0xFC3;
char ADCON0   @ 0xFC2;
char ADCON1   @ 0xFC1;
char ADCON2   @ 0xFC0;
char CCPR1H   @ 0xFBF;
char CCPR1L   @ 0xFBE;
char CCP1CON  @ 0xFBD;
char CCPR2H   @ 0xFBC;
char CCPR2L   @ 0xFBB;
char CCP2CON  @ 0xFBA;
char PSTRCON  @ 0xFB9;
char BAUDCTL  @ 0xFB8;
char PWM1CON  @ 0xFB7;
char ECCP1AS  @ 0xFB6;
char CVRCON   @ 0xFB5;
char CVRCON2  @ 0xFB4;
char TMR3H    @ 0xFB3;
char TMR3L    @ 0xFB2;
char T3CON    @ 0xFB1;
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

char IPR2     @ 0xFA2;
char PIR2     @ 0xFA1;
char PIE2     @ 0xFA0;
char IPR1     @ 0xF9F;
char PIR1     @ 0xF9E;
char PIE1     @ 0xF9D;

char OSCTUNE  @ 0xF9B;

char TRISE    @ 0xF96;
char TRISD    @ 0xF95;
char TRISC    @ 0xF94;
char TRISB    @ 0xF93;
char TRISA    @ 0xF92;

char LATE     @ 0xF8D;
char LATD     @ 0xF8C;
char LATC     @ 0xF8B;
char LATB     @ 0xF8A;
char LATA     @ 0xF89;

char PORTE    @ 0xF84;
char PORTD    @ 0xF83;
char PORTC    @ 0xF82;
char PORTB    @ 0xF81;
char PORTA    @ 0xF80;
char ANSELH   @ 0xF7F;
char ANSEL    @ 0xF7E;
char IOCB     @ 0xF7D;
char WPUB     @ 0xF7C;
char CM1CON0  @ 0xF7B;
char CM2CON0  @ 0xF7A;
char CM2CON1  @ 0xF79;
char SLRCON   @ 0xF78;
char SSPMSK   @ 0xF77;

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

bit PSA     @ T0CON.3;
bit T0SE    @ T0CON.4;
bit T0CS    @ T0CON.5;
bit T08BIT  @ T0CON.6;
bit TMR0ON  @ T0CON.7;

bit SCS0    @ OSCCON.0;
bit SCS1    @ OSCCON.1;
bit IOFS    @ OSCCON.2;
bit OSTS    @ OSCCON.3;
bit IDLEN   @ OSCCON.7;

bit HLVDEN  @ HLVDCON.4;
bit IRVST   @ HLVDCON.5;
bit VDIRMAG @ HLVDCON.7;

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

bit CKP     @ SSPCON1.4;
bit SSPEN   @ SSPCON1.5;
bit SSPOV   @ SSPCON1.6;
bit WCOL    @ SSPCON1.7;

bit SEN     @ SSPCON2.0;
bit RSEN    @ SSPCON2.1;
bit PEN     @ SSPCON2.2;
bit RCEN    @ SSPCON2.3;
bit ACKEN   @ SSPCON2.4;
bit ACKDT   @ SSPCON2.5;
bit ACKSTAT @ SSPCON2.6;
bit GCEN    @ SSPCON2.7;

bit ADON    @ ADCON0.0;
bit GO      @ ADCON0.1;
bit CHS0    @ ADCON0.2;
bit CHS1    @ ADCON0.3;
bit CHS2    @ ADCON0.4;
bit CHS3    @ ADCON0.5;

bit VCFG0   @ ADCON1.4;
bit VCFG1   @ ADCON1.5;

bit ADCS0   @ ADCON2.0;
bit ADCS1   @ ADCON2.1;
bit ADCS2   @ ADCON2.2;
bit ADFM    @ ADCON2.7;

bit DC1B0   @ CCP1CON.4;
bit DC1B1   @ CCP1CON.5;
bit P1M0    @ CCP1CON.6;
bit P1M1    @ CCP1CON.7;

bit DC2B0   @ CCP2CON.4;
bit DC2B1   @ CCP2CON.5;

bit STRA    @ PSTRCON.0;
bit STRB    @ PSTRCON.1;
bit STRC    @ PSTRCON.2;
bit STRD    @ PSTRCON.3;
bit STRSYNC @ PSTRCON.4;

bit ABDEN   @ BAUDCTL.0;
bit WUE     @ BAUDCTL.1;
bit BRG16   @ BAUDCTL.3;
bit CKTXP   @ BAUDCTL.4;
bit DTRXP   @ BAUDCTL.5;
bit RCIDL   @ BAUDCTL.6;
bit ABDOVF  @ BAUDCTL.7;

bit PRSEN   @ PWM1CON.7;

bit PSSBD0  @ ECCP1AS.0;
bit PSSBD1  @ ECCP1AS.1;
bit PSSAC0  @ ECCP1AS.2;
bit PSSAC1  @ ECCP1AS.3;
bit ECCPAS0 @ ECCP1AS.4;
bit ECCPAS1 @ ECCP1AS.5;
bit ECCPAS2 @ ECCP1AS.6;
bit ECCPASE @ ECCP1AS.7;

bit CVRSS   @ CVRCON.4;
bit CVRR    @ CVRCON.5;
bit CVROE   @ CVRCON.6;
bit CVREN   @ CVRCON.7;

bit FVRST   @ CVRCON2.6;
bit FVREN   @ CVRCON2.7;

bit TMR3ON  @ T3CON.0;
bit TMR3CS  @ T3CON.1;
bit T3SYNC_ @ T3CON.2;
bit T3CCP1  @ T3CON.3;
bit T3CKPS0 @ T3CON.4;
bit T3CKPS1 @ T3CON.5;
bit T3CCP2  @ T3CON.6;
bit T3RD16  @ T3CON.7;

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

bit CCP2IP  @ IPR2.0;
bit TMR3IP  @ IPR2.1;
bit HLVDIP  @ IPR2.2;
bit BCLIP   @ IPR2.3;
bit EEIP    @ IPR2.4;
bit C2IP    @ IPR2.5;
bit C1IP    @ IPR2.6;
bit OSCFIP  @ IPR2.7;

bit CCP2IF  @ PIR2.0;
bit TMR3IF  @ PIR2.1;
bit HLVDIF  @ PIR2.2;
bit BCLIF   @ PIR2.3;
bit EEIF    @ PIR2.4;
bit C2IF    @ PIR2.5;
bit C1IF    @ PIR2.6;
bit OSCFIF  @ PIR2.7;

bit CCP2IE  @ PIE2.0;
bit TMR3IE  @ PIE2.1;
bit HLVDIE  @ PIE2.2;
bit BCLIE   @ PIE2.3;
bit EEIE    @ PIE2.4;
bit C2IE    @ PIE2.5;
bit C1IE    @ PIE2.6;
bit OSCFIE  @ PIE2.7;

bit TMR1IP  @ IPR1.0;
bit TMR2IP  @ IPR1.1;
bit CCP1IP  @ IPR1.2;
bit SSPIP   @ IPR1.3;
bit TXIP    @ IPR1.4;
bit RCIP    @ IPR1.5;
bit ADIP    @ IPR1.6;
bit PSPIP   @ IPR1.7;

bit TMR1IF  @ PIR1.0;
bit TMR2IF  @ PIR1.1;
bit CCP1IF  @ PIR1.2;
bit SSPIF   @ PIR1.3;
bit TXIF    @ PIR1.4;
bit RCIF    @ PIR1.5;
bit ADIF    @ PIR1.6;
bit PSPIF   @ PIR1.7;

bit TMR1IE  @ PIE1.0;
bit TMR2IE  @ PIE1.1;
bit CCP1IE  @ PIE1.2;
bit SSPIE   @ PIE1.3;
bit TXIE    @ PIE1.4;
bit RCIE    @ PIE1.5;
bit ADIE    @ PIE1.6;
bit PSPIE   @ PIE1.7;

bit PLLEN   @ OSCTUNE.6;
bit INTSRC  @ OSCTUNE.7;

bit PSPMODE @ TRISE.4;
bit IBOV    @ TRISE.5;
bit OBF     @ TRISE.6;
bit IBF     @ TRISE.7;

bit C1CH0   @ CM1CON0.0;
bit C1CH1   @ CM1CON0.1;
bit C1R     @ CM1CON0.2;
bit C1SP    @ CM1CON0.3;
bit C1POL   @ CM1CON0.4;
bit C1OE    @ CM1CON0.5;
bit C1OUT   @ CM1CON0.6;
bit C1ON    @ CM1CON0.7;

bit C2CH0   @ CM2CON0.0;
bit C2CH1   @ CM2CON0.1;
bit C2R     @ CM2CON0.2;
bit C2SP    @ CM2CON0.3;
bit C2POL   @ CM2CON0.4;
bit C2OE    @ CM2CON0.5;
bit C2OUT   @ CM2CON0.6;
bit C2ON    @ CM2CON0.7;

bit C2RSEL  @ CM2CON1.4;
bit C1RSEL  @ CM2CON1.5;
bit MC2OUT  @ CM2CON1.6;
bit MC1OUT  @ CM2CON1.7;

bit SLRA    @ SLRCON.0;
bit SLRB    @ SLRCON.1;
bit SLRC    @ SLRCON.2;
bit SLRD    @ SLRCON.3;
bit SLRE    @ SLRCON.4;
