// SHawn Aviles
// 2/17/2022

#include <iostream>
using namespace std;

class chromeTab {
public:
    // declare variables
    int length;
    int width;
    chromeTab *next;

    // constructor
    chromeTab() {
        length = 40;
        width = 20;
        next = NULL;
    }
};

int main() {
    // =====================
    // Creating and Deleting Chunks
    // =====================
    chromeTab *p;
    p = new chromeTab;  // creating new chunks
    delete p;           // delete the chunk 'p' is pointing to
                        // VERY IM: this only deletes the chunk, NOT p


    // 1. Get Pointer
    // 2. Use that to get a "new" tab from the heap
    // 3. Use that pointer to manipulate this nameless object

    chromeTab *ptr;
    ptr = new chromeTab;

    cout << "Just Checking 1, L: " << ptr->length << ", w: " << ptr->width << endl;

    // change length to 80 and width to 100
    ptr->length = 80;
    ptr->width = 100;

    // 2nd chunk
    ptr->next = new chromeTab;
    // 3rd chunk
    ptr->next->next = new chromeTab;

    // add something to the front
    // 1. get temp pointer to create a new chunk 
    // 2. conntect this 'new' chunk to the existing train
    // 3. get 'ptr' to connect to this 'new' chunk
    chromeTab *temp;
    temp = new chromeTab;       // 1. done
    temp->next = ptr;           // 2. done
    ptr = temp;                 // 3. done

    // add something to the middle
    // basically, this new chunk should be the new "third" chunk
    temp = new chromeTab;           // 1
    temp->next = ptr->next->next;   // 2
    ptr->next->next = temp;         // 3
    
    // display chunks
    temp = ptr;
    int count = 0;
    while(temp) {       // temp != NULL
        cout << "Chunk #" << ++count << endl;
        cout << "Length: " << temp->length << endl;
        temp = temp->next;

    }
}