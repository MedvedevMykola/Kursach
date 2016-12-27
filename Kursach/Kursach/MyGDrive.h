#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
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
	void Void();            //функція яка нічого не робить але потрібна(не питайте навіщо)
	void displayDocuments();//показує документи GoogleDrive(не потрібна)
	void DownloadDocument();//скачує документ з GoogleDrive(не потрібна)
	void UploadDocument();  //вигружає документ в GoogleDrive(не потрібна)
	void DeleteDocument();  //видаляє документ з GoogleDrive(не потрібна)
	void DownloadDatabase();//скачує базу даних з GoogleDrive
	void UploadDatabase();  //вигружає базу даних в GoogleDrive
	bool Menu();            //меню для роботи з GoogleDrive
	bool ConnectionAvailable();
};
