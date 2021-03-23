#include <iostream>
#include "bigint.h"

using namespace std;

BigInt::BigInt(string s)
{
	len = s.length() - 1;

	for (int i = len; i >= 0; i--){
		dig = ((int)s[i]) - 48;
		number.push_back(dig);
	}
}

string BigInt::to_string()
{
	size = number.size() - 1;
	stringNum = "";

	for (int i = size; i >= 0; i--){
		stringNum += (char)(number[i] + 48);
	}
	return stringNum;
}

void BigInt::add(BigInt b)
{
	sum = 0;
	carry = 0;

	if(number.size() != b.number.size()){
		while(number.size() != b.number.size()){
			if(number.size() > b.number.size()){
				b.number.push_back(0);
			}
			else{
				number.push_back(0);
			}
		}
	}

	for (int i = 0; i < number.size(); i++){
		sum = number[i] + b.number[i] + carry;
		carry = 0;
		carry = sum / 10;
		number[i] = (sum % 10);
	}
    
	if(carry > 0){
		number.push_back(carry);
	}
}