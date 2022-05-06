/*
Shawn Aviles
May 3, 2022
Binary Search Tree

I pledge my honor that I have abided by the Stevens Honor System. -Shawn Aviles
Note: code from previous BST assignment was used as a baseline for this 
*/


#include <iostream>
#include <vector>
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

    int minValTree(TreeNode *start) {
        // this case is not needed in the context of case 3
        if (start == NULL) {
            return -1;
        }

        while (start->left != NULL) start = start->left;
        return start->value;
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
            // so lets figure out what case are we dealing with
            // take into account if root or not

            // case 1: leaf node, no children
            if (fast->left == NULL && fast->right == NULL) {
                // delete the node
                cout << "\nDeleting leaf node - Case I\n" << endl;

                if (fast == start) {
                    start = NULL;
                }
                else {
                    if (key < slow->value) { // slow->left == fast;
                        slow->left = NULL;
                        cout << "About to delete: " << fast->value << endl;
                    }
                    else {
                        slow->right = NULL;
                        cout << "About to delete: " << fast->value << endl;
                    }
                }
                delete fast;
            }

            // case 2: node with one child
            else if (fast->left == NULL && fast->right != NULL){
                // delete the node
                cout << "\nDeleting node with one child - Case II" << endl;

                if (fast == start) {
                    start = fast->right;
                }
                else {
                    if (key < slow->value) {
                        slow->left = fast->right;
                        cout << "About to delete: " << fast->value << endl;
                    }
                    else {
                        slow->right = fast->right;
                        cout << "About to delete: " << fast->value << endl;
                    }
                }
                delete fast;
                
            }
            else if (fast->left != NULL && fast->right == NULL) {
                // delete the node
                cout << "\nDeleting node with one child - Case II" << endl;

                if (start == fast) {
                    start = fast->left;
                }
                else {
                    if (key < slow->value) {
                        slow->left = fast->left;
                        cout << "About to delete: " << fast->value << endl;
                    }
                    else {
                        slow->right = fast->left;
                        cout << "About to delete: " << fast->value << endl;
                    }
                }
                delete fast;
            }

            // case 3: node with two children
            else {
                // find the smallest value in the right subtree
                // and replace the value of the node to be deleted
                cout << "\nDeleting node with two children - Case III" << endl;
                
                // 1. breathe
                // 2. don't actually delete this node
                // 3. we'll find a value to swap with this node
                // 4. minValueRightSubTree

                int swap = minValTree(fast->right);
                deleteNode(swap, root);
                fast->value = swap;
            }
        }


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

    // 5. Questions 8,9,10 from Midterm 2

    // 8) Present an algorithm to delete a tree. 
    // In other words, implement the following function: void deleteTree(TreeNode *root)
    void deleteTree(TreeNode *root) {
        if (root == NULL) return;
        else {
            // post order traversal
            deleteTree(root->left);
            deleteTree(root->right);
            cout << "Deleting: " << root->value << endl;
            delete root;
        }
    }
    // void deleteTree by itself doesn't set the root to NULL which is needed to not receive an error when traversing
    void deleteTreeSafe(TreeNode** rootRef){
        deleteTree(*rootRef);
        *rootRef = NULL;
    }

    // 9) Present an algorithm to check if a given tree is balanced. 
    // The algorithm returns true if the tree is balanced, and false otherwise (bool isBalanced(TreeNode *start))
    // Note: Assuming height-balanced - height of left and right subtree differ by no more than 1
    bool isBalanced(TreeNode *start){
        TreeNode *temp = start;
        int heightL;
        int heightR;

        if (start == NULL) {
            return 1;
        }
        
        heightL = height(temp->left);
        heightR = height(temp->right);

        if (abs(heightL - heightR) <= 1 && isBalanced(temp->left) && isBalanced(temp->right)){
            return true;
        }
        else {
            return false;
        }
    }

    int height(TreeNode *start) {
        if (start == NULL) {
            return 0;
        }
        else {
            return 1 + max(height(start->left), height(start->right));
        }
    }

    // 10) Given two nodes in a BST, present an algorithm to find the first common parent for these nodes. 
    // In other words, design and implement int firstCommonParent(int value1, int value2)
    int firstCommonParent(int value1, int value2) {
        TreeNode *temp = root;

        while (temp != NULL) {
            // if val1 and val2 < root, first common parent is on the left
            if (value1 < temp->value && value2 < temp->value) {
                temp = temp->left;
            }
            // if val1 and val2 > root, first common parent is on the right
            else if (value1 > temp->value && value2 > temp->value) {
                temp = temp->right;
            }
            // if val1 and val2 are on different sides of root than we have foind 
            else {
                break;
            }
        }
        return temp->value;
    }
     
};

int main() {
    BST tree;
    int choice, value, value2;
    tree.addValue(5);
    tree.addValue(3);
    tree.addValue(8);
    tree.addValue(1);
    tree.addValue(4);
    tree.addValue(6);
    tree.addValue(10);
    // tree.addValue(11);
    // tree.addValue(12);
    /*
              5
           /    \
          3      8
         / \    / \
        1   4  6   10
    */
    

    while(1) {
        cout << "Enter 1 to add a new value" << endl;
        cout << "Enter 2 to search" << endl;
        cout << "Enter 3 for in-order" << endl;
        cout << "Enter 4 for pre-order" << endl;
        cout << "Enter 5 for post-order" << endl;
        cout << "Enter 6 to delete a node" << endl;
        cout << "Enter 7 to delete the tree" << endl;
        cout << "Enter 8 to determine if the tree is balanced" << endl;
        cout << "Enter 9 find the first common parent of two nodes" << endl;
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
                cout << "Displaying in-order" << endl;
                tree.inorder(tree.root);
                break;
            case 4:
                cout << "Displaying pre-order" << endl;
                tree.preorder(tree.root);
                break;
            case 5:
                cout << "Displaying post-order" << endl;
                tree.postorder(tree.root);
                break;
            case 6:
                cout << "Deleting Value" << endl;
                cout << "Enter a value to delete" << endl;
                cin >> value;
                tree.deleteNode(value, tree.root);
                break;
            case 7:
                cout << "Deleting entire tree..." << endl;
                tree.deleteTreeSafe(&tree.root);
                break;
            case 8:
                if (tree.isBalanced(tree.root)) cout << "The tree IS balanced" << endl;
                else cout << "The tree IS NOT balanced" << endl;
                break;
            case 9:
                cout << "Finding First Parents" << endl;
                cout << "Enter the first child: ";
                cin >> value;
                cout << "Enter the second child: ";
                cin >> value2;
                cout << "First Common Parent: " << tree.firstCommonParent(value, value2) << endl;
                break;
            default:
                cout << "Goodbye!" << endl;
                exit(0);
                break;
        }
    }
}