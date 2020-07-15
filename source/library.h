/*
void kepler(double *dx,double *dy,double *dz,
			double *oldx,double *oldy,double *oldz,
			double *x,double *y,double *z,
			double *massa,
			int COUNT
			)


typedef void (WINAPI *cfunc) (	double *dx,double *dy,double *dz,
								double *oldx,double *oldy,double *oldz,
								double *x,double *y,double *z,
								double *massa,
								int COUNT
								);

cfunc kepler;

int LOADLIB(char* lib)
{
	HINSTANCE hLib=LoadLibrary(lib);
	if(hLib == NULL) 
		return -1;
	
	kepler=(cfunc)GetProcAddress((HMODULE)hLib,"kepler");
	if(kepler == NULL)
	{	FreeLibrary((HMODULE)hLib);
		return -2;
	}
	
	return 0;
}*/