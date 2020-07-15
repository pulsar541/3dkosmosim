#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <gl\glaux.h>

#define MAX_CHARS	257

class CFont
{
private:
	int		g_FontListID;
	int		font_height;
	HDC		h_DC;
	HFONT	hOldFont;
	HWND	h_Wnd;
	void PositionText( int x, int y, int win_height );

public:
	void CreateOpenGLFont(LPSTR strFontName, int height);
	void glDrawText(int win_height, int x, int y, const char *strString, ...);
	void ShowLabelText(int x, int y, char * OutString, int r, int g, int b);
	void ShowLabelInt(int x, int y, int mes, int r, int g, int b);
	void DestroyFont();
};
