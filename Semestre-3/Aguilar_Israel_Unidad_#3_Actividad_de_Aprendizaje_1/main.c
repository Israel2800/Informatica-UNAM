// Desarrolla en Lenguaje C el programa de un árbol que almacene la siguiente 
// expresión matemática 1 * ((3 ^ 4) + 2). Recuerda utilizar por los menos las 
// operaciones de insert(), delete(), isEmpty() y printInOrder(). 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(char data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, char data) {
    if (root == NULL) {
        return createNode(data);
    }

    root->right = insert(root->right, data);

    return root;
}

bool isEmpty(struct TreeNode* root) {
    return (root == NULL);
}

void printInOrder(struct TreeNode* root) {
    if (root != NULL) {
        if (root->data == '(') {
            printf("(");
            printInOrder(root->right);
        } else {
            printInOrder(root->left);
            printf("%c", root->data);
            printInOrder(root->right);
        }
    }
}

void deleteTree(struct TreeNode* root) {
    if (root != NULL) {
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
    }
}

int main() {
    struct TreeNode* root = NULL;
    char expression[] = "1 * ((3 ^ 4) + 2)";

    for (int i = 0; expression[i] != '\0'; i++) {
        root = insert(root, expression[i]);
    }

    printf("Expresion en orden: ");
    printInOrder(root);
    printf("\n");

    deleteTree(root);

    return 0;
}
