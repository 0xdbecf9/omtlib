#include "Memory.h"

void Memory::HookThis(DWORD dwJmpOffset, DWORD dwMyFuncOffset)
{
	*(DWORD*)(dwJmpOffset + 1) = dwMyFuncOffset-(dwJmpOffset+5);

	Log::msg("> Hook at 0x%p", dwJmpOffset);
}

void Memory::MakeJmp(DWORD dwJmpOffset, DWORD dwMyFuncOffset)
{
	*(BYTE*)(dwJmpOffset) = 0xE8;
	*(DWORD*)(dwJmpOffset + 1) = dwMyFuncOffset-(dwJmpOffset+5);

	Log::msg("> Jmp at 0x%p", dwJmpOffset);
}

void Memory::SetNop(DWORD dwOffset, int Size)
{
	for(int n=0; n < Size; n++)
	{
		*(BYTE*)(dwOffset+n) = 0x90;
	}

	Log::msg("> Nop at 0x%p size: %d", dwOffset, Size);
}

void Memory::SetRetn(DWORD dwOffset)
{
	*(BYTE*)(dwOffset) = 0xC3;

	Log::msg("> Retn at 0x%p", dwOffset);
}

void Memory::SetRRetn(DWORD dwOffset)
{
	*(BYTE*)(dwOffset)=0xC3;
	*(BYTE*)(dwOffset+1)=0x90;
	*(BYTE*)(dwOffset+2)=0x90;
	*(BYTE*)(dwOffset+3)=0x90;
	*(BYTE*)(dwOffset+4)=0x90;

	Log::msg("> RRetn at 0x%p size: %d", dwOffset);
}

void Memory::SetByte(DWORD dwOffset, BYTE btValue)
{
	*(BYTE*)(dwOffset) = btValue;

	Log::msg("> Byte set at 0x%p to: 0x%X", dwOffset, btValue);
}

void Memory::SetBytes(DWORD dwOffset, LPBYTE lpbtValues)
{
	for(int i=0; i < sizeof(lpbtValues); i++)
	{
		*(BYTE*)(dwOffset+i) = lpbtValues[i];
	}

	Log::msg("> Bytes set at 0x%p size: %d", dwOffset, sizeof(lpbtValues));
}

void Memory::WriteChars(DWORD dwOffset, char* sChars)
{
	strcpy((char*)dwOffset, sChars);

	Log::msg("> Chars write at 0x%p chars: %s", dwOffset, sChars);
}