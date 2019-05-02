#ifndef __PadreD_H__
#define __PadreD_H__
#include <random>
using namespace System;
class CPadreD
{
public:
	CPadreD(int ancho, int alto) {
		Random r;
		x = r.Next(400,600);
		y = r.Next(400, 600);
		indiceX = 0;
		indiceY = 0;
		w = ancho;
		h = alto;
		dx = r.Next(-5, 5);
		dy = r.Next(-6, 6);
		dxp = 4;
		dyp = 4;
		eliminado = false;
	}
	~CPadreD() {}
	bool geteliminado() { return eliminado; }
	void seteliminado(bool eliminado) { eliminado = eliminado; }
protected:
	int x;
	int y;
	int indiceX;
	int indiceY;
	int w;
	int h;
	int dx;
	int dy;
	int dxp;
	int dyp;
	bool eliminado;
};

#endif // !__PadreD_H__


#ifndef __Disco_H__
#define __Disco_H__
using namespace System::Drawing;
class CDisco : public CPadreD
{
public:
	CDisco() :CPadreD(140, 140) {}
	~CDisco() {}
	void mover(Graphics^ g) {
		if (x + dx <= g->VisibleClipBounds.Width*0.1 || x + w*0.7 + dx >= g->VisibleClipBounds.Width*0.9)
			dx *= -1;
		if (y + dy <= g->VisibleClipBounds.Height*0.1 || y + h*0.7 + dy >= g->VisibleClipBounds.Height*0.9)
			dy *= -1;
		x += dx;
		y += dy;
	}
	void animar() {
		indiceX++;
		if (indiceX == 4)
			indiceX = 0;
	}
	void dibujar(Graphics^g, Bitmap^bmpDisco) {
		animar();
		mover(g);
		Rectangle PAU = Rectangle(indiceX*w, indiceY*h, w, h);
		Rectangle zoom = Rectangle(x, y, w*0.7, h*0.7);
		g->DrawImage(bmpDisco, zoom, PAU, GraphicsUnit::Pixel);
	}
	Rectangle getRectangulo() {
		return Rectangle(x, y, w*0.7, h*0.7);
	}
private:

};

#endif // !__Disco_H__

#ifndef __Persecutor_H__
#define __Persecutor_H__
using namespace System::Drawing;
class CPersecutor : public CPadreD
{
public:
	CPersecutor() :CPadreD(554 / 4, 140) {}
	~CPersecutor() {}
	void movers(Graphics^ g, int px, int py) {

		if (px <= x)x -= dxp;
		if (px >= x && x + dxp + w*0.7 <= g->VisibleClipBounds.Width*0.9)x += dxp;
		if (py <= y)y -= dyp;
		if (py >= y && y + dyp + h*0.7 <= g->VisibleClipBounds.Width*0.9)y += dyp;

	}
	void animar() {
		indiceX++;
		if (indiceX == 4)
			indiceX = 0;
	}
	void dibujar(Graphics^g, Bitmap^bmpPersecutor, int px, int py) {
		animar();
		movers(g, px, py);
		Rectangle PAU = Rectangle(indiceX*w, indiceY*h, w, h);
		Rectangle zoom = Rectangle(x, y, w*0.7, h*0.7);
		g->DrawImage(bmpPersecutor, zoom, PAU, GraphicsUnit::Pixel);
	}
	Rectangle getRectangulo() {
		return Rectangle(x, y, w*0.7, h*0.7);
	}
private:

};

#endif // !__Persecutor_H__

#ifndef __Persecutor2_H__
#define __Persecutor2_H__
using namespace System::Drawing;
class CPersecutor2 : public CPadreD
{
public:
	CPersecutor2() :CPadreD(554 / 4, 140) {}
	~CPersecutor2() {}
	void movers(Graphics^ g, int px, int py) {

		if (px <= x)x -= dxp;
		if (px >= x && x + dxp + w*0.7 <= g->VisibleClipBounds.Width*0.9)x += dxp;
		if (py <= y)y -= dyp;
		if (py >= y && y + dyp + h*0.7 <= g->VisibleClipBounds.Width*0.9)y += dyp;

	}
	void animar() {
		indiceX++;
		if (indiceX == 4)
			indiceX = 0;
	}
	void dibujar(Graphics^g, Bitmap^bmpPersecutor, int px, int py) {
		animar();
		movers(g, px, py);
		Rectangle PAU = Rectangle(indiceX*w, indiceY*h, w, h);
		Rectangle zoom = Rectangle(x, y, w*0.7, h*0.7);
		g->DrawImage(bmpPersecutor, zoom, PAU, GraphicsUnit::Pixel);
	}
	Rectangle getRectangulo() {
		return Rectangle(x, y, w*0.7, h*0.7);
	}
private:

};

#endif // !__Persecutor2_H__
