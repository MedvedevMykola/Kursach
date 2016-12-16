#pragma once
#include "Time.h"
#include <string>
using namespace std;
class CObj
{
	string name;
	string description;
	string text;
	STime start;
	STime deadline;
	char status;
public:
	CObj(string name1, string desc1,string text1, STime dline1, char stat);
	~CObj();
	void our_time();
	void set_name(string name1) { name = name1; }
	void set_description(string desc1) { description = desc1; }
	void set_text(string text1){ text = text1; }
	void set_deadline(STime dline1);
	void set_status(char stat){ status = stat; }
};

