# MineSweeper扫雷
This is the first project I've tried to write myself. It’s a MineSweeper game based on the **[EasyX](https://easyx.cn/)** Graphics Library. It has all the functions that a classic minesweeper has, like mod selection, customizable mine board,in-game timer, and restart option<br>
基于**[EasyX](https://easyx.cn/)**实现的扫雷小游戏，基本有经典扫雷的所有功能如模式选择 自定义模式 游戏内计时器和重启选项等


## About the code
The idea about scene manager is from [VoidmatrixHeathcliff (Voidmatrix)](https://github.com/VoidmatrixHeathcliff).
All image resources are loaded dynamically so you can change the image resources but make sure `IMAGE` for **mine board** is all same size and **Button** `IMAGE` in three status ` IMAGE _Idle; IMAGE _Hovered; IMAGE _Pushed;`need to be same size<br>
场景管理器来的设计来源[VoidMatrix](https://www.bilibili.com/video/BV17H4y1j7G6/?spm_id_from=333.1387.upload.video_card.click)所有图像资源渲染的位置都是动态加载的，因此可以随意更改图像资源，但请确保**mine board**类的`IMAGE`大小相同，**Button**类的`IMAGE`在三种状态下`IMAGE _Idle; IMAGE _Hovered; IMAGE _Pushed;`也需要大小相同

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
