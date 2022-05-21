#include "queru.h"


int main() {
    db_type *queue = create_database();
    push(queue, 1);
    push(queue, 2);
    push(queue, 3);
    push(queue, 4);
    push(queue, 5);
    printf("%d\n",take_size_of_queue(queue));
    t_node *test_pop; 
    test_pop = pop(queue);
    printf("Your Valuse: %d\n", test_pop->num);
    test_pop = pop(queue);
    printf("Your Valuse: %d\n", test_pop->num);
    test_pop = pop(queue);
    printf("Your Valuse: %d\n", test_pop->num);
    test_pop = pop(queue);
    printf("Your Valuse: %d\n", test_pop->num);
    printf("%d\n",take_size_of_queue(queue));


    return 0;
}
