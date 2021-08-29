
; CC8E Version 1.3F, Copyright (c) B Knudsen Data
; C compiler for the PIC18 microcontrollers
; ************   7. Dec 2013  10:49  *************

	processor  PIC18F452
	radix  DEC

PRODH       EQU   0xFF4
PRODL       EQU   0xFF3
INTCON      EQU   0xFF2
Zero_       EQU   2
TMR1H       EQU   0xFCF
T1CON       EQU   0xFCD
TRISC       EQU   0xF94
TRISB       EQU   0xF93
TRISA       EQU   0xF92
PORTC       EQU   0xF82
INT0IF      EQU   1
GIE         EQU   7
t           EQU   0x00
C2tmp       EQU   0x03
a           EQU   0x7F
C4tmp       EQU   0x7F
s           EQU   0x7F

	GOTO main

  ; FILE display.c
			;void ayarlar();
			;void bekle(unsigned long t);
			;void bekle_kesme(unsigned long a);
			;void sifirla(unsigned long s);
			;
			;void kesme() //kesme gelince yapilacak komutlar, kesmede calisacak fonksiyon main fonksiyonunun ustunde yazilir...	
			;{
kesme
			;    INTCON=0x90; // kesmeler acilir RBO/INT0 girisi interrupt enable edilir.
	MOVLW 144
	MOVWF INTCON,0
			;    INT0IF=0;  // yeni kesmeler gelmesi icin butona bagli olan INT0 portundaki interrupt flagi kapatilir.
	BCF   0xFF2,INT0IF,0
			;	GIE=1;	//kesmeler acilir, yeni kesme gelmesine musade edilir	
	BSF   0xFF2,GIE,0
			;    while(TMR1H<=9){
m001	MOVLW 10
	CPFSLT TMR1H,0
	BRA   m003
			;	 T1CON=0b.0000.0101;//Timer baslatilir.
	MOVLW 5
	MOVWF T1CON,0
			;	 nop();
	NOP  
			;    PORTC.4 = 0;	//	yeþil ledi söndür
	BCF   PORTC,4,0
			;	PORTC.5 = 1;	//	mavi led
	BSF   PORTC,5,0
			;	 T1CON=0b.0000.0000;//Timer durdurulur.
	CLRF  T1CON,0
			;PORTC.4=1;
	BSF   PORTC,4,0
			;     PORTC.5=0;	 
	BCF   PORTC,5,0
			;	 if(TMR1H>9){//9'dan sonra A yazmamasý için deger sifirlanir.
	MOVLW 9
	CPFSGT TMR1H,0
	BRA   m002
			;	            TMR1H=0b.0000;
	CLRF  TMR1H,0
			;	            nop();
	NOP  
			;	            PORTC=TMR1H;
	MOVFF TMR1H,PORTC
			;	            break;
	BRA   m003
			;             }
			;     nop();
m002	NOP  
			;	 PORTC=TMR1H;
	MOVFF TMR1H,PORTC
			;	 bekle_kesme(1000);
	MOVLW 232
	MOVWF a,0
	MOVLW 3
	MOVWF a+1,0
	RCALL bekle_kesme
			;	 
			;    }	
	BRA   m001
			;}	
m003	RETURN
			;
			;void main()
			;{
main
			;	ayarlar();
	RCALL ayarlar
			;	INTCON=0x90;
	MOVLW 144
	MOVWF INTCON,0
			;	
			;anadongu:
			;	PORTC.4=1;
m004	BSF   PORTC,4,0
			;	bekle(1);
	MOVLW 1
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;	PORTC.4=0;
	BCF   PORTC,4,0
			;	bekle(1);
	MOVLW 1
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;goto anadongu;
	BRA   m004
			;
			;}
			;
			;void bekle(unsigned long t)
			;{
bekle
			;	for(t=1400*t;t>0;t--)              
	MOVF  t+1,W,0
	MOVWF C2tmp+1,0
	MOVF  t,W,0
	MOVWF C2tmp,0
	MOVF  C2tmp,W,0
	MULLW 120
	MOVFF PRODL,t
	MOVFF PRODH,t+1
	MOVF  C2tmp+1,W,0
	MULLW 120
	MOVF  PRODL,W,0
	ADDWF t+1,1,0
	MOVF  C2tmp,W,0
	MULLW 5
	MOVF  PRODL,W,0
	ADDWF t+1,1,0
m005	MOVF  t,W,0
	IORWF t+1,W,0
	BTFSC 0xFD8,Zero_,0
	BRA   m006
			;			nop();
	NOP  
	DECF  t,1,0
	MOVLW 0
	SUBWFB t+1,1,0
	BRA   m005
			;}
m006	RETURN
			;
			;void bekle_kesme(unsigned long a)
			;{
bekle_kesme
			;	for(a=1400*a;a>0;a--)
	MOVF  a+1,W,0
	MOVWF C4tmp+1,0
	MOVF  a,W,0
	MOVWF C4tmp,0
	MOVF  C4tmp,W,0
	MULLW 120
	MOVFF PRODL,a
	MOVFF PRODH,a+1
	MOVF  C4tmp+1,W,0
	MULLW 120
	MOVF  PRODL,W,0
	ADDWF a+1,1,0
	MOVF  C4tmp,W,0
	MULLW 5
	MOVF  PRODL,W,0
	ADDWF a+1,1,0
m007	MOVF  a,W,0
	IORWF a+1,W,0
	BTFSC 0xFD8,Zero_,0
	BRA   m008
			;			nop();
	NOP  
	DECF  a,1,0
	MOVLW 0
	SUBWFB a+1,1,0
	BRA   m007
			;}
m008	RETURN
			;
			;void sifirla(unsigned long s)
			;{
sifirla
			;	if(s>9)
	MOVF  s+1,W,0
	BTFSS 0xFD8,Zero_,0
	BRA   m009
	MOVLW 10
	CPFSLT s,0
			;		TMR1H=0b.0000;
m009	CLRF  TMR1H,0
			;}
	RETURN
			;
			;void ayarlar()
			;{	
ayarlar
			;	GIE=1;			
	BSF   0xFF2,GIE,0
			;	TRISA=0xFF;
	SETF  TRISA,0
			;	TRISB=0xFF;
	SETF  TRISB,0
			;	TRISC=0x00;	
	CLRF  TRISC,0
			;
			;		
			;}
	RETURN

	END


; *** KEY INFO ***

; 0x0000E0    5 word(s)  0 % : ayarlar
; 0x000062   28 word(s)  0 % : bekle
; 0x00009A   28 word(s)  0 % : bekle_kesme
; 0x0000D2    7 word(s)  0 % : sifirla
; 0x000004   33 word(s)  0 % : kesme
; 0x000046   14 word(s)  0 % : main

; RAM usage: 5 bytes (5 local), 1531 bytes free
; Maximum call level: 1
; Total of 117 code words (0 %)
