/**************************************************************************************************************************************************************************
Given two arrays of integers with equal lengths, return the maximum value of:

|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|

where the maximum is taken over all 0 <= i, j < arr1.length.

 

Example 1:

Input: arr1 = [1,2,3,4], arr2 = [-1,4,5,6]
Output: 13
Example 2:

Input: arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4]
Output: 20
 

Constraints:

2 <= arr1.length == arr2.length <= 40000
-10^6 <= arr1[i], arr2[i] <= 10^6
**************************************************************************************************************************************************************************/

BEST THING TO IN ABSOLUTE TYPE PROBLEMS JUST OPEN THE EXPRESSION AND MAKE THE CASES AND EVALUATE IT .........

class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int temp1, temp2, temp3, temp4;
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN, max4 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX, min4 = INT_MAX;
        for (int i = 0; i < arr1.size(); i++)
        {
            temp1 = arr1[i] + arr2[i] + i;
            temp2 = arr1[i] + arr2[i] - i;
            temp3 = arr1[i] - arr2[i] + i;
            temp4 = arr1[i] - arr2[i] - i;
            max1 = max(max1, temp1);
            min1 = min(min1, temp1);
            max2 = max(max2, temp2);
            min2 = min(min2, temp2);
            max3 = max(max3, temp3);
            min3 = min(min3, temp3);
            max4 = max(max4, temp4);
            min4 = min(min4, temp4);

        }
        return max(max((max1 - min1), (max2 - min2)), max((max3 - min3), (max4 - min4)));
    }
};
