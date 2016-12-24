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

class My_List
{
	set<CObj>table_intime;
	set<CObj>table_outtime;
public:
	My_List();
	void add_obj(CObj);
	void show();
	void read_from_file();
	void write_to_file();
	bool move(int);
	~My_List();
};