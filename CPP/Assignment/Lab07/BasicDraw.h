#pragma once
#include "GL/glut.h"
struct Vertex
{
public:
	GLdouble x, y, z;
	Vertex(GLdouble x1, GLdouble y1, GLdouble z1);
};
class BasicDraw
{
public:
	void drawRectangle(Vertex v1, Vertex v2, Vertex v3, Vertex v4);
	void drawTrangle(Vertex v1, Vertex v2, Vertex v3, Vertex v4);
	void drawCircle(GLUquadric* sphere,GLdouble radius, GLint slices, GLint stacks);
};