#include "stdlib.h"
#include "string.h"
#include "stdafx.h"
#include "student-management.h"
#include <direct.h>

// Khởi tạo thư mục
void initSystemFolder()
{
	mkdir("score");
	mkdir("cache");
	mkdir("user");
	mkdir("user/admin");
	mkdir("user/experts");
	mkdir("user/managers");
}
//Tạo đường dẫn bằng cách ghép 3 chuỗi s1+s2+s3
char *Path(char s1[], char s2[], char s3[])
{
	char s[128];
	s[0] = '\0';
	strcpy(s, s1);
	strcat(s, s2);
	strcat(s, s3);
	s[strlen(s)] = '\0';
	return s;
}

//Tạo chuỗi mã sinh vien
char *toStr(long n)
{
	char str[10];
	sprintf(str, "%ld", n);
	char S[10];
	S[0] = '\0';
	int count = 9 - strlen(str);
	while (count > 0)
	{
		strcat(S, "0");
		count--;
	}
	strcat(S, str);
	S[9] = '\0';
	return S;
}