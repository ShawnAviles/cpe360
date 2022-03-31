// Shawn Aviles
// March 31, 2022
// linked list - Midterm Take Home
// I pledge my honor that I have abided by the Stevens Honor System. -Shawn Aviles

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

    /* 3.
    7) Given access to the "head" pointer, write a function to find and delete a value (key) from
    a LinkedList. Your function should search for the value (key), and delete the first
    occurrence of that value. If the value does not exist in the list, your function prints an
    appropriate message and deletes nothing.
    In other words, implement void findAndDelete (int key)
    */
    void findAndDelete(int key) {
        // empty linked list - edge case
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        // if key value is at head
        if (key == head->value) {
            Chunk *temp = head;
            head = head->next;
            delete temp;
            size--; // needed to work in LL class but not needed for Take Home #7
            return;
        }
        // delete key
        else {
            Chunk *chase, *follow;
            chase = follow = head;

            while (chase != NULL) {
                if (key == chase->value) {
                    follow->next = chase->next;
                    delete chase;
                    size--; // needed to work in LL class but not needed for Take Home #7
                    return;
                }
                follow = follow->next;
                chase = follow->next;
            }
            cout << "Value does not exist in the list " << endl;
        }
    }

    /* 4.
    8. Write a function to reverse the contents of a linked list. For e.g., a list like
    "head->1-2-3-NULL" becomes "head-›3-2>1-›NULL" after the function call.
    Implement void reverseList()
    */
    void reverseList() {
        Chunk *prev = NULL;
        Chunk *curr = head;
        Chunk *next;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    /* 5.
    9. Write a function to delete every node in the linked list. After your function call, every
    chunk should be deleted and the 'head' pointer set to NULL. In other words, implement
    void deleteLinkedList()
    */
    void deleteLinkedList() {
        Chunk *temp = head;
        while (temp != NULL) {
            head = head->next;
            delete temp;
            temp = head;
        }
        size = 0; // needed to work in LL class but not needed for Take Home #9
        head = NULL;
    }


    // 6. Display
    void displayContents() {
        Chunk *temp = head;
        cout << "----------\nLinked List: ";
        for (int i = 0; i < size; i++){
            cout << temp->value << " --> ";
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
        cout << "Press 3 to remove from a position of the linked list" << endl;
        cout << "Press 4 to remove specifc value from the linked list" << endl;
        cout << "Press 5 to reverse the linked list" << endl;
        cout << "Press 6 to delete all values from the linked list" << endl;
        cout << "Press 7 to display contents" << endl;
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
            case 4: 
                cout << "Enter value to remove:  " << endl;
                cin >> value;
                linked.findAndDelete(value);
                break;
            case 5: linked.reverseList();
                break;
            case 6: linked.deleteLinkedList();
                break;
            case 7: linked.displayContents();
                break;
            default: cout << "Goodbye!" << endl;
                exit(1);
        }
    }
}