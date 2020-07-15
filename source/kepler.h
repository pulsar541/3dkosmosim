#ifndef _KEPLER_H_
#define _KEPLER_H_

#define _RUBBER  0x0001
#define _PLAST	 0x0002
#define _METAL	 0x0003 //пока не работает

class BODY
{
public:
	double x,y,z;
	double dx,dy,dz;
	double massa;
	double radius;
	short material;
	double elasticity;
	double friction;
	bool isDynamic;
	double  koeffMove;
	bool  bNotIgnore;

	int NUM;
	int contact; 
	
	BODY()
	{	
	}
	void setPos(double x,double y,double z)
	{
		this->x=x;	
		this->y=y; 
		this->z=z;
		this->dx=this->dy=this->dz=0;
		this->massa=0;
		this->isDynamic=true;
		this->bNotIgnore=true;
		this->friction=0.5;
		contact=-1;	
	}

	void setDelta(double dx,double dy,double dz)
	{
		this->dx=dx;	
		this->dy=dy;
		this->dz=dz;
		koeffMove = 1;
	}
	
	void setMassa(double massa)
	{
		this->massa=massa;
	}

	void setRadius(double radius)
	{
		this->radius=radius;
	}

	void setMaterial(short material)
	{
		this->material=material;
	}
	void setElasticity(double elasticity)
	{
		this->elasticity=elasticity;
	}

	void setFriction(double friction)
	{
		this->friction=friction;
	}

	void setKoeffMove(double koeffMove)
	{
		this->koeffMove = koeffMove;
	}

	void move()
	{	
		x+=dx*koeffMove;
		y+=dy*koeffMove;
		z+=dz*koeffMove;
	}
};

extern "C" __declspec(dllexport) void keplerA(	double *dx,double *dy,double *dz,
										 		double *x,double *y,double *z,
												double *massa,
												double *r,
												int COUNT
											 );

extern "C" __declspec(dllexport) void keplerB(BODY *body,	int COUNT);


#endif

 