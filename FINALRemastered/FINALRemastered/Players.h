#ifndef __Sprite_h__
#define __Sprite_h__
#include <cstdlib>
#include <string>
using namespace System::Drawing;
class CSprite
{
public:
	CSprite() {}
	~CSprite() {}
	virtual void CambiarSprite() {}
	virtual void dibujar(Graphics ^g) {}
	virtual void mover() {}
	void SetPosx(int value) { Posx = value; }
	int GetPosx() { return Posx; }
	void SetPosy(int value) { Posy = value; }
	int GetPosy() { return Posy; }
	void SetAncho(int value) { Ancho = value; }
	int GetAncho() { return Ancho; }
	void SetAlto(int value) { Alto = value; }
	int GetAlto() { return Alto; }
	void SetDeltax(int value) { Deltax = value; }
	int GetDeltax() { return Deltax; }
	void SetDeltay(int value) { Deltay = value; }
	int GetDeltay() { return Deltay; }

	void SetNombreArchivo(char* value) { NombreArchivo = value; }

	void SetIndiceSpritex(int value) { IndiceSpritex = value; }
	int GetIndiceSpritex() { return IndiceSpritex; }
	void SetIndiceSpritey(int value) { IndiceSpritey = value; }
	int GetIndiceSpritey() { return IndiceSpritey; }
	void SetDeltaSpritex(int value) { DeltaSpritex = value; }
	int GetDeltaSpritex() { return DeltaSpritex; }

protected:
	int Posx;
	int Posy;

	int Ancho;
	int Alto;

	int Deltax;
	int Deltay;

	char* NombreArchivo;

	int IndiceSpritex;
	int IndiceSpritey;

	int DeltaSpritex;

};
#endif // !__Sprite_h__

#ifndef __Jugador_h__
#define __Jugador_h__


class CJugador : public CSprite
{
private:
	int retraso = 0;
public:
	CJugador() {}
	CJugador(int pPosx, int pPosy, int pAncho, int pAlto, int pDeltax, int pDeltay, char* pNombreArchivo, int pIndiceSpritex, int pIndiceSpritey, int pDeltaSpritex)
	{
		Posx = pPosx;
		Posy = pPosy;
		Ancho = pAncho;
		Alto = pAlto;
		Deltax = pDeltax;
		Deltay = pDeltay;
		NombreArchivo = new char[100];
		strcpy(NombreArchivo, pNombreArchivo);
		IndiceSpritex = pIndiceSpritex;
		IndiceSpritey = pIndiceSpritey;
		DeltaSpritex = pDeltaSpritex;
	}
	void CambiarSprite()
	{
		DeltaSpritex = 0;
		if (Deltax == 0 && Deltay == 0)
			IndiceSpritey = 0;
		else {
			if (Deltax == 1 && Deltay == 0)
				IndiceSpritey = 1; DeltaSpritex = 1;
			if (Deltax == 0 && Deltay == 1)
				IndiceSpritey = 0; DeltaSpritex = 1;
			if (Deltax == -1 && Deltay == 0)
				IndiceSpritey = 3; DeltaSpritex = 1;
			if (Deltax == 0 && Deltay == -1)
				IndiceSpritey = 2; DeltaSpritex = 1;

			if (Deltax == 1 && Deltay == 1)
				IndiceSpritey = 4; DeltaSpritex = 1;
			if (Deltax == -1 && Deltay == 1)
				IndiceSpritey = 5; DeltaSpritex = 1;
			if (Deltax == 1 && Deltay == -1)
				IndiceSpritey = 6; DeltaSpritex = 1;
			if (Deltax == -1 && Deltay == -1)
				IndiceSpritey = 7; DeltaSpritex = 1;

		}
		IndiceSpritex = IndiceSpritex == 0 ? IndiceSpritex + DeltaSpritex : 0;
	}
	void dibujar(Graphics ^g)
	{
		Bitmap ^bmp = gcnew Bitmap(gcnew System::String(NombreArchivo));
		Rectangle porcion = Rectangle(Ancho*IndiceSpritex, Alto*IndiceSpritey, Ancho, Alto);
		Rectangle destino = Rectangle(Posx, Posy, Ancho*0.5, Alto*0.5);
		bmp->MakeTransparent();
		g->DrawImage(bmp, destino, porcion, GraphicsUnit::Pixel);
		delete bmp;

	}
	void mover(Graphics^ g)
	{
		int tempX = Posx + Deltax * 10;
		int tempY = Posy + Deltay * 10;
		if (!(tempX < g->VisibleClipBounds.Width*0.1 || tempX + (Ancho *0.5)>g->VisibleClipBounds.Width*0.9)) {
			Posx = tempX;
		}
		if (!(tempY < g->VisibleClipBounds.Height*0.1 || tempY + (Alto *0.5)>g->VisibleClipBounds.Height*0.9)) {
			Posy = tempY;
		}
		if (retraso == 4) {
			CambiarSprite();
			retraso = 0;
		}
		retraso++;
	}
	~CJugador() {}
	Rectangle getrectangle1()
	{
		return Rectangle(Posx, Posy, Ancho*0.5, Alto*0.5);
	}
};
#endif // !__Jugador_h__

#ifndef __Jugador2_h__
#define __Jugador2_h__

class CJugador2 : public CSprite
{
private:
	int retraso = 0;
public:
	CJugador2() {}
	CJugador2(int pPosx, int pPosy, int pAncho, int pAlto, int pDeltax, int pDeltay, char* pNombreArchivo, int pIndiceSpritex, int pIndiceSpritey, int pDeltaSpritex)
	{
		Posx = pPosx;
		Posy = pPosy;
		Ancho = pAncho;
		Alto = pAlto;
		Deltax = pDeltax;
		Deltay = pDeltay;
		NombreArchivo = new char[100];
		strcpy(NombreArchivo, pNombreArchivo);
		IndiceSpritex = pIndiceSpritex;
		IndiceSpritey = pIndiceSpritey;
		DeltaSpritex = pDeltaSpritex;
	}
	void CambiarSprite()
	{
		DeltaSpritex = 0;
		if (Deltax == 0 && Deltay == 0)
			IndiceSpritey = 0;
		else {
			if (Deltax == 1 && Deltay == 0)
				IndiceSpritey = 1; DeltaSpritex = 1;
			if (Deltax == 0 && Deltay == 1)
				IndiceSpritey = 0; DeltaSpritex = 1;
			if (Deltax == -1 && Deltay == 0)
				IndiceSpritey = 3; DeltaSpritex = 1;
			if (Deltax == 0 && Deltay == -1)
				IndiceSpritey = 2; DeltaSpritex = 1;

			if (Deltax == 1 && Deltay == 1)
				IndiceSpritey = 4; DeltaSpritex = 1;
			if (Deltax == -1 && Deltay == 1)
				IndiceSpritey = 5; DeltaSpritex = 1;
			if (Deltax == 1 && Deltay == -1)
				IndiceSpritey = 6; DeltaSpritex = 1;
			if (Deltax == -1 && Deltay == -1)
				IndiceSpritey = 7; DeltaSpritex = 1;
		}
		IndiceSpritex = IndiceSpritex == 0 ? IndiceSpritex + DeltaSpritex : 0;
	}
	void dibujar(System::Drawing::Graphics ^g)
	{
		Bitmap ^bmp = gcnew Bitmap(gcnew System::String(NombreArchivo));
		Rectangle porcion = Rectangle(Ancho*IndiceSpritex, Alto*IndiceSpritey, Ancho, Alto);
		Rectangle destino = Rectangle(Posx, Posy, Ancho *0.5, Alto *0.5);
		bmp->MakeTransparent(bmp->GetPixel(1, 1));
		g->DrawImage(bmp, destino, porcion, GraphicsUnit::Pixel);
		delete bmp;

	}
	void mover(Graphics^ g)
	{

		int tempX = Posx + Deltax * 10;
		int tempY = Posy + Deltay * 10;
		if (!(tempX < g->VisibleClipBounds.Width*0.1 || tempX + (Ancho *0.5)>g->VisibleClipBounds.Width*0.9)) {
			Posx = tempX;
		}
		if (!(tempY < g->VisibleClipBounds.Height*0.1 || tempY + (Alto *0.5)>g->VisibleClipBounds.Height*0.9)) {
			Posy = tempY;
		}
		if (retraso == 5) {
			CambiarSprite();
			retraso = 0;
		}
		retraso++;
	}
	Rectangle getrectangle2()
	{
		return Rectangle(Posx, Posy, Ancho*0.5, Alto*0.5);
	}
	~CJugador2() {}
};
#endif __Jugador2_h__