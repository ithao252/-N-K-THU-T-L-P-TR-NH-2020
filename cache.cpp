#include "stdio.h"
#include "conio.h"
#include "windows.h"
#include "graphics.h"
#include "menu.h"
#include "stdlib.h"
#include "student-management.h"
#include "cache.h"

//Ghi vào cache Tài khoản và mật khẩu đăng nhập hiện hành khi co nguoi dang nhap
void WriteCacheAccount(char username[], char password[])
{
	FILE *f = fopen("cache/currentAccount.txt", "w");
	fprintf(f, "%s %s", username, password);
	fclose(f);
}

//Đọc từ cache Tài khoản và mật khẩu đăng nhập hiện hành
int ReadCacheAccount(char username[], char password[])
{
	FILE *f = fopen("cache/currentAccount.txt", "r");
	if (f)
	{
		fscanf(f, "%s%s", username, password);
		fclose(f);
		if (strcmp(username, "###") == 0)
			return 0;
		return 1;
	}
}

//Hàm trả về phân quyền của tài khoản hiện tại
int ReadClassification()
{
	int n;
	FILE *f = fopen("cache/currentType.txt", "r");
	if (f)
	{
		fscanf(f, "%d", &n);
		fclose(f);
		return n;
	}
	return -1;
}

//Đọc từ cache định dạng [MENU]
void ReadMenuData(int &n, char list[])
{
	FILE *f = fopen("cache/currentMenu.txt", "r");
	if (f)
	{
		fscanf(f, "%d%s", &n, list);
	}
	fclose(f);
}

//Đọc từ cache định dạng [STUDENTSMENU]
void ReadStudentMenuData(int &n, char list[])
{
	FILE *f = fopen("cache/currentStudentMenu.txt", "r");
	if (f)
	{
		fscanf(f, "%d%s", &n, list);
	}
	fclose(f);
}

//Đọc từ cache định dạng [COURSESMENU]
void ReadCourseMenuData(int &n, char list[])
{
	FILE *f = fopen("cache/currentCourseMenu.txt", "r");
	if (f)
	{
		fscanf(f, "%d%s", &n, list);
	}
	fclose(f);
}


//Đọc từ cache định dạng [LECTURERMENU]
void ReadLecturerMenuData(int &n, char list[]) {
	FILE *f = fopen("cache/currentLecturerMenu.txt", "r");
	if (f)
	{
		fscanf(f, "%d%s", &n, list);
	}
	fclose(f);
}
//Đọc từ cache định dạng [CLASSMENU]
void ReadClassMenuData(int &n, char list[]){
	FILE *f = fopen("cache/currentClassMenu.txt", "r");
	if (f)
	{
		fscanf(f, "%d%s", &n, list);
	}
	fclose(f);


}

//Đọc từ cache định dạng [ScoreMENU]
void ReadScoreMenuData(int &n, char list[]){
	FILE *f = fopen("cache/currentScoreMenu.txt", "r");
	if (f)
	{
		fscanf(f, "%d%s", &n, list);
	}
	fclose(f);

}