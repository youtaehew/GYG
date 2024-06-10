#include<Windows.h>
#include<algorithm>
#include "GameLogic.h"
#include <ctime>

void Init()
{

}

void Update()
{

}

void MoveUpdate()
{
	
}

void Render()
{
	
}

void FrameSync(unsigned int _Framerate)
{
	clock_t oldtime = clock();
	clock_t curtime;

	while (true)
	{
		curtime = clock();
		if (curtime - oldtime > 1000 / _Framerate)
		{
			oldtime = curtime;
			break;
		}
	}

}