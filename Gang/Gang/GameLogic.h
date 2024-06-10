#pragma once
#include<vector>

const int MAP_WIDTH = 21;
const int MAP_HEIGHT = 20;
void Init();
void Update();
void MoveUpdate();
void Render();
void FrameSync(unsigned int _Framerate);