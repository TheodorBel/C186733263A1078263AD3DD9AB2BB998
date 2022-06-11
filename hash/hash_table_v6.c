#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_node{
    char *key;
    char *data;
    struct s_node* next;
}t_node;

typedef struct hash_table{
    int size;
    t_node **array;
}ht_type;

t_node *create_node(char *key, char *data){
    t_node *new;
    new = malloc(sizeof(t_node));
    new->data = strdup(data);
    new->key = strdup(key);
    new->next = NULL;
    return (new);
}


ht_type *create_table(int size){
    int index = 0;
    ht_type *table;
    table = malloc(sizeof(ht_type));
    if (table == NULL)
        return (NULL);
    table->size = size;
    table->array = malloc(sizeof(t_node*) * size);
    if (table->array == NULL)
        return (NULL);
    while (index < size){
        table->array[index] = NULL;
        index++;
    }
    return (table);
}

int hash_function(char *str, int size){
    int key = 0;
    int part;
    for (int i = 0; str[i] != '\0'; i++){
        part = (int)str[i] << 2;
        key = key + part;
    }
    key = key % size;
    return(key);
}

t_node *get_element_by_key(ht_type *table, char *key){
    t_node *tmp;
    int index = hash_function(key,table->size);
    tmp = table->array[index];

    if (tmp == NULL){ // esli net elementa po indexu
        printf("empty base\n");
        return (NULL);
    }

    while (tmp != NULL){ //esli est element
        if (strcmp(tmp->key, key) == 0){
           printf("%s\n",tmp->data);
           return (tmp);     
        }
        tmp = tmp->next;
    }                       
    printf("key not found\n");
    return(NULL); //esli net klucha
}

char *insert(ht_type *table, char *key, char *data){
    t_node *tmp;
    t_node *new;
    int index = hash_function(key,table->size);
    tmp = get_element_by_key(table, key);

    if (tmp != NULL){ //Перезапись по ключу
        free(tmp->data);
        tmp->data =  strdup(data);
        return (tmp->data);
    }

    new = create_node(key,data);
    if (table->array[index] == NULL){ //В базе данных нет нод
        table->array[index] = new;
        printf("%s\n", new->data);
        return(new->data);
    }

    tmp = table->array[index]; //В базе есть ноды и это коллизия
    table->array[index] = new;
    new->next = tmp;
    return (new->data);
}

int get_collision(ht_type *table){
    int count = 0;
    t_node *tmp;
    for (int i = 0; i < table->size; i++)
    {
        if (table->array[i] == NULL)
        {
            continue;
        }
        else if (table->array[i]->next == NULL)
        {
            continue;
        }
        tmp = table->array[i];
        while (tmp->next != NULL){
            count++;
            tmp = tmp->next;
        }
        i++;      
    }
    return(count);    
}

char *delete_by_key(ht_type *table, char *key){
    t_node *tmp;
    t_node *deleted;
    char *data;
    int index = hash_function(key, table->size);
    tmp = table->array[index];
    if (strcmp(table->array[index]->key,key) == 0){
       table->array[index] = tmp->next;
       data = tmp->data;
       free(tmp->key);
       free (tmp);
       return (data);
    }
    while (tmp->next != NULL)
    {
        if (strcmp(tmp->next->key, key) == 0)
        {
            deleted = tmp->next;
            tmp->next = tmp->next->next;
            data = deleted->data;
            free(deleted->key);
            free(deleted);
            return(data);
        }
        tmp = tmp->next;
    }
    return(NULL);
}

int main(){
    ht_type *hash_table;
    hash_table = create_table(10);
    insert(hash_table, "first", "1");
    insert(hash_table, "ifrst", "2");
    insert(hash_table, "ifrts", "3");
    get_element_by_key (hash_table, "first");
    get_element_by_key(hash_table, "ifrst");
    get_element_by_key(hash_table, "ifrts");
    int i = get_collision(hash_table);
    printf("%d\n", i);
}
