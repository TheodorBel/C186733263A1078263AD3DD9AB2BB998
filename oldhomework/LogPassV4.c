#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <windows.h>

int main(void)
{
	char datalogin[6] = "test1"; // Массивы для заданных пароля и логина
	char datapassword[6] = "aboba";
	char userlogin[16] = "00000"; // Массивы для ввода пользователя
	char userpassword[16] = "aziza";
	int usertry = 0;
	while (usertry < 5) // Цикл для проверки введенных данных
	{
		++usertry;
		printf ("your login:\n");
		scanf ("%s", userlogin); //Ввод данных
		printf ("your password:\n");
		scanf ("%s", userpassword); //Еще один ввод
		if ((strcmp(datalogin, userlogin) == 0) && (strcmp(datapassword, userpassword)) == 0) //Сравнение данных и ответ в случае правильного ввода
		{
			printf("hello admin!");
			break;
		}
		else if ((strcmp(datalogin, userlogin) != 0) || (strcmp(datapassword, userpassword)) != 0) // Сравнение данных и ответ в случае неправильного ввода
		{
			printf("Incorrect\n");
			if (usertry == 3)
			{
				printf("Wait 3 sec before try again\n");
				Sleep(3000);
			}
		}
	}
	return 0;
}