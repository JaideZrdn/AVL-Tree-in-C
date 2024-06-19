//
//  AVL Funcs.c
//  AVL Tree
//
//  Created by Jaide Zardin on 18/06/24.
//

#include "AVL Funcs.h"

int max(int arg1, int arg2){
    return (arg1 > arg2 ? arg1 : arg2);
}

int height(Node* node){
    if (node == NULL){
        return -1;
    }
    return node->height;
}

int getBalance(Node* node){
    return height(node->left) - height(node->right);
}

Node* rotateLeft(Node* root){
    Node* newRoot = root->right;
    Node* aux = newRoot->left;
    
    if (aux){ //Se tiver filho, temos que atualizar quem é o pai dele
        aux->father = root;
    }
    newRoot->father = root->father; //Atualiza os pais dos nós que trocaram de pai
    root->father = newRoot;
    
    newRoot->left = root; //Atualiza o valor dos filhos de quem foi alterado
    root->right = aux;
    
    root->height = max(height(root->left), height(root->right)) + 1; //Atualiza as alturas de quem teve a altua alterada
    newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;
    
    return newRoot; //Retorna a nova raíz da árvore
}

Node* rotateRight(Node* root){
    Node* newRoot = root->left;
    Node* aux = newRoot->right;
    
    if (aux){ //Se tiver filho, temos que atualizar quem é o pai dele
        aux->father = root;
    }
    newRoot->father = root->father; //Atualiza os pais dos que trocaram de pai
    root->father = newRoot;
    
    newRoot->right = root; //Atualiza o valor dos filhos
    root->left = aux;
    
    root->height = max(height(root->left), height(root->right)) + 1; //Atualiza a altura de quem teve a altura alterada
    newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;
    
    return newRoot; //Retorna a nova raíz da árvore
}

Node* rotateRightLeft(Node* root){
    //Aplica uma rotação a direita no filho dele e depois uma rotação à esquerda nele
    root->right = rotateRight(root->right);
    return rotateLeft(root);
}

Node* rotateLeftRight(Node* root){
    //Aplica uma rotação à esquerda no filho dele e depois uma rotação a direita nele
    root->left = rotateLeft(root->left);
    return rotateRight(root);
}

Node* createNode(int key){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->height = 0; //Todo nó novo a ser inserido começa com altura 0, devido sempre ser uma folha
    newNode->left =  NULL;
    newNode->right =  NULL;
    newNode->father =  NULL;
    
    return newNode;
}

Node* balanceTree(Node* father){
    int balance = getBalance(father);
    
    if (balance > 1) { //ta desbalanceado pra esquerda
        if (getBalance(father->left) > 0) { //O filho ta maior pra esqeurda
            return rotateRight(father);
        } else { //O filho ta melhor pra direita
            return rotateLeftRight(father);
        }
    }
    
    if (balance < -1) { //ta desbalanceado pra direita
        if (getBalance(father->right) < 0) { //O filho ta maior pra direita
            return rotateLeft(father);
        } else { //O filho ta maior pra esquerda
            return rotateRightLeft(father);
        }
    }
    
    return father;
}

Node* insert(Node* father, int key){
    if (father == NULL){ //Não tem raiz, adiciona esse cara ae
        return createNode(key);
    }
    
    if (key < father->key){ //Atualiza o valor do pai em todos os nós passados durate a inserção
        father->left = insert(father->left, key);
        father->left->father = father;
    } else if (key > father->key){
        father->right = insert(father->right, key);
        father->right->father = father;
    } else { //Não recebe valores duplicados
        return NULL;
    }
    
    father->height = max(height(father->left), height(father->right)) + 1; // Atuliazando a altura do pai dele
    
    return balanceTree(father); //Balanceia a árvore recursivamente apenas passando por todos os nós passados durante a inserção
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}
