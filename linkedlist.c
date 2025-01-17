#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};
typedef struct node * nodePT;

nodePT new_node(int value_in);
nodePT array_2_list(int arr[], int n);

nodePT array_2_list(int arr[], int n) {
    int j;
    nodePT lastP = NULL;
    nodePT newP = NULL;
    nodePT L = new_node(arr[0]);

    L->data = arr[0];
    L->next = NULL;

    lastP = L;

    for (j = 1; j < n; j++) {
        newP = new_node(arr[j]);
        lastP->next = newP;
        lastP = newP;
    }

    return L;
}

nodePT new_node(int value_in) {
    nodePT result = malloc(sizeof(struct node));
    result->data = value_in;
    result->next = NULL;
    return result;
}


int main() {

    int arr[] = {15, 3, 86, 42, 1, 25, 12};
    nodePT L = NULL;
    L = array_2_list(arr, (sizeof(arr)/sizeof(arr[0])));
    
    printf("%d\n", L->next->next->next->data);


    free(L);
    return 0;
}