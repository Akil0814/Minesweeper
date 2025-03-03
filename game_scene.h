#pragma once
#include"mine.h"
#include"mine_board.h"
#include<iostream>

extern ExMessage msg;
extern MineBoard board;
extern Mine mine;

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
		if (!waiting_for_first_click)
		{
			board.check_mine(x_index, y_index);
		}
	}

	void on_draw()
	{
		board.draw_board();
	}

	void on_input(const ExMessage& msg)
	{
		if(waiting_for_first_click)
		{
			if(msg.message == WM_LBUTTONDOWN)
			{
				x_index = (msg.x / mine.get_mine_width()) + 1;
				y_index = (msg.y / mine.get_mine_width()) + 1;
				board.set_mine(x_index, y_index);
				waiting_for_first_click = false;
			}
		}
		else
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				x_index = (msg.x / mine.get_mine_width()) + 1;
				y_index = (msg.y / mine.get_mine_width()) + 1;
			}
		}
	}

	void on_exit() {}

private:
	int x_index = msg.x;
	int y_index = msg.y;

	bool waiting_for_first_click = true;

};