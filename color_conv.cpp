/* Author: YOUR NAME HERE
 * Program: color_conv
 * Description: Converts RGB -> CMYK color representation
 */
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int red;
    int green;
    int blue;
    double cyan;
    double magenta;
    double yellow;
    double black;
    double white;
    double red1;
    double green1;
    double blue1;
    
    cout << "Enter red: ";
    cin >> red;
    cout << "Enter green: ";
    cin >> green;
    cout << "Enter blue: ";
    cin >> blue;
    
    red1 = red/255.0;
    green1 = green/255.0;
    blue1 = blue/255.0;
    
    if(red>green){
        white = max(red1,green1);
    }else{
            white = max(green1,blue1);
        }
        
    cyan = (white-red1) / (white);
    magenta = (white-green1) / (white);
    yellow = (white-blue1) / (white);
    black = 1 - white;

    cout << "cyan = " << cyan << endl;
    cout << "magenta = " << magenta << endl;
    cout << "yellow = " << yellow << endl;
    cout << "black = " << black << endl;
    
}