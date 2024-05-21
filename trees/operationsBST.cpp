#include <iostream>

using namespace std;

class Node {
    public:
    int value;
    Node* left;
    Node* right;

    Node(int data) {
        value = data;
        left = right = NULL;
    }
};

class BST {
    public:
    Node* root;

    BST() {
        root = NULL;
    }
    //insertion operations
    void addNodeWithIterative(int value) {
        Node* n1 = new Node(value);
        if(!root) {
            root = n1;
            return;
        }
        Node* temp = root;
        while(temp) {
            if(value<temp->value) { //left subtree
                if(temp->left==NULL) {
                    temp->left = n1;
                    return;
                }
                else {
                    temp = temp->left;
                }
            }
            else { //right subtree
                if(temp->right == NULL) {
                    temp->right = n1;
                    return;
                }
                else {
                    temp = temp->right;
                }
            }
        }
    }

    Node* addNodeRecursively(Node* node, int value) {
        if(!node) { // base condition
            if(!root) {
                root = new Node(value);
            }
            else {
                return new Node(value);
            }
        }
        else if(value < node->value) {
            node->left = addNodeRecursively(node->left,value);
        }
        else {
            node->right = addNodeRecursively(node->right, value);
        }
        return node;
    }
    //searching operations
    bool searchNodeIteratively(int value) {
        Node* temp = root;
        while(temp) {
            if(temp->value == value) {
                return true;
            }
            else if(value < temp->value) {
                temp = temp->left;
            }
            else {
                temp = temp->right;
            }
        }
        return false;
    }

    bool searchNodeRecursively(Node* node, int value) {
        if(!node) { //base condition
            return false;
        }
        else if(node->value == value) {
            return true;
        }
        else if(value < node->value) {
            return searchNodeRecursively(node->left, value);
        }
        else {
            return searchNodeRecursively(node->right, value);
        }
    }

    //deleting an element
    int minValueRight(Node* node) {
        if(node->left == NULL) {
            return node->value;
        }
        return minValueRight(node->left);
    }

    Node* deleteNode(Node* node, int target) {
        if(!node) return node;
        else if(target < node->value) {
            node->left = deleteNode(node->left,target);
        }
        else if(target > node->value) {
            node->right = deleteNode(node->right, target);
        }
        else {
            if(node->left == NULL) {
                return node->right;
            }
            else if(node->right == NULL) {
                return node->left;
            }
            else {
                int right_min = minValueRight(node->right);
                deleteNode(root, right_min);
                node->value = right_min;
            }
        }
        return node;

    }

    //traversal operations
    void preOrder(Node* node) {
        if(!node) {
            return;
        }
        cout<<node->value<<" ";
        preOrder(node->left);
        preOrder(node->right);
    }
    void postOrder(Node* node) {
        if(!node) {
            return;
        }
        postOrder(node->left);
        postOrder(node->right);
        cout<<node->value<<" ";
    }
    void inOrder(Node* node) {
        if(!node) {
            return;
        }
        inOrder(node->left);
        cout<<node->value<<" ";
        inOrder(node->right);
    }
};

int main() {
    BST bs1;
    bs1.addNodeRecursively(bs1.root, 45);
    bs1.addNodeRecursively(bs1.root, 15);
    bs1.addNodeRecursively(bs1.root, 79);
    bs1.addNodeRecursively(bs1.root, 10);
    bs1.addNodeRecursively(bs1.root, 20);
    bs1.addNodeRecursively(bs1.root, 55);
    bs1.addNodeRecursively(bs1.root, 90);
    bs1.addNodeRecursively(bs1.root, 12);
    bs1.addNodeRecursively(bs1.root, 50);
    bs1.deleteNode(bs1.root, 45);
    bs1.inOrder(bs1.root);
    /* cout<<endl;
    bool x = bs1.searchNodeRecursively(bs1.root,23);
    cout<<x; */

    return 0;
}