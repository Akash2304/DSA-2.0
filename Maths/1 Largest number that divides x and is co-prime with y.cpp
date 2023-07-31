/**************************************************************************************************************************************************************************
Given two positive numbers x and y. Find the maximum valued integer a such that: 
 

a divides x i.e. x % a = 0
a and y are co-prime i.e. gcd(a, y) = 1
Examples : 
 

Input : x = 15
        y = 3 
Output : a = 5
Explanation: 5 is the max integer 
which satisfies both the conditions.
             15 % 5 =0
             gcd(5, 3) = 1
Hence, output is 5. 

Input : x = 14
        y = 28
Output : a = 1
Explanation: 14 % 1 =0
             gcd(1, 28) = 1
Hence, output is 1. 
**************************************************************************************************************************************************************************/
// CPP program to find the
// Largest Coprime Divisor

#include <bits/stdc++.h>
using namespace std;

// Recursive function to return gcd
// of a and b
int gcd(int a, int b)
{
	// Everything divides 0
	if (a == 0 || b == 0)
		return 0;

	// base case
	if (a == b)
		return a;

	// a is greater
	if (a > b)
		return gcd(a - b, b);
	return gcd(a, b - a);
}

// function to find largest
// coprime divisor
int cpFact(int x, int y)
{
	while (gcd(x, y) != 1) {
		x = x / gcd(x, y);
	}
	return x;
}

// divisor code
int main()
{
	int x = 15;
	int y = 3;
	cout << cpFact(x, y) << endl;
	x = 14;
	y = 28;
	cout << cpFact(x, y) << endl;
	x = 7;
	y = 3;
	cout << cpFact(x, y);
	return 0;
}

