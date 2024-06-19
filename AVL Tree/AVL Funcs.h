//
//  AVL Funcs.h
//  AVL Tree
//
//  Created by Jaide Zardin on 18/06/24.
//

#ifndef AVL_Funcs_h
#define AVL_Funcs_h

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int key;
    struct Node* left;
    struct Node* right;
    struct Node* father;
    int height;
} Node;

int max(int arg1, int arg2);
int height(Node* node);
int getBalance(Node* node);
Node* rotateLeft(Node* root);
Node* rotateRight(Node* root);
Node* rotateRightLeft(Node* root);
Node* rotateLeftRight(Node* root);
Node* createNode(int key);
Node* insert(Node* father, int key);
Node* balanceTree(Node* father);
void inOrder(Node* root);

#endif /* AVL_Funcs_h */
