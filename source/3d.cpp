#pragma comment(lib, "fmodvc.lib")

#include	<windows.h>
#include	"aselib.h"
#include <gl\gl.h>		// Заголовочный файл для OpenGL32 библиотеки
#include <gl\glu.h>		// Заголовочный файл для GLu32 библиотеки
#include <gl\glaux.h>		// Заголовочный файл для GLaux библиотеки
#include	"glut.h"
//#include <GUI\gui.h>
//#pragma comment(lib, "GUI.lib")

//using namespace gui;
//GUI g_gui;


#include	<time.h>
#include	<conio.h>
//#include	"lib.h"
#include    <math.h>
//#include    "fmod.h"

int SSX;//GetSystemMetrics(SM_CXSCREEN);
int SSY;//GetSystemMetrics(SM_CYSCREEN);

//#include	"fvector.h"

//#include	"asc2list.h"
#include	"kepler.h"



#include	"mathem.h"
#include    "font.h"

#include	"data.h"

#include	"matrix.h"
#include	"objects.h"
#include    "planet.h"
#include    "plazma.h"
#include    "ship.h"
#include    "ufo.h"
#include    "building.h"
#include    "mappoint.h"

matrix <double> M1(4,4);


#include	"r.h"
#include	"input.h"
#include	"draw.h"
#include	"idle.h"


int g_width = 0, g_height = 0;

void reshape(int w, int h)
{
//	SSX = w;
//	SSY = h;
	glViewport ( 0,0,SSX,SSY);  
//	g_gui.reshape(w, h);
}

void timer(int value)
{
//	g_gui.timer(value);
	if (value == 0)
		glutTimerFunc(500, timer, 0);
}

void Ch(int resmode)
{	
	switch(resmode)
	{
	 case 1:  glutGameModeString("800x600:32"); break;
	 case 2:  glutGameModeString("1024x768:32"); break;
	 case 3:  glutGameModeString("1280x1024:32"); break;
	 case 4:  glutGameModeString("1600x1200:32"); break;	
	}
	
	glutEnterGameMode();

	SSX=glutGameModeGet(GLUT_GAME_MODE_WIDTH);
	SSY=glutGameModeGet(GLUT_GAME_MODE_HEIGHT);
			

	glutDisplayFunc			(Draw);					//	функция перерисовки окна
	glutIdleFunc			(Idle);					//	используется для анимации
	glutReshapeFunc			(reshape);				//	изменение размеров окна
	glutKeyboardFunc		(KeyDown);
	glutMouseFunc			(MouseButton);
	glutMotionFunc			(MouseMove);
	glutPassiveMotionFunc	(MousePassiveMove);
	glutKeyboardUpFunc		(KeyUp);
	glutSpecialFunc			(SpKeyDown);
	glutSpecialUpFunc		(SpKeyUp);
	glutTimerFunc(500, timer, 0);
//ShowCursor(0);
}


void BeforeExit()
{
	gluDeleteQuadric(qobj);
	glDisable	(GL_TEXTURE_2D);
	glDisable	(GL_BLEND);
	glDisable	(GL_LINE_SMOOTH);
	//glDisable	(GL_POINT_SMOOTH);
	glDisable	(GL_NORMALIZE);
	glDisable	(GL_DEPTH_TEST);
	glDisable	(GL_COLOR_MATERIAL);
	glDisable	(GL_LIGHTING);
	glDisable	(GL_LIGHT1);
	glDisable	(GL_CULL_FACE);

	font.DestroyFont();
	fontMedium.DestroyFont();
	fontSmall.DestroyFont();

//	FSOUND_StopSound(soundChannel[0]);
//	FSOUND_StopSound(soundChannel[1]);
//	FSOUND_StopSound(soundChannel[2]);
//	FSOUND_Close();

	glDeleteLists(1,3300);
	glutLeaveGameMode();
}

void read_ini()
{
 FILE *f;
 if((f=fopen("game.ini","r"))==NULL) Ch(3);

 int vmode=12;

 while(getc(f)!='=')
 {}
 fscanf(f,"%d",&vmode);

 Ch(vmode);

 fclose(f);
 
}


void click1()
{

}



void	main	(int argc,char *argv[])
{
//	MessageBox(NULL,"Разработчик - Евгений Усейнов\n","",MB_OK);
	
  /*  photo_image = auxDIBImageLoad("texture/ios.bmp");
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexImage2D(GL_TEXTURE_2D, 0, 3,
                 photo_image->sizeX,
                 photo_image->sizeY,
                 0, GL_RGB, GL_UNSIGNED_BYTE,
                 photo_image->data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
*/
	
	////////////////////////////
////////////////////////////////



	

	srand( (unsigned)time( NULL ) );
	
M: 	cout<<endl;
cout<<endl;

//	cout<<" \t800 x 600 \t- 1"<<endl<<endl;
	cout<<" \t1024 x 768 \t- 2"<<endl<<endl;
	cout<<" \t1280 x 1024 \t- 3"<<endl<<endl;
//	cout<<" 7\t1600 x 1200 \tx 32"<<endl<<endl;


	printf("Please input number of  video mode: ");	
	char c;
	int vmode;

	cin>>c;

	vmode=c-'0';

	if(vmode<1 || vmode>3) goto M;



M2: 
	cout<<endl;
	cout<<endl;

/*	cout << "Planet count (1-5): ";

	cin>>c;

	GIANTSCOUNT=c-'0';

	if(GIANTSCOUNT<1 || GIANTSCOUNT>5) goto M2; 

GIANTSCOUNT++;
*/

GIANTSCOUNT = 5;

    glutInit				(&argc,argv);			//	инициализация GLUT
//	glutInitWindowPosition	(0,0);
//	glutInitWindowSize		(SSX,SSY);
	
	glutInitDisplayMode		(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);	//	режим работы

	Ch(vmode);


//	LOADLIB("kepler.dll");

	//
	glEnable				(GL_BLEND);
	glEnable				(GL_LINE_SMOOTH);
	//glEnable				(GL_POINT_SMOOTH);
	glEnable				(GL_NORMALIZE);
	glEnable				(GL_DEPTH_TEST);
	glEnable				(GL_COLOR_MATERIAL);
	glEnable				(GL_LIGHTING);
	glEnable				(GL_LIGHT1);
	glEnable				(GL_CULL_FACE);
	glEnable(GL_TEXTURE_2D);	// Разрешение наложение текстуры

	//glEnable(GL_FOG);                       // Включает туман (GL_FOG)


	glFogi(GL_FOG_MODE, fogMode[fogfilter]);// Выбираем тип тумана

	glFogfv(GL_FOG_COLOR, fogColor);        // Устанавливаем цвет тумана

	glFogf(GL_FOG_DENSITY, 0.5);          // Насколько густым будет туман

	glHint(GL_FOG_HINT, GL_DONT_CARE);      // Вспомогательная установка тумана

	glFogf(GL_FOG_START, 1.0f);             // Глубина, с которой начинается туман

	glFogf(GL_FOG_END, 30000.0f);               // Глубина, где туман заканчивается.


	glFogi (GL_FOG_MODE, fogMode[2]);

	
	//glBindTexture(GL_TEXTURE_2D, texture[0]);
 // glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
  //glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST); // 



	//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	LPCSTR lstr="texture\\io.bmp";	

	tex_image[0] = auxDIBImageLoad("texture\\sun.bmp");
	tex_image[1] = auxDIBImageLoad("texture\\mercury.bmp");
	tex_image[2] = auxDIBImageLoad("texture\\venus.bmp");
	tex_image[3] = auxDIBImageLoad("texture\\earth.bmp");
	tex_image[4] = auxDIBImageLoad("texture\\mars.bmp");
	tex_image[5] = auxDIBImageLoad("texture\\ORIONMOS.bmp");	

/*	tex_image[7] = auxDIBImageLoad(lstr);
	tex_image[8] = auxDIBImageLoad("texture\\w.bmp");
	tex_image[9] = auxDIBImageLoad("texture\\7.bmp");	
	tex_image[0] = auxDIBImageLoad("texture\\sun.bmp");
	tex_image[1] = auxDIBImageLoad("texture\\ORIONMOS.bmp");
	tex_image[12] = auxDIBImageLoad(lstr);
*/
/*
	pixels = new GLubyte[size];
	glGenTextures(1,&textemp);

	glBindTexture(GL_TEXTURE_2D, textemp);
	for (int i=0; i < size; i+=4)
	{
	
	
		int k=100+rand()%156;
	
		pixels[i] =   k;
		pixels[i+1] = k;
		pixels[i+2] = k;
		pixels[i+3] = 255;


	}
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	gluBuild2DMipmaps(GL_TEXTURE_2D, components, width, height, GL_RGBA, GL_UNSIGNED_BYTE, pixels);

	glGenTextures(1,&texclouds);

	glBindTexture(GL_TEXTURE_2D, texclouds);
	for ( i=0; i < size; i+=4)
	{
		
		pixels[i] =   255;
		pixels[i+1] = 255;
		pixels[i+2] = 255;

		if(rand()%100>10)
			pixels[i+3] = 0;
		else	
			pixels[i+3] = rand()%256;

	}
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	gluBuild2DMipmaps(GL_TEXTURE_2D, components, width, height, GL_RGBA, GL_UNSIGNED_BYTE, pixels);

*/

	glGenTextures(6,texture);

//	glBindTexture(GL_TEXTURE_2D, texture);
   // glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST); //   

	for(int j=0;j<6;j++)
	{

	 glBindTexture(GL_TEXTURE_2D, texture[j]);
	 glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	 // if(j<11)
	// {
	//	 glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_CLAMP);
	//	 glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_CLAMP);
	 //}

	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, tex_image[j]->sizeX, tex_image[j]->sizeY,
			 GL_RGB, GL_UNSIGNED_BYTE, tex_image[j]->data); // ( НОВОЕ )
		
	}



/*
	glBindTexture(GL_TEXTURE_2D, pixels);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, tex_image[j]->sizeX, tex_image[j]->sizeY,
			 GL_RGBA, GL_UNSIGNED_BYTE, tex_image[j]->data); // ( НОВОЕ )

*/

	qobj = gluNewQuadric();
	gluQuadricTexture (qobj, GL_TRUE);

	glLightfv				(GL_LIGHT1, GL_POSITION, pos0);
	glLightfv				(GL_LIGHT1, GL_AMBIENT, amb);
//	glLightfv				(GL_LIGHT1, GL_SPECULAR, spec);
//	glLightModelfv			(GL_LIGHT_MODEL_AMBIENT,real_lightmodel);


//	glLightf				(GL_LIGHT1, GL_CONSTANT_ATTENUATION,  0.1);


//	FSOUND_GetVersion();
//	FSOUND_Init(44100, 32, FSOUND_INIT_GLOBALFOCUS);

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

//	BuildFont();                            // Построить шрифт (добавлена)


	CreatePlanet();
	CreateGiantCube();
	CreatePoint();
	CreateAsteroid();
	CreateSimpleSphere();
	CreateDoctor();
	CreatePlazma();	
	CreateRing();
	CreatePortal();
	CreateShips();	
	CreateGiantSol();

	//CreateMyShip();
	//	glLoadIdentity();
	//glClearColor(0.00,0.01,0.04,0);
	//glClearColor(minirand()*0.07,minirand()*0.07,minirand()*0.07,	0);

	font.CreateOpenGLFont("Verdana", 20);
	fontMedium.CreateOpenGLFont("Verdana", 23);
	fontSmall.CreateOpenGLFont("Verdana", 14);
	fontBig.CreateOpenGLFont("Verdana", 72);

	//enable_hyper_speed=(rand()%100>50);

	enable_hyper_speed=0;
 
	SetCursorPos( SSX>>1, SSY>>1 );		//ставим курсор в середину

/*	pSound1 = FSOUND_Sample_Load(FSOUND_FREE,BLASTER_SONG,0,0);
 	pSound2 = FSOUND_Sample_Load(FSOUND_FREE,HYPERJUMP_SONG,0,0);
 	pSound3 = FSOUND_Sample_Load(FSOUND_FREE,UFO_FIRE_SONG,0,0);
	pSound4 = FSOUND_Sample_Load(FSOUND_FREE,METAL_SONG,0,0);
	pSound5 = FSOUND_Sample_Load(FSOUND_FREE,S_U_FIRE,0,0);
	*/
//
//	glLightf			(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.0000000001f);	
	
	glLightf			(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1);	


	
 MyPerspective(FOV,0.005,LIMITSPACE*5000);


//	int temp=rand()%1000;
	
//	if(temp>667)		
	{//	pSound0 = FSOUND_Sample_Load(FSOUND_FREE,SONG_NAME_1,0,0);
	//	soundChannel[0] = FSOUND_PlaySound(FSOUND_FREE,pSound0);
	}
/*	else  if(temp>333  ) 
	{	
		pSound0 = FSOUND_Sample_Load(FSOUND_FREE,SONG_NAME_2,0,0);
		soundChannel[0] = FSOUND_PlaySound(FSOUND_FREE,pSound0);
	}
	else				 
	{	pSound0 = FSOUND_Sample_Load(FSOUND_FREE,SONG_NAME_3,0,0);
 		soundChannel[0] = FSOUND_PlaySound(FSOUND_FREE,pSound0);	
	}
*/
/*	pSound0 = FSOUND_Sample_Load(FSOUND_FREE,SONG_NAME_1,0,0);
	soundChannel[0] = FSOUND_PlaySound(FSOUND_FREE,pSound0);*/

   body = new BODY[1000]; 
	   tower = new Tower;
	   zavod = new ZAVOD;

	GenerateStarSystem();

	for (int i=0;i<1000;i++)
		ball[i]=new Ball();

 MyPerspective ( FOV,0.5,LIMITSPACE * 5000 ); 
 
 float dif[4]={2,2,2,1};
 glLightfv ( GL_LIGHT1, GL_DIFFUSE, dif); 

	
//double xp=-1000; 
//double yp=-1000;

 for (i=0 ; i<10000; i++)
 {  mappoint[i] = new MapPoint();
//	mappoint[i]->x = xp;
//	mappoint[i]->y = yp;

//	xp+=100;

//	if(xp>1000) 		yp+=10;
 }

/*	Button *button1 = new Button;
	button1->setClickFunc(click1);
	button1->setPosition(120, 70);
	button1->setSize(70, 40);
	button1->setText("button1");
	button1->setPressColor(.2f, .2f, .4f, 0.4f);
	button1->setHoverColor(.6f, .6f, .7f, 0.4f);
//	button1->setColor(.5f, .5f, .6f, 0.4f);
	button1->setTextColor(1, 1, 1, 1);
////	panel1->add(button1);
	g_gui.add(button1);*/
 
	glutMainLoop();						//	запуск цикла обработки сообщений

	BeforeExit();


}

void FORWARD()
{ 

//	xpos += sin(yrot*PO180) * cos(xrot*PO180) * 50;//
//	ypos += cos(yrot*PO180) * cos(xrot*PO180) * 50;// 
//	zpos += sin(xrot*PO180) * 50; 
}