#ifndef		__MATHEM_H__
#define		__MATHEM_H__
#include <windows.h>

#define		kvad(x) ((x) * (x)) 
#define MAX(a,b) ((a < b) ? (b) : (a))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define		 PO180	0.017453293  //3.1415926/180; // для перевода радиан в углы
#define		_180oP	57.29577952  //180/3.1415926; // для перевода углов в радианы 

double Sqroot(double x);		//быстрый квадратный корень
double FCOS(double x);		//быстрый косинус
double FSIN(double x);		//быстрый синус
double minirand();
double minirand2();
double myrandom(double a,double b);
double  rasst (double X1,double Y1,double Z1,
			   double X2,double Y2,double Z2);
bool  simple_rasst (double X1,double Y1,double Z1,
			   double X2,double Y2,double Z2,double R);

double ugol(double X1,double Y1,double X2,double Y2);

int    iminimum(double x,double y,double z);

bool  PtInTriang(POINT P,POINT A,POINT B,POINT C);


int GetPos(int mode ,double x,double y, double z);
int pokrugu(int K);



#endif
