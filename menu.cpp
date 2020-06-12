#include "stdafx.h"
#include "graphics.h"
#include "windows.h"
#include "conio.h"
#include "login.h"
#include "student-management.h"
#include "users.h"
#include "student.h"
#include "cache.h"

//Gọi tính năng thứ <I>
void Action(int i)
{
	switch (i)
	{
	case 0:
		ModifyInfo();
		break;
	case 1:
		ChangePassword();
		break;
	case 2:
		InputStudentData();
		break;
	case 3: 
		InputLecturerData();
		break;
	case 4:
		CaseStudentsMenu();
		break;
	case 5:
		InputScore();
		break;
	case 6:
		printf("Dang xuat");
		LogOut();
		break;
	default:
		break;
	}
}


//Vẽ vùng [MENU]
void MakeFieldMenu(int n)
{
	DrawAppNameTab(15, 2);
	//In lời chào
	char user[21], pass[21], greeting[45] = "Xin chao ";
	ReadCacheAccount(user, pass);
	strcat(greeting, user);
	Title(greeting);
	//Xóa khung đăng nhập
	drawRectangle(47, 6, 27, 10, 15);
	//Vẽ khung menu
	drawRectangle(36, 6, 48, n, 3);
}

//In tính năng
void PrintFeature(char str[])
{
	printf("%s", str);
}

//Tạo [MENU] di chuyển lên xuống
void MoveSelect(int n, char f[15][50], char list[])
{
	//Default
	int CurrentSelect = 0, CurrentLine = 7;
	drawRectangle(36, CurrentLine, 48, 1, 1);
	textBgColor(15, 1);
	gotoxy(47, 6);
	PrintFeature(f[0]);
	/*
	#UP: 72
	#DOWN: 80
	*/
	char ch = getch();
	while (ch != 27)	//ESC
	{
		//UP
		if ((ch == 72) && (CurrentSelect>0))
		{
			drawRectangle(36, CurrentLine, 48, 1, 3);
			textBgColor(0, 3);
			gotoxy(47, CurrentLine);
			PrintFeature(f[CurrentSelect]);

			CurrentSelect--;
			CurrentLine--;

			drawRectangle(36, CurrentLine, 48, 1, 1);
			textBgColor(15, 1);
			gotoxy(47, CurrentLine);
			PrintFeature(f[CurrentSelect]);
		}
		//DOWN
		if ((ch == 80) && (CurrentSelect<n - 1))
		{
			drawRectangle(36, CurrentLine, 48, 1, 3);
			textBgColor(0, 3);
			gotoxy(47, CurrentLine);
			PrintFeature(f[CurrentSelect]);

			CurrentSelect++;
			CurrentLine++;

			drawRectangle(36, CurrentLine, 48, 1, 1);
			textBgColor(15, 1);
			gotoxy(47, CurrentLine);
			PrintFeature(f[CurrentSelect]);
		}
		//ENTER
		if (ch == 13)
		{
			int count = -1;
			for (int i = 0; i < strlen(list); i++)
			{
				if (list[i] == '1')
					count++;
				if (count == CurrentSelect)
				{
					Action(i);
					break;
				}
			}
		}

		if (ch == 13) break;
		ch = getch();
	}
}

//In ra [MENU] với số lượng <countFeatures> tính năng và danh sách <list> các tính năng
void Menu(int countFeatures, char list[])
{
	   
	
	char f[15][50] =
	{
		"Cap nhat thong tin",
		"Doi mat khau",
		"Tao sinh vien moi",
		"Them giao vien",
		"Quan li sinh vien",
		"Nhap diem cua sinh vien",
		"Dang xuat"
	};
	Nocursortype();
	MakeFieldMenu(countFeatures);
	int line = 7;
	char fUse[15][50];
	int i = 0;
	for (int fe = 0; fe < 7; fe++)
	{
		if (list[fe] == '1')
		{
			strcpy_s(fUse[i++], f[fe]);
			gotoxy(47, line);
			line++;
			PrintFeature(f[fe]);
		}
	}

	MoveSelect(countFeatures, fUse, list);
	gotoxy(44, 0);
}