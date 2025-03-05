#pragma once
#include"mine.h"
#include"button.h"
#include<vector>
using namespace std;

#define IS_EMPTY 0
#define IS_MINE 1 
#define IS_CHEAKED 2
#define IS_FLAG 3

extern Mine mine;

extern IMAGE MineMarked;
extern IMAGE Num1;
extern IMAGE Num2;
extern IMAGE Num3;
extern IMAGE Num4;
extern IMAGE Num5;
extern IMAGE Num6;
extern IMAGE Num7;
extern IMAGE Num8;
extern IMAGE Base;
extern IMAGE MineCover;

extern IMAGE MineExplode;
extern IMAGE MineFined;

extern IMAGE MineBase;
extern IMAGE Bar;

class MineBoard
{
public:
	MineBoard() = default;
	~MineBoard()= default;

	void set_board()
	{
		width = mine.get_mine_width();
		num_of_mine = mine.get_mine_count();

		board_mine.resize(row_mine, vector<int>(col_mine, IS_EMPTY));
		board_show.resize(row_mine, vector<int>(col_mine, IS_EMPTY));
		board_num.resize(row_mine, vector<int>(col_mine, IS_EMPTY));
	}

	void set_mine(const int index_x,const int index_y)
	{
		int count = num_of_mine;

			board_mine[index_x][index_y] = 1;
		if(15 <(row_show * col_show)- num_of_mine)
		{
			board_mine[index_x + 1][index_y] = 1;
			board_mine[index_x - 1][index_y] = 1;
			board_mine[index_x][index_y + 1] = 1;
			board_mine[index_x][index_y - 1] = 1;
			board_mine[index_x - 1][index_y - 1] = 1;
			board_mine[index_x + 1][index_y - 1] = 1;
			board_mine[index_x - 1][index_y + 1] = 1;
			board_mine[index_x + 1][index_y + 1] = 1;
		}

		while (count>0)
		{

			int x = (rand() % row_show +1);
			int y = (rand() % col_show +1);
			if (board_mine[x][y] == 0)
			{
				board_mine[x][y] = IS_MINE;
				count--;
			}
		}

			board_mine[index_x][index_y] = 0;
		if (15 < (row_show * col_show) - num_of_mine)
		{
			board_mine[index_x + 1][index_y] = 0;
			board_mine[index_x - 1][index_y] = 0;
			board_mine[index_x][index_y + 1] = 0;
			board_mine[index_x][index_y - 1] = 0;
			board_mine[index_x - 1][index_y - 1] = 0;
			board_mine[index_x + 1][index_y - 1] = 0;
			board_mine[index_x - 1][index_y + 1] = 0;
			board_mine[index_x + 1][index_y + 1] = 0;
		}

		for (int i = 1; i <= row_show; i++)
		{
			for (int j = 1; j <= col_show; j++)
				board_num[i][j] = (get_mine_count(i, j));
		}

	}

	void draw_board()
	{
		for (int i = 1; i <=graph_y; i++)
		{
			for (int j = 1; j <= graph_x; j++)
			{
				if (board_show[i][j] == IS_CHEAKED)
				{
					int num = board_num[i][j];
					switch (num)
					{
					case 0:
						putimage((j - 1) * width, (i - 1) * width, &Base);
						break;
					case 1:
						putimage((j - 1) * width, (i - 1) * width, &Num1);
						break;
					case 2:
						putimage((j - 1) * width, (i - 1) * width, &Num2);
						break;
					case 3:
						putimage((j - 1) * width, (i - 1) * width, &Num3);
						break;
					case 4:
						putimage((j - 1) * width, (i - 1) * width, &Num4);
						break;
					case 5:
						putimage((j - 1) * width, (i - 1) * width, &Num5);
						break;
					case 6:
						putimage((j - 1) * width, (i - 1) * width, &Num6);
						break;
					case 7:
						putimage((j - 1) * width, (i - 1) * width, &Num7);
						break;
					case 8:
						putimage((j - 1) * width, (i - 1) * width, &Num8);
						break;
					default:
						break;
					}
				}
				if (board_show[i][j] == IS_EMPTY)
				{
					putimage((j - 1) * width, (i - 1) * width, &MineCover);
				}
				if (board_show[i][j] == IS_FLAG)
				{
					putimage((j - 1) * width, (i - 1) * width, &MineMarked);
				}
			}
		}
		putimage(0, row_show * width, &Bar);
	}

	void show_all_mine()
	{
		for (int i = 1; i <= graph_y; i++)
		{
			for (int j = 1; j <= graph_x; j++)
			{
				if (board_show[i][j] == IS_CHEAKED)
				{
					int num = board_num[i][j];
					switch (num)
					{
					case 0:
						putimage((j - 1) * width, (i - 1) * width, &Base);
						break;
					case 1:
						putimage((j - 1) * width, (i - 1) * width, &Num1);
						break;
					case 2:
						putimage((j - 1) * width, (i - 1) * width, &Num2);
						break;
					case 3:
						putimage((j - 1) * width, (i - 1) * width, &Num3);
						break;
					case 4:
						putimage((j - 1) * width, (i - 1) * width, &Num4);
						break;
					case 5:
						putimage((j - 1) * width, (i - 1) * width, &Num5);
						break;
					case 6:
						putimage((j - 1) * width, (i - 1) * width, &Num6);
						break;
					case 7:
						putimage((j - 1) * width, (i - 1) * width, &Num7);
						break;
					case 8:
						putimage((j - 1) * width, (i - 1) * width, &Num8);
						break;
					default:
						break;
					}
				}
				if (board_show[i][j] == IS_EMPTY)
				{
					putimage((j - 1) * width, (i - 1) * width, &MineCover);
				}
				if (board_show[i][j] == IS_FLAG)
				{
					putimage((j - 1) * width, (i - 1) * width, &MineMarked);
				}
				if (board_show[i][j] == IS_EMPTY && board_mine[i][j]==IS_MINE)
				{
					putimage((j - 1) * width, (i - 1) * width, &MineExplode);
				}
				if (board_show[i][j] == IS_FLAG && board_mine[i][j] == IS_MINE)
				{
					putimage((j - 1) * width, (i - 1) * width, &MineFined);
				}
			}
		}
		putimage(0, row_show * width, &Bar);

	}

	void check_mine(const int x,const int y)
	{

		if (board_mine[x][y] == IS_EMPTY && board_show[x][y] == IS_EMPTY)
		{
			board_show[x][y] = IS_CHEAKED;
			num_of_cover--;
			int num = board_num[x][y];
			if (num == 0)
			{
				check_around(x,y);
			}
		}
		else if (board_mine[x][y] == IS_MINE && board_show[x][y] == IS_EMPTY)
		{
			is_game_end = true;
		}
	}

	void set_flag(const int x,const int y)
	{
		if (board_show[x][y] == IS_EMPTY)
		{
			board_show[x][y] = IS_FLAG;
			}
		else if (board_show[x][y] == IS_FLAG)
		{
			board_show[x][y] = IS_EMPTY;
		}
	}

	void set_rows(int row)
	{
		row_show = row;
		col_mine = col_show + 2;
	}

	void set_cols(int col)
	{
		col_show = col; 
		col_mine = col_show + 2;
	}

	int cheek_col()const
	{
		return col_show;
	}

	int cheek_row()const
	{
		return row_show;
	}

	bool cheek_game_end()const
	{
		return is_game_end;
	}

	void reset_board_data()
	{
		board_mine.clear();
		board_show.clear();
		board_num.clear();

		is_game_end = false;
	}

private:

	void check_around(int x, int y)
	{
		if (x + 1 <= row_show && board_show[x + 1][y] != IS_CHEAKED)
			check_mine(x + 1, y);
		if (x - 1 > 0 && board_show[x - 1][y] != IS_CHEAKED)
			check_mine(x - 1, y);
		if (y + 1 <= col_show && board_show[x][y + 1] != IS_CHEAKED)
			check_mine(x, y + 1);
		if (y - 1 > 0 && board_show[x][y - 1] != IS_CHEAKED)
			check_mine(x, y - 1);

		if (x - 1 > 0 && y - 1 > 0 && board_show[x - 1][y - 1] != IS_CHEAKED)
			check_mine(x - 1, y - 1);
		if (x - 1 > 0 && y + 1 <= col_show && board_show[x - 1][y + 1] != IS_CHEAKED)
			check_mine(x - 1, y + 1);
		if (x + 1 <= row_show && y - 1 > 0 && board_show[x + 1][y - 1] != IS_CHEAKED)
			check_mine(x + 1, y - 1);
		if (x + 1 <= row_show && y + 1 <= col_show && board_show[x + 1][y + 1] != IS_CHEAKED)
			check_mine(x + 1, y + 1);
	}

	int get_mine_count(const int x, const int y)const
	{
		if (x<1 || x>row_show || y<1 || y>col_show)
			return -1;

		return	board_mine[x - 1][y] +
			board_mine[x - 1][y - 1] +
			board_mine[x][y - 1] +
			board_mine[x + 1][y - 1] +
			board_mine[x + 1][y] +
			board_mine[x + 1][y + 1] +
			board_mine[x][y + 1] +
			board_mine[x - 1][y + 1];
	}

private:

	vector<vector<int>>board_mine;
	vector<vector<int>>board_show;
	vector<vector<int>>board_num;

	int row_show = 10;
	int col_show = 10;
	int row_mine = row_show+2;
	int col_mine = col_show+2;

	int graph_x = col_show;
	int graph_y = row_show;

	int num_of_mine= mine.get_mine_count();
	int num_of_cover = (row_show * col_show) - num_of_mine;
	int width = mine.get_mine_width();

	bool is_game_end=false;

};