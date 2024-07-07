#pragma once
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
class Sound
{
public:
	static void playSound(const char* soundFile);
};

