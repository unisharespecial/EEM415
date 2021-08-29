// Header file
#pragma chip PIC18F66J65, core 16, code 49152, ram 0 : 0xE7F

#ifdef ICD2_DEBUG
 char reservedICD2[12] @ 0xDF4;  // reserved RAM for ICD2

 #pragma stackLevels 29   // reserve two levels for debugging
#endif

// Extended Instruction Set

#pragma accessGPR 0x60

#pragma configMapCodeSpace 0xBFFC
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
char ECON1    @ 0xFD2;
char WDTCON   @ 0xFD1;
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
char CCPR3H   @ 0xFB9;
char CCPR3L   @ 0xFB8;
char CCP3CON  @ 0xFB7;
char ECCP1AS  @ 0xFB6;
char CVRCON   @ 0xFB5;
char CMCON    @ 0xFB4;
char TMR3H    @ 0xFB3;
char TMR3L    @ 0xFB2;
char T3CON    @ 0xFB1;
char PSPCON   @ 0xFB0;
char SPBRG1   @ 0xFAF;
char RCREG1   @ 0xFAE;
char TXREG1   @ 0xFAD;
char TXSTA1   @ 0xFAC;
char RCSTA1   @ 0xFAB;

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
char MEMCON   @ 0xF9C;
char OSCTUNE  @ 0xF9B;

char TRISG    @ 0xF98;
char TRISF    @ 0xF97;
char TRISE    @ 0xF96;
char TRISD    @ 0xF95;
char TRISC    @ 0xF94;
char TRISB    @ 0xF93;
char TRISA    @ 0xF92;

char LATG     @ 0xF8F;
char LATF     @ 0xF8E;
char LATE     @ 0xF8D;
char LATD     @ 0xF8C;
char LATC     @ 0xF8B;
char LATB     @ 0xF8A;
char LATA     @ 0xF89;

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
char ERDPTH   @ 0xF7B;
char ERDPTL   @ 0xF7A;
char ECCP1DEL @ 0xF79;
char TMR4     @ 0xF78;
char PR4      @ 0xF77;
char T4CON    @ 0xF76;
char CCPR4H   @ 0xF75;
char CCPR4L   @ 0xF74;
char CCP4CON  @ 0xF73;
char CCPR5H   @ 0xF72;
char CCPR5L   @ 0xF71;
char CCP5CON  @ 0xF70;
char SPBRG2   @ 0xF6F;
char RCREG2   @ 0xF6E;
char TXREG2   @ 0xF6D;
char TXSTA2   @ 0xF6C;
char RCSTA2   @ 0xF6B;
char ECCP3AS  @ 0xF6A;
char ECCP3DEL @ 0xF69;
char ECCP2AS  @ 0xF68;
char ECCP2DEL @ 0xF67;
char SSP2BUF  @ 0xF66;
char SSP2ADD  @ 0xF65;
char SSP2STAT @ 0xF64;
char SSP2CON1 @ 0xF63;
char SSP2CON2 @ 0xF62;
char EDATA    @ 0xF61;
char EIR      @ 0xF60;

char ECON2    @ 0xEFE;
char ESTAT    @ 0xEFD;

char EIE      @ 0xEFB;

char EDMACSH  @ 0xEF7;
char EDMACSL  @ 0xEF6;
char EDMADSTH @ 0xEF5;
char EDMADSTL @ 0xEF4;
char EDMANDH  @ 0xEF3;
char EDMANDL  @ 0xEF2;
char EDMASTH  @ 0xEF1;
char EDMASTL  @ 0xEF0;
char ERXWRPTH @ 0xEEF;
char ERXWRPTL @ 0xEEE;
char ERXRDPTH @ 0xEED;
char ERXRDPTL @ 0xEEC;
char ERXNDH   @ 0xEEB;
char ERXNDL   @ 0xEEA;
char ERXSTH   @ 0xEE9;
char ERXSTL   @ 0xEE8;
char ETXNDH   @ 0xEE7;
char ETXNDL   @ 0xEE6;
char ETXSTH   @ 0xEE5;
char ETXSTL   @ 0xEE4;
char EWRPTH   @ 0xEE3;
char EWRPTL   @ 0xEE2;

char EPKTCNT  @ 0xED9;
char ERXFCON  @ 0xED8;

char EPMOH    @ 0xED5;
char EPMOL    @ 0xED4;

char EPMCSH   @ 0xED1;
char EPMCSL   @ 0xED0;
char EPMM7    @ 0xECF;
char EPMM6    @ 0xECE;
char EPMM5    @ 0xECD;
char EPMM4    @ 0xECC;
char EPMM3    @ 0xECB;
char EPMM2    @ 0xECA;
char EPMM1    @ 0xEC9;
char EPMM0    @ 0xEC8;
char EHT7     @ 0xEC7;
char EHT6     @ 0xEC6;
char EHT5     @ 0xEC5;
char EHT4     @ 0xEC4;
char EHT3     @ 0xEC3;
char EHT2     @ 0xEC2;
char EHT1     @ 0xEC1;
char EHT0     @ 0xEC0;

char MIRDH    @ 0xEB9;
char MIRDL    @ 0xEB8;
char MIWRH    @ 0xEB7;
char MIWRL    @ 0xEB6;

char MIREGADR @ 0xEB4;

char MICMD    @ 0xEB2;

char MAMXFLH  @ 0xEAB;
char MAMXFLL  @ 0xEAA;

char MAIPGH   @ 0xEA7;
char MAIPGL   @ 0xEA6;

char MABBIPG  @ 0xEA4;
char MACON4   @ 0xEA3;
char MACON3   @ 0xEA2;

char MACON1   @ 0xEA0;

char EPAUSH   @ 0xE99;
char EPAUSL   @ 0xE98;
char EFLOCON  @ 0xE97;

char MISTAT   @ 0xE8A;

char MAADR2   @ 0xE85;
char MAADR1   @ 0xE84;
char MAADR4   @ 0xE83;
char MAADR3   @ 0xE82;
char MAADR6   @ 0xE81;
char MAADR5   @ 0xE80;

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

bit RXEN    @ ECON1.2;
bit TXRTS   @ ECON1.3;
bit CSUMEN  @ ECON1.4;
bit DMAST   @ ECON1.5;
bit RXRST   @ ECON1.6;
bit TXRST   @ ECON1.7;

bit SWDTEN  @ WDTCON.0;

bit BOR_    @ RCON.0;
bit POR_    @ RCON.1;
bit PD      @ RCON.2;
bit TO      @ RCON.3;
bit RI_     @ RCON.4;
bit CM_     @ RCON.5;
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
bit ADCAL   @ ADCON0.7;

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

bit DC3B0   @ CCP3CON.4;
bit DC3B1   @ CCP3CON.5;

bit PSS1BD0 @ ECCP1AS.0;
bit PSS1BD1 @ ECCP1AS.1;
bit PSS1AC0 @ ECCP1AS.2;
bit PSS1AC1 @ ECCP1AS.3;
bit ECCP1AS0 @ ECCP1AS.4;
bit ECCP1AS1 @ ECCP1AS.5;
bit ECCP1AS2 @ ECCP1AS.6;
bit ECCP1ASE @ ECCP1AS.7;

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

bit WR      @ EECON1.1;
bit WREN    @ EECON1.2;
bit WRERR   @ EECON1.3;
bit FREE    @ EECON1.4;

bit CCP3IP  @ IPR3.0;
bit CCP4IP  @ IPR3.1;
bit CCP5IP  @ IPR3.2;
bit TMR4IP  @ IPR3.3;

bit CCP3IF  @ PIR3.0;
bit CCP4IF  @ PIR3.1;
bit CCP5IF  @ PIR3.2;
bit TMR4IF  @ PIR3.3;

bit CCP3IE  @ PIE3.0;
bit CCP4IE  @ PIE3.1;
bit CCP5IE  @ PIE3.2;
bit TMR4IE  @ PIE3.3;

bit CCP2IP  @ IPR2.0;
bit TMR3IP  @ IPR2.1;
bit BCL1IP  @ IPR2.3;
bit ETHIP   @ IPR2.5;
bit CMIP    @ IPR2.6;
bit OSCFIP  @ IPR2.7;

bit CCP2IF  @ PIR2.0;
bit TMR3IF  @ PIR2.1;
bit BCL1IF  @ PIR2.3;
bit ETHIF   @ PIR2.5;
bit CMIF    @ PIR2.6;
bit OSCFIF  @ PIR2.7;

bit CCP2IE  @ PIE2.0;
bit TMR3IE  @ PIE2.1;
bit BCL1IE  @ PIE2.3;
bit ETHIE   @ PIE2.5;
bit CMIE    @ PIE2.6;
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

bit WM0     @ MEMCON.0;
bit WM1     @ MEMCON.1;
bit WAIT0   @ MEMCON.4;
bit WAIT1   @ MEMCON.5;
bit EBDIS   @ MEMCON.7;

bit PPRE    @ OSCTUNE.4;
bit PPST0   @ OSCTUNE.5;
bit PLLEN   @ OSCTUNE.6;
bit PPST1   @ OSCTUNE.7;

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

bit P1RSEN  @ ECCP1DEL.7;

bit T4CKPS0 @ T4CON.0;
bit T4CKPS1 @ T4CON.1;
bit TMR4ON  @ T4CON.2;

bit DC4B0   @ CCP4CON.4;
bit DC4B1   @ CCP4CON.5;

bit DC5B0   @ CCP5CON.4;
bit DC5B1   @ CCP5CON.5;

bit TX9D2   @ TXSTA2.0;
bit TRMT2   @ TXSTA2.1;
bit BRGH2   @ TXSTA2.2;
bit SENDB2  @ TXSTA2.3;
bit SYNC2   @ TXSTA2.4;
bit TXEN2   @ TXSTA2.5;
bit TX9_2   @ TXSTA2.6;
bit CSRC2   @ TXSTA2.7;

bit RX9D2   @ RCSTA2.0;
bit OERR2   @ RCSTA2.1;
bit FERR2   @ RCSTA2.2;
bit ADDEN2  @ RCSTA2.3;
bit CREN2   @ RCSTA2.4;
bit SREN2   @ RCSTA2.5;
bit RC9_2   @ RCSTA2.6;
bit SPEN2   @ RCSTA2.7;

bit PSS3BD0 @ ECCP3AS.0;
bit PSS3BD1 @ ECCP3AS.1;
bit PSS3AC0 @ ECCP3AS.2;
bit PSS3AC1 @ ECCP3AS.3;
bit ECCP3AS0 @ ECCP3AS.4;
bit ECCP3AS1 @ ECCP3AS.5;
bit ECCP3AS2 @ ECCP3AS.6;
bit ECCP3ASE @ ECCP3AS.7;

bit P3RSEN  @ ECCP3DEL.7;

bit PSS2BD0 @ ECCP2AS.0;
bit PSS2BD1 @ ECCP2AS.1;
bit PSS2AC0 @ ECCP2AS.2;
bit PSS2AC1 @ ECCP2AS.3;
bit ECCP2AS0 @ ECCP2AS.4;
bit ECCP2AS1 @ ECCP2AS.5;
bit ECCP2AS2 @ ECCP2AS.6;
bit ECCP2ASE @ ECCP2AS.7;

bit P2RSEN  @ ECCP2DEL.7;

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

bit RXERIF  @ EIR.0;
bit TXERIF  @ EIR.1;
bit ETXIF   @ EIR.3;
bit LINKIF  @ EIR.4;
bit DMAIF   @ EIR.5;
bit PKTIF   @ EIR.6;

bit ETHEN   @ ECON2.5;
bit PKTDEC  @ ECON2.6;
bit AUTOINC @ ECON2.7;

bit PHYRDY  @ ESTAT.0;
bit TXABRT  @ ESTAT.1;
bit RXBUSY  @ ESTAT.2;
bit BUFER   @ ESTAT.6;

bit RXERIE  @ EIE.0;
bit TXERIE  @ EIE.1;
bit ETXIE   @ EIE.3;
bit LINKIE  @ EIE.4;
bit DMAIE   @ EIE.5;
bit PKTIE   @ EIE.6;

bit BCEN    @ ERXFCON.0;
bit MCEN    @ ERXFCON.1;
bit HTEN    @ ERXFCON.2;
bit MPEN    @ ERXFCON.3;
bit PMEN    @ ERXFCON.4;
bit CRCEN   @ ERXFCON.5;
bit ANDOR   @ ERXFCON.6;
bit UCEN    @ ERXFCON.7;

bit MIIRD   @ MICMD.0;
bit MIISCAN @ MICMD.1;

bit DEFER   @ MACON4.6;

bit FULDPX  @ MACON3.0;
bit FRMLNEN @ MACON3.1;
bit HFRMEN  @ MACON3.2;
bit PHDREN  @ MACON3.3;
bit TXCRCEN @ MACON3.4;
bit PADCFG0 @ MACON3.5;
bit PADCFG1 @ MACON3.6;
bit PADCFG2 @ MACON3.7;

bit MARXEN  @ MACON1.0;
bit PASSALL @ MACON1.1;
bit RXPAUS  @ MACON1.2;
bit TXPAUS  @ MACON1.3;

bit FCEN0   @ EFLOCON.0;
bit FCEN1   @ EFLOCON.1;

bit BUSY    @ MISTAT.0;
bit SCAN    @ MISTAT.1;
bit NVALID  @ MISTAT.2;
