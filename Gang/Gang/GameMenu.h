#pragma once

const int MIN_Width = 4;
const int MAX_Width = 30;
const int MIN_Height = 3;
const int MAX_Height = 19;

typedef struct _tagpos
{
	int x;
	int y;
	bool operator == (const _tagpos& _pos) {
		if (x == _pos.x && y == _pos.y)
			return true;
		else
			return false;
	}
} POS, * PPOS;

enum class Stage
{
	first,
	second,
	third,
	fourth,
	fifth,
	sixth,
	seventh,
	eighth,
	ninth,
};

void Init();
void Render();
void Update();
void MoveUpdate();
void FrameSync(unsigned int _Framerate);
void MenuMovePos(int data, bool isPlus = true);
void DrawBox();
