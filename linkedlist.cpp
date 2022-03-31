// Shawn Aviles
// March 8, 2022
// linked list

#include<iostream>
using namespace std;

class Chunk {
public:
    int value;
    Chunk *next;

    Chunk() {
        value = -1;
        next = NULL;
    }
};

class LL {
public:
    Chunk *head;
    int size;

    LL() {
        head = NULL;
        size = 0;
    }

    // 0. insert at the head
    void insertAtHead(int value) {
        Chunk *temp = new Chunk();
        temp->value = value;
        temp->next = head;
        head = temp;
        size++;
    }

    // 1. Add: value & position
    void insertAtPosistion(int value, int pos) {
        // first check to see if this positon is valid
        if (pos <= size + 1){
            Chunk *temp = new Chunk;
            temp->value = value;

            if (pos == 1) {
                // exactly like push to stack
                temp->next = head;
                head = temp;
                size++;
                return;
            }
            
            Chunk *help = head;
            for (int i = 1; i < pos - 1 ; i++){
                help = help->next;
            }
            temp->next = help->next;    // 1
            help->next = temp;          // 2
            size++;
        }
        else {
            cout << "Invalid Position" << endl;
            return;
        }
    }

    // 2. Remove: position
    void removeFromPosistion(int pos) {
        if (pos <= size) {
            if (pos == size && size == 1){
                // deleting lone chunk
                delete head;
                head = NULL;
            }

            if (pos == 1) {
                // exactly like stacks
                Chunk *temp = head;
                head = head->next;
                delete temp;
            }
            else if (pos == size) {
                // like a queue
                Chunk *chase = head, *follow = head;
                for (int i = 1; i <= pos; i++) {
                    follow = chase;
                    chase = chase->next;
                }
                follow->next = NULL;
                delete chase;
            }
            else {
                Chunk *chase, *follow;
                chase = follow = head;

                for (int i = 1; i <= pos; i++) {
                    follow = chase;
                    chase = chase->next;
                }
                follow->next = chase->next;
                delete chase;
            }
            size--;
        }
        else {
            cout << "Invalid position" << endl;
            return;
        }

        
    }
    // 3. Display
    void displayContents() {
        Chunk *temp = head;

        cout << "----------\nLinked List: ";
        for (int i = 0; i < size; i++){
            cout << temp -> value << " --> ";
            temp = temp->next;
        }
        cout << "NULL\n----------\n";
    }

};

int main() {
    LL linked;
    int choice, value, pos;

    while(1) {
        cout << "Press 1 to add something to the head of the linked list" << endl;
        cout << "Press 2 to add something anywhere to the linked list" << endl;
        cout << "Press 3 to remove something from the linked list" << endl;
        cout << "Press 4 to display contents" << endl;
        cout << "Anythng else to quit" << endl;
        cin >> choice;

        switch (choice) {
            case 1: 
                cout << "Enter value to add to the head of the linked list: " << endl;
                cin >> value;
                linked.insertAtHead(value);
                break;
            case 2: 
                cout << "Enter value to add to linked list: " << endl;
                cin >> value;
                cout << "Enter position of where to add it: " << endl;
                cin >> pos;
                linked.insertAtPosistion(value, pos);
                break;
            case 3: 
                cout << "Enter position to remove:  " << endl;
                cin >> pos;
                linked.removeFromPosistion(pos);
                break;
            case 4: linked.displayContents();
                break;
            default: cout << "Goodbye!" << endl;
                exit(1);
        }
    }
}