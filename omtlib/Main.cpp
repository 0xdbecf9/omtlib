#include "Main.h"
#include "MU10513.h"

extern "C" BOOL __stdcall DllMain(HMODULE hDLL, DWORD dwReason, LPVOID lpReserved)
{
	switch(dwReason)
	{
		case DLL_PROCESS_ATTACH:
			DisableThreadLibraryCalls(hDLL);
			main();
			break;

		case DLL_PROCESS_DETACH:
			if(DEBUG == true)
			{
				MessageBoxA(NULL, "Application is closing. You can read debug log now.", "Debug Mode", MB_OK);
			}
			break;
	}

	return true;
}

void main()
{
	char sMainVersion[8];
	GetPrivateProfileStringA("LOGIN", "Version", "0.00.00", sMainVersion, 8, CONFIGINI);
	
	if(strcmp(sMainVersion, "1.05.13") == 0)
	{
		MU10513 client;
		client.run();
	}
	else
	{
		MessageBoxA(NULL, "Unsupported version!", "Error", MB_OK);
		exit(1);
	}
}