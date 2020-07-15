#include	"lib.h"



int kolplanet=10;
int    RRR=2000; //для "лук ат"
double KOEFFICIENT=15000;   //коэффициент силы притяжения
bool WithTraectory=1;
bool lb_sol=0;          //признак "хватания солнца мышкой"
bool stop=0;            //признак остановки времени
double solX=0;   //
double solY=0;   // координаты солнца
int rsol=30;             // радиус солнца
int detalization=20;

int rotateX=0;
int rotateY=0;
int rotateZ=0;

#include	"planet.h"




void		Draw	();
void		Idle	();
void		Reshape	(int w,int h);


PLANET *b[1000];


void	Reshape	(int w,int h)
{	//	функция вызывается при изменении размеров окна
	glViewport		(0,0,w,h);			//	новый размер окна
	glMatrixMode	(GL_PROJECTION);	//	выбор матрицы проекций (камеры)
	glLoadIdentity	();					
	gluPerspective(45,w/h,0.01f,10000);
	glMatrixMode	(GL_MODELVIEW);		//	выбор матрицы модели
	glLoadIdentity	();	
    gluLookAt(0,0,1,0,0,0,0,1,0);
  
}
FILE *fp;
void ReadIni()
{

if((fp=fopen("settings.cfg","r"))==NULL) 
	{MessageBox(NULL,
	 "Cannot open file ''settings.cfg''\n\n"
	 "Standart text of this file:\n\n"
	 "	planet_count=10\n"
	 "	with_traectory=0\n"
	 "	sol_power=10000\n"
	 "	look_distance=2000\n"
	 "	detalization=10\n"
	 "	rotateX=45\n"
	 "	rotateY=0\n"
	 "	rotateZ=0\n"
	 "","Error",MB_OK);


	 exit(0);
	}

int temp;
fscanf(fp,
	    "planet_count=%d\n"
		"with_traectory=%d\n"
		"sol_power=%d\n"
		"look_distance=%d\n"
		"detalization=%d\n"
		"rotateX=%d\n"
		"rotateY=%d\n"
		"rotateZ=%d",
		
		&kolplanet,
		&WithTraectory,
		&temp,
		&RRR,
		&detalization,
		&rotateX,
		&rotateY,
		&rotateZ);

KOEFFICIENT=temp;

if(kolplanet>1000) kolplanet=1000;
if(detalization>30) detalization=30;
if(detalization<3) detalization=3;
if(feof(fp)) fclose(fp);

fclose(fp);
}

void CreatePlanets(int kol)
{
	srand( (unsigned)time( NULL ) );
	for(int i=0;i<kol;i++)
	{int xx,yy; 
	//	do
	//	{
		  xx=rand()%1000-500;
		  yy=rand()%1000-500;
	//	}while(RASSTOYANIE(solX,solY,xx,yy)<200);

		b[i]=new PLANET(5+rand()%20,
					 xx,yy,
					 rand()%360,4+rand()%4,
					 minirand(),minirand(),minirand());	

	}
}



void	main	(int argc,char *argv[])
{
	ReadIni();

	CreatePlanets(kolplanet);

    glutInit				(&argc,argv);			//	инициализация GLUT
	GLfloat	pos0[4]={0,0,-RRR,1};
	glutInitWindowPosition	(00,00);
	glutInitWindowSize		(700,600);
	glutInitDisplayMode		(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);	//	режим работы
	glutCreateWindow		("SolSystem");	//	создать окно
	glutIdleFunc			(Idle);					//	используется для анимации
	glutDisplayFunc			(Draw);					//	функция перерисовки окна
	glutReshapeFunc			(Reshape);				//	изменение размеров окна
	glEnable				(GL_DEPTH_TEST);
	glEnable				(GL_COLOR_MATERIAL);
	glEnable				(GL_LIGHTING);
	glEnable				(GL_LIGHT0);
	glLightfv				(GL_LIGHT0, GL_POSITION, pos0);

//	glutFullScreen();
//	glEnable				(GL_BLEND);


	glEnable				(GL_POINT_SMOOTH);

	glutMainLoop			();						//	запуск цикла обработки сообщений
	
 	
fclose(fp);
}

int razbien=1;

void Idle()
{
	for(int i=0;i<kolplanet;i++)
	{
	  b[i]->Move();
	}
	
 glutPostRedisplay();
}


void	Draw	()			
{	glClear	(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);	//	очистка окна
	
  

	glPushMatrix();
	
	
			glTranslatef(0,0,-RRR);
 

			/////////////////////////////
			glPushMatrix();
			glRotatef(rotateX,1,0,0);
			glRotatef(rotateY,0,1,0);
			glRotatef(rotateZ,0,0,1);

			for(int i=0;i<kolplanet;i++)
			{
			 b[i]->Show(WithTraectory);
			}
			glPopMatrix();
			/////////////////////////////

		
			
		
			glPushMatrix();	
			glDisable				(GL_BLEND);
			glDisable				(GL_LIGHTING);
			glColor3f(1,1,0.88);
		    glutSolidCone(100,0,detalization*2,10);
			glEnable				(GL_LIGHTING);
			glEnable				(GL_BLEND);	
			glPopMatrix();
			



			//корона
			/////////////
			glPushMatrix();
			glDisable				(GL_LIGHTING);
			glEnable				(GL_BLEND);

			for(double k=0.01;k<1;k+=0.05)
			{
			//	
			//	glTranslatef(0,0,1);
				glColor4f(1-k,1-k,0.88-k,0.5);
				 glutSolidCone(100+k*100,0,detalization*2,1);
			//
			}
			glDisable				(GL_BLEND);
		
			glEnable				(GL_LIGHTING);
			glPopMatrix();
			////////////////



		


	glPopMatrix();
//	glFlush();
	glutSwapBuffers();

}
