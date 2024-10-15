#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
    // constructor create 
    Node (int val ){
        data = val;
        left = NULL;
        right = NULL;

    }
};
Node *searchInBst(Node *root , int key){
    if (root == NULL){
        return NULL;
    }
    if (root->data == key){
        return root;
    }
    if (root->data > key){
       return searchInBst(root->left , key);
    }
    else {
       return searchInBst(root->right , key);
    }
}

int main(){
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);

    if (searchInBst(root , 5) == NULL){
        cout<<"Key does not exist.";
    }
    else {
        cout<<"Key exist.";
    }
    return 0;
}