#line 1 "C:/Users/LG/Desktop/faruk/faruk2.c"
int dizi[]={1,2,4,8,16,32,64,128};
int x=0;

void fonk()
{if(portd==1)
{ portc=dizi[x];
 x++;
 if(x==8)
 x=0; }
 else if(portd==2)
 { portc=dizi[x];
 x--;
 if(x==-1)
 x=7; }
}

void interrupt()
{ if(INTCON.INT0IF)
 { fonk();
 INTCON.INT0IF=0;
 }

}

void init()
{TRISC=0;
 PORTC=0;
 TRISD=1;
 PORTD=0;
 INTCON=0X88;
 INTCON2=0XF1;
 INTCON3=0X8B;
 INTCON.INT0IF=0;
 INTCON.RBIF=0;
 INTCON3.INT2IF=0;
 INTCON3.INT1IF=0;
 }

void main()
{init();
do{
 }while(1);
}
