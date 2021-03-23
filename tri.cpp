#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

int main() {
    double angle;
    cout << "Enter an angle: ";
    cin >> angle;
    if(angle<15 || angle>75){
        cout << "error" << endl;
        return 0;
    }
    
    double pi = 3.14159265;
    angle = (angle*pi)/(180);
    
    for(int r = 1; r<=31; r++){
        int oper = floor(r*tan(angle));
        if((oper)>=20 && (oper)<=30){
            for(int widths=1; widths<=20; widths++){
                cout << "*";
            }
            cout << endl;
        }else{
            for(int width=1; width<=(oper); width++){
                cout << "*";
            }
            cout << endl;
        }
    }
    
    return 0;
}