#ifndef _draw_h_
#define _draw_h_


int a; 
double mv[16],pm[16]; 
int vp[4]; 
double winx1,winy1,winz1; 
double winx2,winy2,winz2; 
bool zasv; 


void Begin2D()
{
  glDisable ( GL_DEPTH_TEST );
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  gluOrtho2D(0, SSX, 0, SSY);
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();

}
void End2D ()
{
  glPopMatrix();
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glEnable ( GL_DEPTH_TEST );
}

void MyPerspective ( double FOV,double nearz,int farz) 
{ 	
	glMatrixMode ( GL_PROJECTION); // выбор матрицы проекций (камеры)  
    glLoadIdentity (); 
    gluPerspective(FOV, 
     (double)(SSX) / (double)SSY, 
    nearz, 
    farz); 
    glMatrixMode ( GL_MODELVIEW); // выбор матрицы модели  

}


void DrawQuad ( float x, float y, float w, float h, UINT texture )
{
 // glBindTexture ( GL_TEXTURE_2D, texture );
  y = (float)SSY - y - h;
  glEnable(GL_BLEND);
  glColor4f(0,1,0,0.3);
  glBegin ( GL_TRIANGLE_STRIP );
    glTexCoord2f ( 0.0f, 0.0f );    glVertex2f ( x,     y );
    glTexCoord2f ( 1.0f, 0.0f );    glVertex2f ( x + w, y );
    glTexCoord2f ( 0.0f, 1.0f );    glVertex2f ( x,     y + h );
    glTexCoord2f ( 1.0f, 1.0f );    glVertex2f ( x + w, y + h );  
	
  glDisable(GL_BLEND);
  glEnd();
}


void Line(double x0, double y0, double z0, double x1, double y1, double z1)
{ 
   glDisable(GL_LIGHTING); 
   glEnable(GL_BLEND); 
   glBegin(GL_LINES); 
   glVertex3d(x0,y0,z0); 
   glVertex3d(x1,y1,z1); 
   glEnd(); 
   glDisable(GL_BLEND); 
   glEnable(GL_LIGHTING); 
} 


void ShowTextInformation() 
{ 
    glColor3fv(color1); 
    glDisable ( GL_LIGHTING); 
    
    if ( WithInfo) 
    { 
        font.glDrawText(SSY, SSX - 100,SSY - 50,"FOV %d * ",(int)FOV << 1);// 
        static float temperature = 1; 
        static float tporog; 
        tporog = 400000000000 / kvad(rasst(myship -> x,myship -> y,myship -> z,b[0] -> x,b[0] -> y,b[0] -> z)); 
        
        if ( temperature > tporog) temperature *= 0.99; 
        else 
        { 
            if ( temperature < 1)temperature = 1; else temperature *= 1.1; 
        } 
        glColor3fv(color1); 
        //font.glDrawText(SSY, 14, SSY-96,"o");/////  
        //  font.glDrawText(SSY, 70, SSY-96,"o");/////  
        font.glDrawText(SSY, 10, SSY - 90,"Т = %.f C",tporog - 274);/// / / 

        if(!mapmode)
			font.glDrawText(SSY, (SSX >> 1)-100, SSY - 120,"[ V ] - Переключиться в стратегический режим");
		else
		{	font.glDrawText(SSY, (SSX >> 1)-100, SSY - 160,"[ V ] - Переключиться в симуляторный режим");
			font.glDrawText(SSY, (SSX >> 1)-100, SSY - 130,"[ F ] - Сфокусироваться на объекте");
			font.glDrawText(SSY, (SSX >> 1)-100, SSY - 100,"[ M ] - Приказать юниту двигаться");		
		}

    } 
    glColor3fv(color3); 
  
	//font.glDrawText(SSY, p.x+25 , p.y - 10,"+");/// / / 
    // glColor3fv(color3)  
    //  font.glDrawText(SSY, p.x, SSY-p.y,".");/////  
    glColor3fv(color4); 
    font.glDrawText(SSY, 10, SSY - 35,STRVERSION); 
    font.glDrawText(SSY, 10, SSY - 25,"Programmer - Yevgeniy Useynov(C) 2006"); 
    /* 
    
    if ( WithStars) 
    glColor3fv(color3); 
    else glColor3fv(color4); 
    font.glDrawText(SSY, 10, 10,"[6]Show stars"); 
    
    if ( WithTraectory) 
    glColor3fv(color3); 
    else glColor3fv(color4); 
    font.glDrawText(SSY, 10, 20,"[7]Show orbits");/// / / 
    
    if ( WithLabels) 
    glColor3fv(color3); 
    else glColor3fv(color4); 
    font.glDrawText(SSY, 10, 30,"[8]Show labels");/// / / 
    
    if ( WithInfo) 
    glColor3fv(color3); 
    else glColor3fv(color4); 
    font.glDrawText(SSY, 10, 45,"[9]Show info");/// / / 
    
    if ( WithCabin) 
    glColor3fv(color3); 
    else glColor3fv(color4); 
    font.glDrawText(SSY, 10, 55,"[0]Show cabin");/// / / 
    */ 
    
    if ( WithInfo) 
    { 
         glColor3fv(color1);
		if(!mapmode)
		{	
			font.glDrawText(SSY, 200, SSY - 100,"[W] Газ"); 
			font.glDrawText(SSY, 200, SSY - 80,"[S ] Тормоз"); 
			font.glDrawText(SSY, 200, SSY - 60,"[ J ] Гипер-прыжок на 100000000 km"); 
			font.glDrawText(SSY, SSX - 100, SSY - 30,"[ + ] [ - ]");// 
	//		font.glDrawText(SSY, SSX - 90, 30,"IMIN %d",imin); 
			fontSmall.glDrawText(SSY, SSX - 90, 70,"X %f",myship -> x); 
			fontSmall.glDrawText(SSY, SSX - 90, 90,"Y %f",myship -> y); 
			fontSmall.glDrawText(SSY, SSX - 90, 110,"Z %f",myship -> z);


		}
				
		fontSmall.glDrawText(SSY,  90, 70,"[1] - построить сборщик ресурсов");
		fontSmall.glDrawText(SSY,  90, 90,"[2] - построить истребитель"); 

		font.glDrawText(SSY, SSX >>1 , 10,"РЕСУРСЫ  %d",RESOURCES);  
		
		if ( fps <= 25) 
			glColor3fv(color5); 
		else glColor3fv(color3); 
		font.glDrawText(SSY, SSX - 90, 10,"FPS %d",fps); 

    } 
    static float sp; 
    sp = myship -> GetSpeed() * SCALE; 
    
    if ( sp >= 300000) 
    fontMedium.glDrawText(SSY, 100, SSY - 150,"Абс. скорость = %.1f c",sp / 300000); 
    else fontMedium.glDrawText(SSY, 100, SSY - 150,"Абс. скорость = %d km / sec",(int)sp); 
    glEnable ( GL_LIGHTING); 
} 

void ShowOreol() 
{ 
 
	POINT pSol;
	pSol.x =  GetPos(GETX,pos0[0],pos0[1],pos0[2]);
	pSol.y =  GetPos(GETY,pos0[0],pos0[1],pos0[2]);

	POINT pvA;
	POINT pvB;
	POINT pvC;

	pvA.x = GetPos(GETX ,vA[0], vA[1], vA[2]);
	pvA.y = GetPos(GETY ,vA[0], vA[1], vA[2]);	
	pvB.x = GetPos(GETX ,vB[0], vB[1], vB[2]);
	pvB.y = GetPos(GETY ,vB[0], vB[1], vB[2]);	
	pvC.x = GetPos(GETX ,vC[0], vC[1], vC[2]);
	pvC.y = GetPos(GETY ,vC[0], vC[1], vC[2]);	

    if ( GetPos(GETZ,pos0[0],pos0[1],pos0[2]) == 0 
		&& GetPos(GETX,pos0[0],pos0[1],pos0[2]) > 0 
		&&  GetPos(GETY,pos0[0],pos0[1],pos0[2]) > 0 
		&&  GetPos(GETX,pos0[0],pos0[1],pos0[2]) < SSX 
		&&  GetPos(GETY,pos0[0],pos0[1],pos0[2]) < SSY 
	//	&& !PtInTriang(pSol,pvA,pvB,pvC)
//		&& !PtInTriang(pSol,pvB,pvA,pvC)
) 

  { 
        glPushMatrix(); 
        //  glRotatef(90-ugol(mmm[12],mmm[14],b[0]->x,b[0]->z),0,1,0);  
        // glRotatef(90-ugol(mmm[12],mmm[14],b[0]->x,b[0]->z),0,0,1);      
	
		double c=rasst(pos0[0],pos0[1],pos0[2],mmm[12],mmm[13],mmm[14]);
		double a=mmm[14]-pos0[2];

		double ugol_1 = ugol(mmm[12],mmm[13],pos0[0],pos0[1]);
		double ugol_2 = asin(a/c)*_180oP;
 

		glTranslatef(pos0[0],pos0[1],pos0[2]);
		glRotatef(ugol_1+90,0,0,1);
		glRotatef(ugol_2,1,0,0);

        glCallList(OREOL);  
        glPopMatrix(); 
    } 
} 

void ShowCorone() 
{ /*
    static float grad = 0; 
    grad -= xrot * 0.2; 
    static float grad2 = 0; 
    grad2 -= zrot * 0.2; 
    static float rot = 0; 
    
    if ( ( rot -= 0.01) > 360)rot = 0; 
    static int add = rand()%360; 
    static int add2 = rand()%360; 
    static bool temp = ( rand()%100) > 50; 
  */  
 /*    if ( GetPos(GETZ,pos0[0],pos0[1],pos0[2]) == 0 
		&& GetPos(GETX,pos0[0],pos0[1],pos0[2]) > 0 
		&&  GetPos(GETY,pos0[0],pos0[1],pos0[2]) > 0 
		&&  GetPos(GETX,pos0[0],pos0[1],pos0[2]) < SSX 
		&&  GetPos(GETY,pos0[0],pos0[1],pos0[2]) < SSY 
) */
   { 
        glPushMatrix(); 
		//glRotatef(grad2 + rot + add,1,0,0); 
		//glPushMatrix();
		double c=rasst(pos0[0],pos0[1],pos0[2],mmm[12],mmm[13],mmm[14]);
		double a=mmm[14]-pos0[2];
		double ugol_1 = ugol(mmm[12],mmm[13],pos0[0],pos0[1]);
		double ugol_2 = asin(a/c)*_180oP;
		glTranslatef(pos0[0],pos0[1],pos0[2]);
		glRotatef(ugol_1+90,0,0,1);
		glRotatef(ugol_2,1,0,0);
        glCallList(LUCHI); 
        glPopMatrix(); 
      //glPopMatrix(); 
    } 
} 


void ShowGiantSol()
{
   static double rotateZ=0;
  rotateZ+=0.01;
   if(rotateZ> 360) 
	   rotateZ=0;

		glPushMatrix(); 
		
	//	glBindTexture(GL_TEXTURE_2D, texture[6]);
    
		glTranslatef(pos0[0],pos0[1],pos0[2]);

		if(!mapmode)
		{
			double c=rasst(pos0[0],pos0[1],pos0[2],mmm[12],mmm[13],mmm[14]);
			double a=mmm[14]-pos0[2];

			double ugol_1 = ugol(mmm[12],mmm[13],pos0[0],pos0[1]);
			double ugol_2 = asin(a/c)*_180oP;

			glRotatef(ugol_1,0,0,1);
			glRotatef(ugol_2-90,0,1,0);

			double radius = 7000;
			double H=radius*radius/(c-radius);

			if(H<radius*3) H=radius*3;

			glDisable				(GL_LIGHTING);
				CreateAtmosphere(1,1,0.7,radius,H,
				2*radius/(c-radius),
				c-radius);
		

		}
	
		glCallList(54321);

       glPopMatrix(); 
}


void ShowStars() 
{ 
    
    if ( ! mapmode) 
    { 
        glPushMatrix(); 
        glTranslatef(myship -> x * 0.9999,myship -> y * 0.9999,myship -> z * 0.9999); 
        glCallList(STARS); // glRotatef(-b[numkey]->rotate,b[numkey]->rx,b[numkey]->ry,b[numkey]->rz);  
        glPopMatrix(); 
    } 
    else 
    { 
        glPushMatrix(); 
        glLoadIdentity(); 
        glRotatef(YROTATE,1,0,0); 
        glRotatef(XROTATE,0,0,1); 
        glCallList(STARS); // glRotatef(-b[numkey]->rotate,b[numkey]->rx,b[numkey]->ry,b[numkey]->rz);  
        glPopMatrix(); 
    } 
} 

void ShowSpaceClouds() 
{ 
    glPushMatrix(); 
   // glTranslated(myship -> x,myship -> y,myship -> z); 
    // glDisable(GL_BLEND); 
    glRotatef(go * 180,0,0,1); 
    glEnable(GL_BLEND); 
    glDisable(GL_LIGHTING); 
    glEnable(GL_TEXTURE_2D); 
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);

    glBindTexture(GL_TEXTURE_2D, texture[5]);

    glColor4f(ro * 0.2,go * 0.2,bo * 0.2,1); 
    gluSphere ( qobj, 1000000, 20, 20); 



    glDisable ( GL_TEXTURE_2D); 
    glEnable(GL_LIGHTING);

	glDisable(GL_CULL_FACE);

	glPopMatrix(); 

} 

void ShowPlanetOrbit(PLANET * a) 
{ 
    glPushMatrix(); 
    //glLoadIdentity();  
    //glColor3f(1,1,1);  
    double temp = DISTANCE(a,b[0]); 
    glScalef(temp,temp,1); 
     if ( mapmode)  
    { 
        if(a->bVidelen) 
		{ glColor3f(0,0.5,0); 
		  glCallList(RING+1); 
		}
		else 
		{glColor3f(0.1,0.1,0.2);
		 glCallList(RING);
		}
    } 
    /* else 
    { 
        glColor3f(0.2,0.2,0.6); 
        glCallList(RING); 
    } 
    */ 
    glPopMatrix(); 
} 
void TempShowGruzovik()
{
 glPushMatrix();
  glCallList(GRUZOVIK);
 glPopMatrix();
}
void ShowTraectory(PLANET *a) 
{ 
   glDisable ( GL_LIGHTING); 
//   glEnable(GL_BLEND);
   glDisable(GL_BLEND);
   // glLineWidth(1);  
   // glColor3fv(a->colortraectory); 
 
   //glColor3f(0,0.4,0.4); 
glColor3f(0,0.5,0.5); 
   // if(!mapmode) 
   //  glBegin(GL_POINTS); 
   // else  
   glPointSize(1);
   glBegin(GL_POINTS); 
   // int d=0; 
   for ( int j = a -> i;j > a -> k - 1;j -- ) 
   { 
      //    if(d<255) d++; 
      //  glColor3b(300-d,300-d,300-d);   
      if ( j - 1 && j != 0 && a -> p[j - 1].x && a -> p[j].x) 
      { 
         glVertex3d(a -> p[j - 1].x, a -> p[j - 1].y,a -> p[j - 1].z); 
         //  glVertex3d(a->p[j-1].x+0.5, a->p[j-1].y+0.5,a->p[j-1].z+0.5); 
      } 
   } 
   glEnd(); 
 
   glEnable ( GL_LIGHTING); 
} 

void ShowPlanet(PLANET * a,int I) 
{ 
    //  double r = rasst(myship -> x,myship -> y,myship -> z,a -> x,a -> y,a -> z) - a -> radius;  
     float tempwz = a -> GetPos(GETZ);  
    //  
      if(WithLabels && tempwz==0)   
    //    if(a->NUM && a->NUM<GIANTSCOUNT || (a->NUM>=GIANTSCOUNT && r<5000))  
	  {
		  fontSmall.glDrawText(SSY,a->GetPos(GETX),a->GetPos(GETY),a->name);
	  }
  
//	if ( mapmode ) 
    { 
        
        if ( I < GIANTSCOUNT)    
			ShowPlanetOrbit(a); 	
	///	else       
		//	ShowTraectory(a); 
    } 
	

    //  if ( r > 50000 && FOV > 20)  
    //  a -> Show(ASPOINT,1);  
    //  else  
    //  {  
    
    if ( ! mapmode)a -> Show(HIGH,1); 
    else a -> Show(WARE,1); 
    //  }  
    // if(n<GIANTSCOUNT && n==numkey && rasst(winx1,winy1,0,winx2,winy2,0)<b[n]->hr/(FOV*8))  
    // zasv=false;  
} 

void ShowSol() 
{ 
   // glPushMatrix(); 
   // b[0] -> Show(HIGH,1); 
  //  glPopMatrix(); 
} 
#define PUSHM glPushMatrix(); 
#define POPM glPopMatrix(); 



void Display()
{
		/*		 glPushMatrix();
				 glLoadIdentity();
	

				 glTranslatef( focus.x, focus.y,-(kvad(kvad(ZDIST)))+focus.z); 			

		//		 glRotatef(YROTATE,1,0,0); 
		//		 glRotatef(XROTATE,0,0,1);
				 for(int i=0;i<PLANET_COUNT;i++)
				 b[i]->ShowAtm();
				 glPopMatrix();
*/

 	
		if ( ! mapmode) 
		{ 
			glMultMatrixd(invm); 
			glGetDoublev(GL_MODELVIEW_MATRIX,tempm); 
		}
		else
			{
			/*	glPushMatrix(); 
				 glMultMatrixd(invm); 
				 glGetDoublev(GL_MODELVIEW_MATRIX,tempm); 
				 glPopMatrix(); 
*/
				  if (ZDIST > GOALZDIST)
				  {  ZDIST*=0.97;
				  }

			//	 if ( ZDIST < Sqroot(Sqroot(*1.1)))
			//	 {ZDIST =  Sqroot(Sqroot(focus.a*1.1)); 
			//	 }

				 if ( ZDIST < 0)
				 {ZDIST =  0; 
				 }

				 if (ZDIST  > 40) ZDIST = 40;

				 
				 glTranslatef(0,0,-(kvad(kvad(ZDIST)))-focus.a*1.01); //

				 if(m_button)
					 XROTATE = 0;


				 glRotatef(YROTATE,1,0,0); 
				 glRotatef(XROTATE,0,0,1); 


			//	 glRotatef(15,0,1,0); 


				 glTranslated(
					 - focus.x, 
					 - focus.y, 
					 - focus.z); 
		
	
		

		
			
			}

		PUSHM 
		glLightfv(GL_LIGHT1, GL_POSITION, pos0); 


//	if(!mapmode)
//		ShowCorone(); 
   	
		ShowStars();

		ShowSpaceClouds(); 
		ShowGiantSol();


	for (int  n = 1;n < PLANET_COUNT;n ++ ) 
    	if ( E_planet[n] && n!=imin)
			ShowPlanet(b[n],n); 

			ShowPlanet(b[imin],n); 
		

	glDisable(GL_LIGHTING);



//		for(int i=0;i<1000;i++)
//		ball[i]->show();

		//	if(mapmode)
		//	ShowSol(); 

	
	
		glDisable			(GL_COLOR_MATERIAL);

		static float specL[4]={1,1,1,1};
		static float specL2[4]={0,0,0,1};	
		static float spec[4]={1,1,1,1};

		static float amb[4]={0.25,0.25,0.25,1};


		glLightfv			(GL_LIGHT1, GL_SPECULAR,specL);
	
		glMaterialfv		(GL_FRONT_AND_BACK, GL_SPECULAR,spec);
		glMaterialfv		(GL_FRONT_AND_BACK, GL_AMBIENT,amb);
		glMaterialf			(GL_FRONT_AND_BACK,GL_SHININESS,50);//76.8


		glColor4f(0.2,0.2,0.2,0);

		for(int i=0;i<UFOCOUNT;i++)
			ufo[i]->Show();
		
		glLightfv			(GL_LIGHT1, GL_SPECULAR,specL2);
		glEnable			(GL_COLOR_MATERIAL);
				
		zavod->Show();
		tower->Show();
	

	
		if(mapmode && m_button)
		{
			glBegin(GL_LINES);
			for (int xp=-50000; xp<50000; xp+=300)
			{
				if(fabs(::GetPos(GETX,xp,0,0)-p.x)<100/ZDIST) 
					 glColor3f (0,0,1);
				else glColor3f (0,0,0.05);

				glVertex3d(xp, 50000,0);
				glVertex3d(xp,-50000,0);

				if(fabs(::GetPos(GETY,0,xp,0)-p.y)<100/ZDIST) 
					 glColor3f (0,0,1);
				else glColor3f (0,0,0.05);

				glVertex3d(50000, xp,0);
				glVertex3d(-50000,xp,0);
						
			}
			glEnd();
		}


//	if(!mapmode)
//	ShowOreol();


	if(!mapmode)	
	{
		for ( n = 0;n < PLANET_COUNT;n ++ ) 
    	if ( E_planet[n] && n!=imin) 
			b[n]->ShowAtm(); 
		
		b[imin]->ShowAtm(); 
		
	}


	if(mapmode)
			myship->Show();



	POPM 
}



void Draw () 
{  

	glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	MyPerspective ( FOV,45/FOV,10000000 ); 	

	VP=false;
	
	if ( ! mapmode) 
	{
		glViewport (SSX - (SSX>>3) ,(SSY>>1)+(SSY>>3) , SSX>>3,SSY>>3);   
		glLoadIdentity (); 		
		glRotatef(180,0,1,0);
		Display();
	}

	VP=true;

	glViewport ( 0,0,SSX,SSY);  
	glLoadIdentity (); 
	Display();
  	ShowTextInformation(); 
	

	glDisable(GL_LIGHTING);
	glColor3f(0,.5,0);

//	if(mapmode)
	if(mouseLeftButton && !mouseRightButton)
	{
	/*	for(int i=MIN(fixPX,p.x);i<MAX(fixPX,p.x);i+=7)
		{fontMedium.glDrawText(SSY, i+20, p.y-20,"*");
		 fontMedium.glDrawText(SSY, i+20, fixPY-20,"*");
		}

		for(int j=MIN(fixPY,p.y);j<MAX(fixPY,p.y);j+=7)
		{fontMedium.glDrawText(SSY, p.x+20, j-20,"*");
		 fontMedium.glDrawText(SSY, fixPX+20, j-20,"*");
		}	
	*/	
		Begin2D();
			DrawQuad(fixPX,fixPY,p.x-fixPX,p.y-fixPY,1);
		End2D();
	} 


//TempShowGruzovik();

	if(simple_rasst(myship->x, myship->y, myship->z, b[imin]->x, b[imin]->y,b[imin]->z, b[imin]->radius*5))
	{	for(int n=0,yy=10;n<1000;n++)
		{
			if((NSTEXT+yy) > 0 && (NSTEXT+yy) < 280)

			fontSmall.glDrawText(SSY,10,NSTEXT+yy,b[imin]->info[n]);
			yy+=14;
		}
	}
	else  NSTEXT = 0;

    glFlush(); 
    glutSwapBuffers(); 
} 

#endif