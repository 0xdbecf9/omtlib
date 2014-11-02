#include "CMStarterCore.h"

void CMStarterCore::run(char* sMapName)
{
	HANDLE hMap;
    hMap = CreateFileMappingA((HANDLE)MAXDWORD, NULL, PAGE_READWRITE, 0, 300, sMapName);

	char* pBuffer;
    pBuffer = (char*)MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS, 0, 0, 300);

	char sData[] = "OMT-PLAYER|00000000";
	strcpy(pBuffer, sData);

	// Done!
	Log::msg("[CMStarterCore] # Bypassed - mapped at: %s", sMapName);
}
