#pragma once
#include<graphics.h>

class Button
{
public:
	Button(){}
	~Button() {}

	void set_image()
	{
		img_idle = nullptr;
		img_hovered = nullptr;
		img_pushed = nullptr;
	}

	void set_top()
	{

	}

	void set_left()
	{

	}

	void draw()
	{
		switch (status)
		{
		case Status::Idle:
			putimage(region.left, region.top, img_idle);
			break;
		case Status::Hovered:
			putimage(region.left, region.top, img_hovered);
			break;
		case Status::Pushed:
			putimage(region.left, region.top, img_pushed);
			break;
		}
	}

	bool check_cursor_hit(int x, int y)
	{
		return x >= region.left && x <= region.right && y >= region.top && y <= region.bottom;
	}

private:
	enum class Status
	{
		Idle = 0,
		Hovered,
		Pushed
	};
private:
	RECT region={0,0,0,0};
	IMAGE* img_idle=nullptr;
	IMAGE* img_hovered = nullptr;
	IMAGE* img_pushed = nullptr;
	Status status = Status::Idle;
};