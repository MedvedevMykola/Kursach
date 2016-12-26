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
		table_intime.push_back(obj);
	else if (obj.get_status() == '1')
		table_outtime.push_back(obj);
	else if (obj.get_status() == '2')
		table_outtime.push_back(obj);
}

void My_List::show(DataGridView^ Table_intime)
{
	Table_intime->RowCount = 1;
	Table_intime->Rows[0]->Cells[0]->Value = "";
	if(!table_intime.empty() || !table_outtime.empty())
	Table_intime->RowCount = table_intime.size() + table_outtime.size();
	if (!table_intime.empty())
	{
		for (int i = 0;i < table_intime.size();i++)
		{
			Table_intime->Rows[i]->Cells[0]->Style->BackColor = System::Drawing::Color::White;

			Table_intime->Rows[i]->Cells[0]->Value = gcnew String(table_intime[i].get_name().c_str());
		}
	}
	if (!table_outtime.empty())
	{
		auto iter1 = table_outtime.begin();
		for (int i = table_intime.size();i < table_intime.size() + table_outtime.size();i++)
		{
			if (table_outtime[i - table_intime.size()].get_status() == '2')
				Table_intime->Rows[i]->Cells[0]->Style->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)),
					static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(223)));
			else
				Table_intime->Rows[i]->Cells[0]->Style->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
					static_cast<System::Int32>(static_cast<System::Byte>(185)), static_cast<System::Int32>(static_cast<System::Byte>(185)));

			Table_intime->Rows[i]->Cells[0]->Value = gcnew String(table_outtime[i - table_intime.size()].get_name().c_str());
		}
	}
}

void My_List::showIntime(DataGridView^ Table_intime)
{
	Table_intime->RowCount = 1;
	Table_intime->Rows[0]->Cells[0]->Value = "";
	if (!table_intime.empty())
	{
		Table_intime->RowCount = table_intime.size();
		for (int i = 0;i < table_intime.size();i++)
		{
			Table_intime->Rows[i]->Cells[0]->Style->BackColor = System::Drawing::Color::White;

			Table_intime->Rows[i]->Cells[0]->Value = gcnew String(table_intime[i].get_name().c_str());
		}
	}
}

void My_List::showOuttime(DataGridView^ Table_intime)
{
	Table_intime->RowCount = 1;
	Table_intime->Rows[0]->Cells[0]->Value = "";
	if (!table_outtime.empty())
	{
		Table_intime->RowCount = table_outtime.size();
		for (int i = 0;i < table_outtime.size();i++)
		{
			if (table_outtime[i].get_status() == '2')
			Table_intime->Rows[i]->Cells[0]->Style->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(223)));
			if (table_outtime[i].get_status() == '1')
				Table_intime->Rows[i]->Cells[0]->Style->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
					static_cast<System::Int32>(static_cast<System::Byte>(185)), static_cast<System::Int32>(static_cast<System::Byte>(185)));

			Table_intime->Rows[i]->Cells[0]->Value = gcnew String(table_outtime[i].get_name().c_str());
		}
	}
}

bool My_List::IsIntimeEmpty()
{
	return table_intime.empty();
}

bool My_List::IsOuttimeEmpty()
{
	return table_outtime.empty();
}

void My_List::showOne(RichTextBox ^ t1, RichTextBox ^ t2, RichTextBox ^ t3, RichTextBox ^ t4, Button ^ b, int pos, int table)
{
	int pos1 = pos;
	if (table == 1)
		pos1 += table_intime.size();

	if (pos1 + 1 > table_intime.size())
	{
		pos1 -= table_intime.size();
		if (!table_outtime.empty())
		{
			if (table_outtime[pos1].get_status() == '1')
			{
				b->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
					static_cast<System::Int32>(static_cast<System::Byte>(185)),static_cast<System::Int32>(static_cast<System::Byte>(185)));
				b->Text = "Просрочено";
			}
			else
			{
				b->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)),
					static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(223)));
				b->Text = "Виконано";
			}
			b->Enabled = false;

			t1->Text = gcnew String(table_outtime[pos1].get_name().c_str());
			t2->Text = Convert::ToString(table_outtime[pos1].get_start());
			t3->Text = Convert::ToString(table_outtime[pos1].get_deadline());
			t4->Text = gcnew String(table_outtime[pos1].get_text().c_str());
		}
	}
	else
	{
		if (!table_intime.empty())
		{
			b->BackColor = System::Drawing::Color::White;
			b->Text = "Виконується";
			b->Enabled = true;

			t1->Text = gcnew String(table_intime[pos1].get_name().c_str());
			t2->Text = Convert::ToString(table_intime[pos1].get_start());
			t3->Text = Convert::ToString(table_intime[pos1].get_deadline());
			t4->Text = gcnew String(table_intime[pos1].get_text().c_str());
		}

	}
}

void My_List::ChangeObjStatus(int pos, int table, Button^ b)
{
	int pos1 = pos;
	if (table == 1)
		return;

	if (pos1 + 1 > table_intime.size())
	{
		return;
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
			if (temp.get_status() == '0')
			{
				temp.set_status('2');
				add_obj(temp);
				table_intime.erase(iter);
				b->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)),
					static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(223)));
				b->Text = "Виконано";
			}
		}
	}
}

void My_List::SortByName()
{
	sort(table_intime.begin(), table_intime.end(), [](CObj s1, CObj s2) ->bool
	{
		if (s1.get_name() < s2.get_name())
			return true;
		else if (s1.get_name() == s2.get_name())
			if (s1.get_start1() < s2.get_start1())
				return true;
			else if (s1.get_start1() == s2.get_start1())
				if (s1.get_deadline1() < s2.get_deadline1())
					return true;
		return false;
	});

	sort(table_outtime.begin(), table_outtime.end(), [](CObj s1, CObj s2) ->bool
	{
		if (s1.get_name() < s2.get_name())
			return true;
		else if (s1.get_name() == s2.get_name())
			if (s1.get_start1() < s2.get_start1())
				return true;
			else if (s1.get_start1() == s2.get_start1())
				if (s1.get_deadline1() < s2.get_deadline1())
					return true;
		return false;
	});
}

void My_List::SortByDate()
{
	sort(table_intime.begin(), table_intime.end(), [](CObj s1, CObj s2) ->bool
	{
		return s1 < s2;
	});

	sort(table_outtime.begin(), table_outtime.end(), [](CObj s1, CObj s2) ->bool
	{
		return s1 < s2;
	});
}

void My_List::SortByDeadline()
{
	sort(table_intime.begin(), table_intime.end(), [](CObj s1, CObj s2) ->bool
	{
		if (s1.get_deadline1() < s2.get_deadline1())
			return true;
		else if (s1.get_deadline1() == s2.get_deadline1())
			if (s1.get_start1() < s2.get_start1())
				return true;
			else if (s1.get_start1() == s2.get_start1())
				if (s1.get_name() < s2.get_name())
					return true;
		return false;
	});

	sort(table_outtime.begin(), table_outtime.end(), [](CObj s1, CObj s2) ->bool
	{
		if (s1.get_deadline1() < s2.get_deadline1())
			return true;
		else if (s1.get_deadline1() == s2.get_deadline1())
			if (s1.get_start1() < s2.get_start1())
				return true;
			else if (s1.get_start1() == s2.get_start1())
				if (s1.get_name() < s2.get_name())
					return true;
		return false;
	});
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
		for (int i = 0;i < table_intime.size();i++)
		{
			MyString temp1(table_intime[i]);
			fwrite(&temp1, sizeof(MyString), 1, f);
		}
	}

	if (!table_outtime.empty())
	{
		auto iter = table_outtime.begin();
		for (int i = 0;i < table_outtime.size();i++)
		{
			MyString temp2(table_outtime[i]);
			fwrite(&temp2, sizeof(MyString), 1, f);
		}
	}
	fclose(f);
}

My_List::~My_List()
{
}
