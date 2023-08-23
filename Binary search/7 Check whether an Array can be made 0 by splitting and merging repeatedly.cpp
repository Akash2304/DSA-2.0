/***************************************************************************************************************************************************************************
Given an array arr[] with N elements, the task is to find whether all the elements of the given array can be made 0 by given operations. 
Only 2 types of operations can be performed on this array: 

Split an element B into 2 elements C and D such that B = C + D.
Merge 2 elements P and Q as one element R such that R = P^Q i.e. (XOR of P and Q).
You have to determine whether it is possible to convert array A to size 1, containing a single element equal to 0 after several splits and/or merges?

Examples: 

Input:  arr = [9, 17] 
Output: Yes 
Explanation: Following is one possible sequence of operations –   
1) Merge i.e 9 XOR 17 = 24    
2) Split 24 into two parts each of size 12   
3) Merge i.e 12 XOR 12 = 0    
As there is only 1 element i.e 0. So it is possible.

Input:  arr = [1] 
Output: No 
Explanation: There is no possible way to make it 0.
*************************************************************************************************************************************************************************/

// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function that finds if it is
// possible to make the array
// contain only 1 element i.e. 0
string solve(vector<int>& A)
{
	int i, ctr = 0;
	for (i = 0; i < A.size();
		i++) {

		// Check if element is odd
		if (A[i] % 2) {
			ctr++;
		}
	}

	// According to the logic
	// in above approach
	if (ctr % 2) {
		return "No";
	}
	else {
		return "Yes";
	}
}

// Driver code
int main()
{

	vector<int> arr = { 9, 17 };

	cout << solve(arr) << endl;
	return 0;
}

/***********************************************************************************************************************************************************************/
// C++ program to implement the approach
#include <bits/stdc++.h>
using namespace std;

int main()
{
int A[] = { 9, 17 };

// length of the array
int n = sizeof(A) / sizeof(A[0]);

// variable to store the value of XOR
int xor1 = 0;

// traversing the array
for (int i = 0; i < n; i++) {
	xor1 ^= A[i];
}

// checking if the value of XOR is even or odd
// if even printing YES else ONO
if (xor1 % 2 == 0) {
	cout << "Yes\n";
}
else {
	cout << "No\n";
}
}


