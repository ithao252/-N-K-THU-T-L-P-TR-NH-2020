#pragma once
//Ghi vào cache Tài khoản và mật khẩu đăng nhập hiện hành
void WriteCacheAccount(char username[], char password[]);

//Đọc từ cache Tài khoản và mật khẩu đăng nhập hiện hành
int ReadCacheAccount(char username[], char password[]);

//Hàm trả về phân quyền của tài khoản hiện tại
int ReadClassification();

//Đọc từ cache định dạng [MENU]
void ReadMenuData(int &n, char list[]);

//Đọc từ cache định dạng [STUDENTMENU]
void ReadStudentMenuData(int &n, char list[]);

//Đọc từ cache định dạng [COURSEMENU]
void ReadCourseMenuData(int &n, char list[]);

//Đọc từ cache định dạng [CLASSMENU]
void ReadClassMenuData(int &n, char list[]);

//Đọc từ cache định dạng [LECTURERMENU]
void ReadLecturerMenuData(int &n, char list[]);
//Đọc từ cache định dạng [ScoreMENU]
void ReadScoreMenuData(int &n, char list[]);