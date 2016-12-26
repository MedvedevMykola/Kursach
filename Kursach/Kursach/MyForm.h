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
	private: System::Windows::Forms::ToolStripButton^  ShowIntineTask;
	private: System::Windows::Forms::ToolStripButton^  ShowOuttimeTask;
	private: System::Windows::Forms::ToolStripButton^  ShowAll;
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
	private: System::Windows::Forms::ToolStripDropDownButton^  Sorting;
	private: System::Windows::Forms::ToolStripMenuItem^  SortByName;
	private: System::Windows::Forms::ToolStripMenuItem^  SortByTime;
	private: System::Windows::Forms::ToolStripMenuItem^  SortByDeadline;



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
			this->ShowIntineTask = (gcnew System::Windows::Forms::ToolStripButton());
			this->ShowOuttimeTask = (gcnew System::Windows::Forms::ToolStripButton());
			this->ShowAll = (gcnew System::Windows::Forms::ToolStripButton());
			this->Sorting = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->SortByName = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SortByTime = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SortByDeadline = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
				this->AddNewTask, this->ShowIntineTask,
					this->ShowOuttimeTask, this->ShowAll, this->Sorting
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
			// ShowIntineTask
			// 
			this->ShowIntineTask->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->ShowIntineTask->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ShowIntineTask.Image")));
			this->ShowIntineTask->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->ShowIntineTask->Name = L"ShowIntineTask";
			this->ShowIntineTask->Size = System::Drawing::Size(110, 22);
			this->ShowIntineTask->Text = L"Поточні Завдання";
			this->ShowIntineTask->Click += gcnew System::EventHandler(this, &MyForm::ShowingIntime);
			// 
			// ShowOuttimeTask
			// 
			this->ShowOuttimeTask->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->ShowOuttimeTask->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ShowOuttimeTask.Image")));
			this->ShowOuttimeTask->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->ShowOuttimeTask->Name = L"ShowOuttimeTask";
			this->ShowOuttimeTask->Size = System::Drawing::Size(115, 22);
			this->ShowOuttimeTask->Text = L"Виконані Завдання";
			this->ShowOuttimeTask->Click += gcnew System::EventHandler(this, &MyForm::ShowingOuttime);
			// 
			// ShowAll
			// 
			this->ShowAll->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->ShowAll->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ShowAll.Image")));
			this->ShowAll->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->ShowAll->Name = L"ShowAll";
			this->ShowAll->Size = System::Drawing::Size(81, 22);
			this->ShowAll->Text = L"Всі Завдання";
			this->ShowAll->Click += gcnew System::EventHandler(this, &MyForm::ShowingAll);
			// 
			// Sorting
			// 
			this->Sorting->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->Sorting->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->SortByName,
					this->SortByTime, this->SortByDeadline
			});
			this->Sorting->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Sorting.Image")));
			this->Sorting->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Sorting->Name = L"Sorting";
			this->Sorting->Size = System::Drawing::Size(77, 22);
			this->Sorting->Text = L"Сортувати";
			// 
			// SortByName
			// 
			this->SortByName->Name = L"SortByName";
			this->SortByName->Size = System::Drawing::Size(153, 22);
			this->SortByName->Text = L"За Назвою";
			this->SortByName->Click += gcnew System::EventHandler(this, &MyForm::SortingByName);
			// 
			// SortByTime
			// 
			this->SortByTime->Name = L"SortByTime";
			this->SortByTime->Size = System::Drawing::Size(153, 22);
			this->SortByTime->Text = L"За Датою";
			this->SortByTime->Click += gcnew System::EventHandler(this, &MyForm::SortingByTime);
			// 
			// SortByDeadline
			// 
			this->SortByDeadline->Name = L"SortByDeadline";
			this->SortByDeadline->Size = System::Drawing::Size(153, 22);
			this->SortByDeadline->Text = L"За Дедлайном";
			this->SortByDeadline->Click += gcnew System::EventHandler(this, &MyForm::SortingByDeadline);
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
			this->Deadline2->BackColor = System::Drawing::SystemColors::Control;
			this->Deadline2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Deadline2->Location = System::Drawing::Point(510, 60);
			this->Deadline2->Name = L"Deadline2";
			this->Deadline2->ReadOnly = true;
			this->Deadline2->Size = System::Drawing::Size(138, 19);
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
			this->Date2->BackColor = System::Drawing::SystemColors::Control;
			this->Date2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Date2->Location = System::Drawing::Point(366, 60);
			this->Date2->Name = L"Date2";
			this->Date2->ReadOnly = true;
			this->Date2->Size = System::Drawing::Size(138, 19);
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
			this->Name2->Location = System::Drawing::Point(222, 60);
			this->Name2->Name = L"Name2";
			this->Name2->ReadOnly = true;
			this->Name2->Size = System::Drawing::Size(138, 21);
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
			this->Text2->BackColor = System::Drawing::SystemColors::Control;
			this->Text2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Text2->Location = System::Drawing::Point(222, 132);
			this->Text2->Name = L"Text2";
			this->Text2->ReadOnly = true;
			this->Text2->Size = System::Drawing::Size(570, 264);
			this->Text2->TabIndex = 11;
			this->Text2->Text = L"";
			// 
			// Text1
			// 
			this->Text1->AutoSize = true;
			this->Text1->Location = System::Drawing::Point(219, 108);
			this->Text1->Name = L"Text1";
			this->Text1->Size = System::Drawing::Size(43, 13);
			this->Text1->TabIndex = 12;
			this->Text1->Text = L"Задача";
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
			this->Status2->Click += gcnew System::EventHandler(this, &MyForm::ChangeStatus);
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
			this->ToolPanel->ResumeLayout(false);
			this->ToolPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NameList))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	int table = 0;
	int sort = 0;
	void hide();
	void visible();

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		My_List list;
		/*STime s = { 2016,12,30,16,12 };
		CObj a1("qwe1", "QWERTY1", s, '0');
		CObj a2("qwe2", "QWERTY2", s, '0');
		CObj a3("qwe3", "QWERTY3", s, '0');
		CObj a4("qwe4", "QWERTY4", s, '1');
		CObj a5("qwe5", "QWERTY5", s, '2');
		list.add_obj(a1);
		list.add_obj(a3);
		list.add_obj(a2);
		list.add_obj(a4);
		list.add_obj(a5);*/
		//list.read_from_file();
		list.read_from_file();
		table = 0;
		sort = 0;
		list.SortByDate();
		list.write_to_file();
		list.showIntime(NameList);
		hide();
	}

private: System::Void NewTask(System::Object^  sender, System::EventArgs^  e) {
	Kursach::AddingNewTask form1;
	form1.ShowDialog();
	My_List list;
	list.read_from_file();
	if (sort == 0)
		list.SortByDate();
	else if (table == 1)
		list.SortByDeadline();
	else
		list.SortByName();
	list.write_to_file();
	if (table == 0)
		list.showIntime(NameList);
	else if (table == 1)
		list.showOuttime(NameList);
	else
		list.show(NameList);
	hide();
}

private: System::Void Showing(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	My_List list;
	list.read_from_file();
	int t = Convert::ToInt32(NameList->CurrentRow->Index);
	hide();
	if ((table == 0) && (!list.IsIntimeEmpty()))
	{
		visible();
		list.showOne(Name2, Date2, Deadline2, Text2, Status2, t, table);
	}
	if ((table == 1) && (!list.IsOuttimeEmpty()))
	{
		visible();
		list.showOne(Name2, Date2, Deadline2, Text2, Status2, t, table);
	}
	if ((table == 2) && (!list.IsOuttimeEmpty() || (!list.IsOuttimeEmpty())))
	{
		visible();
		list.showOne(Name2, Date2, Deadline2, Text2, Status2, t, table);
	}
}

private: System::Void ShowingIntime(System::Object^  sender, System::EventArgs^  e) {
	My_List list;
	list.read_from_file();
	table = 0;
	list.showIntime(NameList);
	hide();
}

private: System::Void ShowingOuttime(System::Object^  sender, System::EventArgs^  e) {
	My_List list;
	list.read_from_file();
	table = 1;
	list.showOuttime(NameList);
	hide();
}

private: System::Void ShowingAll(System::Object^  sender, System::EventArgs^  e) {
	My_List list;
	list.read_from_file();
	table = 2;
	list.show(NameList);
	hide();
}

private: System::Void ChangeStatus(System::Object^  sender, System::EventArgs^  e) {
	My_List list;
	list.read_from_file();
	int t = Convert::ToInt32(NameList->CurrentRow->Index);
	list.ChangeObjStatus(t, table, Status2);
	Status2->Enabled = false;
	if (sort == 0)
		list.SortByDate();
	else if (table == 1)
		list.SortByDeadline();
	else
		list.SortByName();
	list.write_to_file();
	if (table == 0)
		list.showIntime(NameList);
	else if (table == 1)
		list.showOuttime(NameList);
	else
		list.show(NameList);
	visible();
}

private: System::Void SortingByName(System::Object^  sender, System::EventArgs^  e) {
	My_List list;
	sort = 0;
	list.read_from_file();
	list.SortByName();
	list.write_to_file();
	if (table == 0)
		list.showIntime(NameList);
	else if (table == 1)
		list.showOuttime(NameList);
	else
		list.show(NameList);
	hide();
}
private: System::Void SortingByTime(System::Object^  sender, System::EventArgs^  e) {
	My_List list;
	sort = 1;
	list.read_from_file();
	list.SortByDate();
	list.write_to_file();
	if (table == 0)
		list.showIntime(NameList);
	else if (table == 1)
		list.showOuttime(NameList);
	else
		list.show(NameList);
	hide();
}
private: System::Void SortingByDeadline(System::Object^  sender, System::EventArgs^  e) {
	My_List list;
	sort = 2;
	list.read_from_file();
	list.SortByDeadline();
	list.write_to_file();
	if (table == 0)
		list.showIntime(NameList);
	else if (table == 1)
		list.showOuttime(NameList);
	else
		list.show(NameList);
	hide();
}
};
}
