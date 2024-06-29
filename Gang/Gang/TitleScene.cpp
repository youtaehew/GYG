#include <iostream>
#include <Windows.h>
#include <fcntl.h>
#include <conio.h>
#include <io.h>
#include "TitleScene.h"
#include "console.h"
using namespace std;

string TitleText[2] = { "게임 시작", "게임 종료" };
int x;
int y;
void TitleRender() {
	int prevMode = _setmode(_fileno(stdout), _O_U16TEXT);
	int line= 0;
	SetColor((int)COLOR::YELLOW);
	Gotoxy(1, line++);
	wcout << L"$$$$$$$$\\                            " << endl;
	Gotoxy(1, line++);
	wcout << L"\\__$$  __|                           " << endl;
	Gotoxy(1, line++);
	wcout << L"   $$ | $$$$$$\\  $$$$$$$\\   $$$$$$\\  " << endl;
	Gotoxy(1, line++);
	wcout << L"   $$ | \\____$$\\ $$  __$$\\ $$  __$$\\ " << endl;
	Gotoxy(1, line++);
	wcout << L"   $$ | $$$$$$$ |$$ |  $$ |$$ /  $$ |" << endl;
	Gotoxy(1, line++);
	wcout << L"   $$ |$$  __$$ |$$ |  $$ |$$ |  $$ |" << endl;
	Gotoxy(1, line++);
	wcout << L"   $$ |\\$$$$$$$ |$$ |  $$ |\\$$$$$$$ |" << endl;
	Gotoxy(1, line++);
	wcout << L"   \\__| \\_______|\\__|  \\__| \\____$$ |" << endl;
	Gotoxy(1, line++);
	wcout << L"                           $$\\   $$ |" << endl;
	Gotoxy(1, line++);
	wcout << L"                           \\$$$$$$  |" << endl;
	Gotoxy(1, line++);
	wcout << L"                            \\______/ " << endl;
	Gotoxy(1, line++);
	
	line--;
	SetColor((int)COLOR::WHITE);
	Gotoxy(1, line++);
	wcout << L"$$$$$$$\\   $$$$$$\\  $$\\       $$\\       " << endl;
	Gotoxy(1, line++);
	wcout << L"$$  __$$\\ $$  __$$\\ $$ |      $$ |      " << endl;
	Gotoxy(1, line++);
	wcout << L"$$ |  $$ |$$ /  $$ |$$ |      $$ |      " << endl;
	Gotoxy(1, line++);
	wcout << L"$$$$$$$\\ |$$$$$$$$ |$$ |      $$ |      " << endl;
	Gotoxy(1, line++);
	wcout << L"$$  __$$\\ $$  __$$ |$$ |      $$ |      " << endl;
	Gotoxy(1, line++);
	wcout << L"$$ |  $$ |$$ |  $$ |$$ |      $$ |      " << endl;
	Gotoxy(1, line++);
	wcout << L"$$$$$$$  |$$ |  $$ |$$$$$$$$\\ $$$$$$$$\\ " << endl;
	Gotoxy(1, line++);
	wcout << L"\\_______/ \\__|  \\__|\\________|\\________|" << endl;

	int curmode = _setmode(_fileno(stdout), prevMode);
}

bool Title()
{
	/*while (true)
	{*/
	TitleRender();
	MENU eMenu = MenuRender();
	switch (eMenu)
	{
	case MENU::START:
		//EnterAnimation();
		return true;
		break;
	case MENU::QUIT:
		return false;
		break;
	}
	//}
}


MENU MenuRender()
{
	COORD resolution = GetConsoleResolution();
	x = 8;
	y = 20;


	for (int i = 0; i < 2; i++)
	{
		GotoxyDouble(x, y + i);
		cout << TitleText[i];
	}

	MENU goingMenu = MENU::START;
	while (true)
	{
		switch (KeyController())
		{
		case KEY::UP:
		{
			if ((int)goingMenu - 1 == (int)MENU::FIRST) continue;
			goingMenu = MENU(static_cast<int>(goingMenu) - 1);
			GotoxyDouble(x - 2, y);
			cout << " ";
			GotoxyDouble(x - 2, --y);
			cout << ">";
			Sleep(100);
			break;
		}
		case KEY::DOWN:
		{
			if ((int)goingMenu + 1 == (int)MENU::END) continue;
			goingMenu = MENU(static_cast<int>(goingMenu) + 1);
			GotoxyDouble(x - 2, y);
			cout << " ";
			GotoxyDouble(x - 2, ++y);
			cout << ">";
			Sleep(100);
			break;
		}
		 case KEY::SPACE:
		 {
			return goingMenu;
			break;
		 }
		}
	}
}



KEY KeyController()
{
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		Sleep(100);
		return KEY::SPACE;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		Sleep(100);
		return KEY::UP;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		Sleep(100);
		return KEY::DOWN;
	}
	return KEY::NONE;
}

