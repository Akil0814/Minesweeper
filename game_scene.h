#pragma once
#include"mine.h"
#include"mine_board.h"
#include "scene_manager.h"
#include"button.h"

#include<iostream>

extern ExMessage msg;
extern IMAGE Bar;

extern IMAGE Restart_Idle;
extern IMAGE Restart_Hovered;
extern IMAGE Restart_Pushed;

extern IMAGE Exit_Idle;
extern IMAGE Exit_Hovered;
extern IMAGE Exit_Pushed;

extern MineBoard board;
extern Button restart;
extern Mine mine;

extern SceneManager scene_manager;

class GameScene :public Scene
{
public:
	GameScene() = default;
	~GameScene() = default;

	void on_enter()
	{
		WINDOW_WIDTH = board.cheek_col()*mine.get_mine_width();
		WINDOW_HEIGHT = board.cheek_row()*mine.get_mine_width()+Bar.getheight();

		restart.set_image(&Restart_Idle, &Restart_Hovered, &Restart_Pushed);
		restart.set_left(WINDOW_WIDTH - restart.get_button_width() - 10);
		restart.set_top(WINDOW_HEIGHT - restart.get_button_height() - 10);

		exit.set_image(&Exit_Idle, &Exit_Hovered, &Exit_Pushed);
		exit.set_left(restart.cheek_left()-exit.get_button_width()-10);
		exit.set_top(restart.cheek_top());

		initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);
		board.set_board();
	}

	void on_update()
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
			if (restart.cheek_is_clicked())
			{
				on_exit();
				board.set_board();
				restart.reset_button();
			}
			if (exit.cheek_is_clicked())
			{
				scene_manager.switch_to(SceneManager::SceneType::Menu);
				exit.reset_button();
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

		putimage(0, board.get_height(), &Bar);
		restart.draw();
		exit.draw();
	}

	void on_input(const ExMessage& msg)
	{
		if (msg.x > 0 && msg.x < board.get_width() && msg.y>0 && msg.y < board.get_height()&&!game_end)
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				L_button_down = true;
				x_index = (msg.x / mine.get_mine_width() + 1);
				y_index = (msg.y / mine.get_mine_width() + 1);
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

		restart.process_event(msg);
		exit.process_event(msg);
	}

	void on_exit()
	{
		board.reset_board_data();
		waiting_for_first_click = true;
		game_end = false;
	}

private:
	
	Button restart;
	Button exit;

	int x_index =-1;
	int y_index =-1;

	bool L_button_down = false;
	bool R_button_down = false;

	bool game_end = false;
	bool waiting_for_first_click = true;

};