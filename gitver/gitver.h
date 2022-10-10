#ifndef GITVER_H
#define GITVER_H
#include <stdio.h>
#include <stdlib.h>
#define FILENAME ".fl.txt"

int git_init(); //Будет создавать файл .fl

FILE fl_open(); //Открывает файл и дает на него указатель

char* charcheck_change(FILE* current); // Проверяет наличие изменений 

char status(); // Выводи в консоль результат сравнения

void git_commit(); // Пишет в файл гита изменения

void git_add(char* filename); // Принимает название файла и добавляет его в отслеживаемые

// commit: No
// Autor: Anton
// Data: 1020;22;22
// message; commentaryy
// filename: Azaiza.txt
// str1: add: aaaaa
// str2: del: bbbbbb
// endoffile:
//endofcommit:
//
//
//


//file 5txt now suspect
//
//

#endif