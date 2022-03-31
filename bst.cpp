// Shawn Aviles
// March 31, 2022
// Binary Search Tree

#include <iostream>
using namespace std;


class TreeNode {
public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode() {
        value = 0;
        left = right = NULL;
    }
};

// binary search tree structure
class BST {
public:
    TreeNode *root;

    BST() {
        root = NULL;
    }

    // 1. Add Values
    void addValue(int key) {
        
    }

    // 2. Search for a value (key)
    void searchBST(int key, TreeNode *start) {
        if (start == NULL) {
            cout << "Value not found in this tree" << endl;
        }
        else {
            if (key == root->value) {
                cout << "Yes! Found it!" << endl;
            }
            else if (key > root->value) {
                searchBST(key, start->right);
            }
            else {
                searchBST(key, start->left);
            }
        }
    }
    // 3. Delete a value (key)
    // 4. Display contents: (a) in--, (b) pre--, (c) post-- order
};

int main() {

}