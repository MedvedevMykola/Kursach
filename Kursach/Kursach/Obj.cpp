#include "Obj.h"
#include <ctime>    
   
using namespace std;
/******************************************
*			êîíñòðóêòîð					  *
******************************************/
CObj::CObj(const CObj & obj)
{
	name = obj.name;
	description = obj.description;
	text = obj.text;
	start = obj.start;
	deadline = obj.deadline;
	status = obj.status;
}
CObj::CObj(string name1, string desc1, string text1, STime dline1, char stat)
{
	name = name1;
	description = desc1;
	text = text1;
	set_start();
	deadline = dline1;
	status = stat;
	check_status();
}

/******************************************
*		âèçíà÷åííÿ äàòè ïî÷àòêó			  *
******************************************/
void CObj::set_start()
{
	time_t rawtime; 
	struct tm * ptm;
	time(&rawtime);// äàòà ïî÷àòêó â ñåêóíäàõ
	ptm = localtime(&rawtime);// äàòà ³ ÷àñ â ôîðìàò³ GMT
	
	start.year = (ptm->tm_year + 1900);

	start.month = (ptm->tm_mon + 1);

	start.day = (ptm->tm_mday);
	start.hour = (ptm->tm_hour) % 24;
	start.minutes = (ptm->tm_min);
	start.seconds = (ptm->tm_sec);
}
/******************************************
*		âèçíà÷åííÿ äàòè äåäëàéíó		  *
******************************************/
void CObj::set_deadline(STime dline1)
{
	deadline.year = dline1.year;
	deadline.month = dline1.month;
	deadline.day = dline1.day;
	deadline.hour = dline1.hour;
	deadline.minutes = dline1.minutes;
	deadline.seconds = dline1.seconds;
}
DateTime CObj::get_start()
{
	return DateTime(start.year, start.month, start.day, start.hour, start.minutes, start.seconds);
}
DateTime CObj::get_deadline()
{
	return DateTime(deadline.year, deadline.month, deadline.day, deadline.hour, deadline.minutes, deadline.seconds);
}
/******************************************
*		ïåðåâèçíà÷åííÿ îïåðàö³¿ "<"		  *
******************************************/
bool CObj::operator<(const CObj & obj) const
{
	if (this->start < obj.start)
		return true;
	else if (this->start == obj.start)
		if (this->deadline < obj.deadline)
			return true;
		else if (this->deadline == obj.deadline)
			if (this->name < obj.name)
				return true;
	return false;
}

void CObj::check_status()
{
	STime curr_time;
	time_t rawtime;
	struct tm * ptm;
	time(&rawtime);// äàòà ïî÷àòêó â ñåêóíäàõ
	ptm = localtime(&rawtime);// äàòà ³ ÷àñ â ôîðìàò³ GMT

	curr_time.year = (ptm->tm_year + 1900);

	curr_time.month = (ptm->tm_mon + 1);

	curr_time.day = (ptm->tm_mday);
	curr_time.hour = (ptm->tm_hour) % 24;
	curr_time.minutes = (ptm->tm_min);
	if (deadline < curr_time)
	{
		this->status = '1';
	}
}

CObj::~CObj()
{

}
