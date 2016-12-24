#include "My_List.h"
#define _CRT_SECURE_NO_WARNINGS


using namespace std;

My_List::My_List()
{
}

void My_List::add_obj(CObj obj)
{
	
	obj.check_status();
	if (obj.get_name() == string())
		return;
	if (obj.get_status() == '0')
		table_intime.insert(obj);
	else if (obj.get_status() == '1')
		table_outtime.insert(obj);
}

void My_List::show(DataGridView^ Table_intime, DataGridView^ Table_outtime)
{
	try {
		if (table_intime.empty())
			throw CException("Empty Intime List");
		auto iter = table_intime.begin();
		/*cout << "Intime:" << endl;*/
		Table_intime->RowCount = table_intime.size();
		for (int i = 0;i < table_intime.size();i++)
		{
			CObj temp = *iter;
			DateTime(12, 12, 30, 12, 12, 12);
			Table_intime->Rows[i]->Cells[0]->Value = gcnew String(temp.get_name().c_str());
			Table_intime->Rows[i]->Cells[1]->Value = Convert::ToString(temp.get_start());
			Table_intime->Rows[i]->Cells[2]->Value = Convert::ToString(temp.get_deadline());
			Table_intime->Rows[i]->Cells[3]->Value = gcnew String(temp.get_description().c_str());
			Table_intime->Rows[i]->Cells[4]->Value = gcnew String(temp.get_text().c_str());
			if (i != table_intime.size() - 1)
				iter++;
		}
	}
	catch (CException& excection) {
	}

	try {
		if (table_outtime.empty())
			throw CException("Empty Intime List");
		auto iter = table_outtime.begin();
		/*cout << "Intime:" << endl;*/
		Table_outtime->RowCount = table_outtime.size();
		for (int i = 0;i < table_outtime.size();i++)
		{
			CObj temp = *iter;
			DateTime(12, 12, 30, 12, 12, 12);
			Table_outtime->Rows[i]->Cells[0]->Value = gcnew String(temp.get_name().c_str());
			Table_outtime->Rows[i]->Cells[1]->Value = Convert::ToString(temp.get_start());
			Table_outtime->Rows[i]->Cells[2]->Value = Convert::ToString(temp.get_deadline());
			Table_outtime->Rows[i]->Cells[3]->Value = gcnew String(temp.get_description().c_str());
			Table_outtime->Rows[i]->Cells[4]->Value = gcnew String(temp.get_text().c_str());
			if (i != table_intime.size() - 1)
				iter++;
		}
	}
	catch (CException& excection) {
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
