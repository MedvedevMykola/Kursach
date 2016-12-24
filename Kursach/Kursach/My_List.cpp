#include "My_List.h"
#define _CRT_SECURE_NO_WARNINGS


using namespace std;

My_List::My_List()
{
}

void My_List::add_obj(CObj obj)
{
	
	obj.check_status();
	if (obj.get_start().year < 0)
		return;
	if (obj.get_status() == '0')
		table_intime.insert(obj);
	else if (obj.get_status() == '1')
		table_outtime.insert(obj);
}

void My_List::show()
{
	try {
		if (table_intime.empty())
			throw CException("Empty Intime List");
		auto iter = table_intime.begin();
		cout << "Intime:" << endl;
		for (int i = 0;i < table_intime.size();i++)
		{
			CObj temp = *iter;
			cout << temp.get_name() << " " << temp.get_status() << " " << temp.get_text() << " " << temp.get_description();
			cout << " " << temp.get_deadline().year << " " << temp.get_deadline().month << " " << temp.get_deadline().day << " " << temp.get_deadline().hour << ":" << temp.get_deadline().minutes << " ";
			cout << " " << temp.get_start().year << " " << temp.get_start().month << " " << temp.get_start().day << " " << temp.get_start().hour << ":" << temp.get_start().minutes << endl;
			if (i != table_intime.size() - 1)
				iter++;
		}
	}
	catch (CException& excection) {
		excection.show();
	}
	try {
		if (table_outtime.empty())
			throw CException("Empty Outtime List");
		cout << "Outtime:" << endl;
		auto iter = table_outtime.begin();
		for (int i = 0;i < table_outtime.size();i++)
		{
			CObj temp = *iter;
			cout << temp.get_name() << " " << temp.get_status() << " " << temp.get_text() << " " << temp.get_description();
			cout << " " << temp.get_deadline().year << " " << temp.get_deadline().month << " " << temp.get_deadline().day << " " << temp.get_deadline().hour << ":" << temp.get_deadline().minutes << " ";
			cout << " " << temp.get_start().year << " " << temp.get_start().month << " " << temp.get_start().day << " " << temp.get_start().hour << ":" << temp.get_start().minutes << endl;
			if (i != table_intime.size() - 1)
				iter++;
		}
	}
	catch (CException& excection) {
		excection.show();
	}
}

void My_List::read_from_file()
{
	FILE *f = fopen("database.dat", "rb, ccs=UTF-8");
	do
	{
		CObj *temp = new CObj;
		fread(temp, sizeof(CObj), 1, f);
		add_obj(*temp);
	} while (!feof(f));
	fclose(f);
}

void My_List::write_to_file()
{
	FILE *f = fopen("database.dat", "wb, ccs=UTF-8");
	if (!table_intime.empty())
	{
		auto iter = table_intime.begin();
		for (int i = 0;i < table_intime.size();i++)
		{
			CObj temp = *iter;
			fwrite(&temp, sizeof(CObj), 1, f);
			if (i != table_intime.size() - 1)
				iter++;
		}
	}

	if (!table_outtime.empty())
	{
		auto iter = table_outtime.begin();
		for (int i = 0;i < table_outtime.size();i++)
		{
			CObj temp = *iter;
			fwrite(&temp, sizeof(CObj), 1, f);
			if (i != table_outtime.size() - 1)
				iter++;
		}
	}
	fclose(f);
}

bool My_List::move(int pos)
{
	if (!table_intime.empty())
	{
		auto iter = table_intime.begin();
		if (pos > table_intime.size() || (pos <= 0))
			return false;
		for (int i = 1;i < pos;i++)
		{
			if (i <= pos - 1)
				iter++;
		}
		CObj temp = *iter;
		temp.set_status('1');
		add_obj(temp);
		table_intime.erase(iter);
		return true;
	}
}

My_List::~My_List()
{
}
