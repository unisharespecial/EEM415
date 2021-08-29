// Header file
#pragma chip PIC18F25K50, core 16, code 16384, ram 0 : 0x7FF  // 2048 byte

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
char T1GCON   @ 0xFCC;
char SSP1CON3 @ 0xFCB;
char SSP1MSK  @ 0xFCA;
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
char TMR2     @ 0xFBC;
char PR2      @ 0xFBB;
char T2CON    @ 0xFBA;
char PSTR1CON @ 0xFB9;
char BAUDCON1 @ 0xFB8;
char PWM1CON  @ 0xFB7;
char ECCP1AS  @ 0xFB6;
char ACTCON   @ 0xFB5;
char T3GCON   @ 0xFB4;
char TMR3H    @ 0xFB3;
char TMR3L    @ 0xFB2;
char T3CON    @ 0xFB1;
char SPBRGH1  @ 0xFB0;
char SPBRG1   @ 0xFAF;
char RCREG1   @ 0xFAE;
char TXREG1   @ 0xFAD;
char TXSTA1   @ 0xFAC;
char RCSTA1   @ 0xFAB;

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
char HLVDCON  @ 0xF9C;
char OSCTUNE  @ 0xF9B;
char CM2CON1  @ 0xF9A;
char CM2CON0  @ 0xF99;
char CM1CON0  @ 0xF98;
char CCP2CON  @ 0xF97;

char TRISC    @ 0xF94;
char TRISB    @ 0xF93;
char TRISA    @ 0xF92;
char CCPR2H   @ 0xF91;
char CCPR2L   @ 0xF90;
char CTMUCONH @ 0xF8F;
char CTMUCONL @ 0xF8E;

char LATC     @ 0xF8B;
char LATB     @ 0xF8A;
char LATA     @ 0xF89;
char CTMUICON @ 0xF88;
char IOCC     @ 0xF87;
char IOCB     @ 0xF86;
char WPUB     @ 0xF85;
char PORTE    @ 0xF84;

char PORTC    @ 0xF82;
char PORTB    @ 0xF81;
char PORTA    @ 0xF80;
char PMD1     @ 0xF7F;
char PMD0     @ 0xF7E;
char VREFCON0 @ 0xF7D;
char VREFCON1 @ 0xF7C;
char VREFCON2 @ 0xF7B;
char SLRCON   @ 0xF7A;
char UEP15    @ 0xF79;
char UEP14    @ 0xF78;
char UEP13    @ 0xF77;
char UEP12    @ 0xF76;
char UEP11    @ 0xF75;
char UEP10    @ 0xF74;
char UEP9     @ 0xF73;
char UEP8     @ 0xF72;
char UEP7     @ 0xF71;
char UEP6     @ 0xF70;
char UEP5     @ 0xF6F;
char UEP4     @ 0xF6E;
char UEP3     @ 0xF6D;
char UEP2     @ 0xF6C;
char UEP1     @ 0xF6B;
char UEP0     @ 0xF6A;
char UFRMH    @ 0xF69;
char UFRML    @ 0xF68;
char UEIR     @ 0xF67;
char UEIE     @ 0xF66;
char UIR      @ 0xF65;
char UIE      @ 0xF64;
char UADDR    @ 0xF63;
char UCFG     @ 0xF62;
char USTAT    @ 0xF61;
char UCON     @ 0xF60;

char ANSELC   @ 0xF5D;
char ANSELB   @ 0xF5C;
char ANSELA   @ 0xF5B;
char VREGCON  @ 0xF5A;
char CCPTMRS  @ 0xF59;
char SRCON0   @ 0xF58;
char SRCON1   @ 0xF57;

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
bit HFIOFS  @ OSCCON.2;
bit OSTS    @ OSCCON.3;
bit IDLEN   @ OSCCON.7;

bit LFIOFS  @ OSCCON2.0;
bit HFIOFR  @ OSCCON2.1;
bit PRISD   @ OSCCON2.2;
bit SOSCGO  @ OSCCON2.3;
bit PLLEN   @ OSCCON2.4;
bit INTSRC  @ OSCCON2.5;
bit SOSCRUN @ OSCCON2.6;
bit PLLRDY  @ OSCCON2.7;

bit SWDTEN  @ WDTCON.0;

bit BOR_    @ RCON.0;
bit POR_    @ RCON.1;
bit PD      @ RCON.2;
bit TO      @ RCON.3;
bit RI_     @ RCON.4;
bit SBOREN  @ RCON.6;
bit IPEN    @ RCON.7;

bit TMR1ON  @ T1CON.0;
bit RD16    @ T1CON.1;
bit T1SYNC_ @ T1CON.2;
bit T1SOSCEN @ T1CON.3;
bit T1CKPS0 @ T1CON.4;
bit T1CKPS1 @ T1CON.5;
bit TMR1CS0 @ T1CON.6;
bit TMR1CS1 @ T1CON.7;

bit T1GSS0  @ T1GCON.0;
bit T1GSS1  @ T1GCON.1;
bit T1GVAL  @ T1GCON.2;
bit T1GGO   @ T1GCON.3;
bit T1GSPM  @ T1GCON.4;
bit T1GTM   @ T1GCON.5;
bit T1GPOL  @ T1GCON.6;
bit TMR1GE  @ T1GCON.7;

bit DHEN    @ SSP1CON3.0;
bit AHEN    @ SSP1CON3.1;
bit SBCDE   @ SSP1CON3.2;
bit SDAHT   @ SSP1CON3.3;
bit BOEN    @ SSP1CON3.4;
bit SCIE    @ SSP1CON3.5;
bit PCIE    @ SSP1CON3.6;
bit ACKTIM  @ SSP1CON3.7;

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

bit NVCFG0  @ ADCON1.0;
bit NVCFG1  @ ADCON1.1;
bit PVCFG0  @ ADCON1.2;
bit PVCFG1  @ ADCON1.3;
bit TRIGSEL @ ADCON1.7;

bit ADCS0   @ ADCON2.0;
bit ADCS1   @ ADCON2.1;
bit ADCS2   @ ADCON2.2;
bit ADFM    @ ADCON2.7;

bit T2CKPS0 @ T2CON.0;
bit T2CKPS1 @ T2CON.1;
bit TMR2ON  @ T2CON.2;

bit STR1A   @ PSTR1CON.0;
bit STR1B   @ PSTR1CON.1;
bit STR1C   @ PSTR1CON.2;
bit STR1D   @ PSTR1CON.3;
bit STR1SYNC @ PSTR1CON.4;

bit ABDEN   @ BAUDCON1.0;
bit WUE     @ BAUDCON1.1;
bit BRG16   @ BAUDCON1.3;
bit TXCKP   @ BAUDCON1.4;
bit RXDTP   @ BAUDCON1.5;
bit RCIDL   @ BAUDCON1.6;
bit ABDOVF  @ BAUDCON1.7;

bit P1RSEN  @ PWM1CON.7;

bit ACTORS  @ ACTCON.1;
bit ACTLOCK @ ACTCON.3;
bit ACTSRC  @ ACTCON.4;
bit ACTUD   @ ACTCON.6;
bit ACTEN   @ ACTCON.7;

bit T3GSS0  @ T3GCON.0;
bit T3GSS1  @ T3GCON.1;
bit T3GVAL  @ T3GCON.2;
bit T3GGO   @ T3GCON.3;
bit T3GSPM  @ T3GCON.4;
bit T3GTM   @ T3GCON.5;
bit T3GPOL  @ T3GCON.6;
bit TMR3GE  @ T3GCON.7;

bit TMR3ON  @ T3CON.0;
bit T3RD16  @ T3CON.1;
bit T3SYNC_ @ T3CON.2;
bit T3SOSCEN @ T3CON.3;
bit T3CKPS0 @ T3CON.4;
bit T3CKPS1 @ T3CON.5;
bit TMR3CS0 @ T3CON.6;
bit TMR3CS1 @ T3CON.7;

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

bit RD      @ EECON1.0;
bit WR      @ EECON1.1;
bit WREN    @ EECON1.2;
bit WRERR   @ EECON1.3;
bit FREE    @ EECON1.4;
bit CFGS    @ EECON1.6;
bit EEPGD   @ EECON1.7;

bit TMR1GIP @ IPR3.0;
bit TMR3GIP @ IPR3.1;
bit USBIP   @ IPR3.2;
bit CTMUIP  @ IPR3.3;

bit TMR1GIF @ PIR3.0;
bit TMR3GIF @ PIR3.1;
bit USBIF   @ PIR3.2;
bit CTMUIF  @ PIR3.3;

bit TMR1GIE @ PIE3.0;
bit TMR3GIE @ PIE3.1;
bit USBIE   @ PIE3.2;
bit CTMUIE  @ PIE3.3;

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
bit ACTIP   @ IPR1.7;

bit TMR1IF  @ PIR1.0;
bit TMR2IF  @ PIR1.1;
bit CCP1IF  @ PIR1.2;
bit SSPIF   @ PIR1.3;
bit TXIF    @ PIR1.4;
bit RCIF    @ PIR1.5;
bit ADIF    @ PIR1.6;
bit ACTIF   @ PIR1.7;

bit TMR1IE  @ PIE1.0;
bit TMR2IE  @ PIE1.1;
bit CCP1IE  @ PIE1.2;
bit SSPIE   @ PIE1.3;
bit TXIE    @ PIE1.4;
bit RCIE    @ PIE1.5;
bit ADIE    @ PIE1.6;
bit ACTIE   @ PIE1.7;

bit HLVDEN  @ HLVDCON.4;
bit IRVST   @ HLVDCON.5;
bit BGVST   @ HLVDCON.6;
bit VDIRMAG @ HLVDCON.7;

bit SPLLMULT @ OSCTUNE.7;

bit C2SYNC  @ CM2CON1.0;
bit C1SYNC  @ CM2CON1.1;
bit C2HYS   @ CM2CON1.2;
bit C1HYS   @ CM2CON1.3;
bit C2RSEL  @ CM2CON1.4;
bit C1RSEL  @ CM2CON1.5;
bit MC2OUT  @ CM2CON1.6;
bit MC1OUT  @ CM2CON1.7;

bit C2CH0   @ CM2CON0.0;
bit C2CH1   @ CM2CON0.1;
bit C2R     @ CM2CON0.2;
bit C2SP    @ CM2CON0.3;
bit C2POL   @ CM2CON0.4;
bit C2OE    @ CM2CON0.5;
bit C2OUT   @ CM2CON0.6;
bit C2ON    @ CM2CON0.7;

bit C1CH0   @ CM1CON0.0;
bit C1CH1   @ CM1CON0.1;
bit C1R     @ CM1CON0.2;
bit C1SP    @ CM1CON0.3;
bit C1POL   @ CM1CON0.4;
bit C1OE    @ CM1CON0.5;
bit C1OUT   @ CM1CON0.6;
bit C1ON    @ CM1CON0.7;

bit CTTRIG  @ CTMUCONH.0;
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

bit CCP1MD  @ PMD1.0;
bit CCP2MD  @ PMD1.1;
bit ADCMD   @ PMD1.2;
bit CMP1MD  @ PMD1.3;
bit CMP2MD  @ PMD1.4;
bit CTMUMD  @ PMD1.5;
bit MSSPMD  @ PMD1.6;

bit TMR1MD  @ PMD0.0;
bit TMR2MD  @ PMD0.1;
bit TMR3MD  @ PMD0.2;
bit ACTMD   @ PMD0.4;
bit USBMD   @ PMD0.5;
bit UARTMD  @ PMD0.6;

bit FVRS0   @ VREFCON0.4;
bit FVRS1   @ VREFCON0.5;
bit FVRST   @ VREFCON0.6;
bit FVREN   @ VREFCON0.7;

bit DACNSS  @ VREFCON1.0;
bit DACPSS0 @ VREFCON1.2;
bit DACPSS1 @ VREFCON1.3;
bit DACOE   @ VREFCON1.5;
bit DACLPS  @ VREFCON1.6;
bit DACEN   @ VREFCON1.7;

bit SLRA    @ SLRCON.0;
bit SLRB    @ SLRCON.1;
bit SLRC    @ SLRCON.2;
bit SLRD    @ SLRCON.3;
bit SLRE    @ SLRCON.4;

bit PIDEF   @ UEIR.0;
bit CRC5EF  @ UEIR.1;
bit CRC16EF @ UEIR.2;
bit DFN8EF  @ UEIR.3;
bit BTOEF   @ UEIR.4;
bit BTSEF   @ UEIR.7;

bit PIDEE   @ UEIE.0;
bit CRC5EE  @ UEIE.1;
bit CRC16EE @ UEIE.2;
bit DFN8EE  @ UEIE.3;
bit BTOEE   @ UEIE.4;
bit BTSEE   @ UEIE.7;

bit URSTIF  @ UIR.0;
bit UERRIF  @ UIR.1;
bit ACTVIF  @ UIR.2;
bit TRNIF   @ UIR.3;
bit IDLEIF  @ UIR.4;
bit STALLIF @ UIR.5;
bit SOFIF   @ UIR.6;

bit URSTIE  @ UIE.0;
bit UERRIE  @ UIE.1;
bit ACTVIE  @ UIE.2;
bit TRNIE   @ UIE.3;
bit IDLEIE  @ UIE.4;
bit STALLIE @ UIE.5;
bit SOFIE   @ UIE.6;

bit PPB0    @ UCFG.0;
bit PPB1    @ UCFG.1;
bit FSEN    @ UCFG.2;
bit UTRDIS  @ UCFG.3;
bit UPUEN   @ UCFG.4;
bit UOEMON  @ UCFG.6;
bit UTEYE   @ UCFG.7;

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

bit SRPR    @ SRCON0.0;
bit SRPS    @ SRCON0.1;
bit SRNQEN  @ SRCON0.2;
bit SRQEN   @ SRCON0.3;
bit SRCLK0  @ SRCON0.4;
bit SRCLK1  @ SRCON0.5;
bit SRCLK2  @ SRCON0.6;
bit SRLEN   @ SRCON0.7;

bit SRRC1E  @ SRCON1.0;
bit SRRC2E  @ SRCON1.1;
bit SRRCKE  @ SRCON1.2;
bit SRRPE   @ SRCON1.3;
bit SRSC1E  @ SRCON1.4;
bit SRSC2E  @ SRCON1.5;
bit SRSCKE  @ SRCON1.6;
bit SRSPE   @ SRCON1.7;
