#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int vertex;
    struct node *next;
}t_node;

typedef struct graph{
    int size;
    t_node *array; // Указатель на массив с вершинами
}t_graph;

t_node *create_node(int vertex){
    t_node *new = malloc(sizeof(t_node));
    new->vertex = vertex;
    new->next = NULL;
    return (new);
}

t_graph *create_graph(int size){
    if (size < 1){
        printf("Wrong size of graph");
        return (NULL);
    }
    t_graph *new = malloc(sizeof(t_graph)); 
    new->size = size;
    new->array = malloc(sizeof(t_node) * size);// Создаю массив вершин и делаю его пустым
    for (int i = 0; i != size; i++){
        new->array[i].next = NULL; // Нода из массива, у которой я занулил указатель на следующую
        new->array[i].vertex = i; // Нумерация вершин графа
    }
    return (new);
}

t_graph *add_edge(t_graph *graph, int begin, int end){ // Принимает граф, начало и конец ребра
    t_node *tmp = &(graph->array[begin]); // Нода по индексу - начало ребра. Слева объявил, справа присвоил.
    while (tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = create_node(end); // Создаю ноду в конец иначе списки поплывут

    tmp = &(graph->array[end]);
    while (tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = create_node(begin); // Создается нода чтобы списки были с обеих сторон

    return (graph); 
}

void print_graph(t_graph *graph){
    t_node *vertex;
    for (int i = 0; i < graph->size; i++){
        vertex = &(graph->array[i]);
        printf("vertex number [%d]->", vertex->vertex);
        vertex = vertex->next;
        while (vertex != NULL){
            printf("[%d]->", vertex->vertex);
            vertex = vertex->next;
        }
        printf("NULL\n");
    }

}





int main(){
    t_graph *graph = create_graph(5);
    add_edge(graph,0,4);
    add_edge(graph,1,2);
    add_edge(graph,1,3);
    add_edge(graph,1,4);
    add_edge(graph,2,3);
    print_graph(graph);
    return 0;
}
