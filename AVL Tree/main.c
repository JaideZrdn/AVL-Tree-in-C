//
//  main.c
//  AVL Tree
//
//  Created by Jaide Zardin on 18/06/24.
//

#include "AVL Funcs.h"

int main(int argc, const char * argv[]) {
    Node* root = NULL;
    
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    root = insert(root, 23);
    
    printf("In order traversal of the constructed AVL tree is \n");
    inOrder(root);
    
    printf("%d\n", root->key);

    printf("%d\n", root->left->father->key);
    printf("%d\n", root->left->left->father->key);
    printf("%d\n", root->left->right->father->key);
    printf("%d\n", root->left->right->left->father->key);
    
    
    return 0;
}
