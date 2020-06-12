#include "stdafx.h"
#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "linked-list-student.h"
#include "string.h"
#include "student-management.h"

//Khởi tạo Danh sách liên kết rỗng
void Init(List_Student &L)
{
	L.head = NULL;
	L.tail = NULL;
}

//Kiểm tra Danh sách liên kết rỗng hay không?
int Isempty(List_Student L)
{
	return (L.head == NULL);
}

//Hàm trả về độ dài của Danh sách liên kết
int Len(List_Student L)
{
	Node_Student *PH = L.head, *PT = L.tail; //PH duyệt từ đầu danh sách, PT duyệt từ cuối danh sách
	int i = 0; //Biến đếm
	if (PH != NULL) i = 1;
	while (PH != NULL)
	{
		if (PH == PT) break;
		PH = PH->next;
		i++;
		if (PH == PT) break;
		PT = PT->prev;
		i++;
	}
	return i;
}

//Tạo một Node chứa thông tin <X>
Node_Student *Make_Node(student x)
{
	Node_Student *P = (Node_Student *)malloc(sizeof(Node_Student));
	P->data = x;
	P->prev = NULL;
	P->next = NULL;
	return P;
}

//Chèn <X> vào đầu Danh sách liên kết
void Insert_first(List_Student &L, student x)
{
	Node_Student *P;
	P = Make_Node(x);
	if (Isempty(L))
	{
		L.head = P;
		L.tail = P;
	}
	else
	{
		P->next = L.head;
		L.head->prev = P;
		L.head = P;
	}
}

List_Student GetStudentsData()
{
	FILE *f, *g;
	char username[14];
	List_Student L;
	Init(L);
	errno_t err = fopen_s(&f, "user/student/List.txt", "r");
	errno_t err_2;
	if (err == 0)
	{
		while (fread(&username, sizeof(username), 1, f) != 0)
		{
			char link[100] = "student/";
			strcat(link, username);
			strcat(link, ".txt");
			err_2 = fopen_s(&g, link, "r");
			if (err_2 == 0)
			{
				student student;
				fread(&student, sizeof(student), 1, g);
				fclose(g);
				if (student.acc.active)
				{
					Insert_first(L, student);
				}
			}
		}
		fclose(f);
	}
	return L;
}

void FreeLinkList(List_Student L)
{
	Node_Student *p = L.head;
	while (p != NULL)
	{
		Node_Student *q = p->next;
		free(p);
		p = q;
	}
}