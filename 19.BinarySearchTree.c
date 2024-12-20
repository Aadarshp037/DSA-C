// Binary Search Tree Implementation 

#include <stdio.h>
#include <stdlib.h>
          
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;          

Node* Search(Node* root,int key){
    if (root!=NULL){
        if (root->data==key){
            return root;
        }
        else if(root->data>key){
            return Search(root->left,key);
        }
        else if(root->data<key){
            return Search(root->right,key);
        }
    }
    else{

    return NULL;
    }

}
Node* Insertion(Node* root,int key){
    if (root==NULL){
        Node* New;
        New= (Node*)malloc(sizeof(Node));
        if (New==NULL){
            printf("Memory allocation failed");
            return NULL;
        }
        else{
            New->data=key;
            New->left=NULL;
            New->right=NULL;
        }
        return New;
    }
    else if(root->data>key){
        root->left=Insertion(root->left,key);
    }
    else if(root->data<key){
        root->right=Insertion(root->right,key);
    }
    return root;
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

Node* Maximum(Node* root){
    while (root->right!=NULL){
        root=root->right;
    }
    return root;
}
Node* Minimum(Node* root){
    while (root->left!=NULL){
        root=root->left;
    }
    return root;
}
Node* Succesor(Node* node){
    if (node->right=NULL){
        return NULL;
    }
    else{
        return Minimum(node->right);
    }
}
Node* Predeccesor(Node* node){
    if (node->left=NULL){
        return NULL;
    }
    else{
        return Maximum(node->left);
    }
}

Node* Delete(Node* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->data) {
        root->left = Delete(root->left, key);
    } else if (key > root->data) {
        root->right = Delete(root->right, key);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = Minimum(root->right);
        root->data = temp->data; 
        root->right = Delete(root->right, temp->data); 
    }
    return root;
}
int main(){
    Node* root=NULL;
    root=Insertion(root,20);
    root=Insertion(root,7);
    root=Insertion(root,3);
    root=Insertion(root,11);
    root=Insertion(root,25);
    root=Insertion(root,34);
    root=Insertion(root,40);

    root=Delete(root,34);
     Preorder(root);
    printf("\n");
    Inorder(root);
    printf("\n");
    Postorder(root);
    printf("\n");
    printf("The maximum value of tree is %d\n",Maximum(root)->data);
    printf("The minimum value of tree is %d\n",Minimum(root)->data);
     
    return 0;
}

   