#pragma once
#include "MyGDrive.h"
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
	private: System::Windows::Forms::DataGridView^  Table_intime;






	private: System::Windows::Forms::DataGridView^  Table_outtime;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Name1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Date1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Deadline1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Description1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Text1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Name2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Date2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Deadline;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Description2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Text2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;







	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Table_intime = (gcnew System::Windows::Forms::DataGridView());
			this->Name1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Date1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Deadline1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Description1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Text1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Table_outtime = (gcnew System::Windows::Forms::DataGridView());
			this->Name2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Date2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Deadline = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Description2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Text2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table_intime))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table_outtime))->BeginInit();
			this->SuspendLayout();
			// 
			// Table_intime
			// 
			this->Table_intime->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Table_intime->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Name1, this->Date1,
					this->Deadline1, this->Description1, this->Text1
			});
			this->Table_intime->GridColor = System::Drawing::SystemColors::AppWorkspace;
			this->Table_intime->Location = System::Drawing::Point(154, 47);
			this->Table_intime->Name = L"Table_intime";
			this->Table_intime->ReadOnly = true;
			this->Table_intime->Size = System::Drawing::Size(588, 150);
			this->Table_intime->TabIndex = 0;
			// 
			// Name1
			// 
			this->Name1->HeaderText = L"І\'мя";
			this->Name1->Name = L"Name1";
			this->Name1->ReadOnly = true;
			// 
			// Date1
			// 
			this->Date1->HeaderText = L"Дата";
			this->Date1->Name = L"Date1";
			this->Date1->ReadOnly = true;
			this->Date1->Width = 120;
			// 
			// Deadline1
			// 
			this->Deadline1->HeaderText = L"дедлайн";
			this->Deadline1->Name = L"Deadline1";
			this->Deadline1->ReadOnly = true;
			this->Deadline1->Width = 120;
			// 
			// Description1
			// 
			this->Description1->HeaderText = L"Опис";
			this->Description1->Name = L"Description1";
			this->Description1->ReadOnly = true;
			// 
			// Text1
			// 
			this->Text1->HeaderText = L"Текст";
			this->Text1->Name = L"Text1";
			this->Text1->ReadOnly = true;
			// 
			// Table_outtime
			// 
			this->Table_outtime->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Table_outtime->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Name2,
					this->Date2, this->Deadline, this->Description2, this->Text2
			});
			this->Table_outtime->Location = System::Drawing::Point(154, 248);
			this->Table_outtime->Name = L"Table_outtime";
			this->Table_outtime->Size = System::Drawing::Size(588, 150);
			this->Table_outtime->TabIndex = 1;
			// 
			// Name2
			// 
			this->Name2->HeaderText = L"І\'мя";
			this->Name2->Name = L"Name2";
			this->Name2->ReadOnly = true;
			// 
			// Date2
			// 
			this->Date2->HeaderText = L"Дата";
			this->Date2->Name = L"Date2";
			this->Date2->ReadOnly = true;
			this->Date2->Width = 120;
			// 
			// Deadline
			// 
			this->Deadline->HeaderText = L"дедлайн";
			this->Deadline->Name = L"Deadline";
			this->Deadline->ReadOnly = true;
			this->Deadline->Width = 120;
			// 
			// Description2
			// 
			this->Description2->HeaderText = L"Опис";
			this->Description2->Name = L"Description2";
			this->Description2->ReadOnly = true;
			// 
			// Text2
			// 
			this->Text2->HeaderText = L"Текст";
			this->Text2->Name = L"Text2";
			this->Text2->ReadOnly = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(154, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(71, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Активні події";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(154, 229);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Виконані події";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(800, 600);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Table_outtime);
			this->Controls->Add(this->Table_intime);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table_intime))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table_outtime))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		/*MyGDrive gdrive1;
		gdrive1.DownloadDatabase();*/
		My_List list;
		/*list.read_from_file();*/
		STime s{ 2016, 12, 28, 12, 16, 0 };
		CObj a("qwe1", "qwerty", "QWERTY", s, '0');
		CObj с("qwe2", "qwerty1", "QWERTY", s, '0');
		CObj b("qwe3", "qwerty", "QWERTY", s, '0');
		CObj d("qwe4", "qwerty", "QWERTY", s, '1');
		list.add_obj(b);
		list.add_obj(a);
		list.add_obj(с);
		list.add_obj(d);
		list.show(Table_intime,Table_outtime);
	}
};
}
