// Shawn Aviles
// April 12, 2022
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
        // check to see if tree is empty
        // if empty, make the value to root
        if (root == NULL){
            root = new TreeNode();
            root->value = key;
            return;
        }

        // if not empty, find the correct spot to add the value
        // tree is not empty, so we 'search' tree for value
        // if we fall of tree, we found the right spot
        TreeNode *fast, *slow;
        fast = slow = root;

        while (fast != NULL) {
            slow = fast;

            if (key == fast->value) {
                // duplicate 
                cout << "Value already exists in tree" << endl;
                return;
            }
            else if (key < fast->value) {
                // go left
                fast = fast->left;
            }
            else {
                fast = fast->right;
            }
        }

        // check to see if fast is NULL
        // if it is, we found the right spot
        // slow will have the address of the new 'parent' to be
        if (fast == NULL) {
            TreeNode *temp = new TreeNode();
            temp->value = key;

            if (key < slow->value) {
                slow->left = temp;
            }
            else {
                slow->right = temp;
            }
        }
    }

    // 2. Search for a value (key)
    void searchBST(int key, TreeNode *start) {
        if (start == NULL) {
            cout << "Value not found in this tree" << endl;
        }
        else {
            if (key == start->value) {
                cout << "Yes! Found it!" << endl;
            }
            else if (key > start->value) {
                searchBST(key, start->right);
            }
            else {
                searchBST(key, start->left);
            }
        }
    }
    
    // 3. Delete a value (key)
    void deleteNode(int key, TreeNode *start) {
        if (start == NULL) {
            cout << "Value not found in this tree" << endl;
            return;
        }

        // step 1: search for the value!
        TreeNode *slow, *fast;
        slow = fast = start;

        while (fast != NULL && key != fast->value) {
            slow = fast;

            if (key < fast->value) {
                fast = fast->left;
            }
            else {
                fast = fast->right;
            }
        }

        if (fast == NULL) {
            cout << "This value does not exist in the tree. Not deleting" << endl;
            return;
        }

        if (key == fast->value) {
            // we found it! Yay
            // so lets figure our what case are we dealing with

            // case 1: leaf node, no children
            if (fast->left == NULL && fast->right == NULL) {
                // // delete the node
                cout << "Deleting leaf node - Case I" << endl;
                // if (key < slow->value) {
                //     slow->left = NULL;
                // }
                // else {
                //     slow->right = NULL;
                // }
            }

            // case 2: node with one child
            else if (fast->left == NULL && fast->right != NULL){
                // // delete the node
                cout << "Deleting node with one child - Case II" << endl;
                // if (key < slow->value) {
                //     slow->left = fast->right;
                // }
                // else {
                //     slow->right = fast->right;
                // }
            }
            else if (fast->left != NULL && fast->right == NULL) {
                // // delete the node
                cout << "Deleting node with one child - Case II" << endl;
                // if (key < slow->value) {
                //     slow->left = fast->left;
                // }
                // else {
                //     slow->right = fast->left;
                // }
            }

            // case 3: node with two children
            else {
                // // find the smallest value in the right subtree
                // // and replace the value of the node to be deleted
                cout << "Deleting node with two children - Case III" << endl;
                // TreeNode *temp = fast->right;
                // TreeNode *temp2 = fast;

                // while (temp->left != NULL) {
                //     temp2 = temp;
                //     temp = temp->left;
            }
            // fast->value = temp->value;
            // temp2->left = temp->right; 
        }


        /*
        // possible recursion refactoring 
        if (key == start->value) {
            // found the node to delete
            // check to see if node has children
            if (start->left == NULL && start->right == NULL) {
                // no children
                // delete node
                delete start;
                start = NULL;
            }
            else if (start->left == NULL) {
                // only right child
                // delete node
                TreeNode *temp = start;
                start = start->right;
                delete temp;
            }
            else if (start->right == NULL) {
                // only left child
                // delete node
                TreeNode *temp = start;
                start = start->left;
                delete temp;
            }
            else {
                // two children
                // find the inorder successor
                TreeNode *temp = start->right;
                while (temp->left != NULL) {
                    temp = temp->left;
                }

                // copy the inorder successor value to the node to delete
                start->value = temp->value;

                // delete the inorder successor
                deleteNode(temp->value, start->right);
            }
        }
        else if (key > start->value) {
            deleteNode(key, start->right);
        }
        else {
            deleteNode(key, start->left);
        }

        */
    }

    // 4. Display contents: (a) in--, (b) pre--, (c) post-- order'
    void inorder(TreeNode *start) {
        if (start == NULL) return;
        else {
            // left, root, right
            inorder(start->left);
            cout << start->value << "  " << endl;
            inorder(start->right);
        }
    }

    void preorder(TreeNode *start) {
        if (start == NULL) return;
        else {
            // root, left, right
            cout << start->value << "  " << endl;
            preorder(start->left);
            preorder(start->right);
        }
    }

    void postorder(TreeNode *start) {
        if (start == NULL) return;
        else {
            // left, right, root
            postorder(start->left);
            postorder(start->right);
            cout << start->value << "  " << endl;
        }
    }
};

int main() {
    BST tree;
    int choice, value;
    // we'll jumpstart tree with a few values
    // 30, 15, 60, 7, 22, 45, 17, 27, 75 
    tree.addValue(30);
    tree.addValue(15);
    tree.addValue(60);
    tree.addValue(7);
    tree.addValue(22);
    tree.addValue(45);
    tree.addValue(17);
    tree.addValue(27);
    tree.addValue(75);

    while(1) {
        cout << "Enter 1 to add a new value" << endl;
        cout << "Enter 2 to search for a value" << endl;
        cout << "Enter 3 to delete a value" << endl;
        cout << "(other options coming soon)" << endl;
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter a value to add to the tree" << endl;
                cin >> value;
                tree.addValue(value);
                break;
            case 2:
                cout << "Enter a value to search for" << endl;
                cin >> value;
                tree.searchBST(value, tree.root);
                break;
            case 3:
                cout << "Enter a value to delete" << endl;
                cin >> value;
                tree.searchBST(value, tree.root);
                break;
            default:
                cout << "Goodbye!" << endl;
                exit(0);
                break;
        }
    }
}