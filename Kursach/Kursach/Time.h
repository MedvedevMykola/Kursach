#pragma once
using namespace System;


struct STime
{
	int year;
	int month;
	int day;
	int hour;
	int minutes;
	int seconds;
	
	void Set(DateTime);//Datetime to STime
	bool operator<(const STime &time)const;//перевизначення операції "<"
	bool operator==(const STime &time)const;//перевизначення операції "=="
};

