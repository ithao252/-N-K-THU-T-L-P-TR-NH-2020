#pragma once
#include"student-management.h"
//Cho biết username có khả dụng cho việc tạo mới hay không?
bool AcceptUser(char username[]);

//Thêm Account
void AddAccountStudent(student A);
void AddAccountLecturer(lecturer L);

//Bảng nhập thông tin Tạo Student mới
void InputStudentData();

//Bảng nhập thông tin Tạo Lecturer mới
void InputLecturerData();

//Hàm trả về dữ liệu tài khoản theo đường dẫn link
Accounts ReadAccount(char link[]);

//Viết dữ liệu user vào file với đường dẫn link
int WriteAccount(char link[], Accounts user);

//Thay đổi mật khẩu
void ChangePassword();

//Chỉnh sửa thông tin
void ModifyInfo();