#pragma once
#include "Obj.h"
#include "MyString.h"
#include <set>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <conio.h>
#include "Exception.h"


using std::vector;

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

class My_List
{
	vector<CObj>table_intime; //список активних завдань
	vector<CObj>table_outtime;//список пасивних завдань
public:
	My_List();
	void add_obj(CObj);    //функція добавки нового завдання
	void show(DataGridView^);//виведення списку імен
	void showIntime(DataGridView^);
	void showOuttime(DataGridView^);
	bool IsIntimeEmpty();
	bool IsOuttimeEmpty();
	void showOne(RichTextBox^, RichTextBox^, RichTextBox^, RichTextBox^, Button^, int, int);//виведення одного елементу
	void ChangeObjStatus(int, int, Button^);//переміщення елементу з активних в пасивні
	void SortByName();
	void SortByDate();
	void SortByDeadline();
	void read_from_file(); //читання з файлу
	void write_to_file();  //запис в файл
	~My_List();
};