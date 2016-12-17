#include "stdafx.h"
#include "MyGDrive.h"


using namespace std;

MyGDrive::MyGDrive() : GDrive()
{
	OAuth oauth1;
	oauth1.SetClientId("157623334268-pdch1uarb3180t5hq2s16ash9ei315j0.apps.googleusercontent.com");
	oauth1.SetClientSecret("k4NSk71U-p2sU8lB8Qv3G24R");
	oauth1.SetServerTokenURL("https://accounts.google.com/o/oauth2/token");
	oauth1.SetServerAuthURL("https://accounts.google.com/o/oauth2/auth");
	oauth1.SetAuthorizationScope("https://www.googleapis.com/auth/drive");
	SetAuthorization(oauth1.GetAuthorization());
	int ret_code = oauth1.GetLastErrorCode();
	if (ret_code)
		throw Exception("Google error");
}

void MyGDrive::displayDocuments()
{
	SetResourceIndex(-1); //Clear the documents collection
	int ret_code = ListResources();
	if (ret_code)
		throw Exception("Google error");

	printf("%-4.1s%-42.40s%-22.20s%-32.30s\n\n", "#", "Title", "Author", "Modified Data");

	for (int i = 0;i<GetResourceCount();i++)
	{
		SetResourceIndex(i);
		printf("%-4.1d%-42.40s%-22.20s%-32.30s\n", i, GetResourceTitle(), GetResourceOwners(), GetResourceModifiedDate());
	}
	return;
}

void MyGDrive::displayDocuments1()
{
	SetResourceIndex(-1); //Clear the documents collection
	int ret_code = ListResources();
	if (ret_code)
		throw Exception("Google error");
	remove("database.dat");
	char* str = "database.dat";
	int data = -1;
	for (int i = 0;i<GetResourceCount();i++)
	{
		SetResourceIndex(i);
		if (!strcmp(str, GetResourceTitle())) data = i;
	}
	SetResourceIndex(data);
	char buffer[LINE_LEN + 1]="database.dat";
	SetLocalFile(buffer);
	ret_code = DownloadFile(""); //Use the default file format
	if (ret_code)
		throw Exception("Google error");

	printf("\n Download Successful\n");
	return;
}

bool MyGDrive::Menu()
{
	system("cls");
	printf("Type ? to select this menu, a number 1-5 to select the following choices:\n"
		"1.  List Documents\n"
		"2.  Download Document\n"
		"3.  Upload Document\n"
		"4.  Delete Document\n"
		"5.  My Option\n"
		"6.  Quit\n");
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
				throw Exception("Google error");

			printf("\n Download Successful\n");
			system("pause");
			return true;
		}

		else if (!strcmp(buffer, "3")) //Upload document
		{
			printf("\nLocal File: ");
			scanf("%80s", buffer);

			SetResourceIndex(-1);
			SetLocalFile(buffer);

			printf("Name of New File on Server: ");
			scanf("%80s", buffer);
			UploadFile(buffer);
			ret_code = GetLastErrorCode();

			if (ret_code)
				throw Exception("Google error");

			displayDocuments();
			system("pause");
			return true;
		}

		else if (!strcmp(buffer, "4")) //Delete Document
		{
			printf("\nDocument Number: ");
			scanf("%80s", buffer);
			SetResourceIndex(atoi(buffer));

			ret_code = DeleteResource();

			if (ret_code)
				throw Exception("Google error");

			displayDocuments();
			system("pause");
			return true;
		}

		else if (!strcmp(buffer, "5"))
		{
			displayDocuments1();
			system("pause");
			return true;
		}
		else if (!strcmp(buffer, "6"))
		{
			exit(0);
		}

		else if (!strcmp(buffer, ""))
		{
			// Do nothing
		}
		else
		{
			printf("Please select a number from [1-5].\n");
		} // end of command checking
	}  // end of main while loop
