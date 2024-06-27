//#pragma once
//
////맵 크기
//const int MAP_WIDTH = 21;
//const int MAP_HEIGHT = 20;
//
//typedef struct _tagpos
//{
//	int x;
//	int y;
//	bool operator == (const _tagpos& _pos) {
//		if (x == _pos.x && y == _pos.y)
//			return true;
//		else
//			return false;
//	}
//} POS, * PPOS;
//
//typedef struct _tagplayer
//{
//	POS tPos;         //위치
//	POS tNewPos;      //새위치
//	int bombcnt;      //갯수
//	int bombpower;    //파워
//	bool isWallPush;  //벽밀기
//	bool isPushOnOff; // 스위치
//	bool isTrans;     //투명화
//}PLAYER, * PPLAYER;
//
//typedef struct _tagbomb
//{
//	int x;
//	int y;
//	int life;
//	bool isDie;
//}BOOM, * PBOOM;
//enum class OBJ_TYPE {
//	WALL = '0', ROAD, START, GOAL, BOMB, FLASH_BOMB, EXTRA_BOMB, SLIME, PUSH
//};
//
//
//void Init(char _arrMap[MAP_HEIGHT][MAP_WIDTH],
//	PPLAYER _player, PPOS _pStartPos, PPOS _pEndPos);
//#include<vector>
//using std::vector;
//void Render(char _arrMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer, vector<POS>& _boomEffect);
//void Update(char _arrMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer, vector<BOOM>& _vecBomb, vector<POS>& _boomEffect);
//void MoveUpdate(char _arrMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer);
////void FrameSync(unsigned int _Framerate);
//void BoomCreate(char _arrMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer, vector<BOOM>& _vecBomb);
//void UpdateBombs(char _arrMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer, vector<BOOM>& _vecBomb, vector<POS>& _boomEffect);
//void ExplosionBomb(char _arrMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer, POS _bombPos, vector<POS>& _boomEffect);
//void ItemDrop(char _arrMap[MAP_HEIGHT][MAP_WIDTH], POS _pos);
//void Event(vector<BOOM>& _vecBomb);
//bool GetisItem(char _item, PPLAYER _pPlayer);