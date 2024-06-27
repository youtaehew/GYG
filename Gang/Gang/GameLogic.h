#pragma once
#include<vector>
typedef struct _tagpos
{
	int x;
	int y;
	bool operator ==(const _tagpos& _pos)
	{
		if (x == _pos.x && y == _pos.y)
			return true;
		else
			return false;
	}

}POS, * PPOS;

typedef struct _tagplayer
{
	POS tPos;         
	POS tNewPos;      
	int bombcnt;      
	int bombpower;    
	bool isWallPush;  
	bool isPushOnOff;
	bool isTrans;     
}PLAYER, * PPLAYER;
enum class OBJ_TYPE
{
	AIR = '0', BLOCK, STAR, SPINE, JUMP, ICE
};
const int MAP_WIDTH = 21;
const int MAP_HEIGHT = 20;
void Init();
void Update();
void MoveUpdate();
void Render();
void FrameSync(unsigned int _Framerate);