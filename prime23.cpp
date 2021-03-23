#include <iostream>
using namespace std;


int main(){
    int n;
    int count2 = 0;
    int count3 = 0;
    cout << "Enter a positive integer: ";
    cin >> n;
    if((n % 2 == 0) && (n % 3 ==0)){
        while((n % 2 == 0) || (n % 3 ==0)){
            if (n % 2 == 0){
                count2++;
                n = n/2;
            }
            else if (n % 3 == 0){
                count3++;
                n = n/3;
            }
            
        }
        cout << "Twos=" << count2 << endl;
        cout << "Threes=" << count3 << endl;
    }else{
        cout << "No" << endl;
    }
}