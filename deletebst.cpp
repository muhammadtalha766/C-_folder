#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

node* insertioninBST(node* root, int value) {
    if (root == NULL) {
        return new node(value);
    }
    if (root->data > value) {
        root->left = insertioninBST(root->left, value);
    } else {
        root->right = insertioninBST(root->right, value);
    }
    return root;
}

node* searchBST(node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (root->data > value) {
        return searchBST(root->left, value);
    }
    return searchBST(root->right, value);
}

node* inorderSucc(node* root) {
    node* curr = root;
    while (curr && curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

node* deleteInBST(node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data) {
        root->left = deleteInBST(root->left, key);
    } else if (key > root->data) {
        root->right = deleteInBST(root->right, key);
    } else {
        if (root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }

        node* temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteInBST(root->right, temp->data);
    }
    return root;
}

void inorder(node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    node* root = new node(6);
    insertioninBST(root, 12);
    insertioninBST(root, 4);
    insertioninBST(root, 2);
    insertioninBST(root, 18);
    insertioninBST(root, 9);
    insertioninBST(root, 1);
    insertioninBST(root, 20);

    cout << "In-order traversal before deletion: ";
    inorder(root);
    cout << endl;

    if (searchBST(root, 5) == NULL) {
        cout << "\nElement not found";
    } else {
        cout << "\nElement found";
    }

    root = deleteInBST(root, 12);

    cout << "\nIn-order traversal after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
