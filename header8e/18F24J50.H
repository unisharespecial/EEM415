// Header file
#pragma chip PIC18F24J50, core 16, code 8192, ram 0 : 0xEBF

#ifdef ICD2_DEBUG
 #pragma stackLevels 29   // reserve two levels for debugging
#endif

// Extended Instruction Set

#pragma accessGPR 0x60

#pragma configMapCodeSpace 0x1FFC
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
char TMR0L    @ 0xFD6;
char T0CON    @ 0xFD5;

char OSCCON   @ 0xFD3;
char CM1CON   @ 0xFD2;
char CM2CON   @ 0xFD1;
char RCON     @ 0xFD0;
char TMR1H    @ 0xFCF;
char TMR1L    @ 0xFCE;
char T1CON    @ 0xFCD;
char TMR2     @ 0xFCC;
char PR2      @ 0xFCB;
char T2CON    @ 0xFCA;
char SSP1BUF  @ 0xFC9;
char SSP1ADD  @ 0xFC8;
char SSP1MSK  @ 0xFC8;
char SSP1STAT @ 0xFC7;
char SSP1CON1 @ 0xFC6;
char SSP1CON2 @ 0xFC5;
char ADRESH   @ 0xFC4;
char ADRESL   @ 0xFC3;
char ADCON0   @ 0xFC2;
char ADCON1   @ 0xFC1;
char WDTCON   @ 0xFC0;
char PSTR1CON @ 0xFBF;
char ECCP1AS  @ 0xFBE;
char ECCP1DEL @ 0xFBD;
char CCPR1H   @ 0xFBC;
char CCPR1L   @ 0xFBB;
char CCP1CON  @ 0xFBA;
char PSTR2CON @ 0xFB9;
char ECCP2AS  @ 0xFB8;
char ECCP2DEL @ 0xFB7;
char CCPR2H   @ 0xFB6;
char CCPR2L   @ 0xFB5;
char CCP2CON  @ 0xFB4;
char CTMUCONH @ 0xFB3;
char CTMUCONL @ 0xFB2;
char CTMUICON @ 0xFB1;
char SPBRG1   @ 0xFB0;
char RCREG1   @ 0xFAF;
char TXREG1   @ 0xFAE;
char TXSTA1   @ 0xFAD;
char RCSTA1   @ 0xFAC;
char SPBRG2   @ 0xFAB;
char RCREG2   @ 0xFAA;
char TXREG2   @ 0xFA9;
char TXSTA2   @ 0xFA8;
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
char RCSTA2   @ 0xF9C;
char OSCTUNE  @ 0xF9B;
char T1GCON   @ 0xF9A;
char RTCVALH  @ 0xF99;
char RTCVALL  @ 0xF98;
char T3GCON   @ 0xF97;

char TRISC    @ 0xF94;
char TRISB    @ 0xF93;
char TRISA    @ 0xF92;
char ALRMCFG  @ 0xF91;
char ALRMRPT  @ 0xF90;
char ALRMVALH @ 0xF8F;
char ALRMVALL @ 0xF8E;

char LATC     @ 0xF8B;
char LATB     @ 0xF8A;
char LATA     @ 0xF89;
char DMACON1  @ 0xF88;

char DMACON2  @ 0xF86;
char HLVDCON  @ 0xF85;

char PORTC    @ 0xF82;
char PORTB    @ 0xF81;
char PORTA    @ 0xF80;
char SPBRGH1  @ 0xF7F;
char BAUDCON1 @ 0xF7E;
char SPBRGH2  @ 0xF7D;
char BAUDCON2 @ 0xF7C;
char TMR3H    @ 0xF7B;
char TMR3L    @ 0xF7A;
char T3CON    @ 0xF79;
char TMR4     @ 0xF78;
char PR4      @ 0xF77;
char T4CON    @ 0xF76;
char SSP2BUF  @ 0xF75;
char SSP2ADD  @ 0xF74;
char SSP2MSK  @ 0xF74;
char SSP2STAT @ 0xF73;
char SSP2CON1 @ 0xF72;
char SSP2CON2 @ 0xF71;
char CMSTAT   @ 0xF70;

char TXADDRL  @ 0xF6B;
char TXADDRH  @ 0xF6A;
char RXADDRL  @ 0xF69;
char RXADDRH  @ 0xF68;
char DMABCL   @ 0xF67;
char DMABCH   @ 0xF66;
char UCON     @ 0xF65;
char USTAT    @ 0xF64;
char UEIR     @ 0xF63;
char UIR      @ 0xF62;
char UFRMH    @ 0xF61;
char UFRML    @ 0xF60;

char TCLKCON  @ 0xF52;

char DSGPR1   @ 0xF4F;
char DSGPR0   @ 0xF4E;
char DSCONH   @ 0xF4D;
char DSCONL   @ 0xF4C;
char DSWAKEH  @ 0xF4B;
char DSWAKEL  @ 0xF4A;
char ANCON1   @ 0xF49;
char ANCON0   @ 0xF48;

char ODCON1   @ 0xF42;
char ODCON2   @ 0xF41;
char ODCON3   @ 0xF40;
char RTCCFG   @ 0xF3F;
char RTCCAL   @ 0xF3E;
char REFOCON  @ 0xF3D;
char PADCFG1  @ 0xF3C;

char UCFG     @ 0xF39;
char UADDR    @ 0xF38;
char UEIE     @ 0xF37;
char UIE      @ 0xF36;
char UEP15    @ 0xF35;
char UEP14    @ 0xF34;
char UEP13    @ 0xF33;
char UEP12    @ 0xF32;
char UEP11    @ 0xF31;
char UEP10    @ 0xF30;
char UEP9     @ 0xF2F;
char UEP8     @ 0xF2E;
char UEP7     @ 0xF2D;
char UEP6     @ 0xF2C;
char UEP5     @ 0xF2B;
char UEP4     @ 0xF2A;
char UEP3     @ 0xF29;
char UEP2     @ 0xF28;
char UEP1     @ 0xF27;
char UEP0     @ 0xF26;

char PPSCON   @ 0xEFF;
char RPINR24  @ 0xEFE;
char RPINR23  @ 0xEFD;
char RPINR22  @ 0xEFC;
char RPINR21  @ 0xEFB;

char RPINR17  @ 0xEF7;
char RPINR16  @ 0xEF6;

char RPINR13  @ 0xEF3;
char RPINR12  @ 0xEF2;

char RPINR8   @ 0xEEE;
char RPINR7   @ 0xEED;
char RPINR6   @ 0xEEC;

char RPINR4   @ 0xEEA;
char RPINR3   @ 0xEE9;
char RPINR2   @ 0xEE8;
char RPINR1   @ 0xEE7;

char RPOR18   @ 0xED8;
char RPOR17   @ 0xED7;

char RPOR13   @ 0xED3;
char RPOR12   @ 0xED2;
char RPOR11   @ 0xED1;
char RPOR10   @ 0xED0;
char RPOR9    @ 0xECF;
char RPOR8    @ 0xECE;
char RPOR7    @ 0xECD;
char RPOR6    @ 0xECC;
char RPOR5    @ 0xECB;
char RPOR4    @ 0xECA;
char RPOR3    @ 0xEC9;
char RPOR2    @ 0xEC8;
char RPOR1    @ 0xEC7;
char RPOR0    @ 0xEC6;

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
bit OSTS    @ OSCCON.3;
bit IDLEN   @ OSCCON.7;

bit C1CH0   @ CM1CON.0;
bit C1CH1   @ CM1CON.1;
bit C1R     @ CM1CON.2;
bit C1SP    @ CM1CON.3;
bit C1POL   @ CM1CON.4;
bit C1OE    @ CM1CON.5;
bit C1OUT   @ CM1CON.6;
bit C1ON    @ CM1CON.7;

bit C2CH0   @ CM2CON.0;
bit C2CH1   @ CM2CON.1;
bit C2R     @ CM2CON.2;
bit C2SP    @ CM2CON.3;
bit C2POL   @ CM2CON.4;
bit C2OE    @ CM2CON.5;
bit C2OUT   @ CM2CON.6;
bit C2ON    @ CM2CON.7;

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
bit T1OSCEN @ T1CON.3;
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

bit ADON    @ ADCON0.0;
bit GO      @ ADCON0.1;
bit CHS0    @ ADCON0.2;
bit CHS1    @ ADCON0.3;
bit CHS2    @ ADCON0.4;
bit CHS3    @ ADCON0.5;
bit VCFG0   @ ADCON0.6;
bit VCFG1   @ ADCON0.7;

bit ADCS0   @ ADCON1.0;
bit ADCS1   @ ADCON1.1;
bit ADCS2   @ ADCON1.2;
bit ADCAL   @ ADCON1.6;
bit ADFM    @ ADCON1.7;

bit SWDTEN  @ WDTCON.0;
bit ULPSINK @ WDTCON.1;
bit ULPEN   @ WDTCON.2;
bit DS      @ WDTCON.3;
bit ULPLVL  @ WDTCON.5;
bit LVDSTAT @ WDTCON.6;
bit REGSLP  @ WDTCON.7;

bit STRA    @ PSTR1CON.0;
bit STRB    @ PSTR1CON.1;
bit STRC    @ PSTR1CON.2;
bit STRD    @ PSTR1CON.3;
bit STRSYNC @ PSTR1CON.4;
bit CMPL0   @ PSTR1CON.6;
bit CMPL1   @ PSTR1CON.7;

bit PSS1BD0 @ ECCP1AS.0;
bit PSS1BD1 @ ECCP1AS.1;
bit PSS1AC0 @ ECCP1AS.2;
bit PSS1AC1 @ ECCP1AS.3;
bit ECCP1AS0 @ ECCP1AS.4;
bit ECCP1AS1 @ ECCP1AS.5;
bit ECCP1AS2 @ ECCP1AS.6;
bit ECCP1ASE @ ECCP1AS.7;

bit P1RSEN  @ ECCP1DEL.7;

bit DC1B0   @ CCP1CON.4;
bit DC1B1   @ CCP1CON.5;
bit P1M0    @ CCP1CON.6;
bit P1M1    @ CCP1CON.7;

bit STR2A   @ PSTR2CON.0;
bit STR2B   @ PSTR2CON.1;
bit STR2C   @ PSTR2CON.2;
bit STR2D   @ PSTR2CON.3;
bit STR2SYNC @ PSTR2CON.4;
bit CMP2L0  @ PSTR2CON.6;
bit CMP2L1  @ PSTR2CON.7;

bit PSS2BD0 @ ECCP2AS.0;
bit PSS2BD1 @ ECCP2AS.1;
bit PSS2AC0 @ ECCP2AS.2;
bit PSS2AC1 @ ECCP2AS.3;
bit ECCP2ASE @ ECCP2AS.7;

bit P2RSEN  @ ECCP2DEL.7;

bit DC2B0   @ CCP2CON.4;
bit DC2B1   @ CCP2CON.5;
bit P2M0    @ CCP2CON.6;
bit P2M1    @ CCP2CON.7;

bit IDISSEN @ CTMUCONH.1;
bit EDGSEQEN @ CTMUCONH.2;
bit EDGEN   @ CTMUCONH.3;
bit TGEN    @ CTMUCONH.4;
bit CTMUSIDL @ CTMUCONH.5;
bit CTMUEN  @ CTMUCONH.7;

bit EDG1STAT @ CTMUCONL.0;
bit EDG2STAT @ CTMUCONL.1;
bit EDG1SEL0 @ CTMUCONL.2;
bit EDG1SEL1 @ CTMUCONL.3;
bit EDG1POL @ CTMUCONL.4;
bit EDG2SEL0 @ CTMUCONL.5;
bit EDG2SEL1 @ CTMUCONL.6;
bit EDG2POL @ CTMUCONL.7;

bit IRNG0   @ CTMUICON.0;
bit IRNG1   @ CTMUICON.1;

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

bit TX9D2   @ TXSTA2.0;
bit TRMT2   @ TXSTA2.1;
bit BRGH2   @ TXSTA2.2;
bit SENDB2  @ TXSTA2.3;
bit SYNC2   @ TXSTA2.4;
bit TXEN2   @ TXSTA2.5;
bit TX9_2   @ TXSTA2.6;
bit CSRC2   @ TXSTA2.7;

bit WR      @ EECON1.1;
bit WREN    @ EECON1.2;
bit WRERR   @ EECON1.3;
bit FREE    @ EECON1.4;
bit WPROG   @ EECON1.5;

bit RTCCIP  @ IPR3.0;
bit TMR3GIP @ IPR3.1;
bit CTMUIP  @ IPR3.2;
bit TMR4IP  @ IPR3.3;
bit TX2IP   @ IPR3.4;
bit RC2IP   @ IPR3.5;
bit BCL2IP  @ IPR3.6;
bit SSP2IP  @ IPR3.7;

bit RTCCIF  @ PIR3.0;
bit TMR3GIF @ PIR3.1;
bit CTMUIF  @ PIR3.2;
bit TMR4IF  @ PIR3.3;
bit TX2IF   @ PIR3.4;
bit RC2IF   @ PIR3.5;
bit BCL2IF  @ PIR3.6;
bit SSP2IF  @ PIR3.7;

bit RTCCIE  @ PIE3.0;
bit TMR3GIE @ PIE3.1;
bit CTMUIE  @ PIE3.2;
bit TMR4IE  @ PIE3.3;
bit TX2IE   @ PIE3.4;
bit RC2IE   @ PIE3.5;
bit BCL2IE  @ PIE3.6;
bit SSP2IE  @ PIE3.7;

bit CCP2IP  @ IPR2.0;
bit TMR3IP  @ IPR2.1;
bit HLVDIP  @ IPR2.2;
bit BCL1IP  @ IPR2.3;
bit USBIP   @ IPR2.4;
bit CM1IP   @ IPR2.5;
bit CM2IP   @ IPR2.6;
bit OSCFIP  @ IPR2.7;

bit CCP2IF  @ PIR2.0;
bit TMR3IF  @ PIR2.1;
bit HLVDIF  @ PIR2.2;
bit BCL1IF  @ PIR2.3;
bit USBIF   @ PIR2.4;
bit CM1IF   @ PIR2.5;
bit CM2IF   @ PIR2.6;
bit OSCFIF  @ PIR2.7;

bit CCP2IE  @ PIE2.0;
bit TMR3IE  @ PIE2.1;
bit HLVDIE  @ PIE2.2;
bit BCL1IE  @ PIE2.3;
bit USBIE   @ PIE2.4;
bit CM1IE   @ PIE2.5;
bit CM2IE   @ PIE2.6;
bit OSCFIE  @ PIE2.7;

bit TMR1IP  @ IPR1.0;
bit TMR2IP  @ IPR1.1;
bit CCP1IP  @ IPR1.2;
bit SSP1IP  @ IPR1.3;
bit TX1IP   @ IPR1.4;
bit RC1IP   @ IPR1.5;
bit ADIP    @ IPR1.6;

bit TMR1IF  @ PIR1.0;
bit TMR2IF  @ PIR1.1;
bit CCP1IF  @ PIR1.2;
bit SSP1IF  @ PIR1.3;
bit TX1IF   @ PIR1.4;
bit RC1IF   @ PIR1.5;
bit ADIF    @ PIR1.6;

bit TMR1IE  @ PIE1.0;
bit TMR2IE  @ PIE1.1;
bit CCP1IE  @ PIE1.2;
bit SSP1IE  @ PIE1.3;
bit TX1IE   @ PIE1.4;
bit RC1IE   @ PIE1.5;
bit ADIE    @ PIE1.6;

bit RX9D2   @ RCSTA2.0;
bit OERR2   @ RCSTA2.1;
bit FERR2   @ RCSTA2.2;
bit ADDEN2  @ RCSTA2.3;
bit CREN2   @ RCSTA2.4;
bit SREN2   @ RCSTA2.5;
bit RX9_2   @ RCSTA2.6;
bit SPEN2   @ RCSTA2.7;

bit PLLEN   @ OSCTUNE.6;
bit INTSRC  @ OSCTUNE.7;

bit T1GSS0  @ T1GCON.0;
bit T1GSS1  @ T1GCON.1;
bit T1GVAL  @ T1GCON.2;
bit T1GGO   @ T1GCON.3;
bit T1GSPM  @ T1GCON.4;
bit T1GTM   @ T1GCON.5;
bit T1GPOL  @ T1GCON.6;
bit TMR1GE  @ T1GCON.7;

bit T3GSS0  @ T3GCON.0;
bit T3GSS1  @ T3GCON.1;
bit T3GVAL  @ T3GCON.2;
bit T3GGO   @ T3GCON.3;
bit T3GSPM  @ T3GCON.4;
bit T3GTM   @ T3GCON.5;
bit T3GPOL  @ T3GCON.6;
bit TMR3GE  @ T3GCON.7;

bit ALRMPTR0 @ ALRMCFG.0;
bit ALRMPTR1 @ ALRMCFG.1;
bit AMASK0  @ ALRMCFG.2;
bit AMASK1  @ ALRMCFG.3;
bit AMASK2  @ ALRMCFG.4;
bit AMASK3  @ ALRMCFG.5;
bit CHIME   @ ALRMCFG.6;
bit ALRMEN  @ ALRMCFG.7;

bit DMAEN   @ DMACON1.0;
bit DLYINTEN @ DMACON1.1;
bit DUPLEX0 @ DMACON1.2;
bit DUPLEX1 @ DMACON1.3;
bit RXINC   @ DMACON1.4;
bit TXINC   @ DMACON1.5;
bit SSCON0  @ DMACON1.6;
bit SSCON1  @ DMACON1.7;

bit INTLVL0 @ DMACON2.0;
bit INTLVL1 @ DMACON2.1;
bit INTLVL2 @ DMACON2.2;
bit INTLVL3 @ DMACON2.3;
bit DLYCYC0 @ DMACON2.4;
bit DLYCYC1 @ DMACON2.5;
bit DLYCYC2 @ DMACON2.6;
bit DLYCYC3 @ DMACON2.7;

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

bit ABDEN2  @ BAUDCON2.0;
bit WUE2    @ BAUDCON2.1;
bit BRG16_2 @ BAUDCON2.3;
bit TXCKP2  @ BAUDCON2.4;
bit RXDTP2  @ BAUDCON2.5;
bit RCIDL2  @ BAUDCON2.6;
bit ABDOVF2 @ BAUDCON2.7;

bit TMR3ON  @ T3CON.0;
bit T3RD16  @ T3CON.1;
bit T3SYNC_ @ T3CON.2;
bit T3OSCEN @ T3CON.3;
bit T3CKPS0 @ T3CON.4;
bit T3CKPS1 @ T3CON.5;
bit TMR3CS0 @ T3CON.6;
bit TMR3CS1 @ T3CON.7;

bit T4CKPS0 @ T4CON.0;
bit T4CKPS1 @ T4CON.1;
bit TMR4ON  @ T4CON.2;

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

bit COUT1   @ CMSTAT.0;
bit COUT2   @ CMSTAT.1;

bit SUSPND  @ UCON.1;
bit RESUME  @ UCON.2;
bit USBEN   @ UCON.3;
bit PKTDIS  @ UCON.4;
bit SE0     @ UCON.5;
bit PPBRST  @ UCON.6;

bit PPBI    @ USTAT.1;
bit DIR     @ USTAT.2;
bit ENDP0   @ USTAT.3;
bit ENDP1   @ USTAT.4;
bit ENDP2   @ USTAT.5;
bit ENDP3   @ USTAT.6;

bit PIDEF   @ UEIR.0;
bit CRC5EF  @ UEIR.1;
bit CRC16EF @ UEIR.2;
bit DFN8EF  @ UEIR.3;
bit BTOEF   @ UEIR.4;
bit BTSEF   @ UEIR.7;

bit URSTIF  @ UIR.0;
bit UERRIF  @ UIR.1;
bit ACTVIF  @ UIR.2;
bit TRNIF   @ UIR.3;
bit IDLEIF  @ UIR.4;
bit STALLIF @ UIR.5;
bit SOFIF   @ UIR.6;

bit T3CCP1  @ TCLKCON.0;
bit T3CCP2  @ TCLKCON.1;
bit T1RUN   @ TCLKCON.4;

bit RTCWDIS @ DSCONH.0;
bit DSULPEN @ DSCONH.1;
bit DSEN    @ DSCONH.7;

bit RELEASE @ DSCONL.0;
bit DSBOR   @ DSCONL.1;
bit ULPWDIS @ DSCONL.2;

bit DSINT0  @ DSWAKEH.0;

bit DSPOR   @ DSWAKEL.0;
bit DSMCLR  @ DSWAKEL.2;
bit DSRTC   @ DSWAKEL.3;
bit DSWDT   @ DSWAKEL.4;
bit DSULP   @ DSWAKEL.5;
bit DSFLT   @ DSWAKEL.7;

bit VBGEN   @ ANCON1.7;

bit ECCP1OD @ ODCON1.0;
bit ECCP2OD @ ODCON1.1;

bit U1OD    @ ODCON2.0;
bit U2OD    @ ODCON2.1;

bit SPI1OD  @ ODCON3.0;
bit SPI2OD  @ ODCON3.1;

bit RTCPTR0 @ RTCCFG.0;
bit RTCPTR1 @ RTCCFG.1;
bit RTCOE   @ RTCCFG.2;
bit HALFSEC @ RTCCFG.3;
bit RTCSYNC @ RTCCFG.4;
bit RTCWREN @ RTCCFG.5;
bit RTCEN   @ RTCCFG.7;

bit ROSEL   @ REFOCON.4;
bit ROSSLP  @ REFOCON.5;
bit ROON    @ REFOCON.7;

bit PMPTTL  @ PADCFG1.0;
bit RTSECSEL0 @ PADCFG1.1;
bit RTSECSEL1 @ PADCFG1.2;

bit PPB0    @ UCFG.0;
bit PPB1    @ UCFG.1;
bit FSEN    @ UCFG.2;
bit UTRDIS  @ UCFG.3;
bit UPUEN   @ UCFG.4;
bit UOEMON  @ UCFG.6;
bit UTEYE   @ UCFG.7;

bit PIDEE   @ UEIE.0;
bit CRC5EE  @ UEIE.1;
bit CRC16EE @ UEIE.2;
bit DFN8EE  @ UEIE.3;
bit BTOEE   @ UEIE.4;
bit BTSEE   @ UEIE.7;

bit URSTIE  @ UIE.0;
bit UERRIE  @ UIE.1;
bit ACTVIE  @ UIE.2;
bit TRNIE   @ UIE.3;
bit IDLEIE  @ UIE.4;
bit STALLIE @ UIE.5;
bit SOFIE   @ UIE.6;

bit IOLOCK  @ PPSCON.0;
