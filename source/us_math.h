//#include<math.h>

/*
const long double PiOver180=3.14159265358979323846/180.000000; // для перевода радиан в углы


double FSIN(double x)
{double xxx=x*x*x;

 return x-0.166666667*xxx
	     +0.008333333*xxx*x*x
		 -0.000198413*xxx*xxx*x
		 +0.000002756*xxx*xxx*xxx;

}



double FCOS(double x)
{ 
 double xx=x*x;
 double xxxx=xx*xx;

 return   1.00000000
	     -0.500000000*xx
		 +0.041666667*xxxx
		 -0.001388889*xxxx*xx
		 +0.000024802*xxxx*xxxx;

	//	 -0.000000276*xxxx*xxxx*xx;

}




double minirand()
{ return (double)(rand()%100)/75;
}


double minirand2()
{  return (double)(rand()%100)/4000;
}



double myrandom(double a,double b)
{a*=1000;
 b*=1000;
 double temp1=a+rand()%((int)b-(int)a);
 return  (temp1*1000);
}


double UGOL(double X1,double Y1,double X2,double Y2)
{ double b;  b=fabs(Y1-Y2);
 double c;  c=fabs(X1-X2);
 double result_ugol=0;

  if(Y2<=Y1 && X2>=X1) result_ugol=360-atan(b/c)/PiOver180;
  if(Y2<=Y1 && X2<X1)  result_ugol=180+atan(b/c)/PiOver180;
  if(Y2>Y1 && X2<=X1)  result_ugol=180-atan(b/c)/PiOver180;
  if(Y2>Y1 && X2>X1)   result_ugol=atan(b/c)/PiOver180;  
  return result_ugol;

}


double V_KVADRATE(double ch)
{ return ch*ch;
}
*/
//double (*kv)(double )=V_KVADRATE;


//double (*SIN)(double)=sin;
//double (*COS)(double)=cos;

/*

double KOREN(double x)
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

double (*koren)(double)=KOREN;




double  RASSTOYANIE (double X1,double Y1,double X2,double Y2)
{return hypot(fabs(X1-X2),fabs(Y1-Y2));
} ;

*/