#pragma once
#ifndef __CJuego1_H__
#define __CJuego1_H__
using namespace System::Drawing;
#include "Players.h"
#include "ArrDisco.h"

class CJuego1
{
private:
	CArreglo* arrDisco;
	CJugador * Jugador;
	bool barras_p1 = false;
	
public:
	int vida1 = 60;
	int Nivel = 1;
	int barra = 0;
	int barras = 190;
	CJuego1()
	{
		arrDisco = new CArreglo();
		Jugador = new CJugador(315, 314, 73, 88.5, 0, 0, "Imagenes\\edinson2.png", 0, 0, 0);

		if (Nivel == 1)
		{

			arrDisco->agregarDisco();
			arrDisco->agregarPersecutor();
		}


	}
	~CJuego1() {}

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
		arrDisco->agregarPersecutor();
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
		if (vida1 > 0)
		{
			Jugador->dibujar(g);
			Jugador->mover(g);
		}
		arrDisco->dibujar(g, bmpDisco);
		arrDisco->dibujarp(g, bmpPersecutor, Jugador->GetPosx(), Jugador->GetPosy());
		arrDisco->colision(Jugador->getrectangle1(), vida1);
		if (arrDisco->getcolision1() == true)
		{
			arrDisco->setcolision1(false);
			vida1 = vida1 - 20;
		}
		if (vida1 <= 0)
		{
			Jugador->SetPosx(1000);
			Jugador->SetPosy(1000);
		}
		g->FillRectangle(Brushes::Green, Jugador->GetPosx()-15, Jugador->GetPosy() -20, vida1, 13);
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

	void ProcesarKeyDown(System::Windows::Forms::Keys e)
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


	void ProcesarKeyUp(System::Windows::Forms::Keys e)
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

