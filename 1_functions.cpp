#include <iostream>

using namespace std;

int factorial(int n){
    if (n < 0) {
        return -1;
    }
    else {
        int x = 1;
        for (int i = n; i > 0; i-- )
            x *= i;
        return x;
    }
}

// Recursion
int recFactorial(int n) {
    if (n < 0)
        return -1;

    // (I): Answer to simplest instance of problem
    // "Base Case" or "Anchor Value"
    if (n == 1) 
        return 1;
    // (II): Reducing the original instance towards the base case 
    // exploiting a pattern that is inherent in the problem
    else{
        return n * recFactorial(n-1); 
    }
    
}


int main() {
    int n;

    cout << "Give me a number: ";
    cin >> n;

    cout << "Factorial is: " << recFactorial(n) << endl;

    return 1;
}
