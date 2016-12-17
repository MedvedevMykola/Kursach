#include "stdafx.h"
#include "MyGDrive.h"
#include "Exception.h"


using namespace std;

int main()
{

	try
	{
		MyGDrive gdrive1;
		while (gdrive1.Menu());
	}
	catch (Exception& excection) {
		excection.show();
		system("pause");
	}
	return 0;

}
