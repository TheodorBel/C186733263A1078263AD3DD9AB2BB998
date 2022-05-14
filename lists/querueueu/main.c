#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct q_node{
    int q_num;
    struct q_node *next;
}t_node;

typedef struct q_queue{
    int size;
    t_node *first_q_node;
    t_node *last_q_node;
}q_type;

t_node *create_node(int value){
    t_node *new;
    new = malloc(sizeof (t_node));
    new->q_num = value;
    new->next = NULL;
    return(new);
}

q_type *create_queue(){
    q_type *new;
    new = malloc(sizeof (q_type));
    new->size = 0;
    new->first_q_node = NULL;
    new->last_q_node = NULL;
    return(new);
}


void push(q_type *queue, t_node *new){
    queue->size = queue->size + 1;
    if (queue->first_q_node == NULL){
        queue->first_q_node = new;
        queue->last_q_node = queue->first_q_node;
        return;
    }
    queue->last_q_node->next = new;
    queue->last_q_node = new;

}

t_node *pop(q_type *queue){
    t_node *readden;
    readden = queue->first_q_node;
    queue->first_q_node = readden->next;
    queue->size = queue->size - 1;
    return (readden);
}

int take_size_of_queue(q_type *queue){
    return (queue->size);
}

int main() {
    q_type *queue = create_queue();
    push(queue, create_node(1));
    push(queue, create_node(2));
    push(queue, create_node(3));
    push(queue, create_node(4));
    push(queue, create_node(5));
    printf("%d\n",take_size_of_queue(queue));
    t_node *test_pop;
    test_pop = pop(queue);
    printf("%d\n",test_pop->q_num);
    printf("%d\n",take_size_of_queue(queue));


    return 0;
}