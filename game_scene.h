#pragma once
#include"mine.h"
#include"mine_board.h"
#include "scene_manager.h"
#include<iostream>

extern ExMessage msg;
extern MineBoard board;
extern Mine mine;

extern SceneManager scene_manager;

class GameScene :public Scene
{
public:
	GameScene() = default;
	~GameScene() = default;

	void on_enter()
	{
		WINDOW_WIDTH = (board.cheek_col())*(mine.get_mine_width());
		WINDOW_HEIGHT = (board.cheek_row())*(mine.get_mine_width());

		initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);
		board.set_board();
	}

	void on_update()
	{
		if (game_end)
		{
			if (L_button_down)
			{
				L_button_down = false;
				scene_manager.switch_to(SceneManager::SceneType::Menu);
			}
		}
		else 
		{
			if (L_button_down)
			{
				L_button_down = false;
				board.check_mine(y_index, x_index);
			}
			if (R_button_down)
			{
				R_button_down = false;
				board.set_flag(y_index, x_index);
			}
		}
	}

	void on_draw()
	{
		game_end = board.cheek_game_end();
		if (game_end)
		{
			board.show_all_mine();
		}
		else
			board.draw_board();
	}

	void on_input(const ExMessage& msg)
	{
			if(msg.message == WM_LBUTTONDOWN)
			{
				L_button_down = true;
				x_index = (msg.x / mine.get_mine_width()+1);
				y_index = (msg.y / mine.get_mine_width()+1);
				if (waiting_for_first_click)
				{
					board.set_mine(y_index, x_index);
					waiting_for_first_click = false;
				}

			}
			else if (msg.message == WM_RBUTTONDOWN)
			{
				R_button_down = true;
				x_index = (msg.x / mine.get_mine_width() + 1);
				y_index = (msg.y / mine.get_mine_width() + 1);
			}
	}

	void on_exit()
	{
		board.reset_board_data();
		waiting_for_first_click = true;
		game_end = false;
	}

private:
	int x_index = msg.x;
	int y_index = msg.y;

	bool L_button_down = false;
	bool R_button_down = false;

	bool game_end = false;
	bool waiting_for_first_click = true;

};