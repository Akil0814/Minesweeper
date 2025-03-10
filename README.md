# MineSweeper 扫雷
This is the first project I've tried to write myself. It’s a MineSweeper game based on the **[EasyX](https://easyx.cn/)** Graphics Library. It has all the functions that a classic minesweeper has, like mod selection, customizable mine board,in-game timer, and restart option<br>
	基于 [EasyX](https://easyx.cn/)图形库完成的扫雷小游戏，基本具有经典扫雷游戏的所有功能，如模式选择、自定义雷板、雷计数器、游戏内计时器、重启选项等


## About the code
The idea about scene manager is from [VoidmatrixHeathcliff (Voidmatrix)](https://github.com/VoidmatrixHeathcliff).
All image resources are loaded dynamically so you can change the image resources but make sure `IMAGE` for **mine board** is all same size and **Button** `IMAGE` in three status ` IMAGE _Idle; IMAGE _Hovered; IMAGE _Pushed;`need to be same size<br>
场景管理器来的设计来自[VoidmatrixHeathcliff (Voidmatrix)](https://github.com/VoidmatrixHeathcliff).所有图像资源渲染的位置都是动态加载的，因此可以随意更改图像资源，但请确保**mine board**类的`IMAGE`大小相同，**Button**类的`IMAGE`在三种状态下`IMAGE _Idle; IMAGE _Hovered; IMAGE _Pushed;`也需要大小相同

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
```
## Class and Function Design

### Scene Manager
about how Scene Manager work you can chack on the video [Scene Manager](https://www.youtube.com/watch?v=iY4SjVaV9So&t=53s)
### Scene

#### Menu scene

#### Game scene

#### Selector scene

### Mine Class

### Mine Board

### Button
