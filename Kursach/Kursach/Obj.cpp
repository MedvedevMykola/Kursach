#include "stdafx.h"
#include "Obj.h"
#include <ctime>    
using namespace std;
/******************************************
*			конструктор					  *
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
*		визначення дати початку			  *
******************************************/
void CObj::set_start()
{
	time_t rawtime;
	struct tm * ptm;
	time(&rawtime);// дата початку в секундах
	ptm = gmtime(&rawtime);// дата і час в форматі GMT
	
	start.year = (ptm->tm_year);
	start.month = (ptm->tm_mon);
	start.day = (ptm->tm_mday);
	start.hour = (ptm->tm_hour + 2) % 24;
	start.minutes = (ptm->tm_min);
}
/******************************************
*		визначення дати дедлайну		  *
******************************************/
void CObj::set_deadline(STime dline1)
{
	deadline.year = dline1.year;
	deadline.month = dline1.month;
	deadline.day = dline1.day;
	deadline.hour = dline1.hour;
	deadline.minutes = dline1.minutes;
}