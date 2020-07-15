#ifndef _input_h_
#define _input_h_ 


void Ch(int resmode);
void BeforeExit();
void MyPerspective(double,double,int);


void KeyDown(unsigned char key,int x ,int y)
{	
//	g_gui.keyboard(key, x, y);
 static int temp;
 if(key==27) 
 {
	 if(mapmode)
	 { mapmode=false;
	   FOV=temp;
	 }
	 else
	 {
		//BeforeExit();
		exit(0);
	 }
 }


 if( key == 'f' )
 {	GOALZDIST = 3;
	for(int i=0;i<UFOCOUNT;i++)
	{

			 if(ufo[i]->bVidelen) 
				   ufo[i]->bFocus = true;
			 else  ufo[i]->bFocus = false;
	}

	for(i=0;i<PLANET_COUNT;i++)
	{

			 if(b[i]->bVidelen)
			 {b[i]->bFocus = true;
			  GOALZDIST = 6;
			 }
			 else  b[i]->bFocus = false;
	}



	f_button = true;


 }

 if(key == '5')
 {
	 bL=!bL;
 }


 if(key==43 || key==61) 
			 zoomplus=1;
 if(key==45) zoominus=1;

 
  
 if(key==32)
 {
	if(myship ->isOnPlanet) 
	{	 
		body[PLANET_COUNT].dx+=tempm[1]*0.5;
		body[PLANET_COUNT].dy+=tempm[5]*0.5; 
		body[PLANET_COUNT].dz+=tempm[9]*0.5;
	}
	else
	{
		myship->fireing=true;
		timeFire=400;
	}
 }

 if(//simple_rasst(zavod->x,zavod->y,zavod->z,mmm[12],mmm[13],mmm[14],30) && 
	 !zavod->building)
	 {
	 switch (key) 
	 {
		 case '1':	 zavod->BeginBuildModel(TYDIRIUM);
		 break;
		 case '2':	 zavod->BeginBuildModel(TIEFIGHTER);
		 break;
	 }

 }

 if(key=='v')
 {	 if(!mapmode)	 {
	 temp=FOV;mapmode=true;
 ShowCursor(1);
/*		for(int i=0;i<UFOCOUNT;i++)
		 {

			 if(ufo[i]->bVidelen) 
				   ufo[i]->bFocus = true;
			 else  ufo[i]->bFocus = false;
		 }
 */
	}
	 else			 {FOV=temp;mapmode=false;  ShowCursor(0);}

	 ShowCursor(0);

	if(fabs(focus.x)<10 &&fabs(focus.y)<10)
	{
	 GOALZDIST = 20;
	 ZDIST = 20;
	}
 }


 if(key=='m')
	 m_button=true;


// if(key>='0' && key<='9') numkey=key-'0';

 // if(key=='z') forward=1;

if(key==0x6A || key==0x6A-32) 	
	{ 
		hyperj=true;
		body[PLANET_COUNT].x-=tempm[2]*10000;
		body[PLANET_COUNT].y-=tempm[6]*10000;
		body[PLANET_COUNT].z-=tempm[10]*10000;
		myship->Move();
		
//		soundChannel[2] = FSOUND_PlaySound(FSOUND_FREE,pSound2);		
		Sleep(200);		

		vspysh=0.5;

		myship->isOnPlanet=false;
	}


	if(key=='g' ) GenerateStarSystem();	


/*
	if(key=='6')  WithStars=!WithStars;
	if(key=='7')  WithTraectory=!WithTraectory;
	if(key=='8')  WithLabels=!WithLabels;
	if(key=='0')  WithCabin=!WithCabin;
	if(key=='9')  WithInfo=!WithInfo;

*/

 if(key=='w' || key=='W' )  {forward=1;}
 if(key=='s' || key=='S')   {back=1;   }
 if(key=='a'|| key=='a'-32) {left2=1; brot=1;}
 if(key=='d'|| key=='d'-32) {right2=1; brot=1;}


 //if(zoomplus && zoominus)  FOV=DEFAULTFOV;
 
 if(key=='9' )  {NSTEXT--;}
 if(key=='0' )  {NSTEXT++;}


  
}



 
void KeyUp(unsigned char key,int x ,int y)
{
 if(key==43 || key==61) 
 {zoomplus=0;
 //  MyPerspective(FOV,0.01,LIMITSPACE*5000);
 }
 if(key==45) 
 {zoominus=0;
 //  MyPerspective(FOV,0.01,LIMITSPACE*5000);

 }
 if(key=='a')	 left2=0;
 if(key=='d')	right2=0;

// if(key=='.')	{do{ numkey++; if(numkey>=PLANET_COUNT) numkey=1;} while(!E_planet[numkey]); }
// if(key==',')	{do{ numkey--; if(numkey<1) numkey=PLANET_COUNT-1;} while(!E_planet[numkey]); }
 //if(key=='z') forward=0;
 

 if(key=='m')
	 m_button=false;

 if(key=='f')
	 f_button=false;


if(key=='w'){ forward=0;}
if(key=='s') {back=0;} 
 
 if(key==32) 
	{
	 myship->fireing=false;
	}

//	g_gui.keyboardUp(key, x, y);
}




void SpKeyDown(int key,int x ,int y)
{
//	g_gui.special(key, x, y);
	if(key==GLUT_KEY_LEFT){ left2=1;brot=1;}
	if(key==GLUT_KEY_RIGHT) {right2=1;brot=1;}
	if(key==GLUT_KEY_DOWN) {down2=1;brot=1; ntextDown = true;}
	if(key==GLUT_KEY_UP) {up2=1;brot=1; ntextUp = true; }
	

}

void SpKeyUp(int key,int x ,int y)
{

//	g_gui.specialUp(key, x, y);
 if(key==GLUT_KEY_LEFT) left2=0;
 if(key==GLUT_KEY_RIGHT) right2=0;
 if(key==GLUT_KEY_DOWN) {down2=0;ntextDown = false;}
 if(key==GLUT_KEY_UP) {up2=0;ntextUp = false;}

}



void MouseButton(int key,int state,int x,int y)
{ 
//	g_gui.mouse(key, state, x, y);
	
	if(key==GLUT_RIGHT_BUTTON)
	{
	 if(state==GLUT_UP)		
	 {mouseRightButton=false;
//	  SetCursorPos(SSX>>1,SSY>>1);	
	 }
	 if(state==GLUT_DOWN)	 
	 {mouseRightButton=true;
	 }
	}	

	if( key==GLUT_LEFT_BUTTON )
	{//	mousex=x;
	//	mousey=y;
	 if(state==GLUT_UP)	
	 {mouseLeftButton =false;
		if(!mapmode)
			SetCursorPos(SSX>>1,SSY>>1);
		
//	for(int i=0;i<UFOCOUNT;i++)
//		if(ufo[i]->bVidelen) 
//			ufo[i]->bVidelen = false;


	 }
	 if(state==GLUT_DOWN) 	
	 {
		 mouseLeftButton=true;


			fixPX=x;
			fixPY=y;


	  
			if(m_button)
			{
				for (int xp=-50000; xp<50000; xp+=300)
				{
					if(fabs(::GetPos(GETX,xp,0,0)-p.x)<10) 
					{//	glColor3f (1,1,0);

						for(int i=0;i<UFOCOUNT;i++)
						{
								if(ufo[i]->bVidelen)
								{  ufo[i]->ZDEST = rand()%50-25;
									ufo[i]->XDEST = xp+rand()%50-25;
									ufo[i]->numResPlanet = -1;

								}
						}	
					}
				}
				
				for (int yp=-50000; yp<50000; yp+=300)
				{
					if(fabs(::GetPos(GETY,0,yp,0)-p.y)<10) 
					{
						for(int i=0;i<UFOCOUNT;i++)
						{
								if(ufo[i]->bVidelen)
								{
									ufo[i]->ZDEST = rand()%50-25;
									ufo[i]->YDEST = yp+rand()%50-25 ;
								}
						}
					}
				}
			}


	 }

	}

   	             
}


	int oldx;
	int oldy;

	int x00;
	int y00;

void MouseMove(int x, int y)
{

//	g_gui.motion(x, y);
}


void MousePassiveMove(int x, int y)
{

//g_gui.passiveMotion(x, y);
}


void MyMouseFunc()
{


	int middleX = SSX >> 1;				
	int middleY = SSY >> 1; 

	static int oldpx;
	static int oldpy;

	GetCursorPos( &p );					


		if(mapmode)	
		{
		//	SetCursorPos( middleX, middleY );	
				
			if(mouseRightButton && mouseLeftButton)
			{	ZDIST -= ((oldpy  - p.y )*0.03);
				GOALZDIST =  ZDIST;
			}
			else
				if(mouseRightButton)
				{	//SetCursorPos( middleX, middleY );
					XROTATE += ((oldpx  - p.x )*0.3);
					YROTATE += ((oldpy  - p.y )*0.3);
				}

			oldpx = p.x;
			oldpy = p.y;

	

		}
		else
			{

			if(myship->isOnPlanet)
			{
				SetCursorPos( middleX, middleY );
				yrot = (( middleX - p.x )*0.4);
				xrot = -(( middleY - p.y )*0.4);
				if( (middleY - p.y)!=0 )
				{
				
				}

		
			}
			else if(!mouseRightButton)
			{
		
				if(!mouseLeftButton)
				{
				yrot = (( middleX - p.x )*0.005);
				xrot = -(( middleY - p.y )*0.005);
				}
				else yrot=xrot=zrot=0;

			}

	


		}

}

/*
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
*/

#endif


