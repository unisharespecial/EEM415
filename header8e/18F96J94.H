// Header file
#pragma chip PIC18F96J94, core 16, code 32768, ram 0 : 0xDF9

#ifdef ICD2_DEBUG
 #message ICD2 reservations are not defined!
#endif

// Extended Instruction Set

#pragma accessGPR 0x60

#pragma configMapCodeSpace 0x7FF8
#pragma userIDlocations  -

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
char TMR0     @ 0xFD6;
char T0CON    @ 0xFD5;

char OSCCON   @ 0xFD3;
char IPR5     @ 0xFD2;
char IOCF     @ 0xFD1;
char RCON     @ 0xFD0;
char TMR1H    @ 0xFCF;
char TMR1L    @ 0xFCE;
char T1CON    @ 0xFCD;
char TMR2     @ 0xFCC;
char PR2      @ 0xFCB;
char T2CON    @ 0xFCA;
char SSP1BUF  @ 0xFC9;
char SSP1ADD  @ 0xFC8;
char SSP1STAT @ 0xFC7;
char SSP1CON1 @ 0xFC6;
char SSP1CON2 @ 0xFC5;
char CMSTAT   @ 0xFC4;
char ADCBUF0H @ 0xFC3;
char ADCBUF0L @ 0xFC2;
char ADCON1H  @ 0xFC1;
char ADCON1L  @ 0xFC0;
char CVRCONH  @ 0xFBF;
char CVRCONL  @ 0xFBE;
char ECCP1AS  @ 0xFBD;
char ECCP1DEL @ 0xFBC;
char CCPR1H   @ 0xFBB;
char CCPR1L   @ 0xFBA;
char CCP1CON  @ 0xFB9;
char PIR5     @ 0xFB8;
char PIE5     @ 0xFB7;
char IPR4     @ 0xFB6;
char PIR4     @ 0xFB5;
char PIE4     @ 0xFB4;
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
char IPR6     @ 0xFA9;
char HLVDCON  @ 0xFA8;
char PSPCON   @ 0xFA7;
char PIR6     @ 0xFA6;
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
char TRISJ    @ 0xF9A;
char TRISH    @ 0xF99;
char TRISG    @ 0xF98;
char TRISF    @ 0xF97;
char TRISE    @ 0xF96;
char TRISD    @ 0xF95;
char TRISC    @ 0xF94;
char TRISB    @ 0xF93;
char TRISA    @ 0xF92;
char LATJ     @ 0xF91;
char LATH     @ 0xF90;
char LATG     @ 0xF8F;
char LATF     @ 0xF8E;
char LATE     @ 0xF8D;
char LATD     @ 0xF8C;
char LATC     @ 0xF8B;
char LATB     @ 0xF8A;
char LATA     @ 0xF89;
char PORTJ    @ 0xF88;
char PORTH    @ 0xF87;
char PORTG    @ 0xF86;
char PORTF    @ 0xF85;
char PORTE    @ 0xF84;
char PORTD    @ 0xF83;
char PORTC    @ 0xF82;
char PORTB    @ 0xF81;
char PORTA    @ 0xF80;
char EECON1   @ 0xF7F;
char EECON2   @ 0xF7E;
char RCON2    @ 0xF7D;
char RCON3    @ 0xF7C;
char RCON4    @ 0xF7B;
char UFRML    @ 0xF7A;
char UFRMH    @ 0xF79;
char UIR      @ 0xF78;
char UEIR     @ 0xF77;
char USTAT    @ 0xF76;
char UCON     @ 0xF75;
char UADDR    @ 0xF74;
char TRISVP   @ 0xF73;
char LATVP    @ 0xF72;
char PORTVP   @ 0xF71;
char TXADDRL  @ 0xF70;
char TXADDRH  @ 0xF6F;
char RXADDRL  @ 0xF6E;
char RXADDRH  @ 0xF6D;
char DMABCL   @ 0xF6C;
char DMABCH   @ 0xF6B;
char TXBUF    @ 0xF6A;
char SSP1CON3 @ 0xF69;
char SSP1MSK  @ 0xF68;
char BAUDCON1 @ 0xF67;
char OSCCON2  @ 0xF66;
char OSCCON3  @ 0xF65;
char OSCCON4  @ 0xF64;
char ACTCON   @ 0xF63;
char WPUB     @ 0xF62;
char PIE6     @ 0xF61;
char DMACON1  @ 0xF60;
char RTCCON1  @ 0xF5F;
char RTCCAL   @ 0xF5E;
char RTCVALH  @ 0xF5D;
char RTCVALL  @ 0xF5C;
char ALRMCFG  @ 0xF5B;
char ALRMRPT  @ 0xF5A;
char ALRMVALH @ 0xF59;
char ALRMVALL @ 0xF58;
char RTCCON2  @ 0xF57;
char IOCP     @ 0xF56;
char IOCN     @ 0xF55;
char PADCFG1  @ 0xF54;
char CM1CON   @ 0xF53;
char ECCP2AS  @ 0xF52;
char ECCP2DEL @ 0xF51;
char CCPR2H   @ 0xF50;
char CCPR2L   @ 0xF4F;
char CCP2CON  @ 0xF4E;
char ECCP3AS  @ 0xF4D;
char ECCP3DEL @ 0xF4C;
char CCPR3H   @ 0xF4B;
char CCPR3L   @ 0xF4A;
char CCP3CON  @ 0xF49;
char CCPR8H   @ 0xF48;
char CCPR8L   @ 0xF47;
char CCP8CON  @ 0xF46;
char CCPR9H   @ 0xF45;
char CCPR9L   @ 0xF44;
char CCP9CON  @ 0xF43;
char CCPR10H  @ 0xF42;
char CCPR10L  @ 0xF41;
char CCP10CON @ 0xF40;
char TMR6     @ 0xF3F;
char PR6      @ 0xF3E;
char T6CON    @ 0xF3D;
char TMR8     @ 0xF3C;
char PR8      @ 0xF3B;
char T8CON    @ 0xF3A;
char SSP2CON3 @ 0xF39;
char CM2CON   @ 0xF38;
char CM3CON   @ 0xF37;
char CCPTMRS0 @ 0xF36;
char CCPTMRS1 @ 0xF35;
char CCPTMRS2 @ 0xF34;
char RCSTA2   @ 0xF33;
char TXSTA2   @ 0xF32;
char BAUDCON2 @ 0xF31;
char SPBRGH1  @ 0xF30;
char RCSTA3   @ 0xF2F;
char TXSTA3   @ 0xF2E;
char BAUDCON3 @ 0xF2D;
char SPBRGH3  @ 0xF2C;
char SPBRG3   @ 0xF2B;
char RCREG3   @ 0xF2A;
char TXREG3   @ 0xF29;
char DSCONL   @ 0xF28;
char DSCONH   @ 0xF27;
char DSWAKEL  @ 0xF26;
char DSWAKEH  @ 0xF25;
char DSGPR0   @ 0xF24;
char DSGPR1   @ 0xF23;
char DSGPR2   @ 0xF22;
char DSGPR3   @ 0xF21;
char SPBRGH2  @ 0xF20;
char SPBRG2   @ 0xF1F;
char RCREG2   @ 0xF1E;
char TXREG2   @ 0xF1D;
char PSTR2CON @ 0xF1C;
char PSTR3CON @ 0xF1B;
char SSP2STAT @ 0xF1A;
char SSP2CON1 @ 0xF19;
char SSP2CON2 @ 0xF18;
char SSP2MSK  @ 0xF17;
char TMR5H    @ 0xF16;
char TMR5L    @ 0xF15;
char T5CON    @ 0xF14;
char T5GCON   @ 0xF13;
char CCPR4H   @ 0xF12;
char CCPR4L   @ 0xF11;
char CCP4CON  @ 0xF10;
char CCPR5H   @ 0xF0F;
char CCPR5L   @ 0xF0E;
char CCP5CON  @ 0xF0D;
char CCPR6H   @ 0xF0C;
char CCPR6L   @ 0xF0B;
char CCP6CON  @ 0xF0A;
char CCPR7H   @ 0xF09;
char CCPR7L   @ 0xF08;
char CCP7CON  @ 0xF07;
char TMR4     @ 0xF06;
char PR4      @ 0xF05;
char T4CON    @ 0xF04;
char SSP2BUF  @ 0xF03;
char SSP2ADD  @ 0xF02;
char ANCFG    @ 0xF01;
char DMACON2  @ 0xF00;
char RCSTA4   @ 0xEFF;
char TXSTA4   @ 0xEFE;
char BAUDCON4 @ 0xEFD;
char SPBRGH4  @ 0xEFC;
char SPBRG4   @ 0xEFB;
char RCREG4   @ 0xEFA;
char TXREG4   @ 0xEF9;
char CTMUCON1 @ 0xEF8;
char CTMUCON2 @ 0xEF7;
char CTMUCON3 @ 0xEF6;
char CTMUCON4 @ 0xEF5;
char PMD0     @ 0xEF4;
char PMD1     @ 0xEF3;
char PMD2     @ 0xEF2;
char PMD3     @ 0xEF1;
char PMD4     @ 0xEF0;
char MDCON    @ 0xEEF;
char MDSRC    @ 0xEEE;
char MDCARH   @ 0xEED;
char MDCARL   @ 0xEEC;
char ODCON1   @ 0xEEB;
char ODCON2   @ 0xEEA;
char TRISK    @ 0xEE9;
char LATK     @ 0xEE8;
char PORTK    @ 0xEE7;
char TRISL    @ 0xEE6;
char LATL     @ 0xEE5;
char PORTL    @ 0xEE4;
char MEMCON   @ 0xEE3;
char REFO1CON @ 0xEE2;
char REFO1CON1 @ 0xEE1;
char REFO1CON2 @ 0xEE0;
char REFO1CON3 @ 0xEDF;
char REFO2CON @ 0xEDE;
char REFO2CON1 @ 0xEDD;
char REFO2CON2 @ 0xEDC;
char REFO2CON3 @ 0xEDB;
char LCDPS    @ 0xEDA;
char LCDCON   @ 0xED9;
char LCDREG   @ 0xED8;
char LCDREF   @ 0xED7;
char LCDRL    @ 0xED6;
char LCDSE7   @ 0xED5;
char LCDSE6   @ 0xED4;
char LCDSE5   @ 0xED3;
char LCDSE4   @ 0xED2;
char LCDSE3   @ 0xED1;
char LCDSE2   @ 0xED0;
char LCDSE1   @ 0xECF;
char LCDSE0   @ 0xECE;
char LCDDATA63 @ 0xECD;
char LCDDATA62 @ 0xECC;
char LCDDATA61 @ 0xECB;
char LCDDATA60 @ 0xECA;
char LCDDATA59 @ 0xEC9;
char LCDDATA58 @ 0xEC8;
char LCDDATA57 @ 0xEC7;
char LCDDATA56 @ 0xEC6;
char LCDDATA55 @ 0xEC5;
char LCDDATA54 @ 0xEC4;
char LCDDATA53 @ 0xEC3;
char LCDDATA52 @ 0xEC2;
char LCDDATA51 @ 0xEC1;
char LCDDATA50 @ 0xEC0;
char LCDDATA49 @ 0xEBF;
char LCDDATA48 @ 0xEBE;
char LCDDATA47 @ 0xEBD;
char LCDDATA46 @ 0xEBC;
char LCDDATA45 @ 0xEBB;
char LCDDATA44 @ 0xEBA;
char LCDDATA43 @ 0xEB9;
char LCDDATA42 @ 0xEB8;
char LCDDATA41 @ 0xEB7;
char LCDDATA40 @ 0xEB6;
char LCDDATA39 @ 0xEB5;
char LCDDATA38 @ 0xEB4;
char LCDDATA37 @ 0xEB3;
char LCDDATA36 @ 0xEB2;
char LCDDATA35 @ 0xEB1;
char LCDDATA34 @ 0xEB0;
char LCDDATA33 @ 0xEAF;
char LCDDATA32 @ 0xEAE;
char LCDDATA31 @ 0xEAD;
char LCDDATA30 @ 0xEAC;
char LCDDATA29 @ 0xEAB;
char LCDDATA28 @ 0xEAA;
char LCDDATA27 @ 0xEA9;
char LCDDATA26 @ 0xEA8;
char LCDDATA25 @ 0xEA7;
char LCDDATA24 @ 0xEA6;
char LCDDATA23 @ 0xEA5;
char LCDDATA22 @ 0xEA4;
char LCDDATA21 @ 0xEA3;
char LCDDATA20 @ 0xEA2;
char LCDDATA19 @ 0xEA1;
char LCDDATA18 @ 0xEA0;
char LCDDATA17 @ 0xE9F;
char LCDDATA16 @ 0xE9E;
char LCDDATA15 @ 0xE9D;
char LCDDATA14 @ 0xE9C;
char LCDDATA13 @ 0xE9B;
char LCDDATA12 @ 0xE9A;
char LCDDATA11 @ 0xE99;
char LCDDATA10 @ 0xE98;
char LCDDATA9 @ 0xE97;
char LCDDATA8 @ 0xE96;
char LCDDATA7 @ 0xE95;
char LCDDATA6 @ 0xE94;
char LCDDATA5 @ 0xE93;
char LCDDATA4 @ 0xE92;
char LCDDATA3 @ 0xE91;
char LCDDATA2 @ 0xE90;
char LCDDATA1 @ 0xE8F;
char LCDDATA0 @ 0xE8E;
char ADCON2H  @ 0xE8D;
char ADCON2L  @ 0xE8C;
char ADCON3H  @ 0xE8B;
char ADCON3L  @ 0xE8A;
char ADCON5H  @ 0xE89;
char ADCON5L  @ 0xE88;
char ADCHS0H  @ 0xE87;
char ADCHS0L  @ 0xE86;
char ADCSS1H  @ 0xE85;
char ADCSS1L  @ 0xE84;
char ADCSS0H  @ 0xE83;
char ADCSS0L  @ 0xE82;
char ADCHIT1H @ 0xE81;
char ADCHIT1L @ 0xE80;
char ADCHIT0H @ 0xE7F;
char ADCHIT0L @ 0xE7E;
char ADCTMUEN1H @ 0xE7D;
char ADCTMUEN1L @ 0xE7C;
char ADCTMUEN0H @ 0xE7B;
char ADCTMUEN0L @ 0xE7A;
char ADCBUF25H @ 0xE79;
char ADCBUF25L @ 0xE78;
char ADCBUF24H @ 0xE77;
char ADCBUF24L @ 0xE76;
char ADCBUF23H @ 0xE75;
char ADCBUF23L @ 0xE74;
char ADCBUF22H @ 0xE73;
char ADCBUF22L @ 0xE72;
char ADCBUF21H @ 0xE71;
char ADCBUF21L @ 0xE70;
char ADCBUF20H @ 0xE6F;
char ADCBUF20L @ 0xE6E;
char ADCBUF19H @ 0xE6D;
char ADCBUF19L @ 0xE6C;
char ADCBUF18H @ 0xE6B;
char ADCBUF18L @ 0xE6A;
char ADCBUF17H @ 0xE69;
char ADCBUF17L @ 0xE68;
char ADCBUF16H @ 0xE67;
char ADCBUF16L @ 0xE66;
char ADCBUF15H @ 0xE65;
char ADCBUF15L @ 0xE64;
char ADCBUF14H @ 0xE63;
char ADCBUF14L @ 0xE62;
char ADCBUF13H @ 0xE61;
char ADCBUF13L @ 0xE60;
char ADCBUF12H @ 0xE5F;
char ADCBUF12L @ 0xE5E;
char ADCBUF11H @ 0xE5D;
char ADCBUF11L @ 0xE5C;
char ADCBUF10H @ 0xE5B;
char ADCBUF10L @ 0xE5A;
char ADCBUF9H @ 0xE59;
char ADCBUF9L @ 0xE58;
char ADCBUF8H @ 0xE57;
char ADCBUF8L @ 0xE56;
char ADCBUF7H @ 0xE55;
char ADCBUF7L @ 0xE54;
char ADCBUF6H @ 0xE53;
char ADCBUF6L @ 0xE52;
char ADCBUF5H @ 0xE51;
char ADCBUF5L @ 0xE50;
char ADCBUF4H @ 0xE4F;
char ADCBUF4L @ 0xE4E;
char ADCBUF3H @ 0xE4D;
char ADCBUF3L @ 0xE4C;
char ADCBUF2H @ 0xE4B;
char ADCBUF2L @ 0xE4A;
char ADCBUF1H @ 0xE49;
char ADCBUF1L @ 0xE48;
char ANCON1   @ 0xE47;
char ANCON2   @ 0xE46;
char ANCON3   @ 0xE45;
char RPINR52_53 @ 0xE44;
char RPINR50_51 @ 0xE43;
char RPINR48_49 @ 0xE42;
char RPINR46_47 @ 0xE41;
char RPINR44_45 @ 0xE40;
char RPINR42_43 @ 0xE3F;
char RPINR40_41 @ 0xE3E;
char RPINR38_39 @ 0xE3D;
char RPINR36_37 @ 0xE3C;
char RPINR34_35 @ 0xE3B;
char RPINR32_33 @ 0xE3A;
char RPINR30_31 @ 0xE39;
char RPINR28_29 @ 0xE38;
char RPINR26_27 @ 0xE37;
char RPINR24_25 @ 0xE36;
char RPINR22_23 @ 0xE35;
char RPINR20_21 @ 0xE34;
char RPINR18_19 @ 0xE33;
char RPINR16_17 @ 0xE32;
char RPINR14_15 @ 0xE31;
char RPINR12_13 @ 0xE30;
char RPINR10_11 @ 0xE2F;
char RPINR8_9 @ 0xE2E;
char RPINR6_7 @ 0xE2D;
char RPINR4_5 @ 0xE2C;
char RPINR2_3 @ 0xE2B;
char RPINR0_1 @ 0xE2A;
char RPOR46   @ 0xE29;
char RPOR44_45 @ 0xE28;
char RPOR42_43 @ 0xE27;
char RPOR40_41 @ 0xE26;
char RPOR38_39 @ 0xE25;
char RPOR36_37 @ 0xE24;
char RPOR34_35 @ 0xE23;
char RPOR32_33 @ 0xE22;
char RPOR30_31 @ 0xE21;
char RPOR28_29 @ 0xE20;
char RPOR26_27 @ 0xE1F;
char RPOR24_25 @ 0xE1E;
char RPOR22_23 @ 0xE1D;
char RPOR20_21 @ 0xE1C;
char RPOR18_19 @ 0xE1B;
char RPOR16_17 @ 0xE1A;
char RPOR14_15 @ 0xE19;
char RPOR12_13 @ 0xE18;
char RPOR10_11 @ 0xE17;
char RPOR8_9  @ 0xE16;
char RPOR6_7  @ 0xE15;
char RPOR4_5  @ 0xE14;
char RPOR2_3  @ 0xE13;
char RPOR0_1  @ 0xE12;
char UCFG     @ 0xE11;
char UIE      @ 0xE10;
char UEIE     @ 0xE0F;
char UEP15    @ 0xE0E;
char UEP14    @ 0xE0D;
char UEP13    @ 0xE0C;
char UEP12    @ 0xE0B;
char UEP11    @ 0xE0A;
char UEP10    @ 0xE09;
char UEP9     @ 0xE08;
char UEP8     @ 0xE07;
char UEP7     @ 0xE06;
char UEP6     @ 0xE05;
char UEP5     @ 0xE04;
char UEP4     @ 0xE03;
char UEP3     @ 0xE02;
char UEP2     @ 0xE01;
char UEP1     @ 0xE00;
char UEP0     @ 0xDFF;

bit IOCIF   @ INTCON.0;
bit INT0IF  @ INTCON.1;
bit TMR0IF  @ INTCON.2;
bit IOCIE   @ INTCON.3;
bit INT0IE  @ INTCON.4;
bit TMR0IE  @ INTCON.5;
bit PEIE    @ INTCON.6;
bit GIEL    @ INTCON.6;
bit GIE     @ INTCON.7;
bit GIEH    @ INTCON.7;

bit IOCIP   @ INTCON2.0;
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
bit T0CS0   @ T0CON.4;
bit T0CS1   @ T0CON.5;
bit T08BIT  @ T0CON.6;
bit TMR0ON  @ T0CON.7;

bit NOSC0   @ OSCCON.0;
bit NOSC1   @ OSCCON.1;
bit NOSC2   @ OSCCON.2;
bit COSC0   @ OSCCON.4;
bit COSC1   @ OSCCON.5;
bit COSC2   @ OSCCON.6;
bit IDLEN   @ OSCCON.7;

bit TMR4IP  @ IPR5.0;
bit TMR5IP  @ IPR5.1;
bit TMR6IP  @ IPR5.2;
bit TMR8IP  @ IPR5.4;
bit ACTLOCKIP @ IPR5.5;
bit ACTORSIP @ IPR5.6;

bit BOR_    @ RCON.0;
bit POR_    @ RCON.1;
bit PD      @ RCON.2;
bit TO      @ RCON.3;
bit RI_     @ RCON.4;
bit CM_     @ RCON.5;
bit IPEN    @ RCON.7;

bit TMR1ON  @ T1CON.0;
bit RD16    @ T1CON.1;
bit T1SYNC_ @ T1CON.2;
bit SOSCEN  @ T1CON.3;
bit T1CKPS0 @ T1CON.4;
bit T1CKPS1 @ T1CON.5;
bit TMR1CS0 @ T1CON.6;
bit TMR1CS1 @ T1CON.7;

bit T2CKPS0 @ T2CON.0;
bit T2CKPS1 @ T2CON.1;
bit TMR2ON  @ T2CON.2;

bit BF      @ SSP1STAT.0;
bit UA      @ SSP1STAT.1;
bit RW_     @ SSP1STAT.2;
bit S       @ SSP1STAT.3;
bit P       @ SSP1STAT.4;
bit DA_     @ SSP1STAT.5;
bit CKE     @ SSP1STAT.6;
bit SMP     @ SSP1STAT.7;

bit CKP     @ SSP1CON1.4;
bit SSPEN   @ SSP1CON1.5;
bit SSPOV   @ SSP1CON1.6;
bit WCOL    @ SSP1CON1.7;

bit SEN     @ SSP1CON2.0;
bit RSEN    @ SSP1CON2.1;
bit PEN     @ SSP1CON2.2;
bit RCEN    @ SSP1CON2.3;
bit ACKEN   @ SSP1CON2.4;
bit ACKDT   @ SSP1CON2.5;
bit ACKSTAT @ SSP1CON2.6;
bit GCEN    @ SSP1CON2.7;

bit C1OUT   @ CMSTAT.0;
bit C2OUT   @ CMSTAT.1;
bit C3OUT   @ CMSTAT.2;

bit FORM0   @ ADCON1H.0;
bit FORM1   @ ADCON1H.1;
bit MODE12  @ ADCON1H.2;
bit ADON    @ ADCON1H.7;

bit DONE    @ ADCON1L.0;
bit SAMP    @ ADCON1L.1;
bit ASAM    @ ADCON1L.2;
bit SSRC0   @ ADCON1L.4;
bit SSRC1   @ ADCON1L.5;
bit SSRC2   @ ADCON1L.6;
bit SSRC3   @ ADCON1L.7;

bit CVRNSS  @ CVRCONL.0;
bit CVRPSS0 @ CVRCONL.4;
bit CVRPSS1 @ CVRCONL.5;
bit CVROE   @ CVRCONL.6;
bit CVREN   @ CVRCONL.7;

bit PSS1BD0 @ ECCP1AS.0;
bit PSS1BD1 @ ECCP1AS.1;
bit PSS1AC0 @ ECCP1AS.2;
bit PSS1AC1 @ ECCP1AS.3;
bit ECCP1AS0 @ ECCP1AS.4;
bit ECCP1AS1 @ ECCP1AS.5;
bit ECCP1AS2 @ ECCP1AS.6;
bit ECCP1ASE @ ECCP1AS.7;

bit P1RSEN  @ ECCP1DEL.7;

bit CCP1Y   @ CCP1CON.4;
bit CCP1X   @ CCP1CON.5;
bit P1M0    @ CCP1CON.6;
bit P1M1    @ CCP1CON.7;

bit TMR4IF  @ PIR5.0;
bit TMR5IF  @ PIR5.1;
bit TMR6IF  @ PIR5.2;
bit TMR8IF  @ PIR5.4;
bit ACTLOCKIF @ PIR5.5;
bit ACTORSIF @ PIR5.6;

bit TMR4IE  @ PIE5.0;
bit TMR5IE  @ PIE5.1;
bit TMR6IE  @ PIE5.2;
bit TMR8IE  @ PIE5.4;
bit ACTLOCKIE @ PIE5.5;
bit ACTORSIE @ PIE5.6;

bit ECCP3IP @ IPR4.0;
bit CCP4IP  @ IPR4.1;
bit CCP5IP  @ IPR4.2;
bit CCP6IP  @ IPR4.3;
bit CCP7IP  @ IPR4.4;
bit CCP8IP  @ IPR4.5;
bit CCP9IP  @ IPR4.6;
bit CCP10IP @ IPR4.7;

bit ECCP3IF @ PIR4.0;
bit CCP4IF  @ PIR4.1;
bit CCP5IF  @ PIR4.2;
bit CCP6IF  @ PIR4.3;
bit CCP7IF  @ PIR4.4;
bit CCP8IF  @ PIR4.5;
bit CCP9IF  @ PIR4.6;
bit CCP10IF @ PIR4.7;

bit ECCP3IE @ PIE4.0;
bit CCP4IE  @ PIE4.1;
bit CCP5IE  @ PIE4.2;
bit CCP6IE  @ PIE4.3;
bit CCP7IE  @ PIE4.4;
bit CCP8IE  @ PIE4.5;
bit CCP9IE  @ PIE4.6;
bit CCP10IE @ PIE4.7;

bit TMR3ON  @ T3CON.0;
bit T3RD16  @ T3CON.1;
bit T3SYNC_ @ T3CON.2;
bit T3SOSCEN @ T3CON.3;
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

bit TX9D    @ TXSTA1.0;
bit TRMT    @ TXSTA1.1;
bit BRGH    @ TXSTA1.2;
bit SENDB   @ TXSTA1.3;
bit SYNC    @ TXSTA1.4;
bit TXEN    @ TXSTA1.5;
bit TX9     @ TXSTA1.6;
bit CSRC    @ TXSTA1.7;

bit RX9D    @ RCSTA1.0;
bit OERR    @ RCSTA1.1;
bit FERR    @ RCSTA1.2;
bit ADDEN   @ RCSTA1.3;
bit CREN    @ RCSTA1.4;
bit SREN    @ RCSTA1.5;
bit RX9     @ RCSTA1.6;
bit SPEN    @ RCSTA1.7;

bit T1GSS0  @ T1GCON.0;
bit T1GSS1  @ T1GCON.1;
bit T1GVAL  @ T1GCON.2;
bit T1GGO   @ T1GCON.3;
bit T1GSPM  @ T1GCON.4;
bit T1GTM   @ T1GCON.5;
bit T1GPOL  @ T1GCON.6;
bit TMR1GE  @ T1GCON.7;

bit CMP1IP  @ IPR6.0;
bit CMP2IP  @ IPR6.1;
bit CMP3IP  @ IPR6.2;
bit TX3IP   @ IPR6.4;
bit RC3IP   @ IPR6.5;
bit TX4IP   @ IPR6.6;
bit RC4IP   @ IPR6.7;

bit HLVDEN  @ HLVDCON.4;
bit IRVST   @ HLVDCON.5;
bit BGVST   @ HLVDCON.6;
bit VDIRMAG @ HLVDCON.7;

bit PSPMODE @ PSPCON.4;
bit IBOV    @ PSPCON.5;
bit OBF     @ PSPCON.6;
bit IBF     @ PSPCON.7;

bit CMP1IF  @ PIR6.0;
bit CMP2IF  @ PIR6.1;
bit CMP3IF  @ PIR6.2;
bit TX3IF   @ PIR6.4;
bit RC3IF   @ PIR6.5;
bit TX4IF   @ PIR6.6;
bit RC4IF   @ PIR6.7;

bit RTCCIP  @ IPR3.0;
bit CCP1IP  @ IPR3.1;
bit CCP2IP  @ IPR3.2;
bit CTMUIP  @ IPR3.3;
bit TX2IP   @ IPR3.4;
bit RC2IP   @ IPR3.5;
bit LCDIP   @ IPR3.6;
bit TMR5GIP @ IPR3.7;

bit RTCCIF  @ PIR3.0;
bit CCP1IF  @ PIR3.1;
bit CCP2IF  @ PIR3.2;
bit CTMUIF  @ PIR3.3;
bit TX2IF   @ PIR3.4;
bit RC2IF   @ PIR3.5;
bit LCDIF   @ PIR3.6;
bit TMR5GIF @ PIR3.7;

bit RTCCIE  @ PIE3.0;
bit CCP1IE  @ PIE3.1;
bit CCP2IE  @ PIE3.2;
bit CTMUIE  @ PIE3.3;
bit TX2IE   @ PIE3.4;
bit RC2IE   @ PIE3.5;
bit LCDIE   @ PIE3.6;
bit TMR5GIE @ PIE3.7;

bit TMR3GIP @ IPR2.0;
bit TMR3IP  @ IPR2.1;
bit HLVDIP  @ IPR2.2;
bit BCL1IP  @ IPR2.3;
bit USBIP   @ IPR2.4;
bit BCL2IP  @ IPR2.5;
bit SSP2IP  @ IPR2.6;
bit OSCFIP  @ IPR2.7;

bit TMR3GIF @ PIR2.0;
bit TMR3IF  @ PIR2.1;
bit HLVDIF  @ PIR2.2;
bit BCL1IF  @ PIR2.3;
bit USBIF   @ PIR2.4;
bit BCL2IF  @ PIR2.5;
bit SSP2IF  @ PIR2.6;
bit OSCFIF  @ PIR2.7;

bit TMR3GIE @ PIE2.0;
bit TMR3IE  @ PIE2.1;
bit HLVDIE  @ PIE2.2;
bit BCL1IE  @ PIE2.3;
bit USBIE   @ PIE2.4;
bit BCL2IE  @ PIE2.5;
bit SSP2IE  @ PIE2.6;
bit OSCFIE  @ PIE2.7;

bit TMR1IP  @ IPR1.0;
bit TMR2IP  @ IPR1.1;
bit TMR1GIP @ IPR1.2;
bit SSP1IP  @ IPR1.3;
bit TX1IP   @ IPR1.4;
bit RC1IP   @ IPR1.5;
bit ADIP    @ IPR1.6;
bit PSPIP   @ IPR1.7;

bit TMR1IF  @ PIR1.0;
bit TMR2IF  @ PIR1.1;
bit TMR1GIF @ PIR1.2;
bit SSP1IF  @ PIR1.3;
bit TX1IF   @ PIR1.4;
bit RC1IF   @ PIR1.5;
bit ADIF    @ PIR1.6;
bit PSPIF   @ PIR1.7;

bit TMR1IE  @ PIE1.0;
bit TMR2IE  @ PIE1.1;
bit TMR1GIE @ PIE1.2;
bit SSP1IE  @ PIE1.3;
bit TX1IE   @ PIE1.4;
bit RC1IE   @ PIE1.5;
bit ADIE    @ PIE1.6;
bit PSPIE   @ PIE1.7;

bit STRA    @ PSTR1CON.0;
bit STRB    @ PSTR1CON.1;
bit STRC    @ PSTR1CON.2;
bit STRD    @ PSTR1CON.3;
bit STRSYNC @ PSTR1CON.4;
bit CMPL0   @ PSTR1CON.6;
bit CMPL1   @ PSTR1CON.7;

bit WR      @ EECON1.1;
bit WREN    @ EECON1.2;
bit WRERR   @ EECON1.3;
bit FREE    @ EECON1.4;
bit WWPROG  @ EECON1.5;

bit SWDTEN  @ RCON2.5;
bit EXTR    @ RCON2.7;

bit VBAT    @ RCON3.0;
bit VBPOR   @ RCON3.1;
bit VDDPOR  @ RCON3.2;
bit VDDBOR  @ RCON3.3;
bit STKERR  @ RCON3.7;

bit PMSLP   @ RCON4.0;
bit DPSLP   @ RCON4.2;
bit SRETEN  @ RCON4.4;

bit URSTIF  @ UIR.0;
bit UERRIF  @ UIR.1;
bit ACTVIF  @ UIR.2;
bit TRNIF   @ UIR.3;
bit IDLEIF  @ UIR.4;
bit STALLIF @ UIR.5;
bit SOFIF   @ UIR.6;

bit PIDEF   @ UEIR.0;
bit CRC5EF  @ UEIR.1;
bit CRC16EF @ UEIR.2;
bit DFN8EF  @ UEIR.3;
bit BTOEF   @ UEIR.4;
bit BTSEF   @ UEIR.7;

bit PPBI    @ USTAT.1;
bit DIR     @ USTAT.2;
bit ENDP0   @ USTAT.3;
bit ENDP1   @ USTAT.4;
bit ENDP2   @ USTAT.5;
bit ENDP3   @ USTAT.6;

bit SUSPND  @ UCON.1;
bit RESUME  @ UCON.2;
bit USBEN   @ UCON.3;
bit PKTDIS  @ UCON.4;
bit SE0     @ UCON.5;
bit PPBRST  @ UCON.6;

bit DHEN    @ SSP1CON3.0;
bit AHEN    @ SSP1CON3.1;
bit SBCDE   @ SSP1CON3.2;
bit SDAHT   @ SSP1CON3.3;
bit BOEN    @ SSP1CON3.4;
bit SCIE    @ SSP1CON3.5;
bit PCIE    @ SSP1CON3.6;
bit ACKTIM  @ SSP1CON3.7;

bit ABDEN   @ BAUDCON1.0;
bit WUE     @ BAUDCON1.1;
bit IREN    @ BAUDCON1.2;
bit BRG16   @ BAUDCON1.3;
bit TXCKP   @ BAUDCON1.4;
bit RXDTP   @ BAUDCON1.5;
bit RCIDL   @ BAUDCON1.6;
bit ABDOVF  @ BAUDCON1.7;

bit SOSCGO  @ OSCCON2.1;
bit POSCEN  @ OSCCON2.2;
bit CF      @ OSCCON2.3;
bit LOCK    @ OSCCON2.5;
bit IOLOCK  @ OSCCON2.6;
bit CLKLOCK @ OSCCON2.7;

bit PLLEN   @ OSCCON4.5;
bit CPDIV0  @ OSCCON4.6;
bit CPDIV1  @ OSCCON4.7;

bit ACTORSPOL @ ACTCON.0;
bit ACTORS  @ ACTCON.1;
bit ACTLOCKPOL @ ACTCON.2;
bit ACTLOCK @ ACTCON.3;
bit ACTSRC  @ ACTCON.4;
bit ACTSIDL @ ACTCON.5;
bit ACTEN   @ ACTCON.7;

bit CMP1IE  @ PIE6.0;
bit CMP2IE  @ PIE6.1;
bit CMP3IE  @ PIE6.2;
bit TX3IE   @ PIE6.4;
bit RC3IE   @ PIE6.5;
bit TX4IE   @ PIE6.6;
bit RC4IE   @ PIE6.7;

bit DMAEN   @ DMACON1.0;
bit DLYINTEN @ DMACON1.1;
bit DUPLEX0 @ DMACON1.2;
bit DUPLEX1 @ DMACON1.3;
bit RXINC   @ DMACON1.4;
bit TXINC   @ DMACON1.5;
bit SSCON0  @ DMACON1.6;
bit SSCON1  @ DMACON1.7;

bit RTCPTR0 @ RTCCON1.0;
bit RTCPTR1 @ RTCCON1.1;
bit RTCOE   @ RTCCON1.2;
bit HALFSEC @ RTCCON1.3;
bit RTCSYNC @ RTCCON1.4;
bit RTCWREN @ RTCCON1.5;
bit RTCEN   @ RTCCON1.7;

bit ALRMPTR0 @ ALRMCFG.0;
bit ALRMPTR1 @ ALRMCFG.1;
bit AMASK0  @ ALRMCFG.2;
bit AMASK1  @ ALRMCFG.3;
bit AMASK2  @ ALRMCFG.4;
bit AMASK3  @ ALRMCFG.5;
bit CHIME   @ ALRMCFG.6;
bit ALRMEN  @ ALRMCFG.7;

bit RTCSECSEL0 @ RTCCON2.0;
bit RTCSECSEL1 @ RTCCON2.1;
bit RTCCLKSEL0 @ RTCCON2.2;
bit RTCCLKSEL1 @ RTCCON2.3;
bit PWCSPRE @ RTCCON2.4;
bit PWCCPRE @ RTCCON2.5;
bit PWCPOL  @ RTCCON2.6;
bit PWCEN   @ RTCCON2.7;

bit RLPU    @ PADCFG1.0;
bit RKPU    @ PADCFG1.1;
bit RJPU    @ PADCFG1.2;
bit RHPU    @ PADCFG1.3;
bit RGPU    @ PADCFG1.4;
bit RFPU    @ PADCFG1.5;
bit REPU    @ PADCFG1.6;
bit RDPU    @ PADCFG1.7;

bit PSS2BD0 @ ECCP2AS.0;
bit PSS2BD1 @ ECCP2AS.1;
bit PSS2AC0 @ ECCP2AS.2;
bit PSS2AC1 @ ECCP2AS.3;
bit ECCP2ASE @ ECCP2AS.7;

bit P2RSEN  @ ECCP2DEL.7;

bit PSS3BD0 @ ECCP3AS.0;
bit PSS3BD1 @ ECCP3AS.1;
bit PSS3AC0 @ ECCP3AS.2;
bit PSS3AC1 @ ECCP3AS.3;
bit ECCP3ASE @ ECCP3AS.7;

bit P3RSEN  @ ECCP3DEL.7;

bit CCP3Y   @ CCP3CON.4;
bit CCP3X   @ CCP3CON.5;
bit P3M0    @ CCP3CON.6;
bit P3M1    @ CCP3CON.7;

bit CCP8Y   @ CCP8CON.4;
bit CCP8X   @ CCP8CON.5;

bit CCP9Y   @ CCP9CON.4;
bit CCP9X   @ CCP9CON.5;

bit CCP10Y  @ CCP10CON.4;
bit CCP10X  @ CCP10CON.5;

bit T6CKPS0 @ T6CON.0;
bit T6CKPS1 @ T6CON.1;
bit TMR6ON  @ T6CON.2;

bit T8CKPS0 @ T8CON.0;
bit T8CKPS1 @ T8CON.1;
bit TMR8ON  @ T8CON.2;

bit DHEN2   @ SSP2CON3.0;
bit AHEN2   @ SSP2CON3.1;
bit SBCDE2  @ SSP2CON3.2;
bit SDAHT2  @ SSP2CON3.3;
bit BOEN2   @ SSP2CON3.4;
bit SCIE2   @ SSP2CON3.5;
bit PCIE2   @ SSP2CON3.6;
bit ACKTIM2 @ SSP2CON3.7;

bit C1TSEL0 @ CCPTMRS0.0;
bit C1TSEL1 @ CCPTMRS0.1;
bit C1TSEL2 @ CCPTMRS0.2;
bit C2TSEL0 @ CCPTMRS0.3;
bit C2TSEL1 @ CCPTMRS0.4;
bit C2TSEL2 @ CCPTMRS0.5;
bit C3TSEL0 @ CCPTMRS0.6;
bit C3TSEL1 @ CCPTMRS0.7;

bit C4TSEL0 @ CCPTMRS1.0;
bit C4TSEL1 @ CCPTMRS1.1;
bit C5TSEL0 @ CCPTMRS1.2;
bit C6TSEL0 @ CCPTMRS1.4;
bit C7TSEL0 @ CCPTMRS1.6;
bit C7TSEL1 @ CCPTMRS1.7;

bit C8TSEL0 @ CCPTMRS2.0;
bit C8TSEL1 @ CCPTMRS2.1;
bit C9TSEL0 @ CCPTMRS2.2;
bit C10TSEL0 @ CCPTMRS2.4;

bit RX9D2   @ RCSTA2.0;
bit OERR2   @ RCSTA2.1;
bit FERR2   @ RCSTA2.2;
bit ADDEN2  @ RCSTA2.3;
bit CREN2   @ RCSTA2.4;
bit SREN2   @ RCSTA2.5;
bit RX9_2   @ RCSTA2.6;
bit SPEN2   @ RCSTA2.7;

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
bit IREN2   @ BAUDCON2.2;
bit BRG16_2 @ BAUDCON2.3;
bit TXCKP2  @ BAUDCON2.4;
bit RXDTP2  @ BAUDCON2.5;
bit RCIDL2  @ BAUDCON2.6;
bit ABDOVF2 @ BAUDCON2.7;

bit RX9D3   @ RCSTA3.0;
bit OERR3   @ RCSTA3.1;
bit FERR3   @ RCSTA3.2;
bit ADDEN3  @ RCSTA3.3;
bit CREN3   @ RCSTA3.4;
bit SREN3   @ RCSTA3.5;
bit RX9_3   @ RCSTA3.6;
bit SPEN3   @ RCSTA3.7;

bit TX9D3   @ TXSTA3.0;
bit TRMT3   @ TXSTA3.1;
bit BRGH3   @ TXSTA3.2;
bit SENDB3  @ TXSTA3.3;
bit SYNC3   @ TXSTA3.4;
bit TXEN3   @ TXSTA3.5;
bit TX9_3   @ TXSTA3.6;
bit CSRC3   @ TXSTA3.7;

bit ABDEN3  @ BAUDCON3.0;
bit WUE3    @ BAUDCON3.1;
bit IREN3   @ BAUDCON3.2;
bit BRG16_3 @ BAUDCON3.3;
bit TXCKP3  @ BAUDCON3.4;
bit RXDTP3  @ BAUDCON3.5;
bit RCIDL3  @ BAUDCON3.6;
bit ABDOVF3 @ BAUDCON3.7;

bit RELEASE @ DSCONL.0;
bit DSBOR   @ DSCONL.1;
bit ULPWDIS @ DSCONL.2;

bit RTCWDIS @ DSCONH.0;
bit DSEN    @ DSCONH.7;

bit DSPOR   @ DSWAKEL.0;
bit DSICD   @ DSWAKEL.1;
bit DSMCLR  @ DSWAKEL.2;
bit DSRTC   @ DSWAKEL.3;
bit DSWDT   @ DSWAKEL.4;
bit DSULP   @ DSWAKEL.5;
bit BOR_DSW @ DSWAKEL.6;
bit DSFLT   @ DSWAKEL.7;

bit DSINT0  @ DSWAKEH.0;

bit STR2A   @ PSTR2CON.0;
bit STR2B   @ PSTR2CON.1;
bit STR2C   @ PSTR2CON.2;
bit STR2D   @ PSTR2CON.3;
bit STR2SYNC @ PSTR2CON.4;
bit CMP2L0  @ PSTR2CON.6;
bit CMP2L1  @ PSTR2CON.7;

bit STR3A   @ PSTR3CON.0;
bit STR3B   @ PSTR3CON.1;
bit STR3C   @ PSTR3CON.2;
bit STR3D   @ PSTR3CON.3;
bit STR3SYNC @ PSTR3CON.4;
bit CMP3L0  @ PSTR3CON.6;
bit CMP3L1  @ PSTR3CON.7;

bit BF2     @ SSP2STAT.0;
bit UA2     @ SSP2STAT.1;
bit RW2_    @ SSP2STAT.2;
bit S2      @ SSP2STAT.3;
bit P2      @ SSP2STAT.4;
bit DA2_    @ SSP2STAT.5;
bit CKE2    @ SSP2STAT.6;
bit SMP2    @ SSP2STAT.7;

bit CKP2    @ SSP2CON1.4;
bit SSPEN2  @ SSP2CON1.5;
bit SSPOV2  @ SSP2CON1.6;
bit WCOL2   @ SSP2CON1.7;

bit SEN2    @ SSP2CON2.0;
bit RSEN2   @ SSP2CON2.1;
bit PEN2    @ SSP2CON2.2;
bit RCEN2   @ SSP2CON2.3;
bit ACKEN2  @ SSP2CON2.4;
bit ACKDT2  @ SSP2CON2.5;
bit ACKSTAT2 @ SSP2CON2.6;
bit GCEN2   @ SSP2CON2.7;

bit TMR5ON  @ T5CON.0;
bit T5RD16  @ T5CON.1;
bit T5SYNC_ @ T5CON.2;
bit T5SOSCEN @ T5CON.3;
bit T5CKPS0 @ T5CON.4;
bit T5CKPS1 @ T5CON.5;
bit TMR5CS0 @ T5CON.6;
bit TMR5CS1 @ T5CON.7;

bit T5GSS0  @ T5GCON.0;
bit T5GSS1  @ T5GCON.1;
bit T5GVAL  @ T5GCON.2;
bit T5GGO   @ T5GCON.3;
bit T5GSPM  @ T5GCON.4;
bit T5GTM   @ T5GCON.5;
bit T5GPOL  @ T5GCON.6;
bit TMR5GE  @ T5GCON.7;

bit T4CKPS0 @ T4CON.0;
bit T4CKPS1 @ T4CON.1;
bit TMR4ON  @ T4CON.2;

bit VBGEN   @ ANCFG.0;
bit VBG2EN  @ ANCFG.1;
bit VBG6EN  @ ANCFG.2;

bit RX9D4   @ RCSTA4.0;
bit OERR4   @ RCSTA4.1;
bit FERR4   @ RCSTA4.2;
bit ADDEN4  @ RCSTA4.3;
bit CREN4   @ RCSTA4.4;
bit SREN4   @ RCSTA4.5;
bit RX9_4   @ RCSTA4.6;
bit SPEN4   @ RCSTA4.7;

bit TX9D4   @ TXSTA4.0;
bit TRMT4   @ TXSTA4.1;
bit BRGH4   @ TXSTA4.2;
bit SENDB4  @ TXSTA4.3;
bit SYNC4   @ TXSTA4.4;
bit TXEN4   @ TXSTA4.5;
bit TX9_4   @ TXSTA4.6;
bit CSRC4   @ TXSTA4.7;

bit ABDEN4  @ BAUDCON4.0;
bit WUE4    @ BAUDCON4.1;
bit IREN4   @ BAUDCON4.2;
bit BRG16_4 @ BAUDCON4.3;
bit TXCKP4  @ BAUDCON4.4;
bit RXDTP4  @ BAUDCON4.5;
bit RCIDL4  @ BAUDCON4.6;
bit ABDOVF4 @ BAUDCON4.7;

bit TRIGEN  @ CTMUCON1.0;
bit IDISSEN @ CTMUCON1.1;
bit EDGSEQEN @ CTMUCON1.2;
bit EDGEN   @ CTMUCON1.3;
bit TGEN    @ CTMUCON1.4;
bit CTMUSIDL @ CTMUCON1.5;
bit CTMUEN  @ CTMUCON1.7;

bit EDG2POL @ CTMUCON3.6;
bit EDG2EN  @ CTMUCON3.7;

bit EDG1STAT @ CTMUCON4.0;
bit EDG2STAT @ CTMUCON4.1;
bit EDG1POL @ CTMUCON4.6;
bit EDG1EN  @ CTMUCON4.7;

bit ECCP3MD @ PMD0.0;
bit CCP4MD  @ PMD0.1;
bit CCP5MD  @ PMD0.2;
bit CCP6MD  @ PMD0.3;
bit CCP7MD  @ PMD0.4;
bit CCP8MD  @ PMD0.5;
bit CCP9MD  @ PMD0.6;
bit CCP10MD @ PMD0.7;

bit SSP1MD  @ PMD1.0;
bit SSP2MD  @ PMD1.1;
bit UART1MD @ PMD1.2;
bit UART2MD @ PMD1.3;
bit UART3MD @ PMD1.4;
bit UART4MD @ PMD1.5;
bit ECCP1MD @ PMD1.6;
bit ECCP2MD @ PMD1.7;

bit TMR0MD  @ PMD2.0;
bit TMR1MD  @ PMD2.1;
bit TMR2MD  @ PMD2.2;
bit TMR3MD  @ PMD2.3;
bit TMR4MD  @ PMD2.4;
bit TMR5MD  @ PMD2.5;
bit TMR6MD  @ PMD2.6;
bit TMR8MD  @ PMD2.7;

bit REFO2MD @ PMD3.0;
bit REFO1MD @ PMD3.1;
bit PSPMD   @ PMD3.2;
bit LCDMD   @ PMD3.3;
bit RTCCMD  @ PMD3.4;
bit ADCMD   @ PMD3.5;
bit CTMUMD  @ PMD3.6;
bit TXMMD   @ PMD3.7;

bit EMBMD   @ PMD4.0;
bit LVDMD   @ PMD4.2;
bit IOCMD   @ PMD4.3;
bit USBMD   @ PMD4.4;
bit CMP3MD  @ PMD4.5;
bit CMP2MD  @ PMD4.6;
bit CMP1MD  @ PMD4.7;

bit MDBIT   @ MDCON.0;
bit MDO     @ MDCON.3;
bit MDOPOL  @ MDCON.4;
bit MDSLR   @ MDCON.5;
bit MDOE    @ MDCON.6;
bit MDEN    @ MDCON.7;

bit MDSODIS @ MDSRC.7;

bit SSP1OD  @ ODCON1.0;
bit SSP2OD  @ ODCON1.1;
bit USART1OD @ ODCON1.2;
bit USART2OD @ ODCON1.3;
bit USART3OD @ ODCON1.4;
bit USART4OD @ ODCON1.5;
bit ECCP1OD @ ODCON1.6;
bit ECCP2OD @ ODCON1.7;

bit ECCP3OD @ ODCON2.0;
bit CCP4OD  @ ODCON2.1;
bit CCP5OD  @ ODCON2.2;
bit CCP6OD  @ ODCON2.3;
bit CCP7OD  @ ODCON2.4;
bit CCP8OD  @ ODCON2.5;
bit CCP9OD  @ ODCON2.6;
bit CCP10OD @ ODCON2.7;

bit WM0     @ MEMCON.0;
bit WM1     @ MEMCON.1;
bit WAIT0   @ MEMCON.4;
bit WAIT1   @ MEMCON.5;
bit EBDIS   @ MEMCON.7;

bit R1ACTIVE @ REFO1CON.0;
bit R1DIVSWEN @ REFO1CON.1;
bit R1SLP   @ REFO1CON.3;
bit R1OE    @ REFO1CON.4;
bit R1SIDL  @ REFO1CON.5;
bit R1ON    @ REFO1CON.7;

bit R2ACTIVE @ REFO2CON.0;
bit R2DIVSWEN @ REFO2CON.1;
bit R2SLP   @ REFO2CON.3;
bit R2OE    @ REFO2CON.4;
bit R2SIDL  @ REFO2CON.5;
bit R2ON    @ REFO2CON.7;

bit WA      @ LCDPS.4;
bit LCDA    @ LCDPS.5;
bit BIASMD  @ LCDPS.6;
bit WFT     @ LCDPS.7;

bit LMUX0   @ LCDCON.0;
bit LMUX1   @ LCDCON.1;
bit LMUX2   @ LCDCON.2;
bit CS0     @ LCDCON.3;
bit CS1     @ LCDCON.4;
bit WERR    @ LCDCON.5;
bit SLPEN   @ LCDCON.6;
bit LCDEN   @ LCDCON.7;

bit CLKSEL0 @ LCDREG.0;
bit CLKSEL1 @ LCDREG.1;
bit MODE13  @ LCDREG.2;
bit BIAS0   @ LCDREG.3;
bit BIAS1   @ LCDREG.4;
bit BIAS2   @ LCDREG.5;
bit CPEN    @ LCDREG.7;

bit VLCD1PE @ LCDREF.0;
bit VLCD2PE @ LCDREF.1;
bit VLCD3PE @ LCDREF.2;
bit LCDCST0 @ LCDREF.3;
bit LCDCST1 @ LCDREF.4;
bit LCDCST2 @ LCDREF.5;
bit LCDIRE  @ LCDREF.7;

bit LRLAT0  @ LCDRL.0;
bit LRLAT1  @ LCDRL.1;
bit LRLAT2  @ LCDRL.2;
bit LRLBP0  @ LCDRL.4;
bit LRLBP1  @ LCDRL.5;
bit LRLAP0  @ LCDRL.6;
bit LRLAP1  @ LCDRL.7;

bit CSCNA   @ ADCON2H.2;
bit BUFREGEN @ ADCON2H.3;
bit OFFCAL  @ ADCON2H.4;
bit NVCFG0  @ ADCON2H.5;
bit PVCFG0  @ ADCON2H.6;
bit PVCFG1  @ ADCON2H.7;

bit ALTS    @ ADCON2L.0;
bit BUFM    @ ADCON2L.1;
bit SMPI0   @ ADCON2L.2;
bit SMPI1   @ ADCON2L.3;
bit SMPI2   @ ADCON2L.4;
bit SMPI3   @ ADCON2L.5;
bit SMPI4   @ ADCON2L.6;
bit BUFS    @ ADCON2L.7;

bit SAMC0   @ ADCON3H.0;
bit SAMC1   @ ADCON3H.1;
bit SAMC2   @ ADCON3H.2;
bit SAMC3   @ ADCON3H.3;
bit SAMC4   @ ADCON3H.4;
bit PUMPEN  @ ADCON3H.5;
bit EXTSAM  @ ADCON3H.6;
bit ADRC    @ ADCON3H.7;

bit ASINTMD0 @ ADCON5H.0;
bit ASINTMD1 @ ADCON5H.1;
bit CTMUREQ @ ADCON5H.5;
bit LPENA   @ ADCON5H.6;
bit ASENA   @ ADCON5H.7;

bit PPB0    @ UCFG.0;
bit PPB1    @ UCFG.1;
bit FSEN    @ UCFG.2;
bit UTRDIS  @ UCFG.3;
bit UPUEN   @ UCFG.4;
bit UOEMON  @ UCFG.6;
bit UTEYE   @ UCFG.7;

bit URSTIE  @ UIE.0;
bit UERRIE  @ UIE.1;
bit ACTVIE  @ UIE.2;
bit TRNIE   @ UIE.3;
bit IDLEIE  @ UIE.4;
bit STALLIE @ UIE.5;
bit SOFIE   @ UIE.6;

bit PIDEE   @ UEIE.0;
bit CRC5EE  @ UEIE.1;
bit CRC16EE @ UEIE.2;
bit DFN8EE  @ UEIE.3;
bit BTOEE   @ UEIE.4;
bit BTSEE   @ UEIE.7;
