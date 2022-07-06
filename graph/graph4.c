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

typedef struct queue{ // Структура очереди для обхода в ширину
    t_node *first;
    t_node *last;
}t_queue;

void push(t_queue *queue, t_node *node){
    if (queue->first == NULL){
        queue->first = node;
        queue->last = node;
        return;
    }
    queue->last->next = node;
    queue->last = node;
    return;
}

int search_in_queue(t_queue *queue, int vertex){
    t_node *tmp = queue->first;
    while (tmp->next != NULL){
        if (tmp->vertex == vertex)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

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

int breadth_first_search(t_graph *graph, int vert_start, int vert_finish){ // Поиск в ширину принимает граф и ноды начало и конец
    if (vert_start == vert_finish){
        return(0);
    }
    int counter = 1;
    t_node *tmp;
    t_node *current = &(graph->array[vert_start]); // Нода текущая с которой начнется поиск в этой итерации
    
    t_queue *visited = malloc(sizeof(t_queue)); // Очередь для посещенных нод
    visited->first = NULL;
    visited->last = NULL;

    t_queue *to_visit = malloc(sizeof(t_queue)); // Очередь для нод, которые надо посетить
    to_visit->first = NULL;
    to_visit->last = NULL;

    to_visit->first = current->next;
    tmp = to_visit->first;
    while(tmp != NULL){
        while (tmp != NULL){ // Через цикл идет сравнение вершин, если они совпали, то они в одном шаге
            if (tmp->vertex == vert_finish){
                return(counter);
            }
            if (search_in_queue(visited, tmp->vertex) == 0){ // Функция сравнивает есть ли в визитед нода и пушит если  нет
                push(visited, create_node(tmp->vertex));
                //ТУДУ добавить в очередь to_visit_new для следующей итерации graph->array[tmp->vertex]
            }
            tmp = tmp->next;
        }
        counter++;
      //TMP = to_visit_new  
      // to_visit_new = NULL;
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
    breadth_first_search(graph, 0, 3);
    return 0;
}
