// Header file
#pragma chip PIC18F85J50, core 16, code 16384, ram 0 : 0xF3F

#ifdef ICD2_DEBUG
 char reservedICD2[12] @ 0xEF4;  // reserved RAM for ICD2

 #pragma stackLevels 29   // reserve two levels for debugging
#endif

// Extended Instruction Set

#pragma accessGPR 0x60

#pragma configMapCodeSpace 0x3FFC
#pragma userIDlocations  -

#if __CC8E__ < 1201
 #warning ADSHR must be updated manually for version 1.2 and earlier
#endif

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
char REFOCON  @ 0xFD3;
char CM1CON1  @ 0xFD2;
char CM2CON1  @ 0xFD1;
char RCON     @ 0xFD0;
char TMR1H    @ 0xFCF;
char ODCON1   @ 0xFCF;
char TMR1L    @ 0xFCE;
char ODCON2   @ 0xFCE;
char T1CON    @ 0xFCD;
char ODCON3   @ 0xFCD;
char TMR2     @ 0xFCC;
char PADCFG1  @ 0xFCC;
char PR2      @ 0xFCB;
char MEMCON   @ 0xFCB;
#pragma adshr_sel 0 OSCCON,  TMR1H,  TMR1L,  T1CON,  TMR2,    PR2
#pragma adshr_sel 1 REFOCON, ODCON1, ODCON2, ODCON3, PADCFG1, MEMCON
char T2CON    @ 0xFCA;
char SSP1BUF  @ 0xFC9;
char SSP1ADD  @ 0xFC8;
char SSP1STAT @ 0xFC7;
char SSP1CON1 @ 0xFC6;
char SSP1CON2 @ 0xFC5;
char ADRESH   @ 0xFC4;
char ADRESL   @ 0xFC3;
char ADCON0   @ 0xFC2;
char ANCON1   @ 0xFC2;
char ADCON1   @ 0xFC1;
char ANCON0   @ 0xFC1;
char WDTCON   @ 0xFC0;
char ECCP1AS  @ 0xFBF;
char ECCP1DEL @ 0xFBE;
char CCPR1H   @ 0xFBD;
char CCPR1L   @ 0xFBC;
char CCP1CON  @ 0xFBB;
char ECCP2AS  @ 0xFBA;
char ECCP2DEL @ 0xFB9;
char CCPR2H   @ 0xFB8;
char CCPR2L   @ 0xFB7;
char CCP2CON  @ 0xFB6;
char ECCP3AS  @ 0xFB5;
char ECCP3DEL @ 0xFB4;
char CCPR3H   @ 0xFB3;
char CCPR3L   @ 0xFB2;
char CCP3CON  @ 0xFB1;
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
char SPBRGH1  @ 0xF7F;
char BAUDCON1 @ 0xF7E;
char SPBRGH2  @ 0xF7D;
char BAUDCON2 @ 0xF7C;
char TMR3H    @ 0xF7B;
char TMR3L    @ 0xF7A;
char T3CON    @ 0xF79;
char TMR4     @ 0xF78;
char PR4      @ 0xF77;
char CVRCON   @ 0xF77;
#pragma adshr_sel 0 ADCON0, ADCON1, PR4
#pragma adshr_sel 1 ANCON1, ANCON0, CVRCON
char T4CON    @ 0xF76;
char CCPR4H   @ 0xF75;
char CCPR4L   @ 0xF74;
char CCP4CON  @ 0xF73;
char CCPR5H   @ 0xF72;
char CCPR5L   @ 0xF71;
char CCP5CON  @ 0xF70;
char SSP2BUF  @ 0xF6F;
char SSP2ADD  @ 0xF6E;
char SSP2STAT @ 0xF6D;
char SSP2CON1 @ 0xF6C;
char SSP2CON2 @ 0xF6B;
char CMSTAT   @ 0xF6A;
char PMADDRH  @ 0xF69;
char PMADDRL  @ 0xF68;
char PMDIN1H  @ 0xF67;
char PMDIN1L  @ 0xF66;
char UCON     @ 0xF65;
char USTAT    @ 0xF64;
char UEIR     @ 0xF63;
char UIR      @ 0xF62;
char UFRMH    @ 0xF61;
char UFRML    @ 0xF60;
char UCFG     @ 0xF5F;
char UADDR    @ 0xF5E;
char UEIE     @ 0xF5D;
char UIE      @ 0xF5C;
char UEP15    @ 0xF5B;
char UEP14    @ 0xF5A;
char UEP13    @ 0xF59;
char UEP12    @ 0xF58;
char UEP11    @ 0xF57;
char UEP10    @ 0xF56;
char UEP9     @ 0xF55;
char UEP8     @ 0xF54;
char UEP7     @ 0xF53;
char UEP6     @ 0xF52;
char UEP5     @ 0xF51;
char UEP4     @ 0xF50;
char UEP3     @ 0xF4F;
char UEP2     @ 0xF4E;
char UEP1     @ 0xF4D;
char UEP0     @ 0xF4C;
char PMCONH   @ 0xF4B;
char PMCONL   @ 0xF4A;
char PMMODEH  @ 0xF49;
char PMMODEL  @ 0xF48;
char PMDOUT2H @ 0xF47;
char PMDOUT2L @ 0xF46;
char PMDIN2H  @ 0xF45;
char PMDIN2L  @ 0xF44;
char PMEH     @ 0xF43;
char PMEL     @ 0xF42;
char PMSTATH  @ 0xF41;
char PMSTATL  @ 0xF40;

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

bit ROSEL   @ REFOCON.4;
bit ROSSLP  @ REFOCON.5;
bit ROON    @ REFOCON.7;

bit C1CH0   @ CM1CON1.0;
bit C1CH1   @ CM1CON1.1;
bit C1REF   @ CM1CON1.2;
bit EV1POL0 @ CM1CON1.3;
bit EV1POL1 @ CM1CON1.4;
bit C1POL   @ CM1CON1.5;
bit C1OE    @ CM1CON1.6;
bit C1ON    @ CM1CON1.7;

bit C2CH0   @ CM2CON1.0;
bit C2CH1   @ CM2CON1.1;
bit C2REF   @ CM2CON1.2;
bit EV2POL0 @ CM2CON1.3;
bit EV2POL1 @ CM2CON1.4;
bit C2POL   @ CM2CON1.5;
bit C2OE    @ CM2CON1.6;
bit C2ON    @ CM2CON1.7;

bit BOR_    @ RCON.0;
bit POR_    @ RCON.1;
bit PD      @ RCON.2;
bit TO      @ RCON.3;
bit RI_     @ RCON.4;
bit CM_     @ RCON.5;
bit IPEN    @ RCON.7;

bit U1OD    @ ODCON2.0;
bit U2OD    @ ODCON2.1;

bit TMR1ON  @ T1CON.0;
bit TMR1CS  @ T1CON.1;
bit T1SYNC_ @ T1CON.2;
bit T1OSCEN @ T1CON.3;
bit T1CKPS0 @ T1CON.4;
bit T1CKPS1 @ T1CON.5;
bit T1RUN   @ T1CON.6;
bit RD16    @ T1CON.7;

bit SPI1OD  @ ODCON3.0;
bit SPI2OD  @ ODCON3.1;

bit PMPTTL  @ PADCFG1.0;

bit WM0     @ MEMCON.0;
bit WM1     @ MEMCON.1;
bit WAIT0   @ MEMCON.4;
bit WAIT1   @ MEMCON.5;
bit EBDIS   @ MEMCON.7;

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
bit ADSHR   @ WDTCON.4;
bit REGSLP  @ WDTCON.7;

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

bit PSS2BD0 @ ECCP2AS.0;
bit PSS2BD1 @ ECCP2AS.1;
bit PSS2AC0 @ ECCP2AS.2;
bit PSS2AC1 @ ECCP2AS.3;
bit ECCP2AS0 @ ECCP2AS.4;
bit ECCP2AS1 @ ECCP2AS.5;
bit ECCP2AS2 @ ECCP2AS.6;
bit ECCP2ASE @ ECCP2AS.7;

bit P2RSEN  @ ECCP2DEL.7;

bit CCP2Y   @ CCP2CON.4;
bit CCP2X   @ CCP2CON.5;
bit P2M0    @ CCP2CON.6;
bit P2M1    @ CCP2CON.7;

bit PSS3BD0 @ ECCP3AS.0;
bit PSS3BD1 @ ECCP3AS.1;
bit PSS3AC0 @ ECCP3AS.2;
bit PSS3AC1 @ ECCP3AS.3;
bit ECCP3AS0 @ ECCP3AS.4;
bit ECCP3AS1 @ ECCP3AS.5;
bit ECCP3AS2 @ ECCP3AS.6;
bit ECCP3ASE @ ECCP3AS.7;

bit P3RSEN  @ ECCP3DEL.7;

bit CCP3Y   @ CCP3CON.4;
bit CCP3X   @ CCP3CON.5;
bit P3M0    @ CCP3CON.6;
bit P3M1    @ CCP3CON.7;

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

bit CCP3IP  @ IPR3.0;
bit CCP4IP  @ IPR3.1;
bit CCP5IP  @ IPR3.2;
bit TMR4IP  @ IPR3.3;
bit TX2IP   @ IPR3.4;
bit RC2IP   @ IPR3.5;
bit BCL2IP  @ IPR3.6;
bit SSP2IP  @ IPR3.7;

bit CCP3IF  @ PIR3.0;
bit CCP4IF  @ PIR3.1;
bit CCP5IF  @ PIR3.2;
bit TMR4IF  @ PIR3.3;
bit TX2IF   @ PIR3.4;
bit RC2IF   @ PIR3.5;
bit BCL2IF  @ PIR3.6;
bit SSP2IF  @ PIR3.7;

bit CCP3IE  @ PIE3.0;
bit CCP4IE  @ PIE3.1;
bit CCP5IE  @ PIE3.2;
bit TMR4IE  @ PIE3.3;
bit TX2IE   @ PIE3.4;
bit RC2IE   @ PIE3.5;
bit BCL2IE  @ PIE3.6;
bit SSP2IE  @ PIE3.7;

bit CCP2IP  @ IPR2.0;
bit TMR3IP  @ IPR2.1;
bit LVDIP   @ IPR2.2;
bit BCL1IP  @ IPR2.3;
bit USBIP   @ IPR2.4;
bit CM1IP   @ IPR2.5;
bit CM2IP   @ IPR2.6;
bit OSCFIP  @ IPR2.7;

bit CCP2IF  @ PIR2.0;
bit TMR3IF  @ PIR2.1;
bit LVDIF   @ PIR2.2;
bit BCL1IF  @ PIR2.3;
bit USBIF   @ PIR2.4;
bit CM1IF   @ PIR2.5;
bit CM2IF   @ PIR2.6;
bit OSCFIF  @ PIR2.7;

bit CCP2IE  @ PIE2.0;
bit TMR3IE  @ PIE2.1;
bit LVDIE   @ PIE2.2;
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
bit PMPIP   @ IPR1.7;

bit TMR1IF  @ PIR1.0;
bit TMR2IF  @ PIR1.1;
bit CCP1IF  @ PIR1.2;
bit SSP1IF  @ PIR1.3;
bit TX1IF   @ PIR1.4;
bit RC1IF   @ PIR1.5;
bit ADIF    @ PIR1.6;
bit PMPIF   @ PIR1.7;

bit TMR1IE  @ PIE1.0;
bit TMR2IE  @ PIE1.1;
bit CCP1IE  @ PIE1.2;
bit SSP1IE  @ PIE1.3;
bit TX1IE   @ PIE1.4;
bit RC1IE   @ PIE1.5;
bit ADIE    @ PIE1.6;
bit PMPIE   @ PIE1.7;

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

bit RJPU    @ PORTG.5;
bit REPU    @ PORTG.6;
bit RDPU    @ PORTG.7;

bit ABDEN1  @ BAUDCON1.0;
bit WUE1    @ BAUDCON1.1;
bit BRG16_1 @ BAUDCON1.3;
bit SCKP1   @ BAUDCON1.4;
bit DTRXP1  @ BAUDCON1.5;
bit RCIDL1  @ BAUDCON1.6;
bit ABDOVF1 @ BAUDCON1.7;

bit ABDEN2  @ BAUDCON2.0;
bit WUE2    @ BAUDCON2.1;
bit BRG16_2 @ BAUDCON2.3;
bit SCKP2   @ BAUDCON2.4;
bit DTRXP2  @ BAUDCON2.5;
bit RCIDL2  @ BAUDCON2.6;
bit ABDOVF2 @ BAUDCON2.7;

bit TMR3ON  @ T3CON.0;
bit TMR3CS  @ T3CON.1;
bit T3SYNC_ @ T3CON.2;
bit T3CCP1  @ T3CON.3;
bit T3CKPS0 @ T3CON.4;
bit T3CKPS1 @ T3CON.5;
bit T3CCP2  @ T3CON.6;
bit T3RD16  @ T3CON.7;

bit CVRSS   @ CVRCON.4;
bit CVRR    @ CVRCON.5;
bit CVROE   @ CVRCON.6;
bit CVREN   @ CVRCON.7;

bit T4CKPS0 @ T4CON.0;
bit T4CKPS1 @ T4CON.1;
bit TMR4ON  @ T4CON.2;

bit DCCP4Y  @ CCP4CON.4;
bit DCCP4X  @ CCP4CON.5;

bit DCCP5Y  @ CCP5CON.4;
bit DCCP5X  @ CCP5CON.5;

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

bit PTRDEN  @ PMCONH.0;
bit PTWREN  @ PMCONH.1;
bit PTBEEN  @ PMCONH.2;
bit ADRMUX0 @ PMCONH.3;
bit ADRMUX1 @ PMCONH.4;
bit PSIDL   @ PMCONH.5;
bit PMPEN   @ PMCONH.7;

bit RDSP    @ PMCONL.0;
bit WRSP    @ PMCONL.1;
bit BEP     @ PMCONL.2;
bit CS1P    @ PMCONL.3;
bit CS2P    @ PMCONL.4;
bit ALP     @ PMCONL.5;
bit CSF0    @ PMCONL.6;
bit CSF1    @ PMCONL.7;

bit MODE0   @ PMMODEH.0;
bit MODE1   @ PMMODEH.1;
bit MODE16  @ PMMODEH.2;
bit INCM0   @ PMMODEH.3;
bit INCM1   @ PMMODEH.4;
bit IRQM0   @ PMMODEH.5;
bit IRQM1   @ PMMODEH.6;
bit BUSY    @ PMMODEH.7;

bit WAITE0  @ PMMODEL.0;
bit WAITE1  @ PMMODEL.1;
bit WAITM0  @ PMMODEL.2;
bit WAITM1  @ PMMODEL.3;
bit WAITM2  @ PMMODEL.4;
bit WAITM3  @ PMMODEL.5;
bit WAITB0  @ PMMODEL.6;
bit WAITB1  @ PMMODEL.7;

bit IB0F    @ PMSTATH.0;
bit IB1F    @ PMSTATH.1;
bit IB2F    @ PMSTATH.2;
bit IB3F    @ PMSTATH.3;
bit IBOV    @ PMSTATH.6;
bit IBF     @ PMSTATH.7;

bit OB0E    @ PMSTATL.0;
bit OB1E    @ PMSTATL.1;
bit OB2E    @ PMSTATL.2;
bit OB3E    @ PMSTATL.3;
bit OBUF    @ PMSTATL.6;
bit OBE     @ PMSTATL.7;
