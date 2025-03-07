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
		easy.set_left(WINDOW_WIDTH / 2 - space_between_button - easy.get_button_width());
		easy.set_top(space_between_button);
		easy.set_hold(true);

		normal.set_image(&Normal_Idle, &Normal_Hovered, &Normal_Pushed);
		normal.set_left(WINDOW_WIDTH /2 + space_between_button);
		normal.set_top(space_between_button);
		normal.set_hold(true);

		hard.set_image(&Hard_Idle, &Hard_Hovered, &Hard_Pushed);
		hard.set_left(WINDOW_WIDTH / 2 - space_between_button - hard.get_button_width());
		hard.set_top(space_between_button*2+easy.get_button_height());
		hard.set_hold(true);

		expert.set_image(&Expert_Idle, &Expert_Hovered, &Expert_Pushed);
		expert.set_left(WINDOW_WIDTH / 2 + space_between_button);
		expert.set_top(space_between_button*2 + normal.get_button_height());
		expert.set_hold(true);

	}

	void on_update()
	{
		if (back.cheek_is_clicked())
		{
			scene_manager.switch_to(SceneManager::SceneType::Menu);
			back.reset_click();
		}
		if (easy.cheek_is_clicked())
		{
			current_mod = MOD::Easy;
			set_mod();
			easy.reset_click();
		}
		if (normal.cheek_is_clicked())
		{
			current_mod = MOD::Normal;
			set_mod();
			normal.reset_click();
		}
		if (hard.cheek_is_clicked())
		{
			current_mod = MOD::Hard;
			set_mod();
			hard.reset_click();
		}
		if (expert.cheek_is_clicked())
		{
			current_mod = MOD::Expert;
			set_mod();
			expert.reset_click();
		}
	}

	void on_draw()
	{
		putimage(0, 0, &Setting_background);
		back.draw();
		normal.draw();
		easy.draw();
		hard.draw();
		expert.draw();
	}

	void on_input(const ExMessage& msg)
	{
		back.process_event(msg);
		easy.process_event(msg);
		normal.process_event(msg);
		hard.process_event(msg);
		expert.process_event(msg);
	}

	void on_exit(){}

	void set_mod()
	{
		if(current_mod_button!=nullptr)
			current_mod_button->reset_status();

		switch (current_mod)
		{
			cout << "set_mod" << endl;
		case MOD::Easy:
			board.set_cols(9);
			board.set_rows(9);
			mine.set_mine_count(10);
			current_mod_button = &easy;

			break;
		case MOD::Normal:
			board.set_cols(16);
			board.set_rows(16);
			mine.set_mine_count(40);
			current_mod_button = &normal;

			break;
		case MOD::Hard:
			board.set_cols(20);
			board.set_rows(20);
			mine.set_mine_count(80);
			current_mod_button = &hard;

			break;
		case MOD::Expert:
			board.set_cols(30);
			board.set_rows(16);
			mine.set_mine_count(99);
			current_mod_button = &expert;

			break;
		default:
			break;
		}
	}

private:

	Button back;

	Button easy;
	Button normal;
	Button hard;
	Button expert;

	Button* current_mod_button = nullptr;


	MOD current_mod = MOD::Easy;

	int x = msg.x;
	int y = msg.y;
	int space_between_button = 10;

};