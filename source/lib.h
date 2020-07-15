#ifndef		__LIB_H__
#define		__LIB_H__


//#include	<afxwin.h>
#include	"glut.h"
#include	<stdio.h>
#include	<math.h>
#include	<iostream.h>

//#pragma	warning	(disable:4305)
//#pragma	comment	(lib,"opengl32.lib")
//#pragma	comment	(lib,"glut32.lib")
//#pragma	comment	(lib,"glu32.lib")

void	ShowAxis	(float len=1);
void	ShowLines	();
void	ShowObject	();

class	CMatrix
{
	float	m[4][4];
public:
	CMatrix		()				{SetIdentity();}
	CMatrix&	SetIdentity		();
	CMatrix&	SetRotateX		(float degree);
	CMatrix&	SetRotateY		(float degree);
	CMatrix&	SetRotateZ		(float degree);
	CMatrix&	SetTranslate	(float dx,float dy,float dz=0);
	CMatrix&	SetScale		(float kx,float ky,float kz=1);
	CMatrix&	SetPerspective	(float c);
	CMatrix		operator=		(CMatrix&m);
	CMatrix		operator*		(CMatrix&m);
	void		Print			(char *szName="Matrix");
	void		Save			();
	void		Load			(GLenum pname=GL_MODELVIEW_MATRIX);
};

#endif	//	__LIB_H__