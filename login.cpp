#include "stdio.h"
#include "conio.h"
#include "windows.h"
#include "graphics.h"
#include "menu.h"
#include "stdlib.h"
#include "student-management.h"
#include "cache.h"
#include "input.h"
#include "users.h"
#include"stdafx.h"
//Hàm tạo giao diện đăng nhập cho người dùng
void LayoutLogin(char username[], char password[])
{
	Yescursortype();//dau nhap nhay
	DrawAppNameTab(0, 2);// chu den, nen green
						 //Vẽ khung đăng nhập
	drawRectangle(47, 6, 27, 12, 3);// x=47, y=6, rong=27, dai=10, mau=xanh da troi
	gotoxy(48, 7);//xuong dong
	printf("Username: ");
	gotoxy(48, 9);// xuong dong chua hang de ve khung trang de nhap vao
	printf("Password: ");

	//Vẽ khung input
	drawRectangle(48, 8, 25, 1, 15);
	drawRectangle(48, 10, 25, 1, 15);
	gotoxy(57, 11);
	printf("ENTER to login");

	//Nhập
	gotoxy(48, 8);
	InputUsername(username);
	gotoxy(48, 10);
	InputPassword(password);
	gotoxy(44, 0);
}
//================================================================================
//Hàm trả về loại người dùng, -1 nếu username hoặc password không chính xác
int Login(char username[], char password[])
{
	/*
	1:staff
	2: lecturer
	3: student
	*/
	FILE*f;
	errno_t error;
	error = fopen_s(&f, "user/staff/hatu.txt", "r");
	if (error == 0)
	{
		Accounts ad;
		fread(&ad, sizeof(Accounts), 1, f);
		fclose(f);
		//Tài khoản Admin luôn ở trạng thái ACTIVE
		if ((strcmp(username, ad.username) == 0) && (strcmp(password, ad.password) == 0))
		{
			WriteCacheAccount(username, password);
			return 1;
		}
	}
	else
	{
		if (strcmp(username, "hatu") == 0 && strcmp(password, "123456") == 0)
		{
			WriteCacheAccount(username, password);
			Accounts admin;
			strcpy(admin.username, "hatu");
			strcpy(admin.password, "123456");
			admin.active = true;
			strcpy(admin.fullname, "Hoang Anh Tu");
			admin.sex = 2;
			admin.type = 1;
			WriteAccount("user/staff/hatu.txt", admin);
			return 1;
		}
	}

	error = fopen_s(&f, "user/staff/ntmphuc.txt", "r");
	if (error == 0)
	{
		Accounts ad;
		fread(&ad, sizeof(Accounts), 1, f);
		fclose(f);
		//Tài khoản Admin luôn ở trạng thái ACTIVE
		if ((strcmp(username, ad.username) == 0) && (strcmp(password, ad.password) == 0))
		{
			WriteCacheAccount(username, password);
			return 1;
		}
	}
	else
	{
		if (strcmp(username, "ntmphuc") == 0 && strcmp(password, "123456") == 0)
		{
			WriteCacheAccount(username, password);
			Accounts admin;
			strcpy(admin.username, "ntmphuc");
			strcpy(admin.password, "123456");
			admin.active = true;
			strcpy(admin.fullname, "Nguyen Thi Minh Phuc");

			admin.sex = 2;
			admin.type = 1;
			WriteAccount("user/staff/ntmphuc.txt", admin);
			return 1;
		}
	}

	error = fopen_s(&f, "user/staff/ltathao.txt", "r");
	if (error == 0)
	{
		Accounts ad;
		fread(&ad, sizeof(Accounts), 1, f);
		fclose(f);
		//Tài khoản Admin luôn ở trạng thái ACTIVE
		if ((strcmp(username, ad.username) == 0) && (strcmp(password, ad.password) == 0))
		{
			WriteCacheAccount(username, password);
			return 1;
		}
	}
	else
	{
		if (strcmp(username, "ltathao") == 0 && strcmp(password, "654321") == 0)
		{
			WriteCacheAccount(username, password);
			Accounts admin;
			strcpy(admin.username, "ltathao");
			strcpy(admin.password, "654321");
			admin.active = true;
			strcpy(admin.fullname, "Le Thi Anh Thao");
			admin.sex = 2;
			admin.type = 1;
			WriteAccount("user/staff/ltathao.txt", admin);
			return 1;
		}
	}

	char link2[100] = "user/lecturer/";
	strcat(link2, username);
	strcat(link2, ".txt");
	error = fopen_s(&f, link2, "r");
	if (error == 0)
	{
		Accounts member;
		while (fread(&member, sizeof(Accounts), 1, f) != NULL)
		{
			if ((strcmp(username, member.username) == 0) && (strcmp(password, member.password) == 0))
			{
				if (member.active)
				{
					WriteCacheAccount(username, password);
					return 2;
				}
			}
		}
		fclose(f);
	}
	char link3[100] = "user/student/";
	strcat(link3, username);
	strcat(link3, ".txt");
	error = fopen_s(&f, link3, "r");
	if (error == 0)
	{
		Accounts member;
		while (fread(&member, sizeof(Accounts), 1, f) != NULL)
		{
			if ((strcmp(username, member.username) == 0) && (strcmp(password, member.password) == 0))
			{
				if (member.active)
				{
					WriteCacheAccount(username, password);
					return 3;
				}
			}
		}
		fclose(f);
	}

	return -1;
}
//=====================================================================================================
//Hàm nhận vào loại người dùng để đưa vào menu tương ứng
void CaseLogin(int n)
{
	FILE* f = fopen("cache/currentMenu.txt", "w");	//Viết vào cache trạng thái menu
	FILE* g = fopen("cache/currentType.txt", "w");	//Viết vào cache loại người dùng
	switch (n)
	{/*
	countFeatures <= 15
	list = "xxxxxxxxxxx"
	x = 1 : show feature
	x = 0 : hide feature
	+ f0: Cập nhật thông tin cá nhân (admin, lecturer, student)
	+ f1: Đổi mật khẩu (admin, lecturer, student)
	+ f2: Tạo student (admin)
	+ f3: Tao lecturer(admin)
	+ f4: Quản lý sinh vien (admin)
	+ f5: Quan li diem cua sinh vien (lecturer)
	+ f6: Đăng xuất (admin, lecturer, student)
	*/
	case 1:	//staff
		fprintf(g, "%s", "1");
		fclose(g);
		fprintf(f, "%d %s", 6, "1111101");
		fclose(f);
		Menu(6, "1111101");
		break;
		//================================================================================================
	case 2:	//lecturer
		fprintf(g, "%s", "2");
		fclose(g);
		fprintf(f, "%d %s", 4, "1100011");
		fclose(f);
		Menu(4, "1100011");
		break;
	case 3:	//student
		fprintf(g, "%s", "3");
		fclose(g);
		fprintf(f, "%d %s", 3, "1100001");
		fclose(f);
		Menu(3, "1100001");
		break;
	default:
		break;
	};
}

//Lặp lại bước nhập <USERNAME> và <PASSWORD> đến khi nào đăng nhập thành công hoặc ấn phím [ESC]
void RepeatInput(char username[], char password[])
{
	int statusLogin;
	SetBG();
	do
	{
		drawRectangle(36, 9, 48, 3, 15);
		LayoutLogin(username, password);
		statusLogin = Login(username, password);
		if (statusLogin == -1)
		{
			drawRectangle(36, 9, 48, 3, 12);
			gotoxy(51, 10);
			printf("DANG NHAP THAT BAI");
			Sleep(900);
		}
	} while (statusLogin == -1);
	CaseLogin(statusLogin);
}

//Đăng xuất
void LogOut()
{
	WriteCacheAccount("###", "###");
	char username[21], password[21];
	Title(" ");
	drawRectangle(36, 6, 48, 15, 15);
	RepeatInput(username, password);
}