#pragma once
#include"mine.h"
#include"mine_board.h"
#include "scene_manager.h"
#include"button.h"

#include <chrono>

extern ExMessage msg;
extern IMAGE Bar;
extern IMAGE MineBase;


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
		restart.set_left(WINDOW_WIDTH - restart.get_button_width() - space_between_button);
		restart.set_top(WINDOW_HEIGHT - restart.get_button_height() - space_between_button);

		exit.set_image(&Exit_Idle, &Exit_Hovered, &Exit_Pushed);
		exit.set_left(restart.cheek_left()-exit.get_button_width()- space_between_button);
		exit.set_top(restart.cheek_top());

		initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);
		board.set_board();
	}

	void on_update()
	{
			game_time_curren = chrono::steady_clock::now();
			if (!waiting_for_first_click && !board.cheek_game_end())
			{
				duration = std::chrono::duration_cast<std::chrono::seconds>(game_time_curren - game_start_time);
				hours = std::chrono::duration_cast<std::chrono::hours>(duration).count();
				minutes = std::chrono::duration_cast<std::chrono::minutes>(duration).count() % 60;
				seconds = std::chrono::duration_cast<std::chrono::seconds>(duration).count() % 60;
			}

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
				restart.reset_click();
			}
			if (exit.cheek_is_clicked())
			{
				scene_manager.switch_to(SceneManager::SceneType::Menu);
				exit.reset_click();
			}
	}

	void on_draw()
	{

		if (board.cheek_game_end())
		{
			board.show_all_mine();
		}
		else
		{
			board.draw_board();
		}

		putimage(0, board.get_height(), &Bar);
		putimage(space_between_button, board.get_height()+ space_between_button, &MineBase);

		restart.draw();
		exit.draw();
		draw_tip_text_mine();
			draw_tip_text_time();

	}

	void on_input(const ExMessage& msg)
	{
		if (msg.x > 0 && msg.x < board.get_width() && msg.y>0 && msg.y < board.get_height()&&!board.cheek_game_end())
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
					game_start_time = chrono::steady_clock::now();
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
		hours = 0;
		minutes = 0;
		seconds = 0;
	}


private:
	void draw_tip_text_mine()
	{
		setbkmode(TRANSPARENT);
		static TCHAR str[32];
		_stprintf_s(str, _T(":%d"), board.get_num_of_mine_left());
		settextcolor(RGB(229, 65, 65));
		outtextxy(MineBase.getheight() + space_between_button, board.get_height() + space_between_button*1.5, str);
	}

	void draw_tip_text_time()
	{
		setbkmode(TRANSPARENT);
		static TCHAR str[50];

		_stprintf_s(str, _T("%02d:%02d:%02d"),hours, minutes,seconds);
		settextcolor(RGB(229, 65, 65));
		outtextxy(MineBase.getheight() + space_between_button*5, board.get_height() + space_between_button * 1.5, str);
	}

private:
	
	Button restart;
	Button exit;

	int space_between_button = 10;

	int x_index =-1;
	int y_index =-1;

	bool L_button_down = false;
	bool R_button_down = false;

	bool waiting_for_first_click = true;

	int hours = 0;
	int minutes = 0;
	int seconds = 0;
	std::chrono::steady_clock::time_point game_start_time = chrono::steady_clock::now();
	std::chrono::steady_clock::time_point game_time_curren = chrono::steady_clock::now();
	std::chrono::seconds duration = std::chrono::duration_cast<std::chrono::seconds>(game_time_curren - game_start_time);


};