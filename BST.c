#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode* TreeNodePT;

struct TreeNode {
    int key;
    TreeNodePT left;
    TreeNodePT right;
};

TreeNodePT newNode(int item) {
    TreeNodePT temp = malloc(sizeof(struct TreeNode));
    temp->key = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

TreeNodePT insert(TreeNodePT node, int key) {
    if (node == NULL) return newNode(key); //creates node when space is found
    if (node->key == key) return node; //returns node if one matching exists

    if (node->key < key) {//recurs down right if key is greater than node
        node->right = insert(node->right, key);
    }
    else {//recurs left if key is less than node
        node->left = insert(node->left, key);
    }
    return node;
}

void inorder(TreeNodePT root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

TreeNodePT search(TreeNodePT root, int data) {
    if (root == NULL) {
        printf("%d not found\n", data);
        return NULL;
    }
    else if (data == root->key) {
        printf("%d found\n", root->key);
        return root;
    }
    else if (data < root->key) return search(root->left, data);
    else return search(root->right, data);
}


int main() {
    
    int arr[] = {10, 8, 3, 9, 14, 21, 7, 2, 16, 25};
    int n = sizeof(arr)/sizeof(arr[0]);

    TreeNodePT root = newNode(arr[0]);

    for (int i = 1; i < n; i++) {
        root = insert(root, arr[i]);
    }

    inorder(root);
    printf("\n");

    search(root, 10);
    search(root, 12);
    search(root, 25);

    return 0;
}