#include "GameLogic.h"
#include "TitleScene.h"
#include "Console.h"
using namespace std;

int main()
{
	Init();
	if (!Title())
		return 0;
	else
	{

		// ���� ����.
		while (true)
		{
			system("cls");
			Update();
			Gotoxy(0, 0);
			Render();

			FrameSync(60);
		}
	}
}