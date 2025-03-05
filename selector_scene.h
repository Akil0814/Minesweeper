#pragma once
#include "scene_manager.h"
#include "scene.h"
#include<iostream>

extern IMAGE img_setting_background;


class SelectorScene :public Scene
{
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
		putimage(0, 0, &img_setting_background);
	}
	void on_draw()
	{

	}
	void on_input(const ExMessage& msg)
	{

	}
	void on_exit() {}

private:


};