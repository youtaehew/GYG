#include<Windows.h>
#include<vector>
#include "TitleScene.h"
#include "GameMenu.h"
#include "console.h"
#include<fstream>
#include<string>
using std::vector;

int main()
{
	system("title TaengTaengBall | mode con cols=40 lines=25");
	CursorVis(false, 1);
	if (!Title())
		return 0;
	else
	{
		Init();
		while (true) {
			Update();
		    Render();
		}
	}
}