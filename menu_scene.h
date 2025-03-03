#pragma once
#include "scene_manager.h"
#include "scene.h"
#include<iostream>

extern IMAGE img_menu_background;
extern IMAGE img_menu_setting;
extern IMAGE img_menu_start;

extern SceneManager scene_manager;

class MenuScene :public Scene
{
public:
	MenuScene() = default;

	~MenuScene() = default;

	void on_enter()
	{
		initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);

		pos_button_start_x = (img_menu_background.getwidth() - img_menu_start.getwidth()) / 2;
		pos_button_start_y = (img_menu_background.getheight() - img_menu_start.getheight()) / 2;
		pos_button_start_x_end = pos_button_start_x + img_menu_start.getwidth();
		pos_button_start_y_end = pos_button_start_y + img_menu_start.getheight();

		pos_button_setting_x = pos_button_start_x;
		pos_button_setting_y = pos_button_start_y + img_menu_start.getheight();
		pos_button_setting_x_end = pos_button_setting_x + img_menu_setting.getwidth();
		pos_button_setting_y_end = pos_button_setting_y + img_menu_setting.getheight();

	}

	void on_update(){}

	void on_draw()
	{
		putimage(0, 0, &img_menu_background);
		putimage(pos_button_start_x, pos_button_start_y, &img_menu_start);
		putimage(pos_button_setting_x, pos_button_setting_y, &img_menu_setting);
	}

	void on_input(const ExMessage& msg)
	{
		if (msg.message == WM_LBUTTONDOWN)
		{
			int x = msg.x;
			int y = msg.y;
			
			if(msg.x >= pos_button_start_x&&
			   msg.x <= pos_button_start_x_end&&
			   msg.y >= pos_button_start_y&&
			   msg.y >= pos_button_start_y_end)
			scene_manager.switch_to(SceneManager::SceneType::Game);

			if (msg.x >= pos_button_setting_x &&
				msg.x <= pos_button_setting_x_end &&
				msg.y >= pos_button_setting_y &&
				msg.y >= pos_button_setting_y_end)
			scene_manager.switch_to(SceneManager::SceneType::Selector);
		}
	}

	void on_exit(){}

private:
	int pos_button_start_x=0;
	int pos_button_start_y=0;
	int pos_button_start_x_end=0;
	int pos_button_start_y_end=0;

	int pos_button_setting_x=0;
	int pos_button_setting_y=0;
	int pos_button_setting_x_end=0;
	int pos_button_setting_y_end=0;

};
