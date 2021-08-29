// Header file
#pragma chip PIC18F13K50, core 16, code 4096, ram 0 : 0x2FF

#ifdef ICD2_DEBUG
 #pragma stackLevels 29   // reserve two levels for debugging
#endif

// Extended Instruction Set

#pragma accessGPR 0x60

char unusedBank1[256] @ 0x100;


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
char CCPR1H   @ 0xFBF;
char CCPR1L   @ 0xFBE;
char CCP1CON  @ 0xFBD;
char REFCON2  @ 0xFBC;
char REFCON1  @ 0xFBB;
char REFCON0  @ 0xFBA;
char PSTRCON  @ 0xFB9;
char BAUDCON  @ 0xFB8;
char PWM1CON  @ 0xFB7;
char ECCP1AS  @ 0xFB6;

char TMR3H    @ 0xFB3;
char TMR3L    @ 0xFB2;
char T3CON    @ 0xFB1;
char SPBRGH   @ 0xFB0;
char SPBRG    @ 0xFAF;
char RCREG    @ 0xFAE;
char TXREG    @ 0xFAD;
char TXSTA    @ 0xFAC;
char RCSTA    @ 0xFAB;
char EEADRH   @ 0xFAA;
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

char TRISC    @ 0xF94;
char TRISB    @ 0xF93;
char TRISA    @ 0xF92;

char LATC     @ 0xF8B;
char LATB     @ 0xF8A;
char LATA     @ 0xF89;

char PORTC    @ 0xF82;
char PORTB    @ 0xF81;
char PORTA    @ 0xF80;
char ANSELH   @ 0xF7F;
char ANSEL    @ 0xF7E;

char IOCB     @ 0xF7A;
char IOCA     @ 0xF79;
char WPUB     @ 0xF78;
char WPUA     @ 0xF77;
char SLRCON   @ 0xF76;

char SSPMASK  @ 0xF6F;

char CM1CON0  @ 0xF6D;
char CM2CON1  @ 0xF6C;
char CM2CON0  @ 0xF6B;

char SRCON1   @ 0xF69;
char SRCON0   @ 0xF68;

char UCON     @ 0xF64;
char USTAT    @ 0xF63;
char UIR      @ 0xF62;
char UCFG     @ 0xF61;
char UIE      @ 0xF60;
char UEIR     @ 0xF5F;
char UFRMH    @ 0xF5E;
char UFRML    @ 0xF5D;
char UADDR    @ 0xF5C;
char UEIE     @ 0xF5B;
char UEP7     @ 0xF5A;
char UEP6     @ 0xF59;
char UEP5     @ 0xF58;
char UEP4     @ 0xF57;
char UEP3     @ 0xF56;
char UEP2     @ 0xF55;
char UEP1     @ 0xF54;
char UEP0     @ 0xF53;

bit RABIF   @ INTCON.0;
bit INT0IF  @ INTCON.1;
bit TMR0IF  @ INTCON.2;
bit RABIE   @ INTCON.3;
bit INT0IE  @ INTCON.4;
bit TMR0IE  @ INTCON.5;
bit PEIE    @ INTCON.6;
bit GIEL    @ INTCON.6;
bit GIE     @ INTCON.7;
bit GIEH    @ INTCON.7;

bit RABIP   @ INTCON2.0;
bit TMR0IP  @ INTCON2.2;
bit INTEDG2 @ INTCON2.4;
bit INTEDG1 @ INTCON2.5;
bit INTEDG0 @ INTCON2.6;
bit RABPU_  @ INTCON2.7;

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

bit LFIOFS  @ OSCCON2.0;
bit HFIOFL  @ OSCCON2.1;
bit PRI_SD  @ OSCCON2.2;

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

bit NVCFG0  @ ADCON1.0;
bit NVCFG1  @ ADCON1.1;
bit PVCFG0  @ ADCON1.2;
bit PVCFG1  @ ADCON1.3;

bit ADCS0   @ ADCON2.0;
bit ADCS1   @ ADCON2.1;
bit ADCS2   @ ADCON2.2;
bit ADFM    @ ADCON2.7;

bit DC1B0   @ CCP1CON.4;
bit DC1B1   @ CCP1CON.5;
bit P1M0    @ CCP1CON.6;
bit P1M1    @ CCP1CON.7;

bit D1NSS   @ REFCON1.0;
bit D1PSS0  @ REFCON1.2;
bit D1PSS1  @ REFCON1.3;
bit DAC1OE  @ REFCON1.5;
bit D1LPS   @ REFCON1.6;
bit D1EN    @ REFCON1.7;

bit TSRS    @ REFCON0.2;
bit TSEN    @ REFCON0.3;
bit FVR1S0  @ REFCON0.4;
bit FVR1S1  @ REFCON0.5;
bit FVR1ST  @ REFCON0.6;
bit FVR1EN  @ REFCON0.7;

bit STRA    @ PSTRCON.0;
bit STRB    @ PSTRCON.1;
bit STRC    @ PSTRCON.2;
bit STRD    @ PSTRCON.3;
bit STRSYNC @ PSTRCON.4;

bit ABDEN   @ BAUDCON.0;
bit WUE     @ BAUDCON.1;
bit BRG16   @ BAUDCON.3;
bit CKTXP   @ BAUDCON.4;
bit DTRXP   @ BAUDCON.5;
bit RCIDL   @ BAUDCON.6;
bit ABDOVF  @ BAUDCON.7;

bit PRSEN   @ PWM1CON.7;

bit PSSBD0  @ ECCP1AS.0;
bit PSSBD1  @ ECCP1AS.1;
bit PSSAC0  @ ECCP1AS.2;
bit PSSAC1  @ ECCP1AS.3;
bit ECCPAS0 @ ECCP1AS.4;
bit ECCPAS1 @ ECCP1AS.5;
bit ECCPAS2 @ ECCP1AS.6;
bit ECCPASE @ ECCP1AS.7;

bit TMR3ON  @ T3CON.0;
bit TMR3CS  @ T3CON.1;
bit T3SYNC_ @ T3CON.2;
bit T3CCP1  @ T3CON.3;
bit T3CKPS0 @ T3CON.4;
bit T3CKPS1 @ T3CON.5;
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

bit TMR3IP  @ IPR2.1;
bit USBIP   @ IPR2.2;
bit BCLIP   @ IPR2.3;
bit EEIP    @ IPR2.4;
bit C2IP    @ IPR2.5;
bit C1IP    @ IPR2.6;
bit OSCFIP  @ IPR2.7;

bit TMR3IF  @ PIR2.1;
bit USBIF   @ PIR2.2;
bit BCLIF   @ PIR2.3;
bit EEIF    @ PIR2.4;
bit C2IF    @ PIR2.5;
bit C1IF    @ PIR2.6;
bit OSCFIF  @ PIR2.7;

bit TMR3IE  @ PIE2.1;
bit USBIE   @ PIE2.2;
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

bit SPLLEN  @ OSCTUNE.6;
bit INTSRC  @ OSCTUNE.7;

bit SLRA    @ SLRCON.0;
bit SLRB    @ SLRCON.1;
bit SLRC    @ SLRCON.2;

bit C1CH0   @ CM1CON0.0;
bit C1CH1   @ CM1CON0.1;
bit C1R     @ CM1CON0.2;
bit C1SP    @ CM1CON0.3;
bit C1POL   @ CM1CON0.4;
bit C1OE    @ CM1CON0.5;
bit C1OUT   @ CM1CON0.6;
bit C1ON    @ CM1CON0.7;

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

bit SRRC1E  @ SRCON1.0;
bit SRRC2E  @ SRCON1.1;
bit SRRCKE  @ SRCON1.2;
bit SRRPE   @ SRCON1.3;
bit SRSC1E  @ SRCON1.4;
bit SRSC2E  @ SRCON1.5;
bit SRSCKE  @ SRCON1.6;
bit SRSPE   @ SRCON1.7;

bit SRPR    @ SRCON0.0;
bit SRPS    @ SRCON0.1;
bit SRNQEN  @ SRCON0.2;
bit SRQEN   @ SRCON0.3;
bit SRCLK0  @ SRCON0.4;
bit SRCLK1  @ SRCON0.5;
bit SRCLK2  @ SRCON0.6;
bit SRLEN   @ SRCON0.7;

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
bit UPUEN   @ UCFG.4;
bit UTEYE   @ UCFG.7;

bit URSTIE  @ UIE.0;
bit UERRIE  @ UIE.1;
bit ACTVIE  @ UIE.2;
bit TRNIE   @ UIE.3;
bit IDLEIE  @ UIE.4;
bit STALLIE @ UIE.5;
bit SOFIE   @ UIE.6;

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
