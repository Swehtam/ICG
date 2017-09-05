#include "main.h"

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************

	int i = 384;
	float dc = 63.0;
	int dy = 96;
	int dx = 64;
	
	DrawTriangle(256, 0, color(255, 0, 0, 255), 0, i, color(0, 255, 0, 255), 512, i,
					color(0, 0, 255, 255));
	DrawTriangle(256, 0, color(255, 0, 0, 255), 0, i, color(0, 255, 0, 255), 128, i, 
					color(0, 255-dc, dc, 255));
	DrawTriangle(256, 0, color(255, 0, 0, 255), 0, i, color(0, 255, 0, 255), 256, i, 
					color(0, 255 - (2*dc), dc*2, 255));
	DrawTriangle(256, 0, color(255, 0, 0, 255), 0, i, color(0, 255, 0, 255), i, i, 
					color(0, 255 - (3*dc), dc*3, 255));
	DrawTriangle(256, 0, color(255, 0, 0, 255), dx, i-dy, color(dc, 255-dc, 0, 255), 512-dx,
 					i-dy, color(dc, 0, 255-dc, 255));
	DrawTriangle(256, 0, color(255, 0, 0, 255), dx*2, i - (2*dy), 
					color(2*dc, 255 - (2*dc), 0, 255), 512 - (2*dx), i - (2*dy),
					color(2*dc, 0, 255 - (2*dc), 255));
	DrawTriangle(256, 0, color(255, 0, 0, 255), dx*3, i - (3*dy),
					color(3*dc, 255 - (3*dc), 0, 255), 512 - (3*dx), i - (3*dy),
					color(3*dc, 0, 255 - (3*dc), 255));

}

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;	

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}
