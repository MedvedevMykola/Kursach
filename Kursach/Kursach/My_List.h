#pragma once
#include "Obj.h"
#include <set>
#include <string>
#include <vector>
using namespace std;
class My_List
{
	set<CObj>table_intime;
	set<CObj>table_outtime;
public:
	My_List();
	void add_obj_intime(CObj);
	void add_obj_outtime(CObj);
	~My_List();
};