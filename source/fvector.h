#include "mathem.h"


// класс вектора силы
class FVECTOR
{public:
// double degree;		  //угол направления
// double degree2;	
 double value;		  //величина силы
 // координаты 
 double x0,y0,z0,  // откуда смотрит вектор
	    x1,y1,z1;  // куда смотрит вектор
 FVECTOR()
 {
//  degree=0;
 // degree2=0;
    value=0;
 }


 void calc_kas(double oldx,double oldy,double oldz,
	           double x,    double y,    double z)  
 { 

	x0=x;
    y0=y;
    z0=z;
	 
	x1=x+x-oldx;
    y1=y+y-oldy;
    z1=z+z-oldz;

	value=rasst(oldx, oldy, oldz , x,     y,     z);
}

 void calc_kas2(double oldx,double oldy,double oldz,
	            double x,    double y,    double z)  
 { 

	//x0=*x;
   // y0=*y;
   // z0=*z;
	 
	x1=x0+(x-oldx);
    y1=y0+(y-oldy);
    z1=z0+(z-oldz);

	value=rasst(oldx, oldy, oldz , x,     y,     z);
}

 void calc_prit(double xa,double ya,double za,
	            double xb,double yb,double zb,
				double mass)
 {  x0=xa;
    y0=ya;
    z0=za;
	
	double R=	rasst(xa,ya,za,xb,yb,zb);
	double temp=mass/(R*R*R);



	x1=x0- (xa-xb) * temp;
	y1=y0- (ya-yb) * temp;
	z1=z0- (za-zb) * temp;

//	старая неоптимизированная запись
/*	double value=*mass/kvad(R);
	x1=x0-value*(*xa-*xb)/R;
	y1=y0-value*(*ya-*yb)/R;
	z1=z0-value*(*za-*zb)/R;
*/

 }
      

};





void ResultofAddVect(FVECTOR *FRES,FVECTOR *A, FVECTOR *B)
{

	FRES->x0=A->x0;
	FRES->y0=A->y0;
	FRES->z0=A->z0;

 	FRES->x1=A->x1+B->x1-FRES->x0;
	FRES->y1=A->y1+B->y1-FRES->y0;
	FRES->z1=A->z1+B->z1-FRES->z0;

}
