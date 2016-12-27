#include "MyGDrive.h"
#include "MyForm.h"
#include "My_List.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Kursach::MyForm form;
	Application::Run(%form);
}