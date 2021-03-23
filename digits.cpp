/* Author: Cameron Walcott
 * Program: digits
 * Description: Find and output ones, tens and hundreds digits
 */
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num;
    int ones;
    int tens;
    int hundreds;
    cout << "Enter a number between 0 and 999: ";
    cin >> num;
    
    if(num<10){
        cout << "1's Digit is: " << num << endl;
        cout << "10's Digit is: " << 0 << endl;
        cout << "100's Digit is: " << 0 << endl;
        return 0;
    }else if(num<=99){
        ones = num % 10;
        tens = (num/10);
        cout << "1's digit is: " << ones << endl;
        cout << "10's digit is: " << tens << endl;
        cout << "100's Digit is: " << 0 << endl;
        return 0;
    }else if(num>=100){
        ones = num % 10;
        tens = (num/10) % 10;
        hundreds = (num/100);
        cout << "1's digit is: " << ones << endl;
        cout << "10's digit is: " << tens << endl;
        cout << "100's digit is: " << hundreds << endl;
        return 0;
        
    }
    
}
