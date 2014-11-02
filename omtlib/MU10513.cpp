#include "MU10513.h"

void MU10513::run()
{
	DWORD oldProtect;
	VirtualProtect(LPVOID(0x400000), 11218432, PAGE_EXECUTE_READWRITE, &oldProtect);

	if(this->isValid() == false)
	{
		MessageBoxA(NULL, "Main validation failed!", "Error", MB_OK);
		exit(1);
	}

	if(DEBUG == true)
	{
		Log::alloc();
		Log::msg("### Global Mu Online 1.05.13 Debug Mode ###\n");
	}

	CMStarterCore cmstartercore;
	cmstartercore.run(CMSTARTERCORE);

	this->fixIt();
}

bool MU10513::isValid()
{
	// Client validation
	if(strcmp((char*)0x0101DC3C, "MU Auto Update") != 0)
	{
		return false;
	}

	return true;
}

void MU10513::fixIt()
{
	// FIXING: Mu.exe
	BYTE bytes_jump[] = {0xE9, 0x8B, 0x00, 0x00, 0x00, 0x90};
	Memory::SetBytes(0x004D908A, bytes_jump);

	Memory::SetByte(0x004D902F, 0xEB);

	// FIXING: gg init error
	Memory::SetBytes(0x004D950D, bytes_jump);
	
	Memory::SetByte(0x00A2071C, 0xEB); // MessageBox

	// FIXING: Resource Guard files check..
	Memory::SetByte(0x004DC381, 0xEB);
	Memory::SetByte(0x0062D0B2, 0xEB);
	Memory::SetByte(0x0062D1CE, 0xEB);

	// FIXING: nProtect Error
	Memory::SetNop(0x004D768B, 2); // Closing main
	Memory::SetNop(0x004D76F7, 5); // MessageBoxA
	Memory::SetNop(0x004D76FC, 5); // nProtect Tick

	// FIXING: WZRegPII.dll load
	//Memory::HookThis(0x006D9D57, (DWORD)&(HOOKS10513::LoadWZRegPII));
	//Memory::HookThis(0x004D7873, (DWORD)&(HOOKS10513::LoginRequest));
}

// ===================================================== //

namespace HOOKS10513 {

char LoadWZRegPII(void *ptr)
{
	std::cout << "[LoadWZRegPII] # Bypassed" << std::endl;
	return 0;
}

int WINAPI LoginRequest(void *ptr, void *a2, void *Src)
{
	std::cout << "[LoginRequest] # Handled" << std::endl;
	std::cout << "[LoginReques]t # a2: " << (char*)a2 << " Src: " << (char*)Src << std::endl;
	return 3; // 1 - OK, 2 - Bad userName, 3 - Bad userPassword, 5 - Connection Error
}

} // END NAMESPACE