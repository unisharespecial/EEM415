// Header file
#pragma chip PIC18F86J93, core 16, code 32768, ram 0 : 0xF4F

#ifdef ICD2_DEBUG
 #pragma stackLevels 29   // reserve two levels for debugging
#endif

// Extended Instruction Set

#pragma accessGPR 0x60

#pragma configMapCodeSpace 0x7FFC
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
char LCDREG   @ 0xFD2;
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
char LCDDATA4 @ 0xFBF;
char LCDDATA3 @ 0xFBE;
char LCDDATA2 @ 0xFBD;
char LCDDATA1 @ 0xFBC;
char LCDDATA0 @ 0xFBB;
char LCDSE5   @ 0xFBA;
char LCDSE4   @ 0xFB9;
char LCDSE3   @ 0xFB8;
char LCDSE2   @ 0xFB7;
char LCDSE1   @ 0xFB6;
char CVRCON   @ 0xFB5;
char CMCON    @ 0xFB4;
char TMR3H    @ 0xFB3;
char TMR3L    @ 0xFB2;
char T3CON    @ 0xFB1;

char SPBRG1   @ 0xFAF;
char RCREG1   @ 0xFAE;
char TXREG1   @ 0xFAD;
char TXSTA1   @ 0xFAC;
char RCSTA1   @ 0xFAB;
char LCDPS    @ 0xFAA;
char LCDSE0   @ 0xFA9;
char LCDCON   @ 0xFA8;
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
char LCDDATA23 @ 0xF7D;
char LCDDATA22 @ 0xF7C;
char LCDDATA21 @ 0xF7B;
char LCDDATA20 @ 0xF7A;
char LCDDATA19 @ 0xF79;
char LCDDATA18 @ 0xF78;
char LCDDATA17 @ 0xF77;
char LCDDATA16 @ 0xF76;
char LCDDATA15 @ 0xF75;
char LCDDATA14 @ 0xF74;
char LCDDATA13 @ 0xF73;
char LCDDATA12 @ 0xF72;
char LCDDATA11 @ 0xF71;
char LCDDATA10 @ 0xF70;
char LCDDATA9 @ 0xF6F;
char LCDDATA8 @ 0xF6E;
char LCDDATA7 @ 0xF6D;
char LCDDATA6 @ 0xF6C;
char LCDDATA5 @ 0xF6B;
char CCPR1H   @ 0xF6A;
char CCPR1L   @ 0xF69;
char CCP1CON  @ 0xF68;
char CCPR2H   @ 0xF67;
char CCPR2L   @ 0xF66;
char CCP2CON  @ 0xF65;
char SPBRG2   @ 0xF64;
char RCREG2   @ 0xF63;
char TXREG2   @ 0xF62;
char TXSTA2   @ 0xF61;
char RCSTA2   @ 0xF60;
char RTCCFG   @ 0xF5F;
char RTCCAL   @ 0xF5E;
char RTCVALH  @ 0xF5D;
char RTCVALL  @ 0xF5C;
char ALRMCFG  @ 0xF5B;
char ALRMRPT  @ 0xF5A;
char ALRMVALH @ 0xF59;
char ALRMVALL @ 0xF58;
char CTMUCONH @ 0xF57;
char CTMUCONL @ 0xF56;
char CTMUICON @ 0xF55;
char PADCFG1  @ 0xF54;

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
bit IOFS    @ OSCCON.2;
bit OSTS    @ OSCCON.3;
bit IDLEN   @ OSCCON.7;

bit CKSEL0  @ LCDREG.0;
bit CKSEL1  @ LCDREG.1;
bit MODE13  @ LCDREG.2;
bit BIAS0   @ LCDREG.3;
bit BIAS1   @ LCDREG.4;
bit BIAS2   @ LCDREG.5;
bit CPEN    @ LCDREG.6;

bit SWDTEN  @ WDTCON.0;
bit REGSLP  @ WDTCON.7;

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
bit ADCAL   @ ADCON0.7;

bit VCFG0   @ ADCON1.4;
bit VCFG1   @ ADCON1.5;
bit TRIGSEL @ ADCON1.7;

bit ADCS0   @ ADCON2.0;
bit ADCS1   @ ADCON2.1;
bit ADCS2   @ ADCON2.2;
bit ADFM    @ ADCON2.7;

bit S32C0   @ LCDDATA4.0;
bit S33C0   @ LCDDATA4.1;
bit S34C0   @ LCDDATA4.2;
bit S35C0   @ LCDDATA4.3;
bit S36C0   @ LCDDATA4.4;
bit S37C0   @ LCDDATA4.5;
bit S38C0   @ LCDDATA4.6;
bit S39C0   @ LCDDATA4.7;

bit S24C0   @ LCDDATA3.0;
bit S25C0   @ LCDDATA3.1;
bit S26C0   @ LCDDATA3.2;
bit S27C0   @ LCDDATA3.3;
bit S28C0   @ LCDDATA3.4;
bit S29C0   @ LCDDATA3.5;
bit S30C0   @ LCDDATA3.6;
bit S31C0   @ LCDDATA3.7;

bit S16C0   @ LCDDATA2.0;
bit S17C0   @ LCDDATA2.1;
bit S18C0   @ LCDDATA2.2;
bit S19C0   @ LCDDATA2.3;
bit S20C0   @ LCDDATA2.4;
bit S21C0   @ LCDDATA2.5;
bit S22C0   @ LCDDATA2.6;
bit S23C0   @ LCDDATA2.7;

bit S08C0   @ LCDDATA1.0;
bit S09C0   @ LCDDATA1.1;
bit S10C0   @ LCDDATA1.2;
bit S11C0   @ LCDDATA1.3;
bit S12C0   @ LCDDATA1.4;
bit S13C0   @ LCDDATA1.5;
bit S14C0   @ LCDDATA1.6;
bit S15C0   @ LCDDATA1.7;

bit S00C0   @ LCDDATA0.0;
bit S01C0   @ LCDDATA0.1;
bit S02C0   @ LCDDATA0.2;
bit S03C0   @ LCDDATA0.3;
bit S04C0   @ LCDDATA0.4;
bit S05C0   @ LCDDATA0.5;
bit S06C0   @ LCDDATA0.6;
bit S07C0   @ LCDDATA0.7;

bit SE40    @ LCDSE5.0;
bit SE41    @ LCDSE5.1;
bit SE42    @ LCDSE5.2;
bit SE43    @ LCDSE5.3;
bit SE44    @ LCDSE5.4;
bit SE45    @ LCDSE5.5;
bit SE46    @ LCDSE5.6;
bit SE47    @ LCDSE5.7;

bit SE32    @ LCDSE4.0;
bit SE33    @ LCDSE4.1;
bit SE34    @ LCDSE4.2;
bit SE35    @ LCDSE4.3;
bit SE36    @ LCDSE4.4;
bit SE37    @ LCDSE4.5;
bit SE38    @ LCDSE4.6;
bit SE39    @ LCDSE4.7;

bit SE24    @ LCDSE3.0;
bit SE25    @ LCDSE3.1;
bit SE26    @ LCDSE3.2;
bit SE27    @ LCDSE3.3;
bit SE28    @ LCDSE3.4;
bit SE29    @ LCDSE3.5;
bit SE30    @ LCDSE3.6;
bit SE31    @ LCDSE3.7;

bit SE16    @ LCDSE2.0;
bit SE17    @ LCDSE2.1;
bit SE18    @ LCDSE2.2;
bit SE19    @ LCDSE2.3;
bit SE20    @ LCDSE2.4;
bit SE21    @ LCDSE2.5;
bit SE22    @ LCDSE2.6;
bit SE23    @ LCDSE2.7;

bit SE08    @ LCDSE1.0;
bit SE09    @ LCDSE1.1;
bit SE10    @ LCDSE1.2;
bit SE11    @ LCDSE1.3;
bit SE12    @ LCDSE1.4;
bit SE13    @ LCDSE1.5;
bit SE14    @ LCDSE1.6;
bit SE15    @ LCDSE1.7;

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

bit WA      @ LCDPS.4;
bit LCDA    @ LCDPS.5;
bit BIASMD  @ LCDPS.6;
bit WFT     @ LCDPS.7;

bit SE00    @ LCDSE0.0;
bit SE01    @ LCDSE0.1;
bit SE02    @ LCDSE0.2;
bit SE03    @ LCDSE0.3;
bit SE04    @ LCDSE0.4;
bit SE05    @ LCDSE0.5;
bit SE06    @ LCDSE0.6;
bit SE07    @ LCDSE0.7;

bit LMUX0   @ LCDCON.0;
bit LMUX1   @ LCDCON.1;
bit CS0     @ LCDCON.2;
bit CS1     @ LCDCON.3;
bit WERR    @ LCDCON.5;
bit SLPEN   @ LCDCON.6;
bit LCDEN   @ LCDCON.7;

bit WR      @ EECON1.1;
bit WREN    @ EECON1.2;
bit WRERR   @ EECON1.3;
bit FREE    @ EECON1.4;
bit WPROG   @ EECON1.5;

bit RTCCIP  @ IPR3.0;
bit CCP1IP  @ IPR3.1;
bit CCP2IP  @ IPR3.2;
bit CTMUIP  @ IPR3.3;
bit TX2IP   @ IPR3.4;
bit RC2IP   @ IPR3.5;
bit LCDIP   @ IPR3.6;

bit RTCCIF  @ PIR3.0;
bit CCP1IF  @ PIR3.1;
bit CCP2IF  @ PIR3.2;
bit CTMUIF  @ PIR3.3;
bit TX2IF   @ PIR3.4;
bit RC2IF   @ PIR3.5;
bit LCDIF   @ PIR3.6;

bit RTCCIE  @ PIE3.0;
bit CCP1IE  @ PIE3.1;
bit CCP2IE  @ PIE3.2;
bit CTMUIE  @ PIE3.3;
bit TX2IE   @ PIE3.4;
bit RC2IE   @ PIE3.5;
bit LCDIE   @ PIE3.6;

bit TMR3IP  @ IPR2.1;
bit LVDIP   @ IPR2.2;
bit BCLIP   @ IPR2.3;
bit CMIP    @ IPR2.6;
bit OSCFIP  @ IPR2.7;

bit TMR3IF  @ PIR2.1;
bit LVDIF   @ PIR2.2;
bit BCLIF   @ PIR2.3;
bit CMIF    @ PIR2.6;
bit OSCFIF  @ PIR2.7;

bit TMR3IE  @ PIE2.1;
bit LVDIE   @ PIE2.2;
bit BCLIE   @ PIE2.3;
bit CMIE    @ PIE2.6;
bit OSCFIE  @ PIE2.7;

bit TMR1IP  @ IPR1.0;
bit TMR2IP  @ IPR1.1;
bit SSPIP   @ IPR1.3;
bit TX1IP   @ IPR1.4;
bit RC1IP   @ IPR1.5;
bit ADIP    @ IPR1.6;

bit TMR1IF  @ PIR1.0;
bit TMR2IF  @ PIR1.1;
bit SSPIF   @ PIR1.3;
bit TX1IF   @ PIR1.4;
bit RC1IF   @ PIR1.5;
bit ADIF    @ PIR1.6;

bit TMR1IE  @ PIE1.0;
bit TMR2IE  @ PIE1.1;
bit SSPIE   @ PIE1.3;
bit TX1IE   @ PIE1.4;
bit RC1IE   @ PIE1.5;
bit ADIE    @ PIE1.6;

bit PLLEN   @ OSCTUNE.6;
bit INTSRC  @ OSCTUNE.7;

bit CCP1OD  @ TRISG.5;
bit CCP2OD  @ TRISG.6;
bit SPIOD   @ TRISG.7;

bit U1OD    @ LATG.6;
bit U2OD    @ LATG.7;

bit RJPU    @ PORTG.5;
bit REPU    @ PORTG.6;
bit RDPU    @ PORTG.7;

bit ABDEN   @ BAUDCON1.0;
bit WUE     @ BAUDCON1.1;
bit BRG16   @ BAUDCON1.3;
bit TXCKP   @ BAUDCON1.4;
bit RXDTP   @ BAUDCON1.5;
bit RCMT    @ BAUDCON1.6;
bit ABDOVF  @ BAUDCON1.7;

bit S40C3   @ LCDDATA23.0;
bit S41C3   @ LCDDATA23.1;
bit S42C3   @ LCDDATA23.2;
bit S43C3   @ LCDDATA23.3;
bit S44C3   @ LCDDATA23.4;
bit S45C3   @ LCDDATA23.5;
bit S46C3   @ LCDDATA23.6;
bit S47C3   @ LCDDATA23.7;

bit S32C3   @ LCDDATA22.0;
bit S33C3   @ LCDDATA22.1;
bit S34C3   @ LCDDATA22.2;
bit S35C3   @ LCDDATA22.3;
bit S36C3   @ LCDDATA22.4;
bit S37C3   @ LCDDATA22.5;
bit S38C3   @ LCDDATA22.6;
bit S39C3   @ LCDDATA22.7;

bit S24C3   @ LCDDATA21.0;
bit S25C3   @ LCDDATA21.1;
bit S26C3   @ LCDDATA21.2;
bit S27C3   @ LCDDATA21.3;
bit S28C3   @ LCDDATA21.4;
bit S29C3   @ LCDDATA21.5;
bit S30C3   @ LCDDATA21.6;
bit S31C3   @ LCDDATA21.7;

bit S16C3   @ LCDDATA20.0;
bit S17C3   @ LCDDATA20.1;
bit S18C3   @ LCDDATA20.2;
bit S19C3   @ LCDDATA20.3;
bit S20C3   @ LCDDATA20.4;
bit S21C3   @ LCDDATA20.5;
bit S22C3   @ LCDDATA20.6;
bit S23C3   @ LCDDATA20.7;

bit S08C3   @ LCDDATA19.0;
bit S09C3   @ LCDDATA19.1;
bit S10C3   @ LCDDATA19.2;
bit S11C3   @ LCDDATA19.3;
bit S12C3   @ LCDDATA19.4;
bit S13C3   @ LCDDATA19.5;
bit S14C3   @ LCDDATA19.6;
bit S15C3   @ LCDDATA19.7;

bit S00C3   @ LCDDATA18.0;
bit S01C3   @ LCDDATA18.1;
bit S02C3   @ LCDDATA18.2;
bit S03C3   @ LCDDATA18.3;
bit S04C3   @ LCDDATA18.4;
bit S05C3   @ LCDDATA18.5;
bit S06C3   @ LCDDATA18.6;
bit S07C3   @ LCDDATA18.7;

bit S40C2   @ LCDDATA17.0;
bit S41C2   @ LCDDATA17.1;
bit S42C2   @ LCDDATA17.2;
bit S43C2   @ LCDDATA17.3;
bit S44C2   @ LCDDATA17.4;
bit S45C2   @ LCDDATA17.5;
bit S46C2   @ LCDDATA17.6;
bit S47C2   @ LCDDATA17.7;

bit S32C2   @ LCDDATA16.0;
bit S33C2   @ LCDDATA16.1;
bit S34C2   @ LCDDATA16.2;
bit S35C2   @ LCDDATA16.3;
bit S36C2   @ LCDDATA16.4;
bit S37C2   @ LCDDATA16.5;
bit S38C2   @ LCDDATA16.6;
bit S39C2   @ LCDDATA16.7;

bit S24C2   @ LCDDATA15.0;
bit S25C2   @ LCDDATA15.1;
bit S26C2   @ LCDDATA15.2;
bit S27C2   @ LCDDATA15.3;
bit S28C2   @ LCDDATA15.4;
bit S29C2   @ LCDDATA15.5;
bit S30C2   @ LCDDATA15.6;
bit S31C2   @ LCDDATA15.7;

bit S16C2   @ LCDDATA14.0;
bit S17C2   @ LCDDATA14.1;
bit S18C2   @ LCDDATA14.2;
bit S19C2   @ LCDDATA14.3;
bit S20C2   @ LCDDATA14.4;
bit S21C2   @ LCDDATA14.5;
bit S22C2   @ LCDDATA14.6;
bit S23C2   @ LCDDATA14.7;

bit S08C2   @ LCDDATA13.0;
bit S09C2   @ LCDDATA13.1;
bit S10C2   @ LCDDATA13.2;
bit S11C2   @ LCDDATA13.3;
bit S12C2   @ LCDDATA13.4;
bit S13C2   @ LCDDATA13.5;
bit S14C2   @ LCDDATA13.6;
bit S15C2   @ LCDDATA13.7;

bit S00C2   @ LCDDATA12.0;
bit S01C2   @ LCDDATA12.1;
bit S02C2   @ LCDDATA12.2;
bit S03C2   @ LCDDATA12.3;
bit S04C2   @ LCDDATA12.4;
bit S05C2   @ LCDDATA12.5;
bit S06C2   @ LCDDATA12.6;
bit S07C2   @ LCDDATA12.7;

bit S40C1   @ LCDDATA11.0;
bit S41C1   @ LCDDATA11.1;
bit S42C1   @ LCDDATA11.2;
bit S43C1   @ LCDDATA11.3;
bit S44C1   @ LCDDATA11.4;
bit S45C1   @ LCDDATA11.5;
bit S46C1   @ LCDDATA11.6;
bit S47C1   @ LCDDATA11.7;

bit S32C1   @ LCDDATA10.0;
bit S33C1   @ LCDDATA10.1;
bit S34C1   @ LCDDATA10.2;
bit S35C1   @ LCDDATA10.3;
bit S36C1   @ LCDDATA10.4;
bit S37C1   @ LCDDATA10.5;
bit S38C1   @ LCDDATA10.6;
bit S39C1   @ LCDDATA10.7;

bit S24C1   @ LCDDATA9.0;
bit S25C1   @ LCDDATA9.1;
bit S26C1   @ LCDDATA9.2;
bit S27C1   @ LCDDATA9.3;
bit S28C1   @ LCDDATA9.4;
bit S29C1   @ LCDDATA9.5;
bit S30C1   @ LCDDATA9.6;
bit S31C1   @ LCDDATA9.7;

bit S16C1   @ LCDDATA8.0;
bit S17C1   @ LCDDATA8.1;
bit S18C1   @ LCDDATA8.2;
bit S19C1   @ LCDDATA8.3;
bit S20C1   @ LCDDATA8.4;
bit S21C1   @ LCDDATA8.5;
bit S22C1   @ LCDDATA8.6;
bit S23C1   @ LCDDATA8.7;

bit S08C1   @ LCDDATA7.0;
bit S09C1   @ LCDDATA7.1;
bit S10C1   @ LCDDATA7.2;
bit S11C1   @ LCDDATA7.3;
bit S12C1   @ LCDDATA7.4;
bit S13C1   @ LCDDATA7.5;
bit S14C1   @ LCDDATA7.6;
bit S15C1   @ LCDDATA7.7;

bit S00C1   @ LCDDATA6.0;
bit S01C1   @ LCDDATA6.1;
bit S02C1   @ LCDDATA6.2;
bit S03C1   @ LCDDATA6.3;
bit S04C1   @ LCDDATA6.4;
bit S05C1   @ LCDDATA6.5;
bit S06C1   @ LCDDATA6.6;
bit S07C1   @ LCDDATA6.7;

bit S40C0   @ LCDDATA5.0;
bit S41C0   @ LCDDATA5.1;
bit S42C0   @ LCDDATA5.2;
bit S43C0   @ LCDDATA5.3;
bit S44C0   @ LCDDATA5.4;
bit S45C0   @ LCDDATA5.5;
bit S46C0   @ LCDDATA5.6;
bit S47C0   @ LCDDATA5.7;

bit DC1B0   @ CCP1CON.4;
bit DC1B1   @ CCP1CON.5;

bit DC2B0   @ CCP2CON.4;
bit DC2B1   @ CCP2CON.5;

bit TX9D2   @ TXSTA2.0;
bit TRMT2   @ TXSTA2.1;
bit BRGH2   @ TXSTA2.2;
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
bit RX9_2   @ RCSTA2.6;
bit SPEN2   @ RCSTA2.7;

bit RTCPTR0 @ RTCCFG.0;
bit RTCPTR1 @ RTCCFG.1;
bit RTCOE   @ RTCCFG.2;
bit HALFSEC @ RTCCFG.3;
bit RTCSYNC @ RTCCFG.4;
bit RTCWREN @ RTCCFG.5;
bit RTCEN   @ RTCCFG.7;

bit ALRMPTR0 @ ALRMCFG.0;
bit ALRMPTR1 @ ALRMCFG.1;
bit AMASK0  @ ALRMCFG.2;
bit AMASK1  @ ALRMCFG.3;
bit AMASK2  @ ALRMCFG.4;
bit AMASK3  @ ALRMCFG.5;
bit CHIME   @ ALRMCFG.6;
bit ALRMEN  @ ALRMCFG.7;

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

bit IRNG0   @ CTMUICON.0;
bit IRNG1   @ CTMUICON.1;

bit RTSECSEL0 @ PADCFG1.1;
bit RTSECSEL1 @ PADCFG1.2;
