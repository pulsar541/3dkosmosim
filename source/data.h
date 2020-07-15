#ifndef _data_h_
#define _data_h_


#define  STRVERSION	 "Version 1.0.1"

#define SONG_NAME_1  "1music\\music1.mp3"
#define SONG_NAME_2  "1music\\music2.mp3"
#define SONG_NAME_3  "1music\\music3.mp3"


#define BLASTER_SONG  "sound\\blaster.wav"
#define HYPERJUMP_SONG  "sound\\hyperjump.wav"
#define UFO_FIRE_SONG  "sound\\ufofire.wav"
#define METAL_SONG  "sound\\metal.wav"
#define S_U_FIRE  "sound\\S_ufofire.wav"


#define loff  glDisable(GL_LIGHTING);
#define lon   glEnable(GL_LIGHTING);

/*
FSOUND_SAMPLE *pSound0;				
FSOUND_SAMPLE *pSound1;				
FSOUND_SAMPLE *pSound2;					
FSOUND_SAMPLE *pSound3;					
FSOUND_SAMPLE *pSound4;				
FSOUND_SAMPLE *pSound5;
*/
int soundChannel[6]={0,1,2,3,4,5};



POINT		p;


#define		_0v1	  (rand()%100>50)

#define		LIMITSPACE 10000
#define		SCALE		 200

#define		ISENEMY				 0
#define		ISPORTAL			 1
#define		ISDOCTOR			 2

#define		MYSHIPNUM			 700
#define		DEFAULTFOV			 40

#define		GETX				 0
#define		GETY				 1
#define		GETZ				 2

#define		ASPOINT				0
#define		LOW					1
#define		MEDIUM				2
#define		HIGH				3
#define		WARE				4

#define		DETAL_TRAECT1   500
#define		DETAL_TRAECT2   15



#define		LOADING   0
#define		GAME	  1

#define		LOFF	  glDisable(GL_LIGHTING);
#define		LON		  glEnable(GL_LIGHTING);	  


bool GameState=1;

bool hyperj=true;


bool		left=0,up=0,down=0,right=0;
bool		left2=0,up2=0,down2=0,right2=0;


bool mapmode=0;


bool showpoint=true;

 bool forward=0;
 bool back=0;



int Level=0;

int		mousex,mousey;
bool	zoomplus=0, zoominus=0;

bool    ntextUp = 0;
bool    ntextDown = 0;
 
int		NSTEXT = 0;
int		MTXT = 0;

GLfloat	pos0[4]={0,0,0,1};


GLfloat	real_lightmodel[4]={0.00,0.00,0.00,1};
GLfloat	unreal_lightmodel[4]={0.02,0.02,0.02,1};

//GLfloat	L_lightmodel[4]={0.06,0.06,0.06,1};
GLfloat	L_lightmodel[4]={0.1,0.1,0.1,1};
GLfloat	shiplightmodel[4]={0.1,0.1,0,1};


GLfloat	amb[4]={0,0,0,1};
GLfloat	spec[4]={1,1,1,1};


double		XCAM=0;
double		YCAM=0;
double		FOV=DEFAULTFOV;

double		XROTATE=0;//45;
double		YROTATE=0;
double		ZDIST=20;
double		GOALZDIST=20;

int			SOLCOUNT=1;
int			ASTEROIDSCOUNT=20;
int			GIANTSCOUNT=SOLCOUNT+4;
int			PLANET_COUNT=GIANTSCOUNT+ASTEROIDSCOUNT;

#define			UFOCOUNT 300

int			BALLCOUNT=100;


bool		WithTraectory=true;
bool		WithStars=true;
bool		WithLabels=true;
bool		WithCabin=true;
bool		WithInfo=true;

//double		MAXSPEED=40;	

double		MASS_OF_SOL=500000;

int			numkey=1;
int			Lhvost=1000;
bool		E_planet[1000]={0};
bool Esol=true;;

int			detalization=50;
//unsigned int	texture=0;		// ћесто дл€ одной текстуры

class		Ball;
Ball		*ball[1000];


class		UFO;
UFO			*ufo[UFOCOUNT];

class		SHIP;
SHIP		*myship;


class		PLANET;
PLANET		*b[1000];


class		BODY;
BODY		*body;



class	Tower;
Tower	*tower;


class	ZAVOD;
ZAVOD	*zavod;


class MapPoint;
MapPoint *mappoint[10000]; 


bool vid[1000];

float		colorsol0[4]={1,1,1,1};
float		colorsol1[4]={0,0,0,0};
float		colororeol0[4]={1,1,1,1};
float		colororeol1[4]={0,0,0,0};

double		xrot=0;
double		yrot=0;
double		zrot=0;

double		xpos=0;
double		ypos=1000;
double		zpos=0;

CFont font;
CFont fontMedium;
CFont fontSmall;
CFont fontBig;

double mmm[16]=
{1.0,0,0,0,
 0,1.0,0,0,
 0,0,1.0,0,
 0,0,0,1.0
};
double invm[16]=
{1.0,0,0,0,
 0,1.0,0,0,
 0,0,1.0,0,
 0,0,0,1.0
};

double tempm[16]=
{1.0,0,0,0,
 0,1.0,0,0,
 0,0,1.0,0,
 0,0,0,1.0
};

int fps=0;

double	ship_start_positioin_x,
		ship_start_positioin_y,
		ship_start_positioin_z;


int imin=0;


double dway=0.0005;


double olddway=0;
double koeff=1;
bool brot=0;
static double kf=0.01;

double cmin;


int otsch=0; 
bool dobro_na_kursor=true;
bool dobro_na_oreol=true;

bool enable_hyper_speed=0;



	
GLUquadricObj *qobj = 0;


double dupx;
double dupy;
double dupz;



float vspysh=0;



int sfactor[9]={
 GL_ZERO ,
 GL_ONE ,
 GL_DST_COLOR   ,                   
 GL_ONE_MINUS_DST_COLOR   ,        
 GL_SRC_ALPHA_SATURATE ,            
 GL_SRC_ALPHA ,
 GL_ONE_MINUS_SRC_ALPHA ,
 GL_DST_ALPHA ,
 GL_ONE_MINUS_DST_ALPHA 
};

int dfactor[8]={
 GL_ZERO ,                          
 GL_ONE   ,                         
 GL_SRC_COLOR ,                  
 GL_ONE_MINUS_SRC_COLOR ,           
 GL_SRC_ALPHA       ,              
 GL_ONE_MINUS_SRC_ALPHA ,          
 GL_DST_ALPHA      ,               
 GL_ONE_MINUS_DST_ALPHA           
};



int numsfactor=0;
int numdfactor=0;


DWORD starttime2=timeGetTime(),time2;
DWORD starttime3=timeGetTime(),time3;
DWORD starttimeFire=timeGetTime(),timeFire;
DWORD starttimeFireVrag=timeGetTime(),timeFireVrag;
DWORD starttime1=timeGetTime(),time1;
DWORD tGT;



char rusglas[]={'у','е','ы','а','о','э','€','и','ю'};


bool StarGigant=false;

float ro,go,bo;

DWORD dt = 0;



static float color1[3] = 
{ 0.8,0.8,1 
}; 
static float color2[3] = 
{ 0,0.5,0 
}; 
static float color3[3] =
{ 0,1,0 
}; 
static float color4[3] = 
{ 0.5,0,0 
}; 
static float color5[3] = 
{ 1,0,0 
}; 

/*
float vA[3]={1000,0,10000};
float vB[3]={0,1000,10000};
float vC[3]={1000,1000,10000};
*/
float vA[3]={0,0,0};
float vB[3]={0,0,0};
float vC[3]={0,0,0};

GLuint fogMode[]= { GL_EXP, GL_EXP2, GL_LINEAR }; // ’ранит три типа тумана

GLuint fogfilter= 0;                    // “ип используемого тумана

GLfloat fogColor[4]= {0.7f, 0.7f, 0.7f, 1.0f}; // ÷вет тумана



unsigned int texture[20];
AUX_RGBImageRec *tex_image[20];

unsigned int texclouds;


unsigned int textemp;

struct MYPOINT 
{ 
   double x; 
   double y; 
   double z;
   
   double a;
}; 

long RESOURCES = 1000; 


int GetPos(int mode ,double x,double y, double z) 
   { static double mv[16],pm[16]; 
      static int vp[4]; 
      static double winx,winy,winz; 
      glGetDoublev(GL_MODELVIEW_MATRIX, mv); 
      glGetDoublev(GL_PROJECTION_MATRIX,pm); 
      glGetIntegerv(GL_VIEWPORT,vp); 
      gluProject(x,y,z,mv,pm,vp,&winx,&winy,&winz); 
      switch(mode) 
      {  case GETX : return winx; 
         case GETY : return SSY-winy; 
         case GETZ : return winz; 
         default : return 0; 
      } 
   } 


bool VP=false;
bool bL=false;

	GLsizei width = 2048;
	GLsizei height = 2048;
	GLint components = 4;
	GLsizei size = width*height*components;
	GLubyte *pixels = NULL;

	

int fixPX,fixPY;


bool mouseRightButton=false;
bool mouseLeftButton=false;
bool m_button=false;
bool f_button=false;

MYPOINT focus;




bool keyF=false;



#endif 
