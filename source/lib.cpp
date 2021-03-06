#include	"lib.h"

CMatrix&	CMatrix::SetIdentity	()
{	
	for (int i=0;i<4;i++)
		for (int j=0;j<4;j++) 
			if (i!=j) m[i][j]=0;
			else m[i][j]=1;
	return *this;
}
CMatrix&	CMatrix::SetRotateX		(float degree)
{
	float	c,s;
	SetIdentity	();
	c=cos(degree*3.14/180.);
	s=sin(degree*3.14/180.);
	m[1][1]=c;
	m[1][2]=-s;
	m[2][1]=s;
	m[2][2]=c;
	return	*this;
}
CMatrix&	CMatrix::SetRotateY		(float degree)
{
	float	c,s;
	SetIdentity	();
	c=cos(degree*3.14/180.);
	s=sin(degree*3.14/180.);
	m[0][0]=c;
	m[0][2]=s;
	m[2][0]=-s;
	m[2][2]=c;
	return *this;
}
CMatrix&	CMatrix::SetRotateZ		(float degree)
{
	float	c,s;
	SetIdentity	();
	c=cos(degree*3.14/180.);
	s=sin(degree*3.14/180.);
	m[0][0]=c;
	m[1][1]=c;
	m[0][1]=-s;
	m[1][0]=s;
	return *this;
}
CMatrix&	CMatrix::SetTranslate	(float dx,float dy,float dz)
{
	SetIdentity	();
	m[0][3]=dx;
	m[1][3]=dy;
	m[2][3]=dz;
	return *this;
}
CMatrix&	CMatrix::SetScale		(float kx,float ky,float kz)
{
	SetIdentity	();
	m[0][0]=kx;
	m[1][1]=ky;
	m[2][2]=kz;
	return *this;
}
CMatrix&	CMatrix::SetPerspective	(float c)
{
	SetIdentity	();
	m[3][2]=1./c;
	return *this;
}
CMatrix	CMatrix::operator= (CMatrix &mat)
{
	for	(int i=0;i<4;i++)
		for	(int j=0;j<4;j++)
			m[i][j]=mat.m[i][j];
	return	*this;
}
CMatrix	CMatrix::operator* (CMatrix &m2)
{
	int	i,j,k;
	CMatrix	t;
	for	(i=0;i<4;i++)
		for	(j=0;j<4;j++)
			t.m[i][j]=0;
	for	(i=0;i<4;i++)			
		for	(j=0;j<4;j++)		
			for	(k=0;k<4;k++)	
				t.m[i][k]+=m[i][j]*m2.m[j][k];
	return	t;
}

void	CMatrix::Print		(char *szName)
{
	printf	("======[ %s ]======\n",szName);
	for	(int i=0;i<4;i++)
		for	(int j=0;j<4;j++)
			if	(j!=3)	printf ("%.3f, ",m[i][j]);
			else		printf ("%.3f\n",m[i][j]);
}

void	CMatrix::Save	()
{
	//	�������� ������� � ������������ � ����������
	float	ptr[16];
	int	i,j;
	for	(i=0;i<4;i++)
		for	(j=0;j<4;j++)
			ptr[i+4*j]=m[i][j];
	glLoadMatrixf	(ptr);
}

void	CMatrix::Load	(GLenum pname)
{
	//	�������� ������� � ������������ � ����������
	float	ptr[16];
	int	i,j;
	glGetFloatv	(pname,ptr);
	for	(i=0;i<4;i++)
		for	(j=0;j<4;j++)
			m[i][j]=ptr[i+4*j];

}

void	ShowLines	()
{
	float	i,j;
	glColor3f	(1,1,1);
	glLineWidth	(2);
	glBegin	(GL_LINES);
		for	(i=-1;i<1;i+=.5)
			for	(j=-1;j<1;j+=.5)
			{
				glVertex3f	(i,j,-100);
				glVertex3f	(i,j,100);
			}
	glEnd	();
}

void	ShowAxis	(float len)
{
	glColor3f	(1,1,1);
	glLineWidth	(2);
	glBegin	(GL_LINES);

		glVertex2f	(-1.*len,0);
		glVertex2f	(1.*len,0);

		glVertex2f	(0,-1.*len);
		glVertex2f	(0,1.*len);

		glVertex2f	(.96*len,.04*len);
		glVertex2f	(.96*len,-.04*len);

		glVertex2f	(.04*len,.96*len);
		glVertex2f	(-.04*len,.96*len);

		glVertex3f	(0,0,-1.*len);
		glVertex3f	(0,0,1.*len);
		
		glVertex3f	(-.04*len,0,.96*len);
		glVertex3f	(.04*len,0,.96*len);

	glEnd	();
}

void	ShowObject	()
{
	glColor3f	(1,0,0);				//	���� �������
	glLineWidth	(1);					//	������� �����
	glBegin		(GL_LINE_LOOP);			//	������ ��������� �������
		glVertex2f	(-.25,0);
		glVertex2f	(0,.25);
		glVertex2f	(.25,-.15);
	glEnd		();
}
