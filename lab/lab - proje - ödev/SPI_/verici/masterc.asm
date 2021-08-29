
; CC8E Version 1.3D, Copyright (c) B Knudsen Data
; C compiler for the PIC18 microcontrollers
; ************  23. Jan 2011  21:14  *************

	processor  PIC18F452
	radix  DEC

	__config 0x300001, 0xF1
	__config 0x300002, 0xF8
	__config 0x300003, 0xFE

Zero_       EQU   2
SSPBUF      EQU   0xFC9
SSPADD      EQU   0xFC8
SSPCON1     EQU   0xFC6
ADCON0      EQU   0xFC2
ADCON1      EQU   0xFC1
TRISD       EQU   0xF95
TRISC       EQU   0xF94
TRISB       EQU   0xF93
TRISA       EQU   0xF92
PORTD       EQU   0xF83
PORTC       EQU   0xF82
PORTB       EQU   0xF81
PORTA       EQU   0xF80
GIE         EQU   7
SSPEN       EQU   5
SSPIF       EQU   3
t           EQU   0x00
x           EQU   0x02

	GOTO main

  ; FILE masterc.c
			;#pragma config[1] = 0xF1 // Osilatör: XT
			;#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
			;#pragma config[3] = 0xFE // Watchdog Timer kapalý
			;
			;void ayarlar();
			;void I2Cayar();
			;void bekle(unsigned long t);   // t milisaniye gecikme saðlayan fonksiyon tanýmý
			;void main()
			;{  
main
			;   
			;   
			;   ayarlar();
	RCALL ayarlar
			;
			;//-----------------------------------------------   
			;while(1)
			;{
			;if(PORTA.0==1)
m001	BTFSS PORTA,0,0
	BRA   m003
			;{PORTD.0=0;
	BCF   PORTD,0,0
			;   SSPBUF=0x1;
	MOVLW 1
	MOVWF SSPBUF,0
			;   while(!SSPIF);
m002	BTFSS 0xF9E,SSPIF,0
	BRA   m002
			;   SSPIF=0;
	BCF   0xF9E,SSPIF,0
			;   PORTD.0=1;
	BSF   PORTD,0,0
			; bekle(1000);
	MOVLW 232
	MOVWF t,0
	MOVLW 3
	MOVWF t+1,0
	RCALL bekle
			;  }
			;
			;if(PORTA.1==1)
m003	BTFSS PORTA,1,0
	BRA   m005
			;{PORTD.0=0;
	BCF   PORTD,0,0
			;   SSPBUF=0x2;
	MOVLW 2
	MOVWF SSPBUF,0
			;   while(!SSPIF);
m004	BTFSS 0xF9E,SSPIF,0
	BRA   m004
			;   SSPIF=0;
	BCF   0xF9E,SSPIF,0
			;   PORTD.0=1;
	BSF   PORTD,0,0
			; bekle(1000);
	MOVLW 232
	MOVWF t,0
	MOVLW 3
	MOVWF t+1,0
	RCALL bekle
			;  }
			;
			;if(PORTA.2==1)
m005	BTFSS PORTA,2,0
	BRA   m007
			;{PORTD.0=0;
	BCF   PORTD,0,0
			;   SSPBUF=0x3;
	MOVLW 3
	MOVWF SSPBUF,0
			;   while(!SSPIF);
m006	BTFSS 0xF9E,SSPIF,0
	BRA   m006
			;   SSPIF=0;
	BCF   0xF9E,SSPIF,0
			;   PORTD.0=1;
	BSF   PORTD,0,0
			; bekle(1000);
	MOVLW 232
	MOVWF t,0
	MOVLW 3
	MOVWF t+1,0
	RCALL bekle
			;  }
			;if(PORTA.3==1)
m007	BTFSS PORTA,3,0
	BRA   m009
			;{PORTD.0=0;
	BCF   PORTD,0,0
			;   SSPBUF=0xA;
	MOVLW 10
	MOVWF SSPBUF,0
			;   while(!SSPIF);
m008	BTFSS 0xF9E,SSPIF,0
	BRA   m008
			;   SSPIF=0;
	BCF   0xF9E,SSPIF,0
			;   PORTD.0=1;
	BSF   PORTD,0,0
			; bekle(1000);
	MOVLW 232
	MOVWF t,0
	MOVLW 3
	MOVWF t+1,0
	RCALL bekle
			;  }
			;
			;if(PORTA.4==1)
m009	BTFSS PORTA,4,0
	BRA   m011
			;{PORTD.0=0;
	BCF   PORTD,0,0
			;   SSPBUF=0x4;
	MOVLW 4
	MOVWF SSPBUF,0
			;   while(!SSPIF);
m010	BTFSS 0xF9E,SSPIF,0
	BRA   m010
			;   SSPIF=0;
	BCF   0xF9E,SSPIF,0
			;   PORTD.0=1;
	BSF   PORTD,0,0
			; bekle(1000);
	MOVLW 232
	MOVWF t,0
	MOVLW 3
	MOVWF t+1,0
	RCALL bekle
			;  }
			;if(PORTA.5==1)
m011	BTFSS PORTA,5,0
	BRA   m013
			;{PORTD.0=0;
	BCF   PORTD,0,0
			;   SSPBUF=0x5;
	MOVLW 5
	MOVWF SSPBUF,0
			;   while(!SSPIF);
m012	BTFSS 0xF9E,SSPIF,0
	BRA   m012
			;   SSPIF=0;
	BCF   0xF9E,SSPIF,0
			;   PORTD.0=1;
	BSF   PORTD,0,0
			; bekle(1000);
	MOVLW 232
	MOVWF t,0
	MOVLW 3
	MOVWF t+1,0
	RCALL bekle
			;  }
			;
			;if(PORTC.6==1)
m013	BTFSS PORTC,6,0
	BRA   m015
			;{PORTD.0=0;
	BCF   PORTD,0,0
			;   SSPBUF=0x6;
	MOVLW 6
	MOVWF SSPBUF,0
			;   while(!SSPIF);
m014	BTFSS 0xF9E,SSPIF,0
	BRA   m014
			;   SSPIF=0;
	BCF   0xF9E,SSPIF,0
			;   PORTD.0=1;
	BSF   PORTD,0,0
			; bekle(1000);
	MOVLW 232
	MOVWF t,0
	MOVLW 3
	MOVWF t+1,0
	RCALL bekle
			;  }
			;
			;if(PORTB.0==1)
m015	BTFSS PORTB,0,0
	BRA   m017
			;{PORTD.0=0;
	BCF   PORTD,0,0
			;   SSPBUF=0xB;
	MOVLW 11
	MOVWF SSPBUF,0
			;   while(!SSPIF);
m016	BTFSS 0xF9E,SSPIF,0
	BRA   m016
			;   SSPIF=0;
	BCF   0xF9E,SSPIF,0
			;   PORTD.0=1;
	BSF   PORTD,0,0
			; bekle(1000);
	MOVLW 232
	MOVWF t,0
	MOVLW 3
	MOVWF t+1,0
	RCALL bekle
			;  }
			;if(PORTB.1==1)
m017	BTFSS PORTB,1,0
	BRA   m019
			;{PORTD.0=0;
	BCF   PORTD,0,0
			;   SSPBUF=0x7;
	MOVLW 7
	MOVWF SSPBUF,0
			;   while(!SSPIF);
m018	BTFSS 0xF9E,SSPIF,0
	BRA   m018
			;   SSPIF=0;
	BCF   0xF9E,SSPIF,0
			;   PORTD.0=1;
	BSF   PORTD,0,0
			; bekle(1000);
	MOVLW 232
	MOVWF t,0
	MOVLW 3
	MOVWF t+1,0
	RCALL bekle
			;  }
			;if(PORTB.2==1)
m019	BTFSS PORTB,2,0
	BRA   m021
			;{PORTD.0=0;
	BCF   PORTD,0,0
			;   SSPBUF=0x8;
	MOVLW 8
	MOVWF SSPBUF,0
			;   while(!SSPIF);
m020	BTFSS 0xF9E,SSPIF,0
	BRA   m020
			;   SSPIF=0;
	BCF   0xF9E,SSPIF,0
			;   PORTD.0=1;
	BSF   PORTD,0,0
			; bekle(1000);
	MOVLW 232
	MOVWF t,0
	MOVLW 3
	MOVWF t+1,0
	RCALL bekle
			;  }
			;if(PORTB.3==1)
m021	BTFSS PORTB,3,0
	BRA   m023
			;{PORTD.0=0;
	BCF   PORTD,0,0
			;   SSPBUF=0x9;
	MOVLW 9
	MOVWF SSPBUF,0
			;   while(!SSPIF);
m022	BTFSS 0xF9E,SSPIF,0
	BRA   m022
			;   SSPIF=0;
	BCF   0xF9E,SSPIF,0
			;   PORTD.0=1;
	BSF   PORTD,0,0
			; bekle(1000);
	MOVLW 232
	MOVWF t,0
	MOVLW 3
	MOVWF t+1,0
	RCALL bekle
			;  }
			;if(PORTB.4==1)
m023	BTFSS PORTB,4,0
	BRA   m025
			;{PORTD.0=0;
	BCF   PORTD,0,0
			;   SSPBUF=0xC;
	MOVLW 12
	MOVWF SSPBUF,0
			;   while(!SSPIF);
m024	BTFSS 0xF9E,SSPIF,0
	BRA   m024
			;   SSPIF=0;
	BCF   0xF9E,SSPIF,0
			;   PORTD.0=1;
	BSF   PORTD,0,0
			; bekle(1000);
	MOVLW 232
	MOVWF t,0
	MOVLW 3
	MOVWF t+1,0
	RCALL bekle
			;  }
			;if(PORTB.5==1)
m025	BTFSS PORTB,5,0
	BRA   m027
			;{PORTD.0=0;
	BCF   PORTD,0,0
			;   SSPBUF=0xF;
	MOVLW 15
	MOVWF SSPBUF,0
			;   while(!SSPIF);
m026	BTFSS 0xF9E,SSPIF,0
	BRA   m026
			;   SSPIF=0;
	BCF   0xF9E,SSPIF,0
			;   PORTD.0=1;
	BSF   PORTD,0,0
			; bekle(1000);
	MOVLW 232
	MOVWF t,0
	MOVLW 3
	MOVWF t+1,0
	RCALL bekle
			;  }
			;if(PORTB.6==1)
m027	BTFSS PORTB,6,0
	BRA   m029
			;{PORTD.0=0;
	BCF   PORTD,0,0
			;   SSPBUF=0xE;
	MOVLW 14
	MOVWF SSPBUF,0
			;   while(!SSPIF);
m028	BTFSS 0xF9E,SSPIF,0
	BRA   m028
			;   SSPIF=0;
	BCF   0xF9E,SSPIF,0
			;   PORTD.0=1;
	BSF   PORTD,0,0
			; bekle(1000);
	MOVLW 232
	MOVWF t,0
	MOVLW 3
	MOVWF t+1,0
	RCALL bekle
			;  }
			;if(PORTB.7==1)
m029	BTFSS PORTB,7,0
	BRA   m031
			;{PORTD.0=0;
	BCF   PORTD,0,0
			;   SSPBUF=0xD;
	MOVLW 13
	MOVWF SSPBUF,0
			;   while(!SSPIF);
m030	BTFSS 0xF9E,SSPIF,0
	BRA   m030
			;   SSPIF=0;
	BCF   0xF9E,SSPIF,0
			;   PORTD.0=1;
	BSF   PORTD,0,0
			; bekle(1000);
	MOVLW 232
	MOVWF t,0
	MOVLW 3
	MOVWF t+1,0
	RCALL bekle
			;  }
			;
			;if(PORTC.7==1)
m031	BTFSS PORTC,7,0
	BRA   m001
			;{PORTD.0=0;
	BCF   PORTD,0,0
			;   SSPBUF=0x0;
	CLRF  SSPBUF,0
			;   while(!SSPIF);
m032	BTFSS 0xF9E,SSPIF,0
	BRA   m032
			;   SSPIF=0;
	BCF   0xF9E,SSPIF,0
			;   PORTD.0=1;
	BSF   PORTD,0,0
			; bekle(1000);
	MOVLW 232
	MOVWF t,0
	MOVLW 3
	MOVWF t+1,0
	RCALL bekle
			;  }
			;
			;}
	BRA   m001
			;//-----------------------------------------------   
			;}
			;
			;//////////////////////////////////////////////////////////////////////////////////////////////////
			;void ayarlar()   // Bütün baþlangýç ayarlarýnýn tamamlandýðý kýsým
			;{   
ayarlar
			;   GIE=0;         // Bütün kesmeleri kapat
	BCF   0xFF2,GIE,0
			;   TRISA=0xFF;
	SETF  TRISA,0
			;   TRISB=0xFF;
	SETF  TRISB,0
			;  // TRISE=0xFF;
			;   TRISD=0x00; 
	CLRF  TRISD,0
			;   TRISC=0xD0;
	MOVLW 208
	MOVWF TRISC,0
			;   PORTC=0x00;     
	CLRF  PORTC,0
			;}
	RETURN
			;//////////////////////////////////////////////////////////////////////////////////
			;
			;void I2Cayar()
			;{
I2Cayar
			;    TRISC.3=1; //I2C SCL Ayarý
	BSF   TRISC,3,0
			;	TRISC.4=1; //I2C SDA Ayarý
	BSF   TRISC,4,0
			;	SSPCON1.3=1; //I2C Master Modu seç
	BSF   SSPCON1,3,0
			;	SSPCON1.2=0;
	BCF   SSPCON1,2,0
			;	SSPCON1.1=0;
	BCF   SSPCON1,1,0
			;	SSPCON1.0=0;
	BCF   SSPCON1,0,0
			;	SSPADD=0x0A; //100kHZ Hýz Modu seç
	MOVLW 10
	MOVWF SSPADD,0
			;	SSPEN=1; //MSSP'yi Etkinleþtir
	BSF   0xFC6,SSPEN,0
			;	ADCON0=0b.0000.0001; //ADC Etkinleþtir
	MOVLW 1
	MOVWF ADCON0,0
			;	ADCON1=0b.0000.0000; //ADC Hýzý FClock/2
	CLRF  ADCON1,0
			;}
	RETURN
			;//////////////////////////////////////////////////////////////////////////////////////////////////
			;
			;void bekle(unsigned long t)   //t milisaniye gecikme saðlar
			;{
bekle
			;   unsigned x;
			;   
			;   for(;t>0;t--)
m033	MOVF  t,W,0
	IORWF t+1,W,0
	BTFSC 0xFD8,Zero_,0
	BRA   m036
			;      for(x=140;x>0;x--)
	MOVLW 140
	MOVWF x,0
m034	MOVF  x,1,0
	BTFSC 0xFD8,Zero_,0
	BRA   m035
			;         nop();
	NOP  
	DECF  x,1,0
	BRA   m034
m035	DECF  t,1,0
	MOVLW 0
	SUBWFB t+1,1,0
	BRA   m033
			;}
m036	RETURN

	END


; *** KEY INFO ***

; 0x0001C6    8 word(s)  0 % : ayarlar
; 0x0001D6   13 word(s)  0 % : I2Cayar
; 0x0001F0   17 word(s)  0 % : bekle
; 0x000004  225 word(s)  1 % : main

; RAM usage: 3 bytes (3 local), 1533 bytes free
; Maximum call level: 1
; Total of 265 code words (1 %)
