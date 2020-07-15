
#define TYPE_POINTS		0x0001
#define TYPE_LINES		0x0002
#define TYPE_POLYGONS	0x0003

#ifndef	_ASC2LIST_H_
#define _ASC2LIST_H_


extern "C" __declspec(dllexport)  int Load3d(char *filename,float scale,short type);
#endif

