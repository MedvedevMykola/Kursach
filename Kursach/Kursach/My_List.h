#pragma once
#include "Obj.h"
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


using std::set;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

class My_List
{
	set<CObj>table_intime;
	set<CObj>table_outtime;
public:
	My_List();
	void add_obj(CObj);
	void show(DataGridView^, DataGridView^);
	void read_from_file();
	void write_to_file();
	bool move(int);
	~My_List();
};