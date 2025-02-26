#include"head.h"

void LoadResource()
{
	loadimage(&MineExplode, _T("res/Mine.png"));
	loadimage(&MineCover, _T("res/MineCover.png"));
	loadimage(&Num1, _T("res/Num1.png"));
	loadimage(&Num2, _T("res/Num2.png"));
	loadimage(&Num3, _T("res/Num3.png"));
	loadimage(&Num4, _T("res/Num4.png"));
	loadimage(&Num5, _T("res/Num5.png"));
	loadimage(&Num6, _T("res/Num6.png"));
	loadimage(&Num7, _T("res/Num7.png"));
	loadimage(&Num8, _T("res/Num8.png"));
	loadimage(&Base, _T("res/Base.png"));
	loadimage(&MineMarked, _T("res/MineMarked.png"));
	loadimage(&MineFined, _T("res/MineFined.png"));
	loadimage(&MineBace, _T("res/MineBace.png"));//test
}


int main()
{

	srand((unsigned int)time(NULL));//初始化随机数

	while (true)
	{
		DWORD start_time = GetTickCount();
		FlushBatchDraw();
		while (peekmessage(&msg))
		{


		}

		DWORD end_time = GetTickCount();
		DWORD delta_time = end_time - start_time;
		if (delta_time < 1000 / ((unsigned int)fps))//程序循环的优化
		{
			Sleep(1000 / fps - delta_time);
		}
	}

	EndBatchDraw();

	closegraph();

	return 0;
}