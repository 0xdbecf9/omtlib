#pragma once
#include <Windows.h>
#include <iostream>

class Log
{

public:
	static void alloc();
	static void msg(const char* Format, ...);

};

