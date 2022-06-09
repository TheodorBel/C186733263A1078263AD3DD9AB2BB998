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

char *insert(ht_type *table, char *key, char *data){
    t_node *tmp;
    t_node *new;
    int index = hash_function(key,table->size);
    tmp = get_element_by_key(table,key);

    if (tmp != NULL){ //Перезапись по ключу
        free(tmp->data);
        tmp->data =  strdup(data);
        return (tmp->data);
    }

    new = create_node(key,data);
    if (table->array[index] == NULL){ //В базе данных нет нод
        table->array[index] = new;
        return(new->data);
    }

    tmp = table->array[index]; //В базе есть ноды и это коллизия
    table->array[index] = new;
    new->next = tmp;
    return (new->data);
}

t_node *get_element_by_key(ht_type *table, char *key){
    t_node *tmp;
    int index = hash_function(key,table->size);
    tmp = table->array[index];

    if (tmp == NULL){ // esli net elementa po indexu
        printf("Base is empty\n");
        return (NULL);
    }

    while (tmp != NULL){ //esli est element
        if (strcmp(tmp->key, key) == 0){
           printf("%s\n",tmp->data);
           return (tmp);     
        }
        tmp = tmp->next;
    }

    printf("element not found\n"); //esli net klucha
    return(NULL);
}

int collision(ht_type *table){
    int sum = 0;
    int count = 0;
    t_node *tmp;
    for (int i = 0; i != table->size; i++){
        tmp = table->array[i];
        count = 0;
        while (tmp->next != NULL){
            if (tmp->next == NULL)
                break;
            count ++;
            

        }
        sum = sum + count;
    }

}

t_node *delete_by_key(ht_type *table, char *key){
    t_node *tmp;
    t_node *deleted;
    int index = hash_function(key, table->size);
    tmp = table->array[index];
    if (strcmp(table->array[index]->key,key) == 0){
       table->array[index] = tmp->next;
       return (tmp);
    }
    while (tmp->next != NULL){
        if (strcmp(tmp->next->key, key) == 0){
            deleted = tmp->next;
            tmp->next = tmp->next->next;
            return (deleted);
        }
    }

}

int main(){
    ht_type *hash_table;
    hash_table = create_table(10);
    insert(hash_table, "qqqqqqqq", "one");
    insert(hash_table, "asd", "two");
    insert(hash_table, "zzzzzzzzz", "free");
    insert(hash_table, "xxxxxxxx", "four");
    insert(hash_table, "ccacccccc", "five");
    insert(hash_table, "ccbcccccc", "five");
    insert(hash_table, "ccccccccc", "five");
    insert(hash_table, "ccccccccc", "five");
    get_element_by_key(hash_table, "zzzzzzzzz");
    get_element_by_key(hash_table, "xxxxxxxx");
    get_element_by_key(hash_table, "ccccccccc");
}
