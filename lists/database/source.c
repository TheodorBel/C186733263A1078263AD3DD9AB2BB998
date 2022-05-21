#include "db.h"


t_node* create_node(int value)
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

db_type* create_database() {
    db_type* new;
    new = malloc(sizeof(db_type));
    if (new == NULL)
        return NULL;
    new->size = 0;
    new->first_node = NULL;
    return(new);
};

t_node* db_find_by_index(db_type* db, int index) {
    t_node* finder = db->first_node;
    int current = 0;
    if ((db->size <= index) || (index < 0))
        return(NULL);
    while (current != index) {
        finder = finder->next;
        current = current + 1;
    }
    return (finder);
}

int db_read_by_index(db_type* db, int index) {
    t_node* finder;
    finder = db_find_by_index(db, index);
    if (finder == NULL)
        return(-1);
    return(finder->num);
}

t_node* db_pop_by_index(db_type* db, int index) {
    t_node* finder;
    t_node* prev;
    t_node* next;
    finder = db_find_by_index(db, index);
    if (finder == NULL)
        return NULL;
    db->size = db->size - 1;
    prev = finder->prev;
    next = finder->next;
    if (index == 0) {
        db->first_node = finder->next;
        db->first_node->prev = NULL;
        return finder;
    }
    if (index == db->size) {
        prev->next = NULL;
        return finder;
    }
    prev->next = next;
    next->prev = prev;
    return finder;
}

void db_delete_by_index(db_type* db, int index) {
    t_node* finder = db_pop_by_index(db,index);
    if (finder == NULL)
        return;
    free(finder);
}

t_node *db_append(db_type* db, t_node* new) {
    if (db->first_node == NULL) { //ѕолучаетс€ так, что это получаетс€ нода, если не было ни одной, то она запишетс€ как перва€.
        db->first_node = new;
        db->size = db->size + 1;
        return new;
    }
    t_node* last;
    last = db->first_node;
    while (last->next != NULL) {
        last = last->next; // —лева то куда, справа то что присваиваю.
    }
    last->next = new;
    new->prev = last;
    db->size = db->size + 1;
    return new;
}

t_node *db_prepend(db_type* db, t_node* new)
{
    t_node* tmp;
    if (db->size == 0)
    {
        db->first_node = new;
        db->size = db->size + 1;
        return new;
    }
    tmp = db->first_node;
    db->first_node = new;
    new->next = tmp;
    tmp->prev = new;
    db->size = db->size + 1;
    return new;
}

t_node *db_insert(db_type* db, t_node* new, int index)
{
    t_node* last;
    t_node* tmp = NULL;
    int i = 0;
    last = db->first_node;
    while (last != NULL) // ѕоиск по индексу
    {
        tmp = last->next;
        last = tmp;
        i++;
        if (index == i)
            break;
    }
    if (tmp == NULL)
        return NULL;
    new->next = tmp;
    new->prev = tmp->prev;
    tmp->prev = new;
    last = new->prev;
    last->next = new;
    db->size = db->size + 1;
    return new;
}


t_node *db_insert_by_index(db_type* db, int value, int index) {
    t_node* new = create_node(value);

    if (db->size < index || index < -1)
    {
        printf("index not found\n");
        return NULL;
    }

    if (db->size == index)   
        return db_append(db, new);

    if (db->size == 0 || index == -1)
        return db_prepend(db, new);

    return db_insert(db, new, index);
}

int db_getsize(db_type* db) {
    return(db->size);
}

t_node* db_get_element_by_value(db_type* db, int value) {
    t_node* finder = db->first_node;
    if (db->size == 0)
        return(NULL);
    while (finder != NULL) {
        if (finder->num == value)
            return(finder);
        finder = finder->next;
    }
    return (NULL);

}