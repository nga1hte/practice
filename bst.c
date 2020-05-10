#include <stdio.h>
#include <stdlib.h>

typedef struct bst{
    int data;
    struct bst *left;
    struct bst *right;
}bst;

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


int main(){
    bst *root = NULL;
    root = insertBstNode(root, 5);
    root = insertBstNode(root, 1);
    root = insertBstNode(root, 2);
    root = insertBstNode(root, 3);
    root = insertBstNode(root, 4);
    root = insertBstNode(root, 6);
    root = insertBstNode(root, 7);
    root = insertBstNode(root, 8);
    root = insertBstNode(root, 9);
    root = insertBstNode(root, 10);
    print_bst(root);
    printf("\n");
    if(search(root, 10)) printf("Found!\n");
    else printf("Not Found!\n");
    root = delete(root, 5);
    print_bst(root);

}
