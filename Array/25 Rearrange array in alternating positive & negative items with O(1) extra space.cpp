/************************************************************************************************************************************************************************
Given an array of positive and negative numbers, arrange them in an alternate fashion such that every positive number is followed by a 
negative and vice-versa maintaining the order of appearance. The number of positive and negative numbers need not be equal. If there are more positive 
numbers they appear at the end of the array. If there are more negative numbers, they too appear at the end of the array.

Examples: 

Input:  arr[] = {1, 2, 3, -4, -1, 4}
Output: arr[] = {-4, 1, -1, 2, 3, 4}

Input:  arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}
Output: arr[] = {-5, 5, -2, 2, -8, 4, 7, 1, 8, 0}

*******************************************************************************************************************************************************************/
Naive Approach: 
The above problem can be easily solved if O(n) extra space is allowed.

We can store the positive values and negative values in two separate data structures.
We will start filling the original array with alternating negative and positive values in the same order 
in which it appears in the original array.
It becomes interesting due to the limitations that O(1) extra space and order of appearances. 

Optimal Approach:
The idea is to process the array from left to right. While processing, find the first out-of-place element in the remaining unprocessed array. 
An element is out of place if it is negative and at odd index (0-based index), or if it is positive and at even index (0-based index).
Once we find an out-of-place element, we find the first element after it with an opposite sign. We right rotate the subarray between 
these two elements (including these two).

Illustration:

Let the array be arr[] = { -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 }

First iteration: 

{ -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 } , -2 appears on odd index position and is out of place.
We will look for the first element that appears with an opposite sign
{ -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 } => perform rotation of subarray between this two elements
{ -5, 5, -2, 2, 4, 7, 1, 8, 0, -8 }
Second iteration: 

{ -5, 5, -2, 2, 4, 7, 1, 8, 0, -8 } , 4 is out of place.
{ -5, 5, -2, 2, 4, 7, 1, 8, 0, -8 } =>-8 is of different sign 
{ -5, 5, -2, 2, -8, 4, 7, 1, 8, 0 } => after performing right rotation between 4 to -8
Algorithm:
We will maintain a variable to mark if the element is in its correct position or not. Let the variable be outofplace. Initially, it is -1.

We will iterate over the array
If outofplace is -1, we will check if the current index is out of place.
If the current index is out of place we will update the outofplace with the index value.
Else we will keep the value as it is.
If the outofplace is not -1, we will search for the next index which has a different sign than that of the value that is present in outofplace position.
Now we will pass this two positions to right rotate our array.
Update the value of outofplace by 2 unit.
Following is the implementation of the above idea.  


/*  C++ program to rearrange
   positive and negative integers
   in alternate fashion while keeping
   the order of positive and negative numbers. */
#include <assert.h>
#include <iostream>
using namespace std;
 
// Utility function to right rotate all elements between
// [outofplace, cur]
void rightrotate(int arr[], int n, int outofplace, int cur)
{
    char tmp = arr[cur];
    for (int i = cur; i > outofplace; i--)
        arr[i] = arr[i - 1];
    arr[outofplace] = tmp;
}
 
void rearrange(int arr[], int n)
{
    int outofplace = -1;
 
    for (int index = 0; index < n; index++) {
        if (outofplace >= 0) {
            // find the item which must be moved into the
            // out-of-place entry if out-of-place entry is
            // positive and current entry is negative OR if
            // out-of-place entry is negative and current
            // entry is positive then right rotate
            //
            // [...-3, -4, -5, 6...] -->   [...6, -3, -4,
            // -5...]
            //      ^                          ^
            //      |                          |
            //     outofplace      -->      outofplace
            //
            if (((arr[index] >= 0) && (arr[outofplace] < 0))
                || ((arr[index] < 0)
                    && (arr[outofplace] >= 0))) {
                rightrotate(arr, n, outofplace, index);
 
                // the new out-of-place entry is now 2 steps
                // ahead
                if (index - outofplace >= 2)
                    outofplace = outofplace + 2;
                else
                    outofplace = -1;
            }
        }
 
        // if no entry has been flagged out-of-place
        if (outofplace == -1) {
            // check if current entry is out-of-place
            if (((arr[index] >= 0) && (!(index & 0x01)))
                || ((arr[index] < 0) && (index & 0x01))) {
                outofplace = index;
            }
        }
    }
}
 
// A utility function to print an array 'arr[]' of size 'n'
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
// Driver code
int main()
{
 
    int arr[] = { -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Given array is \n";
    printArray(arr, n);
 
    rearrange(arr, n);
 
    cout << "Rearranged array is \n";
    printArray(arr, n);
 
    return 0;
}
Output
Given array is 
-5 -2 5 2 4 7 1 8 0 -8 
Rearranged array is 
-5 5 -2 2 -8 4 7 1 8 0 
Time Complexity: O(N*N), as we are using a loop to traverse N times and calling function to right rotate each time which will cost O (N).
Auxiliary Space: O(1).
/************************************************************************************************************************************************************************/

  better time complexity of O(nlogn) with constant space. The code is explained by the help of the comments at the end of the code: 
#include<bits/stdc++.h>
using namespace std;

void altNegPos(vector<int>& v, int n){
    sort(v.begin(), v.end());
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(v[i]>=0)
            break;
        cnt++;
    }
    int i=1;
    int t = cnt;
    if(cnt%2){
        while(i<cnt){
            swap(v[i],v[t+i]);
            i+=2;
        }
    }
    else{
        while(i<cnt){
            swap(v[i],v[t]);
            i+=2;t+=2;
        }
    }
}

int main(){
    vector<int>v = {-5, -2, 5, 2, 4, -8, -9, -3, 7};
    int n = v.size();
    altNegPos(v, n);
    for(auto val: v)
        cout<<val<<" ";
    return 0;
}

        //T.C = O(nlogn)
        //S.C = O(1)

/*
The intution behind this approach is we have some negative integers say k, and >=(k-1) positive integers,
We have to rearrange the elements such that the negative and positive elements occur are placed at alternating positions.
So we sort the array in non descending order and count the number of negative numbers, Say k.
If k is even we start swapping every alternating element: starting from element at index 1 and element at index k.
As the kth negative number (at index k-1 before the swap) will be swapped so it won't be adjacent to the swapped first negative element
(at index 1 before the swap now at index k).
Else if k is odd we start swapping every alternating element: starting from element at index i=1 and element at index k+i.
As the kth negative number (at index k-1 before the swap) will not be swapped so it won't be adjacent to the swapped first negative element
(at index 1 before the swap now at index k+1).
*/
