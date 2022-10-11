#include "gitver.h"
#define ADD "add:"
#define ADDED_FILE "added_file:"
#define ADDED_FILE_END "END_OF_FILE"
#define DIR_ROOT "./"

int git_init() //Дроп в файл и так далее
{ 
    FILE *f = fopen(FILENAME, "w"); //функция фопен создаст или пересоздаст файл filename и откроет его в режиме записи
    if (f == NULL)
        return -1;

    fprintf(f, "%s", "init\n"); //TODO добавить дату
    fclose(f);
    // printf("hello\n");
    return 0;
}

FILE* fl_open(char* command) //TODO Проверить нужная ли команда a w r 
{
    FILE *f = fopen(FILENAME, command); //функция фопен создаст или пересоздаст файл filename и откроет его в режиме записи
    if (f == NULL)
        return -1;
    // printf("hello\n");
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
    fputs("\nend_of_added_file\n", fl);
    fclose(added_file);
    fclose(fl);
    free(text); 
    return 0;
}

char* check_files(){ //Найти все названия файлов с тегом added в файле fl --- Найти все названия файлов в текущей директории, кроме файла fl --- 
    DIR *dir;
    struct dirent *entry;
    char* all_names[10];
    int count = 0;

    dir = opendir(DIR_ROOT);
    if (!dir) {
        printf("error");
        exit(-1);
    };

    while ( (entry = readdir(dir)) != NULL) {

        if ((strncmp(entry->d_name, ".", 1) == 0) || (strncmp(entry->d_name, "..", 2) == 0) || (strncmp(entry->d_name, ".fl.txt", 7) == 0)){
            continue;
        };

        all_names[count] = calloc(sizeof(entry->d_name), (sizeof(char)));


        strcpy(all_names[count], entry->d_name);
        count++;
    };

    closedir(dir); 
    //показать файлы которые есть в фл


    FILE* root = fl_open("r");
    if (root == NULL)
    {
        printf("Can't open file");
        return -1;
    }
    
    char * text = calloc(2048, sizeof(char));// 2048 это максимальная длина строки в байтах
    if (!text)
    {
        printf("not enough memory.\n");
        return 1;
    }
    //printf("%s", all_names[0]);
    

    while (fgets(text, 2048, root) != NULL)
    {   
        if (strncmp(text, ADD, (sizeof(ADD)/sizeof(char))-1) == 0)
        {
            for (int i = 0; i < 6; i++)
            {
                if (strncmp(text + 5, all_names[i], 4) == 0) //TODO Сделать так чтобы пробелы в конце не руинили сравнение
                {
                    printf("%sis suspected: \n", text + 5);
                }
            }
        }
        
            
    }                   
    fclose(root);
    free(text); 
    return 0;

    //Показать файлы, которые есть в директории, но которых нет фл

    //Показать файлы, которые есть в фл, но которых нет в директории
    

}

char* check_change(FILE* current){


}