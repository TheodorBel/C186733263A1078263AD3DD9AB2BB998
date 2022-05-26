#include "stack.h"

t_node *create_node(int value)
{
    t_node* new;
    new = malloc(sizeof(t_node));
    if (new == NULL)
        return NULL;
    new->num = value;
    new->next = NULL;
    new->prev = NULL;
    return (new);
}

db_type* create_database() 
{
    db_type* new;
    new = malloc(sizeof(db_type));
    if (new == NULL)
        return NULL;
    new->size = 0;
    new->first_node = NULL;
    return(new);
};

t_node *push(db_type *db, t_node *new){
    t_node *last;
    t_node *pusher;
    pusher = create_node(1);
    if (db->first_node == NULL){
        db->first_node = pusher;
        db->size = db->size + 1;
        return pusher;
    }
    last = db->first_node;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = pusher;
    pusher->prev = last;
    db->size = db->size + 1;
    return new;
}

int db_get_size(db_type *db){
    return(db->size);
}

t_node *pop(db_type *db){
    t_node *finder = db->first_node;
    t_node *previous;
    int index = db_get_size(db);
    int current = 1;
    while (current != index) {
        finder = finder->next;
        current = current + 1;
    }
    previous =  finder->prev;
    previous->next = NULL;
    db->size = db->size - 1;
    return (finder);

}