#include <iostream>
#include "bigint.h"

using namespace std;

int main(){
	BigInt xy("1738");
	BigInt yz("1050");
	xy.add(yz);
	cout << xy.number[1] << endl;
	return 0;
}