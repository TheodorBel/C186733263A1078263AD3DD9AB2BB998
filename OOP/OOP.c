#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <json-c/json.h>
#include <yaml.h>
#define SAVE_SUCCESS 0
#define SAVE_FAILURE 1


typedef struct account_user{
    char *name;
    char *second_name;
    char *age;
    char *adress;
}acc_type;

acc_type *create_account(char *name, char *second_name, char *age, char *adress){
    acc_type *new = malloc(sizeof(acc_type));
    new->name = name;
    new->second_name = second_name;
    new->age = age;
    new->adress = adress;
    return(new);
}
typedef struct account Account;

struct account{ 
    char *encoded_data;
    char *filename;
    void (*dump)(Account*); // Сохранить в папку с выбранным типом файлов
    int (*encode)(Account*, acc_type*);  //Собрать все данные аккаунта в необходимый вид
};

int encode_to_json(Account *account, acc_type *user) // Функция, которая будет пределывать данные из структуры аккаунт в json
{ 
    char *json_data = malloc(sizeof(char)*200);
    bzero(json_data, 200);

    strcat(json_data, "{\"User\": {\n\t\"First Name\": "); //Слепляем всё в одну строчку
    strcat(json_data, user->name);
    strcat(json_data, ",\n\t\"Second name\": ");
    strcat(json_data, user->second_name);
    strcat(json_data, ",\n\t\"Age\": ");
    strcat(json_data, user->age);
    strcat(json_data, ",\n\t\"City\": ");
    strcat(json_data, user->adress);
    strcat(json_data, "\n\t}\n}\n");

    account->encoded_data = json_data;

    return (SAVE_SUCCESS); 
} 

char *encode_to_yaml(Account *account, acc_type *user) //Переделка в ямл
{ 
    char *yml_data = malloc(sizeof(char)*200);
    bzero(yml_data, 200);

    strcat(yml_data, "user:\n\tfirst_name: ");
    strcat(yml_data, user->name);
    strcat(yml_data, "\n\tsecond_name: ");
    strcat(yml_data, user->second_name);
    strcat(yml_data, "\n\tage: ");
    strcat(yml_data, user->age);
    strcat(yml_data, "\n\tcity: ");
    strcat(yml_data, user->adress);
    strcat(yml_data, "\n");

    account->encoded_data = yml_data;
    return (EXIT_SUCCESS);
} 
 
int dump_to_file(Account *account) //Дроп в файл и так далее
{ 
    FILE *f = fopen(account->filename, "w"); //File специальный тип данных в Ф лежит адрес файла
    if (f == NULL)
        return (SAVE_FAILURE);

    fprintf(f, "%s", account->encoded_data);
    fclose(f);
    return (SAVE_SUCCESS);
} 

Account* interact_json() 
{ 
    Account* a = malloc(sizeof(Account)); 
    a->encoded_data = NULL;
    a->filename = "test.json";
    a->dump = &dump_to_file; 
    a->encode = &encode_to_json; 
    return a; 
}

Account* interact_yaml() 
{ 
    Account* b = malloc(sizeof(Account)); 
    b->encoded_data = NULL;
    b->filename = "test.yaml";
    b->dump = &dump_to_file; 
    b->encode = &encode_to_yaml; 
    return b; 
}

void polymorph(Account* a, acc_type *user) 
{ 
    a->encode(a, user);
    a->dump(a); 
}


int main(){
acc_type *first = create_account("sasha", "grey", "34", "North Highlands, California");
polymorph(interact_json(), first);
polymorph(interact_yaml(), first);
}
