#include "stdafx.h"
#include "Time.h"
/******************************************
*		перевизначення операції "<"		  *
******************************************/
bool STime::operator<(const STime & time) const
{
	STime tmp = time;
	if (this->year < tmp.year)
		return true;
	else if (this->month < tmp.month)
		return true;
	else if (this->day < tmp.day)
		return true;
	else if (this->hour < tmp.hour)
		return true;
	else if (this->minutes < tmp.minutes)
		return true;
	else return false;
}
