#pragma once
#include "scene_manager.h"
#include "scene.h"
#include"button.h"
#include"mine_board.h"
#include"mine.h"
#include<iostream>

extern IMAGE Setting_background;
extern IMAGE Setting_Back_Idle;
extern IMAGE Setting_Back_Hovered;
extern IMAGE Setting_Back_Pushed;

extern IMAGE Easy_Idle;
extern IMAGE Easy_Hovered;
extern IMAGE Easy_Pushed;
extern IMAGE Normal_Idle;
extern IMAGE Normal_Hovered;
extern IMAGE Normal_Pushed;
extern IMAGE Hard_Idle;
extern IMAGE Hard_Hovered;
extern IMAGE Hard_Pushed;
extern IMAGE Expert_Idle;
extern IMAGE Expert_Hovered;
extern IMAGE Expert_Pushed;

extern MineBoard board;
extern Mine mine;

class SelectorScene :public Scene
{
public:
	enum class MOD
	{
		Easy=0,
		Normal,
		Hard,
		Expert
		//Custom
	};

public:
	SelectorScene() = default;

	~SelectorScene() = default;

	void on_enter()
	{
		WINDOW_WIDTH = Setting_background.getwidth();
		WINDOW_HEIGHT = Setting_background.getheight();
		initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);

		back.set_image(&Setting_Back_Idle, &Setting_Back_Hovered, &Setting_Back_Pushed);
		back.set_left(WINDOW_WIDTH - back.get_button_width() - space_between_button);
		back.set_top(WINDOW_HEIGHT - back.get_button_height() - space_between_button);

		easy.set_image(&Easy_Idle, &Easy_Hovered, &Easy_Pushed);
		easy.set_left(space_between_button);
		easy.set_top(space_between_button);

		normal.set_image(&Normal_Idle, &Normal_Hovered, &Normal_Pushed);
		normal.set_left(space_between_button);
		normal.set_top(space_between_button * 2 + easy.get_button_width());

		hard.set_image(&Hard_Idle, &Hard_Hovered, &Hard_Pushed);
		hard.set_left(space_between_button+easy.get_button_height());
		hard.set_top(space_between_button);

		expert.set_image(&Expert_Idle, &Expert_Hovered, &Expert_Pushed);
		expert.set_left(space_between_button + normal.get_button_height());
		expert.set_top(space_between_button * 2 + hard.get_button_width());

	}
	void on_update()
	{
		if (back.cheek_is_clicked())
		{
			scene_manager.switch_to(SceneManager::SceneType::Menu);
			back.reset_button();
		}
		if (easy.cheek_is_clicked())
		{
			current_mod = MOD::Easy;
			easy.reset_button();

		}
		if (normal.cheek_is_clicked())
		{
			current_mod = MOD::Normal;
			normal.reset_button();

		}
		if (hard.cheek_is_clicked())
		{
			current_mod = MOD::Hard;
			hard.reset_button();

		}
		if (expert.cheek_is_clicked())
		{
			current_mod = MOD::Expert;
			expert.reset_button();

		}
		set_mod();
	}

	void on_draw()
	{
		putimage(0, 0, &Setting_background);
		back.draw();
		normal.draw();
	}

	void on_input(const ExMessage& msg)
	{
		if (msg.message == WM_LBUTTONDOWN)
		{
			int x = msg.x;
			int y = msg.y;
			L_button_down = true;
		}
		back.process_event(msg);
		easy.process_event(msg);
		normal.process_event(msg);
		hard.process_event(msg);
		expert.process_event(msg);
	}

	void on_exit(){}

	void set_mod()
	{
		switch (current_mod)
		{
		case MOD::Easy:
			board.set_cols(9);
			board.set_rows(9);
			mine.set_mine_count(10);
			break;
		case MOD::Normal:
			board.set_cols(16);
			board.set_rows(16);
			mine.set_mine_count(40);
			break;
		case MOD::Hard:
			board.set_cols(20);
			board.set_rows(20);
			mine.set_mine_count(80);
			break;
		case MOD::Expert:
			board.set_cols(30);
			board.set_rows(16);
			mine.set_mine_count(99);
			break;
		default:
			break;
		}
		board.set_board();
	}

private:

	Button back;

	Button easy;
	Button normal;
	Button hard;
	Button expert;

	MOD current_mod = MOD::Easy;

	int x = msg.x;
	int y = msg.y;
	int space_between_button = 10;

	bool L_button_down = false;

};