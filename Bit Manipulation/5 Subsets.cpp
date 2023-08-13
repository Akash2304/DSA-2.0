/***************************************************************************************************************************************************************************
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
**************************************************************************************************************************************************************************/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        // (1<<n) =2^n
        for(int i=0; i < (1<<n); i++)
        {
            vector<int> subset;
            for(int j=0;j<n;j++)
            {
                // if the ith bit is set 
                if( (i & (1<<j)) )
                {
                    subset.push_back(nums[j]);
                }
            }
            ans.push_back(subset);
        }
        return ans;
    }
};

/************************************************************************************************************************************************************************/
Approach 1: Recusion
Code
class Solution {
public:
    
    void sub(int i,vector<int> &nums, vector<int> &temp,vector<vector<int>>&ans)
    {
        if(i>=nums.size())
        {
            ans.push_back(temp);
            return;
        }
        
        // pick
        temp.push_back(nums[i]);
        sub(nums, i+1, temp,ans);

        // not pick
        temp.pop_back();
        //this pop is necessary because we are passing temp by reference. 
        //if anything will be picked in above call it will remain in temp if we will not pop it.
        sub(nums, i+1, temp,ans);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;       
        sub(nums, 0, temp,ans); 
        return ans;
    }
};
Complexity
Time complexity:O(N*(2^N))
Space complexity: O(N) + O(N*(2^N)) = O(N*(2^N))
maximum depth of recusion tree will be N hence recursion stack space is O(N).
we have to store 2^N subsets in ans each of size O(N)
Video Solution by Striver :
https://youtu.be/AxNNVECce8c


Approach 2: Bit Manipulation (Power Set)
Code
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        // (1<<n) =2^n
        for(int subset_num=0; subset_num < (1<<n); subset_num++)
        {
            vector<int> subset;
            for(int i=0;i<n;i++)
            {
                // if the ith bit is set 
                if( (subset_num & (1<<i)) )
                {
                    subset.push_back(nums[i]);
                }
            }
            ans.push_back(subset);
        }
        return ans;
    }
};
Complexity
Time complexity: O(N*(2^N))
2^N subsets will be generated.
for each subset number we check N bits (set or not)
Space complexity: O(N*(2^N))
we have to store 2^N subsets in ans each of size O(N)
Video Solution by Striver :
https://youtu.be/b7AYbpM5YrE


Approach 3: Iterative
Code
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> output;
        int n=nums.size();

        output.push_back({});
        // initialising the output with an empty subset

        for(int i=0; i<n;i++)
        {
            // for every index i in nums make a copy of all the existing rows in output.
            // Then add the ith num to the copy and then push it in output 
            int size=output.size();
            for(int j=0;j<size;j++)
            {
                vector<int> newRow=output[j]; //O(N)
                
                newRow.push_back(nums[i]);
                output.push_back(newRow);
            }
        }
        return output;
    }
};
Complexity
Time complexity: O(N*(2^N))
2^N subsets will be generated.
while generating each subset we have to copy one of the previous subset:
Space complexity: O(N*(2^N))
