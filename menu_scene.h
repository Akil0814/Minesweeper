#pragma once
#include "scene_manager.h"
#include "scene.h"
#include"button.h"

using namespace std;

extern IMAGE Menu_background;
extern IMAGE Menu_Start_Idle;
extern IMAGE Menu_Start_Hovered;
extern IMAGE Menu_Start_Pushed;
extern IMAGE Menu_Setting_Idle;
extern IMAGE Menu_Setting_Hovered;
extern IMAGE Menu_Setting_Pushed;

extern SceneManager scene_manager;

class MenuScene :public Scene
{
public:
	MenuScene() = default;

	~MenuScene() = default;

	void on_enter()
	{
		WINDOW_WIDTH = Menu_background.getwidth();
		WINDOW_HEIGHT = Menu_background.getheight();
		initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);

		start.set_image(&Menu_Start_Idle, &Menu_Start_Hovered, &Menu_Start_Pushed);
		start.set_top((WINDOW_HEIGHT - start.get_button_height()) / 2);
		start.set_left((WINDOW_WIDTH - start.get_button_width()) / 2);

		setting.set_image(&Menu_Setting_Idle, &Menu_Setting_Hovered, &Menu_Setting_Pushed);
		setting.set_top(start.cheek_top()+ start.get_button_height()+ space_between_button);
		setting.set_left(start.cheek_left());
	}

	void on_update()
	{
		if(start.cheek_is_clicked())
			scene_manager.switch_to(SceneManager::SceneType::Game);
		if (setting.cheek_is_clicked())
			scene_manager.switch_to(SceneManager::SceneType::Selector);
	}

	void on_draw()
	{
		putimage(0, 0, &Menu_background);
		start.draw();
		setting.draw();
	}

	void on_input(const ExMessage& msg)
	{
		start.process_event(msg);
		setting.process_event(msg);
	}

	void on_exit()
	{
		start.reset_click();
		setting.reset_click();
	}

private:
	Button setting;
	Button start;

	int space_between_button = 10;
	bool is_click=false;
};
