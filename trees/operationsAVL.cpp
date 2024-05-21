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
    Node* leftRotation(Node* node) {
        Node* x = node;
        Node* y = node->right;
        Node* z = y->right;

        Node* alpha = y->left;

        y->left = x;
        x->right = alpha;

        return y;
    }
    Node* rightRotation(Node* node) {
        Node* x = node;
        Node* y = node->left;
        Node* z = y->left;

        Node* alpha = y->right;

        y->right = x;
        x->left = alpha;

        return y;
    }
    int heightOfNode(Node* node) {
        if(!node) {
            return -1;
        }

        return 1 + max(heightOfNode(node->left), heightOfNode(node->right));
    }
    int balanceFactor(Node* node) {
        if(!node) return 0;

        return heightOfNode(node->left)  - heightOfNode(node->right);
    }
    Node* addNodeWithRecursion(Node* node, int value) {
        if(!node ){
            return new Node(value);
        }
        else if(value < node->value) {
            node->left = addNodeWithRecursion(node->left, value);
        }
        else {
            node->right = addNodeWithRecursion(node->right, value);
        }

        int bf = balanceFactor(node);

        if(bf < -1) {
            if(value > node->right->value) {
                return leftRotation(node);
            }
            else {
                node->right = rightRotation(node->right);
                return leftRotation(node);
            }
        }
        else if(bf > 1) {
            if(value < node->left->value) {
                return rightRotation(node);
            }
            else {
                node->left = leftRotation(node->left);
                return rightRotation(node);
            }
        }

        return node; 
    }

    void preOrder(Node* node) {
        if(!node) return;

        cout<<node->value<<" ";
        preOrder(node->left);
        preOrder(node->right);
    }

};


int main() {
    BST t1;

    t1.root = t1.addNodeWithRecursion(t1.root, 12);
    t1.root = t1.addNodeWithRecursion(t1.root, 8);
    t1.root = t1.addNodeWithRecursion(t1.root, 18);
    t1.root = t1.addNodeWithRecursion(t1.root, 5);
    t1.root = t1.addNodeWithRecursion(t1.root, 11);
    t1.root = t1.addNodeWithRecursion(t1.root, 17);
    t1.root = t1.addNodeWithRecursion(t1.root, 4);

    t1.preOrder(t1.root);


    return 0;


}