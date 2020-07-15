#ifndef __ase_h
#define __ase_h

/////////////////////////////////////////////////////////////////////////
// ASCII Scene Export Library Version 1.0.2 
// Copyright (c)2006, Maximov Nikolai.
/////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
extern "C" {
#endif

#include <windows.h>
#include <gl\gl.h>

#if defined(_WIN32)
 #if defined (_ASE_LIB)
  #define ASEAPI __declspec(dllexport)
 #else
  #define ASEAPI __declspec(dllimport)
  #pragma message("Note: including lib: ASELib.lib\n")
  #pragma comment (lib, "ASELib.lib")
 #endif
#else
 #define ASEAPI extern
#endif

#define ASE_VERSION_1_0_2

namespace aselib
{
	struct ASEAPI MESH
	{
		GLfloat *vertex;
		GLfloat *color;
		GLfloat *normal;
		GLfloat *texcoord;
		GLuint numverts;

		GLfloat aabb_min[3];
		GLfloat aabb_max[3];

		MESH();
		~MESH();
		bool Load (const char *filename);
		void Draw ();
		void Unload ();
	};
};

#ifdef __cplusplus
}
#endif

#endif /* __ase_h_ */
