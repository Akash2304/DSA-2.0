/**********************************************************************************************************************************************************************
Given an array, return the length of the longest subarray of non-negative integers

Examples : 

Input : {2, 3, 4, -1, -2, 1, 5, 6, 3}
Output : 4
Explanation: The subarray [ 1, 5, 6, 3] has length 4 and contains no negative integers

Input : {1, 0, 0, 1, -1, -1, 0, 0, 1, 0}
Output : 4
Explanation: Subarrays [1, 0, 0, 1] and [0, 0, 1, 0] have equal lengths but sum of first one is greater so that will be the output.
***********************************************************************************************************************************************************************/

// C++ program to find length of the longest
// subarray with non-negative numbers.
#include<iostream>
using namespace std;

// Function that returns the longest
// subarray of non-negative integers
int longestSubarry(int *arr, int n)
{
	// Initialize result
	int res = 0;
	
	// Traverse array
	for (int i = 0; i < n; i++)
	{
		// Count of current
		// non-negative integers
		int curr_count = 0;
		
		while (i < n && arr[i] >= 0)
		{
			curr_count++;
			i++;
		}
	
		// Update result if required.
		res = max(res, curr_count);
	}
	
	return res;
}

// Driver code
int main()
{
	int arr[] = {1, 0, 4, 0, 1, -1, -1,
						0, 0, 1, 0};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << longestSubarry(arr, n);
	return 0;
}
