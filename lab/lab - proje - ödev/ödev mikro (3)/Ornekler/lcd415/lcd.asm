
; CC8E Version 1.3F, Copyright (c) B Knudsen Data
; C compiler for the PIC18 microcontrollers
; ************   7. Dec 2013   9:41  *************

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
sayac       EQU   0x7F
sayac1      EQU   0x7F
zaman       EQU   0x7F
a           EQU   0x7F
C2tmp       EQU   0x7F
s           EQU   0x7F
t           EQU   0x7F
n           EQU   0x7F

	GOTO main

  ; FILE lcd.c
			;void init();
			;void bekle(unsigned long t);
			;/*void LcdInit();
			;void LcdYaz(char );
			;void LcdKomut(unsigned kom);
			;void MesajYaz(const char *msj,unsigned adr);*/
			;void ayarlar();
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
			;    int sayac=0;
	CLRF  sayac,0
			;    int sayac1=0;
	CLRF  sayac1,0
			;    int zaman=0;
	CLRF  zaman,0
			;    while(TMR1H<=9){
m001	MOVLW 10
	CPFSLT TMR1H,0
	BRA   m003
			;	 T1CON=0b.0000.0101;//Timer baslatilir.
	MOVLW 5
	MOVWF T1CON,0
			;	 nop();
	NOP  
			;     sayac=TMR1H;
	MOVFF TMR1H,sayac
			;	 T1CON=0b.0000.0000;//Timer durdurulur.
	CLRF  T1CON,0
			;	if(TMR1H>9){//9'dan sonra A yazmamasý için deger sifirlanir.
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
			;     sayac1=TMR1H;
	MOVFF TMR1H,sayac1
			;     zaman=sayac1-sayac;
	MOVF  sayac,W,0
	SUBWF sayac1,W,0
	MOVWF zaman,0
			;	 PORTC=zaman;
	MOVFF zaman,PORTC
			;	 bekle_kesme(1000);
	MOVLW 232
	MOVWF a,0
	MOVLW 3
	MOVWF a+1,0
	RCALL bekle_kesme
			;	 	}
	BRA   m001
			;}	
m003	RETURN
			;	
			;
			;bit e @ PORTE.0, rs @ PORTE.1, rw @ PORTE.2;
			;unsigned disp @ PORTD;
			;
			;void main(){
main
			;    ayarlar();
	RCALL ayarlar
			;	INTCON=0x90;
	MOVLW 144
	MOVWF INTCON,0
			;	/*init();
			;	LcdInit();*/
			;  
			;anadongu:
			;/*	MesajYaz("\f zaman= %d,zaman ",0x80);
			;	bekle(1500);
			;	MesajYaz("application file    ",0x80);
			;	bekle(1500);*/
			;	
			;goto anadongu;
m004	BRA   m004
			;}
			;   	
			;void bekle_kesme(unsigned long a)
			;{
bekle_kesme
			;	for(a=1400*a;a>0;a--)
	MOVF  a+1,W,0
	MOVWF C2tmp+1,0
	MOVF  a,W,0
	MOVWF C2tmp,0
	MOVF  C2tmp,W,0
	MULLW 120
	MOVFF PRODL,a
	MOVFF PRODH,a+1
	MOVF  C2tmp+1,W,0
	MULLW 120
	MOVF  PRODL,W,0
	ADDWF a+1,1,0
	MOVF  C2tmp,W,0
	MULLW 5
	MOVF  PRODL,W,0
	ADDWF a+1,1,0
m005	MOVF  a,W,0
	IORWF a+1,W,0
	BTFSC 0xFD8,Zero_,0
	BRA   m006
			;			nop();
	NOP  
	DECF  a,1,0
	MOVLW 0
	SUBWFB a+1,1,0
	BRA   m005
			;}
m006	RETURN
			;
			;void sifirla(unsigned long s)
			;{
sifirla
			;	if(s>9)
	MOVF  s+1,W,0
	BTFSS 0xFD8,Zero_,0
	BRA   m007
	MOVLW 10
	CPFSLT s,0
			;		TMR1H=0b.0000;
m007	CLRF  TMR1H,0
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
			;/*void init()
			;{
			;	TRISD=0X00;
			;	TRISE=0X00;
			;}
			;*/
			;
			;void bekle(unsigned long t)	//t milisaniye gecikme saðlar
			;{
bekle
			;	unsigned n;
			;	for(;t>0;t--)
m008	MOVF  t,W,0
	IORWF t+1,W,0
	BTFSC 0xFD8,Zero_,0
	BRA   m011
			;		for(n=140;n>0;n--)
	MOVLW 140
	MOVWF n,0
m009	MOVF  n,1,0
	BTFSC 0xFD8,Zero_,0
	BRA   m010
			;			nop();
	NOP  
	DECF  n,1,0
	BRA   m009
m010	DECF  t,1,0
	MOVLW 0
	SUBWFB t+1,1,0
	BRA   m008
			;}
m011	RETURN

	END


; *** KEY INFO ***

; 0x0000AA   17 word(s)  0 % : bekle
; 0x0000A0    5 word(s)  0 % : ayarlar
; 0x00005A   28 word(s)  0 % : bekle_kesme
; 0x000092    7 word(s)  0 % : sifirla
; 0x000004   39 word(s)  0 % : kesme
; 0x000052    4 word(s)  0 % : main

; RAM usage: 0 bytes (0 local), 1536 bytes free
; Maximum call level: 1
; Total of 102 code words (0 %)
