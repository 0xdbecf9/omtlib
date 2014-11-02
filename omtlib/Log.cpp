#include "Log.h"

void Log::alloc()
{
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
}

void Log::msg(const char* Format, ...)
{
	char buffer[256];
	va_list args;
	va_start(args, Format);
	vsprintf(buffer, Format, args);
	va_end(args);

	printf("%s\n", buffer);
}