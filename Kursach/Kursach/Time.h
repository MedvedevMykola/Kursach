#pragma once
struct STime
{
	int year;
	int month;
	int day;
	int hour;
	int minutes;
	bool operator<(const STime &time)const;//перевизначення операції "<"
	bool operator==(const STime &time)const;//перевизначення операції "<"
};

