﻿#pragma once

#include "student-management.h"
// Khởi tạo thư mục
void initSystemFolder();
//Tạo đường dẫn bằng cách ghép 3 chuỗi s1+s2+s3
char *Path(char s1[], char s2[], char s3[]);

//Tạo chuỗi mã độc giả
char *toStr(long n);