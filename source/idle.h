#ifndef _idle_h_
#define _idle_h_


int ttt = 0; 
static int tmp = 100; 

void CalcTraectory(PLANET *a) 
{ 
   a -> sch ++; 
   a -> p[a -> i].x = a -> x; 
   a -> p[a -> i].y = a -> y; 
   a -> p[a -> i].z = a -> z; 
   if ( mapmode) 
   { 
      a -> colortraectory[0] = a -> colorplanet[0] * 0.2; 
      a -> colortraectory[1] = a -> colorplanet[1] * 0.2; 
      a -> colortraectory[2] = a -> colorplanet[2] * 0.2; 
   } 
   else 
   { 
      a -> colortraectory[0] = 0; 
      a -> colortraectory[1] = 0; 
      a -> colortraectory[2] = 0.1; 
   } 
   for ( int j = a -> i;j > a -> k - 1;j -- ) 
   { 
      if ( a -> NUM >= GIANTSCOUNT && DISTANCE(a,b[a -> KOMU]) < 5000) 
      { 
         a -> p[j].x += body[a -> KOMU].dx; 
         a -> p[j].y += body[a -> KOMU].dy; 
         a -> p[j].z += body[a -> KOMU].dz; 
      } 
   } 
   switch ( a -> NUM < GIANTSCOUNT) 
   { 
      case 1 : if ( a -> sch > DETAL_TRAECT1) 
      { 
         if ( a -> i ++> 1500 ) 
         a -> k ++; 
         a -> sch = 0; 
      } 
      break; 
      case 0 : if ( a -> sch > DETAL_TRAECT2) 
      { a -> sch = 0; 
         if ( a -> i ++> 500 ) 
         a -> k ++; 
         if ( a -> i > 6000 ) 
         a -> k = a -> i = 0; 
      } 
      break; 
   } 
   //  if(a->NUM<GIANTSCOUNT) 
   //  { 
   //  if(a->i>500)   
   //   a->k++; 
   //  } 
   //  else 
   //  { 
   //  if(a->i>1000)   
   //   a->k++; 
   //  } 
   //  } 
   if ( a -> i == 6000 ) 
   a -> i = 0; 
   //if ( a -> NUM >= GIANTSCOUNT && DISTANCE(a,b[a -> KOMU]) > 5000) 
   //DELETE_PLANET(a); 
} 


void FlyPlanets () 
{ 
static int k=0;	



  keplerB(body, PLANET_COUNT+1);


	   for (int  n = 0; n < PLANET_COUNT; n ++ ) 
	   { 

		   if(body[n].isDynamic)
		   {body[n].x+=body[n].dx;
			body[n].y+=body[n].dy;
			body[n].z+=body[n].dz;
		   }

		   b[n]->x=body[n].x;
		   b[n]->y=body[n].y;
		   b[n]->z=body[n].z;
		   b[n]->Processing();

		   if(b[n]->bVidelen)
			   vid[n]=true;
		   else   
			   vid[n]=false;

		   //CalcTraectory(b[n]);

	   }

		myship -> Move();
	
		for(int i=0;i<UFOCOUNT;i++)
		{


			ufo[i]->Processing();
			ufo[i]->Move();				

		//	body[PLANET_COUNT+1+i].x=ufo[i]->x;
	//		body[PLANET_COUNT+1+i].y=ufo[i]->y;
	//		body[PLANET_COUNT+1+i].z=ufo[i]->z;

	//		CalcTraectoryUFO(ufo[i]);
		}


	/*	for (i=0 ; i<10000; i++)
			mappoint[i]->Process();
 */

		zavod->SetPos(body[1].x,body[1].y,body[1].z+body[1].radius-2.7);
		zavod->dx=body[1].dx;
		zavod->dy=body[1].dy;
		zavod->dz=body[1].dz;

		tower->SetPos(body[1].x,body[1].y,body[1].z-body[1].radius);
} 


void WorkWithOrientation()
{
	if(mouseRightButton)
	{ xrot=yrot=zrot=0;
	}


		  glPushMatrix (); 
		   glLoadMatrixd ( mmm ); 

		   glRotatef (( zrot ),0,0,1 ); 
		   glRotatef (( yrot *FOV/45),0,1,0 ); 
		   glRotatef (( - xrot *FOV/45),1,0,0 );
		   glGetDoublev ( GL_MODELVIEW_MATRIX,mmm ); 
		   glPopMatrix (); 


	// матрица "invm" равна обратной "mmm" 
	   static int MGAS = M1.getactualsize (); 
	   for ( int i = 0, k = 0; i < MGAS; i ++ ) 
	   for ( int j = 0; j < MGAS; j ++ , k ++ ) 
	   M1.setvalue ( i,j,mmm[k] ); 
	   M1.invert (); 
	   static bool xyz; 
	   static double rv; 
	   for ( i = 0,k = 0; i < MGAS; i ++ ) 
	   for ( int j = 0; j < MGAS; j ++ , k ++ ) 
	   { 
		  M1.getvalue ( i,j,rv,xyz ); 
		  invm[k] = rv; 
	   } 
	   if ( ( zoomplus ) && FOV > 1 ) 
	   { 
		  FOV /= 1.02; 
		  if ( FOV < 1 ) 
		  FOV = 1; 
	  //    MyPerspective ( FOV,1,LIMITSPACE * 5000 ); 
	   } 
	   if ( zoominus ) 
	   { 
		  FOV *= 1.02; 
		  if ( FOV > 90 ) 
		  FOV = 90; 
	  //    MyPerspective ( FOV,1,LIMITSPACE * 5000 ); 
	   } 

	

  MyMouseFunc ();
	
	

}



static int oldimin = 0; 
static double oldcmin; 





void NotDraw () 
{ 

 //   CalcTraectoryShip ( myship ); 
   int vyt = 1; 
   olddway = dway; 



  
   if(ntextDown) NSTEXT-=3;
   if(ntextUp) NSTEXT+=3;

      if ( forward || back)  
	  { body[PLANET_COUNT].setFriction(0.05); 
	  
	     if ( forward ) 
		  { 
			 
        			 
			 if(myship ->isOnPlanet) 
			 {
				 dway=0.02;
				
				 xrot+=
					 50*sqrt(kvad(body[PLANET_COUNT].dx)+kvad(body[PLANET_COUNT].dy)+kvad(body[PLANET_COUNT].dz))
					/(2*3.1415926*b[imin]->radius);

			 }
			 else 
			 {if(dway<0.1) dway = 0.1;
				 dway*=1.01;

			 }


		//	 myship->Move();
//			 body[PLANET_COUNT].move(1);
		  } 


		  if ( back ) 
		  { 
   		

			 if(myship ->isOnPlanet) 
			 { 
				 dway=-0.02;
			
				 xrot-=
					 50*sqrt(kvad(body[PLANET_COUNT].dx)+kvad(body[PLANET_COUNT].dy)+kvad(body[PLANET_COUNT].dz))
					/(2*3.1415926*b[imin]->radius);
			 }
			 else 
			 {
			 	 body[PLANET_COUNT].dx/=1.04;	
  				 body[PLANET_COUNT].dy/=1.04;		 
  				 body[PLANET_COUNT].dz/=1.04;
			 
			 }
		  } 
	  }
	 else
	 {dway =0;
	  body[PLANET_COUNT].setFriction(0.4); 

/*
		if(!myship->isOnPlanet)
		{
		 	 body[PLANET_COUNT].dx/=1.02;	
  			 body[PLANET_COUNT].dy/=1.02;		 
  			 body[PLANET_COUNT].dz/=1.02;
		}*/
	 }


/*
	 if(myship ->isOnPlanet && ( forward || back))	 
	 else   
*/ 


   /*if ( dway > 0.001 ) 
   { 
      xrot += 0.00005 * dway * ( rand () %30 - 14 ); 
      yrot += 0.00005 * dway * ( rand () %30 - 14 ); 
   } */
 
 
   // // // // // // // // // // // // // // // // // // / 
    
    

	 
	   static int time = 0; 
	   time ++; 

   
	   if(!myship->isOnPlanet)
	   {   if(left2 || right2)
		   {
			   if ( left2 ) zrot += 0.05; 
			   if ( right2 ) zrot -= 0.05; 
		   }
		   else
		   {
			   if(zrot>=0.05) zrot-=0.05;
			   if(zrot<=-0.05) zrot+=0.05;
		   }
	   }
	   else 
	   {   if(left2 || right2)
		   {
			   if ( left2 ) 
			   {
					myship->x -=  tempm[0] * dway;
					myship->y -=  tempm[4] * dway;
					myship->z -=  tempm[8] * dway;
		
			   }
			   if ( right2 ) 
			   {
					myship->x +=  tempm[0] * dway;
					myship->y +=  tempm[4] * dway;
					myship->z +=  tempm[8] * dway;
		

			   }
			}
   		   else
			   {
				   if(zrot>=0.05) zrot-=0.05;
				   if(zrot<=-0.05) zrot+=0.05;
			   }
	   }

	   if ( zrot > 2 ) zrot = 2; 
	   if ( zrot < - 2 ) zrot =- 2; 


//	   if ( up2 ) xrot += 0.015; 
	   if ( xrot > 2 ) xrot = 2; 
//	   if ( down2 ) xrot -= 0.015; 
	   if ( xrot < - 2 ) xrot = -2; 
	   // yrot = zrot; 

	   double tempk = FOV / DEFAULTFOV; 
 
 
		//  static double olddxrot;
		 //  static double olddyrot;
		 //  static double olddzrot;

 
		//if(myship->isOnPlanet)
		//zrot=0;
			   
   

		 /*  olddxrot=xrot;
		   olddyrot=yrot;
		   olddzrot=zrot;
		*/
   


	   /* 
	   for ( int j = 0; j < 1000; j ++ ) 
	   { 
		  ball[j] -> move (); 
		  for ( int i = 0; i < PLANET_COUNT; i ++ ) 
		  { 
			 if ( E_planet[i] ) 
			 if ( rasst ( 
			 ball[j] -> x, 
			 ball[j] -> y, 
			 ball[j] -> z, 
			 b[i] -> x, 
			 b[i] -> y, 
			 b[i] -> z 
			 ) < b[i] -> hr ) 
			 { 
				// b[i] -> dx = - ( ball[j] -> dx-add_dx ); 
				// b[i] -> dy = - ( ball[j] -> dy-add_dy ); 
				// b[i] -> dz = - ( ball[j] -> dz-add_dz ); 
				// b[i] -> Move (); 
				ball[j] -> x = ball[j] -> y = ball[j] -> z = 1000000000000000000; 
			 } 
		  } 
	   } 
	   { 
		  for ( int i = 1; i < PLANET_COUNT; i ++ ) 
		  if ( E_planet[i] && b[i] -> showfire > 0 ) 
		  b[i] -> showfire--; 
	   } 
	   */ 



 
}


void Nearest()
{
	
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
 
void Idle () 
{
	



   tGT = timeGetTime (); 
   time1 = tGT-starttime1; 
   time2 = tGT-starttime2; 
   time3 = tGT-starttime3; 
   
   dt=(double)(0.001*time1);

   if ( time1 > 1000/100 ) 
  
   {
 
	   FlyPlanets (); 
	if(VP);
	{
		NotDraw ();
	}

	 
      ttt ++;
	  
  	  WorkWithOrientation();

	  starttime1 += time1; 
   } 
   
  glutPostRedisplay (); 


   if ( time2 > 1000 ) 
   { 
      starttime2 += time2; 
      fps = ttt; 
      ttt = 0; 

   } 
   
   
   
   zavod->Calc();



   if ( time3 > 1000/50) 
   { 
	  
	   	  
	   static int k=0;
	   static int t=0;
	
		if(k>999) k=0;
//		if(myship->fireing && t>2)
//		{ 
//			t=0;
//		   ball[k]->setPos (myship ->x,myship ->y,myship ->z);
//		   ball[k]->setDelta (tempm[2],tempm[6],tempm[10]);
//	
//		}

		  t++;
	  k++;


	 

      /* 
      for ( int i = 1; i < PLANET_COUNT; i ++ ) 
      if ( E_planet[i] && rasst ( b[i] -> x,b[i] -> y,b[i] -> z,myship -> x,myship -> y,myship -> z < 5000 ) ) 
      { 
         if ( b[i] -> timer ++ > 100 ) 
         { 
            b[i] -> showfire = 100; 
            b[i] -> timer = rand () %100; 
            b[i] -> goalx = myship -> x + minirand () - 0.5; 
            b[i] -> goaly = myship -> y + minirand () - 0.5; 
            b[i] -> goalz = myship -> z + minirand () - 0.5; 
         } 
      } 
      dupx = myship -> x; 
      dupy = myship -> y; 
      dupz = myship -> z; 
      */ 
      starttime3 += time3; 
  


   //   if ( mapmode ) MyPerspective ( 45,500,LIMITSPACE * 500 ); 
   //   else 
	
      glGetDoublev ( GL_MODELVIEW_MATRIX,mv ); 
      glGetDoublev ( GL_PROJECTION_MATRIX,pm ); 
      glGetIntegerv ( GL_VIEWPORT,vp ); 
      gluProject ( pos0[0],pos0[1],pos0[2],mv,pm,vp,&winx1,&winy1,&winz1 ); 
	  
 

      /* 
      static float vspysh = 0; 
      if ( cmin < 2 ) 
      { 
         myship -> x = b[b[imin] -> num_dest] -> x + b[b[imin] -> num_dest] -> hr + 100; 
         myship -> y = b[b[imin] -> num_dest] -> y + b[b[imin] -> num_dest] -> hr + 100; 
         myship -> z = b[b[imin] -> num_dest] -> z + b[b[imin] -> num_dest] -> hr + 100; 
         if ( _0v1 ) zrot = 2; 
         else zrot = - 2; 
         if ( _0v1 ) xrot = 2; 
         else xrot = - 2; 
         vspysh = 0.95; 
      } 
      */ 
      if ( vspysh > 0 ) vspysh -= 0.1; 

//      showpoint = (bool)!showpoint; 
   } 

//  g_gui.idle();
 
} 

#endif
