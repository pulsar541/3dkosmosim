#ifndef _ufo_h_
#define _ufo_h_ 

#include "data.h"
#include "pyl.h"


class UFO 
{
public:


 	double oldx,oldy,oldz;	
	double x,y,z;				
	double goaldx,goaldy,goaldz;
	double dx,dy,dz;

	double massa,speed;	

	int showfire;
	int i,k;

	bool fireing;
	bool bPolnyi;

	MYPOINT p3d[10000];
	int NUM;			// номер   корабля
	int timer;

	bool ver;
	bool E;
	float color[3];

	bool fastspeed;
	bool active;
	bool bVidelen;
	bool bFocus;
	int numgoto;
	int numResPlanet;
	double oldr;


	Pyl		 *pyl[100];

	 int numpyl;
	 int counter;

	 double dposx;
	 double dposy;

	 double XDEST;
	 double YDEST;
	 double ZDEST;

	 double DistToMe;

	 double DistToDest;

	 int numList;


 UFO(  double x0,double y0,double z0,
	   double ugol,
	   double startglobalspeed,
	   double m,
	   int num)
	{

	 dposx = minirand()-0.5;
	 dposy = minirand()-0.5;

	 bPolnyi = false;

	 numgoto = 2;
	 timer=400;
		  NUM=num;
		
	  numpyl=0;
	  counter = 0;
	//	  pyl = new Pyl[100];
	

	  bVidelen = false;
 	  bFocus = false;
 
	  numResPlanet=0;

		  x=x0;
		  y=y0;
		  z=z0;
	
//	  for(int i=0;i<10000;i++) 
//		   p[i].x=p[i].y=p[i].z=0;


			ver=0;
			showfire=0;
		  dx=1;
		  dy=1;
		  dz=1;
		  massa=m;

		  color[0]=0.8;
		  color[1]=0.8;
		  color[2]=0.8;
	
		  oldx=x0+1;
		  oldy=y0+1; 
		  oldz=z0+1; 

	 E=true;
	 fastspeed=true;

	 k=i=0;
	 active=false;
			


	}

	void Born(int numList,bool mode)
	{
		for( i=0;i<100;i++)
		{pyl[i]=new Pyl(1);
		 
		}


		active=true;


		this->numList = numList;


		GoTo(mmm[12],mmm[13],mmm[14]);
	}


	void StandartShow()
	{
			
	//	static int rot=0;
	//	if(rot++>360) rot=0;
		
		if(active)
		{
		

			if((bVidelen || m_button) && (XDEST!=x || YDEST!=y || ZDEST!=z ))
			{
				glDisable(GL_LIGHTING);
				glColor3f(0.3,0,0.3);
				glBegin(GL_LINES);
				glVertex3d(x,y,z);
				glVertex3d(XDEST,YDEST,ZDEST);
				glEnd();
				glPushMatrix();	
				glTranslatef(XDEST,YDEST,ZDEST);
				glutWireCube(5);
				glPopMatrix();

			}

		}
	}

	void StandartMove()
	{
		 goaldx=XDEST-this->x;
		 goaldy=YDEST-this->y;
		 goaldz=ZDEST-this->z;

	/*	 if(dx>goaldx)  dx-=0.03;
		 if(dy>goaldy)  dy-=0.03;
		 if(dz>goaldz)  dz-=0.03;	
		 if(dx<goaldx)  dx+=0.03;
		 if(dy<goaldy)  dy+=0.03;
		 if(dz<goaldz)  dz+=0.03;
*/
	//	 if(fabs(x-XDEST)>5) 
			 x+=dx;
	//	 if(fabs(y-YDEST)>5) 
			 y+=dy;
	//	 if(fabs(z-ZDEST)>5) 
			 z+=dz;	
		 
		 if(fabs(x-XDEST)<5 && fabs(y-YDEST)<5 && fabs(z-ZDEST)<5)
		 {	 XDEST = x;
			 YDEST = y;
			 ZDEST = z;
		 }

		 
	}

	
	void Show()
	{

	if(active)
		{
			StandartShow();

			glPushMatrix();
			glTranslated (x,y,z);

				double C=rasst(x,y,z,x+dx,y+dy,z+dz);
				double A=dz;
				double ugol_1 = ugol(x+dx,y+dy,x,y);
				double ugol_2 = asin(A/C)*_180oP;
 
				glRotatef(ugol_1,0,0,1);
				glRotatef(ugol_2-90,0,1,0);
		
				glColor4f(0.2,0.2,0.2,0);
				glCallList(numList);	
			
				if( bVidelen) 
				{		
					glColor3f(0,0.5,0);
					glPushMatrix(); 
					glDisable(GL_LIGHTING);
					if(numList==TYDIRIUM)		  
					{	 // glScalef(0.01,0.01,0.01);
						glScalef(
							  tydirium.aabb_max[0]-tydirium.aabb_min[0],
							  tydirium.aabb_max[1]-tydirium.aabb_min[1],
							  tydirium.aabb_max[2]-tydirium.aabb_min[2]
							  );
	
	

					}
					if(numList==TIEFIGHTER)	 
					{	//  glScalef(0.5,0.5,0.5);
						glScalef(
							  tiefighter.aabb_max[0]-tiefighter.aabb_min[0],
							  tiefighter.aabb_max[1]-tiefighter.aabb_min[1],
							  tiefighter.aabb_max[2]-tiefighter.aabb_min[2]
							  );
	
					}
					  glutWireDodecahedron();
					  glPopMatrix(); 
				}
				
				if(numList==TYDIRIUM)
				{	
					float div[4]={1,1,0.3,1};
							glMaterialfv		(GL_FRONT_AND_BACK, GL_DIFFUSE,div);
				
				}
			
				if(numList==TIEFIGHTER)
				{	
					float div[4]={0.3,0.3,0.3,1};
							glMaterialfv		(GL_FRONT_AND_BACK, GL_DIFFUSE,div);
				
				}

				if(bVidelen) 	
						glColor3f(0,1,0);
				else glColor3f(0,0,1);

				glPointSize(2);
				glDisable(GL_DEPTH_TEST);

				glCallList(LISTPOINT);
						///////////////////////	
					
				glEnable(GL_DEPTH_TEST);
				glDisable(GL_CULL_FACE);
				glEnable(GL_BLEND);
				glDisable(GL_LIGHTING);

				
			glPopMatrix();
			///////////////////////



			if(fabs(x-XDEST)>1 || fabs(y-YDEST)>1 || fabs(z-ZDEST)>1)
				{

						glPushMatrix();
						for ( int i = 0; i < 100; i ++ ) 
								pyl[i]->show(); 
						glPopMatrix();
				}


		}
	}
	
	void Move()
	{
		if(active)
		{

		StandartMove();


			switch(numList)
			{
				//----------------
				case TYDIRIUM:


					if(numResPlanet==0)
						numResPlanet=1;


					if(isOnPlanet(1)) 
					{ 
						numgoto = numResPlanet;

						if(bPolnyi && numResPlanet>1)
							RESOURCES++; 

				//		dx=dy=dz=0;
					}
				//	else 
						/////////////////////if(numgoto != 1 )
				//			bPolnyi = false;

					if(isOnPlanet(numResPlanet)) 
					{
						numgoto = 1;
						bPolnyi = true;
						dx=dy=dz=0;
					}
				
				
				
					if(numResPlanet>1)
					GoTo(body[numgoto].x,body[numgoto].y,body[numgoto].z);
					


					break;
				//----------------
				}//endswintch
			
			
		}
	}

	void Processing()
	{	if(active)
		{
		
				
			oldr = DistToDest;
			DistToDest = rasst (x,y,z,goaldx,goaldy,goaldz);

		//	if(mouseLeftButton  ) 		
		//	{
			
		//	}

	
			if(mouseLeftButton)
			{
					for(int i=0;i<UFOCOUNT;i++)
					{
					  if(	GetPos(GETZ)==0	 &&			 
						    GetPos(GETX)>MIN(fixPX,p.x) && GetPos(GETX)<MAX(fixPX,p.x)	&& 
							GetPos(GETY)>MIN(fixPY,p.y) && GetPos(GETY)<MAX(fixPY,p.y)	||
							fabs(p.x-GetPos(GETX))<(300/ZDIST) && 
							fabs(p.y-GetPos(GETY))<(300/ZDIST))
							{
								bVidelen = true;
							}
					  else	
						  if(!m_button )
						  {   bVidelen = false;

							  if(numList == TYDIRIUM)
							  {
								  for(int i=0;i<PLANET_COUNT;i++)
								  {
									  if(vid[i])
									  {
										 numResPlanet = i; 
										 if (!bPolnyi) numgoto = i;
									//	 bVidelen = true;
										  break;
									  }
								  }
							

							  }
							 
						  }
					}
			}


			if(oldr<DistToDest) 
			{
					dx*=0.994;
					dy*=0.994;		
					dz*=0.994;
			}


				double tx = x+dx*500 ;
				double ty = y+dy*500 ;
				double tz = z+dz*500 ;

				double tx2 = x+dx*100 ;
				double ty2 = y+dy*100 ;
				double tz2 = z+dz*100 ;

				for(int i=0;i<PLANET_COUNT;i++)
				{
					if(E_planet[i])
					{
						if(simple_rasst(tx,ty,tz,body[i].x,body[i].y,body[i].z,body[i].radius))
						{
							dz +=0.1;
							break;
						}

						if(simple_rasst(tx2,ty2,tz2,body[i].x,body[i].y,body[i].z,body[i].radius))
						{
							dz +=0.1;
							break;
						}

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
				 focus.a = 5;

			}


		
			
			pyl[numpyl]->setCoord(x, y, z);
			  numpyl++; 
			  if(numpyl>99) 
				   numpyl=0;

		}
	}

	void GoTo(double xd,double yd,double zd)
	{	
		XDEST = xd;
		YDEST = yd;
		ZDEST = zd;
	}


	void SetPos(double x,double y,double z)
	{
		this->x=x;
		this->y=y;
		this->z=z;
	}


	void SetDelta(double dx,double dy,double dz)
	{
		this->dz=dx;
		this->dy=dy;
		this->dz=dz;
	}

	bool isOnPlanet(int num)
	{bool result=false;
	
		static double R=0;

		double oldr = R;

	if((R=rasst(body[num].x,body[num].y,body[num].z,x,y,z))<body[num].radius*1.1)
		result=true;

		if(oldr<R) 
		{
			dx*=0.995;
			dy*=0.995;		
			dz*=0.995;
		}

		return 	result;
	}



int GetPos(int mode) 
	{static double mv[16],pm[16];
	 static int vp[4];
	 static double  winx,winy,winz;

	 glGetDoublev(GL_MODELVIEW_MATRIX, mv);
	 glGetDoublev(GL_PROJECTION_MATRIX,pm);
	 glGetIntegerv(GL_VIEWPORT,vp);
	 gluProject(x,y,z,mv,pm,vp,&winx,&winy,&winz);

	 switch(mode)
	 {case GETX: return winx;
	  case GETY: return SSY-winy;
	  case GETZ: return winz;
	  default  : return 0;
	 }
	}


 void del()
 {
   active=false;
 }


};

void	CreateUFOs()
	{

	for(int i=0;i<UFOCOUNT;i++)
		{ufo[i]=//(RESER*)
		new UFO(
		mmm[12]+rand(),
		mmm[13]+rand(),
		mmm[14]+rand(),
		ugol(0,0,ship_start_positioin_x,ship_start_positioin_y)+90,
		0,
		0.00000001,
		MYSHIPNUM+1);
/*
fighter[i]=(FIGHTER*)new UFO(
		mmm[12]+rand(),
		mmm[13]+rand(),
		mmm[14]+rand(),
		ugol(0,0,ship_start_positioin_x,ship_start_positioin_y)+90,
		0,
		0.00000001,
		MYSHIPNUM+1);
*/
		}



	}



#endif
