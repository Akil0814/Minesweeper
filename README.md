# MineSweeper--扫雷
This is the first project I've tried to write myself. It’s a MineSweeper game based on the **[EasyX](https://easyx.cn/)** Graphics Library. It has all the functions that a classic minesweeper has, like mod selection, customizable mine board,in-game timer, and restart option<br>
	基于 [EasyX](https://easyx.cn/)图形库完成的扫雷小游戏，基本具有经典扫雷游戏的所有功能，如模式选择、自定义雷板、雷计数器、游戏内计时器、重启选项等

## About the code
The idea about scene manager is from [VoidmatrixHeathcliff (Voidmatrix)](https://github.com/VoidmatrixHeathcliff).
All image resources are loaded dynamically so you can change the image resources but make sure `IMAGE` for **mine board** is all same size and **Button** `IMAGE` in three status ` IMAGE _Idle; IMAGE _Hovered; IMAGE _Pushed;`need to be same size

#### All image for mine board
```
IMAGE MineExplode;
IMAGE MineCover;
IMAGE Num1;
IMAGE Num2;
IMAGE Num3;
IMAGE Num4;
IMAGE Num5;
IMAGE Num6;
IMAGE Num7;
IMAGE Num8;
IMAGE Base;
IMAGE MineMarked;
IMAGE MineFined;
IMAGE MineWin;
IMAGE MineBase;
IMAGE Bar;
