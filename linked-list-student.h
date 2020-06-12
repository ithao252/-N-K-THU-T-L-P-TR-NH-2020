#pragma once
#include "student-management.h"
//Khởi tạo Danh sách liên kết rỗng
void Init(List_Student &L);

//Kiểm tra Danh sách liên kết rỗng hay không?
int Isempty(List_Student L);

//Hàm trả về độ dài của Danh sách liên kết
int Len(List_Student L);

//Tạo một Node chứa thông tin <X>
Node_Student *Make_Node(student x);

//Chèn <X> vào đầu Danh sách liên kết
void Insert_first(List_Student &L, student x);

List_Student GetStudentsData();
List_Student GetScoreData();
void FreeLinkList(List_Student L);