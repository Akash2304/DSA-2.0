/************************************************************************************************************************************************************************
Given an integer array nums with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must 
exist in the array.

Implement the Solution class:

Solution(int[] nums) Initializes the object with the array nums.
int pick(int target) Picks a random index i from nums where nums[i] == target. If there are multiple valid i's, then each index should have an equal probability of returning.
 

Example 1:

Input
["Solution", "pick", "pick", "pick"]
[[[1, 2, 3, 3, 3]], [3], [1], [3]]
Output
[null, 4, 0, 2]

Explanation
Solution solution = new Solution([1, 2, 3, 3, 3]);
solution.pick(3); // It should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
solution.pick(1); // It should return 0. Since in the array only nums[0] is equal to 1.
solution.pick(3); // It should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
 

Constraints:

1 <= nums.length <= 2 * 104
-231 <= nums[i] <= 231 - 1
target is an integer from nums.
At most 104 calls will be made to pick.
****************************************************************************************************************************************************************************/
rand() function in c++ is used to generate random numbers in a code. rand function in c++ returns any integer ranging from (o to rand_max), as defined by the user. 
this function is defined in the header file "cstdlib" in C++.

  How does rand() in C++ Work?
rand() function in C++ is used to generate random numbers for a given range in our code. For a computer system, it is not possible to generate any random number because 
it is a machine, and it works on any task based on 0 and 1 so it can not sense randomness. Hence, a thing called PRNG (Pseudo Random Number Generator) that generates 
a sequence of random numbers is used in C++. This Pseudo-Random Number Generator is capable of sensing randomness in a program. Rand_max is a constant whose value is 
set to 32767, found in the header file <cstdlib>.




class Solution {
public:
    unordered_map<int,vector<int>> m;
    Solution(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int x=m[target].size();

        x=rand()%x;  //here rand() give any random no.and when we mod it x we get diff index ....

        return m[target][x];
    }
};
/***********************************************************************************************************************************************************************/

  class Solution {

    unordered_map<int, vector<int>> m;
public:
    Solution(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
            m[nums[i]].push_back(i);
    }
    
    int pick(int target) {
        auto picked = m[target];
        int n = picked.size();
        return picked[rand()%n];
    }
};

/**********************************************************************************************************************************************************************/
class Solution {
vector<int> _nums;
public:
Solution(vector<int> nums) {
    _nums = nums;
}

int pick(int target) {
    int n = 0, ans = -1;
    for(int i = 0 ; i < _nums.size(); i++){
        if(_nums[i] != target) continue;
        if(n == 0){ans = i; n++;}
        else{
            n++;
            if(rand() % n == 0){ans = i;}// with prob 1/(n+1) to replace the previous index
        }
    }
    return ans;
}
};
