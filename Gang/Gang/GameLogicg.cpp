//#include <Windows.h>
//#include<mmsystem.h>
//#include<algorithm>
//#include "GameLogic.h"
//#include "console.h"
//#include <fstream>
//#pragma comment(lib, "winmm.lib")
//#undef max;
//#undef min;
//
//void Init(char _arrMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer, PPOS _pStartPos, PPOS _pEndPos)
//{
//	system("title bombman | mode con cols=90 lines=40");
//	CursorVis(false, 1);
//	LockResize();
//	//PlayBgm(TEXT("")) ÀÌ¸§, º¼·ý 10(1%)
//	SetFontSize(FW_BOLD, 20, 20);
//
//	std::fstream readMap("stage.txt");
//	if (readMap.is_open()) {
//		for (int i = 0; i < MAP_HEIGHT; ++i) {
//			//readMap.clear();
//			readMap.getline(_arrMap[i], MAP_WIDTH);
//			if (readMap.fail()) {
//				std::cout << "file error" << endl;
//			}
//		}
//	}
//
//	strcpy_s(_arrMap[0], "21111100000000000000");
//	strcpy_s(_arrMap[1], "00000111111110000000");
//	strcpy_s(_arrMap[2], "00111100000000000000");
//	strcpy_s(_arrMap[3], "00000100000000000000");
//	strcpy_s(_arrMap[4], "00000111111111100000");
//	strcpy_s(_arrMap[5], "00000100000000100000");
//	strcpy_s(_arrMap[6], "00000100000000100000");
//	strcpy_s(_arrMap[7], "00000100000000100000");
//	strcpy_s(_arrMap[8], "00000100000000100000");
//	strcpy_s(_arrMap[9], "00000100000000100000");
//	strcpy_s(_arrMap[10], "00000100000000111100");
//	strcpy_s(_arrMap[11], "00000100000000000000");
//	strcpy_s(_arrMap[12], "00000111111111111100");
//	strcpy_s(_arrMap[13], "00000100000000001103");
//	strcpy_s(_arrMap[14], "00000100000000001001");
//	strcpy_s(_arrMap[15], "00000100000000001111");
//	strcpy_s(_arrMap[16], "00000100000000000000");
//	strcpy_s(_arrMap[17], "00000100000000000100");
//	strcpy_s(_arrMap[18], "00000111111111111100");
//	strcpy_s(_arrMap[19], "00000000000000000000");
//
//	for (int i = 0; i < MAP_HEIGHT; ++i) {
//		for (int j = 0; j < MAP_WIDTH; ++j) {
//			if (_arrMap[i][j] == (char)OBJ_TYPE::START)
//				*_pStartPos = { j,i };
//			else if (_arrMap[i][j] == (char)OBJ_TYPE::GOAL)
//				*_pEndPos = { j,i };
//		}
//	}
//	srand((unsigned int)time(NULL));
//	*_pPlayer = { *_pStartPos, {},1, 1, false, false, false };
//}
//
//void Render(char _arrMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer, vector<POS>& _boomEffect)
//{
//	for (int i = 0; i < MAP_HEIGHT; ++i) {
//
//		for (int j = 0; j < MAP_WIDTH; j++)
//		{
//			if (_pPlayer->tPos.x == j && _pPlayer->tPos.y == i)
//				cout << "¡×";
//			else if (_arrMap[i][j] == (char)OBJ_TYPE::WALL)
//				cout << "¡á";
//			else if (_arrMap[i][j] == (char)OBJ_TYPE::ROAD)
//				cout << "  ";
//			else if (_arrMap[i][j] == (char)OBJ_TYPE::START)
//				cout << "¡Ú";
//			else if (_arrMap[i][j] == (char)OBJ_TYPE::GOAL)
//				cout << "¢Í";
//			else if (_arrMap[i][j] == (char)OBJ_TYPE::BOMB)
//			{
//
//				SetColor((int)COLOR::SKYBLUE);
//				cout << "¢Ä";
//			}
//			else if (_arrMap[i][j] == (char)OBJ_TYPE::FLASH_BOMB)
//			{
//
//				SetColor((int)COLOR::MINT);
//				cout << "¢Å";
//			}
//			else if (_arrMap[i][j] == (char)OBJ_TYPE::EXTRA_BOMB)
//				cout << "¡Ý";
//			else if (_arrMap[i][j] == (char)OBJ_TYPE::SLIME)
//				cout << "¢À";
//			else if (_arrMap[i][j] == (char)OBJ_TYPE::PUSH)
//				cout << "¢É";
//			SetColor((int)COLOR::WHITE);
//		}
//		cout << endl;
//	}
//	cout << "¹æÇâÅ°: ¿òÁ÷ÀÓ" << endl;
//	cout << "Spacebar: ÆøÅº ¼³Ä¡" << endl;
//	cout << "F: Push ¿Â¿ÀÇÁ" << endl;
//
//	COORD Resolution = GetConsoleResolution();
//	int x = Resolution.X / 2;
//	int y = Resolution.Y / 6;
//
//	Gotoxy(x, y);
//	cout << "ÆøÅº ÆÄ¿ö: " << _pPlayer->bombpower;
//	Gotoxy(x, y + 1);
//	cout << "ÆøÅº ÆÄ¿ö: " << _pPlayer->bombcnt;
//	Gotoxy(x, y + 2);
//
//	if (_pPlayer->isPushOnOff)
//		cout << "Çª½Ã ´É·Â: " << "ON " << endl;
//	else
//		cout << "Çª½Ã ´É·Â: " << "OFF " << endl;
//	Gotoxy(x, y + 3);
//	if (_pPlayer->isTrans)
//		cout << "½½¶óÀÓ ´É·Â: " << "ON " << endl;
//	else
//		cout << "½½¶óÀÓ ´É·Â: " << "OFF " << endl;
//
//	if (!_boomEffect.empty())
//	{
//		for (int i = 0; i < _boomEffect.size(); ++i)
//		{
//			int x = _boomEffect[i].x;
//			int y = _boomEffect[i].y;
//			Gotoxy(x * 2, y);
//			SetColor((int)COLOR::LIGHT_RED);
//			cout << "¡Ø";
//			SetColor();
//		}
//		_boomEffect.clear();
//	}
//
//}
//
//void Update(char _arrMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer, vector<BOOM>& _vecBomb, vector<POS>& _boomEffect)
//{
//	MoveUpdate(_arrMap, _pPlayer);
//	if (GetisItem(_arrMap[_pPlayer->tPos.y][_pPlayer->tPos.x], _pPlayer)) {
//		_arrMap[_pPlayer->tPos.y][_pPlayer->tPos.x] = (char)OBJ_TYPE::ROAD;
//	}
//	if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
//		BoomCreate(_arrMap, _pPlayer, _vecBomb);
//	}
//	UpdateBombs(_arrMap, _pPlayer, _vecBomb, _boomEffect);
//
//	if (GetAsyncKeyState('F') & 0x8000) {
//		if (_pPlayer->isWallPush) {
//			_pPlayer->isPushOnOff = !_pPlayer->isPushOnOff;
//		}
//	}
//	FrameSync(60);
//}
//
//void MoveUpdate(char _arrMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer)
//{
//	_pPlayer->tNewPos = _pPlayer->tPos;
//	if (GetAsyncKeyState(VK_UP) && 0x8000)
//	{
//		--_pPlayer->tNewPos.y;
//	}
//	if (GetAsyncKeyState(VK_DOWN) && 0x8000)
//	{
//		++_pPlayer->tNewPos.y;
//	}
//	if (GetAsyncKeyState(VK_RIGHT) && 0x8000)
//	{
//		++_pPlayer->tNewPos.x;
//	}
//	if (GetAsyncKeyState(VK_LEFT) && 0x8000)
//	{
//		--_pPlayer->tNewPos.x;
//	}
//
//
//	_pPlayer->tNewPos.x = std::clamp(_pPlayer->tNewPos.x, 0, MAP_WIDTH - 2);
//	_pPlayer->tNewPos.y = std::clamp(_pPlayer->tNewPos.y, 0, MAP_HEIGHT - 1);
//
//	if (_arrMap[_pPlayer->tNewPos.y][_pPlayer->tNewPos.x] != (char)OBJ_TYPE::WALL) {
//		_pPlayer->tPos = _pPlayer->tNewPos;
//	}
//
//	else if (_pPlayer->isWallPush && _pPlayer->isPushOnOff &&
//		_arrMap[_pPlayer->tNewPos.y][_pPlayer->tNewPos.x] == (char)OBJ_TYPE::WALL) {
//		POS tDiffPos = { _pPlayer->tNewPos.x - _pPlayer->tPos.x, _pPlayer->tNewPos.y - _pPlayer->tPos.y };
//		POS tNextPos = { _pPlayer->tPos.x + tDiffPos.x * 1, _pPlayer->tPos.y + tDiffPos.y * 1 };
//		POS tDoubleNextPos = { _pPlayer->tPos.x + tDiffPos.x * 2, _pPlayer->tPos.y + tDiffPos.y * 2 };
//
//		if (_pPlayer->isTrans && _arrMap[tDoubleNextPos.y][tDoubleNextPos.x] == (char)OBJ_TYPE::WALL)
//			_pPlayer->tPos = _pPlayer->tNewPos;
//		if (_arrMap[tDoubleNextPos.y][tDoubleNextPos.x] == (char)OBJ_TYPE::ROAD) {
//			_arrMap[tNextPos.y][tNextPos.x] = (char)OBJ_TYPE::ROAD;
//			_arrMap[tDoubleNextPos.y][tDoubleNextPos.x] = (char)OBJ_TYPE::WALL;
//			_pPlayer->tPos = _pPlayer->tNewPos;
//		}
//	}
//	else if (_pPlayer->isTrans) {
//		_pPlayer->tPos = _pPlayer->tNewPos;
//	}
//
//}
//
//void FrameSync(unsigned int _Framerate)
//{
//	clock_t oldtime = clock();
//	clock_t curtime;
//
//	while (true) {
//		curtime = clock();
//		if (curtime - oldtime > 1000 / _Framerate) {
//			oldtime = curtime;
//			break;
//		}
//	}
//}
//
//void BoomCreate(char _arrMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer, vector<BOOM>& _vecBomb)
//{
//	if (_pPlayer->bombcnt >= 5) {
//		return;
//	}
//
//	if (_arrMap[_pPlayer->tPos.y][_pPlayer->tPos.x] == (char)OBJ_TYPE::ROAD) {
//		_vecBomb.push_back({ _pPlayer->tPos.x, _pPlayer->tPos.y, 50, false });
//		_arrMap[_pPlayer->tPos.y][_pPlayer->tPos.x] = (char)OBJ_TYPE::BOMB;
//		++_pPlayer->bombcnt;
//	}
//}
//
//void UpdateBombs(char _arrMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer, vector<BOOM>& _vecBomb, vector<POS>& _boomEffect)
//{
//	int boomInterval = 5;
//
//	for (auto& boomitem : _vecBomb) {
//		if (boomitem.isDie)
//			continue;
//
//		--boomitem.life;
//		_arrMap[boomitem.y][boomitem.x]
//			= boomitem.life % boomInterval >= boomInterval / 2 ?
//			(char)OBJ_TYPE::BOMB : (char)OBJ_TYPE::FLASH_BOMB;
//
//		if (boomitem.life <= 0) {
//			boomitem.isDie = true;
//			--_pPlayer->bombcnt;
//			ExplosionBomb(_arrMap, _pPlayer, { boomitem.x, boomitem.y }, _boomEffect);
//		}
//	}
//}
//
//void ExplosionBomb(char _arrMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer, POS _bombPos, vector<POS>& _boomEffect)
//{
//	PlaySound(TEXT("explosion.wav"), NULL, SND_FILENAME | SND_ASYNC);
//	_arrMap[_bombPos.y][_bombPos.x] = (char)OBJ_TYPE::ROAD;
//
//	int bombMinRangeX = std::max(0, _bombPos.x - _pPlayer->bombpower);
//	int bombMaxRangeX = std::min(MAP_WIDTH - 2, _bombPos.x + _pPlayer->bombpower);
//	int bombMaxRangeY = std::min(MAP_HEIGHT - 1, _bombPos.y + _pPlayer->bombpower);
//	int bombMinRangeY = std::max(0, _bombPos.y - _pPlayer->bombpower);
//
//	for (int i = bombMinRangeX; i <= bombMaxRangeX; ++i) {
//		POS newPos = { i, _bombPos.y };
//		if (std::find(_boomEffect.begin(), _boomEffect.end(), newPos) == _boomEffect.end()) {
//			_boomEffect.push_back(newPos);
//			if (_arrMap[_bombPos.y][i] == (char)OBJ_TYPE::WALL)
//				ItemDrop(_arrMap, newPos);
//		}
//	}
//
//	for (int i = bombMinRangeY; i <= bombMaxRangeY; ++i) {
//		POS newPos = { _bombPos.x, i };
//		if (std::find(_boomEffect.begin(), _boomEffect.end(), newPos) == _boomEffect.end()) {
//			_boomEffect.push_back(newPos);
//			if (_arrMap[i][_bombPos.x] == (char)OBJ_TYPE::WALL)
//				ItemDrop(_arrMap, newPos);
//		}
//	}
//}
//
//void ItemDrop(char _arrMap[MAP_HEIGHT][MAP_WIDTH], POS _pos)
//{
//	//È®·üÃ³¸® ºÎºÐ °úÁ¦
//	int randomitem = rand() % 100 + 1;
//	if (randomitem <= 50) {
//		randomitem = rand() % 100 + 1;
//		if (randomitem <= 50) {
//			_arrMap[_pos.y][_pos.x] = (char)OBJ_TYPE::EXTRA_BOMB;
//		}
//		else if (randomitem <= 80) {
//			_arrMap[_pos.y][_pos.x] = (char)OBJ_TYPE::SLIME;
//		}
//		else {
//			_arrMap[_pos.y][_pos.x] = (char)OBJ_TYPE::PUSH;
//		}
//	}
//	else {
//
//		_arrMap[_pos.y][_pos.x] = (char)OBJ_TYPE::ROAD;
//	}
//}
//
//void Event(vector<BOOM>& _vecBomb)
//{
//	vector<BOOM>::iterator iter = _vecBomb.begin();
//	for (; iter != _vecBomb.end();) {
//		if (iter->isDie)
//			iter = _vecBomb.erase(iter);
//		else
//			++iter;
//	}
//}
//
//bool GetisItem(char _item, PPLAYER _pPlayer)
//{
//	if (_item == (char)OBJ_TYPE::EXTRA_BOMB) {
//		_pPlayer->bombpower++;
//		return true;
//	}
//	else if (_item == (char)OBJ_TYPE::PUSH) {
//		_pPlayer->isWallPush = true;
//		return true;
//	}
//	else if (_item == (char)OBJ_TYPE::SLIME) {
//		_pPlayer->isTrans = true;
//		return true;
//	}
//	return false;
//}
//
//
//
//
//
