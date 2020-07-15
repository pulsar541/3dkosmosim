#ifndef _plazma_h_
#define _plazma_h_


class Ball 
{ 
   public : 
	   double x,y,z;
	   double dx,dy,dz;
   double x2; 
   double y2; 
   double z2; 
   double x3; 
   double y3; 
   double z3; 
   double scale; 
   int k; 
   bool dob; 
   Ball() 
   { 
      k = 0; 
      x = y = z = 1000000000000; 
      dx = dy = dz = 0; 
      dob = 0; 
      c = 0; 
   } 
   int c; 
   void move() 
   { 
      x += dx; 
      y += dy; 
      z += dz; 
      if ( k ++> 1000) 
      { k = 0; 
         x = y = z = 1000000000000; 
         dx = dy = dz = 0; 
      } 
   } 
   void setPos(double x,double y,double z)
   { 	this->x=x;	
		this->y=y; 
		this->z=z;
   }
   void setDelta(double dx,double dy,double dz)
   { 	this->dx=dx;	
		this->dy=dy; 
		this->dz=dz;
   }
   void show() 
   { 
      if ( ( dx*dy*dz) != 0 ) 
      { 
         glPushMatrix(); 
         glTranslated(x,y,z); 
         glCallList(PLAZMA + c); 
         glPopMatrix(); 
      } 
   } 
}; 

#endif
