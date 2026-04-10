#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

/*
 * Creating a tree
 *
 */
struct BstNode{
    int data;
    struct BstNode* left;
    struct BstNode* right;
};


/*
 * Dynamically allocates memory for a new node in the heap
 * takes the data to be inserted as argument, creates a node in the heap using malloc, and return the address of the new node
 */
struct BstNode* GetNewNode(int data) {
    struct BstNode* newNode = malloc(sizeof(struct BstNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

/*
 * Inserts a node into the tree
 * takes the address of the root node, and the data to insert as arguments
 * If the tree is empty, create a new node and set it as the root
 * If the data to insert is <= root, make a recursive call to insert data in the left subtree
 * If the data is > root, then insert it in the right subtree
 */
struct BstNode* Insert(struct BstNode* root, int data) {
    if (root == NULL) { // check if the tree is empty
        root = GetNewNode(data);
        return root;
    }
    else if (data <= root->data) {
        root->left = Insert(root->left, data);
    }
    else {
        root->right = Insert(root->right, data);
    }
    return root;
}

/*
 * Function to search for an element
 * Takes the address of the root and the data to be searched as arguments
 * returns true if the data is in the tree, false otherwise
 */
bool Search(struct BstNode* root, int data) {
    if (root == NULL) return false;
    if (root->data == data) return true; // elem found in the root

    // making recursive calls to search the element in the left subtree
    else if (data <= root->data) return Search(root->left, data);

    // making recursive calls to search the element in the right subtree
    else return Search(root->right, data);
}

int main(void) {
    // To create a tree we need to declare a pointer to BstNode, that will store the address of the root node
    // when first creating the tree, the root is empty
    struct BstNode* root = NULL;

    root = Insert(root, 10);
    root = Insert(root, 15);
    root = Insert(root, 9);
    root = Insert(root, 20);
    root = Insert(root, 19);
    root = Insert(root, 7);

    int num;
    printf("Enter a number to search: ");
    scanf("%d", &num);

    if (Search(root, num) == true) printf("Elem found!");
    else printf("Elem not found!");

    return 0;
}
