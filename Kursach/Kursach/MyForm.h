#pragma once
#include "MyGDrive.h"
#include "AddingNewTask.h"
#include "My_List.h"
#include "Exception.h"
#include <locale.h>


namespace Kursach {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;

	private: System::Windows::Forms::ToolStrip^  ToolPanel;
	private: System::Windows::Forms::ToolStripButton^  AddNewTask;
	private: System::Windows::Forms::ToolStripButton^  Move;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton3;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton2;
	private: System::Windows::Forms::DataGridView^  NameList;
	private: System::Windows::Forms::RichTextBox^  Deadline2;

	private: System::Windows::Forms::Label^  Name1;
	private: System::Windows::Forms::RichTextBox^  Date2;

	private: System::Windows::Forms::Label^  Status1;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Name3;
	private: System::Windows::Forms::RichTextBox^  Name2;

	private: System::Windows::Forms::Label^  Date1;



	private: System::Windows::Forms::Label^  Deadline1;
	private: System::Windows::Forms::RichTextBox^  Text2;


	private: System::Windows::Forms::Label^  Text1;
	private: System::Windows::Forms::Button^  Status2;


	private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->ToolPanel = (gcnew System::Windows::Forms::ToolStrip());
			this->AddNewTask = (gcnew System::Windows::Forms::ToolStripButton());
			this->Move = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton3 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->NameList = (gcnew System::Windows::Forms::DataGridView());
			this->Name3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Deadline2 = (gcnew System::Windows::Forms::RichTextBox());
			this->Name1 = (gcnew System::Windows::Forms::Label());
			this->Date2 = (gcnew System::Windows::Forms::RichTextBox());
			this->Status1 = (gcnew System::Windows::Forms::Label());
			this->Name2 = (gcnew System::Windows::Forms::RichTextBox());
			this->Date1 = (gcnew System::Windows::Forms::Label());
			this->Deadline1 = (gcnew System::Windows::Forms::Label());
			this->Text2 = (gcnew System::Windows::Forms::RichTextBox());
			this->Text1 = (gcnew System::Windows::Forms::Label());
			this->Status2 = (gcnew System::Windows::Forms::Button());
			this->ToolPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NameList))->BeginInit();
			this->SuspendLayout();
			// 
			// ToolPanel
			// 
			this->ToolPanel->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->AddNewTask, this->Move,
					this->toolStripButton3, this->toolStripButton1, this->toolStripButton2
			});
			this->ToolPanel->Location = System::Drawing::Point(0, 0);
			this->ToolPanel->Name = L"ToolPanel";
			this->ToolPanel->Size = System::Drawing::Size(807, 25);
			this->ToolPanel->TabIndex = 1;
			this->ToolPanel->Text = L"toolStrip1";
			// 
			// AddNewTask
			// 
			this->AddNewTask->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->AddNewTask->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"AddNewTask.Image")));
			this->AddNewTask->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->AddNewTask->Name = L"AddNewTask";
			this->AddNewTask->Size = System::Drawing::Size(118, 22);
			this->AddNewTask->Text = L"Добавити Завдання";
			this->AddNewTask->Click += gcnew System::EventHandler(this, &MyForm::NewTask);
			// 
			// Move
			// 
			this->Move->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->Move->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Move.Image")));
			this->Move->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Move->Name = L"Move";
			this->Move->Size = System::Drawing::Size(110, 22);
			this->Move->Text = L"Поточні Завдання";
			this->Move->Click += gcnew System::EventHandler(this, &MyForm::Moving);
			// 
			// toolStripButton3
			// 
			this->toolStripButton3->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton3.Image")));
			this->toolStripButton3->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton3->Name = L"toolStripButton3";
			this->toolStripButton3->Size = System::Drawing::Size(115, 22);
			this->toolStripButton3->Text = L"Виконані Завдання";
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(81, 22);
			this->toolStripButton1->Text = L"Всі Завдання";
			// 
			// toolStripButton2
			// 
			this->toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton2.Image")));
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->Size = System::Drawing::Size(108, 22);
			this->toolStripButton2->Text = L"Сортувати по даті";
			// 
			// NameList
			// 
			this->NameList->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->NameList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Name3 });
			this->NameList->Location = System::Drawing::Point(12, 28);
			this->NameList->Name = L"NameList";
			this->NameList->RowHeadersWidth = 30;
			this->NameList->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->NameList->Size = System::Drawing::Size(158, 368);
			this->NameList->TabIndex = 2;
			this->NameList->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::Showing);
			// 
			// Name3
			// 
			this->Name3->HeaderText = L"Назва";
			this->Name3->Name = L"Name3";
			this->Name3->ReadOnly = true;
			this->Name3->Width = 125;
			// 
			// Deadline2
			// 
			this->Deadline2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Deadline2->Location = System::Drawing::Point(510, 54);
			this->Deadline2->Name = L"Deadline2";
			this->Deadline2->Size = System::Drawing::Size(138, 25);
			this->Deadline2->TabIndex = 3;
			this->Deadline2->Text = L"";
			// 
			// Name1
			// 
			this->Name1->AutoSize = true;
			this->Name1->Location = System::Drawing::Point(219, 38);
			this->Name1->Name = L"Name1";
			this->Name1->Size = System::Drawing::Size(39, 13);
			this->Name1->TabIndex = 4;
			this->Name1->Text = L"Назва";
			// 
			// Date2
			// 
			this->Date2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Date2->Location = System::Drawing::Point(366, 54);
			this->Date2->Name = L"Date2";
			this->Date2->Size = System::Drawing::Size(138, 25);
			this->Date2->TabIndex = 5;
			this->Date2->Text = L"";
			// 
			// Status1
			// 
			this->Status1->AutoSize = true;
			this->Status1->Location = System::Drawing::Point(651, 38);
			this->Status1->Name = L"Status1";
			this->Status1->Size = System::Drawing::Size(41, 13);
			this->Status1->TabIndex = 6;
			this->Status1->Text = L"Статус";
			// 
			// Name2
			// 
			this->Name2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Name2->Location = System::Drawing::Point(222, 54);
			this->Name2->Name = L"Name2";
			this->Name2->Size = System::Drawing::Size(138, 25);
			this->Name2->TabIndex = 7;
			this->Name2->Text = L"";
			// 
			// Date1
			// 
			this->Date1->AutoSize = true;
			this->Date1->Location = System::Drawing::Point(363, 38);
			this->Date1->Name = L"Date1";
			this->Date1->Size = System::Drawing::Size(89, 13);
			this->Date1->TabIndex = 8;
			this->Date1->Text = L"Дата створення";
			// 
			// Deadline1
			// 
			this->Deadline1->AutoSize = true;
			this->Deadline1->Location = System::Drawing::Point(510, 38);
			this->Deadline1->Name = L"Deadline1";
			this->Deadline1->Size = System::Drawing::Size(52, 13);
			this->Deadline1->TabIndex = 10;
			this->Deadline1->Text = L"Дедлайн";
			// 
			// Text2
			// 
			this->Text2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Text2->Location = System::Drawing::Point(222, 124);
			this->Text2->Name = L"Text2";
			this->Text2->Size = System::Drawing::Size(570, 272);
			this->Text2->TabIndex = 11;
			this->Text2->Text = L"";
			// 
			// Text1
			// 
			this->Text1->AutoSize = true;
			this->Text1->Location = System::Drawing::Point(222, 105);
			this->Text1->Name = L"Text1";
			this->Text1->Size = System::Drawing::Size(37, 13);
			this->Text1->TabIndex = 12;
			this->Text1->Text = L"Текст";
			// 
			// Status2
			// 
			this->Status2->BackColor = System::Drawing::Color::White;
			this->Status2->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->Status2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Status2->Location = System::Drawing::Point(654, 54);
			this->Status2->Name = L"Status2";
			this->Status2->Size = System::Drawing::Size(138, 25);
			this->Status2->TabIndex = 13;
			this->Status2->Text = L"Статус";
			this->Status2->UseVisualStyleBackColor = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(807, 412);
			this->Controls->Add(this->Status2);
			this->Controls->Add(this->Text1);
			this->Controls->Add(this->Text2);
			this->Controls->Add(this->Deadline1);
			this->Controls->Add(this->Date1);
			this->Controls->Add(this->Name2);
			this->Controls->Add(this->Status1);
			this->Controls->Add(this->Date2);
			this->Controls->Add(this->Name1);
			this->Controls->Add(this->Deadline2);
			this->Controls->Add(this->NameList);
			this->Controls->Add(this->ToolPanel);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Click += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ToolPanel->ResumeLayout(false);
			this->ToolPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NameList))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		My_List list;
		STime s = { 2016,12,30,16,12 };
		CObj a1("qwe1", "QWERTY1", s, '0');
		CObj a2("qwe2", "QWERTY2", s, '0');
		CObj a3("qwe3", "QWERTY3", s, '0');
		CObj a4("qwe4", "QWERTY4", s, '1');
		CObj a5("qwe5", "QWERTY5", s, '1');
		list.add_obj(a1);
		list.add_obj(a2);
		list.add_obj(a3);
		list.add_obj(a4);
		//list.add_obj(a5);
		//list.read_from_file();
		list.show(NameList);
		list.write_to_file();
	}
private: System::Void NewTask(System::Object^  sender, System::EventArgs^  e) {
	Kursach::AddingNewTask form1;
	form1.ShowDialog();
}
private: System::Void Moving(System::Object^  sender, System::EventArgs^  e) {
	
}
private: System::Void Showing(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	My_List list;
	list.read_from_file();
	int t = Convert::ToInt32(NameList->CurrentRow->Index);
	list.showOne(Name2, Date2, Deadline2, Text2, Status2, t);
}
};
}
