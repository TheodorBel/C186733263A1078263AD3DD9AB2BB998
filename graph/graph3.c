#include <stdio.h>
#include <stdlib.h>

typedef struct element    // Определение структуры ноды
{
    int key;
    struct element *left;
    struct element *right;
}t_node;

t_node *create_root(int key) // Создание корня дерева
{
    t_node *root = malloc(sizeof(t_node));
    root -> key = key;
    root -> left = NULL;
    root -> right = NULL;
    return root;
}

t_node *add(t_node *root, int key)
{
    t_node *new = malloc(sizeof(t_node)); //Новая нода на вставку
    new->key = key;
    t_node *tmp; //Нода чтобы найти куда вставлять
    tmp = root;
    while (tmp != NULL){   // Если тмп больше или равно, то вставка вправо, если меньше, то влево.
        if (tmp->key < key){ // Если ячейки уже заняты, то тмп ищет ближайшую не занятую. 
            if (tmp->left == NULL){
                tmp->left = new;
                break;
            }
            tmp = tmp->left;
        }
         if (tmp->key >= key){
            if (tmp->right == NULL){
                tmp->right = new;
                break;
            }
            tmp = tmp->right;
        }
    }
}

t_node *search(t_node *root, int key)
{
    t_node *tmp;
    tmp = root;
    if ((tmp == NULL) || (tmp -> key == key)) //Если в дереве ничего нет или ключ от корня
        return root;
    if (tmp->key < key){ // вот тут надо как-то обойти дерево
        
    }
}

void delete(t_node *root, int key){

}

void print_tree(t_node *root){

}

int main(){

return 0;
}
