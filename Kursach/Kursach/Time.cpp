#include "Time.h"


/******************************************
*				перетворювач			  *
******************************************/
void STime::Set(DateTime date)
{
	year = date.Year;
	month = date.Month;
	day = date.Day;
	hour = date.Hour;
	minutes = date.Minute;
	seconds = 0;
}
/******************************************
*		перевизначення операції "<"		  *
******************************************/
bool STime::operator<(const STime & time) const
{
	if (year < time.year)
		return true;
	else if (year == time.year)
		if (month < time.month)
			return true;
		else if (month == time.month)
			if (day < time.day)
				return true;
			else if (day == time.day)
				if (hour < time.hour)
					return true;
				else if (hour == time.hour)
					if (minutes < time.minutes)
						return true;
					else if (minutes == time.minutes)
						if (seconds < time.seconds)
							return true;
	
	return false;
}
/******************************************
*		перевизначення операції "=="	  *
******************************************/
bool STime::operator==(const STime & time) const
{
	if ((year == time.year) && (month == time.month) && (day == time.day) && (hour == time.hour) && (minutes == time.minutes) && (seconds == time.seconds))
		return true;
	return false;
}
