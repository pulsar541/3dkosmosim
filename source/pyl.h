

class Pyl 
{ 
   public : 
   double x,y,z,dw,dx,dy,dz,ax,ay,az; 
   double color[3]; 
	bool mode;

   Pyl(bool mode) 
   { x = y = z = dw = 0; 
      color[0] = color[1] = color[2] = 0.2; 
	  this->mode = mode;
   }
   
   void setCoord(double x,double y,double z) 
   {  dw = 0;
   
      this->x = x; 
      this->y = y; 
      this->z = z; 
	  dx = 0.4*minirand()-0.2;
	  dy = 0.4*minirand()-0.2;
	  dz = 0.4*minirand()-0.2;	
	  ax=ay=az=0;
   } 
   void show() 
   { 
	   dw+=0.3;	
	   ax+=dx;
	   ay+=dy;	
	   az+=dz;
	  glPushMatrix(); 	 
			glTranslated( x,y,z);
			  glColor4d(1,.7,0,8/dw);  
   	//		  glCallList(LISTPOINT);
			  
			  glPushMatrix(); 	 
					glTranslated( ax,ay,az);
								
					glCallList(LISTPOINT); 	
					glPopMatrix();

					glPushMatrix(); 	 
					glTranslated( -ax,-ay,-az); 	
					glCallList(LISTPOINT); 
			glPopMatrix(); 			  
	glPopMatrix();
   } 
}; 