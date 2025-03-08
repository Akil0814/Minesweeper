#pragma once
extern IMAGE Base;

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
	int num_of_flag = num_of_mine;
};
