

#ifndef _planet_h_
#define _planet_h_


#include "building.h"



void CreateMyShip(double,double,double,int); 
void CreateUFOs(); 
void FlyPlanets(); 
void GeneratePortalSystem(); 


bool InTheWindow(double *x,double *y, double *z,int *sizex,int *sizey) 
{ static double mv[16],pm[16]; 
   static int vp[4]; 
   static double winx,winy,winz; 
   glGetDoublev(GL_MODELVIEW_MATRIX, mv); 
   glGetDoublev(GL_PROJECTION_MATRIX,pm); 
   glGetIntegerv(GL_VIEWPORT,vp); 
   gluProject(*x,*y,*z,mv,pm,vp,&winx,&winy,&winz); 
   return ( winx >= 0 && winx < *sizex && winy >= 0 && winy < *sizey ); 
} 
////////////////////////////////////////////////////////////////////////   

class PLANET 
{ 
   public : 
   double x; 
   double y; 
   double z; 
   double dx; 
   double dy; 
   double dz; 
   double massa; 
   double radius; 
   int num_dest; 
   int i,k; 
   double rotate; 
   double angle; 
   int sch; 
   bool rx,ry,rz; 
   int NUM; // номер   небесного тела   
   MYPOINT p[10000]; 
   float colorplanet[3]; 
   float colortraectory[3]; 
   int distance_to_planet; 
   int KOMU; 
   int Type; 
   int portalcount; 
   // векторы силы        
   double maxprit; 
   double dist; 
   char name[10]; 
   double rasst_do_solnca; 
   int timer; 
   int showfire; 
   int showdoctor; 
   double goalx; 
   double goaly; 
   double goalz; 
   int health; 
   bool opened; 
   bool bFocus;
   bool bVidelen;

   bool bWithClouds;


   float dif[4];

   int numTexture; 

   char info[1000][1000];
   int LEN_INFO ;
   int NNN ;


   PLANET(char *filename, char *name) 
   {LEN_INFO = 30000;
	   NNN=0;
/*
		   for(int i=0;i<100;i++)
		   {
			   info[i] = 65+rand()%33;
			   if(rand()>30000) info[i] = 13;
			   info[i+1]=0;
		   }
	   */

   
		   FILE *fp;
		   fp=fopen(filename,"r");

		   int n=0;
		   int i=0;
		   int kol=0;

		   for( int k=0; k<LEN_INFO;k++)
		   {
		   
			   info[n][i] = getc(fp);

			   if(info[n][i]  == '^') break;



			   if( info[n][i] == '\n' || (kol>90 && info[n][i] == ' ')) 
			   { 
				  info[n][i] = ' ';
				 n++; 
			     i=-1;
				 kol=0;
			   }
			   
			   i++;
			   kol++;

			  
		   }

		     fclose(fp);

			 lstrcpy(this->name,name);
		

	   
   };
   
   void   setPL(double rad, 
			   double x0,double y0,double z0, 
			   double ugol, 
			   double speed, 
			   double r,double g,double b, 
			   double m, 
			   int num, 
			   int komu) 
   { 

	   
	   numTexture=rand()%10;

	   bVidelen = false;
	   bFocus = false;
	  
	   bWithClouds = (bool)((_0v1)*NUM);

      health = 100; 
      opened = false; 
      showfire = 0; 
      showdoctor = 0; 
      timer = rand() * 3; 
      Type = ISENEMY; 
      portalcount = 0; 
      NUM = num; 
      KOMU = komu; 
      x = x0; 
      y = y0; 
      z = z0; 
      dx = cos(ugol*PO180) * ( speed + 0.00000001); 
      dy = sin(ugol*PO180) * ( speed + 0.00000001); 
      dz = 0; 


      rotate = 0; 
      angle = rand()%36; 
      massa = m; 
      radius = rad; 


      colorplanet[0] = r; 
      colorplanet[1] = g; 
      colorplanet[2] = b; 


      for ( i = 0;i < 10000;i ++ ) 
      p[i].x = p[i].y = p[i].z = 0; 

   //   name[0] = '?'; 
   //   name[1] = '\0'; 

   //   if ( NUM < GIANTSCOUNT) 
//		  SetName(); 

      i = 1; 
      k = 0; 
      sch = 999; 
      rotate = 0; 




   } 
   void SetName() 
   { 
      name[0] = 'А' + rand()%20; 
      name[1] = 'а' + rand()%20; 
      for ( i = 2;i < 10;i ++ ) 
      { name[i] = 'а' + rand()%20; 
         if ( i%2) name[i] = rusglas[rand()%10]; 
         if ( i > 1 && rand()%100 > 69) name[i] = '\0'; 
      } 
   } 
   void ChangeName() 
   { 
      name[0] = 'П'; 
      name[1] = 'о'; 
      name[2] = 'р'; 
      name[3] = 'т'; 
      name[4] = 'а'; 
      name[5] = 'л'; 
      name[6] = ' '; 
      char str[3]; 
      itoa(NUM,str,10); 
      name[7] = ' '; 
      name[8] = str[0]; 
      name[9] = str[1]; 
      name[10] = '\0'; 
   } 

   void ShowAtm()
   {
 
	   static float an=0;
	   an+=0.003;
	   if(an>360) an=0;


   		double H;
		double C;
		double A;
		double ugol_1;
		double ugol_2;
		glPushMatrix(); 
		glTranslated ( x,y,z); 




	 
				C=rasst(x,y,z,mmm[12],mmm[13],mmm[14]);


				 A=mmm[14]-z;
				 ugol_1 = ugol(mmm[12],mmm[13],x,y);
				 ugol_2 = asin(A/C)*_180oP;

		 if(!mapmode)	
		 {
				glRotatef(ugol_1,0,0,1);
				glRotatef(ugol_2-90,0,1,0);
		 }
				H=radius*radius/(C-radius);

				if(H<radius) H=radius;
				if(H>radius*10) H=radius*10;
			//	if(H>radius*100) H=radius*100;
	     
				
		//		if(!mapmode)
		//			glClearColor (colorplanet[0]/(C-radius),colorplanet[1]/(C-radius),colorplanet[2]/(C-radius),0); 
		//		else
		//			glClearColor (0,0,0,0); 



				

		
			//	glPushMatrix(); 		
			//		glDisable (GL_LIGHTING);

					if(NUM)
						CreateAtmosphere(colorplanet[0],colorplanet[1],colorplanet[2],radius,H,
						2*radius/(C-radius),
						C-radius);
					else 
						CreateAtmosphere(1,1,1,radius,H,
						2*radius/(C-radius),
						C-radius);
			//	glPopMatrix(); 

		/*		glColor4f(colorplanet[0]/(C-radius),colorplanet[1]/(C-radius),colorplanet[2]/(C-radius),1);
				glPushMatrix();
				glScalef(radius*5,radius*5,radius*5);
				glCallList(LISTSIMPLESPHERE);
				glPopMatrix();
*/



		glPopMatrix(); 
		
	
	//	if(!NUM)
			return;

		glPushMatrix(); 
		glTranslated ( x,y,z); 
					glEnable(GL_BLEND);
					glDisable(GL_LIGHTING);

					 glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
					 glScalef(1.1,1.1,1.1);
			
					 glBindTexture(GL_TEXTURE_2D, texclouds);

					 glRotatef(an,0,0,1);
					 
					 glEnable(GL_CULL_FACE);
					 glCullFace(GL_FRONT);
					 glCallList(NUM + 1);
					 glCullFace(GL_BACK);
					 glCallList(NUM + 1);

		  glPopMatrix();


   }

   void Show(int detalization,bool a) 
   { 

   
    //dif[0] = 0.5+colorplanet[0]; 
    // dif[1] = 0.5+colorplanet[1]; 
    // dif[2] = 0.5+colorplanet[2];
   //  dif[3] = 1; 
   //
  
  // if(!NUM) dif[0]=dif[1]=dif[2]=1;

 //  glLightfv ( GL_LIGHT1, GL_DIFFUSE, dif); 
   


      glPushMatrix(); 
	


      if ( a) glTranslated ( x,y,z); 

 //     if ( NUM) 
 //     {


         glColor3f(1,1,1); 
         switch(detalization) 
         { 
            case WARE : 
			//	glCallList( LISTPOINT ); 
			//	glDisable(GL_LIGHTING);
			//	glColor3fv(colorplanet);
			//	glutWireSphere(radius, 20,20);
			//	break;
			case HIGH : 

				//	if(NUM)glBindTexture(GL_TEXTURE_2D,textemp);
				//	else 
				if(NUM<=4)
						glBindTexture(GL_TEXTURE_2D,texture[NUM]);
			
				/*
				 if(NUM>=GIANTSCOUNT) 
					 glBindTexture(GL_TEXTURE_2D, texture[9]);
				else if(NUM && NUM<GIANTSCOUNT) 
					glBindTexture(GL_TEXTURE_2D, texture[numTexture]);
				else 
					glBindTexture(GL_TEXTURE_2D, texture[10]);
*/

				glEnable(GL_TEXTURE_2D);
			//	cout<<"t="<<texture<<endl;


				glScalef(radius,radius,radius);
				glCallList(LISTPLANET);

				if(bVidelen && mapmode )
				{	glColor4f(0,1,0,0.5);
					glDisable(GL_LIGHTING);
					glEnable(GL_BLEND);
					glutWireSphere(1.1,8,8);
				}


            break; 
            case ASPOINT : 
				glCallList( LISTPOINT ); 
			break; 
			

		    } 
		

      glPopMatrix(); 



   } 
   void SimSimOpen() 
   { 
      opened = true; 
      if ( Type == ISPORTAL) 
      { ChangeName(); radius = 2; 
      } 
      else 
      { 
         if ( _0v1 && _0v1 ) 
         { Type = ISDOCTOR; name[0] = ' + '; name[1] = '\0'; 
         } 
         else 
         { Type = ISENEMY; SetName(); 
         } 
      } 
   } 
   /* void TimerBeetwinFire() 
   { 
      showfire = 10; 
      pogrx = minirand() - 0.5; 
      pogry = minirand() - 0.5; 
      pogrz = minirand() - 0.5; 
   } 
   */ 
   void ShowFire() 
   { 
      glPushMatrix(); 
//      Laser(x,y,z,goalx,goaly,goalz); 
      float xr = ( rand()%30 - 14); 
      float yr = ( rand()%30 - 14); 
      glViewport ( xr,yr,SSX + xr,SSY + yr); 
      glPopMatrix(); 
   } 
   void ShowDoctor() 
   { 
      glPushMatrix(); 
//      Doctor(x,y,z,goalx,goaly,goalz); 
      glPopMatrix(); 
   } 
   int GetPos(int mode) 
   { static double mv[16],pm[16]; 
      static int vp[4]; 
      static double winx,winy,winz; 
      glGetDoublev(GL_MODELVIEW_MATRIX, mv); 
      glGetDoublev(GL_PROJECTION_MATRIX,pm); 
      glGetIntegerv(GL_VIEWPORT,vp); 
      gluProject(x,y,z,mv,pm,vp,&winx,&winy,&winz); 
      switch(mode) 
      { case GETX : return winx; 
         case GETY : return SSY-winy; 
         case GETZ : return winz; 
         default : return 0; 
      } 
   } 

	void Processing()
	{	
			if(mouseLeftButton && !mouseRightButton)
			{
					for(int i=0;i<UFOCOUNT;i++)
					{
					  if(	GetPos(GETZ)==0	 &&			 
						  GetPos(GETX)>MIN(fixPX,::p.x) && GetPos(GETX)<MAX(fixPX,::p.x)	&& 
						  GetPos(GETY)>MIN(fixPY,::p.y) && GetPos(GETY)<MAX(fixPY,::p.y)	||
						  fabs(::p.x-GetPos(GETX))<(300/ZDIST) && 
						  fabs(::p.y-GetPos(GETY))<(300/ZDIST))
							{
								bVidelen = true;
	
					
							}
					  else	  bVidelen = false;
					}
			}
	
			if(bFocus)
			{

				 if(focus.x>x) focus.x -= 0.1*fabs(x-focus.x);
				 if(focus.y>y) focus.y -= 0.1*fabs(y-focus.y);
				 if(focus.z>z) focus.z -= 0.1*fabs(z-focus.z);

				 if(focus.x<x) focus.x += 0.1*fabs(x-focus.x);
				 if(focus.y<y) focus.y += 0.1*fabs(y-focus.y);
				 if(focus.z<z) focus.z += 0.1*fabs(z-focus.z);

				 focus.x += dx;
				 focus.y += dy;
				 focus.z += dz;

				 focus.a = radius;

			}
		
	}
}; 


//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////




double solradius; 



#define MACROCALCSPEED speed[i] =   sqrt(MASS_OF_SOL) / sqrt(rasst(xx,yy,zz,0,0,0)) 


double DISTANCE(PLANET *a,PLANET *b) 
{ 
   return rasst(a -> x,a -> y,a -> z,b -> x,b -> y,b -> z); 
} 
void CreatePlanets(int kol) 
{ //delete[] b;
 // delete[] body;
 


   double soldiam = 100 + minirand() * 200;; 

   if ( StarGigant) 
		soldiam = 10000 + minirand() * 3000; 
 


	
   b[0] = new PLANET("info/venus.txt","Солнце"); 
   b[0] -> setPL(7000,0,0,0,0,0,1,1,1,MASS_OF_SOL,0,0); 
   E_planet[0] = 1; 



   double xx = 0,yy = 0,zz = 0; 
   double ae; 
 //  if ( StarGigant) ae = 40000 + rand()%5000; 
 
  // else    
	   ae =  100000; 


  
   double rasst_to_sol = ae; 
   double degree_to_sol; 
   double speed[1000]; 

   if(StarGigant) rasst_to_sol = 10000; 
 


   for ( int i = 1;i < kol;i ++ ) 
   { 
  //    if(StarGigant) 
	//  rasst_to_sol += 5000 ; 
	//  else 
	//	  rasst_to_sol = 0.4 + 0.3*ae*pow(2,i); 

	   rasst_to_sol *= 1.4 ;
      degree_to_sol = rand()%360; 

  
	  double radius;
	  double massa;

	  
	  if(i<GIANTSCOUNT)
	  { radius= 100+minirand()*100;
	      xx = ( rasst_to_sol)*sin(degree_to_sol*PO180); 
		  yy = ( rasst_to_sol)*cos(degree_to_sol*PO180);  
		  zz = 0; 
		  massa=radius*10;
	  }
	  else
	  {
		  radius= 50+minirand()*50; 
		  double t=5000+minirand()*100000;
	      xx = t*sin(degree_to_sol*PO180); 
		  yy = t*cos(degree_to_sol*PO180);  
		  zz = minirand()*20000 ;
		  massa=radius*10;
	  }


      MACROCALCSPEED; 
    


	  switch (i)
	  {
		case 1:	b[i] = new PLANET("info/mercury.txt","Меркурий"); break;
		case 2:	b[i] = new PLANET("info/venus.txt","Венера"); break;
		case 3:	b[i] = new PLANET("info/earth.txt","Земля"); break;
		case 4:	b[i] = new PLANET("info/mars.txt","Марс"); break;

		case 5:	b[i] = new PLANET("info/jupiter.txt","Юпитер"); break;
		case 6:	b[i] = new PLANET("info/saturn.txt","Сатурн"); break;
		case 7:	b[i] = new PLANET("info/uranus.txt","Уран"); break;
		case 8:	b[i] = new PLANET("info/neptune.txt","Нептун"); break;
		case 9:	b[i] = new PLANET("info/pluto.txt","Плутон"); break;

		default : b[i] = new PLANET("info/_.txt",""); break;
	  
	  }

      b[i] -> setPL ( radius, 
					  xx,yy,zz, 
					  ugol(0,0,xx,yy) + 90, 
					  speed[i], 
					  minirand()*0.3, 
					  minirand()*0.3, 
					  minirand()*0.3, 
					  massa, 
					  i, 
					  0 
					  ); 
      b[i] -> rasst_do_solnca = rasst_to_sol; 
      E_planet[i] = 1; 
	  


   } 
   /*
   xx = yy = zz = 0; 
   for ( i = (GIANTSCOUNT + kol)/2;i < kol;i ++ ) 
   { 
      double radius = 20 + minirand() * 50; 
      // int tempi=pokrugu(GIANTSCOUNT-1);   
      int tempi = 1 + rand()%(GIANTSCOUNT-1); 
      xx = b[tempi] -> x + rand()%2000-1000; 
      yy = b[tempi] -> y + rand()%2000-1000; 
      zz = b[tempi] -> z + rand()%2000-1000; 
     // MACROCALCSPEED; 
      // b[i]=new PLANET(radius, xx,yy,zz);   
      // double dop =  sqrt(b[tempi]->massa)/sqrt(DISTANCE(b[tempi],b[i]));   
      b[i] = new PLANET(); 
      b[i] -> setPL( radius, 
					  xx,yy,zz, 
					  minirand()*360, 
					  -minirand(), 
					  minirand(), 
					  minirand(), 
					  minirand(), 
					  radius*0.5, 
					  i, 
					  tempi 
					  ); 
      E_planet[i] = 1; 		  

   } 
  */


} 

void GeneratePortalSystem() 
{ 
   for ( int i = GIANTSCOUNT;i < PLANET_COUNT;i ++ ) 
   { //b[i]->num_dest=1+rand()%(GIANTSCOUNT-1);   
      if ( E_planet[i]) 
      { b[i] -> Type = ISPORTAL; 
         b[b[i] -> KOMU] -> portalcount ++; 
         break; 
      } 
   } 
   // for(int i=GIANTSCOUNT;i<PLANET_COUNT;i++)   
   // {    
   for ( int j = GIANTSCOUNT;j < PLANET_COUNT;j ++ ) 
   //  if(b[j]->isportal /*&& b[i]->isportal*/)   
   //  { // b[i]->num_dest=j;   
   //b[j]->num_dest=i;   
   b[j] -> num_dest = rand()%GIANTSCOUNT; 
   //  }   
   // }   
} 
void ShowLoading(int); 

class Tower;
void GenerateStarSystem() 
{ 

	pos0[0] = 1000000+minirand()*2000000;
	pos0[1] = 1000000+minirand()*2000000;
	pos0[2] = 100000+minirand()*1000000;

	pos0[0] = 0;
	pos0[1] = 0;
	pos0[2] = 0;


	StarGigant=0;//_0v1;


   for ( int i = 0;i < 1000;i ++ ) 
	   E_planet[i] = 0; 
   Level ++; 
 

   GIANTSCOUNT = 10;

 //  ASTEROIDSCOUNT = GIANTSCOUNT; 

   PLANET_COUNT = GIANTSCOUNT;// + ASTEROIDSCOUNT; 

 

   CreatePlanets ( PLANET_COUNT); 
 
   b[0]->bVidelen = true;

   if(!StarGigant)
   {
	   CreateOreol(2000000+minirand()*100000); //2000  
	   CreateLuchi(50000+minirand()*100000); 
   }


   for ( int n = 0; n < PLANET_COUNT; n ++ ) 
   { 
      body[n].setPos(b[n] -> x, b[n] -> y,b[n] -> z); 
      body[n].setDelta( b[n] -> dx,b[n] -> dy, b[n] -> dz); 
      body[n].setMassa( b[n] -> massa); 
      body[n].setRadius(b[n] -> radius);  
      body[n].setElasticity(0);
      body[n].setFriction(0.05);

   } 



 
 //  fclose(outfile);

   //read_ini();   
 //  cout << endl; 
 //  otsch = 10000; 
 //  putchar('\n'); 
 //  printf("Loading music..."); 
 //  GeneratePortalSystem(); 
   
   //int tmpn = 1 + rand()%(GIANTSCOUNT - 1); 
   

   SetActiveWindow(FindWindow(NULL,"GLUT")); 
   SetForegroundWindow(FindWindow(NULL,"GLUT")); 


   float dif[4] = 
   { 
      2, 
      2, 
      2, 
      1 
   }; 
  // float dif[4]={1,1,1,1};   
   glLightfv ( GL_LIGHT1, GL_DIFFUSE, dif); 
   glLightModelfv ( GL_LIGHT_MODEL_AMBIENT,L_lightmodel); 

   CreateStars(); 


   int nn = 1;//1 + rand()%(GIANTSCOUNT-1);

   if(0)
   {
		CreateMyShip(minirand()*100000-50000,minirand()*100000-50000,minirand()*100000-50000,0);	   
   }
   else
   {
		CreateMyShip(body[nn].x,body[nn].y-100,body[nn].z+body[nn].radius*10.1,nn);	   
   }



   tower->isBuild = true;
   tower->x =  body[nn].x;
   tower->y =  body[nn].y;
   tower->z =  body[nn].z+body[nn].radius;

   zavod->isBuild = true;
	zavod->x =  body[nn].x;
   zavod->y =  body[nn].y;
   zavod->z =  body[nn].z+body[nn].radius;

   ro = minirand(); 
   go = minirand(); 
   bo = minirand(); 


  // CreateGruzovik();
 //  CreateMySphere(400);
   CreateUFOs(); 


   ufo[0] -> Born(TYDIRIUM,true); 
   ufo[0] -> SetPos(zavod->x,zavod->y,zavod->z); 
                
   ufo[1] -> Born(TIEFIGHTER,true); 
   ufo[1] -> SetPos(tower->x,tower->y,tower->z); 


 /*  fogColor[0]=ro;
   fogColor[1]=go;
   fogColor[2]=bo;

glFogfv(GL_FOG_COLOR, fogColor);        // Устанавливаем цвет тумана
*/

   //delete [] body;
} 

#endif
