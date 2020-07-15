#ifndef _objects_h_
#define _objects_h_


#define		LISTPLANET			 1000
#define		LISTSIMPLESPHERE	 3300
#define		LISTPOINT			 2001
#define		LISTPOINT2			 2004
#define		STARS				 2101
#define		OREOL				 2200
#define		LUCHI				 2300
#define		ATMOSPHERE			 2330
#define		GIANTCUBE			 2400
#define		RING				 5500
#define		ASTEROID			 2600
#define		PORTAL				 2700
#define		DOCTOR				 2800
#define		PLAZMA				 2900
#define		GRUZOVIK			 3001

#define		TIEFIGHTER			 4000
#define		TYDIRIUM			 4001



aselib::MESH tydirium;
aselib::MESH tiefighter;


void CreatePlanet()
{
	  qobj = gluNewQuadric();
	  gluQuadricTexture (qobj, GL_TRUE);
   
		 glNewList(LISTPLANET,GL_COMPILE); 
		 	 glEnable(GL_LIGHTING); 
 			 glEnable(GL_TEXTURE_2D);
			 glEnable(GL_CULL_FACE);
			 glCullFace(GL_BACK);
			 glDisable(GL_BLEND); 
			 glColor3f(1,1,1); 

			 glPushMatrix(); 
			 gluSphere ( qobj, 1.0f, detalization, detalization);
			 glDisable(GL_TEXTURE_2D);

			 glPopMatrix(); 
         glEndList(); 

}


void CreateShips()
{	

	if(!tiefighter.Load("models/stels.ASE"))
	{
		MessageBox(NULL,"models/stels.ase","models/stels.ase",MB_OK);
		exit(0);
	}
	glNewList(TIEFIGHTER,GL_COMPILE);
		glDisable(GL_TEXTURE_2D);	// Разрешение наложение текстуры
		glDisable(GL_BLEND);
		glEnable(GL_LIGHTING);
//		glColor3f(1,1,1);
		glScalef(0.25,0.25,0.25);
		glRotatef(90,1,0,0);
		glRotatef(90,0,1,0);
		glRotatef(-90,0,0,1);
		tiefighter.Draw();
	glEndList();

	
	if(!tydirium.Load("models/tydirium.ase"))
	{		MessageBox(NULL,"models/tydirium.ase","models/tydirium.ase",MB_OK);
		exit(0);
	}

	glNewList(TYDIRIUM,GL_COMPILE);
		glDisable(GL_TEXTURE_2D);	// Разрешение наложение текстуры
		glDisable(GL_BLEND);
		glEnable(GL_LIGHTING);
	//	glColor3f(0,0,0);
		glScalef(0.01,0.01,0.01);
		glRotatef(-90,1,0,0);
		glRotatef(90,0,1,0);

		tydirium.Draw();
	
	glEndList();

	

//	tydirium.Unload ();
	tiefighter.Unload ();

}

void CreatePoint()
{static double vertex0[3]={0,0,0};
 static double vertex1[3]={0,0,2};
 static double vertex2[3]={0,0,-2};
 
 glNewList(LISTPOINT,GL_COMPILE);
 glDisable(GL_LIGHTING);
 glDisable(GL_TEXTURE_2D);	// Разрешение наложение текстуры
		
 //glColor3f(1,1,1);
  glBegin(GL_POINTS);
   glVertex3dv(vertex0);
  glEnd(); 
 glEnable(GL_LIGHTING); 
 glEndList();
 //////////////
 glNewList(LISTPOINT2,GL_COMPILE);
 glDisable(GL_LIGHTING);
 //glEnable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);	// Разрешение наложение текстуры
		
 glEnable(GL_DEPTH_TEST);
  glBegin(GL_POINTS);
  glVertex3dv(vertex0);
  glVertex3dv(vertex1);
  glVertex3dv(vertex2);
  glEnd(); 

 glDisable(GL_DEPTH_TEST);
 //glDisable(GL_BLEND);
 glEnable(GL_LIGHTING); 
 glEndList();

}


void CreateAsteroid()
{
	glNewList(ASTEROID,GL_COMPILE);
		glPushMatrix();
	glColor3f(0.5,0.5,0.5);
//	glScalef(2,2,2);
	glDisable(GL_TEXTURE_2D);	// Разрешение наложение текстуры
		
			for(int i=0;i<10;i++)
				{ 
					glRotatef(rand()%100,1,0,0);
					glRotatef(rand()%100,0,1,0);					
					glutSolidDodecahedron();		
				}
			
			glPopMatrix();
	glEndList();

}


void CreateGiantCube()
{static float vertex[3]={0,0,0};
 glNewList(GIANTCUBE,GL_COMPILE);
 glDisable(GL_TEXTURE_2D);	// Разрешение наложение текстуры
		
 glPushMatrix();
 glLoadIdentity();
 glutSolidCube(LIMITSPACE*100); 

 glPopMatrix();
 glEndList();
}


void CreateSimpleSphere()
{
 glNewList(LISTSIMPLESPHERE,GL_COMPILE);
 glDisable(GL_LIGHTING);
 glDisable(GL_TEXTURE_2D);	// Разрешение наложение текстуры
 glEnable(GL_BLEND);		
 glutSolidSphere(1,20,20); 
 glEnable(GL_LIGHTING);
 glEndList();

}



void CreateRing()
{

 glNewList(RING,GL_COMPILE);
 glDisable(GL_LIGHTING);
// glEnable			(GL_LINE_SMOOTH);
 glEnable			(GL_BLEND);
 glDisable(GL_TEXTURE_2D);	
  
	glBegin(GL_LINES);
		for(int u=-1;u<360;u++)
		{	glVertex3f(cos(PO180*u),sin(PO180*u),0); 
		}
	glEnd();
 glEndList();


 glNewList(RING+1,GL_COMPILE);
 glDisable(GL_LIGHTING);
// glEnable			(GL_LINE_SMOOTH);
 glEnable			(GL_BLEND);
 glDisable(GL_TEXTURE_2D);	
 
	glBegin(GL_LINES);
		for( u=-1;u<360;u++)
		{	glVertex3f(cos(PO180*u),sin(PO180*u),0); 
		}
	glEnd();

 glEndList();


}


void getnorm (double a[3],double b[3],double c[3],double *n)
{
double mult=0;
//-- a - общая вершина двух векторов --// 
n[0]=(b[1]-a[1])*(c[2]-a[2])-(b[2]-a[2])*(c[1]-a[1]);
n[1]=(c[0]-a[0])*(b[2]-a[2])-(b[0]-a[0])*(c[2]-a[2]);
n[2]=(b[0]-a[0])*(c[1]-a[1])-(c[0]-a[0])*(b[1]-a[1]);
//--Определение нужного направления нормали: от точки (0,0,0)---------//[/b]
for (int i=0;i<3;i++) mult+=a[i]*n[i];
if (mult<0) for (int j=0;j<3;j++) n[j]=-n[j];

glNormal3dv(n);

}


void setAutoNorm (double a[3],double b[3],double c[3])
{
double mult=0;
double n[3];
//-- a - общая вершина двух векторов --// 
n[0]=(b[1]-a[1])*(c[2]-a[2])-(b[2]-a[2])*(c[1]-a[1]);
n[1]=(c[0]-a[0])*(b[2]-a[2])-(b[0]-a[0])*(c[2]-a[2]);
n[2]=(b[0]-a[0])*(c[1]-a[1])-(c[0]-a[0])*(b[1]-a[1]);
//--Определение нужного направления нормали: от точки (0,0,0)---------//[/b]
for (int i=0;i<3;i++) mult+=a[i]*n[i];
if (mult<0) for (int j=0;j<3;j++) n[j]=-n[j];

glNormal3dv(n);

}


void CreateAtmosphere(float red,float green,float blue,
					  double R,double H,
					  double kR,
					  double RASST)
{
 //glNewList(ATMOSPHERE,GL_COMPILE);
	glDisable(GL_TEXTURE_2D);	// Разрешение наложение текстуры
		
//	glDisable				(GL_DEPTH_TEST);
	glEnable				(GL_BLEND);
//	glDisable				(GL_CULL_FACE);
//	glDisable				(GL_LIGHTING);
	glBlendFunc				(GL_SRC_ALPHA,GL_ONE);	


						static double pv1x ;
						static double pv1y ;
						static double pv1z ;

						static double pv2x ;
						static double pv2y ;
						static double pv2z ;

						static double pv3x ;
						static double pv3y ;
						static double pv3z ;
	
						static double pv4x;
						static double pv4y;
						static double pv4z ;

	int delta = 5;

	glBegin(GL_QUADS);
  

		  for(int u=0;u<360;u+=delta)
			{ 			  
					  //
			  
							
						
						if(kR>1) 
							kR=1;

						double aprev[3]={cos(PO180*(u-delta))*R*kR,sin(PO180*(u-delta))*R*kR,0};
					
						pv1x = cos(PO180*u)*R*kR;//a
						pv1y = sin(PO180*u)*R*kR;
						pv1z = 0;

						pv2x = cos(PO180*(u+delta))*R*kR;//b
						pv2y = sin(PO180*(u+delta))*R*kR;
						pv2z = 0;

						pv3x = cos(PO180*(u+delta))*(R*kR);//c
						pv3y = sin(PO180*(u+delta))*(R*kR);
						pv3z = H;

						pv4x = cos(PO180*u)*(R*kR);//d
						pv4y = sin(PO180*u)*(R*kR);
						pv4z = H;

					double bnext[3]={cos(PO180*(u+delta+delta))*R*kR,sin(PO180*(u+delta+delta))*R*kR,0};
					double cnext[3]={cos(PO180*(u+delta+delta))*R*kR,sin(PO180*(u+delta+delta))*(R*kR),H};


						double a[3]={pv1x,pv1y,pv1z};
						double b[3]={pv2x,pv2y,pv2z};
						double c[3]={pv3x,pv3y,pv3z};
						double d[3]={pv4x,pv4y,pv4z};
						double n[3];

				


	/*
						glNormal3d(0,0,1);
						glColor4f(red,green,blue,1);	
						glVertex3dv(a);  	
					    glVertex3dv(b);							
						glColor4f(red,green,blue,0);
						 glVertex3dv(c);
						glVertex3dv(d);  
			
					 */
						glColor4f(red,green,blue,1);
					  setAutoNorm(aprev,b,c);
					  glVertex3f(cos(PO180*u)*R,sin(PO180*u)*R,0);  				  
					  setAutoNorm(a,bnext,cnext); 
					  glVertex3f(cos(PO180*(u+delta))*R,sin(PO180*(u+delta))*R,0);

					  glColor4f(0,0,0,0);
					  setAutoNorm(a,bnext,cnext); 
					  glVertex3f(cos(PO180*(u+delta))*R,sin(PO180*(u+delta))*R,H);	
					  setAutoNorm(aprev,b,c);
					  glVertex3f(cos(PO180*u)*R,sin(PO180*u)*R,H);  
					
						
	
		}

	glEnd(); 

//	glEnable				(GL_DEPTH_TEST);
	glDisable				(GL_BLEND);
//	glEnable				(GL_LIGHTING);

//glEndList();

}



void CreateOreol(double hr)
{


	
	int delta=20;

	for(int i=0;i<3;i++)
	{
	colororeol0[i]=0.2+minirand()*0.2;
	colororeol1[i]=0;
	}
	
	glNewList(OREOL,GL_COMPILE);
	glDisable(GL_TEXTURE_2D);	// Разрешение наложение текстуры
		
		//	glCullFace(GL_FRONT);

			glDisable				(GL_CULL_FACE);

			glDisable				(GL_DEPTH_TEST);
			glEnable				(GL_BLEND);
			glDisable				(GL_LIGHTING);
			glBlendFunc				(GL_SRC_ALPHA,GL_ONE);	
		//	glRotatef(90,0,1,0);
		

			 glBegin(GL_TRIANGLES);
				  			
				for(int u=0; u<360;u+=delta)
					{
					
					 glColor4fv(colororeol0);		
					 glVertex3f(0,0,0);
					 glColor4fv(colororeol1);		
					 glVertex3f(cos(PO180*u)*hr,
								 30000,
								 sin(PO180*u)*hr);  	

					  glVertex3f(cos(PO180*(u+delta*2))*hr,
								 30000,
						         sin(PO180*(u+delta*2))*hr
								 );
					// 	 if(360-u<=delta) delta=360-u;
					}
	

			glEnd();
			glEnable				(GL_DEPTH_TEST);
			glDisable				(GL_BLEND);
			glEnable				(GL_LIGHTING);


	glEndList();

}

void CreateLuchi(double hr)
{glNewList(LUCHI,GL_COMPILE);
	glDisable(GL_TEXTURE_2D);	// Разрешение наложение текстуры
		
	glDisable				(GL_DEPTH_TEST);
	glEnable				(GL_BLEND);
	glDisable				(GL_CULL_FACE);
	glDisable				(GL_LIGHTING);
	glBlendFunc				(GL_SRC_ALPHA,GL_ONE);	

	float r=1-minirand()*0.7;
	float g=1-minirand()*0.7;
	float b=1-minirand()*0.7;

	glBegin(GL_TRIANGLES);
		  for(int u=0;u<360;u+=36)
					{ 	
					  glColor3f(r,g,b);
					  glVertex3f(0,0,0);
					  glColor4f(0,0,0,0);	
					  glVertex3f(cos(PO180*u)*hr*5,0,sin(PO180*u)*hr*5);  				  
					  glVertex3f(cos(PO180*(u+36))*hr*5,0,sin(PO180*(u+36))*hr*5);
					}
	glEnd(); 

	glEnable				(GL_DEPTH_TEST);
	glDisable				(GL_BLEND);
	glEnable				(GL_LIGHTING);

glEndList();
}



void CreatePlazma()
{glNewList(PLAZMA,GL_COMPILE);
	

	glDisable				(GL_LIGHTING);
	glEnable				(GL_BLEND);

	glColor4f(1,1,1,1);
	glutSolidSphere(0.1,3,3);

	glColor4f(0,1,0,1);
	glutSolidSphere(0.2,3,3);

	glColor4f(0,1,0,0.05);
	glutSolidSphere(0.5,3,3);
	glEnable(GL_LIGHTING);

glEndList();
glNewList(PLAZMA+1,GL_COMPILE);
	

	glDisable				(GL_LIGHTING);
	glEnable				(GL_BLEND);

	glColor4f(1,1,1,1);
	glutSolidSphere(0.1,3,3);

	glColor4f(1,0,0,1);
	glutSolidSphere(0.2,3,3);

	glColor4f(1,0,0,0.01);
	glutSolidSphere(0.5,3,3);
	glEnable(GL_LIGHTING);

glEndList();
}



void CreatePortal()
{glNewList(PORTAL,GL_COMPILE);


	glColor3f(2,0,0);
	glutSolidTorus(0.1,3,8,20);
	glRotatef(90,0,1,0);
	glutSolidTorus(0.1,3,8,20);
	glRotatef(90,1,0,0);
	glutSolidTorus(0.1,3,8,20);

	glDisable				(GL_DEPTH_TEST);
	glEnable				(GL_BLEND);
	glDisable(GL_TEXTURE_2D);	// Разрешение наложение текстуры
		
	glDisable				(GL_LIGHTING);
	glBlendFunc				(GL_SRC_ALPHA,GL_ONE);	

//	glScalef(2,2,2);
	
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.2,0.2,0.2);  glVertex3f(0,0,0); 
		  for(int u=0;u<=360;u+=45)
					{ 
					  glColor4fv(colorsol1);
					  glVertex3f(cos(PO180*u),sin(PO180*u),0);  				  
					  glVertex3f(cos(PO180*(u+90)),sin(PO180*(u+90)),0);

					}
	glEnd();

	
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.2,0.2,0.2);  glVertex3f(0,0,0); 
		  for( u=0;u<=360;u+=45)
					{ 
					  glColor4fv(colorsol1);
					  glVertex3f(cos(PO180*u),0,sin(PO180*u));  				  
					  glVertex3f(cos(PO180*(u+90)),0,sin(PO180*(u+90)));

					}
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
			glColor3f(0.2,0.2,0.2);  glVertex3f(0,0,0); 
		  for( u=0;u<=360;u+=45)
					{ 
					  glColor4fv(colorsol1);
					  glVertex3f(0,cos(PO180*u),sin(PO180*u));  				  
					  glVertex3f(0,cos(PO180*(u+90)),sin(PO180*(u+90)));

					}
	glEnd(); 


	

	glEnable				(GL_DEPTH_TEST);
	glDisable				(GL_BLEND);
	glEnable				(GL_LIGHTING);

glEndList();
}



void CreateDoctor()
{	glNewList(DOCTOR,GL_COMPILE);
		glPushMatrix();
		glEnable(GL_TEXTURE_2D);
		glDisable(GL_BLEND);
		glDisable(GL_LIGHTING);
/*		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 
												tex_image[7]->sizeX, 
												tex_image[7]->sizeY, 
												0, GL_RGB, GL_UNSIGNED_BYTE, 
												tex_image[7]->data);
												*/
		gluSphere (qobj, 2, 8, 8);
		glEnable(GL_BLEND);
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		glColor4f(0.1,0.2,0.1,0.2);
		glutSolidSphere(20,20,20);
		glEnable(GL_LIGHTING);
		glDisable(GL_CULL_FACE);
		glDisable(GL_TEXTURE_2D);	
		glPopMatrix();				 
	glEndList();
}

#include<fstream>
using namespace std;
void CreateStars()
{
	
	
	std::ofstream stream;
	stream.open("stars.dat");
	

	if(!stream.is_open())
	{
		return;
		
	}
	double temp;
			glNewList(STARS,GL_COMPILE);
			glPushMatrix();
	
 static int du=0;	

	//	glDisable				(GL_BLEND);	
		   glEnable(GL_BLEND); 	
		//	glCullFace(GL_FRONT);
			glDisable(GL_LIGHTING);
			glDisable(GL_TEXTURE_2D);
			glDisable(GL_DEPTH_TEST);
		   // glEnable(GL_POINT_SMOOTH); 						
	
			glDisable				(GL_BLEND);	
			glPointSize(1);

			int deltaK = rand()%20;
			unsigned int count = 0;

			for(int k=0;k<360;k+=deltaK)
			{
				
				deltaK = rand()%30;

				glRotated(k,0,1,0);

				stream << "rotate " << deltaK << " 0 1 0 " << endl; 

				int deltaV = rand()%20;

				for(int v=0;v<360;v+=deltaV)
				{	
					
					deltaV = rand()%30;
					glRotated(v,0,0,1);
					stream << "rotate " << deltaV << " 0 0 1 " << endl; 
					glBegin(GL_POINTS);
					for(int u=0;u<360;u+=rand()%20)	 
					{	double t=0.1+minirand()*0.2;
						glColor3d(t,t,t);	
						stream << "color " << t << " " << t << " "<< t << " " << endl; 

						float x,y,z;

						x = -cos(PO180*u)*(300000);
						y = 0;
						z = -sin(PO180*u)*(300000);

						glVertex3f(x,y,z);count++;


						stream << "localcoord " << x << " " << y << " "<< z << " "<<endl;

					}
					glEnd();
				}
			}

			stream << "numverts " << count << " "<<endl;
			glEnable(GL_DEPTH_TEST);


		//	glEnable				(GL_BLEND);			
			glPopMatrix();

			glEnable(GL_LIGHTING);	
			glEndList();
			
	stream.close();
			
	
}

void CreateGruzovik()
{//	glNewList (GRUZOVIK,GL_COMPILE);
//		Load3d("GRUZOVIK.ASC",100,TYPE_POLYGONS);
//	glEndList();
}



void MyVertexFor(double i,double j,double radius)
{

	double x = radius * cos(j) * cos(i);
	double y = radius * cos(j) * sin(i);
	double z = radius * sin(j);

	glVertex3f(x,y,z);

}
/*

  

*/



void CreateMySphere(double radius)
{
	double j_step = 3.1415926 / 40; 
	double i_step = 3.1415926 / 40; 

//	glNewList (12345,GL_COMPILE);

	glColor3f(minirand()*0.5,minirand()*0.5,minirand()*0.5);

	
	for (double j = - 3.1415926; j < 3.1415926 ; j += j_step) 
		{ 
 		
			for (double  i = 0; i < 3.1415926; i += i_step) 
			{ 


	
			glBegin(GL_LINES);   
						MyVertexFor( i,j,radius) ;
						MyVertexFor( i + i_step, j,radius); 
			glEnd();
		
			glBegin(GL_LINES);   
						MyVertexFor( i,j,radius) ;
						MyVertexFor( i, j+ j_step,radius); 
			glEnd();
	
			glBegin(GL_LINES);   
						MyVertexFor( i,j,radius) ;
						MyVertexFor( i+ i_step, j+ j_step,radius); 
			glEnd();


/*
	
			glBegin(GL_TRIANGLES);
			
			glColor3f(minirand(),minirand(),minirand());
			MyVertexFor( i , j,radius); 			
			MyVertexFor( i, j+ j_step,radius);						
			MyVertexFor( i+ i_step, j,radius); 
		
			glColor3f(minirand(),minirand(),minirand());
			MyVertexFor( i+ i_step, j+ j_step,radius); 
			MyVertexFor( i, j+ j_step,radius);						
			MyVertexFor( i+ i_step, j,radius); 


			glEnd();
*/

			} 

		}	
//	glEndList();
}


void CreateGiantSol()
{
  qobj = gluNewQuadric();
  gluQuadricTexture (qobj, GL_TRUE);

	 glNewList(54321,GL_COMPILE); 
		 	 glDisable(GL_LIGHTING); 
 			 glEnable(GL_TEXTURE_2D);
		 //	 glDisable(GL_DEPTH_TEST);
			 glColor3f(1,1,1); 
			 gluSphere ( qobj, 7000, detalization, detalization);
			 glDisable(GL_TEXTURE_2D);
		//	 glEnable(GL_DEPTH_TEST);
	
     glEndList(); 
}


#endif
