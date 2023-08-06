/***********************************************************************************************************************************************************************
Given a NxN 2-D matrix, the task to find the sum of all the submatrices.

Examples: 

Input :  arr[] = {{1, 1},
                  {1, 1}};
Output : 16
Explanation: 
Number of sub-matrices with 1 elements = 4
Number of sub-matrices with 2 elements = 4
Number of sub-matrices with 3 elements = 0
Number of sub-matrices with 4 elements = 1

Since all the entries are 1, the sum becomes
sum = 1 * 4 + 2 * 4 + 3 * 0 + 4 * 1 = 16

Input : arr[] = {{1, 2, 3},
                 {4, 5, 6},
                 {7, 8, 9}}
Output : 500
**************************************************************************************************************************************************************************/
Simple Solution: A naive solution is to generate all the possible submatrices and sum up all of them. 
The time complexity of this approach will be O(n6).

Efficient Solution : For each element of the matrix, let us try to find the number of sub-matrices, the element will lie in. 
This can be done in O(1) time. Let us suppose the index of an element be (X, Y) in 0 based indexing, then the number of submatrices (Sx, y)
for this element will be given by the formula Sx, y = (X + 1) * (Y + 1) * (N – X) * (N – Y). This formula works, because we just have to choose
two different positions on the matrix that will create a submatrix that envelopes the element. Thus, for each element, ‘sum’ can be updated as sum += (Sx, y) * Arrx, y.

Below is the implementation of the above approach: 

Here we need to try to solve this question in the Reverse lookup  Technique:

1) For a particular element what are the possible submatrices where this element will be included.

2) When we get the number of possible submatrices then we can count the contribution of that particular element by doing ( a[i]* total number of
submatrices where this will be included) where a[i] = current element

3) Now Question comes how to find the number of possible submatrices for a particular element.

 [[1 2 3]

  [4 5 6]

  [7 8 9]]

So let’s consider the current element as 5 , so for 5 there are (X+1)*(Y+1) choices where co-ordinates of submatrix starting point can lie,(Top Left)

Similarly, there will be (N-X)*(N-Y) choices where the end  co-ordinates of that submatrix can lie (Bottom Right)

 Number of choices for Top Left = (X+1)*(Y+1)

Number of choices for Bottom Right = (N-X)*(N-Y)

Total number of choices for the current element to be included in the submatrix will be : (X+1)*(Y+1) * (N-X)*(N-Y)

Contribution of the current element which can be included in all the possible submatrices will be  = arr[X][Y] * (X+1)*(Y+1) * (N-X)*(N-Y)

where X and Y  are index of the submatrices.


// C++ program to find the sum of all
// possible submatrices of a given Matrix
 
#include <iostream>
#define n 3
using namespace std;
 
// Function to find the sum of all
// possible submatrices of a given Matrix
int matrixSum(int arr[][n])
{
    // Variable to store
    // the required sum
    int sum = 0;
 
    // Nested loop to find the number
    // of submatrices, each number belongs to
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
 
            // Number of ways to choose
            // from top-left elements
            int top_left = (i + 1) * (j + 1);
 
            // Number of ways to choose
            // from bottom-right elements
            int bottom_right = (n - i) * (n - j);
            sum += (top_left * bottom_right * arr[i][j]);
        }
 
    return sum;
}
 
// Driver Code
int main()
{
    int arr[][n] = { { 1, 1, 1 },
                     { 1, 1, 1 },
                     { 1, 1, 1 } };
 
    cout << matrixSum(arr);
 
    return 0;
}
