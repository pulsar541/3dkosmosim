#ifndef _ship_h_
#define _ship_h_

void Line(double x0,double y0,double z0, 
double x1,double y1,double z1);

class SHIP 
{ 
   public : 

   double oldx; // X координата   корабля в предыдущий момент времети 
   double oldy; // Y координата   корабля в предыдущий момент времети 
   double oldz; // Z координата   корабля в предыдущий момент времети 
   double x; // X координата   корабля в текущий момент времети 
   double y; // Y координата   корабля в текущий момент времети 
   double z; // Z координата   корабля в текущий момент времети 
   double dx,dy,dz; // приращение пути  корабля по орбите 
   double massa; // масса 
   double speed; // скорость 
   int i,k; 
   bool fireing; 
   bool isOnPlanet; 
   // int sch; 
   // bool rx,ry,rz; 
   int NUM; // номер   корабля 
   MYPOINT p[10000]; 
   float colorSHIP[3]; 
   double t; 
   double popr_horiz; 
   // векторы силы      
   double maxprit; 
   int type; 
   int zdravie; 
   SHIP( double x0,double y0,double z0, 
   double ugol, 
   double startglobalspeed, 
   double m, 
   int num) 
   { 

      t = 0; 
      popr_horiz = 0; 
      isOnPlanet = false; 
      NUM = num; 
      x = x0; 
      y = y0; 
      z = z0; 
      mmm[12] = x; 
      mmm[13] = y; 
      mmm[14] = z; 
      for ( int i = 0;i < 10000;i ++ ) 
      p[i].x = p[i].y = p[i].z = 0; 
      //   gluLookAt(x,y,z,0,0,0,0,1,0); 
      //   glGetFloatv(GL_MODELVIEW_MATRIX,mmm); 
      // glLoadMatrixf(mmm); 
      dx = 1; 
      dy = 1; 
      dz = 1; 
      massa = m; 
      //  speed=sp;   
      //  oldx=x0-cos(ugol*PO180)*(startglobalspeed+0.00000001); 
      //  oldy=y0-sin(ugol*PO180)*(startglobalspeed+0.00000001);  
      //  oldz=z-0.0001;  
      oldx = x0 + 1; 
      oldy = y0 + 1; 
      oldz = z0 + 1; 
      zdravie = 100; 
      /* 
      for ( i = 0;i < 10000;i ++ ) 
      p[i].x = p[i].y = p[i].z = 0; 
      i = 1; 
      k = 0; 
      sch = 999; 
      rotate = 0; 
      rx?0 : 1; 
      ry?0 : 1; 
      rz = 1; 
      */ 
      //glNewList(NUM,GL_COMPILE_AND_EXECUTE); 
      // glutSolidSphere(hr,detalization,detalization);  
      // glEndList(); 
      type = 40; 
      colorSHIP[0] = minirand(); 
      colorSHIP[1] = minirand(); 
      colorSHIP[2] = minirand(); 
   } 
   void Show() 
   { /*
      glColor3fv(colorSHIP); 
      glDisable(GL_BLEND); 
      glPushMatrix(); 
      glLoadIdentity(); 
      //glTranslated (x,y,z); 
      glRotated ( zrot * 3,0,0,1); 
      glRotated ( - xrot * 3,1,0,0); 
      // glPushMatrix(); 
      // static double th=-70; 
      //static double tz=0; 
      //th-=xrot; 
      //tz-=zrot; 
      // glRotated (th,1,0,0); 
      // glRotated (tz,0,0,1); 
      glRotated ( - 25,1,0,0); 
      glPushMatrix(); 
      glTranslated ( - 0.3,0, - 0.6); 
      glRotatef(60,0,1,0); 
      glutSolidTorus(0.002,0.5,8,20); 
      glRotatef( - 60,0,1,0); 
      glTranslated ( 0.6,0,0); 
      glRotatef( - 60,0,1,0); 
      glutSolidTorus(0.002,0.5,8,20); 
      glPopMatrix(); 
      glPopMatrix(); 
      glPushMatrix(); 
      glLoadIdentity(); 
      glTranslatef(1.7, - 1, - 3.5); 
      glColor3f(0.5,0,0); 
      if ( zdravie > 33) glColor3f(0.8,0.8,0); 
      if ( zdravie > 66) glColor3f(0,0.5,0); 
//      glScalef(0.02,0.02,0.02); 
      for ( int i = 0;i < zdravie;i += 4) 
      { 
         glTranslatef(0,3,0); 
         glutSolidDodecahedron(); 
      } 
	  */

      glPushMatrix(); 
	  glColor3f(1,0,0);
	  glTranslated (x,y,z);
	  glDisable(GL_LIGHTING);
	  glScalef(10,10,10);
	  glutWireDodecahedron();
      glPointSize(5);
	  glCallList(LISTPOINT);
	  glPointSize(1);
      glPopMatrix(); 
      
   } 
   void SetCamera() 
   { 
      mmm[12] = x; 
      mmm[13] = y; 
      mmm[14] = z; 
   } 

	void Nearest()
	{
		
		  static double oldcmin = cmin; 
		  oldcmin = cmin; 
		  cmin = rasst ( myship -> x,myship -> y,myship -> z,b[0] -> x,b[0] -> y,b[0] -> z ) - b[0] ->radius ; 
		  double temp; 
		  for ( int i = 0; i < PLANET_COUNT; i ++ ) 
		  { 
			 temp = rasst ( myship -> x,myship -> y,myship -> z,b[i] -> x,b[i] -> y,b[i] -> z ) - b[i] ->radius; 
			 if ( cmin > temp ) 
			 { 
				cmin = temp; 
				imin = i; 
			 } 
		  } 

	}

   void Move() 
   {

	  Nearest(); 



      body[PLANET_COUNT].dx += - tempm[2] * dway; 
      body[PLANET_COUNT].dy += - tempm[6] * dway; 
      body[PLANET_COUNT].dz += - tempm[10] * dway; 
    
//	  body[PLANET_COUNT].move();
  //    x = body[PLANET_COUNT].x ; 
  //    y = body[PLANET_COUNT].y ; 
   //   z = body[PLANET_COUNT].z ; 
//  	
	  

	body[PLANET_COUNT].x+=body[PLANET_COUNT].dx;
	body[PLANET_COUNT].y+=body[PLANET_COUNT].dy;
	body[PLANET_COUNT].z+=body[PLANET_COUNT].dz;
	
		
		myship -> oldx=myship -> x;
		myship -> oldy=myship -> y;
  		myship -> oldz=myship -> z;
	 	
      x = body[PLANET_COUNT].x ; 
      y = body[PLANET_COUNT].y ; 
      z = body[PLANET_COUNT].z ; 
 	



  //    x += body[imin].dx ; 
   //   y += body[imin].dy ; 
   //   z += body[imin].dz ; 	  

   Obr();

   SetCamera(); 
/*	  if ( cmin > ( 4))
	  {body[PLANET_COUNT].contact=-1;*/
//		body[PLANET_COUNT].=0.000000000001;
//	  }
        
   } 
   void Obr() 
   { 
      if ( ( myship -> t += 0.6*(dway>0)) > 360) myship -> t = 0; 
      static short p; 
      static double k; 
      k =1.5;// + 0.05*sin(t); 
  
	  if ( cmin < body[imin].radius*0.1) 
      { isOnPlanet = true;
		body[PLANET_COUNT].radius = k; 
      } 
      else 
      { isOnPlanet = false; 
	//    body[PLANET_COUNT].massa=0;
      } 
   
	  static int pp=0;
 
	  if ( isOnPlanet && VP) 
      { 
		 double tx = b[imin] -> x - tempm[2] * b[imin] ->radius*0.5; 
         double ty = b[imin] -> y - tempm[6] * b[imin] ->radius*0.5; 
         double tz = b[imin] -> z - tempm[10] * b[imin] ->radius*0.5; 

         if ( GetPos(GETX,tx,ty,tz) > ( SSX >> 1)) pp=1;
         if ( GetPos(GETX,tx,ty,tz) < ( SSX >> 1)) pp=2;
		
		 if(pp==2)
		 zrot -= 0.1; 
    
		 if(pp==1)	
		 zrot += 0.1;
      } 
   } 
   double GetSpeed() 
   { return rasst(x,y,z,oldx,oldy,oldz); 
   } 
   // double GetLocalSpeed() 
   // {return GetSpeed()-b[imin]->GetSpeed(); 
   // } 
}; 
static void CreateMyShip(double x,double y,double z,int I) 
{ 
   // ship_start_positioin_x=10*rand()%LIMITSPACE-5*LIMITSPACE; 
   // ship_start_positioin_y=10*rand()%LIMITSPACE-5*LIMITSPACE; 
   // ship_start_positioin_z=10*rand()%LIMITSPACE-5*LIMITSPACE;; 
   myship = new SHIP( 
   x, 
   y, 
   z, 
   ugol(0,0,ship_start_positioin_x,ship_start_positioin_y) + 90, 
   0, 
   0.00000001, 
   MYSHIPNUM); 


   body[PLANET_COUNT].setPos(x,y,z); 
   body[PLANET_COUNT].setDelta(body[I].dx,body[I].dy,body[I].dz); 
   body[PLANET_COUNT].setMassa(0);
   body[PLANET_COUNT].setRadius(3); 
   body[PLANET_COUNT].setKoeffMove(1); 
   body[PLANET_COUNT].setElasticity(0.99);
   body[PLANET_COUNT].setFriction(0.5);



   //speed 
} 

 
#endif