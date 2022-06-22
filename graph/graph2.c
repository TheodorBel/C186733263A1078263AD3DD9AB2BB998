#include <stdio.h>
#include <stdlib.h>

typedef struct s_node{
    struct s_node *left; // Только меньшие элементы
    struct s_node *right; //Элементы которые больше или равны
    int data;
}t_node;

// Создание элемента с заданным значением
t_node *create_node(int data){
    t_node *new;
    new = malloc(sizeof(t_node));
    new->left = NULL;
    new->right = NULL;
    new->data = data;
    return(new);

}
//Добавление элемента в дерево
int add_node(t_node *root, t_node *new){
    if (root->data < new->data){//идем влево
        if (root->left == NULL){ // Если ничего нет, то сюда вставляем новый элемент
            root->left = new;
            return(new->data);   
        }
        add_node(root->left, new); // если что-то есть применяем рекурсию и встаем на нужное место

    }
    if (root->data >= new->data){//идем вправо
        if (root->right == NULL){ // Если ничего нет, то сюда вставляем новый элемент
            root->right = new;
            return(new->data);   
        }
        add_node(root->right, new); // если что-то есть применяем рекурсию и встаем на нужное место
    }

}
//Печать дерева от конкретного элемента вниз
void print_tree(t_node *current_element){
    if(current_element->left != NULL){
        printf("%d\n", current_element->data);
        print_tree(current_element->left);    
    }
    if(current_element->right != NULL){
        printf("%d\n",current_element->data);
        print_tree(current_element->right);    
    }
}

int main(){
    int a[7] = {1, 42, 2, 4, 7, 0, 3};
    t_node *root = create_node(5);
    for (int i = 0; i < 6; i++){
        t_node *new;
        new = create_node(a[i]);
        add_node(root, new);
    }
    print_tree(root);
}
