#include "windows.h"
#include "stdio.h"
#include"student-management.h"
#include "conio.h"
#include"stdafx.h"
struct IMG
{
	int a[30][120];
	int width;
	int height;
};



void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}


void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}


void textColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


void textBgColor(int colorText, int colorBG)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (colorBG << 4) | colorText);
}


void drawRectangleBorder(int positionX, int positionY, int width, int height, int color)
{
	textBgColor(0, color);
	for (int x = 0; x < width; x++)
	{
		gotoxy(positionX + x, positionY);
		printf("%c", ' ');
		gotoxy(positionX + x, positionY + height - 1);
		printf("%c", ' ');
	}
	for (int y = 0; y < height; y++)
	{
		gotoxy(positionX, positionY + y);
		printf("%c", ' ');
		gotoxy(positionX + width - 1, positionY + y);
		printf("%c", ' ');
	}
	gotoxy(44, 0);
	textBgColor(0, color);
}


void drawRectangle(int positionX, int positionY, int width, int height, int color)
{
	textBgColor(0, color);
	gotoxy(positionX, positionY);
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			gotoxy(positionX + x, positionY + y);
			printf("%c", ' ');
		}
	}
	gotoxy(44, 0);
}

int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}


int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}


void SetBG()
{
	drawRectangle(0, 0, MAXWIDTH, MAXHEIGHT, 15);
	textBgColor(0, 15);
	system("cls");

}

void DrawAppNameTab(int TextColor, int BgColor)
{
	drawRectangle(47, 2, 27, 3, BgColor);
	gotoxy(48, 3);
	textBgColor(TextColor, BgColor);
	printf("PHAN MEM QUAN LY SINH VIEN");
}



void Title(char title[45])
{
	drawRectangle(48, 5, 36, 1, 15);
	gotoxy(47, 5);
	textBgColor(0, 15);
	printf("%s", title);
}

void VerticalLine(int PosX, int PosY, int Length, int TextColor, int BgColor)
{
	textBgColor(TextColor, BgColor);
	for (int i = PosY; i < PosY + Length; i++)
	{
		gotoxy(PosX, i);
		printf("%c", char(179));
	}
}

void HorizontalLine(int PosX, int PosY, int Length, int TextColor, int BgColor)
{
	textBgColor(TextColor, BgColor);
	for (int i = PosX; i < PosX + Length; i++)
	{
		gotoxy(i, PosY);
		printf("%c", char(196));
	}
}


void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}


void Yescursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
