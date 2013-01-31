#pragma once

#include "StringHelper.h"
#include "Octree.h"
#include "Assimp.h"
#include "OpenGL.h"

namespace SDF {

	using namespace System;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace OpenGLForm;
	using namespace AssimpFileHandler;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			Assimp = new CAssimp();
			InitializeComponent();
			OpenGL = gcnew COpenGL(this->panel1, Assimp);

			this->timer1->Enabled = true;
			Assimp->logInfo("Form Fully Loaded");
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
				delete OpenGL;
				delete Assimp;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		CAssimp* Assimp;
		COpenGL^ OpenGL;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  souborToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  nov�ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  otev��tToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator;
	private: System::Windows::Forms::ToolStripMenuItem^  ulo�itToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ulo�itjakoToolStripMenuItem;



	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
	private: System::Windows::Forms::ToolStripMenuItem^  ukon�itToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  upravitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  zp�tToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  znovuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator3;
	private: System::Windows::Forms::ToolStripMenuItem^  vyjmoutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  kop�rovatToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  vlo�itToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator4;
	private: System::Windows::Forms::ToolStripMenuItem^  vybratv�eToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  n�strojeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  p�izp�sobitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  mo�nostiToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  n�pov�daToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  obsahToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  indexToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  hledatToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator5;
	private: System::Windows::Forms::ToolStripMenuItem^  oproduktuToolStripMenuItem;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::ComponentModel::IContainer^  components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->souborToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->nov�ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->otev��tToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->ulo�itToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ulo�itjakoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->ukon�itToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->upravitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zp�tToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->znovuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->vyjmoutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->kop�rovatToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->vlo�itToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator4 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->vybratv�eToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->n�strojeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->p�izp�sobitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mo�nostiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->n�pov�daToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->obsahToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->indexToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->hledatToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator5 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->oproduktuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->souborToolStripMenuItem, 
				this->upravitToolStripMenuItem, this->n�strojeToolStripMenuItem, this->n�pov�daToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(784, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// souborToolStripMenuItem
			// 
			this->souborToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {this->nov�ToolStripMenuItem, 
				this->otev��tToolStripMenuItem, this->toolStripSeparator, this->ulo�itToolStripMenuItem, this->ulo�itjakoToolStripMenuItem, this->toolStripSeparator2, 
				this->ukon�itToolStripMenuItem});
			this->souborToolStripMenuItem->Name = L"souborToolStripMenuItem";
			this->souborToolStripMenuItem->Size = System::Drawing::Size(57, 20);
			this->souborToolStripMenuItem->Text = L"&Soubor";
			// 
			// nov�ToolStripMenuItem
			// 
			this->nov�ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"nov�ToolStripMenuItem.Image")));
			this->nov�ToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->nov�ToolStripMenuItem->Name = L"nov�ToolStripMenuItem";
			this->nov�ToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
			this->nov�ToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->nov�ToolStripMenuItem->Text = L"&Nov�";
			// 
			// otev��tToolStripMenuItem
			// 
			this->otev��tToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"otev��tToolStripMenuItem.Image")));
			this->otev��tToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->otev��tToolStripMenuItem->Name = L"otev��tToolStripMenuItem";
			this->otev��tToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->otev��tToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->otev��tToolStripMenuItem->Text = L"&Otev��t";
			this->otev��tToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::otev��tToolStripMenuItem_Click);
			// 
			// toolStripSeparator
			// 
			this->toolStripSeparator->Name = L"toolStripSeparator";
			this->toolStripSeparator->Size = System::Drawing::Size(150, 6);
			// 
			// ulo�itToolStripMenuItem
			// 
			this->ulo�itToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"ulo�itToolStripMenuItem.Image")));
			this->ulo�itToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->ulo�itToolStripMenuItem->Name = L"ulo�itToolStripMenuItem";
			this->ulo�itToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->ulo�itToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->ulo�itToolStripMenuItem->Text = L"&Ulo�it";
			// 
			// ulo�itjakoToolStripMenuItem
			// 
			this->ulo�itjakoToolStripMenuItem->Name = L"ulo�itjakoToolStripMenuItem";
			this->ulo�itjakoToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->ulo�itjakoToolStripMenuItem->Text = L"Ulo�it j&ako";
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(150, 6);
			// 
			// ukon�itToolStripMenuItem
			// 
			this->ukon�itToolStripMenuItem->Name = L"ukon�itToolStripMenuItem";
			this->ukon�itToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->ukon�itToolStripMenuItem->Text = L"U&kon�it";
			this->ukon�itToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::ukon�itToolStripMenuItem_Click);
			// 
			// upravitToolStripMenuItem
			// 
			this->upravitToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {this->zp�tToolStripMenuItem, 
				this->znovuToolStripMenuItem, this->toolStripSeparator3, this->vyjmoutToolStripMenuItem, this->kop�rovatToolStripMenuItem, this->vlo�itToolStripMenuItem, 
				this->toolStripSeparator4, this->vybratv�eToolStripMenuItem});
			this->upravitToolStripMenuItem->Name = L"upravitToolStripMenuItem";
			this->upravitToolStripMenuItem->Size = System::Drawing::Size(57, 20);
			this->upravitToolStripMenuItem->Text = L"&Upravit";
			// 
			// zp�tToolStripMenuItem
			// 
			this->zp�tToolStripMenuItem->Name = L"zp�tToolStripMenuItem";
			this->zp�tToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Z));
			this->zp�tToolStripMenuItem->Size = System::Drawing::Size(167, 22);
			this->zp�tToolStripMenuItem->Text = L"&Zp�t";
			// 
			// znovuToolStripMenuItem
			// 
			this->znovuToolStripMenuItem->Name = L"znovuToolStripMenuItem";
			this->znovuToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Y));
			this->znovuToolStripMenuItem->Size = System::Drawing::Size(167, 22);
			this->znovuToolStripMenuItem->Text = L"&Znovu";
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(164, 6);
			// 
			// vyjmoutToolStripMenuItem
			// 
			this->vyjmoutToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"vyjmoutToolStripMenuItem.Image")));
			this->vyjmoutToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->vyjmoutToolStripMenuItem->Name = L"vyjmoutToolStripMenuItem";
			this->vyjmoutToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::X));
			this->vyjmoutToolStripMenuItem->Size = System::Drawing::Size(167, 22);
			this->vyjmoutToolStripMenuItem->Text = L"&Vyjmout";
			// 
			// kop�rovatToolStripMenuItem
			// 
			this->kop�rovatToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"kop�rovatToolStripMenuItem.Image")));
			this->kop�rovatToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->kop�rovatToolStripMenuItem->Name = L"kop�rovatToolStripMenuItem";
			this->kop�rovatToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C));
			this->kop�rovatToolStripMenuItem->Size = System::Drawing::Size(167, 22);
			this->kop�rovatToolStripMenuItem->Text = L"&Kop�rovat";
			// 
			// vlo�itToolStripMenuItem
			// 
			this->vlo�itToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"vlo�itToolStripMenuItem.Image")));
			this->vlo�itToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->vlo�itToolStripMenuItem->Name = L"vlo�itToolStripMenuItem";
			this->vlo�itToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::V));
			this->vlo�itToolStripMenuItem->Size = System::Drawing::Size(167, 22);
			this->vlo�itToolStripMenuItem->Text = L"&Vlo�it";
			// 
			// toolStripSeparator4
			// 
			this->toolStripSeparator4->Name = L"toolStripSeparator4";
			this->toolStripSeparator4->Size = System::Drawing::Size(164, 6);
			// 
			// vybratv�eToolStripMenuItem
			// 
			this->vybratv�eToolStripMenuItem->Name = L"vybratv�eToolStripMenuItem";
			this->vybratv�eToolStripMenuItem->Size = System::Drawing::Size(167, 22);
			this->vybratv�eToolStripMenuItem->Text = L"&Vybrat v�e";
			// 
			// n�strojeToolStripMenuItem
			// 
			this->n�strojeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->p�izp�sobitToolStripMenuItem, 
				this->mo�nostiToolStripMenuItem});
			this->n�strojeToolStripMenuItem->Name = L"n�strojeToolStripMenuItem";
			this->n�strojeToolStripMenuItem->Size = System::Drawing::Size(63, 20);
			this->n�strojeToolStripMenuItem->Text = L"&N�stroje";
			// 
			// p�izp�sobitToolStripMenuItem
			// 
			this->p�izp�sobitToolStripMenuItem->Name = L"p�izp�sobitToolStripMenuItem";
			this->p�izp�sobitToolStripMenuItem->Size = System::Drawing::Size(133, 22);
			this->p�izp�sobitToolStripMenuItem->Text = L"&P�izp�sobit";
			// 
			// mo�nostiToolStripMenuItem
			// 
			this->mo�nostiToolStripMenuItem->Name = L"mo�nostiToolStripMenuItem";
			this->mo�nostiToolStripMenuItem->Size = System::Drawing::Size(133, 22);
			this->mo�nostiToolStripMenuItem->Text = L"&Mo�nosti";
			// 
			// n�pov�daToolStripMenuItem
			// 
			this->n�pov�daToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->obsahToolStripMenuItem, 
				this->indexToolStripMenuItem, this->hledatToolStripMenuItem, this->toolStripSeparator5, this->oproduktuToolStripMenuItem});
			this->n�pov�daToolStripMenuItem->Name = L"n�pov�daToolStripMenuItem";
			this->n�pov�daToolStripMenuItem->Size = System::Drawing::Size(73, 20);
			this->n�pov�daToolStripMenuItem->Text = L"&N�pov�da";
			// 
			// obsahToolStripMenuItem
			// 
			this->obsahToolStripMenuItem->Name = L"obsahToolStripMenuItem";
			this->obsahToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->obsahToolStripMenuItem->Text = L"&Obsah";
			// 
			// indexToolStripMenuItem
			// 
			this->indexToolStripMenuItem->Name = L"indexToolStripMenuItem";
			this->indexToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->indexToolStripMenuItem->Text = L"&Index";
			// 
			// hledatToolStripMenuItem
			// 
			this->hledatToolStripMenuItem->Name = L"hledatToolStripMenuItem";
			this->hledatToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->hledatToolStripMenuItem->Text = L"&Hledat";
			// 
			// toolStripSeparator5
			// 
			this->toolStripSeparator5->Name = L"toolStripSeparator5";
			this->toolStripSeparator5->Size = System::Drawing::Size(141, 6);
			// 
			// oproduktuToolStripMenuItem
			// 
			this->oproduktuToolStripMenuItem->Name = L"oproduktuToolStripMenuItem";
			this->oproduktuToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->oproduktuToolStripMenuItem->Text = L"&O produktu...";
			// 
			// timer1
			// 
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel1->Location = System::Drawing::Point(0, 27);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(784, 535);
			this->panel1->TabIndex = 1;
			this->panel1->Resize += gcnew System::EventHandler(this, &Form1::panel1_Resize);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 562);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Shape Diameter Function";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

#pragma region Extra Functions

	private: System::Void SetOpenGLSize(int width, int height)
	{
		if(width<1) width = 1;
		if(height<1) height = 1;
		OpenGL->ResizeOpengl(width, height);
	}
	protected: virtual void Form1::WndProc(System::Windows::Forms::Message %m) override  
	{        
		if(m.Msg == WM_MOUSEWHEEL)  
		{
			OpenGL->WndProc(m);
		}
		System::Windows::Forms::Form::WndProc(m);  
	}

#pragma endregion

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		//timer
		OpenGL->Render();
		OpenGL->SwapOpenGLBuffers();
	}
	private: System::Void panel1_Resize(System::Object^  sender, System::EventArgs^  e)
	{
		if(this->timer1->Enabled == false)
			return;
		Control^ control = dynamic_cast<Control^>(sender);
		SetOpenGLSize(control->Size.Width, control->Size.Height);
	}
	private: System::Void otev��tToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		// Displays an OpenFileDialog so the user can select a model.
		OpenFileDialog ^openFileDialog1 = gcnew OpenFileDialog();
		openFileDialog1->Filter = "3D Model Files(*.OBJ)|*.OBJ|All files (*.*)|*.*";
		openFileDialog1->Title = "Select Model";

		// Show the Dialog.
		// If the user clicked OK in the dialog and
		// a .xml file was selected, open it.
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			//OpenGL->SetFileName(openFileDialog1->FileName);
			//OpenGL->LoadFromFile();
			//this->Text = gcnew System::String(OpenGL->GetPanoName().c_str());
			Assimp->logInfo("File: "+ MarshalString(openFileDialog1->FileName) + " Loaded");
		}
	}
	private: System::Void ukon�itToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Application::Exit();
	}
};
}

