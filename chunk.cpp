/*
Shawn Avies
February 24, 2022
*/
#include <iostream>
using namespace std;

class chunk {
public:
    int value;
    chunk *next;

    chunk() {
        value = 1;
        next = NULL;
    }
};

// PURPOSE of this lecture is to do three things well:
// 1: Add a chunk in the front, middle, and end
// 2: Removre a chunk from the front, middle, and end
// 3: Display the values in a train of chunks

int main() {
    // Phase-0 jumpstart: get three chunks that are knitted together
    // <pointer> = new <type>
    chunk *ptr;
    ptr = new chunk;
    ptr->next = new chunk;
    ptr->next->next = new chunk;


    // Phase-1: Let's add something new to the front, middle, and end
    // front first
    chunk *temp;
    temp = new chunk;
    temp->next = ptr;   //1
    ptr = temp;         //2

    // add to middle
    chunk *temp2;
    temp2 = new chunk;
    temp2->next = ptr->next->next;  //1
    ptr->next->next = temp;         //2

    // add to the end;
    chunk *temp3;
    temp3 = new chunk;
    ptr->next->next->next = temp3;
    // can do in 1 line: ptr->next->next->next = new chunk;
    // already grounded by default tso thats it


    // Phase-2: Remove a chunk from the front, middle, and end;
    //grab the address of the thing you want to delete. Next isolate it (re-organize your structure, and finally delete the chunk
    // remove from front
    chunk *temp4;
    temp4 = ptr; //1
    ptr = ptr->next; //2
    delete temp; // deletes whatever temp is pointing to

    // remove from middle
    temp4 = ptr->next->next;
    ptr->next->next = ptr->next->next->next;
    delete temp4;

    // remove last chunk
    // temp = ptr->next->next->next;
    // ptr->next->next->next = NULL;
    // delete temp;
    // Or
    delete ptr->next->next->next;
    ptr->next->next->next = NULL;

    

    

}