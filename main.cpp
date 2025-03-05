#include"scene_manager.h"
#include"scene.h"
#include"menu_scene.h"
#include"game_scene.h"
#include"selector_scene.h"
#include"mine.h"
#include"mine_board.h"
#include"button.h"
#include<graphics.h>

ExMessage msg;

IMAGE Menu_background;
IMAGE Menu_Start_Idle;
IMAGE Menu_Start_Hovered;
IMAGE Menu_Start_Pushed;
IMAGE Menu_Setting_Idle;
IMAGE Menu_Setting_Hovered;
IMAGE Menu_Setting_Pushed;

IMAGE MineExplode;
IMAGE MineCover;
IMAGE Num1;
IMAGE Num2;
IMAGE Num3;
IMAGE Num4;
IMAGE Num5;
IMAGE Num6;
IMAGE Num7;
IMAGE Num8;
IMAGE Base;
IMAGE MineMarked;
IMAGE MineFined;
IMAGE MineBase;
IMAGE Bar;
IMAGE Restart_Idle;
IMAGE Restart_Hovered;
IMAGE Restart_Pushed;

Scene* menu_scene = nullptr;
Scene* game_scene = nullptr;
Scene* selector_scene = nullptr;

SceneManager scene_manager;
MineBoard board;
Mine mine;

void LoadResource()
{
	loadimage(&Menu_background, _T("res/Menu_back_ground.png"));
	loadimage(&Menu_Start_Idle, _T("res/Menu_Start_Idle.png"));
	loadimage(&Menu_Start_Hovered, _T("res/Menu_Start_Hovered.png"));
	loadimage(&Menu_Start_Pushed, _T("res/Menu_Start_Pushed.png"));
	loadimage(&Menu_Setting_Idle, _T("res/Menu_Setting_Idle.png"));
	loadimage(&Menu_Setting_Hovered, _T("res/Menu_Setting_Hovered.png"));
	loadimage(&Menu_Setting_Pushed, _T("res/Menu_Setting_Pushed.png"));

	loadimage(&MineExplode, _T("res/MineExplode.png"));
	loadimage(&MineCover, _T("res/MineCover.png"));
	loadimage(&Num1, _T("res/Num1.png"));
	loadimage(&Num2, _T("res/Num2.png"));
	loadimage(&Num3, _T("res/Num3.png"));
	loadimage(&Num4, _T("res/Num4.png"));
	loadimage(&Num5, _T("res/Num5.png"));
	loadimage(&Num6, _T("res/Num6.png"));
	loadimage(&Num7, _T("res/Num7.png"));
	loadimage(&Num8, _T("res/Num8.png"));
	loadimage(&Base, _T("res/Base.png"));
	loadimage(&MineMarked, _T("res/MineMarked.png"));
	loadimage(&MineFined, _T("res/MineFined.png"));
	loadimage(&MineBase, _T("res/MineBase.png"));
	loadimage(&Bar, _T("res/Bar.png"));
	loadimage(&Restart_Idle, _T("res/Restart_Idle.png"));
	loadimage(&Restart_Hovered, _T("res/Restart_Hovered.png"));
	loadimage(&Restart_Pushed, _T("res/Restart_Pushed.png"));
}

int main()
{
	constexpr int FPS = 30;

	LoadResource();
	srand((unsigned int)time(NULL));

	initgraph(1,1);
	BeginBatchDraw();

	menu_scene = new MenuScene();
	game_scene = new GameScene();
	selector_scene = new SelectorScene();

	scene_manager.set_current_scene(menu_scene);

	while (true)
	{
		DWORD frame_start_time = GetTickCount();

		while (peekmessage(&msg))
		{
			scene_manager.on_input(msg);
		}

		scene_manager.on_update();

		cleardevice();

		scene_manager.on_draw();

		FlushBatchDraw();

		DWORD frame_end_time = GetTickCount();
		DWORD frame_delta_time = frame_end_time - frame_start_time;
		if (frame_delta_time < 1000 / FPS)
			Sleep(1000 / FPS - frame_delta_time);
	}

	EndBatchDraw();

	return 0;
}