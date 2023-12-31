/*************************************************************************************************************************************************************************
Given an integer array of N integers, find sum of bit differences in all pairs that can be formed from array elements. Bit difference of a pair (x, y) is
count of different bits at same positions in binary representations of x and y.
For example, bit difference for 2 and 7 is 2. Binary representation of 2 is 010 and 7 is 111 (first and last bits differ in two numbers).

Note: (x, y) and (y, x) are considered two separate pairs.

Example 1:

Input: 
N = 2
arr[] = {1, 2}
Output: 4
Explanation: All pairs in array are (1, 1)
(1, 2), 2, 1), (2, 2)
Sum of bit differences = 0 + 2 + 2 + 0
                       = 4
Example 2:

Input:
N = 3 
arr[] = {1, 3, 5}
Output: 8
Explanation: 
All pairs in array are (1, 1), (1, 3),
(1, 5), (3, 1), (3, 3) (3, 5),(5, 1),
(5, 3), (5, 5)
Sum of bit differences =  0 + 1 + 1 +
                          1 + 0 + 2 +
                          1 + 2 + 0 
                       = 8
Your Task:  
You don't need to read input or print anything. Your task is to complete the function sumBitDifferences() which takes the array arr[] and n as inputs and returns
an integer denoting the answer.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 105
1 <= arr[i] <= 105
**************************************************************************************************************************************************************************/
https://www.youtube.com/watch?v=L_fIn5TM3mM

class Solution{
public:
	
	long long sumBitDifferences(int arr[], int n) {
	    long long ans=0;
	    
	    for(int i=0;i<32;i++)
	    {
	        long long  countonn=0, countoff=0;
	        for(int j=0;j<n;j++)
	        {
	            if((arr[j] & (1<<i)))
	            countonn++;
	            else
	            countoff++;
	        }
	        
	        ans+=countonn*(countoff)*2;
	        
	    }
	    
	    return ans;
	}
};
