#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct s_node
{
    int num;
    struct s_node *prev;
    struct s_node *next;
}t_node;

typedef struct database{
    int size;
    t_node *first_node;
}db_type;

t_node *create_node(int value)
{
    t_node *new;
    new = malloc(sizeof (t_node));
    new->num = value;
    new->next = NULL;
    new->prev = NULL;
    return (new);
}

db_type *create_database(){
    db_type *new;
    new = malloc(sizeof(db_type));
    new->size = 0;
    new->first_node = NULL;
    return(new);
};

t_node *db_find_by_index(db_type *db, int index){
    t_node *finder = db->first_node;
    int current = 0;
    if ((db->size <= index) || (index < 0))
        return(NULL);
    while (current != index){
        finder = finder->next;
        current = current + 1;
    }
    return (finder);
}

int db_read_by_index(db_type *db,int index){
    t_node *finder;
    finder = db_find_by_index(db,index);
    if(finder == NULL)
        return(-1);
    return(finder->num);
}

void db_delete_by_index(db_type *db, int index){
    t_node *finder;
    t_node *prev;
    t_node *next;
    finder = db_find_by_index(db,index);
    if (finder == NULL)
        return;
    db->size = db->size -1;
    prev = finder->prev;
    next = finder->next;
    if(index == 0){
        db->first_node = finder->next;
        free(finder);
        return;
    }
    if(index == db->size) {
        prev->next = NULL;
        free(finder);
        return;
    }
    prev->next = next;
    next->prev = prev;
    free(finder);
}

void db_insert_end(db_type *db, t_node *new){
    if (db->first_node == NULL) { //Получается так, что это получается нода, если не было ни одной, то она запишется как первая.
        db->first_node = new;
        db->size = db->size + 1;
        return;
    }
    t_node *last;
    last = db->first_node;
    while (last->next != NULL){
        last = last->next; // Слева то куда, справа то что присваиваю.
    }
    last->next = new;
    new->prev = last;
    db->size = db->size + 1;

}

void db_insert_front(db_type *db, t_node *new)
{
    t_node *tmp;
    if (db->size == 0)
    {
        db->first_node = new;
        db->size = db->size + 1;
        return;
    }
    tmp = db->first_node;
    db->first_node = new;
    new->next = tmp;
    tmp->prev = new;
    db->size = db->size + 1;
}

void db_insert_mid(db_type *db, t_node *new, int index)
{
    t_node *last;
    t_node *tmp;
    int i = 0;
    last = db->first_node;
    while (last != NULL) // Поиск по индексу
    {
        tmp = last->next;
        last = tmp;
        i++;
        if ( index == i)
            break;
    }
    new->next = tmp;
    new->prev = tmp->prev;
    tmp->prev = new;
    last = new->prev;
    last->next = new;
    db->size = db->size + 1;
}


void db_insert(db_type *db, int value, int index){
    t_node *new = create_node(value);
    if (db->size < index || index < -1)
    {
        printf("index not found\n");
        return;
    }
    if (db->size == index)
    {
        db_insert_end(db, new);
        return;
    }
    if (db->size == 0 || index == -1)
    {
        db_insert_front(db, new);
        return;
    }
    db_insert_mid(db, new, index);
}

int db_getsize(db_type *db){
    return(db->size);
}

t_node *db_get_element_by_value(db_type *db,int value){
    t_node *finder = db->first_node;
    if (db->size == 0)
        return(NULL);
    while (finder != NULL){
        if(finder->num == value)
            return(finder);
        finder = finder->next;
    }
    return (NULL);

}

int main() {
    int test_to_finder;
    db_type *db = create_database();
    db_insert(db,0,-1);
    db_insert(db,11,-1);
    db_insert(db,1,-1);
    db_insert(db,4,1);
    db_insert(db,1,-1);
    test_to_finder = db_read_by_index(db,3);
    printf("Readden element:%d\nSize of my base:%d\n", test_to_finder, db_getsize(db));
    db_delete_by_index(db,3);
    test_to_finder = db_read_by_index(db,3);
    printf("Readden element:%d\nSize of my base:%d\n", test_to_finder, db_getsize(db));



    return 0;
}
