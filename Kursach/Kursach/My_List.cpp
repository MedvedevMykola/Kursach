#include "stdafx.h"
#include "My_List.h"


My_List::My_List()
{
}

void My_List::add_obj_intime(CObj obj)
{
	table_intime.emplace(obj);
}

void My_List::add_obj_outtime(CObj obj)
{
	table_outtime.insert(obj);
}


My_List::~My_List()
{
}
