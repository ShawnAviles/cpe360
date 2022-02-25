#include<iostream>
using namespace std;

void hanoi(int N, char S, char I, char D){
    // variable is shared across function calls
    static int count = 0;
    // (I): Base Case
    if (N == 1)
        cout << "Move [" << ++count << "] " << N << " from " << S << " ---> " << D << endl;
    // (II): Drive N towards base case
    else {
        hanoi(N-1, S, D, I);
        cout << "Move [" << ++count << "] " << N << " from " << S << " ---> " << D << endl;
        hanoi(N-1, I, S, D);
    }
}


int main(){
    int N;
    // source, intermediary, disciplinary
    char S = 'S', I = 'I', D = 'D';

    cout << "Give me a # of discs: " << endl;
    cin >> N;

    hanoi(N, S, I, D);
    return 1;
}