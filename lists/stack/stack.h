#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

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

t_node *create_node(int value);
db_type* create_database();
t_node *push(db_type *db, t_node *new);
int db_get_size(db_type *db);
t_node *pop(db_type *db);






#endif