// Binary Search Tree for Character Tree

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node* left;
    struct node* right;
} Node;

Node* Search(Node* root, char key) {
    if (root != NULL) {
        if (root->data == key) {
            return root;
        } else if (root->data > key) {
            return Search(root->left, key);
        } else {
            return Search(root->right, key);
        }
    }
    return NULL;
}

Node* Insertion(Node* root, char key) {
    if (root == NULL) {
        Node* New = (Node*)malloc(sizeof(Node));
        if (New == NULL) {
            printf("Memory allocation failed\n");
            return NULL;
        }
        New->data = key;
        New->left = NULL;
        New->right = NULL;
        return New;
    }
    if (key < root->data) {
        root->left = Insertion(root->left, key);
    } else if (key > root->data) {
        root->right = Insertion(root->right, key);
    }
    return root;
}

void Preorder(Node* root) {
    if (root != NULL) {
        printf("%c\t", root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(Node* root) {
    if (root != NULL) {
        Postorder(root->left);
        Postorder(root->right);
        printf("%c\t", root->data);
    }
}

void Inorder(Node* root) {
    if (root != NULL) {
        Inorder(root->left);
        printf("%c\t", root->data);
        Inorder(root->right);
    }
}

Node* Maximum(Node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

Node* Minimum(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* Successor(Node* node) {
    if (node->right == NULL) {
        return NULL;
    }
    return Minimum(node->right);
}

Node* Predecessor(Node* node) {
    if (node->left == NULL) {
        return NULL;
    }
    return Maximum(node->left);
}

Node* Delete(Node* root, char key) {
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

int main() {
    Node* root = NULL;
    root = Insertion(root, 'e');
    root = Insertion(root, 'b');
    root = Insertion(root, 'f');
    root = Insertion(root, 'a');
    root = Insertion(root, 'c');
    root = Insertion(root, 'd');
    root = Insertion(root, 'g');

    printf("Preorder:\n");
    Preorder(root);
    printf("\nInorder:\n");
    Inorder(root);
    printf("\nPostorder:\n");
    Postorder(root);
    printf("\n");

   
    return 0;
}