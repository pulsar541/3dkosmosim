#define STRVERSION "Version 1.00. " 
#define SONG_NAME_1 "music\\music1.mp3 " 
#define SONG_NAME_2 "music\\music2.mp3 " 
#define SONG_NAME_3 "music\\music3.mp3 " 
#define BLASTER_SONG "sound\\blaster.wav " 
#define HYPERJUMP_SONG "sound\\hyperjump.wav " 
#define UFO_FIRE_SONG "sound\\ufofire.wav " 
#define METAL_SONG "sound\\metal.wav " 
#define S_U_FIRE "sound\\S_ufofire.wav " 
FSOUND_SAMPLE *pSound0; 
FSOUND_SAMPLE *pSound1; 
FSOUND_SAMPLE *pSound2; 
FSOUND_SAMPLE *pSound3; 
FSOUND_SAMPLE *pSound4; 
FSOUND_SAMPLE *pSound5; 
int soundChannel[6] = 
{ 
0,1,2,3,4,5 
}; 
#define _0v1 ( rand () %100 > 50 ) 
#define LIMITSPACE 10000 
#define SCALE 2000 
#define LISTSIMPLESPHERE 3300 
#define LISTPOINT 2001 
#define LISTPOINT2 2004 
#define STARS 2101 
#define OREOL 2200 
#define LUCHI 2300 
#define GIANTCUBE 2400 
#define RING 2500 
#define ASTEROID 2600 
#define PORTAL 2700 
#define DOCTOR 2800 
#define PLAZMA 2900 
#define LISTUFO 3000 
#define ISENEMY 0 
#define ISPORTAL 1 
#define ISDOCTOR 2 
#define MYSHIPNUM 700 
#define DEFAULTFOV 45 
#define GETX 0 
#define GETY 1 
#define GETZ 2 
#define ASPOINT 0 
#define LOW 1 
#define MEDIUM 2 
#define HIGH 3 
#define WARE 4 
#define DETAL_TRAECT1 500 
#define DETAL_TRAECT2 10 
#define LOADING 0 
#define GAME 1 
#define LOFF glDisable ( GL_LIGHTING ); 
#define LON glEnable ( GL_LIGHTING ); 
bool GameState = 1; 
bool hyperj = true; 
bool left = 0,up = 0,down = 0,right = 0; 
bool left2 = 0,up2 = 0,down2 = 0,right2 = 0; 
bool mapmode = false; 
bool showpoint = true; 
bool for ward = 0; bool back = 0; int Level = 0; 
int mousex,mousey; 
bool zoomplus = 0, zoominus = 0; 
GLfloat pos0[4] = 
{ 
0,0,0,1 
}; 
GLfloat real_lightmodel[4] = 
{ 
0.00,0.00,0.00,1 
}; 
GLfloat unreal_lightmodel[4] = 
{ 
0.02,0.02,0.02,1 
}; 
GLfloat L_lightmodel[4] = 
{ 
0.05,0.05,0.05,1 
}; 
GLfloat shiplightmodel[4] = 
{ 
0.1,0.1,0,1 
}; 
GLfloat amb[4] = 
{ 
0,0,0,1 
}; 
GLfloat spec[4] = 
{ 
1,1,1,1 
}; 
double XCAM = 0; 
double YCAM = 0; 
double FOV = DEFAULTFOV; 
double XROTATE = 0; 
// 45; 
double YROTATE = 20; 
int SOLCOUNT = 1; 
int ASTEROIDSCOUNT = 20; 
int GIANTSCOUNT = SOLCOUNT + 4; 
int PLANET_COUNT = GIANTSCOUNT + ASTEROIDSCOUNT; 
int UFOCOUNT = 100; 
int BALLCOUNT = 100; 
bool WithTraectory = true; 
bool WithStars = true; 
bool WithLabels = true; 
bool WithCabin = true; 
bool WithInfo = true; 
// double MAXSPEED = 40; 
double MASS_OF_SOL = 7000; 
int numkey = 1; 
int Lhvost = 1000; 
bool E_planet[1000] = 
{ 
0 
}; 
bool Esol = true;
; 
int detalization = 100; 
unsigned int texture[1]; 
// ћесто дл€ одной текстуры 
class UFO; 
UFO *ufo[100]; 
class SHIP; 
SHIP *myship; 
class PLANET; 
PLANET *b[1000]; 
class BODY; 
BODY *body; 
class Ball; 
Ball *ball[1000]; 
class Pyl; 
Pyl *pyl[100]; 
float colorsol0[4] = 
{ 
1,1,1,1 
}; 
float colorsol1[4] = 
{ 
0,0,0,0 
}; 
float colororeol0[4] = 
{ 
1,1,1,1 
}; 
float colororeol1[4] = 
{ 
0,0,0,0 
}; 
double xrot = 0; 
double yrot = 0; 
double zrot = 0; 
double xpos = 0; 
double ypos = 1000; 
double zpos = 0; 
CFont font; 
CFont fontMedium; 
CFont fontSmall; 
CFont fontBig; 
double mmm[16] = 
{ 
   1.0,0,0,0, 
   0,1.0,0,0, 
   0,0,1.0,0, 
   0,0,0,1.0 
}; 
double invm[16] = 
{ 
   1.0,0,0,0, 
   0,1.0,0,0, 
   0,0,1.0,0, 
   0,0,0,1.0 
}; 
double tempm[16] = 
{ 
   1.0,0,0,0, 
   0,1.0,0,0, 
   0,0,1.0,0, 
   0,0,0,1.0 
}; 
int fps = 0; 
double ship_start_positioin_x, 
ship_start_positioin_y, 
ship_start_positioin_z; 
int imin = 0; 
double dway = 0.0005; 
double olddway = 0; 
double koeff = 1; 
bool brot = 0; 
static double kf = 0.01; 
double cmin; 
int otsch = 0; 
bool dobro_na_kursor = true; 
bool dobro_na_oreol = true; 
bool enable_hyper_speed = 0; 
AUX_RGBImageRec *tex_image[13]; 
GLUquadricObj *qobj = 0; 
double dupx; 
double dupy; 
double dupz; 
void Line ( double,double,double,double,double,double ); 
void Laser ( double,double,double,double,double,double ); 
void Doctor ( double,double,double,double,double,double ); 
float vspysh = 0; 
int sfactor[9] = 
{ 
   GL_ZERO , 
   GL_ONE , 
   GL_DST_COLOR , 
   GL_ONE_MINUS_DST_COLOR , 
   GL_SRC_ALPHA_SATURATE , 
   GL_SRC_ALPHA , 
   GL_ONE_MINUS_SRC_ALPHA , 
   GL_DST_ALPHA , 
   GL_ONE_MINUS_DST_ALPHA 
}; 
int dfactor[8] = 
{ 
   GL_ZERO , 
   GL_ONE , 
   GL_SRC_COLOR , 
   GL_ONE_MINUS_SRC_COLOR , 
   GL_SRC_ALPHA , 
   GL_ONE_MINUS_SRC_ALPHA , 
   GL_DST_ALPHA , 
   GL_ONE_MINUS_DST_ALPHA 
}; 
int numsfactor = 0; 
int numdfactor = 0; 
DWORD starttime1 = timeGetTime () , time1; 
DWORD starttime2 = timeGetTime () , time2; 
DWORD starttime3 = timeGetTime () , time3; 
DWORD starttimeFire = timeGetTime () , timeFire; 
DWORD starttimeFireVrag = timeGetTime () , timeFireVrag; 
DWORD tGT; 
POINT p; 
char rusglas[] = 
{ 
'у','е','ы','а','о','э','€','и','ю' 
}; 
bool StarGigant = false; 
float ro,go,bo; 
 