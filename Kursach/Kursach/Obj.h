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
	CObj() {};
	CObj(const CObj&);
	CObj(string name1, string desc1,string text1, STime dline1, char stat);
	~CObj();
	/******************************************
	*				setter					  *
	******************************************/
	void set_name(string name1) { name = name1; }
	void set_description(string desc1) { description = desc1; }
	void set_text(string text1){ text = text1; }
	void set_start();
	void set_deadline(STime dline1);
	void set_status(char stat){ status = stat; }
	/******************************************
	*				getter					  *
	******************************************/
	string get_name() const{ return name; }
	string get_description() { return description; }
	string get_text() { return text; }
	STime get_start() { return start; }
	STime get_deadline() { return deadline; }
	char get_status() { return status; }
	/******************************************
	*				operator				  *
	******************************************/
	bool operator<(const CObj &obj)const;
	/******************************************
	*				functions				  *
	******************************************/
	void check_status();
};
