#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************

void Troca(int *x0, int *y0, int *x1, int *y1){
	int aux0, aux1;
	aux0 = *x0;
	*x0 = *x1;
	*x1 = aux0;	

	aux1 = *y0;
	*y0 = *y1;
	*y1 = aux1;
}

class color {
	public:
	float r, g, b, a;
	color(float r, float g, float b, float a) {
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}
};

//função para colocar uma cor no pixel
void PutPixel(int x, int y, color c){
	FBptr[4*x + 4*y*IMAGE_WIDTH + 0] = c.r;
	FBptr[4*x + 4*y*IMAGE_WIDTH + 1] = c.g;
	FBptr[4*x + 4*y*IMAGE_WIDTH + 2] = c.b; 	
	FBptr[4*x + 4*y*IMAGE_WIDTH + 3] = c.a;
}

//Algoritimo de Bresenham para desenhar uma linha na tela
void DrawLine(int x0, int y0, int x1, int y1, color c0, color c1){
	int dx = x1 - x0;
	int dy = y1 - y0;
	bool trocou = false;
	bool inverteu = false;

	if (abs(dy) > abs(dx)){
		Troca(&x0, &x1, &y0, &y1);
		dx = x1 - x0;
		dy = y1 - y0;
		trocou = true;

	}
	
	if(trocou == true){
		PutPixel(y0, x0, c1);
	} else{
		PutPixel(x0, y0, c0);
	}
	
	if(dx < 0){
		Troca(&x0, &y0, &x1, &y1);
		dx = x1 - x0;
		dy = y1 - y0;
		color c2 = c0;
		c0 = c1;
		c1 = c2;
	}

	if(dy < 0){
		dy = -dy;
		inverteu = true;
	}

	//interpolação de cor, cada um desses deltas é a varição do começo até o fim da linha
	//no caso eles vao ser divididos pela variação do x, pois o while é igual a variação do x
	float dr = (c1.r - c0.r) / dx;
	float dg = (c1.g - c0.g) / dx;
	float db = (c1.b - c0.b) / dx;	
    
	int d = 2*dy - dx;
	int incr_e = 2 * dy;
	int incr_ne = 2 * (dy - dx);
	int x = x0;
	int y = y0;

	while (x < x1) {
		c0.r += dr;
		c0.g += dg;
		c0.b += db;
	
		if (d <= 0) {
			d += incr_e;
			x++;
		} else{
			d += incr_ne;
			x++;
			if(inverteu){ 
				y--;
			}
			else {
				y++;
				}
		}

		if(trocou == true){
			PutPixel(y, x, c0);
		} else{
			PutPixel(x, y, c0);
		}	
	}
}

void DrawTriangle(int x0, int y0, int x1, int y1, int x2, int y2, color c0, color c1, color c2){
	DrawLine(x0, y0, x1, y1, c0, c1);
	DrawLine(x1, y1, x2, y2, c1, c2);
	DrawLine(x2, y2, x0, y0, c2, c0);
}


#endif // _MYGL_H_

