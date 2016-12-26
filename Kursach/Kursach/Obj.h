#pragma once
#include "Time.h"
#include <string>
#define _CRT_SECURE_NO_WARNINGS


using std::string;
using namespace System;


class CObj
{
	string name;
	string text;
	STime start;
	STime deadline;
	char status;
public:
	CObj();
	CObj(const CObj&);
	CObj(string name1, string text1, STime dline1, char stat);
	~CObj();
	/******************************************
	*				setter					  *
	******************************************/
	void set_name(string name1) { name = name1; }
	void set_text(string text1){ text = text1; }
	void set_start();
	void set_start1(STime start1) { start = start1; }
	void set_deadline(STime dline1);
	void set_status(char stat){ status = stat; }
	/******************************************
	*				getter					  *
	******************************************/
	string get_name() const{ return name; }
	string get_text() { return text; }
	DateTime get_start();
	DateTime get_deadline();
	STime get_start1() { return start; };
	STime get_deadline1() { return deadline; };
	char get_status() { return status; }
	/******************************************
	*				operator				  *
	******************************************/
	bool operator<(const CObj &obj)const;
	/******************************************
	*				functions				  *
	******************************************/
	void check_status();//перевіряє актуальність статусу завдання
	void Copy(const CObj&);//копіює об'єкт
};
