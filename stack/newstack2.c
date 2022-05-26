#include "stack.h"

int main(){
    db_type *stack;
    stack = create_database();
    push(stack,create_node(11));
    push(stack,create_node(12));
    push(stack,create_node(13));
    push(stack,create_node(14));
    push(stack,create_node(15));
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
}