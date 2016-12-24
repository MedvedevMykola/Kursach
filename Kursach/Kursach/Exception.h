#pragma once
#include <cstdio>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS


class CException {
private:
	char* msg;
public:
	CException(char* message);
	~CException();

	void show(void);
};