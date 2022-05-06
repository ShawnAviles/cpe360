/*
Shawn Aviles
CPE 360 - Final Project
Day in the Life of a Queue

"I pledge my honor that I have abided by the Stevens Honor System."
-Shawn Aviles
*/

/*
Assignment Notes
3 peak times - breakfast, lunch, dinner
*/

#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

// cusomters
class Customer {
public:
    int inTime;
    int outTime;
    int orderTime;

};

// queue class with head andt tail pointers
class Queue {
public:
    Customer *head;
    
    Queue() {
    }

    void enqueue(int inTime, int orderTime) {
        
    }

    void dequeue() {

    }
};


int main() {
    int TIME = 0, generator;
    int cumulativeTime = 0;
    int customerCount = 0;
    int cumulativeQLength;
    // use as many variables as needed

    srand(time(NULL));

    // store hours, every minute of the day
    // 8am-1am -> 17 hours -> 1020 minutes
    while(TIME < 1020) {
        // 1. should we add a new customer to the Q at this minute?
        if (TIME > 0 && TIME <= 120) {
            // 8am - 10am 
            generator = rand() % 100 + 1;
            if (generator <= 30) {
                generator = rand() % 6 + 1;
                cout << "New Customer arrived at time: " << TIME << " with order time: " << generator << endl;
                
               // add customer to Q: Q.enqueue();
            }
        }
        // else if (all other time slots) { }


        // 2. is the customer going to place an order this minute?
        // 3. ustomer is ready to depart the store at this minute?
        TIME ++;
    }
}
