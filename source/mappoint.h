#ifndef _mappoint_h_
#define _mappoint_h_

class MapPoint
{   public:
	int mappointsize;

	double x,y;

	void Show(double x,double y)
	{this->x=x;
this->x=y;
		glPushMatrix();
		glTranslated(x,y,0);
		glPointSize(mappointsize);
		glCallList(LISTPOINT);
		glPointSize(1);
		glPopMatrix();

		if(fabs(p.x-GetPos(GETX))<20 && 
		   fabs(p.y-GetPos(GETY))<20  )
		   mappointsize = 10;
		else 
		   mappointsize = 3;
	}

	int GetPos(int mode) 
	{static double mv[16],pm[16];
	 static int vp[4];
	 static double  winx,winy,winz;

	 glGetDoublev(GL_MODELVIEW_MATRIX, mv);
	 glGetDoublev(GL_PROJECTION_MATRIX,pm);
	 glGetIntegerv(GL_VIEWPORT,vp);
	 gluProject(x,y,0,mv,pm,vp,&winx,&winy,&winz);

	 switch(mode)
	 {case GETX: return winx;
	  case GETY: return SSY-winy;
	  case GETZ: return winz;
	  default  : return 0;
	 }
	}

/*	void Process()
	{
	

	}*/
};

#endif