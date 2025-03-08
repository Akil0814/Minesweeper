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

IMAGE Setting_background;
IMAGE Setting_Back_Idle;
IMAGE Setting_Back_Hovered;
IMAGE Setting_Back_Pushed;

IMAGE Easy_Idle;
IMAGE Easy_Hovered;
IMAGE Easy_Pushed;
IMAGE Normal_Idle;
IMAGE Normal_Hovered;
IMAGE Normal_Pushed;
IMAGE Hard_Idle;
IMAGE Hard_Hovered;
IMAGE Hard_Pushed;
IMAGE Expert_Idle;
IMAGE Expert_Hovered;
IMAGE Expert_Pushed;
IMAGE Custom_Idle;
IMAGE Custom_Hovered;
IMAGE Custom_Pushed;
IMAGE Custom_row;
IMAGE Custom_col;
IMAGE Custom_mine;
IMAGE Custom_row_Editing;
IMAGE Custom_col_Editing;
IMAGE Custom_mine_Editing;

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
IMAGE MineWin;
IMAGE MineBase;
IMAGE Bar;

IMAGE Restart_Idle;
IMAGE Restart_Hovered;
IMAGE Restart_Pushed;
IMAGE Exit_Idle;
IMAGE Exit_Hovered;
IMAGE Exit_Pushed;

Scene* menu_scene = nullptr;
Scene* game_scene = nullptr;
Scene* selector_scene = nullptr;

SceneManager scene_manager;
MineBoard board;
Mine mine;

void LoadResource()
{
	loadimage(&Setting_background, _T("res/Setting_background.png"));
	loadimage(&Setting_Back_Idle, _T("res/Setting_Back_Idle.png"));
	loadimage(&Setting_Back_Hovered, _T("res/Setting_Back_Hovered.png"));
	loadimage(&Setting_Back_Pushed, _T("res/Setting_Back_Pushed.png"));

	loadimage(&Setting_Back_Idle, _T("res/Setting_Back_Idle.png"));
	loadimage(&Setting_Back_Hovered, _T("res/Setting_Back_Hovered.png"));
	loadimage(&Setting_Back_Pushed, _T("res/Setting_Back_Pushed.png"));

	loadimage(&Easy_Idle, _T("res/Easy_Idle.png"));
	loadimage(&Easy_Hovered, _T("res/Easy_Hovered.png"));
	loadimage(&Easy_Pushed, _T("res/Easy_Pushed.png"));

	loadimage(&Normal_Idle, _T("res/Normal_Idle.png"));
	loadimage(&Normal_Hovered, _T("res/Normal_Hovered.png"));
	loadimage(&Normal_Pushed, _T("res/Normal_Pushed.png"));

	loadimage(&Hard_Idle, _T("res/Hard_Idle.png"));
	loadimage(&Hard_Hovered, _T("res/Hard_Hovered.png"));
	loadimage(&Hard_Pushed, _T("res/Hard_Pushed.png"));

	loadimage(&Expert_Idle, _T("res/Expert_Idle.png"));
	loadimage(&Expert_Hovered, _T("res/Expert_Hovered.png"));
	loadimage(&Expert_Pushed, _T("res/Expert_Pushed.png"));

	loadimage(&Custom_Idle, _T("res/Custom_Idle.png"));
	loadimage(&Custom_Hovered, _T("res/Custom_Hovered.png"));
	loadimage(&Custom_Pushed, _T("res/Custom_Pushed.png"));
	loadimage(&Custom_row, _T("res/Custom_row.png"));
	loadimage(&Custom_col, _T("res/Custom_col.png"));
	loadimage(&Custom_mine, _T("res/Custom_mine.png"));
	loadimage(&Custom_row_Editing, _T("res/Custom_row_Editing.png"));
	loadimage(&Custom_col_Editing, _T("res/Custom_col_Editing.png"));
	loadimage(&Custom_mine_Editing, _T("res/Custom_mine_Editing.png"));

	loadimage(&Menu_background, _T("res/Menu_back_ground.png"));
	loadimage(&Menu_Start_Idle, _T("res/Menu_Start_Idle.png"));
	loadimage(&Menu_Start_Hovered, _T("res/Menu_Start_Hovered.png"));
	loadimage(&Menu_Start_Pushed, _T("res/Menu_Start_Pushed.png"));
	loadimage(&Menu_Setting_Idle, _T("res/Menu_Setting_Idle.png"));
	loadimage(&Menu_Setting_Hovered, _T("res/Menu_Setting_Hovered.png"));
	loadimage(&Menu_Setting_Pushed, _T("res/Menu_Setting_Pushed.png"));

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
	loadimage(&MineExplode, _T("res/MineExplode.png"));
	loadimage(&MineWin, _T("res/MineWin.png"));

	loadimage(&Bar, _T("res/Bar.png"));
	loadimage(&MineBase, _T("res/MineBase.png"));
	loadimage(&Restart_Idle, _T("res/Restart_Idle.png"));
	loadimage(&Restart_Hovered, _T("res/Restart_Hovered.png"));
	loadimage(&Restart_Pushed, _T("res/Restart_Pushed.png"));
	loadimage(&Exit_Idle, _T("res/Exit_Idle.png"));
	loadimage(&Exit_Hovered, _T("res/Exit_Hovered.png"));
	loadimage(&Exit_Pushed, _T("res/Exit_Pushed.png"));
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