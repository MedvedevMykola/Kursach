#include "stdafx.h"
#include "Obj.h"
#include <ctime>    
using namespace std;
/******************************************
*			êîíñòðóêòîð					  *
******************************************/
CObj::CObj(string name1, string desc1, string text1, STime dline1, char stat)
{
	set_name(name1);
	set_description(desc1);
	set_text(text1);
	set_start();
	set_deadline(dline1);
	set_status(stat);
}


CObj::~CObj()
{

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
	+start.month = (ptm->tm_mon + 1);

	start.day = (ptm->tm_mday);
	start.hour = (ptm->tm_hour) % 24;
	start.minutes = (ptm->tm_min);
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
}
/******************************************
*		ïåðåâèçíà÷åííÿ îïåðàö³¿ "<"		  *
******************************************/
bool CObj::operator<(const CObj & obj) const
{
	CObj tmp = obj;
	if (this->start < tmp.start)
		return true;
	else
		if (this->deadline < tmp.deadline)
			return true;
		else
			if (this->name < tmp.name)
				return true;
			else
				return false;
}
