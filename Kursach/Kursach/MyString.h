#pragma once
#include <string>
#include "Time.h"
#include "Obj.h"


using std::string;

struct MyString
{
	char name[64];
	char text[4096];
	STime start;
	STime deadline;
	char status;
	MyString() {};
	MyString(CObj);
	CObj Get(void);
};