#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {
    struct tree_node *root;
    root=NULL;
    int choice;
    int data;
    int aux;

    while( 1 > 0 )
    {
        printf("\nPress 1 for inserting a node in BST fashion: ");
        printf("\nPress 2 for traversing the tree in preorder fashion :");
        printf("\nPress 3 for traversing the tree in postorder fashion :");
        printf("\nPress 4 for traversing the tree in inorder fashion :");
        printf("\nPress 5 for searching:");
        printf("\nPress 6 for poping and element:");
        printf("\nPress 7 to exit :");


        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter the value to be inserted:");
                scanf("%d",&data);
                insert_node(&root, data);
                break;

            case 2: preorder(root);
                break;

            case 3: postorder(root);
                break;

            case 4: inorder(root);
                break;

            case 5:
                printf("\nEnter the value to be searched:");
                scanf("%d",&data);
                aux = search_node(root, data);
                (aux == 1) ? printf("Element found") : printf("Element not found");
                break;
            case 6:
                printf("\nEnter the value to be poped:");
                scanf("%d",&data);
                aux = pop_node(root, data);
                (aux != -2) ? printf("Element poped %d",aux) : printf("Element not found");
                break;
            case 7: exit(0);
                break;
            default: printf("\nYou have entered an invalid choice. Please try again");
        }
    }

    free(root);

    return 0;
}