#pragma once
#include<iostream>

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

extern IMAGE MineExplode;
extern IMAGE MineFined;

extern IMAGE MineBace;//test

class Mine
{
public:
	Mine() = default;
	~Mine() = default;

	void set_mine_count(int num)
	{
		num_of_mine = num;
	}

	int get_mine_count()const
	{
		return num_of_mine;
	}


	int get_mine_width()const
	{
		return Base.getwidth();
	}


private:
	int width = get_mine_width();
	int num_of_mine=10;
};
