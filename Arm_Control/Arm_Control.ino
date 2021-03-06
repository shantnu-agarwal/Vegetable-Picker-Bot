#include<Servo.h>

#define THRESHOLD 200
int pos[]={90,135,90,135};
Servo S1,S2,S3,S4;


void setup() {
  
  S1.attach(5);
  S2.attach(6);
  S3.attach(7);
  S4.attach(8);
  armreset();

}

void armreset()
{
  S1.write(pos[0]);
  S2.write(pos[1]);
  S3.write(pos[2]);
  S4.write(pos[3]);
}


//void readData(int x, int y, int SIZE);

void setArmValues(int x,int y,int SIZE)
{
  
  if( abs(x) <5 && abs(y)<5)
      forward(SIZE);
  else
  {
    if(x>0 && y>0)
      motion(1,1,1,0);
    
    if(x<0 && y>0) 
      motion(0,1,1,0);
  
    if(x<0 && y<0)
      motion(0,0,0,1);
      
    if(x>0 && y<0)
      motion(1,0,0,1);
  } 
  
}

void motion(int a,int b,int c, int d)
{
  if(a==1)
    S1.write(++pos[0]);
  else
    S1.write(--pos[0]);
  
  if(b==1)
    S2.write(++pos[1]);
   else
    S2.write(--pos[1]);
    
  if(c==1)
    S3.write(++pos[2]);
  else
    S3.write(--pos[2]);
    
  if(d==1)
    S4.write(++pos[3]);
   else
    S4.write(--pos[3]);
}

void forward(int SIZE)
{
  if(SIZE>THRESHOLD)
    cut();
   else
   {
      S2.write( --pos[1] );
      S3.write( ++pos[2] );
   }
}

void cut()
{
//   algo to cut
//  calibrate cutting   
  
  
//   When cut is complete
    armreset();
}

void loop (){
                        //    SPI reads graphical data from RasPi
    int x,y,SIZE;
//    readData( x , y , SIZE );
    
    setArmValues(x,y,SIZE);
}
