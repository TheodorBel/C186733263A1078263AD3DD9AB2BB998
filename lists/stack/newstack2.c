#include "stack.h"

int main (){
    db_type *stack;
    stack = create_database();
    push(stack, create_node(1));
    push(stack, create_node(2));
    push(stack, create_node(3));
    push(stack, create_node(3));
    push(stack, create_node(3));
    push(stack, create_node(3));
    push(stack, create_node(3));
    push(stack, create_node(3));
    int test1;
    test1 = db_get_size(stack);
    printf("%d\n", test1);
    pop(stack);
    pop(stack);
    pop(stack);
    int test2;
    test2 = db_get_size(stack);
    printf("%d\n", test2);



}