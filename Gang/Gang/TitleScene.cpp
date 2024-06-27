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

	/*wcout << endl;
	wcout << L"$$$$$$$$\\                                   $$$$$$$$\\                                      $$$$$$$\\            $$\\ $$\\ " << endl;
	wcout << L"\\__$$  __|                                  \\__$$  __|                                     $$  __$$\\           $$ |$$ |" << endl;
	wcout << L"   $$ | $$$$$$\\   $$$$$$\\  $$$$$$$\\   $$$$$$\\  $$ | $$$$$$\\   $$$$$$\\  $$$$$$$\\   $$$$$$\\  $$ |  $$ | $$$$$$\\  $$ |$$ |" << endl;
	wcout << L"   $$ | \\____$$\\ $$  __$$\\ $$  __$$\\ $$  __$$\\ $$ | \\____$$\\ $$  __$$\\ $$  __$$\\ $$  __$$\\ $$$$$$$\\ | \\____$$\\ $$ |$$ |" << endl;
	wcout << L"   $$ | $$$$$$$ |$$$$$$$$ |$$ |  $$ |$$ /  $$ |$$ | $$$$$$$ |$$$$$$$$ |$$ |  $$ |$$ /  $$ |$$  __$$\\  $$$$$$$ |$$ |$$ |" << endl;
	wcout << L"   $$ |$$  __$$ |$$   ____|$$ |  $$ |$$ |  $$ |$$ |$$  __$$ |$$   ____|$$ |  $$ |$$ |  $$ |$$ |  $$ |$$  __$$ |$$ |$$ |" << endl;
	wcout << L"   $$ |\\$$$$$$$ |\\$$$$$$$\\ $$ |  $$ |\\$$$$$$$ |$$ |\\$$$$$$$ |\\$$$$$$$\\ $$ |  $$ |\\$$$$$$$ |$$$$$$$  |\\$$$$$$$ |$$ |$$ |" << endl;
	wcout << L"   \\__| \\_______| \\_______|\\__|  \\__| \\____$$ |\\__| \\_______| \\_______|\\__|  \\__| \\____$$ |\\_______/  \\_______|\\__|\\__|" << endl;
	wcout << L"                                     $$\\   $$ |                                  $$\\   $$ |                            " << endl;
	wcout << L"                                     \\$$$$$$  |                                  \\$$$$$$  |                            " << endl;
	wcout << L"                                      \\______/                                    \\______/                             " << endl;*/


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

void InfoRender()
{
	cout << "조작";
	while (true)
	{
		if (KeyController() == KEY::SPACE)
			break;
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

//void EnterAnimation()
//{
//	system("cls");
//	COORD Resolution = GetConsoleResolution();
//	int width = Resolution.X;
//	int height = Resolution.Y;
//	int animtime = 20;
//	for (int i = 0; i < 5; i++)
//	{
//		Gotoxy(0, 0);
//		SetColor((int)COLOR::BLACK, (int)COLOR::WHITE);
//		system("cls");
//		Sleep(animtime);
//
//		Gotoxy(0, 0);
//		SetColor((int)COLOR::WHITE);
//		system("cls");
//		Sleep(animtime);
//	}
//
//	//크로스
//	SetColor((int)COLOR::BLACK, (int)COLOR::WHITE);
//	for (int i = 0; i < width / 2; ++i)
//	{
//		for (int j = 0; j < height; j += 2)
//		{
//			Gotoxy(i * 2, j);
//			cout << "  ";
//		}
//
//		for (int j = 1; j < height; j += 2)
//		{
//			Gotoxy(width - 2 - i * 2, j);
//			cout << "  ";
//		}
//		Sleep(animtime);
//	}
//	SetColor((int)COLOR::WHITE);
//	system("cls");
//}
//
//void ColorWrite(bool Color = false, int number = 0)
//{
//	if (!Color) {
//		for (int i = 0; i < 2; i++)
//		{
//			GotoxyDouble(x, y + i);
//			cout << TitleText[i];
//		}
//	}
//	else {
//		for (int i = 0; i < 2; i++) {
//			if (i == number) {
//				SetColor((int)COLOR::RED);
//			}
//			GotoxyDouble(x, y + i);
//			cout << TitleText[i];
//			if (i == number) {
//				SetColor((int)COLOR::WHITE);
//			}
//		}
//	}
//}
