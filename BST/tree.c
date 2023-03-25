#include <stdio.h>
#include <malloc.h>
#include "tree.h"

void insert_node(struct tree_node **root, int new_element_value) {

    while(*root != NULL){
        if (new_element_value < (*root)->info){
            root = &(*root)->left_child;
        }else{
            root = &(*root)->right_child;
        }
    }
    *root = malloc (sizeof **root);
    (*root)->info = new_element_value;
    (*root)->left_child = NULL;
    (*root)->right_child = NULL;
}


void preorder(struct tree_node *root) {
    if(root == NULL)
    {
        printf("\nThe BST is empty");
        return;
    }

    printf("%d,", root->info);
    if (root->left_child) preorder(root->left_child);
    if (root->right_child) preorder(root->right_child);
}

///to be implemented
void postorder(struct tree_node *root) {
    if(root == NULL){
        printf("/nThe BST is empty");
        return;
    }

    if(root -> left_child)
        postorder(root -> left_child);
    if(root -> right_child)
        postorder(root ->right_child);

    printf("%d ",root->info);
}

///to be implemented
void inorder(struct tree_node *root) {
if(root == NULL){
        printf("/nThe BST is empty");
        return;
    }

    if(root -> left_child)
        inorder(root -> left_child);

    printf("%d ",root->info);

    if(root -> right_child)
        preorder(root ->right_child);


}

int search_node(struct tree_node *root, int searched_value){
    int found = 0;
    struct tree_node *current;

    current = root;
    while ( (current != NULL) && (found == 0) ){
        if (current->info == searched_value){
            found = 1;
        }else if ( searched_value > current->info){
            current = current->right_child;
        }else if ( searched_value < current->info  ){
            current = current->left_child;
        }
    }

    return found;
}

///to be implemented
int pop_node(struct tree_node *root, int searched_value){
    int found = 0;
    int aux;
    struct tree_node *current;
    struct tree_node *parrent;
    struct tree_node *iterator;

    ///to be implemented


    current = root;
    parrent = root;

    while ( (current != NULL) && (found == 0) ){

        if (current->info == searched_value){
            found = 1;
        }else if ( searched_value > current->info){
            parrent = current;
            current = current->right_child;
        }else if ( searched_value < current->info  ){
            parrent = current;
            current = current->left_child;
        }
    }

    if (found == 0){
        return -1;
    }


    if ( (current->left_child == NULL) && (current->right_child == NULL) ){

        if ( current->info < parrent->info ){
            parrent->left_child = NULL;
        }else{
            parrent->right_child = NULL;
        }
        aux = current->info;
        free(current);
        return aux;
    } else if ( current->left_child == NULL ){
        if (parrent->info < current->info ){
            parrent->right_child = current->right_child;
        }else{
            parrent->left_child = current->right_child;
        }
        aux = current->info;
        free(current);
        return aux;
    } else if ( current->right_child == NULL ) {

        if (parrent->info < current->info) {
            parrent->right_child = current->left_child;
        } else {
            parrent->left_child = current->left_child;
        }
        aux = current->info;
        free(current);
        return aux;
    } else {

        iterator = current->right_child;
        while (iterator->left_child != NULL){
            iterator = iterator->left_child;
        }
        aux = pop_node(root, iterator->info);
        current->info = aux;
        return searched_value;
    }

    return found;
}

