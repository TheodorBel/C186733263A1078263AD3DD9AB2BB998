#ifndef DB_H
#define DB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_node
{
    int num;
    struct s_node* prev;
    struct s_node* next;
}t_node;

typedef struct database {
    int size;
    t_node* first_node;
}db_type;

t_node* create_node(int value);
db_type* create_database();
t_node* db_find_by_index(db_type* db, int index);
int db_read_by_index(db_type* db, int index);
void db_delete_by_index(db_type* db, int index);
t_node *db_append(db_type* db, t_node* new);
t_node *db_prepend(db_type* db, t_node* new);
t_node *db_insert(db_type* db, t_node* new, int index);
t_node *db_insert_by_index(db_type* db, int value, int index);
int db_getsize(db_type* db);
t_node* db_get_element_by_value(db_type* db, int value);






#endif 