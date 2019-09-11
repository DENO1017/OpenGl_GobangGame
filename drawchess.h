
#ifndef	_DRAW_CHESS_H_
#define	_DRAW_CHESS_H_

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef MACOS
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#endif


void DrawChess();


#endif	//_STANFORD_BUNNY_H_