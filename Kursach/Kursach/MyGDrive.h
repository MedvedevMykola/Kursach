#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include "Exception.h"
#include "ingoogle.h"

#define LINE_LEN 100


class MyGDrive : public GDrive
{
public:
	MyGDrive();
	virtual int FireSSLServerAuthentication(GDriveSSLServerAuthenticationEventParams *e)
	{
		e->Accept = true;
		return 0;
	}
	char* Auth();
	void Auth1(char*);
	void Void();            //������� ��� ����� �� ������ ��� �������(�� ������� �����)
	void displayDocuments();//������ ��������� GoogleDrive(�� �������)
	void DownloadDocument();//����� �������� � GoogleDrive(�� �������)
	void UploadDocument();  //������� �������� � GoogleDrive(�� �������)
	void DeleteDocument();  //������� �������� � GoogleDrive(�� �������)
	void DownloadDatabase();//����� ���� ����� � GoogleDrive
	void UploadDatabase();  //������� ���� ����� � GoogleDrive
	bool Menu();            //���� ��� ������ � GoogleDrive
	bool ConnectionAvailable();
};
