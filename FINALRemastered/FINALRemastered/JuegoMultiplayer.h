#pragma once
#ifndef __Juego_h__
#define __Juego_h__
using namespace System::Drawing;
#include "Players.h"
#include "ArrDisco.h"

class CJuego
{
private:
	CArreglo* arrDisco;
	CJugador * Jugador;
	CJugador2 * Jugador2;
	bool barras_p1 = false;
public:
	int Nivel = 1;
	int barra = 0;
	int barras = 190;
	int vida1 = 60;
	int vida2 = 60;
	CJuego()
	{
		arrDisco = new CArreglo();
		Jugador = new CJugador(315, 314, 73, 88.5, 0, 0, "Imagenes\\edinson2.png", 0, 0, 0);
		Jugador2 = new CJugador2(250, 314, 73, 88.5, 0, 0, "Imagenes\\omar.png", 0, 0, 0);
		if (Nivel == 1)
		{
			arrDisco->agregarDisco();
			arrDisco->agregarPersecutor();
			arrDisco->agregarPersecutor2();
		}
		
	}
	~CJuego() {}



	void setbarras_p(bool barras_p1)
	{
		this->barras_p1=barras_p1;
	}

	bool getbarras_p()
	{
		return barras_p1;
	}

	void Bajabarras(bool barras_p1)
	{
		if(barras_p1 == true)
		barras--;
	}

	void superspeed(Graphics^ g) {
		Jugador->dibujar(g);
		Jugador->mover(g);
		Jugador2->dibujar(g);
		Jugador2->mover(g);
		
	}
	void agregar()
	{
		
		arrDisco->agregarDisco();
		arrDisco->agregarPersecutor();
		arrDisco->agregarPersecutor2();
	}
	
	void ProcesarTick(Graphics ^g)
	{
		Random r;
		if (barra <= 790)
			barra = barra + 1;
		if (barra == 790 && arrDisco->contadordisco()>0 && arrDisco->contadorpersecutor1()>0 && arrDisco->contadorpersecutor2()>0) {
			barra = 0;
			arrDisco->borrar();
		}
		if (barra == 790)
		{
			Nivel++;
			barra = 0;
		}
		Bitmap^bmpPersecutor = gcnew Bitmap("Imagenes\\discosinfondo2.png");
		Bitmap^bmpDisco = gcnew Bitmap("Imagenes\\sierrasfinal.png");
		bmpPersecutor->MakeTransparent();
		bmpDisco->MakeTransparent();
		if (vida1 > 0)
		{
			Jugador->dibujar(g);
			Jugador->mover(g);
			arrDisco->dibujarp(g, bmpPersecutor, Jugador->GetPosx(), Jugador->GetPosy());
		}
		if (vida2 > 0)
		{
		Jugador2->dibujar(g);
		Jugador2->mover(g);
		arrDisco->dibujarp2(g, bmpPersecutor, Jugador2->GetPosx(), Jugador2->GetPosy());
		}
		arrDisco->dibujar(g, bmpDisco);
		arrDisco->colision(Jugador->getrectangle1(),vida1);
		arrDisco->colisionp2(Jugador2->getrectangle2() ,vida2);
		if (arrDisco->getcolision1() == true) 
		{
			arrDisco->setcolision1(false);
			vida1 = vida1 -20;
		}
		if (arrDisco->getcolision2() == true)
		{
			arrDisco->setcolision2(false);
			vida2 = vida2 - 20;
		}
		if (vida1 <= 0)
		{
			Jugador->SetPosx(1000);
			Jugador->SetPosy(1000);
			arrDisco->cambiarp1(g, bmpPersecutor, Jugador2->GetPosx(), Jugador2->GetPosy());
		}
		if (vida2 <= 0)
		{
			Jugador2->SetPosx(1000);
			Jugador2->SetPosy(1000);
			arrDisco->cambiarp2(g, bmpPersecutor, Jugador->GetPosx(), Jugador->GetPosy());
		}
		
		g->FillRectangle(Brushes::Blue, Jugador->GetPosx()-15, Jugador->GetPosy() - 20, vida1, 13);
		g->FillRectangle(Brushes::Red, Jugador2->GetPosx()-15, Jugador2->GetPosy() - 20, vida2, 15);
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

	void ProcesarKeyDown2(System::Windows::Forms::Keys e)
	{
		switch (e) {
		case System::Windows::Forms::Keys::A:
			Jugador2->SetDeltax(-1);
			break;
		case System::Windows::Forms::Keys::W:
			Jugador2->SetDeltay(-1);
			break;
		case System::Windows::Forms::Keys::D:
			Jugador2->SetDeltax(1);
			break;
		case System::Windows::Forms::Keys::S:
			Jugador2->SetDeltay(1);
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
	void ProcesarKeyUp2(System::Windows::Forms::Keys e)
	{
		switch (e) {
		case System::Windows::Forms::Keys::A:
			Jugador2->SetDeltax(0);
			break;
		case System::Windows::Forms::Keys::W:
			Jugador2->SetDeltay(0);
			break;
		case System::Windows::Forms::Keys::D:
			Jugador2->SetDeltax(0);
			break;
		case System::Windows::Forms::Keys::S:
			Jugador2->SetDeltay(0);
			break;
		default:
			break;
		}
	}
};



#endif // !__Juego_h__