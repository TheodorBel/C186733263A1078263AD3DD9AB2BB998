#include "gitver.h"

int git_init() //Дроп в файл и так далее
{ 
    FILE *f = fopen(FILENAME, "w"); //функция фопен создаст или пересоздаст файл filename и откроет его в режиме записи
    if (f == NULL)
        return -1;

    fprintf(f, "%s", "init"); //TODO добавить дату
    fclose(f);
    printf("hello\n");
    return 0;
}