#pragma once
#include <Windows.h>
#include "Log.h"
#include "Defines.h"
#include "Memory.h"
#include "CMStarterCore.h"

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