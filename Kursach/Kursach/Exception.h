#pragma once
#include <cstdio>
#include <string.h>


class Exception {
private:
	char* msg;
public:
	Exception(char* message);
	~Exception();

	void show(void);
};