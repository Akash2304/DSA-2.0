/***************************************************************************************************************************************************************************
A magic number is defined as a number which can be expressed as a power of 5 or sum of unique powers of 5. First few magic numbers are
5, 25, 30(5 + 25), 125, 130(125 + 5), ….
Write a function to find the nth Magic number.
Example: 

Input: n = 2
Output: 25

Input: n = 5
Output: 130 
***************************************************************************************************************************************************************************/

// C++ program to find nth magic number
#include <bits/stdc++.h>
using namespace std;

// Function to find nth magic number
int nthMagicNo(int n)
{
	int pow = 1, answer = 0;

	// Go through every bit of n
	while (n)
	{
	pow = pow*5;

	// If last bit of n is set
	if (n & 1)
		answer += pow;

	// proceed to next bit
	n >>= 1; // or n = n/2
	}
	return answer;
}

// Driver program to test above function
int main()
{
	int n = 5;
	cout << "nth magic number is " << nthMagicNo(n) << endl;
	return 0;
}

/**********************************************************************************************************************************************************************/
