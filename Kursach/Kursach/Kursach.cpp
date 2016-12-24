#include "MyGDrive.h"
#include "MyForm.h"
#include "My_List.h"
#include "Exception.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Kursach::MyForm form;  //нужно указать имя своего проекта (а не test_project)
	Application::Run(%form);
}

//int main()
//{
//	try
//	{
//		//MyGDrive gdrive1;
//		//while (gdrive1.Menu());
//		//gdrive1.DownloadDatabase();
//		My_List list;
//		STime s = { 2016,12,28,12,16 };
//		CObj a("qwe1", "qwerty", "QWERTY", s, '0');
//		CObj с("qwe2", "qwerty1", "QWERTY", s, '0');
//		CObj b("qwe3", "qwerty", "QWERTY", s, '0');
//		list.add_obj(b);
//		list.add_obj(a);
//		list.add_obj(с);
//		list.show();
//		list.move(3);
//		/*list.write_to_file();
//		My_List list1;
//		list1.read_from_file();*/
//		list.show();
//		//gdrive1.UploadDatabase();
//	}
//	catch (CException& excection) {
//		excection.show();
//		system("pause");
//	}
//	system("pause");
//	return 0;
//
//}