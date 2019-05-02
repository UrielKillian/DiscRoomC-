#ifndef __ARREGLO_H__
#define __ARREGLO_H__
#include "Disco.h"
#include <vector>
using namespace std;
class CArreglo
{
public:
	CArreglo() {
		arregloDisco = vector<CDisco*>();
		arregloPersecutor = vector<CPersecutor*>();
		arregloPersecutor2 = vector<CPersecutor2*>();
	}
	~CArreglo() {}
	void agregarDisco()
	{
		CDisco *oDisco = new CDisco();
		arregloDisco.push_back(oDisco);
	}
	void agregarPersecutor()
	{
		CPersecutor *oPersecutor = new CPersecutor();
		arregloPersecutor.push_back(oPersecutor);
	}
	void agregarPersecutor2()
	{
		CPersecutor2 *oPersecutor2 = new CPersecutor2();
		arregloPersecutor2.push_back(oPersecutor2);
	}

	void dibujar(Graphics^g, Bitmap^bmpDisco) {
		for (int i = 0; i < arregloDisco.size(); i++)
		{
			arregloDisco.at(i)->dibujar(g, bmpDisco);
			if (arregloDisco.size() == 5)
				break;
		}
	}
	void dibujarp(Graphics^g, Bitmap^bmpPersecutor, int px, int py)
	{
		for (int i = 0; i < arregloPersecutor.size(); i++)
		{
			arregloPersecutor.at(i)->dibujar(g, bmpPersecutor, px, py);
		}
	}
	void dibujarp2(Graphics^g, Bitmap^bmpPersecutor, int px, int py)
	{
		for (int i = 0; i < arregloPersecutor2.size(); i++)
		{
			arregloPersecutor2.at(i)->dibujar(g, bmpPersecutor, px, py);
		}
	}
	
	void borrar()
	{
		for (int i = 0; i < arregloDisco.size(); i++)arregloDisco.erase(arregloDisco.begin()+i);
		for (int i = 0; i < arregloPersecutor.size(); i++)arregloPersecutor.erase(arregloPersecutor.begin() + i);
		for (int i = 0; i < arregloPersecutor2.size(); i++)arregloPersecutor2.erase(arregloPersecutor2.begin() + i);
	}
	int contadordisco()
	{
		return arregloDisco.size();
	}
	int contadorpersecutor1()
	{
		return arregloPersecutor.size();
	}
	int contadorpersecutor2()
	{
		return arregloPersecutor2.size();
	}
	//void borrarpersecutor()
	//{
	//	arregloPersecutor.erase(arregloPersecutor.begin() + i);
	//}

	void cambiarp1(Graphics^g, Bitmap^bmpPersecutor, int px, int py)
	{
		for (int i = 0; i < arregloPersecutor.size(); i++)
		{
			arregloPersecutor.at(i)->dibujar(g, bmpPersecutor, px, py);
		}
	}
	void cambiarp2(Graphics^g, Bitmap^bmpPersecutor, int px, int py)
	{
		for (int i = 0; i < arregloPersecutor.size(); i++)
		{
			arregloPersecutor.at(i)->dibujar(g, bmpPersecutor, px, py);
		}
	}

	/*void borrarpersecutor2()
	{
		arregloPersecutor2.erase();
	}
*/
	void colision(Rectangle r, int vida)
	{
		for (int i = 0; i < arregloDisco.size(); i++)
		{
			if (arregloDisco.at(i)->getRectangulo().IntersectsWith(r))//Jugador1
			{
				colision1 = true;
				arregloDisco.erase(arregloDisco.begin() + i);
				
			}
		}
		for (int i = 0; i < arregloPersecutor.size(); i++)//Jugador1
		{
			if (arregloPersecutor.at(i)->getRectangulo().IntersectsWith(r))
			{
				colision1 = true;
				arregloPersecutor.erase(arregloPersecutor.begin() + i);
				

			}
		}
		for (int i = 0; i < arregloPersecutor2.size(); i++)//Jugador1
		{
			if (arregloPersecutor2.at(i)->getRectangulo().IntersectsWith(r))
			{
				colision1 = true;
				arregloPersecutor2.erase(arregloPersecutor2.begin() + i);
			}
		}
	}

	void colisionp2(Rectangle r2, int vida)
	{
		for (int i = 0; i < arregloDisco.size(); i++)
		{
			if (arregloDisco.at(i)->getRectangulo().IntersectsWith(r2))//Jugador2
			{
				colision2 = true;
				arregloDisco.erase(arregloDisco.begin() + i);


			}
		}
		for (int i = 0; i < arregloPersecutor2.size(); i++)//Jugador2
		{
			if (arregloPersecutor2.at(i)->getRectangulo().IntersectsWith(r2))
			{
				colision2 = true;
				arregloPersecutor2.erase(arregloPersecutor2.begin() + i);


			}
		}
		for (int i = 0; i < arregloPersecutor.size(); i++)//Jugador2
		{
			if (arregloPersecutor.at(i)->getRectangulo().IntersectsWith(r2))
			{
				colision2 = true;

				arregloPersecutor.erase(arregloPersecutor.begin() + i);
			}
		}
	}
	bool getcolision1()
	{
		return colision1;
	}
	bool getcolision2()
	{
		return colision2;
	}
	void setcolision1(bool colision1)
	{
		this->colision1 = colision1;
	}
	void setcolision2(bool colision2)
	{
		this->colision2 = colision2;
	}
private:
	vector<CDisco*>arregloDisco;
	vector<CPersecutor*>arregloPersecutor;
	vector<CPersecutor2*>arregloPersecutor2;
	bool colision1 = false;
	bool colision2 = false;
};

#endif // !__ARREGLO_H__
