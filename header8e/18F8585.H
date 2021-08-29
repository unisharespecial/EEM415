// Header file
#ifndef ICD2_DEBUG
 #pragma chip PIC18F8585, core 16, code 24576, ram 0 : 0xCFF

#else
 #pragma chip PIC18F8585, core 16, code 0x5EC0, ram 0 : 0xCFF
 // NOTE: last 320 words are reserved for ICD2 debugging

 char reservedICD2[12] @ 0xCF4;  // reserved RAM for ICD2

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
char ADCON2  @ 0xFC0;
char CCPR1H  @ 0xFBF;
char CCPR1L  @ 0xFBE;
char CCP1CON @ 0xFBD;
char CCPR2H  @ 0xFBC;
char CCPR2L  @ 0xFBB;
char CCP2CON @ 0xFBA;

char ECCP1AS @ 0xFB6;
char CVRCON  @ 0xFB5;
char CMCON   @ 0xFB4;
char TMR3H   @ 0xFB3;
char TMR3L   @ 0xFB2;
char T3CON   @ 0xFB1;
char PSPCON  @ 0xFB0;
char SPBRG   @ 0xFAF;
char RCREG   @ 0xFAE;
char TXREG   @ 0xFAD;
char TXSTA   @ 0xFAC;
char RCSTA   @ 0xFAB;
char EEADRH  @ 0xFAA;
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
char MEMCON  @ 0xF9C;

char TRISJ   @ 0xF9A;
char TRISH   @ 0xF99;
char TRISG   @ 0xF98;
char TRISF   @ 0xF97;
char TRISE   @ 0xF96;
char TRISD   @ 0xF95;
char TRISC   @ 0xF94;
char TRISB   @ 0xF93;
char TRISA   @ 0xF92;
char LATJ    @ 0xF91;
char LATH    @ 0xF90;
char LATG    @ 0xF8F;
char LATF    @ 0xF8E;
char LATE    @ 0xF8D;
char LATD    @ 0xF8C;
char LATC    @ 0xF8B;
char LATB    @ 0xF8A;
char LATA    @ 0xF89;
char PORTJ   @ 0xF88;
char PORTH   @ 0xF87;
char PORTG   @ 0xF86;
char PORTF   @ 0xF85;
char PORTE   @ 0xF84;
char PORTD   @ 0xF83;
char PORTC   @ 0xF82;
char PORTB   @ 0xF81;
char PORTA   @ 0xF80;

char SPBRGH  @ 0xF7F;
char BAUDCON @ 0xF7E;

char ECCP1DEL @ 0xF79;

char ECANCON @ 0xF77;
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

char CANCON_RO0 @ 0xF5F;
char CANSTAT_RO0 @ 0xF5E;
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

char CANCON_RO1 @ 0xF4F;
char CANSTAT_RO1 @ 0xF4E;
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

char CANCON_RO2 @ 0xF3F;
char CANSTAT_RO2 @ 0xF3E;
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

char CANCON_RO3 @ 0xF2F;
char CANSTAT_RO3 @ 0xF2E;
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

char CANCON_RO4 @ 0xE7F;
char CANSTAT_RO4 @ 0xE7E;
char B5D7   @ 0xE7D;
char B5D6   @ 0xE7C;
char B5D5   @ 0xE7B;
char B5D4   @ 0xE7A;
char B5D3   @ 0xE79;
char B5D2   @ 0xE78;
char B5D1   @ 0xE77;
char B5D0   @ 0xE76;
char B5DLC  @ 0xE75;
char B5EIDL @ 0xE74;
char B5EIDH @ 0xE73;
char B5SIDL @ 0xE72;
char B5SIDH @ 0xE71;
char B5CON  @ 0xE70;

char CANCON_RO5 @ 0xE6F;
char CANSTAT_RO5 @ 0xE6E;
char B4D7   @ 0xE6D;
char B4D6   @ 0xE6C;
char B4D5   @ 0xE6B;
char B4D4   @ 0xE6A;
char B4D3   @ 0xE69;
char B4D2   @ 0xE68;
char B4D1   @ 0xE67;
char B4D0   @ 0xE66;
char B4DLC  @ 0xE65;
char B4EIDL @ 0xE64;
char B4EIDH @ 0xE63;
char B4SIDL @ 0xE62;
char B4SIDH @ 0xE61;
char B4CON  @ 0xE60;

char CANCON_RO6 @ 0xE5F;
char CANSTAT_RO6 @ 0xE5E;
char B3D7   @ 0xE5D;
char B3D6   @ 0xE5C;
char B3D5   @ 0xE5B;
char B3D4   @ 0xE5A;
char B3D3   @ 0xE59;
char B3D2   @ 0xE58;
char B3D1   @ 0xE57;
char B3D0   @ 0xE56;
char B3DLC  @ 0xE55;
char B3EIDL @ 0xE54;
char B3EIDH @ 0xE53;
char B3SIDL @ 0xE52;
char B3SIDH @ 0xE51;
char B3CON  @ 0xE50;

char CANCON_RO7 @ 0xE4F;
char CANSTAT_RO7 @ 0xE4E;
char B2D7   @ 0xE4D;
char B2D6   @ 0xE4C;
char B2D5   @ 0xE4B;
char B2D4   @ 0xE4A;
char B2D3   @ 0xE49;
char B2D2   @ 0xE48;
char B2D1   @ 0xE47;
char B2D0   @ 0xE46;
char B2DLC  @ 0xE45;
char B2EIDL @ 0xE44;
char B2EIDH @ 0xE43;
char B2SIDL @ 0xE42;
char B2SIDH @ 0xE41;
char B2CON  @ 0xE40;

char CANCON_RO8 @ 0xE3F;
char CANSTAT_RO8 @ 0xE3E;
char B1D7   @ 0xE3D;
char B1D6   @ 0xE3C;
char B1D5   @ 0xE3B;
char B1D4   @ 0xE3A;
char B1D3   @ 0xE39;
char B1D2   @ 0xE38;
char B1D1   @ 0xE37;
char B1D0   @ 0xE36;
char B1DLC  @ 0xE35;
char B1EIDL @ 0xE34;
char B1EIDH @ 0xE33;
char B1SIDL @ 0xE32;
char B1SIDH @ 0xE31;
char B1CON  @ 0xE30;

char CANCON_RO9 @ 0xE2F;
char CANSTAT_RO9 @ 0xE2E;
char B0D7   @ 0xE2D;
char B0D6   @ 0xE2C;
char B0D5   @ 0xE2B;
char B0D4   @ 0xE2A;
char B0D3   @ 0xE29;
char B0D2   @ 0xE28;
char B0D1   @ 0xE27;
char B0D0   @ 0xE26;
char B0DLC  @ 0xE25;
char B0EIDL @ 0xE24;
char B0EIDH @ 0xE23;
char B0SIDL @ 0xE22;
char B0SIDH @ 0xE21;
char B0CON  @ 0xE20;

char TXBIE @ 0xDFC;

char BIE0  @ 0xDFA;

char BSEL0 @ 0xDF8;

char MSEL3 @ 0xDF3;
char MSEL2 @ 0xDF2;
char MSEL1 @ 0xDF1;
char MSEL0 @ 0xDF0;

char RXFBCON7 @ 0xDE7;
char RXFBCON6 @ 0xDE6;
char RXFBCON5 @ 0xDE5;
char RXFBCON4 @ 0xDE4;
char RXFBCON3 @ 0xDE3;
char RXFBCON2 @ 0xDE2;
char RXFBCON1 @ 0xDE1;
char RXFBCON0 @ 0xDE0;

char SDFLC    @ 0xDD8;

char RXFCON1  @ 0xDD5;
char RXFCON0  @ 0xDD4;

char RXF15EIDL @ 0xD93;
char RXF15EIDH @ 0xD92;
char RXF15SIDL @ 0xD91;
char RXF15SIDH @ 0xD90;

char RXF14EIDL @ 0xD8B;
char RXF14EIDH @ 0xD8A;
char RXF14SIDL @ 0xD89;
char RXF14SIDH @ 0xD88;
char RXF13EIDL @ 0xD87;
char RXF13EIDH @ 0xD86;
char RXF13SIDL @ 0xD85;
char RXF13SIDH @ 0xD84;
char RXF12EIDL @ 0xD83;
char RXF12EIDH @ 0xD82;
char RXF12SIDL @ 0xD81;
char RXF12SIDH @ 0xD80;

char RXF11EIDL @ 0xD7B;
char RXF11EIDH @ 0xD7A;
char RXF11SIDL @ 0xD79;
char RXF11SIDH @ 0xD78;
char RXF10EIDL @ 0xD77;
char RXF10EIDH @ 0xD76;
char RXF10SIDL @ 0xD75;
char RXF10SIDH @ 0xD74;
char RXF9EIDL @ 0xD73;
char RXF9EIDH @ 0xD72;
char RXF9SIDL @ 0xD71;
char RXF9SIDH @ 0xD70;

char RXF8EIDL @ 0xD6B;
char RXF8EIDH @ 0xD6A;
char RXF8SIDL @ 0xD69;
char RXF8SIDH @ 0xD68;
char RXF7EIDL @ 0xD67;
char RXF7EIDH @ 0xD66;
char RXF7SIDL @ 0xD65;
char RXF7SIDH @ 0xD64;
char RXF6EIDL @ 0xD63;
char RXF6EIDH @ 0xD62;
char RXF6SIDL @ 0xD61;
char RXF6SIDH @ 0xD60;

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
bit T08BIT  @ T0CON.6;
bit TMR0ON  @ T0CON.7;

bit SCS     @ OSCCON.0;
bit SCS1    @ OSCCON.1;
bit PLLEN   @ OSCCON.2;
bit LOCK    @ OSCCON.3;

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

bit DC2B0   @ CCP2CON.4;
bit DC2B1   @ CCP2CON.5;

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

bit CIS     @ CMCON.3;
bit C1INV   @ CMCON.4;
bit C2INV   @ CMCON.5;
bit C1OUT   @ CMCON.6;
bit C2OUT   @ CMCON.7;

bit TMR3ON  @ T3CON.0;
bit TMR3CS  @ T3CON.1;
bit T3SYNC_ @ T3CON.2;
bit T3CCP1  @ T3CON.3;
bit T3CKPS0 @ T3CON.4;
bit T3CKPS1 @ T3CON.5;
bit T3CCP2  @ T3CON.6;
bit T3RD16  @ T3CON.7;

bit PSPMODE @ PSPCON.4;
bit IBOV    @ PSPCON.5;
bit OBF     @ PSPCON.6;
bit IBF     @ PSPCON.7;

bit TX9D   @ TXSTA.0;
bit TRMT   @ TXSTA.1;
bit BRGH   @ TXSTA.2;
bit SYNC   @ TXSTA.4;
bit TXEN   @ TXSTA.5;
bit TX9    @ TXSTA.6;
bit CSRC   @ TXSTA.7;

bit RX9D   @ RCSTA.0;
bit OERR   @ RCSTA.1;
bit FERR   @ RCSTA.2;
bit ADDEN  @ RCSTA.3;
bit CREN   @ RCSTA.4;
bit SREN   @ RCSTA.5;
bit RX9    @ RCSTA.6;
bit SPEN   @ RCSTA.7;

bit RD      @ EECON1.0;
bit WR      @ EECON1.1;
bit WREN    @ EECON1.2;
bit WRERR   @ EECON1.3;
bit FREE    @ EECON1.4;
bit CFGS    @ EECON1.6;
bit EEPGD   @ EECON1.7;

bit RXB0IP  @ IPR3.0;
bit RXB1IP  @ IPR3.1;
bit RXBnIP  @ IPR3.1;
bit TXB0IP  @ IPR3.2;
bit TXB1IP  @ IPR3.3;
bit TXB2IP  @ IPR3.4;
bit TXBnIP  @ IPR3.4;
bit ERRIP   @ IPR3.5;
bit WAKIP   @ IPR3.6;
bit IRXIP   @ IPR3.7;

bit RXB0IF  @ PIR3.0;
bit RXB1IF  @ PIR3.1;
bit RXBnIF  @ PIR3.1;
bit TXB0IF  @ PIR3.2;
bit TXB1IF  @ PIR3.3;
bit TXB2IF  @ PIR3.4;
bit TXBnIF  @ PIR3.4;
bit ERRIF   @ PIR3.5;
bit WAKIF   @ PIR3.6;
bit IRXIF   @ PIR3.7;

bit RXB0IE  @ PIE3.0;
bit RXB1IE  @ PIE3.1;
bit RXBnIE  @ PIE3.1;
bit TXB0IE  @ PIE3.2;
bit TXB1IE  @ PIE3.3;
bit TXB2IE  @ PIE3.4;
bit TXBnIE  @ PIE3.4;
bit ERRIE   @ PIE3.5;
bit WAKIE   @ PIE3.6;
bit IRXIE   @ PIE3.7;

bit CCP2IP  @ IPR2.0;
bit TMR3IP  @ IPR2.1;
bit LVDIP   @ IPR2.2;
bit BCLIP   @ IPR2.3;
bit EEIP    @ IPR2.4;
bit CMIP    @ IPR2.6;

bit CCP2IF  @ PIR2.0;
bit TMR3IF  @ PIR2.1;
bit LVDIF   @ PIR2.2;
bit BCLIF   @ PIR2.3;
bit EEIF    @ PIR2.4;
bit CMIF    @ PIR2.6;

bit CCP2IE  @ PIE2.0;
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

bit WM0     @ MEMCON.0;
bit WM1     @ MEMCON.1;
bit WAIT0   @ MEMCON.4;
bit WAIT1   @ MEMCON.5;
bit EBDIS   @ MEMCON.7;

bit ABDEN   @ BAUDCON.0;
bit WUE     @ BAUDCON.1;
bit BRG16   @ BAUDCON.3;
bit SCKP    @ BAUDCON.4;
bit RCIDL   @ BAUDCON.6;
