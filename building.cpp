#include <Windows.h>
#include <math.h>
#include <gl\GL.h>
#include "building.h"
#include "glVector.h"

#define MAX_VBUFFER 256


/*  Constructor for	building */
building::building (int type, int x, int y, int height, int width, int depth)
{
	_x = x;
	_y = y;
	_height = height;
	_width = width;
	_depth = depth;
/*	switch (type) {
		// 1.blocky
	case 1:
		CreateBlocky();
		break;
	}*/
}

building::~building()
{
}

void building::ConstructCube (int left, int right, int front, int back, int bottom, int top)
{
	GLvector *p[10];
	float x1,x2,z1,z2,y1,y2;
//	cube c;
	int height;

	height = top - bottom;
	x1 = (float)left;
	x2 = (float)right;
	y1 = (float)bottom;
	y2 = (float)top;
	z1 = (float)front;
	z2 = (float)back;

	p[0] = new GLvector (x1, y1, z1); 
	p[1] = new GLvector (x1, y2, z1); 
	p[2] = new GLvector (x2, y1, z1); 
	p[3] = new GLvector (x2, y2, z1); 
	p[4] = new GLvector (x2, y1, z2); 
	p[5] = new GLvector (x2, y2, z2); 
	p[6] = new GLvector (x1, y1, z2); 
	p[7] = new GLvector (x1, y2, z2); 
	p[8] = new GLvector (x1, y1, z1); 
	p[9] = new GLvector (x1, y2, z1);  
}