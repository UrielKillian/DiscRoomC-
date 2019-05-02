#pragma once
#ifndef __CJuego2_H__
#define __CJuego2_H__
using namespace System::Drawing;
#include "Players.h"
#include "ArrDisco.h"

class CJuego2
{
private:
	CArreglo* arrDisco;
	CJugador2 * Jugador;
	bool barras_p1 = false;

public:
	int vida2 = 60;
	int Nivel = 1;
	int barra = 0;
	int barras = 190;
	CJuego2()
	{
		arrDisco = new CArreglo();
		Jugador = new CJugador2(315, 314, 73, 88.5, 0, 0, "Imagenes\\omar.png", 0, 0, 0);

		if (Nivel == 1)
		{

			arrDisco->agregarDisco();
			arrDisco->agregarPersecutor2();
		}


	}
	~CJuego2() {}

	void setbarras_p(bool barras_p1)
	{
		this->barras_p1 = barras_p1;
	}

	bool getbarras_p()
	{
		return barras_p1;
	}

	void Bajabarras(bool barras_p1)
	{
		if (barras_p1 == true)
			barras--;
	}

	void sombras(Graphics^ g) {
		Jugador->dibujar(g);
		Jugador->mover(g);

	}
	void agregar()
	{
		arrDisco->agregarDisco();
		arrDisco->agregarPersecutor2();
	}
	void ProcesarTick(Graphics ^g)
	{
		Random r;
		if (barra <= 790)
			barra = barra + 1;
		if (barra == 790) {
			barra = 0;
			arrDisco->borrar();
			Nivel++;
		}

		Bitmap^bmpPersecutor = gcnew Bitmap("Imagenes\\discosinfondo2.png");
		Bitmap^bmpDisco = gcnew Bitmap("Imagenes\\sierrasfinal.png");
		bmpPersecutor->MakeTransparent();
		bmpDisco->MakeTransparent();
		if (vida2 > 0)
		{
			Jugador->dibujar(g);
			Jugador->mover(g);
		}
		arrDisco->dibujar(g, bmpDisco);
		arrDisco->dibujarp2(g, bmpPersecutor, Jugador->GetPosx(), Jugador->GetPosy());
		arrDisco->colisionp2(Jugador->getrectangle2(),vida2);
		if (arrDisco->getcolision2() == true)
		{
			arrDisco->setcolision2(false);
			vida2 = vida2 - 20;
		}
		if (vida2 <= 0)
		{
			Jugador->SetPosx(1000);
			Jugador->SetPosy(1000);
		}
		g->FillRectangle(Brushes::Green, Jugador->GetPosx() - 15, Jugador->GetPosy() - 20, vida2, 13);
		Bajabarras(getbarras_p());

		if (barra == 5 && Nivel == 1)agregar();
		if (barra == r.Next(100, 200) && Nivel == 1)agregar();
		if (barra == r.Next(300, 400) && Nivel == 1)agregar();
		if (barra == 25 && Nivel == 1)agregar();
		if (barra == r.Next(25, 200) && Nivel == 2)agregar();
		if (barra == r.Next(200, 300) && Nivel == 2)agregar();
		if (barra == r.Next(300, 400) && Nivel == 2)agregar();
		if (barra == 25 && Nivel == 2)agregar();
		if (barra == r.Next(100, 200) && Nivel == 3)agregar();
		if (barra == r.Next(300, 400) && Nivel == 3)agregar();
		if (barra == r.Next(400, 500) && Nivel == 3)agregar();
		if (barra == 25 && Nivel == 3)agregar();
		if (barra == r.Next(100, 200) && Nivel == 4)agregar();
		if (barra == r.Next(600, 700) && Nivel == 4)agregar();
		if (barra == 25 && Nivel == 4)agregar();
		if (barra == r.Next(700, 800) && Nivel == 5)agregar();
		if (barra == 25 && Nivel == 5)agregar();
		if (barra == 25 && Nivel == 5)agregar();
		if (barra == 100 && Nivel == 5)agregar();
	}

	void ProcesarKeyDown2(System::Windows::Forms::Keys e)
	{
		switch (e) {
		case System::Windows::Forms::Keys::Left:
			Jugador->SetDeltax(-1);
			break;
		case System::Windows::Forms::Keys::Up:
			Jugador->SetDeltay(-1);
			break;
		case System::Windows::Forms::Keys::Right:
			Jugador->SetDeltax(1);
			break;
		case System::Windows::Forms::Keys::Down:
			Jugador->SetDeltay(1);
			break;
		default:
			break;
		}
	}


	void ProcesarKeyUp2(System::Windows::Forms::Keys e)
	{
		switch (e) {
		case System::Windows::Forms::Keys::Left:
			Jugador->SetDeltax(0);
			break;
		case System::Windows::Forms::Keys::Up:
			Jugador->SetDeltay(0);
			break;
		case System::Windows::Forms::Keys::Right:
			Jugador->SetDeltax(0);
			break;
		case System::Windows::Forms::Keys::Down:
			Jugador->SetDeltay(0);
			break;
		default:
			break;
		}
	}
};
#endif // !__CJuego1_H__

