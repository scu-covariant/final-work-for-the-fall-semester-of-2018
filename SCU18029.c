#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
//全局变量

int position_x, position_y; //画笔所在的位置
int level;					//关卡数
int hight, width;			//画面大小
int h, l;					//代表不同关数行的大小
int mColor, uColor;
int level_1[6][6] = {{1, 1, 1, 1, 1, 0},
					 {1, 1, 1, 1, 1, 0},
					 {1, 1, 1, 1, 1, 1},
					 {1, 1, 1, 1, 1, 1},
					 {1, 0, 1, 1, 1, 1},
					 {1, 0, 0, 0, 1, 1}};
int level_2[6][6] = {{0, 1, 0, 1, 1, 1},
					 {1, 1, 1, 1, 1, 1},
					 {1, 1, 1, 1, 1, 1},
					 {0, 1, 1, 1, 0, 1},
					 {1, 1, 1, 1, 1, 1},
					 {1, 1, 1, 1, 1, 1}};
int level_3[8][6] = {{1, 1, 1, 1, 1, 1},
					 {1, 1, 1, 1, 1, 1},
					 {1, 0, 1, 1, 1, 1},
					 {1, 1, 1, 1, 1, 0},
					 {1, 1, 1, 1, 1, 1},
					 {0, 1, 1, 1, 1, 1},
					 {1, 1, 1, 1, 1, 1},
					 {1, 0, 1, 1, 1, 1}};
int level_4[8][6] = {{1, 1, 1, 1, 1, 1},
					 {1, 1, 1, 1, 1, 1},
					 {0, 1, 1, 0, 1, 1},
					 {1, 1, 1, 1, 1, 1},
					 {0, 1, 1, 1, 1, 0},
					 {1, 1, 1, 1, 1, 1},
					 {1, 1, 1, 1, 1, 1},
					 {1, 1, 1, 1, 1, 1}};
int level_5[8][6] = {{1, 1, 1, 1, 1, 1},
					 {0, 1, 1, 1, 0, 1},
					 {1, 1, 1, 1, 1, 1},
					 {1, 1, 1, 1, 1, 1},
					 {0, 1, 1, 1, 1, 1},
					 {1, 1, 1, 1, 0, 0},
					 {1, 1, 1, 1, 1, 1},
					 {1, 1, 1, 1, 1, 1}};
int level_6[8][6] = {{1, 1, 1, 1, 1, 1},
					 {1, 0, 1, 1, 1, 1},
					 {0, 1, 1, 0, 1, 1},
					 {1, 1, 1, 1, 1, 1},
					 {0, 1, 1, 1, 1, 0},
					 {1, 1, 1, 1, 1, 1},
					 {1, 1, 1, 1, 1, 1},
					 {1, 1, 1, 1, 1, 1}}; //关卡
int level_7[8][6] = {{1, 1, 1, 0, 1, 1},
					 {0, 1, 1, 1, 1, 1},
					 {1, 1, 1, 1, 1, 1},
					 {1, 1, 1, 0, 1, 1},
					 {0, 1, 1, 1, 1, 0},
					 {1, 1, 1, 1, 1, 1},
					 {1, 1, 1, 1, 1, 1},
					 {1, 1, 1, 1, 1, 1}};
int level_8[8][6] = {{1, 1, 1, 1, 0, 1},
					 {1, 0, 0, 1, 1, 1},
					 {1, 1, 1, 1, 1, 1},
					 {1, 1, 1, 1, 1, 1},
					 {0, 1, 1, 1, 1, 0},
					 {1, 1, 1, 1, 1, 1},
					 {1, 1, 1, 1, 1, 1},
					 {1, 1, 1, 1, 1, 1}};
int level_9[8][6] = {{1, 1, 1, 1, 1, 1},
					 {1, 1, 1, 1, 1, 0},
					 {1, 0, 1, 1, 1, 1},
					 {1, 0, 1, 1, 1, 1},
					 {0, 1, 1, 1, 1, 0},
					 {1, 1, 1, 1, 1, 1},
					 {1, 1, 1, 1, 1, 1},
					 {1, 1, 1, 1, 1, 1}};
int *le1 = &level_1[0][0], *le2 = &level_2[0][0], *le3 = &level_3[0][0],
	*le4 = &level_4[0][0], *le5 = &level_5[0][0], *le6 = &level_6[0][0],
	*le7 = &level_7[0][0], *le8 = &level_8[0][0], *le9 = &level_9[0][0];
int *all[9];
int finish[9];
int myColor, unColor;
void textcolor(int color)
{
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOutput, color);
}
void rcolor()
{
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOutput, 15);
}
void gotoxy(int x, int y) //光标移动到(x,y)位置
{
	HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hwnd, pos);
}
void HideCursor() // 用于隐藏光标
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0}; // 第二个值为0表示隐藏光标
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void change_h() //每次改变level都要引用来改变h
{
	if (level < 3)
		h = 6;
	else
		h = 8;
}
int flash(int a) //光标(→箭头进行闪动)
{
	if (a % 2 == 1)
	{
		printf("→");
		Sleep(400);
	}
	else
	{
		printf(" ");
		Sleep(200);
	}
	a += 1;
	return a;
}
void loading(int attempt, int scr)
{
	int load = 0;
	static int speed = 0;
	gotoxy(16, 4);
	textcolor(11);
	if (!scr)
	{
		if (attempt < 10)
			printf("很厉害嘛(。′ω｀)。 轻轻松松过关  下一关还要再接再厉!");
		else if (attempt >= 10)
			printf("终于通关了╰（‵□′）╯不容易啊  下一关还在前面等着你");
	}
	while (load - 101)
	{
		gotoxy(16, 6);
		printf("              %d  %%   Loading......   \n", load);
		if (load <= 20)
		{
			if (speed < 140)
				speed++;
			else
			{
				load += 1;
				speed = 0;
			}
		}
		else if (load <= 58)
		{
			if (speed < 300)
				speed++;
			else
			{
				load += 1;
				speed = 0;
			}
		}
		else if (load <= 70)
		{
			if (speed < 1200)
				speed++;
			else
			{
				load += 1;
				speed = 0;
			}
		}
		else
		{
			if (speed < 200)
				speed++;
			else
			{
				load += 1;
				speed = 0;
			}
		}
	}
}
void mainScreen() //主界面
{
	printf("\n\n\n");
	textcolor(10);
	printf("                        *         *          ************             *            \n");
	printf("                       ****      ****                                  *           \n");
	printf("                      *  *      *  *           *********         ************      \n");
	printf("                                               *   *   *         *          *      \n");
	printf("                        ***********         *  *   *   *  *         ******         \n");
	printf("                             *              *  *********  *                        \n");
	printf("    ************         *********          *  *   *   *  *        *********        \n");
	printf("                             *              *  *   *   *  *          *   *         \n");
	printf("                       *************        *  *********  *          *   *         \n");
	printf("                             *       *      *             *         *    *   *     \n");
	printf("                             *********      ***************       *      *****     \n");
	rcolor();
	printf("\n\n            Press");
	textcolor(13);
	printf("  W  A  S  D  ");
	rcolor();
	printf("to control,  Press");
	textcolor(13);
	printf("    Enter    ");
	rcolor();
	printf(" to choose\n\n\n\n");
	textcolor(11);
	printf("                                       Start to Play\n\n\n");
	printf("                                       Change Colors\n\n\n");
	printf("                                       How to Play");
	rcolor();
}
int screenWithInput() //主界面的转动
{
	char input;
	int a = 1;
	int ks = 1, yx = 0, skip = 0;
	while (!kbhit())
	{
		gotoxy(35, 20);
		a = flash(a);
	}
	while (1) // 判断是否有输入
	{
		input = getch();
		if (input >= 'A' && input <= 'Z')
			input += 32;
		switch (input)
		{
		case 'w':
			if (ks == 2)
				ks = 1;
			else if (ks == 3)
				ks = 2;
			break; //ks = 0时 在下
		case 's':
			if (ks == 1)
				ks = 2;
			else if (ks == 2)
				ks = 3;
			break;
		case '\r':
			skip = 1;
			break;
		default:
			break;
		} //copy by 2048
		if (!skip && ks == 1)
		{
			int a = 1;
			gotoxy(35, 23);
			printf(" ");
			gotoxy(35, 26);
			printf(" ");
			while (!kbhit())
			{
				gotoxy(35, 20);
				a = flash(a);
			}
		}
		else if (!skip && ks == 2)
		{
			int a = 1;
			gotoxy(35, 20);
			printf(" ");
			gotoxy(35, 26);
			printf(" ");
			while (!kbhit())
			{
				gotoxy(35, 23);
				a = flash(a);
			}
		}
		else if (!skip && ks == 3)
		{
			int a = 1;
			gotoxy(35, 20);
			printf(" ");
			gotoxy(35, 23);
			printf(" ");
			while (!kbhit())
			{
				gotoxy(35, 26);
				a = flash(a);
			}
		}
		if (skip)
			break;
	}
	return ks; //ks = 0为help  ks = 1时为play
}
void chapterMenu() //关卡选择界面
{
	textcolor(13);
	printf("   *\n");
	printf(" * *\n");
	printf("*  ********* | press");
	textcolor(12);
	printf(" E ");
	textcolor(13);
	printf("to return\n");
	printf(" * *\n");
	printf("   *\n");
	rcolor();
	printf("                        | S E L E C T   L E V E L|\n");
	printf("\n\n");
	printf("                   ");
	if (finish[0] == 0)
		textcolor(97);
	else if (finish[0] == 1)
		textcolor(224);
	printf("   ");
	rcolor();
	printf("            ");
	if (finish[1] == 0)
		textcolor(97);
	else if (finish[1] == 1)
		textcolor(224);
	printf("   ");
	rcolor();
	printf("              ");
	if (finish[2] == 0)
		textcolor(97);
	else if (finish[2] == 1)
		textcolor(224);
	printf("   \n");
	rcolor();
	printf("                   ");
	if (finish[0] == 0)
		textcolor(97);
	else if (finish[0] == 1)
		textcolor(224);
	printf(" 1 ");
	rcolor();
	printf("            ");
	if (finish[1] == 0)
		textcolor(97);
	else if (finish[1] == 1)
		textcolor(224);
	printf(" 2 ");
	rcolor();
	printf("              ");
	if (finish[2] == 0)
		textcolor(97);
	else if (finish[2] == 1)
		textcolor(224);
	printf(" 3 \n");
	rcolor();
	printf("                   ");
	if (finish[0] == 0)
		textcolor(97);
	else if (finish[0] == 1)
		textcolor(224);
	printf("   ");
	rcolor();
	printf("            ");
	if (finish[1] == 0)
		textcolor(97);
	else if (finish[1] == 1)
		textcolor(224);
	printf("   ");
	rcolor();
	printf("              ");
	if (finish[2] == 0)
		textcolor(97);
	else if (finish[2] == 1)
		textcolor(224);
	printf("   \n");
	rcolor();
	printf("\n\n\n\n");
	printf("                   ");
	if (finish[3] == 0)
		textcolor(97);
	else if (finish[3] == 1)
		textcolor(224);
	printf("   ");
	rcolor();
	printf("            ");
	if (finish[4] == 0)
		textcolor(97);
	else if (finish[4] == 1)
		textcolor(224);
	printf("   ");
	rcolor();
	printf("              ");
	if (finish[5] == 0)
		textcolor(97);
	else if (finish[5] == 1)
		textcolor(224);
	printf("   \n");
	rcolor();
	printf("                   ");
	if (finish[3] == 0)
		textcolor(97);
	else if (finish[3] == 1)
		textcolor(224);
	printf(" 4 ");
	rcolor();
	printf("            ");
	if (finish[4] == 0)
		textcolor(97);
	else if (finish[4] == 1)
		textcolor(224);
	printf(" 5 ");
	rcolor();
	printf("              ");
	if (finish[5] == 0)
		textcolor(97);
	else if (finish[5] == 1)
		textcolor(224);
	printf(" 6 \n");
	rcolor();
	printf("                   ");
	if (finish[3] == 0)
		textcolor(97);
	else if (finish[3] == 1)
		textcolor(224);
	printf("   ");
	rcolor();
	printf("            ");
	if (finish[4] == 0)
		textcolor(97);
	else if (finish[4] == 1)
		textcolor(224);
	printf("   ");
	rcolor();
	printf("              ");
	if (finish[5] == 0)
		textcolor(97);
	else if (finish[5] == 1)
		textcolor(224);
	printf("   \n");
	rcolor();
	printf("\n\n\n\n");
	printf("                   ");
	if (finish[6] == 0)
		textcolor(97);
	else if (finish[6] == 1)
		textcolor(224);
	printf("   ");
	rcolor();
	printf("            ");
	if (finish[7] == 0)
		textcolor(97);
	else if (finish[7] == 1)
		textcolor(224);
	printf("   ");
	rcolor();
	printf("              ");
	if (finish[8] == 0)
		textcolor(97);
	else if (finish[8] == 1)
		textcolor(224);
	printf("   \n");
	rcolor();
	printf("                   ");
	if (finish[6] == 0)
		textcolor(97);
	else if (finish[6] == 1)
		textcolor(224);
	printf(" 7 ");
	rcolor();
	printf("            ");
	if (finish[7] == 0)
		textcolor(97);
	else if (finish[7] == 1)
		textcolor(224);
	printf(" 8 ");
	rcolor();
	printf("              ");
	if (finish[8] == 0)
		textcolor(97);
	else if (finish[8] == 1)
		textcolor(224);
	printf(" 9 \n");
	rcolor();
	printf("                   ");
	if (finish[6] == 0)
		textcolor(97);
	else if (finish[6] == 1)
		textcolor(224);
	printf("   ");
	rcolor();
	printf("            ");
	if (finish[7] == 0)
		textcolor(97);
	else if (finish[7] == 1)
		textcolor(224);
	printf("   ");
	rcolor();
	printf("              ");
	if (finish[8] == 0)
		textcolor(97);
	else if (finish[8] == 1)
		textcolor(224);
	printf("   \n");
	rcolor();
}
int chapterChoosing() //关卡选择数据
{
	char input;
	int a = 1;
	int ks = 1, skip = 0;
	while (!kbhit())
	{
		gotoxy(16, 9);
		a = flash(a);
	}
	while (1) // 判断是否有输入
	{
		input = getch();
		if (input >= 'A' && input <= 'Z')
			input += 32;
		switch (input)
		{
		case 'w':
			if (ks == 4)
				ks = 1;
			else if (ks == 5)
				ks = 2;
			else if (ks == 6)
				ks = 3;
			else if (ks == 7)
				ks = 4;
			else if (ks == 8)
				ks = 5;
			else if (ks == 9)
				ks = 6;
			break;
		case 'a':
			if (ks == 2)
				ks = 1;
			else if (ks == 3)
				ks = 2;
			else if (ks == 5)
				ks = 4;
			else if (ks == 6)
				ks = 5;
			else if (ks == 8)
				ks = 7;
			else if (ks == 9)
				ks = 8;
			break;
		case 's':
			if (ks == 1)
				ks = 4;
			else if (ks == 2)
				ks = 5;
			else if (ks == 3)
				ks = 6;
			else if (ks == 4)
				ks = 7;
			else if (ks == 5)
				ks = 8;
			else if (ks == 6)
				ks = 9;
			break;
		case 'd':
			if (ks == 1)
				ks = 2;
			else if (ks == 2)
				ks = 3;
			else if (ks == 4)
				ks = 5;
			else if (ks == 5)
				ks = 6;
			else if (ks == 7)
				ks = 8;
			else if (ks == 8)
				ks = 9;
			break;
		case '\r':
			skip = 1;
			break; //确定选择
		case 'e':
			ks = 0;
			skip = 1;
			break; //返回上级
		default:
			break;
		} //copy by 2048
		if (!skip && ks == 1)
		{
			level = 1;
			change_h();
			int a = 1;
			gotoxy(31, 9);
			printf(" ");
			gotoxy(48, 9);
			printf(" ");
			gotoxy(16, 16);
			printf(" ");
			gotoxy(31, 16);
			printf(" ");
			gotoxy(48, 16);
			printf(" ");
			gotoxy(16, 23);
			printf(" ");
			gotoxy(31, 23);
			printf(" ");
			gotoxy(48, 23);
			printf(" ");
			while (!kbhit())
			{
				gotoxy(16, 9);
				a = flash(a);
			}
		}
		else if (!skip && ks == 2)
		{
			level = 2;
			change_h();
			int a = 1;
			gotoxy(16, 9);
			printf(" ");
			gotoxy(48, 9);
			printf(" ");
			gotoxy(16, 16);
			printf(" ");
			gotoxy(31, 16);
			printf(" ");
			gotoxy(48, 16);
			printf(" ");
			gotoxy(16, 23);
			printf(" ");
			gotoxy(31, 23);
			printf(" ");
			gotoxy(48, 23);
			printf(" ");
			while (!kbhit())
			{
				gotoxy(31, 9);
				a = flash(a);
			}
		}
		else if (!skip && ks == 3)
		{
			level = 3;
			change_h();
			int a = 1;
			gotoxy(16, 9);
			printf(" ");
			gotoxy(31, 9);
			printf(" ");
			gotoxy(16, 16);
			printf(" ");
			gotoxy(31, 16);
			printf(" ");
			gotoxy(48, 16);
			printf(" ");
			gotoxy(16, 23);
			printf(" ");
			gotoxy(31, 23);
			printf(" ");
			gotoxy(48, 23);
			printf(" ");
			while (!kbhit())
			{
				gotoxy(48, 9);
				a = flash(a);
			}
		}
		else if (!skip && ks == 4)
		{
			level = 4;
			change_h();
			int a = 1;
			gotoxy(16, 9);
			printf(" ");
			gotoxy(31, 9);
			printf(" ");
			gotoxy(48, 9);
			printf(" ");
			gotoxy(31, 16);
			printf(" ");
			gotoxy(48, 16);
			printf(" ");
			gotoxy(16, 23);
			printf(" ");
			gotoxy(31, 23);
			printf(" ");
			gotoxy(48, 23);
			printf(" ");
			while (!kbhit())
			{
				gotoxy(16, 16);
				a = flash(a);
			}
		}
		else if (!skip && ks == 5)
		{
			level = 5;
			change_h();
			int a = 1;
			gotoxy(16, 9);
			printf(" ");
			gotoxy(31, 9);
			printf(" ");
			gotoxy(48, 9);
			printf(" ");
			gotoxy(16, 16);
			printf(" ");
			gotoxy(48, 16);
			printf(" ");
			gotoxy(16, 23);
			printf(" ");
			gotoxy(31, 23);
			printf(" ");
			gotoxy(48, 23);
			printf(" ");
			while (!kbhit())
			{
				gotoxy(31, 16);
				a = flash(a);
			}
		}
		else if (!skip && ks == 6)
		{
			level = 6;
			change_h();
			int a = 1;
			gotoxy(16, 9);
			printf(" ");
			gotoxy(31, 9);
			printf(" ");
			gotoxy(48, 9);
			printf(" ");
			gotoxy(16, 16);
			printf(" ");
			gotoxy(31, 16);
			printf(" ");
			gotoxy(16, 23);
			printf(" ");
			gotoxy(31, 23);
			printf(" ");
			gotoxy(48, 23);
			printf(" ");
			while (!kbhit())
			{
				gotoxy(48, 16);
				a = flash(a);
			}
		}
		else if (!skip && ks == 7)
		{
			level = 7;
			change_h();
			int a = 1;
			gotoxy(16, 9);
			printf(" ");
			gotoxy(31, 9);
			printf(" ");
			gotoxy(48, 9);
			printf(" ");
			gotoxy(16, 16);
			printf(" ");
			gotoxy(31, 16);
			printf(" ");
			gotoxy(48, 16);
			printf(" ");
			gotoxy(31, 23);
			printf(" ");
			gotoxy(48, 23);
			printf(" ");
			while (!kbhit())
			{
				gotoxy(16, 23);
				a = flash(a);
			}
		}
		else if (!skip && ks == 8)
		{
			level = 8;
			change_h();
			int a = 1;
			gotoxy(16, 9);
			printf(" ");
			gotoxy(31, 9);
			printf(" ");
			gotoxy(48, 9);
			printf(" ");
			gotoxy(16, 16);
			printf(" ");
			gotoxy(31, 16);
			printf(" ");
			gotoxy(48, 16);
			printf(" ");
			gotoxy(16, 23);
			printf(" ");
			gotoxy(48, 23);
			printf(" ");
			while (!kbhit())
			{
				gotoxy(31, 23);
				a = flash(a);
			}
		}
		else if (!skip && ks == 9)
		{
			level = 9;
			change_h();
			int a = 1;
			gotoxy(16, 9);
			printf(" ");
			gotoxy(31, 9);
			printf(" ");
			gotoxy(48, 9);
			printf(" ");
			gotoxy(16, 16);
			printf(" ");
			gotoxy(31, 16);
			printf(" ");
			gotoxy(48, 16);
			printf(" ");
			gotoxy(16, 23);
			printf(" ");
			gotoxy(31, 23);
			printf(" ");
			while (!kbhit())
			{
				gotoxy(48, 23);
				a = flash(a);
			}
		}
		if (skip)
			break;
	}
	return ks;
}
void colorChangeMenu()
{
	textcolor(13);
	printf("   *\n");
	printf(" * *\n");
	printf("*  ********* | press");
	textcolor(12);
	printf(" E ");
	textcolor(13);
	printf("to return");
	rcolor();
	printf("           Press");
	textcolor(13);
	printf("  R  ");
	rcolor();
	printf("to reset colors\n");
	textcolor(13);
	printf(" * *\n");
	printf("   *\n");
	rcolor();
	printf("\n\n                           |C H A N G E  C O L O R S|\n\n\n\n");
	textcolor(mColor - 112);
	printf("  Predent Color : ");
	printf("□|         ");
	textcolor(9);
	printf("□         ");
	textcolor(10);
	printf("□         ");
	textcolor(11);
	printf("□         \n\n\n");
	printf("                              ");
	textcolor(12);
	printf("□         ");
	textcolor(13);
	printf("□         ");
	textcolor(14);
	printf("□         \n\n\n\n\n");
	textcolor(uColor - 112);
	printf("  Predent Color : ");
	printf("■|         ");
	textcolor(1);
	printf("■         ");
	textcolor(2);
	printf("■         ");
	textcolor(3);
	printf("■         \n\n\n");
	printf("                              ");
	textcolor(4);
	printf("■         ");
	textcolor(5);
	printf("■         ");
	textcolor(6);
	printf("■         \n");
	rcolor();
	printf("\n\n            Press");
	textcolor(13);
	printf("  W  A  S  D  ");
	rcolor();
	printf("to control,  Press");
	textcolor(13);
	printf("    Enter    ");
	rcolor();
	printf(" to choose\n\n");
}
int colorChange(int colorQuit)
{
	char input;
	int a = 1;
	int ks = colorQuit, myColor, skip = 0;
	while (!kbhit())
	{
		switch (colorQuit)
		{
		case 1:
			gotoxy(27, 11);
			myColor = 9;
			break;
		case 2:
			gotoxy(38, 11);
			myColor = 10;
			break;
		case 3:
			gotoxy(49, 11);
			myColor = 11;
			break;
		case 4:
			gotoxy(27, 14);
			myColor = 12;
			break;
		case 5:
			gotoxy(38, 14);
			myColor = 13;
			break;
		case 6:
			gotoxy(49, 14);
			myColor = 14;
			break;
		case 7:
			gotoxy(27, 19);
			unColor = 1;
			break;
		case 8:
			gotoxy(38, 19);
			unColor = 2;
			break;
		case 9:
			gotoxy(49, 19);
			unColor = 3;
			break;
		case 10:
			gotoxy(27, 22);
			unColor = 4;
			break;
		case 11:
			gotoxy(38, 22);
			unColor = 5;
			break;
		case 12:
			gotoxy(49, 22);
			unColor = 6;
			break;
		default:
			break;
		}
		a = flash(a);
	}
	ks = colorQuit;
	while (1)
	{
		input = getch();
		if (input >= 'A' && input <= 'Z')
			input += 32;
		switch (input)
		{
		case 'w':
			if (ks == 4)
				ks = 1;
			else if (ks == 5)
				ks = 2;
			else if (ks == 6)
				ks = 3;
			else if (ks == 7)
				ks = 4;
			else if (ks == 8)
				ks = 5;
			else if (ks == 9)
				ks = 6;
			else if (ks == 10)
				ks = 7;
			else if (ks == 11)
				ks = 8;
			else if (ks == 12)
				ks = 9;
			break;
		case 'a':
			if (ks == 2)
				ks = 1;
			else if (ks == 3)
				ks = 2;
			else if (ks == 5)
				ks = 4;
			else if (ks == 6)
				ks = 5;
			else if (ks == 8)
				ks = 7;
			else if (ks == 9)
				ks = 8;
			else if (ks == 11)
				ks = 10;
			else if (ks == 12)
				ks = 11;
			break;
		case 's':
			if (ks == 1)
				ks = 4;
			else if (ks == 2)
				ks = 5;
			else if (ks == 3)
				ks = 6;
			else if (ks == 4)
				ks = 7;
			else if (ks == 5)
				ks = 8;
			else if (ks == 6)
				ks = 9;
			else if (ks == 7)
				ks = 10;
			else if (ks == 8)
				ks = 11;
			else if (ks == 9)
				ks = 12;
			break;
		case 'd':
			if (ks == 1)
				ks = 2;
			else if (ks == 2)
				ks = 3;
			else if (ks == 4)
				ks = 5;
			else if (ks == 5)
				ks = 6;
			else if (ks == 7)
				ks = 8;
			else if (ks == 8)
				ks = 9;
			else if (ks == 10)
				ks = 11;
			else if (ks == 11)
				ks = 12;
			break;
		case '\r':
			skip = 2;
			break; //确定选择
		case 'e':
			skip = 1;
			break; //返回上级
		case 'r':
			skip = 3;
		default:
			break;
		} //copy by 2048
		if (!skip && ks == 1)
		{
			myColor = 9;
			gotoxy(38, 11);
			printf(" ");
			gotoxy(49, 11);
			printf(" ");
			gotoxy(27, 14);
			printf(" ");
			gotoxy(38, 14);
			printf(" ");
			gotoxy(49, 14);
			printf(" ");
			gotoxy(27, 19);
			printf(" ");
			gotoxy(38, 19);
			printf(" ");
			gotoxy(49, 19);
			printf(" ");
			gotoxy(27, 22);
			printf(" ");
			gotoxy(38, 22);
			printf(" ");
			gotoxy(49, 22);
			printf(" ");
			while (!kbhit())
			{
				gotoxy(27, 11);
				a = flash(a);
			}
		}
		if (!skip && ks == 2)
		{
			myColor = 10;
			gotoxy(27, 11);
			printf(" ");
			gotoxy(49, 11);
			printf(" ");
			gotoxy(27, 14);
			printf(" ");
			gotoxy(38, 14);
			printf(" ");
			gotoxy(49, 14);
			printf(" ");
			gotoxy(27, 19);
			printf(" ");
			gotoxy(38, 19);
			printf(" ");
			gotoxy(49, 19);
			printf(" ");
			gotoxy(27, 22);
			printf(" ");
			gotoxy(38, 22);
			printf(" ");
			gotoxy(49, 22);
			printf(" ");
			while (!kbhit())
			{
				gotoxy(38, 11);
				a = flash(a);
			}
		}
		if (!skip && ks == 3)
		{
			myColor = 11;
			gotoxy(27, 11);
			printf(" ");
			gotoxy(38, 11);
			printf(" ");
			gotoxy(27, 14);
			printf(" ");
			gotoxy(38, 14);
			printf(" ");
			gotoxy(49, 14);
			printf(" ");
			gotoxy(27, 19);
			printf(" ");
			gotoxy(38, 19);
			printf(" ");
			gotoxy(49, 19);
			printf(" ");
			gotoxy(27, 22);
			printf(" ");
			gotoxy(38, 22);
			printf(" ");
			gotoxy(49, 22);
			printf(" ");
			while (!kbhit())
			{
				gotoxy(49, 11);
				a = flash(a);
			}
		}
		if (!skip && ks == 4)
		{
			myColor = 12;
			gotoxy(27, 11);
			printf(" ");
			gotoxy(38, 11);
			printf(" ");
			gotoxy(49, 11);
			printf(" ");
			gotoxy(38, 14);
			printf(" ");
			gotoxy(49, 14);
			printf(" ");
			gotoxy(27, 19);
			printf(" ");
			gotoxy(38, 19);
			printf(" ");
			gotoxy(49, 19);
			printf(" ");
			gotoxy(27, 22);
			printf(" ");
			gotoxy(38, 22);
			printf(" ");
			gotoxy(49, 22);
			printf(" ");
			while (!kbhit())
			{
				gotoxy(27, 14);
				a = flash(a);
			}
		}
		if (!skip && ks == 5)
		{
			myColor = 13;
			gotoxy(27, 11);
			printf(" ");
			gotoxy(38, 11);
			printf(" ");
			gotoxy(49, 11);
			printf(" ");
			gotoxy(27, 14);
			printf(" ");
			gotoxy(49, 14);
			printf(" ");
			gotoxy(27, 19);
			printf(" ");
			gotoxy(38, 19);
			printf(" ");
			gotoxy(49, 19);
			printf(" ");
			gotoxy(27, 22);
			printf(" ");
			gotoxy(38, 22);
			printf(" ");
			gotoxy(49, 22);
			printf(" ");
			while (!kbhit())
			{
				gotoxy(38, 14);
				a = flash(a);
			}
		}
		if (!skip && ks == 6)
		{
			myColor = 14;
			gotoxy(27, 11);
			printf(" ");
			gotoxy(38, 11);
			printf(" ");
			gotoxy(49, 11);
			printf(" ");
			gotoxy(27, 14);
			printf(" ");
			gotoxy(38, 14);
			printf(" ");
			gotoxy(27, 19);
			printf(" ");
			gotoxy(38, 19);
			printf(" ");
			gotoxy(49, 19);
			printf(" ");
			gotoxy(27, 22);
			printf(" ");
			gotoxy(38, 22);
			printf(" ");
			gotoxy(49, 22);
			printf(" ");
			while (!kbhit())
			{
				gotoxy(49, 14);
				a = flash(a);
			}
		}
		if (!skip && ks == 7)
		{
			unColor = 1;
			gotoxy(27, 11);
			printf(" ");
			gotoxy(38, 11);
			printf(" ");
			gotoxy(49, 11);
			printf(" ");
			gotoxy(27, 14);
			printf(" ");
			gotoxy(38, 14);
			printf(" ");
			gotoxy(49, 14);
			printf(" ");
			gotoxy(38, 19);
			printf(" ");
			gotoxy(49, 19);
			printf(" ");
			gotoxy(27, 22);
			printf(" ");
			gotoxy(38, 22);
			printf(" ");
			gotoxy(49, 22);
			printf(" ");
			while (!kbhit())
			{
				gotoxy(27, 19);
				a = flash(a);
			}
		}
		if (!skip && ks == 8)
		{
			unColor = 2;
			gotoxy(27, 11);
			printf(" ");
			gotoxy(38, 11);
			printf(" ");
			gotoxy(49, 11);
			printf(" ");
			gotoxy(27, 14);
			printf(" ");
			gotoxy(38, 14);
			printf(" ");
			gotoxy(49, 14);
			printf(" ");
			gotoxy(27, 19);
			printf(" ");
			gotoxy(49, 19);
			printf(" ");
			gotoxy(27, 22);
			printf(" ");
			gotoxy(38, 22);
			printf(" ");
			gotoxy(49, 22);
			printf(" ");
			while (!kbhit())
			{
				gotoxy(38, 19);
				a = flash(a);
			}
		}
		if (!skip && ks == 9)
		{
			unColor = 3;
			gotoxy(27, 11);
			printf(" ");
			gotoxy(38, 11);
			printf(" ");
			gotoxy(49, 11);
			printf(" ");
			gotoxy(27, 14);
			printf(" ");
			gotoxy(38, 14);
			printf(" ");
			gotoxy(49, 14);
			printf(" ");
			gotoxy(27, 19);
			printf(" ");
			gotoxy(38, 19);
			printf(" ");
			gotoxy(27, 22);
			printf(" ");
			gotoxy(38, 22);
			printf(" ");
			gotoxy(49, 22);
			printf(" ");
			while (!kbhit())
			{
				gotoxy(49, 19);
				a = flash(a);
			}
		}
		if (!skip && ks == 10)
		{
			unColor = 4;
			gotoxy(27, 11);
			printf(" ");
			gotoxy(38, 11);
			printf(" ");
			gotoxy(49, 11);
			printf(" ");
			gotoxy(27, 14);
			printf(" ");
			gotoxy(38, 14);
			printf(" ");
			gotoxy(49, 14);
			printf(" ");
			gotoxy(27, 19);
			printf(" ");
			gotoxy(38, 19);
			printf(" ");
			gotoxy(49, 19);
			printf(" ");
			gotoxy(38, 22);
			printf(" ");
			gotoxy(49, 22);
			printf(" ");
			while (!kbhit())
			{
				gotoxy(27, 22);
				a = flash(a);
			}
		}
		if (!skip && ks == 11)
		{
			unColor = 5;
			gotoxy(27, 11);
			printf(" ");
			gotoxy(38, 11);
			printf(" ");
			gotoxy(49, 11);
			printf(" ");
			gotoxy(27, 14);
			printf(" ");
			gotoxy(38, 14);
			printf(" ");
			gotoxy(49, 14);
			printf(" ");
			gotoxy(27, 19);
			printf(" ");
			gotoxy(38, 19);
			printf(" ");
			gotoxy(49, 19);
			printf(" ");
			gotoxy(27, 22);
			printf(" ");
			gotoxy(49, 22);
			printf(" ");
			while (!kbhit())
			{
				gotoxy(38, 22);
				a = flash(a);
			}
		}
		if (!skip && ks == 12)
		{
			unColor = 6;
			gotoxy(27, 11);
			printf(" ");
			gotoxy(38, 11);
			printf(" ");
			gotoxy(49, 11);
			printf(" ");
			gotoxy(27, 14);
			printf(" ");
			gotoxy(38, 14);
			printf(" ");
			gotoxy(49, 14);
			printf(" ");
			gotoxy(27, 19);
			printf(" ");
			gotoxy(38, 19);
			printf(" ");
			gotoxy(49, 19);
			printf(" ");
			gotoxy(27, 22);
			printf(" ");
			gotoxy(38, 22);
			printf(" ");
			while (!kbhit())
			{
				gotoxy(49, 22);
				a = flash(a);
			}
		}
		else if (skip == 2)
		{
			if (ks < 7)
				mColor = myColor + 112;
			else
				uColor = unColor + 112;
			skip = 0;
			colorQuit = ks;
			return colorQuit;
		}
		else if (skip == 3)
		{
			mColor = 124;
			myColor = 9;
			uColor = 117;
			unColor = 5;
			return ks;
		}
		else if (skip == 1)
		{
			system("cls");
			return 0;
		}
	}
}
void show(int *chapter[0], int attempt) // 显示画面
{
	gotoxy(0, 0); // 光标移动到原点位置，以下重画清屏
	int i, j, t;
	t = hight - h; //美化图案
	textcolor(13);
	printf("   *\n");
	printf(" * *\n");
	printf("*  ********* | press");
	textcolor(12);
	printf(" E ");
	textcolor(13);
	printf("to return\n");
	printf(" * *\n");
	printf("   *\n\n\n");
	rcolor();
	printf("                        ---------------------------\n");
	while (t--) //对称图案
	{
		printf("                       |                           |\n");
	}
	for (i = 0; i < hight; i++)
	{
		printf("                       |       ");
		for (j = 0; j < width; j++)
		{
			if ((i == position_y) && (j == position_x))
			{
				textcolor(mColor);
				printf("□");
				rcolor();
			} //   输出笔所在位置o
			else if (chapter[level - 1][i * 6 + j] == 1 && i < h && j < l)
			{
				textcolor(uColor);
				printf("■");
				rcolor();
			} //   输出尚未走过位置@
			else if (chapter[level - 1][i * 6 + j] == -1 && i < h && j < l)
			{
				textcolor(mColor);
				printf("■");
				rcolor();
			} //   输出已经走过位置O
			else if (chapter[level - 1][i * 6 + j] == 0 && i < h && j < l)
			{
				textcolor(115);
				printf("  ");
				rcolor();
			} //   输出不能走的位置!
			else
				printf("  "); //   输出空格
		}
		printf("|");
		if (!i)
			printf("    Level:  %d", level);
		if (i == h - 2)
			printf("    Times Of Attemps:  %d", attempt);
		if (i == h)
		{
			printf(" ～(￣▽￣～)~ ↑");
			textcolor(9);
			printf("你是魔鬼吗??");
			rcolor();
		}
		printf("\n");
	}
	printf("                        --------------------------- \n");
	printf("                    \n");
	printf("                    \n");
	if (h == 8)
		printf("\n\n");
	printf("                       Press ");
	textcolor(13);
	printf(" R ");
	rcolor();
	printf(" to restart\n\n");
	printf("                       Press ");
	textcolor(13);
	printf(" N ");
	rcolor();
	printf(" to skip\n");

	//	HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
	//	SetConsoleTextAttribute(hwnd, BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE
	//								  |FOREGROUND_RED|FOREGROUND_BLUE);
	//控制台颜色的改变尚未成功
}
void startup() // 每一关数据初始化
{
	HideCursor();
	hight = 9;
	width = 10;
	int a = 0, b = 0;
	switch (level)
	{
	case 1:
		a = 2;
		b = 2;
		break;
	case 2:
		a = 1;
		b = 5;
		break;
	case 3:
		a = 0;
		b = 7;
		break;
	case 4:
		a = 0;
		b = 3;
		break;
	case 5:
		a = 0;
		b = 0;
		break;
	case 6:
		a = 0;
		b = 1;
		break;
	case 7:
		a = 0;
		b = 0;
		break;
	case 8:
		a = 5;
		b = 0;
		break;
	case 9:
		a = 5;
		b = 0;
		break;
	default:
		break;
	}
	position_x = a;
	position_y = b;

} //第一关 暂用
int *reset(int *chapter[0]) //重置关卡数据
{
	int m, n;
	for (m = 0; m < h; m++) //每次都初始化关卡
	{
		for (n = 0; n < l; n++)
		{
			chapter[level - 1][m * 6 + n] = all[level - 1][m * 6 + n];
		}
	}
	return chapter[0];
}
int updateWithInput(int *chapter[0]) // 与用户输入有关的更新
{
	char input;
	int a = 0;
	if (kbhit()) // 判断是否有输入
	{
		input = getch(); // 根据用户的不同输入来移动，不必输入回车
		if (input >= 'A' && input <= 'Z')
			input += 32;
		if (input == 'a')
		{
			chapter[level - 1][position_y * 6 + position_x] = -1;
			position_x--; // 位置左移
			if (chapter[level - 1][position_y * 6 + position_x] < 1 || position_y > h - 1 || position_x > l - 1 || position_x < 0 || position_y < 0)
				position_x++;
		}
		if (input == 'd')
		{
			chapter[level - 1][position_y * 6 + position_x] = -1;
			position_x++; // 位置右移
			if (chapter[level - 1][position_y * 6 + position_x] < 1 || position_y > h - 1 || position_x > l - 1 || position_x < 0 || position_y < 0)
				position_x--;
		}
		if (input == 'w')
		{
			chapter[level - 1][position_y * 6 + position_x] = -1;
			position_y--; // 位置上移
			if (chapter[level - 1][position_y * 6 + position_x] < 1 || position_y > h - 1 || position_x > l - 1 || position_x < 0 || position_y < 0)
				position_y++;
		}
		if (input == 's')
		{
			chapter[level - 1][position_y * 6 + position_x] = -1;
			position_y++; // 位置下移
			if (chapter[level - 1][position_y * 6 + position_x] < 1 || position_y > h - 1 || position_x > l - 1 || position_x < 0 || position_y < 0)
				position_y--;
		}
		else if (input == 'r')
			a = 1; // 重新开始
		else if (input == 'n')
			a = 2;
		else if (input == 'e')
			a = 3;
	}
	return a;
}
int exam(int *chapter[0]) //用于每一关的检测,如果剩余有@,则该关未通过
{
	int bOK = 0; //是否通过监测数据
	int m = 0, n = 0;
	for (m = 0; m < h; m++) //检测是否均为通过,若是, 则返回0,否贼返回!0
	{
		for (n = 0; n < l; n++)
		{
			if (chapter[level - 1][m * 6 + n] > 0)
			{
				if (m == position_y && n == position_x)
					continue;
				bOK += 1;
			}
		}
	}
	return bOK;
}
void praise() //通关显示
{

	printf("\n\n\n\n");
	printf("                                  恭喜你通关啦!                    \n\n\n\n\n\n\n\n");
	textcolor(14);
	printf("   **         **   ****    *****   ********     ****     ******   **     **  \n");
	printf("    **       **     **    **   **     **      **    **   **  **    **   **   \n");
	printf("     **     **      **   **           **      *      *   **  **     ** **    \n");
	printf("      **   **       **   **           **      *      *   ******      ***     \n");
	printf("       ** **        **   **           **      *      *   **  *        *      \n");
	printf("        ***         **    **   **     **      **    **   **   *       *      \n");
	printf("         *         ****    *****      **        ****     **    *      *      \n");
	rcolor();
}
void help() //显示提示
{
	textcolor(13);
	printf("   *\n");
	printf(" * *\n");
	printf("*  ********* | press");
	textcolor(12);
	printf(" E ");
	textcolor(13);
	printf("to return\n");
	printf(" * *\n");
	printf("   *\n");
	rcolor();
	printf("\n\n");
	textcolor(28);
	printf("                                                            \n");
	printf("      '一笔画完'小游戏,不重复地经过所有未走过的单元格       \n");
	printf("                                                            \n");
	printf("      你的当前所在位置用正方形边框□表示                    \n");
	printf("                                                            \n");
	printf("      通过关卡来点亮他,当所有关卡通过时,获得游戏胜利        \n");
	printf("                                                            \n");
	printf("      settings:                                             \n");
	printf("                                                            \n");
	printf("      up : W  down : S  left : A  right : D                 \n");
	printf("                                                            \n");
	printf("      restart : R  skip : N                                 \n");
	printf("                                                            \n");
	printf("      return : E                                            \n");
	printf("                                                            \n");
	printf("--------------------------游戏帮助--------------------------\n");
	textcolor(29);
	printf("                                                            \n");
	printf("                                                            \n");
	printf("                   Made By : Jola                           \n");
	printf("                                                            \n");
	printf("                                                            \n");
	rcolor();
}
void helpExit()
{
	char input;
	while (1)
	{
		input = getch();
		if (input >= 'A' && input <= 'Z')
			input += 32;
		if (input == 'e')
		{
			system("cls");
			break;
		}
	}
}
int main(int argc, char *argv[])
{
	HideCursor();
	all[0] = le1, all[1] = le2, all[2] = le3,
	all[3] = le4, all[4] = le5, all[5] = le6,
	all[6] = le7, all[7] = le8, all[8] = le9;
	level = 1, l = 6;
	mColor = 124, uColor = 117, myColor = 9, unColor = 5;
	change_h(); //初始化h
	int fi = 0;
	for (fi = 0; fi < 9; fi++)
	{
		finish[fi] = 0;
	}
	int attempt = 0; //尝试次数
	int m = 0, n = 0;
	int screen = 0;
	int scr = 1, colorQuit = 1;
	int choosingExit = 0;
	int bOK = 0; // 是否通过.0为未通过,1为通过
	int level1[6][6], level2[6][6], level3[8][6],
		level4[8][6], level5[8][6], level6[8][6],
		level7[8][6], level8[8][6], level9[8][6];
	int *p1 = &level1[0][0], *p2 = &level2[0][0],
		*p3 = &level3[0][0], *p4 = &level4[0][0],
		*p5 = &level5[0][0], *p6 = &level6[0][0],
		*p7 = &level7[0][0], *p8 = &level8[0][0],
		*p9 = &level9[0][0];								//指针化
	int *chapter[9] = {p1, p2, p3, p4, p5, p6, p7, p8, p9}; //将每个复制下来地关卡
	int t = 0;												//操作次数
	while (1)
	{
		gotoxy(0, 0);
		colorQuit = 1;
		mainScreen();
		screen = screenWithInput();
		while (1)
		{
			if (screen == 1)
			{
				system("cls");
				chapterMenu();
				choosingExit = chapterChoosing();
				if (!choosingExit)
				{
					system("cls");
					break;
				}
				system("cls");
				while (1)
				{
					reset(chapter);
					startup(); //初始化当前关卡
					while (1)
					{
						while (bOK || !t) //如果过了bOK = 0
						{
							scr = 0;
							bOK = exam(chapter); //检测是否通关
							int a = 0;
							show(chapter, attempt);
							a = updateWithInput(chapter);
							if (a == 1)
							{
								reset(chapter);
								startup();
								attempt++;
							}				 //检测重新开始
							else if (a == 2) //若a = 2 代表着下一关,使scr = 1
							{
								scr = 1;
								break;
							}
							else if (a == 3) //若a = 3 代表着返回上界面,使scr = 0
							{
								scr = 2;
								break;
							}
							t++;
						}
						if (scr == 2) //选关
						{
							system("cls");
							attempt = 0;
							break;
						}
						else if (scr < 2) //下一关
						{
							if (!scr)
								finish[level - 1] = 1;
							if (!scr)
							{
								int allFinish = 0;
								for (fi = 0; fi < 9; fi++)
								{
									if (finish[fi] == 1)
										allFinish++;
								}
								if (allFinish == 9) //9关均通过则进入通关界面 退出游戏
								{
									system("cls"); //清屏
									praise();
									Sleep(5000);
									return 1;
								}
							}
							loading(attempt, scr);
							system("cls");
							bOK = 0, t = 0, attempt = 0; //操作次数归零,尝试次数归零,通关情况归零
							if (level < 9)
								level++;
							else
							{
								textcolor(206);
								if (scr == 1)
								{
									gotoxy(28, 14);
									printf("   W A R N I N G ! ! ! ");
								}
								gotoxy(28, 17);
								printf("This is the last level!");
								rcolor();
								Sleep(1100);
								scr = 2;
								break;
							}
							change_h();
							startup();
							reset(chapter);
						}
					}
					if (scr == 2)
					{
						level = 1;
						change_h();
						break;
					}
				}
				if (level == 6 && scr < 2)
					break;
			}
			else if (screen == 2)
			{

				while (colorQuit)
				{
					system("cls");
					colorChangeMenu();
					colorQuit = colorChange(colorQuit);
				}

				break;
			}
			else if (screen == 3)
			{
				system("cls");
				help();
				helpExit();
				break;
			}
		}
	}
	return 0;
}
