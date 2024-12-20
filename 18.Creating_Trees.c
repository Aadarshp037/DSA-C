// Simple tree creating using dynamic array

#include <stdio.h>
#include <stdlib.h>
          
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;      

Node* Nodes;
Node* createNode(int d){
    Node* N=(Node*)malloc(sizeof(Node));
    N->data=d;
    N->left=NULL;
    N->right=NULL;
    return N;
}

void Linkage(){
    for (int i=0;i<3;i++){
        Nodes[i].left=&Nodes[2*i + 1];
        Nodes[i].right=&Nodes[2*i + 2];
    }
}
void Preorder(Node* root){
    if (root!=NULL){
        printf("%d\t",root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}
void Postorder(Node* root){
    if (root!=NULL){
        Postorder(root->left);
        Postorder(root->right);
        printf("%d\t",root->data);
    }
}
void Inorder(Node* root){
    if (root!=NULL){
        Inorder(root->left);
        printf("%d\t",root->data);
        Inorder(root->right);
    }
}


int main(){

   
    Nodes= (Node*)malloc(7 * sizeof(Node));
      if (Nodes == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    Nodes[0] = *createNode(1);
    Nodes[1] = *createNode(2);
    Nodes[2] = *createNode(3);
    Nodes[3] = *createNode(4);
    Nodes[4] = *createNode(5);
    Nodes[5] = *createNode(6);
    Nodes[6] = *createNode(7);
    // Linking both arrays
    Linkage();
    Node* root=&Nodes[0];
    printf("Preorder Traversal: \n");
    Preorder(root);
    printf("\n");
    printf("Postorder Traversal: \n");
    Postorder(root);
    printf("\n");
    printf("Inorder Traversal: \n");
    Inorder(root);

    free(Nodes);
    return 0;
}
