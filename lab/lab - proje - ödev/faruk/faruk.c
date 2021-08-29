int i=0,j=0,x=0;
int dizi[]={1,2,4,8,16,32,64,128};

void init()
{TRISB=1;
 PORTB=0;
 TRISC=0;
 PORTC=0;
 TRISD=0;
 PORTD=0;
}
void main()
{init();
 do{ if(PORTB==2)
     {i=1;
        if(i==1 && PORTB==3)
          {
           PORTC=dizi[x];
            if(x==0)
              x=8;
            else x--;
            i=0;
            PORTD=1;
           }
      }

      if(PORTB==1)
      { j=1;
         if(j==1 && PORTB==3)
          {
           PORTC=dizi[x];
               if(x==8)
                 x=0;
                 else x++;
                 j=0;
                 PORTD=2;
           }
      }
       else portd=255;
 
 
 
 
 }while(1);
 }