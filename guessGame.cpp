#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int main() {
    // Guessing gmae as preface to final Project - Day in the Life of the Queue
    int secret;
    int guess, count = 0;

    srand(time(NULL));
    secret = rand()%10 + 1;

    while(count < 3) {
        cout << "Guess?" << endl;
        cin >> guess;
        if (guess == secret) {
            cout << "You win!" << endl;
            exit(0);
        }
        count++;
    }
    cout << "My secret number is: " << secret << endl;
}