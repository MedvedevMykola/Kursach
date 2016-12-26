#include "MyForm.h"

void Kursach::MyForm::hide()
{
	Name1->Visible = false;
	Name2->Visible = false;
	Date1->Visible = false;
	Date2->Visible = false;
	Deadline1->Visible = false;
	Deadline2->Visible = false;
	Status1->Visible = false;
	Status2->Visible = false;
	Text1->Visible = false;
	Text2->Visible = false;
}

void Kursach::MyForm::visible()
{
	Name1->Visible = true;
	Name2->Visible = true;
	Date1->Visible = true;
	Date2->Visible = true;
	Deadline1->Visible = true;
	Deadline2->Visible = true;
	Status1->Visible = true;
	Status2->Visible = true;
	Text1->Visible = true;
	Text2->Visible = true;
}

