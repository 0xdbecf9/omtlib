#pragma once
#include <Windows.h>
#include "Log.h"

class Memory
{

public:
	Memory(void) {}
	~Memory(void) {}

	void static HookThis(DWORD dwMyFuncOffset, DWORD dwJmpOffset);
	void static MakeJmp(DWORD dwMyFuncOffset, DWORD dwJmpOffset);
	void static SetNop(DWORD dwOffset, int Size);
	void static SetRetn(DWORD dwOffset);
	void static SetRRetn(DWORD dwOffset);
	void static SetByte(DWORD dwOffset, BYTE btValue);
	void static SetBytes(DWORD dwOffset, LPBYTE lpbtValues);
	void static WriteChars(DWORD dwOffset, char* sChars);

};