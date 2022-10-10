#include "gitver.h"
#define ADD "add:"
#define ADDED_FILE "added_file:"
#define ADDED_FILE_END "END_OF_FILE"

int git_init() //Дроп в файл и так далее
{ 
    FILE *f = fopen(FILENAME, "w"); //функция фопен создаст или пересоздаст файл filename и откроет его в режиме записи
    if (f == NULL)
        return -1;

    fprintf(f, "%s", "init\n"); //TODO добавить дату
    fclose(f);
    printf("hello\n");
    return 0;
}

FILE* fl_open(char* command) //TODO Проверить нужная ли команда a w r 
{
    FILE *f = fopen(FILENAME, command); //функция фопен создаст или пересоздаст файл filename и откроет его в режиме записи
    if (f == NULL)
        return -1;
    printf("hello\n");
    return f;
}

void git_add(char* filename)
{
    FILE* fl = fl_open("a"); // Открыл файл в режиме дозаписи
    fprintf(fl, "%s %s", ADD, filename); //В формате строки записываю в файл новый отслеживаемый
    fprintf(fl, "%s", "\n");


    FILE* added_file = fopen(filename, "r"); //Пытаемся открыть добавленный файл
    if (added_file == NULL)
    {
        printf("Can't open file");
        return -1;
    }

    fprintf(fl, "%s\n", ADDED_FILE);
    // file = fopen("fscanf.txt", "r");
    
    
    char * text = calloc(2048, sizeof(char));// 2048 это максимальная длина строки в байтах
    if (!text)
    {
        printf("not enough memory.\n");
        return 1;
    }
    
    
    while (fgets(text, 2048, added_file) != NULL)
    {
        fputs(text, fl);
    }
    fclose(added_file);
    fclose(fl);
    free(text); 
    return 0;
}