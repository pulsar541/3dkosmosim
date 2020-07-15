#include "mathem.h"
#include "math.h"
#include "windows.h"


//double PO180=3.14159265358979323846264/180.000000; // для перевода радиан в углы
//double _180oP=180.000000/3.14159265358979323846264; // для перевода углов в радианы 

#define ITNUM 5

double Sqroot(double x) {
  int expo,i;
  double a,b;
  if(x<=0.F) return(0.F);
  /* decompose x into mantisse ranged [0.5,1) and exponent. Machine-
     dependent operation is presented here as a function call. */
  x=frexp(x,&expo);
  /* odd exponent: multiply mantisse by 2 and decrease exponent 
     making it even. Now the mantisse is ranged [0.5,2.) */
  if(expo&1) {x*=2.F;expo--;}
  /* initial approximation */
  a=1.F;
  /* process ITNUM Newtonian iterations with the mantisse as 
     an argument */
  for(i=ITNUM;i>0;i--) {
    b=x/a; a+=b; a*=0.5F;
  }
  /* divide the exponent by 2 and combine the result.
     Function ldexp() is opposite to frexp. */
  a=ldexp(a,expo/2);
  return(a);
}



/*


long double fsin[3600000];
long double fcos[3600000];
void SetMySinCos()
{
	for(unsigned long i=0;i<3600000;i++)
	{	fsin[i]=sin(i*0.0001);
		fcos[i]=cos(i*0.0001);	
	}
}

float FSIN(float x)
{//return sin(x); 
 return fsin[(int)(x*10000)];
}

float FCOS(float x)
{  //return cos(x);
return fcos[(int)(x*10000)];
}*/

double FSIN(double x)
{double xx=x*x;//2
 double xxx=xx*x;//3
 double xxxxxx=xxx*xxx; //6

 return x-0.166666667*xxx
	     +0.008333333*xxx*xx
		 -0.000198413*xxxxxx*x
		 +0.000002756*xxxxxx*xxx
		 -0.000000025*xxxxxx*xxx*xx;

}



double FCOS(double x)
{ 
 double xx=x*x;
 double xxxx=xx*xx;
 double xxxxxxxx=xxxx*xxxx;
 //return fcos[(int)(x)][(int)((x-(int)x)*1000)];
 
 return   1.00000000
	     -0.500000000*xx
		 +0.041666667*xxxx
		 -0.001388889*xxxx*xx
		 +0.000024802*xxxxxxxx
		 -0.000000276*xxxxxxxx*xx
		 +0.000000002*xxxxxxxx*xxxx;
}




int iminimum(double x,double y,double z)
{
return 0;
}


double minirand()
{ return (double)(rand()%10000)/10000;
}


double minirand2()
{  return (double)(rand()%100)/4000;
}


double myrandom(double a,double b)
{a*=1000;
 b*=1000;
 double temp=(a+rand()%((int)b-(int)a));
 return temp/1000;

}


double  rasst (double X1,double Y1,double Z1,
			   double X2,double Y2,double Z2)
{
	return Sqroot(kvad(fabs(X1-X2))+kvad(fabs(Y1-Y2))+ kvad(fabs(Z1-Z2)));


} ;

bool  simple_rasst (double X1,double Y1,double Z1,
	  				  double X2,double Y2,double Z2, double R)
{

	return (X1< X2+R && X1> X2-R &&
			Y1< Y2+R && Y1> Y2-R &&
			Z1< Z2+R && Z1> Z2-R );
	

	
//	return (fabs(X1-X2)<R && fabs(Y1-Y2)<R && fabs(Z1-Z2)<R);

} ;

double ugol(double X1,double Y1,double X2,double Y2)
{ double result_ugol;
 double b;  b=fabs(Y1-Y2);
 double c;  c=fabs(X1-X2);


  if(Y2<=Y1 && X2>=X1) result_ugol=360-atan(b/c)*_180oP;
  if(Y2<=Y1 && X2<X1)  result_ugol=180+atan(b/c)*_180oP;
  if(Y2>Y1 && X2<=X1)  result_ugol=180-atan(b/c)*_180oP;
  if(Y2>Y1 && X2>X1)   result_ugol=atan(b/c)*_180oP;  

  return result_ugol;

}



bool  PtInTriang(POINT P,POINT A,POINT B,POINT C)
{
	  if ((P.x-A.x)*(A.y-B.y) - (P.y-A.y)*(A.x-B.x) >= 0) 
	  {
		  if ((P.x-B.x)*(B.y-C.y) - (P.y-B.y)*(B.x-C.x) >= 0) 
		  {
			  if ((P.x-C.x)*(C.y-A.y) - (P.y-C.y)*(C.x-A.x) >= 0) 
			  return true;// попадает
		  }
	  }

	  return false;// не попадает
}




int pokrugu(int K) 
{ static int k = 1; 
   if ( k == K) k = 1; 
   else k ++; 
   return k; 
} 






/*
double sqrt(double x)
{int i=0;
 float sq0,sq=x;
 do
 {
   i++;  
   sq0=sq; 
   sq=(sq0+x/(sq0))/2;
 }
 while(sq!=sq0);
 return sq;
}





double  RASST (double X1,double Y1,double X2,double Y2)
{return sqrt(kv(fabs(X1-X2))+kv(fabs(Y1-Y2)));
} 
*/
//double (*rasst)(double ,double ,double ,double )=RASSTOYANIE;



