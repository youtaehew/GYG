#pragma once
void TitleRender();
bool Title();
enum class MENU
{
	FIRST, START,QUIT, END
};
MENU MenuRender();
void InfoRender();
enum class KEY
{
	NONE, UP, DOWN, SPACE
};

KEY KeyController();
void EnterAnimation();
//void ColorWrite(bool Color = false, int number = 0);