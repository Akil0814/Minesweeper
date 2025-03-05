#pragma once
#include "scene_manager.h"
#include "scene.h"
#include"button.h"

#include<iostream>

extern IMAGE img_setting_background;


class SelectorScene :public Scene
{
public:
	enum class Mod
	{
		Easy,
		Normal,
		Hard,
		Expert,
		Custom

	};

public:
	SelectorScene() = default;

	~SelectorScene() = default;

	void on_enter()
	{
		WINDOW_WIDTH = img_setting_background.getwidth();
		WINDOW_HEIGHT = img_setting_background.getheight();
		initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);
	}
	void on_update()
	{
		if (L_button_down)
		{
			L_button_down = false;
		}
		
	}

	void on_draw()
	{
		putimage(0, 0, &img_setting_background);
	}

	void on_input(const ExMessage& msg)
	{
		if (msg.message == WM_LBUTTONDOWN)
		{
			int x = msg.x;
			int y = msg.y;
			L_button_down = true;
		}
	}

	void on_exit(){}

private:
	Button back;

	int x = msg.x;
	int y = msg.y;

	bool L_button_down = false;

};