#pragma config[1] = 0xF1 // Osilatör: XT
#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
#pragma config[3] = 0xFE // Watchdog Timer kapalý

void ayarlar();
void bekle(unsigned long t);   // t milisaniye gecikme saðlayan fonksiyon tanýmý


void main()
{
   ayarlar();

//-----------------------------------------------   
anadongu:

    bekle(1);   // Acquisition Time(Sample & Hold kapasitörünün þarj olmasý için gerekli zaman)
    
     
    while(1)
    {
    
    
    PORTB.0=1;
    if(PORTB.4==1)
    {
      bekle(20);
      PORTD=0x01;}
    if(PORTB.5==1)
    {
      bekle(20);
      PORTD=0x02;}
    if(PORTB.6==1)
    {
      bekle(20);
      PORTD=0x03;}
    PORTB.0=0;
    
    PORTB.1=1;
    if(PORTB.4==1)
    {
      bekle(20);
      PORTD=0x04;}
    if(PORTB.5==1)
    {
      bekle(20);
      PORTD=0x05;}
    if(PORTB.6==1)
    {
      bekle(20);
      PORTD=0x06;}
    PORTB.1=0; 
     
    PORTB.2=1;
    if(PORTB.4==1)
    {
      bekle(20);
      PORTD=0x07;}
    if(PORTB.5==1)
    {
      bekle(20);
      PORTD=0x08;}
    if(PORTB.6==1)
    {
      bekle(20);
      PORTD=0x09;}
    PORTB.2=0;  
     
    PORTB.3=1;
    if(PORTB.4==1)
    {
      bekle(20);
      PORTD=0x0B;}
    if(PORTB.5==1)
    {
      bekle(20);
      PORTD=0x0A;}
    if(PORTB.6==1)
    {
      bekle(20);
      PORTD=0x0C;}
    PORTB.3=0;   
     
} 
    
   goto anadongu;
//-----------------------------------------------   
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void ayarlar()   // Bütün baþlangýç ayarlarýnýn tamamlandýðý kýsým
{   
   GIE=0;         // Bütün kesmeleri kapat
   TRISB=0xF0;      // B portu giriþ yapýldý
   TRISD=0;      // D portu çýkýþ yapýldý
     
   PORTD=0;      // D portu çýkýþlarý sýfýrlandý

   
   
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void bekle(unsigned long t)   //t milisaniye gecikme saðlar
{
   unsigned x;
   
   for(;t>0;t--)
      for(x=140;x>0;x--)
         nop();
}

//////////////////////////////////////////////////////////////////////////////////////////////////
