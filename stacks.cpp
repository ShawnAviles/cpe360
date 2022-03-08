/*
Shawn Avies
stacks
February 24, 2022
*/
#include <iostream>
using namespace std;

// 1. concept "chunk"
class Chunk {
public:
    int value;
    Chunk *next;

    Chunk() {
        value = 1;
        next = NULL;
    }
};

// 2. Class called "Stack"
// a stack of chunks
// member of functions to add, delete, and display
class Stack {
public:
    Chunk *top;

    Stack() {
        top = NULL;
    }

    // 1. add: Push: adds a new element to the Stack
    void push(int x) {
        // step 1: go get us a new chunk and put 'x' inside the value portion
        Chunk *temp = new Chunk;
        temp->value = x;

        // step 2: to make this new chink the "first" chunk
        // if the stack is empty, make this the first chunk. Else, move the pointers
        if (top == NULL) {
            top = temp;
        }
        else {
            temp->next = top;
            top = temp;
        }
        cout << "Just added a new element: " << top->value << endl;
    }

    // 2. delete: deletes the most recent element in the stack
    void pop() {
        // step 1: check to see if the stack is empty. If yes, nothing to do here.
        // step 2: if it's not empty, just get rid of the first chunk
        if (top == NULL) {
            cout << "Nothing to delete. Empty Stack. " << endl;
        }
        else {
            Chunk *temp;
            temp = top;
            top = top->next;
            cout << "About to delete: " << temp->value << endl;
            delete temp;
        }
    }

    // 3. display: displays the contents in the stack
    void display(){
        Chunk *temp;
        temp = top;

        cout << "-----Stack-----" << endl;
        while (temp != NULL) {
            cout << temp->value << endl;
            temp = temp->next;
        }
        cout << "NULL\n---------------" << endl;
    }
};



int main() {
    Stack S;
    int choice, value;

    while(1) {
        cout << "Press 1 to push to stack" << endl;
        cout << "Press 2 to pop from the stack" << endl;
        cout << "Press 3 to display contents" << endl;
        cout << "Anythng else to quit" << endl;
        cin >> choice;

        switch (choice) {
            case 1: cout << "Enter value to push to stack: " << endl;
                cin >> value;
                S.push(value);
                break;
            case 2: S.pop();
                break;
            case 3: S.display();
                break;
            default: cout << "Goodbye!" << endl;
                exit(1);
        }
    }
  

}