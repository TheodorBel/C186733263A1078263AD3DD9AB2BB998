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
    t_node *array;
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
    int count = 0;
    ht_type *table;
    table = malloc(sizeof(ht_type));
    if (table == NULL)
        return (NULL);
    table->size = size;
    table->array = malloc(sizeof(t_node)*size);
    if (table->array == NULL)
        return (NULL);
    while (count < size){
        table->array[count].key = NULL;
        table->array[count].data = NULL;
        table->array[count].next = NULL;
        count++;
    }
    return (table);
}

int hash_function(char *str, int size){
    int key = 0;
    int part;
    for (int i = 0; str[i]; i++){
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
    
    if ( table->array[index].key == NULL){  // Если всё хорошо
        table->array[index].data =  strdup(data);
        table->array[index].key = strdup(key);
        printf("%s\n", table->array[index].data);
        return(table->array[index].data);
    }
    
    tmp = &(table->array[index]);
    while (tmp->next != NULL){ // Если перезапись
        if (strcmp(tmp->key, key) == 0){
           free(tmp->data);
           tmp->data =  strdup(data);
           return (tmp->data);     
        }
        tmp = tmp->next;
    }
    
    new = create_node(key, data);   //Если коллизия
    tmp->next = new;
    return (new->data);
}

t_node *get_element_by_key(ht_type *table, char *key){
    t_node *tmp;
    int index = hash_function(key,table->size);
    tmp = &(table->array[index]);
    if (tmp->next == NULL){
        if (strcmp(tmp->key, key) == 0){
        printf("%s\n",tmp->data);
        return (tmp);
        }
    }
    while (tmp->next != NULL){
        if (strcmp(tmp->key, key) == 0){
           printf("%s\n",tmp->data);
           return (tmp);     
        }
        tmp = tmp->next;
    }
    printf("%s\n", "element not found");
    return(NULL);
}


int main(){
    ht_type *hash_table;
    hash_table = create_table(100);
    insert(hash_table, "qqqqqqqq", "one");
    insert(hash_table, "asd", "two");
    insert(hash_table, "zzzzzzzzz", "free");
    insert(hash_table, "xxxxxxxx", "four");
    insert(hash_table, "ccccccccc", "five");
    get_element_by_key(hash_table, "zzzzzzzzz");
    get_element_by_key(hash_table, "xxxxxxxx");
    get_element_by_key(hash_table, "ccccccccc");
}
