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

// customers
class Customer {
public:
    Customer *next;
    Customer *prev;
    int inTime;             // time when customer enters the burger joint
    int outTime;            // time when customer leaves the burger joint, varies depending on first person in line etc.
    int orderTime;          // individual order time of customer (1-6 minutes)

    // default constructor used for traversals
    Customer() {
        next = NULL;
        prev = NULL;
    }

    Customer(int newInTime, int newOrderTime) {
        inTime = newInTime;
        orderTime = newOrderTime;
        next = NULL; // in front of them in line
        prev = NULL; // behind them in line
    }
};

// queue class with head and tail pointers
class Queue {
public:
    Customer *head;
    Customer *tail;
    int customersInLine = 0;
    int waitTime = 0;
    int totalCustomers = 0;
    int serviceTime = 0;
    int queueLength = 0;

    int worstCaseTime = 0;
    int worstCaseWait = 0;
    int worstCaseService = INT_MIN;
    int worstCaseQueueLength = 0;

    int bestCaseTime = 0;
    int bestCaseWait = 0;
    int bestCaseService = INT_MAX;
    int bestCaseQueueLength = 0;

    Queue() {
        head = NULL; // back of the line
        tail = NULL; // front of the line
    }


    void enqueue(int inTime, int orderTime) {
        Customer *temp = new Customer(inTime, orderTime);

        // enqueue the customer
        if (head == NULL) {
            temp->outTime = temp->inTime + temp->orderTime;
            head = temp;
            tail = head;
            //cout << "expected leave time (1): " << temp->outTime << endl;
        }
        else {
            temp->outTime = head->outTime + temp->orderTime;
            temp->next = head;
            head->prev = temp;
            head = temp;
            //cout << "expected leave time (2): " << temp->outTime << endl;
        }
        waitTime += (temp->outTime - temp->orderTime) - temp->inTime;
        serviceTime += temp->outTime - temp->inTime;
        customersInLine++;
        totalCustomers++;

        
        if (bestCaseService > temp->outTime - temp->inTime) {
            bestCaseService = temp->outTime - temp->inTime;
            bestCaseTime = temp->inTime;
            bestCaseWait = (temp->outTime - temp->orderTime) - temp->inTime;
            bestCaseQueueLength = customersInLine;
        }
        
        if(worstCaseService < temp->outTime - temp->inTime) {
            worstCaseService = temp->outTime - temp->inTime;
            worstCaseTime = temp->inTime;
            worstCaseWait = (temp->outTime - temp->orderTime) - temp->inTime;
            worstCaseQueueLength = customersInLine;
        } 
    }

    void dequeue(int currentTime) {
        Customer *temp;
        if (head == NULL) {
            return;
        }

        // assuming that the outTime is calculated correctly then
        // this should dequeue the customer at the right time and properly adjust the tail and prev values
        if (tail->outTime == currentTime) {
            if (head->next == NULL) {
                cout << "   Leaving: Customer that came in at " << head->inTime << " leaves at " << currentTime << endl;
                delete head;
                head = NULL;
                tail = NULL;
            }
            else {
                cout << "   Leaving: Customer that came in at " << tail->inTime << " leaves at " << currentTime << endl;
                temp = tail;
                tail = temp->prev;
                tail->next = NULL;
                delete temp;
            }
            customersInLine--;
        }
    }

    // display contents of Q
    bool printContents() {
        Customer *temp;

        if(head == NULL) {
            cout << "Empty Q" << endl;
            return false;
        }
        else {
            temp = head;
            cout << "------CUSTOMERS-----" << endl;
            while (temp != NULL) {
                cout << "Customer in at " <<  temp->inTime << "     Expected to leave at " << temp->outTime << endl;
                temp = temp->next;
            }
            cout << "--------------------" << endl;
            return true;
        }
    }
};


int main() {
    int TIME = 1, generator, orderTime;
    int totalQueueLength = 0;
    Queue Q;

    srand(time(NULL));

    // store hours, every minute of the day
    // 8am-1am -> 17 hours -> 1020 minutes
    while(TIME <= 1020) {
        totalQueueLength += Q.customersInLine; 

        // 1. should we add a new customer to the Q at this minute?
        // 8am-10am                 BREAKFAST
        if (TIME > 0 && TIME <= 120) { // should be to 120
            generator = rand() % 100 + 1;
            if (generator <= 30) {
                orderTime = rand() % 6 + 1;
                cout << "New Customer arrived at time: " << TIME << " with order time: " << orderTime << endl;
                Q.enqueue(TIME, orderTime);
            }
            Q.dequeue(TIME);
        }

        // 10am-11:30am
        else if (TIME > 120 && TIME <= 210) {
            generator = rand() % 100 + 1;
            if (generator <= 10) {
                orderTime = rand() % 6 + 1;
                cout << "New Customer arrived at time: " << TIME << " with order time: " << orderTime << endl;
                Q.enqueue(TIME, orderTime);
            }
            Q.dequeue(TIME);
        }

        // 11:30am-1:30pm           LUNCH
        else if (TIME > 210 && TIME <= 330) {
            generator = rand() % 100 + 1;
            if (generator <= 40) {
                orderTime = rand() % 6 + 1;
                cout << "New Customer arrived at time: " << TIME << " with order time: " << orderTime << endl;
                Q.enqueue(TIME, orderTime);
            }
            Q.dequeue(TIME);
        }

        // 1:30pm-5:30pm
        else if (TIME > 330 && TIME <= 570) {
            generator = rand() % 100 + 1;
            if (generator <= 10) {
                orderTime = rand() % 6 + 1;
                cout << "New Customer arrived at time: " << TIME << " with order time: " << orderTime << endl;
                Q.enqueue(TIME, orderTime);
            }
            Q.dequeue(TIME);
        }
        // 5:30pm-8pm               DINNER           
        else if (TIME > 570 && TIME <= 720) {
            generator = rand() % 100 + 1;
            if (generator <= 25) {
                orderTime = rand() % 6 + 1;
                cout << "New Customer arrived at time: " << TIME << " with order time: " << orderTime << endl;
                Q.enqueue(TIME, orderTime);
            }
            Q.dequeue(TIME);
        }
        // 8pm-11pm
        else if (TIME > 720 && TIME <= 900) {
            generator = rand() % 100 + 1;
            if (generator <= 20) {
                orderTime = rand() % 6 + 1;
                cout << "New Customer arrived at time: " << TIME << " with order time: " << orderTime << endl;
                Q.enqueue(TIME, orderTime);
            }
            Q.dequeue(TIME);
        }
        // 11pm-1am
        else {
            generator = rand() % 100 + 1;
            if (generator <= 10) {
                orderTime = rand() % 6 + 1;
                cout << "New Customer arrived at time: " << TIME << " with order time: " << orderTime << endl;
                Q.enqueue(TIME, orderTime);
            }
            Q.dequeue(TIME);
        }
        // 2. is the customer going to place an order this minute?
        // 3. customer is ready to depart the store at this minute?
        
        TIME ++;
    }
    if (Q.printContents()){
        cout << "Head: " << Q.head->inTime << endl;
        cout << "Tail: " << Q.tail->inTime << endl;
        cout << "Customers in line: " << Q.customersInLine <<  endl;
    }

    /*
    2.1 how good is the current system
    Average Customer Wait Time
    Average Customer Service Time
    Average Queue Length
    Best Case and Worse Case
    */
    cout << "Average Customer Wait Time: " << (double)Q.waitTime/(double)Q.totalCustomers << endl;
    cout << "Average Customer Service Time: " << (double)Q.serviceTime/(double)Q.totalCustomers << endl;
    cout << "Average Queue Length: " << (double)totalQueueLength/(double)TIME << endl;
    cout << "Best Case: \n At time: " << Q.bestCaseTime << "\n Service Time: " << Q.bestCaseService << "\n Wait Time: " << Q.bestCaseWait << " \n Queue Length: " << Q.bestCaseQueueLength << endl;
    cout << "Wort Case: \n At time: " << Q.worstCaseTime << "\n Service Time: " << Q.worstCaseService << "\n Wait Time: " << Q.worstCaseWait << " \n Queue Length: " << Q.worstCaseQueueLength << endl;

}
