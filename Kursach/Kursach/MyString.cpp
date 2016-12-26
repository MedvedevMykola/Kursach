#include "MyString.h"

MyString::MyString(CObj Obj)
{
	strcpy(name, Obj.get_name().c_str());
	strcpy(text, Obj.get_text().c_str());
	start = Obj.get_start1();
	deadline = Obj.get_deadline1();
	status = Obj.get_status();
}

CObj MyString::Get(void)
{
	string name1 = name;
	string text1 = text;
	CObj temp(name1, text1, deadline, status);
	temp.set_start1(start);
	return temp;
}
