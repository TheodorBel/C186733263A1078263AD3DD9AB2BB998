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
}

int db_get_size(db_type *db)
{
    return(db->size);
}

t_node *find_last_node(db_type *db)
{
    t_node *finder = db->first_node;
    if (finder == NULL )
        return NULL;
    int index = db_get_size(db);
    int current = 1;
    while (current != index) {
        if (index == 1)
            break;
        finder = finder->next;
        current = current + 1;
    }
    return finder;
}

t_node *push(db_type *db, t_node *new)
{
    t_node *tmp = find_last_node(db);
    if (tmp == NULL)
    {
        db->first_node = new;
        db->size = db->size + 1;
        return new;
    }
    tmp->next = new;
    new->prev = tmp;
    db->size = db->size + 1;
    return new;
}

t_node *pop(db_type *db)
{
    t_node *tmp = find_last_node(db);
    t_node *swapper;
    if (tmp == NULL)
        return NULL;
    if (tmp == db->first_node)
    {
        db->first_node == NULL;
        db->size = db->size - 1;
        return tmp;
    }
    swapper = tmp;
    free(tmp);
    db->size = db->size - 1;
    return swapper;
    
}