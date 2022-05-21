#include "queru.h"

t_node *push(db_type* queue, int data){
    t_node* new = create_node(data);
    if (new == NULL)
        return NULL;
    return db_append(queue, new);
    
}

t_node *pop(db_type* queue){
    t_node *testpop = db_pop_by_index(queue, 0);
    return testpop;
}

int take_size_of_queue(db_type* queue){
    return db_getsize(queue);
      
}