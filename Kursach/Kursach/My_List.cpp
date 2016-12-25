#include "My_List.h"
#define _CRT_SECURE_NO_WARNINGS


using namespace std;

My_List::My_List()
{
}

void My_List::add_obj(CObj obj)
{
	
	obj.check_status();
	if (obj.get_start1().year == -842150451)
		return;
	if (obj.get_status() == '0')
		table_intime.insert(obj);
	else if (obj.get_status() == '1')
		table_outtime.insert(obj);
}

void My_List::show(DataGridView^ Table_intime)
{
	Table_intime->RowCount = table_intime.size() + table_outtime.size();
	if (!table_intime.empty())
	{
		auto iter = table_intime.begin();
		for (int i = 0;i < table_intime.size();i++)
		{
			CObj temp = *iter;
			Table_intime->Rows[i]->Cells[0]->Style->BackColor = System::Drawing::Color::White;

			Table_intime->Rows[i]->Cells[0]->Value = gcnew String(temp.get_name().c_str());
			if (i != table_intime.size() - 1)
				iter++;
		}
	}
	if (!table_outtime.empty())
	{
		auto iter1 = table_outtime.begin();
		for (int i = table_intime.size();i < table_intime.size() + table_outtime.size();i++)
		{
			CObj temp = *iter1;
			Table_intime->Rows[i]->Cells[0]->Style->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(223)));

			Table_intime->Rows[i]->Cells[0]->Value = gcnew String(temp.get_name().c_str());
			if (i != table_intime.size() - 1)
				iter1++;
		}
	}
}

void My_List::showOne(RichTextBox ^ t1, RichTextBox ^ t2, RichTextBox ^ t3, RichTextBox ^ t4, Button ^ b, int pos)
{
	int pos1 = pos;
	if (pos + 1 > table_intime.size())
	{
		pos1 = pos - table_intime.size();
		if (!table_outtime.empty())
		{
			auto iter1 = table_outtime.begin();
			for (int i = 1;i < pos1;i++)
			{
				if (i <= pos1 - 1)
					iter1++;
			}
			CObj temp = *iter1;
			b->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(223)));
			b->Text = "��������";

			
			t1->Text = gcnew String(temp.get_name().c_str());
			t2->Text = Convert::ToString(temp.get_start());
			t3->Text = Convert::ToString(temp.get_deadline());
			t4->Text = gcnew String(temp.get_text().c_str());
		}
	}
	else
	{
		if (!table_intime.empty())
		{
			auto iter = table_intime.begin();
			for (int i = 0;i < pos1;i++)
			{
				if (i <= pos1 - 1)
					iter++;
			}
			CObj temp = *iter;
			b->BackColor = System::Drawing::Color::White;
			b->Text = "����������";

			t1->Text = gcnew String(temp.get_name().c_str());
			t2->Text = Convert::ToString(temp.get_start());
			t3->Text = Convert::ToString(temp.get_deadline());
			t4->Text = gcnew String(temp.get_text().c_str());
		}

	}
}

void My_List::read_from_file()
{
	FILE *f = fopen("database.dat", "rb, ccs=UTF-8");
	do
	{
		MyString *temp = new MyString;
		fread(temp, sizeof(MyString), 1, f);
		CObj temp1 = temp->Get();
		add_obj(temp1);
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
			MyString temp1(temp);
			fwrite(&temp1, sizeof(MyString), 1, f);
			if (i != table_intime.size() - 1)
				iter++;
		}
	}

	if (!table_outtime.empty())
	{
		auto iter = table_outtime.begin();
		for (int i = 0;i < table_outtime.size();i++)
		{
			CObj temp2 = *iter;
			MyString temp3(temp2);
			fwrite(&temp3, sizeof(MyString), 1, f);
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
