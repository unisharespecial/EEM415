// Header file
#ifndef ICD2_DEBUG
 #pragma chip PIC18F248, core 16, code 8192, ram 0 : 0x2FF

#else
 #pragma chip PIC18F248, core 16, code 0x1EE0, ram 0 : 0x2FF
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
char SSPCON1 @ 0xFC6;
char SSPCON2 @ 0xFC5;
char ADRESH  @ 0xFC4;
char ADRESL  @ 0xFC3;
char ADCON0  @ 0xFC2;
char ADCON1  @ 0xFC1;

char CCPR1H  @ 0xFBF;
char CCPR1L  @ 0xFBE;
char CCP1CON @ 0xFBD;

char TMR3H   @ 0xFB3;
char TMR3L   @ 0xFB2;
char T3CON   @ 0xFB1;
char SPBRG   @ 0xFAF;
char RCREG   @ 0xFAE;
char TXREG   @ 0xFAD;
char TXSTA   @ 0xFAC;
char RCSTA   @ 0xFAB;

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

char TRISC   @ 0xF94;
char TRISB   @ 0xF93;
char TRISA   @ 0xF92;


char LATC    @ 0xF8B;
char LATB    @ 0xF8A;
char LATA    @ 0xF89;

char PORTC   @ 0xF82;
char PORTB   @ 0xF81;
char PORTA   @ 0xF80;

char TXERRCNT @ 0xF76;
char RXERRCNT @ 0xF75;
char COMSTAT @ 0xF74;
char CIOCON  @ 0xF73;
char BRGCON3 @ 0xF72;
char BRGCON2 @ 0xF71;
char BRGCON1 @ 0xF70;
char CANCON  @ 0xF6F;
char CANSTAT @ 0xF6E;
char RXB0D7  @ 0xF6D;
char RXB0D6  @ 0xF6C;
char RXB0D5  @ 0xF6B;
char RXB0D4  @ 0xF6A;
char RXB0D3  @ 0xF69;
char RXB0D2  @ 0xF68;
char RXB0D1  @ 0xF67;
char RXB0D0  @ 0xF66;
char RXB0DLC @ 0xF65;
char RXB0EIDL @ 0xF64;
char RXB0EIDH @ 0xF63;
char RXB0SIDL @ 0xF62;
char RXB0SIDH @ 0xF61;
char RXB0CON @ 0xF60;

char CANSTATRO1 @ 0xF5E;
char RXB1D7  @ 0xF5D;
char RXB1D6  @ 0xF5C;
char RXB1D5  @ 0xF5B;
char RXB1D4  @ 0xF5A;
char RXB1D3  @ 0xF59;
char RXB1D2  @ 0xF58;
char RXB1D1  @ 0xF57;
char RXB1D0  @ 0xF56;
char RXB1DLC @ 0xF55;
char RXB1EIDL @ 0xF54;
char RXB1EIDH @ 0xF53;
char RXB1SIDL @ 0xF52;
char RXB1SIDH @ 0xF51;
char RXB1CON @ 0xF50;

char CANSTATRO2 @ 0xF4E;
char TXB0D7  @ 0xF4D;
char TXB0D6  @ 0xF4C;
char TXB0D5  @ 0xF4B;
char TXB0D4  @ 0xF4A;
char TXB0D3  @ 0xF49;
char TXB0D2  @ 0xF48;
char TXB0D1  @ 0xF47;
char TXB0D0  @ 0xF46;
char TXB0DLC @ 0xF45;
char TXB0EIDL @ 0xF44;
char TXB0EIDH @ 0xF43;
char TXB0SIDL @ 0xF42;
char TXB0SIDH @ 0xF41;
char TXB0CON @ 0xF40;

char CANSTATRO3 @ 0xF3E;
char TXB1D7  @ 0xF3D;
char TXB1D6  @ 0xF3C;
char TXB1D5  @ 0xF3B;
char TXB1D4  @ 0xF3A;
char TXB1D3  @ 0xF39;
char TXB1D2  @ 0xF38;
char TXB1D1  @ 0xF37;
char TXB1D0  @ 0xF36;
char TXB1DLC @ 0xF35;
char TXB1EIDL @ 0xF34;
char TXB1EIDH @ 0xF33;
char TXB1SIDL @ 0xF32;
char TXB1SIDH @ 0xF31;
char TXB1CON @ 0xF30;

char CANSTATRO4 @ 0xF2E;
char TXB2D7  @ 0xF2D;
char TXB2D6  @ 0xF2C;
char TXB2D5  @ 0xF2B;
char TXB2D4  @ 0xF2A;
char TXB2D3  @ 0xF29;
char TXB2D2  @ 0xF28;
char TXB2D1  @ 0xF27;
char TXB2D0  @ 0xF26;
char TXB2DLC @ 0xF25;
char TXB2EIDL @ 0xF24;
char TXB2EIDH @ 0xF23;
char TXB2SIDL @ 0xF22;
char TXB2SIDH @ 0xF21;
char TXB2CON @ 0xF20;

char RXM1EIDL @ 0xF1F;
char RXM1EIDH @ 0xF1E;
char RXM1SIDL @ 0xF1D;
char RXM1SIDH @ 0xF1C;
char RXM0EIDL @ 0xF1B;
char RXM0EIDH @ 0xF1A;
char RXM0SIDL @ 0xF19;
char RXM0SIDH @ 0xF18;
char RXF5EIDL @ 0xF17;
char RXF5EIDH @ 0xF16;
char RXF5SIDL @ 0xF15;
char RXF5SIDH @ 0xF14;
char RXF4EIDL @ 0xF13;
char RXF4EIDH @ 0xF12;
char RXF4SIDL @ 0xF11;
char RXF4SIDH @ 0xF10;
char RXF3EIDL @ 0xF0F;
char RXF3EIDH @ 0xF0E;
char RXF3SIDL @ 0xF0D;
char RXF3SIDH @ 0xF0C;
char RXF2EIDL @ 0xF0B;
char RXF2EIDH @ 0xF0A;
char RXF2SIDL @ 0xF09;
char RXF2SIDH @ 0xF08;
char RXF1EIDL @ 0xF07;
char RXF1EIDH @ 0xF06;
char RXF1SIDL @ 0xF05;
char RXF1SIDH @ 0xF04;
char RXF0EIDL @ 0xF03;
char RXF0EIDH @ 0xF02;
char RXF0SIDL @ 0xF01;
char RXF0SIDH @ 0xF00;


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
bit INTEDG1 @ INTCON2.5;
bit INTEDG0 @ INTCON2.6;
bit RBPU    @ INTCON2.7;

bit INT1IF  @ INTCON3.0;
bit INT1IE  @ INTCON3.3;
bit INT1IP  @ INTCON3.6;

bit PSA     @ T0CON.3;
bit T0SE    @ T0CON.4;
bit T0CS    @ T0CON.5;
bit T08BIT  @ T0CON.6;
bit TMR0ON  @ T0CON.7;

bit SCS     @ OSCCON.0;

bit LVDEN   @ LVDCON.4;
bit IRVST   @ LVDCON.5;

bit SWDTEN  @ WDTCON.0;

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
bit GO      @ ADCON0.2;
bit CHS0    @ ADCON0.3;
bit CHS1    @ ADCON0.4;
bit CHS2    @ ADCON0.5;
bit ADCS0   @ ADCON0.6;
bit ADCS1   @ ADCON0.7;

bit ADCS2   @ ADCON1.6;
bit ADFM    @ ADCON1.7;

bit DC1B0   @ CCP1CON.4;
bit DC1B1   @ CCP1CON.5;

bit TMR3ON  @ T3CON.0;
bit TMR3CS  @ T3CON.1;
bit T3SYNC_ @ T3CON.2;
bit T3CCP1  @ T3CON.3;
bit T3CKPS0 @ T3CON.4;
bit T3CKPS1 @ T3CON.5;
bit T3ECCP1 @ T3CON.6;
bit T3RD16  @ T3CON.7;

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

bit RD      @ EECON1.0;
bit WR      @ EECON1.1;
bit WREN    @ EECON1.2;
bit WRERR   @ EECON1.3;
bit FREE    @ EECON1.4;
bit CFGS    @ EECON1.6;
bit EEPGD   @ EECON1.7;

bit RXB0IP  @ IPR3.0;
bit RXB1IP  @ IPR3.1;
bit TXB0IP  @ IPR3.2;
bit TXB1IP  @ IPR3.3;
bit TXB2IP  @ IPR3.4;
bit ERRIP   @ IPR3.5;
bit WAKIP   @ IPR3.6;
bit IRXIP   @ IPR3.7;

bit RXB0IF  @ PIR3.0;
bit RXB1IF  @ PIR3.1;
bit TXB0IF  @ PIR3.2;
bit TXB1IF  @ PIR3.3;
bit TXB2IF  @ PIR3.4;
bit ERRIF   @ PIR3.5;
bit WAKIF   @ PIR3.6;
bit IRXIF   @ PIR3.7;

bit RXB0IE  @ PIE3.0;
bit RXB1IE  @ PIE3.1;
bit TXB0IE  @ PIE3.2;
bit TXB1IE  @ PIE3.3;
bit TXB2IE  @ PIE3.4;
bit ERRIE   @ PIE3.5;
bit WAKIE   @ PIE3.6;
bit IRXIE   @ PIE3.7;

bit TMR3IP  @ IPR2.1;
bit LVDIP   @ IPR2.2;
bit BCLIP   @ IPR2.3;
bit EEIP    @ IPR2.4;
bit CMIP    @ IPR2.6;

bit TMR3IF  @ PIR2.1;
bit LVDIF   @ PIR2.2;
bit BCLIF   @ PIR2.3;
bit EEIF    @ PIR2.4;
bit CMIF    @ PIR2.6;

bit TMR3IE  @ PIE2.1;
bit LVDIE   @ PIE2.2;
bit BCLIE   @ PIE2.3;
bit EEIE    @ PIE2.4;
bit CMIE    @ PIE2.6;

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
