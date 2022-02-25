// SHawn Aviles
// 2/15/2022 - Pointers example program

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

    // I needed a new tab
    // pointer (lhs) = new chromeTab
    ptr->next = new chromeTab;
    ptr->next->length = 180;    // change new tab's length
    ptr->next->width = 280;     // change new tab's width

    // Third tab please!
    ptr->next->next = new chromeTab;
    // l = 200, w = 100
    ptr->next->next->length = 200;
    ptr->next->next->width = 100;

    // Fourth Tab
    ptr->next->next->next = new chromeTab;
    // l = 10, w = 10
    ptr->next->next->next->length = 10;
    ptr->next->next->next->width = 10;

    // delete pte; // deletes the first one, and you lose access to the rest of them too!
    // deletes function deletes what the pointer is pointing to not the pointer itself
}