#include <iostream>
#include <cstdlib>
using namespace std;

int roll(){
    return (rand() % 6) + 1;
}

int line = 4;
int sum = 0;
int counts[21];
void printHistogram(){
    for(int i = 0; i < 21; i++){
        cout << line << ':';
        for (int j = 0; j < counts[i]; j++) {
            cout << 'X';
        }
        cout << endl;
        line = line + 1;
    }
}
int main() {
    srand(time(0));
    for (int i = 0; i < 21; i++) {
        counts[i] = 0;
    }
    int n = 0;
    cout << "How many rolls would you like to do?: ";
    cin >> n;
    for(int i=0; i < n; i++){
        for(int j=0; j < 4; j++){
            sum = sum + roll();
        }
        counts[sum-4] = counts[sum-4] + 1;
        sum = 0;
    }
    printHistogram();
    return 0;
}


