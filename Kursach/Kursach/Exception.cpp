#include "Exception.h"
#define _CRT_SECURE_NO_WARNINGS


CException::CException(char* message) {
	msg = new char[strlen(message) + 1];
	strcpy(msg, message);
}

CException::~CException() {
	delete[] msg;
	msg = nullptr;
}

void CException::show(void) {
	printf("%s\n", msg);
}