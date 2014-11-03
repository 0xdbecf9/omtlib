#pragma once
#include <Windows.h>
#include "Log.h"
#include "Defines.h"
#include "Memory.h"
#include "CMStarterCore.h"

char unknown(int ptr, ...);
int unknown2(int ptr, ...);

extern "C" __declspec( dllexport ) int AcquireBasicHWInfo(int a1);
extern "C" __declspec( dllexport ) int AcquireBasicOSInfo(int a1);
extern "C" __declspec( dllexport ) LPCWSTR AcquirePlain();
extern "C" __declspec( dllexport ) int AcquireUMID(int a1);
extern "C" __declspec( dllexport ) int ExtractPII(int a1);
extern "C" __declspec( dllexport ) int RegistPII(int a1);

class MU10513
{

public:
	MU10513() {}
	~MU10513() {}
	void run();

private:
	bool isValid();
	void fixIt();

};

namespace HOOKS10513 {

char LoadWZRegPII(void *ptr);
int WINAPI LoginRequest(void *ptr, void *a2, void *Src);

}