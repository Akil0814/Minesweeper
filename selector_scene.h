#pragma once
#include "scene_manager.h"
#include "scene.h"
#include<iostream>

class SelectorScene :public Scene
{
public:
	SelectorScene() = default;

	~SelectorScene() = default;

	void on_enter()
	{


	}
	void on_update() {}
	void on_draw()
	{

	}
	void on_input(const ExMessage& msg) {}
	void on_exit() {}
};