/********************************************************
 * CS 103 PA 1: Abundant numbers
 * Name:
 * USC email:
 * Comments (you want us to know):
 *
 * Description:
 *   Displays the top 3 most "abundant" (see writeup)
 *   numbers in the input sequence.  The input sequence
 *   is assumed to be valid natural numbers separated
 *   by spaces and ending with 0.
 *
 *   ABSOLUTELY NO ARRAY or `string`/`vector`/etc. usage
 *   is allowed!

 *   You may only declare: bool, int, or unsigned int
 *   No library functions (beyond cin/cout) are allowed.
 *
 *   You may NOT modify any of the given template code.
 *   This ensures our automated checkers can parse your
 *   output.  Failure to follow this direction will lead
 *   to a score of 0 on this part of the assignment.
 ********************************************************/

#include <iostream>
using namespace std;

int main()
{
  // n1 is the number with the highest abundance, a1
  // n2 is the number with the 2nd-highest abundance, a2
  // n3 is the number with the 3rd-highest abundance, a3
  unsigned int n1 = 0, n2 = 0, n3 = 0;
  int a1 = 0, a2 = 0, a3 = 0;

  // num_abundant counts how many numbers in the input
  // sequence are abundant
  int num_abundant = 0;

  cout << "Enter a sequence of natural numbers, separated by spaces, ";
  cout << "and ending with 0."<< endl;

  /* Your code here */
    int num = 1;
    int i2 = 0;
    while(num != 0){ //checks that the input is not zero
        cin >> num; 
        for (int i = 1; i < num; i++){ // for loop used to find prime factors
            if (num % i == 0){
                i2 = i2 + i; // adds prime factors
            }
        }
        
        // series of if statements that will store and swap values (number and abundance). Used to update the data set 
        
        if(num<i2){
           num_abundant = num_abundant + 1; 
            if(i2>a1){
                n3 = n2;
                a3 = a2;
                n2 = n1;
                a2 = a1;
                n1 = num;
                a1 = i2;
            }else if(i2>a2){
                n3 = n2;
                a3 = a2;
                n2 = num;
                a2 = i2;
            }else if(i2>a3){
                n3 = num;
                a3 = i2;
            }
        }
        i2 = 0; // resets value of the sum of factors for each iteration of the loop
    } // while loop ends when user inputs 0
 

    
    
  /* End of your code */

  cout << "Abundant number count: " << num_abundant << endl;
  cout << "Top 3 most abundant numbers: " << endl;
  cout << n1 << " : " << a1 << endl;
  cout << n2 << " : " << a2 << endl;
  cout << n3 << " : " << a3 << endl;


  return 0;

}
