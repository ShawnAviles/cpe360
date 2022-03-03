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
        Chunk *temp = new Chunk;
        temp->value = x;

        if (top == NULL) {
            top = temp;
        }
        else {
            temp->next = top;
            top = temp;
        }
    }

    // 2. delete: deletes the most recent element in the stack
    void pop() {

    }

    // 3. display: displays the contents in the stack
    void display(){
        Chunk *temp;
        temp = top;
        if (top == NULL) {
            
        }
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
            default: exit(1);
        }
    }
  

}