#pragma once
#include "scene_manager.h"
#include "scene.h"
#include"button.h"

#include<iostream>
using namespace std;

extern IMAGE img_menu_background;
extern IMAGE img_menu_setting;
extern IMAGE Menu_Start_Idle;

extern SceneManager scene_manager;

class MenuScene :public Scene
{
public:
	MenuScene() = default;

	~MenuScene() = default;

	void on_enter()
	{
		WINDOW_WIDTH = img_menu_background.getwidth();
		WINDOW_HEIGHT = img_menu_background.getheight();
		initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);

	}

	void on_update(){}

	void on_draw()
	{
		putimage(0, 0, &img_menu_background);
	}

	void on_input(const ExMessage& msg)
	{
		if (msg.message == WM_LBUTTONDOWN)
		{
			int x = msg.x;
			int y = msg.y;
			
			if(true)
			scene_manager.switch_to(SceneManager::SceneType::Game);

			//if ()
			//scene_manager.switch_to(SceneManager::SceneType::Selector);
		}
	}

	void on_exit(){}

private:
	Button setting;
	Button start;
};
