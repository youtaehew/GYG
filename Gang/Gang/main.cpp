#include<Windows.h>
#include "GameMenu.h"
#include "TitleScene.h"
#include "Console.h"
#include<fstream>
#include <string>

int main() {
	system("title TaengTaengBall | mode con cols=41 lines=25");
	CursorVis(false, 1);
	if (!Title()) {
		return 0;
	}
	else {
		Init();
		while (true) {
			Update();
		}
	}
}