//
// Created by Ionut on 4/7/2019.
//

#ifndef CODE_SKELETON_TREES_TREE_H
#define CODE_SKELETON_TREES_TREE_H

struct tree_node {
    struct tree_node *left_child;
    struct tree_node *right_child;
    int info;
};

void insert_node(struct tree_node **root, int new_element_value);
void preorder(struct tree_node *root);
void postorder(struct tree_node *root);
void inorder(struct tree_node *root);
int search_node(struct tree_node *root, int searched_value);
int pop_node(struct tree_node *root, int searched_value);

#endif //CODE_SKELETON_TREES_TREE_H
