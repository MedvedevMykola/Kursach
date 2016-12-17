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
	void displayDocuments();
	void DownloadDatabase();
	void UploadDatabase();
	bool Menu();
};
