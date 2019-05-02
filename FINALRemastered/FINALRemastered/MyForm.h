#pragma once
#include "JuegoMultiplayer.h"
namespace FINALRemastered {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		int cont;
		int tiempo;
	public:
		Bitmap^bmpMapa = gcnew Bitmap("Imagenes\\fondito3.jpg");
	private: System::Windows::Forms::Timer^  timer1;
	public:
		CArreglo *oArreglo;
		CJuego * oJuego;

	public:
		
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			oJuego = new CJuego();
			oArreglo = new CArreglo();	
			
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
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
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(981, 953);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		Graphics^g = this->CreateGraphics();
		BufferedGraphicsContext^espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^buffer = espacio->Allocate(g, this->ClientRectangle);
		buffer->Graphics->DrawImage(bmpMapa, 0, 0, this->Width, this->Height);
		oJuego->ProcesarTick(buffer->Graphics);
		buffer->Render(g);
		g->FillRectangle(Brushes::Black, 30, 10, 800, 50);
		g->FillRectangle(Brushes::Red, 35, 15, oJuego->barra, 40);
		g->FillRectangle(Brushes::Black, 30, 900, 200, 50);
		g->FillRectangle(Brushes::SkyBlue, 35, 905, oJuego->barras, 40);
		if (oJuego->vida1 <= 0 && oJuego->vida2 <= 0)this->Close();
		if (oJuego->Nivel == 1)bmpMapa = gcnew Bitmap("Imagenes\\fondito3.jpg");
		if (oJuego->Nivel == 2)bmpMapa = gcnew Bitmap("Imagenes\\mapa2.png");
		if (oJuego->Nivel == 3)bmpMapa = gcnew Bitmap("Imagenes\\fondito2.jpg");
		if (oJuego->Nivel == 4)bmpMapa = gcnew Bitmap("Imagenes\\fondito4.jpg");
		if (oJuego->Nivel == 5)bmpMapa = gcnew Bitmap("Imagenes\\mapa3.png");
		if (oJuego->Nivel == 6) {
			this->Close();
		}
	
		delete buffer, espacio, g;
	}
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		Graphics^g = this->CreateGraphics();
		BufferedGraphicsContext^espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^buffer = espacio->Allocate(g, this->ClientRectangle);
		oJuego->ProcesarKeyDown(e->KeyCode);
		oJuego->ProcesarKeyDown2(e->KeyCode);
		switch (e->KeyCode)
		{
		case Keys::D1:
			oJuego->Nivel = 1;
			oJuego->barra = 0;
			break;
		case Keys::D2:
			oJuego->Nivel = 2;
			oJuego->barra = 0;
			break;
		case Keys::D3:
			oJuego->Nivel = 3;
			oJuego->barra = 0;
			break;
		case Keys::D4:
			oJuego->Nivel = 4;
			oJuego->barra = 0;
			break;
		case Keys::D5:
			oJuego->Nivel = 5;
			oJuego->barra = 0;
			break;
		case Keys::Space:
			oJuego->superspeed(g);
			break;
		case Keys::C:
			if (oJuego->barras > 0)
			{
				oJuego->setbarras_p(true);
				this->timer1->Interval = 100;
			}
			break;
		case Keys::NumPad1:
			oJuego->vida1 = 20;
			oJuego->vida2 = 20;
			break;
		case Keys::NumPad2:
			oJuego->vida1 = 40;
			oJuego->vida2 = 40;
			break;
		case Keys::NumPad3:
			oJuego->vida2 = 60;
			oJuego->vida1 = 60;
			break;

		default:
			break;
		}
		

	}
	private: System::Void MyForm_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		Graphics^g = this->CreateGraphics();
		BufferedGraphicsContext^espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^buffer = espacio->Allocate(g, this->ClientRectangle);
		oJuego->ProcesarKeyUp(e->KeyCode);
		oJuego->ProcesarKeyUp2(e->KeyCode);
		switch (e->KeyCode)
		{
		case Keys::Space:
			oJuego->superspeed(g);
			break;
		case Keys::C:
			oJuego->setbarras_p(false);
			this->timer1->Interval = 5;
		default:
			break;
		}
		
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		
		
	}

};
}
