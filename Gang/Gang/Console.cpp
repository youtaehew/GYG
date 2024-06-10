#include<Windows.h>
#include "console.h"

void FullScreen()
{
	ShowWindow(GetConsoleWindow(),
		SW_MAXIMIZE);
	::SendMessage(GetConsoleWindow(),
		WM_SYSKEYDOWN
		, VK_RETURN, 0x20000000);
}

void Gotoxy(int _x, int _y)
{
	// �ܼ�â �ڵ�
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	// Ŀ������ ����ü
	COORD Cur = { _x, _y }; // {_x*2,_y}�� �� �ڿ������� �� ����.
	// Ŀ�������Ǽ����ϴ� �Լ�.
	SetConsoleCursorPosition(hOut, Cur);
}

BOOL GotoPos(int _x, int _y)
{
	// �ܼ�â �ڵ�
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	// Ŀ������ ����ü
	COORD Cur = { _x, _y }; // {_x*2,_y}�� �� �ڿ������� �� ����.
	// Ŀ�������Ǽ����ϴ� �Լ�.
	return SetConsoleCursorPosition(hOut, Cur);
}

COORD CursorPos()
{
	CONSOLE_SCREEN_BUFFER_INFO buf;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE)
		, &buf);
	return buf.dwCursorPosition;
}

void CursorVis(bool _vis, DWORD _size)
{
	CONSOLE_CURSOR_INFO curinfo;
	curinfo.dwSize = _size; // Ŀ������ 1~100
	curinfo.bVisible = _vis; // on, off
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE)
		, &curinfo);
}

void SetColor(int _textcolor, int _bgcolor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE)
		, (_bgcolor << 4) | _textcolor);
}

int GetColor()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE)
		, &info);
	int color = info.wAttributes & 0xf;
	return color;
}

void LockResize()
{
	HWND console = GetConsoleWindow();
	if (nullptr != console) // ��� ǥ����
	{
		LONG style = GetWindowLong(console, GWL_STYLE);
		style &= ~WS_MAXIMIZEBOX & ~WS_SIZEBOX;
		SetWindowLong(console, GWL_STYLE, style);
	}
}

COORD GetConsoleResolution()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE)
		, &info);
	short width = info.srWindow.Right - info.srWindow.Left + 1;
	short height = info.srWindow.Bottom - info.srWindow.Top + 1;
	return COORD{ width, height };
}

void SetFontSize(UINT weight, UINT fontx, UINT fonty)
{
	CONSOLE_FONT_INFOEX font;
	font.cbSize = sizeof(font);

	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	GetCurrentConsoleFontEx(hout, false, &font);
	font.FontWeight = weight;
	font.dwFontSize.X = fontx;
	font.dwFontSize.Y = fonty;
	GetCurrentConsoleFontEx(hout, false, &font);
}
