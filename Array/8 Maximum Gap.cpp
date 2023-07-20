/**********************************************************************************************************************************************************************
Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.

You must write an algorithm that runs in linear time and uses linear extra space.

 

Example 1:

Input: nums = [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
Example 2:

Input: nums = [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109
**************************************************************************************************************************************************************************/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        const int size_num = nums.size();
    if (size_num < 2) return 0;
    int maxV = *max_element(nums.begin(), nums.end());
    int minV = *min_element(nums.begin(), nums.end());
    if (maxV == minV) return 0;
    double range = (maxV - minV) / double(size_num - 1);
    vector<int> max_b(size_num, INT_MIN), min_b(size_num, INT_MAX);
    for (int i = 0; i < size_num; i++) {

        // yaha element sort hoke arrange ho rhe dono arrays mai 
        int index = (nums[i] - minV) / range;
        max_b[index] = max(max_b[index], nums[i]);
        min_b[index] = min(min_b[index], nums[i]);
    }
    int max_g = (int)range,  start = max_b[0];
    for (int i = 1; i < size_num; i++) {
        if (min_b[i] == INT_MAX) continue;
        max_g = max(max_g, min_b[i] - start);
        start = max_b[i];
    }
    return max_g;
    }
};
