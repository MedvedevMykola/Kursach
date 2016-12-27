#include "MyGDrive.h"
#define _CRT_SECURE_NO_WARNINGS


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Net;

MyGDrive::MyGDrive() : GDrive()
{
}

char* MyGDrive::Auth()
{
	char s[1000];
	OAuth oauth1;
	if (ConnectionAvailable())
	{
		oauth1.SetClientId("157623334268-pdch1uarb3180t5hq2s16ash9ei315j0.apps.googleusercontent.com");
		oauth1.SetClientSecret("k4NSk71U-p2sU8lB8Qv3G24R");
		oauth1.SetServerTokenURL("https://accounts.google.com/o/oauth2/token");
		oauth1.SetServerAuthURL("https://accounts.google.com/o/oauth2/auth");
		oauth1.SetAuthorizationScope("https://www.googleapis.com/auth/drive");
		SetAuthorization(oauth1.GetAuthorization());
		strcpy(s, GetAuthorization());
		int ret_code = oauth1.GetLastErrorCode();
		if (ret_code)
			return "";
		return s;
	}
	return "";
}

void MyGDrive::Auth1(char* s)
{
	if (ConnectionAvailable())
	{
		OAuth oauth1;
		oauth1.SetClientId("157623334268-pdch1uarb3180t5hq2s16ash9ei315j0.apps.googleusercontent.com");
		oauth1.SetClientSecret("k4NSk71U-p2sU8lB8Qv3G24R");
		oauth1.SetServerTokenURL("https://accounts.google.com/o/oauth2/token");
		oauth1.SetServerAuthURL("https://accounts.google.com/o/oauth2/auth");
		oauth1.SetAuthorizationScope("https://www.googleapis.com/auth/drive");
		SetAuthorization(s);
		int ret_code = oauth1.GetLastErrorCode();
		if (ret_code)
			return;
	}
}

void MyGDrive::Void()
{
	if (ConnectionAvailable())
	{
		try
		{
			SetResourceIndex(-1);
			int ret_code = ListResources();
			if (ret_code)
				return;
			for (int i = 0;i < GetResourceCount();i++)
			{
				SetResourceIndex(i);
			}
			return;
		}
		catch (...) {}
	}
}

void MyGDrive::displayDocuments()
{
	SetResourceIndex(-1); //Clear the documents collection
	int ret_code = ListResources();
	if (ret_code)
		return;

	printf("%-4.1s%-42.40s%-22.20s%-32.30s\n\n", "#", "Title", "Author", "Modified Data");

	for (int i = 0;i<GetResourceCount();i++)
	{
		SetResourceIndex(i);
		printf("%-4.1d%-42.40s%-22.20s%-32.30s\n", i, GetResourceTitle(), GetResourceOwners(), GetResourceModifiedDate());
	}
	return;
}

void MyGDrive::DownloadDocument()
{
	displayDocuments();
	char buffer[LINE_LEN + 1];
	int ret_code = 0;
	printf("\nDocument Number: ");
	scanf("%80s", buffer);
	SetResourceIndex(atoi(buffer));

	printf("Download Directory: ");
	scanf("%80s", buffer);
	strcat(buffer, "\\");
	strcat(buffer, GetResourceTitle());
	SetLocalFile(buffer);

	ret_code = DownloadFile(""); //Use the default file format
	if (ret_code)
		return;

	printf("\n Download Successful\n");
}

void MyGDrive::UploadDocument()
{
	char buffer[LINE_LEN + 1];
	int ret_code = 0;
	printf("\nLocal File: ");
	scanf("%80s", buffer);

	SetResourceIndex(-1);
	SetLocalFile(buffer);

	printf("Name of New File on Server: ");
	scanf("%80s", buffer);
	UploadFile(buffer);
	ret_code = GetLastErrorCode();

	if (ret_code)
		return;

	displayDocuments();
}

void MyGDrive::DeleteDocument()
{
	displayDocuments();
	char buffer[LINE_LEN + 1];
	int ret_code = 0;
	printf("\nDocument Number: ");
	scanf("%80s", buffer);
	SetResourceIndex(atoi(buffer));

	ret_code = DeleteResource();

	if (ret_code)
		return;

	displayDocuments();
}

void MyGDrive::DownloadDatabase()
{
	if (ConnectionAvailable())
	{
		try
		{
			SetResourceIndex(-1); //Clear the documents collection
			int ret_code = ListResources();
			if (ret_code)
				return;
			remove("database.dat");
			char* str = "database.dat";
			int data = -1;
			for (int i = 0;i < GetResourceCount();i++)
			{
				SetResourceIndex(i);
				if (!strcmp(str, GetResourceTitle())) data = i;
			}
			SetResourceIndex(data);
			char buffer[LINE_LEN + 1] = "database.dat";
			SetLocalFile(buffer);
			ret_code = DownloadFile(""); //Use the default file format
			if (ret_code)
			{
				FILE *f = fopen("database.dat", "wb, ccs=UTF-8");
				fclose(f);
				return;
			}
			return;
		}
		catch (...) {}
	}
}

void MyGDrive::UploadDatabase()
{
	if (ConnectionAvailable())
	{
		try
		{
			Void();
			SetResourceIndex(-1);
			char* str = "database.dat";
			for (int i = 0;i < GetResourceCount();i++)
			{
				SetResourceIndex(i);
				if (!strcmp(str, GetResourceTitle()))
				{
					int ret_code = DeleteResource(); //Use the default file format
					if (ret_code)
						return;
				}
			}
			SetResourceIndex(-1);
			SetLocalFile("database.dat");
			UploadFile("database.dat");
			int ret_code = GetLastErrorCode();

			if (ret_code)
				return;
			return;
		}
		catch (...) {}
	}
}

bool MyGDrive::Menu()
{
	system("cls");
	printf("Type ? to select this menu, a number 1-7 to select the following choices:\n"
		"1.  List Documents\n"
		"2.  Download Document\n"
		"3.  Upload Document\n"
		"4.  Delete Document\n"
		"5.  Download Database\n"
		"6.  Upload Database\n"
		"7.  Quit\n");
	char buffer[LINE_LEN + 1];
	int ret_code = 0;
	printf("\n> ");
	scanf("%80s", buffer);

	if (!strcmp(buffer, "1")) //List documents
	{
		displayDocuments();
		system("pause");
		return true;
	}

	else if (!strcmp(buffer, "2")) //Download document
	{
		DownloadDocument();
		system("pause");
		return true;
	}

	else if (!strcmp(buffer, "3")) //Upload document
	{
		UploadDocument();
		system("pause");
		return true;
	}

	else if (!strcmp(buffer, "4")) //Delete Document
	{
		DeleteDocument();
		system("pause");
		return true;
	}

	else if (!strcmp(buffer, "5"))
	{
		DownloadDatabase();
		system("pause");
		return true;
	}

	else if (!strcmp(buffer, "6"))
	{
		UploadDatabase();
		system("pause");
		return true;
	}

	else if (!strcmp(buffer, "7"))
	{
		exit(0);
	}

	else if (!strcmp(buffer, ""))
	{
		// Do nothing
	}
	else
	{
		printf("Please select a number from [1-7].\n");
	} // end of command checking
}  // end of main while loop
bool MyGDrive::ConnectionAvailable()
{
	try
	{
		IPHostEntry^ hostInfo = Dns::GetHostByName("microsoft.com");
	}
	catch(...)
	{
		return false;
	}
	return true;
}