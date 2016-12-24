#pragma once
struct STime
{
	int year;
	int month;
	int day;
	int hour;
	int minutes;
	int seconds;
	bool operator<(const STime &time)const;//перевизначення операції "<"
	bool operator==(const STime &time)const;//перевизначення операції "<"
};

