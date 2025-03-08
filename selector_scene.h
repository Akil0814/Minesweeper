#pragma once
#include "scene_manager.h"
#include "scene.h"
#include"button.h"
#include"mine_board.h"
#include"mine.h"

#include<iostream>
#include<vector>
#include <conio.h> 

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
extern IMAGE Custom_Idle;
extern IMAGE Custom_Hovered;
extern IMAGE Custom_Pushed;
extern IMAGE Custom_row;
extern IMAGE Custom_col;
extern IMAGE Custom_mine;
extern IMAGE Custom_row_Editing;
extern IMAGE Custom_col_Editing;
extern IMAGE Custom_mine_Editing;

extern MineBoard board;
extern Mine mine;

class SelectorScene :public Scene
{
public:
	SelectorScene()
	{
		easy.set_hold();
	}

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

		normal.set_image(&Normal_Idle, &Normal_Hovered, &Normal_Pushed);
		normal.set_left(WINDOW_WIDTH /2 + space_between_button);
		normal.set_top(space_between_button);

		hard.set_image(&Hard_Idle, &Hard_Hovered, &Hard_Pushed);
		hard.set_left(WINDOW_WIDTH / 2 - space_between_button - hard.get_button_width());
		hard.set_top(space_between_button*2+easy.get_button_height());

		expert.set_image(&Expert_Idle, &Expert_Hovered, &Expert_Pushed);
		expert.set_left(WINDOW_WIDTH / 2 + space_between_button);
		expert.set_top(space_between_button*2 + normal.get_button_height());

		custom.set_image(&Custom_Idle, &Custom_Hovered, &Custom_Pushed);
		custom.set_left((WINDOW_WIDTH-custom.get_button_width()) / 2);
		custom.set_top(space_between_button * 2+ expert.get_button_height()+expert.cheek_top());

		custom_row.set_image(&Custom_row, &Custom_row, &Custom_row_Editing);
		custom_row.set_left(space_between_button * 6);
		custom_row.set_top(space_between_button * 2 + custom.get_button_height() + custom.cheek_top());

		custom_col.set_image(&Custom_col, &Custom_col, &Custom_col_Editing);
		custom_col.set_left(space_between_button * 6);
		custom_col.set_top(space_between_button * 2 + custom_row.get_button_height() + custom_row.cheek_top());

		custom_mine.set_image(&Custom_mine, &Custom_mine, &Custom_mine_Editing);
		custom_mine.set_left(space_between_button * 6);
		custom_mine.set_top(space_between_button * 2 + custom_col.get_button_height() + custom_col.cheek_top());
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
		if (custom.cheek_is_clicked())
		{
			current_mod = MOD::Custom;
			set_mod();
			custom.reset_click();
		}

		if (custom_row.cheek_is_clicked())
		{
			current_mod = MOD::Custom;
			current_custom_input= Custom_Input::row;
			set_customize();
			set_mod();
			read_keyboard = true;
			custom_row.reset_click();
		}
		if (custom_col.cheek_is_clicked())
		{
			current_mod = MOD::Custom;
			current_custom_input= Custom_Input::col;
			set_customize();
			set_mod();
			read_keyboard = true;
			custom_col.reset_click();
		}
		if (custom_mine.cheek_is_clicked())
		{
			current_mod = MOD::Custom;
			current_custom_input= Custom_Input::mine;
			set_customize();
			set_mod();
			read_keyboard = true;
			custom_mine.reset_click();
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
		custom.draw();
		custom_row.draw();
		custom_col.draw();
		custom_mine.draw();

		setbkmode(TRANSPARENT);
		settextstyle(size_of_text, 0, _T("System"), 0, 0, FW_BOLD, FALSE, FALSE, FALSE);
		draw_tip_text_col();
		draw_tip_text_row();
		draw_tip_text_mine();
	}

	void on_input(const ExMessage& msg)
	{
		if(read_keyboard)
			read_form_keyboard(msg);
		back.process_event(msg);
		easy.process_event(msg);
		normal.process_event(msg);
		hard.process_event(msg);
		expert.process_event(msg);

		custom.process_event(msg);
		custom_row.process_event(msg);
		custom_col.process_event(msg);
		custom_mine.process_event(msg);
	}

	void on_exit()
	{
		set_mod();
	}

private:
	void set_mod()
	{
		read_keyboard = false;

		if(current_mod_button!=nullptr)
			current_mod_button->reset_hold();
		if (current_customize_button != nullptr&& current_mod!= MOD::Custom)
			current_customize_button->reset_hold();

		switch (current_mod)
		{
		case MOD::Easy:
			col_count = 9;
			row_count = 9;
			mine_count = 10;
			current_mod_button = &easy;
			break;
		case MOD::Normal:
			col_count = 16;
			row_count = 16;
			mine_count = 40;
			current_mod_button = &normal;
			break;
		case MOD::Hard:
			col_count = 20;
			row_count = 20;
			mine_count = 80;
			current_mod_button = &hard;
			break;
		case MOD::Expert:
			col_count = 30;
			row_count = 16;
			mine_count = 99;
			current_mod_button = &expert;
			break;
		case MOD::Custom:
			current_mod_button = &custom;	
		default:
			break;
		}

		if (col_count * row_count <= mine_count)
		{
			mine_count = col_count * row_count - 1;
		}
		set_board_mod(col_count, row_count, mine_count);
		current_mod_button->set_hold();

	}

	void  set_board_mod(int mod_col,int mod_row,int mod_mine_count)
	{	
		board.set_cols(mod_col);
		board.set_rows(mod_row);
		mine.set_mine_count(mod_mine_count);
	}

	void set_customize()
	{
		all_input.clear();

		if (current_mod_button != nullptr&& current_mod_button != &custom)
				current_mod_button->reset_hold();
		if (current_customize_button != nullptr)
			current_customize_button->reset_hold();

		switch (current_custom_input)
		{
		case Custom_Input::col:
			current_customize_button = &custom_col;
			counter_input = &col_count;

			break;
		case Custom_Input::row:
			current_customize_button = &custom_row;
			counter_input = &row_count;

			break;
		case Custom_Input::mine:
			current_customize_button = &custom_mine;
			counter_input = &mine_count;

			break;
		default:
			break;
		}

		current_customize_button->set_hold();
		current_mod_button->set_hold();
	}

	void read_form_keyboard(const ExMessage& msg)
	{
		switch (msg.message)
		{
		case WM_KEYDOWN:
			if (msg.vkcode >= 0x30 && msg.vkcode <= 0x39&& all_input.size()<3)
			{
				switch (msg.vkcode)
				{
				case 0x30:
					tmp_num_for_input = 0;
					break;
				case 0x31:
					tmp_num_for_input = 1;
					break;
				case 0x32:
					tmp_num_for_input = 2;
					break;
				case 0x33:
					tmp_num_for_input = 3;
					break;
				case 0x34:
					tmp_num_for_input = 4;
					break;
				case 0x35:
					tmp_num_for_input = 5;
					break;
				case 0x36:
					tmp_num_for_input = 6;
					break;
				case 0x37:
					tmp_num_for_input = 7;
					break;
				case 0x38:
					tmp_num_for_input = 8;
					break;
				case 0x39:
					tmp_num_for_input = 9;
					break;
				default:
					break;
				}

				all_input.push_back(tmp_num_for_input);
				vector<int> tmp(all_input);
				tmp_num_for_loop = 0;
				for (int i = 1; !tmp.empty(); i *= 10)
				{
					int t = tmp.back();
					tmp_num_for_loop = tmp_num_for_loop + t * i;
					tmp.pop_back();
				}
				*counter_input = tmp_num_for_loop;
			}
		break;
		}
	}

	void draw_tip_text_row()
	{
		
		static TCHAR str[12];
		_stprintf_s(str, _T("Row:%d"), row_count);
		settextcolor(RGB(0, 0, 0));
		outtextxy(custom_row.cheek_left() + space_between_button, custom_row.cheek_top() + space_between_button, str);
	}
	void draw_tip_text_col()
	{
		static TCHAR str[12];
		_stprintf_s(str, _T("Col:%d"),col_count);
		settextcolor(RGB(0, 0, 0));
		outtextxy(custom_col.cheek_left() + space_between_button, custom_col.cheek_top()+ space_between_button,str);
	}
	void draw_tip_text_mine()
	{
		static TCHAR str[12];
		_stprintf_s(str, _T("Mine:%d"), mine_count);
		settextcolor(RGB(0, 0, 0));
		outtextxy(custom_mine.cheek_left() + space_between_button, custom_mine.cheek_top() + space_between_button, str);
	}

private:
	enum class MOD
	{
		Easy = 0,
		Normal,
		Hard,
		Expert,
		Custom
	};

	enum class Custom_Input
	{
		col=0,
		row,
		mine
	};

private:

	const int size_of_text = 28;
	const int space_between_button = 10;
	static const int max_num_for_input = 999;

	int col_count = board.cheek_col();
	int row_count = board.cheek_row();
	int mine_count = mine.get_mine_count();
	int* counter_input = nullptr;

	vector<int>all_input;
	int tmp_num_for_input=0;
	int tmp_num_for_loop = 0;

	bool read_keyboard = false;

	Button back;

	Button easy;
	Button normal;
	Button hard;
	Button expert;
	Button custom;
	Button custom_row;
	Button custom_col;
	Button custom_mine;

	Button* current_mod_button = &easy;
	Button* current_customize_button = nullptr;

	MOD current_mod = MOD::Easy;
	Custom_Input current_custom_input = Custom_Input::col;

	int x = msg.x;
	int y = msg.y;

};