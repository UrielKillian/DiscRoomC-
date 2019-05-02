#pragma once
#include "JuegoSoloBruno.h"
namespace FINALRemastered {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de JuegoBruno
	/// </summary>
	public ref class JuegoBruno : public System::Windows::Forms::Form
	{
	private:
		CJuego2 *objJuego;
		Bitmap^bmpMapa = gcnew Bitmap("Imagenes\\mapa1.png");
		Bitmap^bmpPersecutor = gcnew Bitmap("Imagenes\\discosinfondo2.png");
	private: System::Windows::Forms::Timer^  timer1;
			 Bitmap^bmpDisco = gcnew Bitmap("Imagenes\\sierrasfinal.png");
	public:
		JuegoBruno(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			objJuego = new CJuego2();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~JuegoBruno()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 5;
			this->timer1->Tick += gcnew System::EventHandler(this, &JuegoBruno::timer1_Tick);
			// 
			// JuegoBruno
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(981, 953);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"JuegoBruno";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"JuegoBruno";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &JuegoBruno::JuegoBruno_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &JuegoBruno::JuegoBruno_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		Graphics^g = this->CreateGraphics();
		BufferedGraphicsContext^espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^buffer = espacio->Allocate(g, this->ClientRectangle);
		buffer->Graphics->DrawImage(bmpMapa, 0, 0, this->Width, this->Height);
		objJuego->ProcesarTick(buffer->Graphics);
		buffer->Render(g);
		g->FillRectangle(Brushes::Black, 30, 10, 800, 50);
		g->FillRectangle(Brushes::Red, 35, 15, objJuego->barra, 40);
		g->FillRectangle(Brushes::Black, 30, 900, 200, 50);
		g->FillRectangle(Brushes::SkyBlue, 35, 905, objJuego->barras, 40);
		if (objJuego->vida2 <= 0)this->Close();
		if (objJuego->Nivel == 2)bmpMapa = gcnew Bitmap("Imagenes\\mapa2.png");
		if (objJuego->Nivel == 3)bmpMapa = gcnew Bitmap("Imagenes\\mapa3.png");
		if (objJuego->Nivel == 4)bmpMapa = gcnew Bitmap("Imagenes\\mapa5.1.png");
		if (objJuego->Nivel == 5)bmpMapa = gcnew Bitmap("Imagenes\\fondito3.jpg");
		if (objJuego->Nivel == 6) {
			this->Close();
		}

		delete buffer, espacio, g;
	}
	private: System::Void JuegoBruno_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		Graphics^g = this->CreateGraphics();
		BufferedGraphicsContext^espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^buffer = espacio->Allocate(g, this->ClientRectangle);
		objJuego->ProcesarKeyDown2(e->KeyCode);
		switch (e->KeyCode)
		{
		case Keys::D1:
			objJuego->Nivel = 1;
			objJuego->barra = 0;
			break;
		case Keys::D2:
			objJuego->Nivel = 2;
			objJuego->barra = 0;
			break;
		case Keys::D3:
			objJuego->Nivel = 3;
			objJuego->barra = 0;
			break;
		case Keys::D4:
			objJuego->Nivel = 4;
			objJuego->barra = 0;
			break;
		case Keys::D5:
			objJuego->Nivel = 5;
			objJuego->barra = 0;
			break;
		case Keys::Space:
			objJuego->sombras(g);
			break;
		case Keys::C:
			if (objJuego->barras > 0)
			{
				objJuego->setbarras_p(true);
				this->timer1->Interval = 100;
			}
			break;
		case Keys::NumPad1:
			objJuego->vida2 = 20;
			break;
		case Keys::NumPad2:
			objJuego->vida2 = 40;
			break;
		case Keys::NumPad3:
			objJuego->vida2 = 60;
			break;
		default:
			break;
		}
	}
	private: System::Void JuegoBruno_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		Graphics^g = this->CreateGraphics();
		BufferedGraphicsContext^espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^buffer = espacio->Allocate(g, this->ClientRectangle);
		objJuego->ProcesarKeyUp2(e->KeyCode);
		switch (e->KeyCode)
		{
		case Keys::Space:
			objJuego->sombras(g);
			break;
		case Keys::C:
			objJuego->setbarras_p(false);
			this->timer1->Interval = 5;
		default:
			break;
		}
	}
};
}
