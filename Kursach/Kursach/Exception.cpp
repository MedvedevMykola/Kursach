#include "stdafx.h"
#include "Exception.h"


Exception::Exception(char* message) {
	msg = new char[strlen(message) + 1];
	strcpy(msg, message);
}

Exception::~Exception() {
	delete[] msg;
	msg = nullptr;
}

void Exception::show(void) {
	printf("%s\n", msg);
}