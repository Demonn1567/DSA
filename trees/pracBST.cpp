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
    //insertion
    void addNodeWithIterative(int value) {
        Node* n1 = new Node(value);
        if(!root) {
            root = n1;
            return;
        }

        Node* temp = root;
        while(temp) {
            if(value <temp->value) {
                if(temp->left==NULL) {
                    temp->left = n1;
                    return;
                }
                else {
                    temp = temp->left;
                }
            }
            else {
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
        if(!node) {
            if(!root) {
                root = new Node(value);
            }
            else {
                return new Node(value);
            }
        }
        else if(value < node->value) {
            node->left = addNodeRecursively(node->left, value);
        }
        else {
            node->right = addNodeRecursively(node->right, value);
        }

        return node;
    }

    //searching
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
        if(!node) {
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

    //deletion
    int rightMin(Node* node) {
        if(node->left == NULL) {
            return node->value;
        }
        return rightMin(node->left);
    }

    Node* deleteNode(Node* node, int target) {
        if(!node) {
            return node;
        }
        else if(target < node->value) {
            node->left = deleteNode(node->left, target);
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
                int rightmin = rightMin(node->right);
                deleteNode(root, rightmin);
                node->value = rightmin;
            }
        }
        return node;
    }


    //traversals
    void inOrder(Node* root) {
        if(!root) {
            return;
        }

        inOrder(root->left);
        cout<<root->value<<" ";
        inOrder(root->right);
    }


    void preOrder(Node* root) {
        if(!root) {
            return;
        }

        cout<<root->value<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void postOrder(Node* root) {
        if(!root) {
            return;
        }
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->value<<" ";
    }

};

int main() {
    BST bs1;
    bs1.addNodeRecursively(bs1.root, 62);
    bs1.addNodeRecursively(bs1.root, 29);
    bs1.addNodeRecursively(bs1.root, 22);
    bs1.addNodeRecursively(bs1.root, 58);
    bs1.addNodeRecursively(bs1.root, 37);
    bs1.addNodeRecursively(bs1.root, 35);
    bs1.addNodeRecursively(bs1.root, 47);
    bs1.addNodeRecursively(bs1.root, 42);
    bs1.addNodeRecursively(bs1.root, 52);
    bs1.addNodeRecursively(bs1.root, 75);
    bs1.addNodeRecursively(bs1.root, 92);
    bs1.addNodeRecursively(bs1.root, 82);
    bs1.addNodeRecursively(bs1.root, 97);

    bs1.deleteNode(bs1.root, 58);

    //bool x  = bs1.searchNodeRecursively(bs1.root,121);
    //cout<<x;

    bs1.preOrder(bs1.root);


    return 0;
}