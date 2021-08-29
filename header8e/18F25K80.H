// Header file
#pragma chip PIC18F25K80, core 16, code 16384, ram 0 : 0xE3F

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
char OSCCON2  @ 0xFD2;
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
char ECCP1AS  @ 0xFBF;
char ECCP1DEL @ 0xFBE;
char CCPR1H   @ 0xFBD;
char CCPR1L   @ 0xFBC;
char CCP1CON  @ 0xFBB;
char TXSTA2   @ 0xFBA;
char BAUDCON2 @ 0xFB9;
char IPR4     @ 0xFB8;
char PIR4     @ 0xFB7;
char PIE4     @ 0xFB6;
char CVRCON   @ 0xFB5;
char CMSTAT   @ 0xFB4;
char TMR3H    @ 0xFB3;
char TMR3L    @ 0xFB2;
char T3CON    @ 0xFB1;
char T3GCON   @ 0xFB0;
char SPBRG1   @ 0xFAF;
char RCREG1   @ 0xFAE;
char TXREG1   @ 0xFAD;
char TXSTA1   @ 0xFAC;
char RCSTA1   @ 0xFAB;
char T1GCON   @ 0xFAA;
char PR4      @ 0xFA9;
char HLVDCON  @ 0xFA8;
char BAUDCON1 @ 0xFA7;
char RCSTA2   @ 0xFA6;
char IPR3     @ 0xFA5;
char PIR3     @ 0xFA4;
char PIE3     @ 0xFA3;
char IPR2     @ 0xFA2;
char PIR2     @ 0xFA1;
char PIE2     @ 0xFA0;
char IPR1     @ 0xF9F;
char PIR1     @ 0xF9E;
char PIE1     @ 0xF9D;
char PSTR1CON @ 0xF9C;
char OSCTUNE  @ 0xF9B;
char REFOCON  @ 0xF9A;
char CCPTMRS  @ 0xF99;

char TRISC    @ 0xF94;
char TRISB    @ 0xF93;
char TRISA    @ 0xF92;
char ODCON    @ 0xF91;
char SLRCON   @ 0xF90;

char LATC     @ 0xF8B;
char LATB     @ 0xF8A;
char LATA     @ 0xF89;
char T4CON    @ 0xF88;
char TMR4     @ 0xF87;

char PORTC    @ 0xF82;
char PORTB    @ 0xF81;
char PORTA    @ 0xF80;
char EECON1   @ 0xF7F;
char EECON2   @ 0xF7E;
char SPBRGH1  @ 0xF7D;
char SPBRGH2  @ 0xF7C;
char SPBRG2   @ 0xF7B;
char RCREG2   @ 0xF7A;
char TXREG2   @ 0xF79;
char IPR5     @ 0xF78;
char PIR5     @ 0xF77;
char PIE5     @ 0xF76;
char EEADRH   @ 0xF75;
char EEADR    @ 0xF74;
char EEDATA   @ 0xF73;
char ECANCON  @ 0xF72;
char COMSTAT  @ 0xF71;
char CIOCON   @ 0xF70;
char CANCON   @ 0xF6F;
char CANSTAT  @ 0xF6E;
char RXB0D7   @ 0xF6D;
char RXB0D6   @ 0xF6C;
char RXB0D5   @ 0xF6B;
char RXB0D4   @ 0xF6A;
char RXB0D3   @ 0xF69;
char RXB0D2   @ 0xF68;
char RXB0D1   @ 0xF67;
char RXB0D0   @ 0xF66;
char RXB0DLC  @ 0xF65;
char RXB0EIDL @ 0xF64;
char RXB0EIDH @ 0xF63;
char RXB0SIDL @ 0xF62;
char RXB0SIDH @ 0xF61;
char RXB0CON  @ 0xF60;
char CM1CON   @ 0xF5F;
char CM2CON   @ 0xF5E;
char ANCON0   @ 0xF5D;
char ANCON1   @ 0xF5C;
char WPUB     @ 0xF5B;
char IOCB     @ 0xF5A;
char PMD0     @ 0xF59;
char PMD1     @ 0xF58;
char PMD2     @ 0xF57;
char PADCFG1  @ 0xF56;
char CTMUCONH @ 0xF55;
char CTMUCONL @ 0xF54;
char CTMUICON @ 0xF53;
char CCPR2H   @ 0xF52;
char CCPR2L   @ 0xF51;
char CCP2CON  @ 0xF50;
char CCPR3H   @ 0xF4F;
char CCPR3L   @ 0xF4E;
char CCP3CON  @ 0xF4D;
char CCPR4H   @ 0xF4C;
char CCPR4L   @ 0xF4B;
char CCP4CON  @ 0xF4A;
char CCPR5H   @ 0xF49;
char CCPR5L   @ 0xF48;
char CCP5CON  @ 0xF47;
char PSPCON   @ 0xF46;
char MDCON    @ 0xF45;
char MDSRC    @ 0xF44;
char MDCARH   @ 0xF43;
char MDCARL   @ 0xF42;

char CANCON_RO0 @ 0xF3F;
char CANSTAT_RO0 @ 0xF3E;
char RXB1D7   @ 0xF3D;
char RXB1D6   @ 0xF3C;
char RXB1D5   @ 0xF3B;
char RXB1D4   @ 0xF3A;
char RXB1D3   @ 0xF39;
char RXB1D2   @ 0xF38;
char RXB1D1   @ 0xF37;
char RXB1D0   @ 0xF36;
char RXB1DLC  @ 0xF35;
char RXB1EIDL @ 0xF34;
char RXB1EIDH @ 0xF33;
char RXB1SIDL @ 0xF32;
char RXB1SIDH @ 0xF31;
char RXB1CON  @ 0xF30;
char CANCON_RO1 @ 0xF2F;
char CANSTAT_RO1 @ 0xF2E;
char TXB0D7   @ 0xF2D;
char TXB0D6   @ 0xF2C;
char TXB0D5   @ 0xF2B;
char TXB0D4   @ 0xF2A;
char TXB0D3   @ 0xF29;
char TXB0D2   @ 0xF28;
char TXB0D1   @ 0xF27;
char TXB0D0   @ 0xF26;
char TXB0DLC  @ 0xF25;
char TXB0EIDL @ 0xF24;
char TXB0EIDH @ 0xF23;
char TXB0SIDL @ 0xF22;
char TXB0SIDH @ 0xF21;
char TXB0CON  @ 0xF20;
char CANCON_RO2 @ 0xF1F;
char CANSTAT_RO2 @ 0xF1E;
char TXB1D7   @ 0xF1D;
char TXB1D6   @ 0xF1C;
char TXB1D5   @ 0xF1B;
char TXB1D4   @ 0xF1A;
char TXB1D3   @ 0xF19;
char TXB1D2   @ 0xF18;
char TXB1D1   @ 0xF17;
char TXB1D0   @ 0xF16;
char TXB1DLC  @ 0xF15;
char TXB1EIDL @ 0xF14;
char TXB1EIDH @ 0xF13;
char TXB1SIDL @ 0xF12;
char TXB1SIDH @ 0xF11;
char TXB1CON  @ 0xF10;
char CANCON_RO3 @ 0xF0F;
char CANSTAT_RO3 @ 0xF0E;
char TXB2D7   @ 0xF0D;
char TXB2D6   @ 0xF0C;
char TXB2D5   @ 0xF0B;
char TXB2D4   @ 0xF0A;
char TXB2D3   @ 0xF09;
char TXB2D2   @ 0xF08;
char TXB2D1   @ 0xF07;
char TXB2D0   @ 0xF06;
char TXB2DLC  @ 0xF05;
char TXB2EIDL @ 0xF04;
char TXB2EIDH @ 0xF03;
char TXB2SIDL @ 0xF02;
char TXB2SIDH @ 0xF01;
char TXB2CON  @ 0xF00;
char RXM1EIDL @ 0xEFF;
char RXM1EIDH @ 0xEFE;
char RXM1SIDL @ 0xEFD;
char RXM1SIDH @ 0xEFC;
char RXM0EIDL @ 0xEFB;
char RXM0EIDH @ 0xEFA;
char RXM0SIDL @ 0xEF9;
char RXM0SIDH @ 0xEF8;
char RXF5EIDL @ 0xEF7;
char RXF5EIDH @ 0xEF6;
char RXF5SIDL @ 0xEF5;
char RXF5SIDH @ 0xEF4;
char RXF4EIDL @ 0xEF3;
char RXF4EIDH @ 0xEF2;
char RXF4SIDL @ 0xEF1;
char RXF4SIDH @ 0xEF0;
char RXF3EIDL @ 0xEEF;
char RXF3EIDH @ 0xEEE;
char RXF3SIDL @ 0xEED;
char RXF3SIDH @ 0xEEC;
char RXF2EIDL @ 0xEEB;
char RXF2EIDH @ 0xEEA;
char RXF2SIDL @ 0xEE9;
char RXF2SIDH @ 0xEE8;
char RXF1EIDL @ 0xEE7;
char RXF1EIDH @ 0xEE6;
char RXF1SIDL @ 0xEE5;
char RXF1SIDH @ 0xEE4;
char RXF0EIDL @ 0xEE3;
char RXF0EIDH @ 0xEE2;
char RXF0SIDL @ 0xEE1;
char RXF0SIDH @ 0xEE0;
char CANCON_RO4 @ 0xEDF;
char CANSTAT_RO4 @ 0xEDE;
char B5D7     @ 0xEDD;
char B5D6     @ 0xEDC;
char B5D5     @ 0xEDB;
char B5D4     @ 0xEDA;
char B5D3     @ 0xED9;
char B5D2     @ 0xED8;
char B5D1     @ 0xED7;
char B5D0     @ 0xED6;
char B5DLC    @ 0xED5;
char B5EIDL   @ 0xED4;
char B5EIDH   @ 0xED3;
char B5SIDL   @ 0xED2;
char B5SIDH   @ 0xED1;
char B5CON    @ 0xED0;
char CANCON_RO5 @ 0xECF;
char CANSTAT_RO5 @ 0xECE;
char B4D7     @ 0xECD;
char B4D6     @ 0xECC;
char B4D5     @ 0xECB;
char B4D4     @ 0xECA;
char B4D3     @ 0xEC9;
char B4D2     @ 0xEC8;
char B4D1     @ 0xEC7;
char B4D0     @ 0xEC6;
char B4DLC    @ 0xEC5;
char B4EIDL   @ 0xEC4;
char B4EIDH   @ 0xEC3;
char B4SIDL   @ 0xEC2;
char B4SIDH   @ 0xEC1;
char B4CON    @ 0xEC0;
char CANCON_RO6 @ 0xEBF;
char CANSTAT_RO6 @ 0xEBE;
char B3D7     @ 0xEBD;
char B3D6     @ 0xEBC;
char B3D5     @ 0xEBB;
char B3D4     @ 0xEBA;
char B3D3     @ 0xEB9;
char B3D2     @ 0xEB8;
char B3D1     @ 0xEB7;
char B3D0     @ 0xEB6;
char B3DLC    @ 0xEB5;
char B3EIDL   @ 0xEB4;
char B3EIDH   @ 0xEB3;
char B3SIDL   @ 0xEB2;
char B3SIDH   @ 0xEB1;
char B3CON    @ 0xEB0;
char CANCON_RO7 @ 0xEAF;
char CANSTAT_RO7 @ 0xEAE;
char B2D7     @ 0xEAD;
char B2D6     @ 0xEAC;
char B2D5     @ 0xEAB;
char B2D4     @ 0xEAA;
char B2D3     @ 0xEA9;
char B2D2     @ 0xEA8;
char B2D1     @ 0xEA7;
char B2D0     @ 0xEA6;
char B2DLC    @ 0xEA5;
char B2EIDL   @ 0xEA4;
char B2EIDH   @ 0xEA3;
char B2SIDL   @ 0xEA2;
char B2SIDH   @ 0xEA1;
char B2CON    @ 0xEA0;
char CANCON_RO8 @ 0xE9F;
char CANSTAT_RO8 @ 0xE9E;
char B1D7     @ 0xE9D;
char B1D6     @ 0xE9C;
char B1D5     @ 0xE9B;
char B1D4     @ 0xE9A;
char B1D3     @ 0xE99;
char B1D2     @ 0xE98;
char B1D1     @ 0xE97;
char B1D0     @ 0xE96;
char B1DLC    @ 0xE95;
char B1EIDL   @ 0xE94;
char B1EIDH   @ 0xE93;
char B1SIDL   @ 0xE92;
char B1SIDH   @ 0xE91;
char B1CON    @ 0xE90;
char CANCON_RO9 @ 0xE8F;
char CANSTAT_RO9 @ 0xE8E;
char B0D7     @ 0xE8D;
char B0D6     @ 0xE8C;
char B0D5     @ 0xE8B;
char B0D4     @ 0xE8A;
char B0D3     @ 0xE89;
char B0D2     @ 0xE88;
char B0D1     @ 0xE87;
char B0D0     @ 0xE86;
char B0DLC    @ 0xE85;
char B0EIDL   @ 0xE84;
char B0EIDH   @ 0xE83;
char B0SIDL   @ 0xE82;
char B0SIDH   @ 0xE81;
char B0CON    @ 0xE80;
char TXBIE    @ 0xE7F;
char BIE0     @ 0xE7E;
char BSEL0    @ 0xE7D;
char MSEL3    @ 0xE7C;
char MSEL2    @ 0xE7B;
char MSEL1    @ 0xE7A;
char MSEL0    @ 0xE79;
char RXFBCON7 @ 0xE78;
char RXFBCON6 @ 0xE77;
char RXFBCON5 @ 0xE76;
char RXFBCON4 @ 0xE75;
char RXFBCON3 @ 0xE74;
char RXFBCON2 @ 0xE73;
char RXFBCON1 @ 0xE72;
char RXFBCON0 @ 0xE71;
char SDFLC    @ 0xE70;
char RXF15EIDL @ 0xE6F;
char RXF15EIDH @ 0xE6E;
char RXF15SIDL @ 0xE6D;
char RXF15SIDH @ 0xE6C;
char RXF14EIDL @ 0xE6B;
char RXF14EIDH @ 0xE6A;
char RXF14SIDL @ 0xE69;
char RXF14SIDH @ 0xE68;
char RXF13EIDL @ 0xE67;
char RXF13EIDH @ 0xE66;
char RXF13SIDL @ 0xE65;
char RXF13SIDH @ 0xE64;
char RXF12EIDL @ 0xE63;
char RXF12EIDH @ 0xE62;
char RXF12SIDL @ 0xE61;
char RXF12SIDH @ 0xE60;
char RXF11EIDL @ 0xE5F;
char RXF11EIDH @ 0xE5E;
char RXF11SIDL @ 0xE5D;
char RXF11SIDH @ 0xE5C;
char RXF10EIDL @ 0xE5B;
char RXF10EIDH @ 0xE5A;
char RXF10SIDL @ 0xE59;
char RXF10SIDH @ 0xE58;
char RXF9EIDL @ 0xE57;
char RXF9EIDH @ 0xE56;
char RXF9SIDL @ 0xE55;
char RXF9SIDH @ 0xE54;
char RXF8EIDL @ 0xE53;
char RXF8EIDH @ 0xE52;
char RXF8SIDL @ 0xE51;
char RXF8SIDH @ 0xE50;
char RXF7EIDL @ 0xE4F;
char RXF7EIDH @ 0xE4E;
char RXF7SIDL @ 0xE4D;
char RXF7SIDH @ 0xE4C;
char RXF6EIDL @ 0xE4B;
char RXF6EIDH @ 0xE4A;
char RXF6SIDL @ 0xE49;
char RXF6SIDH @ 0xE48;
char RXFCON1  @ 0xE47;
char RXFCON0  @ 0xE46;
char BRGCON3  @ 0xE45;
char BRGCON2  @ 0xE44;
char BRGCON1  @ 0xE43;
char TXERRCNT @ 0xE42;
char RXERRCNT @ 0xE41;

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

bit SCS0    @ OSCCON.0;
bit SCS1    @ OSCCON.1;
bit HFIOFS  @ OSCCON.2;
bit OSTS    @ OSCCON.3;
bit IDLEN   @ OSCCON.7;

bit MFIOSEL @ OSCCON2.0;
bit MFIOFS  @ OSCCON2.1;
bit SOSCGO  @ OSCCON2.3;
bit SOSCDRV @ OSCCON2.4;
bit SOSCRUN @ OSCCON2.6;

bit SWDTEN  @ WDTCON.0;
bit ULPSINK @ WDTCON.1;
bit ULPEN   @ WDTCON.2;
bit SRETEN  @ WDTCON.4;
bit ULPLVL  @ WDTCON.5;
bit REGSLP  @ WDTCON.7;

bit BOR_    @ RCON.0;
bit POR_    @ RCON.1;
bit PD      @ RCON.2;
bit TO      @ RCON.3;
bit RI_     @ RCON.4;
bit SBOREN  @ RCON.6;
bit IPEN    @ RCON.7;

bit TMR1ON  @ T1CON.0;
bit T1RD16  @ T1CON.1;
bit T1SYNC_ @ T1CON.2;
bit T1SOSCEN @ T1CON.3;
bit T1CKPS0 @ T1CON.4;
bit T1CKPS1 @ T1CON.5;
bit TMR1CS0 @ T1CON.6;
bit TMR1CS1 @ T1CON.7;

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
bit CHS4    @ ADCON0.6;

bit CHSN0   @ ADCON1.0;
bit CHSN1   @ ADCON1.1;
bit CHSN2   @ ADCON1.2;
bit VNCFG   @ ADCON1.3;
bit VCFG0   @ ADCON1.4;
bit VCFG1   @ ADCON1.5;
bit TRIGSEL0 @ ADCON1.6;
bit TRIGSEL1 @ ADCON1.7;

bit ADCS0   @ ADCON2.0;
bit ADCS1   @ ADCON2.1;
bit ADCS2   @ ADCON2.2;
bit ADFM    @ ADCON2.7;

bit P1RSEN  @ ECCP1DEL.7;

bit TX9D2   @ TXSTA2.0;
bit TRMT2   @ TXSTA2.1;
bit BRGH2   @ TXSTA2.2;
bit SENDB2  @ TXSTA2.3;
bit SYNC2   @ TXSTA2.4;
bit TXEN2   @ TXSTA2.5;
bit TX9_2   @ TXSTA2.6;
bit CSRC2   @ TXSTA2.7;

bit ABDEN2  @ BAUDCON2.0;
bit WUE2    @ BAUDCON2.1;
bit BRG16_2 @ BAUDCON2.3;
bit TXCKP2  @ BAUDCON2.4;
bit RXDTP2  @ BAUDCON2.5;
bit RCIDL2  @ BAUDCON2.6;
bit ABDOVF2 @ BAUDCON2.7;

bit CCP3IP  @ IPR4.0;
bit CCP4IP  @ IPR4.1;
bit CCP5IP  @ IPR4.2;
bit CMP1IP  @ IPR4.4;
bit CMP2IP  @ IPR4.5;
bit EEIP    @ IPR4.6;
bit TMR4IP  @ IPR4.7;

bit CCP3IF  @ PIR4.0;
bit CCP4IF  @ PIR4.1;
bit CCP5IF  @ PIR4.2;
bit CMP1IF  @ PIR4.4;
bit CMP2IF  @ PIR4.5;
bit EEIF    @ PIR4.6;
bit TMR4IF  @ PIR4.7;

bit CCP3IE  @ PIE4.0;
bit CCP4IE  @ PIE4.1;
bit CCP5IE  @ PIE4.2;
bit CMP1IE  @ PIE4.4;
bit CMP2IE  @ PIE4.5;
bit EEIE    @ PIE4.6;
bit TMR4IE  @ PIE4.7;

bit CVRSS   @ CVRCON.5;
bit CVROE   @ CVRCON.6;
bit CVREN   @ CVRCON.7;

bit CMP1OUT @ CMSTAT.6;
bit CMP2OUT @ CMSTAT.7;

bit TMR3ON  @ T3CON.0;
bit T3RD16  @ T3CON.1;
bit T3SYNC_ @ T3CON.2;
bit SOSCEN  @ T3CON.3;
bit T3CKPS0 @ T3CON.4;
bit T3CKPS1 @ T3CON.5;
bit TMR3CS0 @ T3CON.6;
bit TMR3CS1 @ T3CON.7;

bit T3GSS0  @ T3GCON.0;
bit T3GSS1  @ T3GCON.1;
bit T3GVAL  @ T3GCON.2;
bit T3GGO   @ T3GCON.3;
bit T3GSPM  @ T3GCON.4;
bit T3GTM   @ T3GCON.5;
bit T3GPOL  @ T3GCON.6;
bit TMR3GE  @ T3GCON.7;

bit TX9D1   @ TXSTA1.0;
bit TRMT1   @ TXSTA1.1;
bit BRGH1   @ TXSTA1.2;
bit SENDB1  @ TXSTA1.3;
bit SYNC1   @ TXSTA1.4;
bit TXEN1   @ TXSTA1.5;
bit TX9_1   @ TXSTA1.6;
bit CSRC1   @ TXSTA1.7;

bit RX9D1   @ RCSTA1.0;
bit OERR1   @ RCSTA1.1;
bit FERR1   @ RCSTA1.2;
bit ADDEN1  @ RCSTA1.3;
bit CREN1   @ RCSTA1.4;
bit SREN1   @ RCSTA1.5;
bit RX9_1   @ RCSTA1.6;
bit SPEN1   @ RCSTA1.7;

bit T1GSS0  @ T1GCON.0;
bit T1GSS1  @ T1GCON.1;
bit T1GVAL  @ T1GCON.2;
bit T1GGO   @ T1GCON.3;
bit T1GSPM  @ T1GCON.4;
bit T1GTM   @ T1GCON.5;
bit T1GPOL  @ T1GCON.6;
bit TMR1GE  @ T1GCON.7;

bit HLVDEN  @ HLVDCON.4;
bit IRVST   @ HLVDCON.5;
bit BGVST   @ HLVDCON.6;
bit VDIRMAG @ HLVDCON.7;

bit ABDEN1  @ BAUDCON1.0;
bit WUE1    @ BAUDCON1.1;
bit BRG16_1 @ BAUDCON1.3;
bit TXCKP1  @ BAUDCON1.4;
bit RXDTP1  @ BAUDCON1.5;
bit RCIDL1  @ BAUDCON1.6;
bit ABDOVF1 @ BAUDCON1.7;

bit RX9D2   @ RCSTA2.0;
bit OERR2   @ RCSTA2.1;
bit FERR2   @ RCSTA2.2;
bit ADDEN2  @ RCSTA2.3;
bit CREN2   @ RCSTA2.4;
bit SREN2   @ RCSTA2.5;
bit RC9_2   @ RCSTA2.6;
bit SPEN2   @ RCSTA2.7;

bit CCP1IP  @ IPR3.1;
bit CCP2IP  @ IPR3.2;
bit CTMUIP  @ IPR3.3;
bit TX2IP   @ IPR3.4;
bit RC2IP   @ IPR3.5;

bit CCP1IF  @ PIR3.1;
bit CCP2IF  @ PIR3.2;
bit CTMUIF  @ PIR3.3;
bit TX2IF   @ PIR3.4;
bit RC2IF   @ PIR3.5;

bit CCP1IE  @ PIE3.1;
bit CCP2IE  @ PIE3.2;
bit CTMUIE  @ PIE3.3;
bit TX2IE   @ PIE3.4;
bit RC2IE   @ PIE3.5;

bit TMR3GIP @ IPR2.0;
bit TMR3IP  @ IPR2.1;
bit HLVDIP  @ IPR2.2;
bit BCLIP   @ IPR2.3;
bit OSCFIP  @ IPR2.7;

bit TMR3GIF @ PIR2.0;
bit TMR3IF  @ PIR2.1;
bit HLVDIF  @ PIR2.2;
bit BCLIF   @ PIR2.3;
bit OSCFIF  @ PIR2.7;

bit TMR3GIE @ PIE2.0;
bit TMR3IE  @ PIE2.1;
bit HLVDIE  @ PIE2.2;
bit BCLIE   @ PIE2.3;
bit OSCFIE  @ PIE2.7;

bit TMR1IP  @ IPR1.0;
bit TMR2IP  @ IPR1.1;
bit TMR1GIP @ IPR1.2;
bit SSPIP   @ IPR1.3;
bit TX1IP   @ IPR1.4;
bit RC1IP   @ IPR1.5;
bit ADIP    @ IPR1.6;
bit PSPIP   @ IPR1.7;

bit TMR1IF  @ PIR1.0;
bit TMR2IF  @ PIR1.1;
bit TMR1GIF @ PIR1.2;
bit SSPIF   @ PIR1.3;
bit TX1IF   @ PIR1.4;
bit RC1IF   @ PIR1.5;
bit ADIF    @ PIR1.6;
bit PSPIF   @ PIR1.7;

bit TMR1IE  @ PIE1.0;
bit TMR2IE  @ PIE1.1;
bit TMR1GIE @ PIE1.2;
bit SSPIE   @ PIE1.3;
bit TX1IE   @ PIE1.4;
bit RC1IE   @ PIE1.5;
bit ADIE    @ PIE1.6;
bit PSPIE   @ PIE1.7;

bit PLLEN   @ OSCTUNE.6;
bit INTSRC  @ OSCTUNE.7;

bit RODIV0  @ REFOCON.0;
bit RODIV1  @ REFOCON.1;
bit RODIV2  @ REFOCON.2;
bit RODIV3  @ REFOCON.3;
bit ROSEL   @ REFOCON.4;
bit ROSSLP  @ REFOCON.5;
bit ROON    @ REFOCON.7;

bit U1OD    @ ODCON.0;
bit U2OD    @ ODCON.1;
bit CCP1OD  @ ODCON.2;
bit CCP2OD  @ ODCON.3;
bit CCP3OD  @ ODCON.4;
bit CCP4OD  @ ODCON.5;
bit CCP5OD  @ ODCON.6;
bit SSPOD   @ ODCON.7;

bit SLRA    @ SLRCON.0;
bit SLRB    @ SLRCON.1;
bit SLRC    @ SLRCON.2;
bit SLRD    @ SLRCON.3;
bit SLRE    @ SLRCON.4;
bit SLRF    @ SLRCON.5;
bit SLRG    @ SLRCON.6;

bit T4CKPS0 @ T4CON.0;
bit T4CKPS1 @ T4CON.1;
bit TMR4ON  @ T4CON.2;

bit RD      @ EECON1.0;
bit WR      @ EECON1.1;
bit WREN    @ EECON1.2;
bit WRERR   @ EECON1.3;
bit FREE    @ EECON1.4;
bit CFGS    @ EECON1.6;
bit EEPGD   @ EECON1.7;

bit RXB0IP  @ IPR5.0;
bit RXB1IP  @ IPR5.1;
bit TXB0IP  @ IPR5.2;
bit TXB1IP  @ IPR5.3;
bit TXB2IP  @ IPR5.4;
bit ERRIP   @ IPR5.5;
bit WAKIP   @ IPR5.6;
bit IRXIP   @ IPR5.7;

bit RXB0IF  @ PIR5.0;
bit RXB1IF  @ PIR5.1;
bit TXB0IF  @ PIR5.2;
bit TXB1IF  @ PIR5.3;
bit TXB2IF  @ PIR5.4;
bit ERRIF   @ PIR5.5;
bit WAKIF   @ PIR5.6;
bit IRXIF   @ PIR5.7;

bit RXB0IE  @ PIE5.0;
bit RXB1IE  @ PIE5.1;
bit TXB0IE  @ PIE5.2;
bit TXB1IE  @ PIE5.3;
bit TXB2IE  @ PIE5.4;
bit ERRIE   @ PIE5.5;
bit WAKIE   @ PIE5.6;
bit IRXIE   @ PIE5.7;

bit EWARN   @ COMSTAT.0;
bit RXWARN  @ COMSTAT.1;
bit TXWARN  @ COMSTAT.2;
bit RXBP    @ COMSTAT.3;
bit TXBP    @ COMSTAT.4;
bit TXBO    @ COMSTAT.5;
bit RXB1OVFL @ COMSTAT.6;
bit RXB0OVFL @ COMSTAT.7;

bit CLKSEL  @ CIOCON.0;
bit CANCAP  @ CIOCON.4;
bit ENDRHI  @ CIOCON.5;
bit TX2EN   @ CIOCON.6;
bit TX2SRC  @ CIOCON.7;

bit SSPMD   @ PMD0.0;
bit UART1MD @ PMD0.1;
bit UART2MD @ PMD0.2;
bit CCP1MD  @ PMD0.3;
bit CCP2MD  @ PMD0.4;
bit CCP3MD  @ PMD0.5;
bit CCP4MD  @ PMD0.6;
bit CCP5MD  @ PMD0.7;

bit TMR0MD  @ PMD1.0;
bit TMR1MD  @ PMD1.1;
bit TMR2MD  @ PMD1.2;
bit TMR3MD  @ PMD1.3;
bit TMR4MD  @ PMD1.4;
bit ADCMD   @ PMD1.5;
bit CTMUMD  @ PMD1.6;
bit PSPMD   @ PMD1.7;

bit CMP1MD  @ PMD2.0;
bit CMP2MD  @ PMD2.1;
bit ECANMD  @ PMD2.2;
bit MODMD   @ PMD2.3;

bit CTMUDS  @ PADCFG1.0;
bit RGPU    @ PADCFG1.4;
bit RFPU    @ PADCFG1.5;
bit REPU    @ PADCFG1.6;
bit RDPU    @ PADCFG1.7;

bit CTTRIG  @ CTMUCONH.0;
bit IDISSEN @ CTMUCONH.1;
bit EDGSEQEN @ CTMUCONH.2;
bit EDGEN   @ CTMUCONH.3;
bit TGEN    @ CTMUCONH.4;
bit CTMUSIDL @ CTMUCONH.5;
bit CTMUEN  @ CTMUCONH.7;

bit PSPMODE @ PSPCON.4;
bit IBOV    @ PSPCON.5;
bit OBF     @ PSPCON.6;
bit IBF     @ PSPCON.7;

bit MDBIT   @ MDCON.0;
bit MDO     @ MDCON.3;
bit MDOPOL  @ MDCON.4;
bit MDSLR   @ MDCON.5;
bit MDOE    @ MDCON.6;
bit MDEN    @ MDCON.7;

bit MDSODIS @ MDSRC.7;

bit B0TXEN  @ BSEL0.2;
bit B1TXEN  @ BSEL0.3;
bit B2TXEN  @ BSEL0.4;
bit B3TXEN  @ BSEL0.5;
bit B4TXEN  @ BSEL0.6;
bit B5TXEN  @ BSEL0.7;

bit WAKFIL  @ BRGCON3.6;
bit WAKDIS  @ BRGCON3.7;
