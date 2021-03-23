/* Author: YOUR NAME HERE
 * Program: compute_sin
 * Description: Reads a number x from input, an angle in radians. 
 *    Computes an approximation to sin(x) using an 4th-order Taylor series.
 */
#include <iostream>
#include <cmath>

using namespace std;

int fact(int); // declares a function the skeleton defines for you.

int main()
{
   // Declare any variables you need here
   double x;
   double ans;
   // Prompt the user
   cout << "Enter x in radians:  ";
   
   // get input
   cin >> x;
   
   // Do some operations
   ans = x - (x*x*x)/(3*2) + (x*x*x*x*x)/(5*4*3*2) - (x*x*x*x*x*x*x)/(7*6*5*4*3*2);
   
   // Print the result to the user
   cout << "sin(" << x << ") = " << ans << endl; 
   
   // You're done
   return 0;
   
}

// here's the actual definition of fact, declared earlier.
int fact(int n)
{
   int result = 1;
   for (int i = 1; i <= n; i++) {
      result = result * i;
   }
   return result;
}

