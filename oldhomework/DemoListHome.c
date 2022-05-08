#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_node
{
    int num;
    struct s_node *prev;
    struct s_node *next;
    int index;
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

void db_insert(db_type *db, int aleksey){
    t_node *newnode;
    newnode = create_node(aleksey);
    if (db->first_node == NULL) { //Получается так, что это получается нода, если не было ни одной, то она запишется как первая.
        db->first_node = newnode;
        db->size = db->size + 1;
        return;
    }
    t_node *last;
    last = db->first_node;
    while (last->next != NULL){
        last = last->next; // Слева то куда, справа то что присваиваю.
    }
    last->next = newnode;
    newnode->prev = last;

}


int main() {
    db_type *db = create_database();
    db_insert(db, rand() % 8);
    db_insert(db, rand() % 8 );
//    t_node *head;
//    head = malloc(sizeof (t_node));
//    head->num = rand() % 5;
//    head->next = NULL;
//    head->index = 0;
//    head ->prev = NULL;
//    t_node *tmp;
//    head->next = tmp;
//    t_node *last;
//    last = head;

//    for (int i = 0; i < 10; i++)
//    {
//        tmp = create_node();
//        tmp->index = last->index +1;
//        tmp->prev = last;
//        last->next = tmp;
//        last = tmp;
//    }
//
    return 0;
}
