// Header file
#ifndef ICD2_DEBUG
 #pragma chip PIC18F2553, core 16, code 16384, ram 0 : 0x7FF

#else
 #pragma chip PIC18F2553, core 16, code 0x3EE0, ram 0 : 0x7FF
 // NOTE: last 288 words are reserved for ICD2 debugging

 char reservedICD2[12] @ 0x3F4;  // reserved RAM for ICD2

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

char TMR0H   @ 0xFD7;
char TMR0L   @ 0xFD6;
char T0CON   @ 0xFD5;

char OSCCON  @ 0xFD3;
char HLVDCON @ 0xFD2;
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

char BAUDCON @ 0xFB8;
char ECCP1DEL @ 0xFB7;
char ECCP1AS @ 0xFB6;
char CVRCON  @ 0xFB5;
char CMCON   @ 0xFB4;
char TMR3H   @ 0xFB3;
char TMR3L   @ 0xFB2;
char T3CON   @ 0xFB1;
char SPBRGH  @ 0xFB0;
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

char IPR2    @ 0xFA2;
char PIR2    @ 0xFA1;
char PIE2    @ 0xFA0;
char IPR1    @ 0xF9F;
char PIR1    @ 0xF9E;
char PIE1    @ 0xF9D;

char OSCTUNE @ 0xF9B;

char TRISC   @ 0xF94;
char TRISB   @ 0xF93;
char TRISA   @ 0xF92;

char LATC    @ 0xF8B;
char LATB    @ 0xF8A;
char LATA    @ 0xF89;

char PORTC   @ 0xF82;
char PORTB   @ 0xF81;
char PORTA   @ 0xF80;

char UEP15   @ 0xF7F;
char UEP14   @ 0xF7E;
char UEP13   @ 0xF7D;
char UEP12   @ 0xF7C;
char UEP11   @ 0xF7B;
char UEP10   @ 0xF7A;
char UEP9    @ 0xF79;
char UEP8    @ 0xF78;
char UEP7    @ 0xF77;
char UEP6    @ 0xF76;
char UEP5    @ 0xF75;
char UEP4    @ 0xF74;
char UEP3    @ 0xF73;
char UEP2    @ 0xF72;
char UEP1    @ 0xF71;
char UEP0    @ 0xF70;
char UCFG    @ 0xF6F;
char UADDR   @ 0xF6E;
char UCON    @ 0xF6D;
char USTAT   @ 0xF6C;
char UEIE    @ 0xF6B;
char UEIR    @ 0xF6A;
char UIE     @ 0xF69;
char UIR     @ 0xF68;
char UFRMH   @ 0xF67;
char UFRML   @ 0xF66;


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

bit T0SE    @ T0CON.4;
bit T0CS    @ T0CON.5;
bit T08BIT  @ T0CON.6;
bit TMR0ON  @ T0CON.7;

bit SCS0    @ OSCCON.0;
bit SCS1    @ OSCCON.1;
bit FLTS    @ OSCCON.2;
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

bit DC2B0   @ CCP2CON.4;
bit DC2B1   @ CCP2CON.5;

bit ABDEN   @ BAUDCON.0;
bit WUE     @ BAUDCON.1;
bit BRG16   @ BAUDCON.3;
bit SCKP    @ BAUDCON.4;
bit RCMT    @ BAUDCON.6;
bit ABDOVF  @ BAUDCON.7;

bit PRSEN   @ ECCP1DEL.7;

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

bit TX9D   @ TXSTA.0;
bit TRMT   @ TXSTA.1;
bit BRGH   @ TXSTA.2;
bit SENDB  @ TXSTA.3;
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

bit RD     @ EECON1.0;
bit WR     @ EECON1.1;
bit WREN   @ EECON1.2;
bit WRERR  @ EECON1.3;
bit FREE   @ EECON1.4;
bit CFGS   @ EECON1.6;
bit EEPGD  @ EECON1.7;

bit CCP2IP  @ IPR2.0;
bit TMR3IP  @ IPR2.1;
bit LVDIP   @ IPR2.2;
bit BCLIP   @ IPR2.3;
bit EEIP    @ IPR2.4;
bit USBIP   @ IPR2.5;
bit CMIP    @ IPR2.6;
bit OSCFIP  @ IPR2.7;

bit CCP2IF  @ PIR2.0;
bit TMR3IF  @ PIR2.1;
bit LVDIF   @ PIR2.2;
bit BCLIF   @ PIR2.3;
bit EEIF    @ PIR2.4;
bit USBIF   @ PIR2.5;
bit CMIF    @ PIR2.6;
bit OSCFIF  @ PIR2.7;

bit CCP2IE  @ PIE2.0;
bit TMR3IE  @ PIE2.1;
bit LVDIE   @ PIE2.2;
bit BCLIE   @ PIE2.3;
bit EEIE    @ PIE2.4;
bit USBIE   @ PIE2.5;
bit CMIE    @ PIE2.6;
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

bit INTSRC  @ OSCTUNE.7;

bit UPP0    @ UCFG.0;
bit UPP1    @ UCFG.1;
bit FSEN    @ UCFG.2;
bit UTRDIS  @ UCFG.3;
bit UPUEN   @ UCFG.4;
bit UOEMON  @ UCFG.6;
bit UTEYE   @ UCFG.7;

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

bit PIDEE   @ UEIE.0;
bit CRC5EE  @ UEIE.1;
bit CRC16EE @ UEIE.2;
bit DFN8EE  @ UEIE.3;
bit BTOEE   @ UEIE.4;
bit BTSEE   @ UEIE.7;

bit PIDEF   @ UEIR.0;
bit CRC5EF  @ UEIR.1;
bit CRC16EF @ UEIR.2;
bit DFN8EF  @ UEIR.3;
bit BTOEF   @ UEIR.4;
bit BTSEF   @ UEIR.7;

bit URSTIE  @ UIE.0;
bit UERRIE  @ UIE.1;
bit ACTIVIE @ UIE.2;
bit TRNIE   @ UIE.3;
bit IDLEIE  @ UIE.4;
bit STALLIE @ UIE.5;
bit SOFIE   @ UIE.6;

bit URSTIF  @ UIR.0;
bit UERRIF  @ UIR.1;
bit ACTIVIF @ UIR.2;
bit TRNIF   @ UIR.3;
bit IDLEIF  @ UIR.4;
bit STALLIF @ UIR.5;
bit SOFIF   @ UIR.6;
