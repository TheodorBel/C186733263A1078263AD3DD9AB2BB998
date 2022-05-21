#ifndef QUERU_H
#define QUERU_H
#include "..\database\db.h"

t_node* push(db_type* queue, int data);
t_node* pop(db_type* queue);
int take_size_of_queue(db_type* queue);




#endif