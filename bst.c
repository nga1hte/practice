#include <stdio.h>
#include <stdlib.h>

typedef struct bst{
    int data;
    struct bst *left;
    struct bst *right;
}bst;

typedef struct queue{
    bst *data;
    struct queue *next;
}queue;

queue *head = NULL;
queue *tail = NULL;

bst *getBstNode(int data){
    bst *newNode = (bst *) malloc(sizeof(bst));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bst *insertBstNode(bst *root, int data){
    if(root == NULL){
        root = getBstNode(data);
    }
    else if(data <= root->data){
        root->left = insertBstNode(root->left, data);
    }
    else{
        root->right = insertBstNode(root->right, data);
    }
    return root;
}

//non recursive implementation
bst *insertBst(bst *node, int data){
    bst *prev;
    bst *head = node;
    if(node == NULL){
        node = getBstNode(data);
        return node;
    }
    bst *tmp = getBstNode(data);
    while(node != NULL){
        if(data <= node->data){
            prev = node;
            node = node->left;
        }else if(data > node->data){
            prev = node;
            node = node->right ;
        }
    }
    if(data <= prev->data)
        prev->left = tmp;
    else
        prev->right = tmp;
    return head;
}

int search(bst *root, int data){
    if(root == NULL) return 0;
    else if(root->data == data) return 1;
    else if(root->data < data) search(root->right, data);
    else search(root->left, data);
}

//change location of printf(data) to implement pre-order in-order and post-order
void print_bst(bst *root){
    if(root == NULL)
        return;
    print_bst(root->left);
    printf("%d ", root->data);
    print_bst(root->right);
}

bst *findMin(bst *root){
    while(root->left != NULL) root = root->left;
    return root;
}

int findHeight(bst *root){
    if(root == NULL) return -1;
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return (rightHeight > leftHeight ? rightHeight : leftHeight) + 1;
}

//deletion of a node in binary search tree
bst *delete(bst *root, int data){
     if(root == NULL) return root;
     else if(data < root->data) root->left = delete(root->left, data);
     else if(data > root->data) root->right = delete(root->right, data);
     else{
         if(root->left == NULL && root->right == NULL){
             free(root);
             root = NULL;
         }else if(root->left == NULL){
             bst *tmp = root;
             root = root->right;
             free(tmp);
         }else if(root->right == NULL){
             bst *tmp = root;
             root = root->left;
             free(tmp);
         }else{
             bst *tmp = findMin(root->right);
             root->data = tmp->data;
             root->right = delete(root->right, tmp->data);
         }
     }
     return root;
}

void enqueue(bst *data){
    queue *newNode = (queue *) malloc(sizeof(queue));
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL && tail == NULL){
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

bst *dequeue(){
    queue *temp = head;
    bst *data = head->data;
    if(head == NULL){
        return data;
    }
    if(head == tail) head = tail = NULL;
    else head = head->next;
    free(temp);
    return data;
}

int isEmpty(){ 
    return (head == NULL);
}

bst *top(){
    if(!isEmpty()) return head->data;
}


void levelOrder(bst *root){
    if(root == NULL) return;
    enqueue(root);
    while(!isEmpty()){
        bst *current = top();
        printf("%d ", current->data);
        if(current->left != NULL) enqueue(current->left);
        if(current->right != NULL) enqueue(current->right);
        dequeue();
    }
}


int main(){
    bst *root = NULL;

    root = insertBstNode(root, 5);
    root = insertBstNode(root, 3);
    root = insertBstNode(root, 4);
    root = insertBstNode(root, 1);
    root = insertBstNode(root, 2);
    root = insertBstNode(root, 8);
    root = insertBstNode(root, 7);
    root = insertBstNode(root, 9);
    root = insertBstNode(root, 10);
    root = insertBstNode(root, 6);
    print_bst(root);
    printf("\n");
    if(search(root, 10)) printf("Found!\n");
    else printf("Not Found!\n");
    print_bst(root);
    printf("\n");
    printf("Height: %d\n", findHeight(root));
    levelOrder(root);
    printf("\n");
}
