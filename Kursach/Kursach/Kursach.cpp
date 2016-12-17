#include "stdafx.h"
#include "ingoogle.h"


using namespace std;
class MyGDrive : public GDrive
{
public:

	virtual int FireSSLServerAuthentication(GDriveSSLServerAuthenticationEventParams *e)
	{
		e->Accept = true;
		return 0;
	}
};

MyGDrive gdrive1;

int main()
{
	OAuth oauth1;
	oauth1.SetClientId("157623334268-pdch1uarb3180t5hq2s16ash9ei315j0.apps.googleusercontent.com");
	oauth1.SetClientSecret("k4NSk71U-p2sU8lB8Qv3G24R");
	oauth1.SetServerTokenURL("https://accounts.google.com/o/oauth2/token");
	oauth1.SetServerAuthURL("https://accounts.google.com/o/oauth2/auth");
	oauth1.SetAuthorizationScope("https://www.googleapis.com/auth/drive");
	gdrive1.SetAuthorization(oauth1.GetAuthorization());
	return 0;
}
