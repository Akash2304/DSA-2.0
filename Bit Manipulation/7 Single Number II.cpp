/**************************************************************************************************************************************************************************
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99
 

Constraints:

1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each element in nums appears exactly three times except for one element which appears once.
***********************************************************************************************************************************************************************/


WE ALSO USE SORTING AND OTHER WAY IS USING HASHMAP.........

Approach
It first initializes two variables:n to store the size of the input vector nums, and res to store the final result.

It then enters a loop that iterates 32 times. This loop is used to consider each bit position in the numbers.

Inside the loop, a variable cnt is initialized to keep track of the number of occurrences of the current bit position.

Another loop is used to iterate over each element nums[j] in the input vector.

For each element, the code checks if the i-th bit (where i is the current bit position) is set by performing a bitwise right shift nums[j] >> i followed by a
bitwise AND operation with 1 (& 1). If the result is non-zero, it means the i-th bit is set in nums[j], and the cnt variable is incremented.

After counting the number of occurrences of the current bit position across all elements, the code checks if cnt is not divisible by 3 cnt % 3 != 0. If this 
condition is true, it means the bit position appears an odd number of times, indicating that the single number has a set bit at that position.

In such a case, the code sets the i-th bit of the result (res) by performing a bitwise OR operation | with 1 left-shifted by i 1 << i. This operation sets the i-th
bit of res to 1.

After completing the loop for all bit positions, the code returns the final result res.

FOR BETTER UNDERSTAING WATCH VEDIO ON YOUTUBE 
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int n=nums.size();

        int res=0;

        for(int i=0;i<32;i++){
        //count the number of occurrences of the current bit position
            int cnt=0;
            for(int j=0;j<n;j++){
                if((nums[j]>>i) & 1){
                    cnt++;
                }
            }
            if(cnt%3 !=0)
            res=res|(1<<i);

        }
        return res;
    }
};



/***************************************************************************************************************************************************************************/

You may encounter where every digit appears 2 times except one then in that cases k=2 and p=1 ->k is 2, then m = 1, we need only one 32-bit integer (x1) as the counter.
And 2^m = k so we do not even need a mask.

here (k = 3, p = 1) k is 3, then m = 2, we need two 32-bit integers(x2, x1) as the counter. And 2^m > k so we do need a mask. Write k in its binary form: k = '11', 
then k1 = 1, k2 = 1, so we have mask = ~(x1 & x2).

If k = 5, p = 3
k is 5, then m = 3, we need three 32-bit integers(x3, x2, x1) as the counter. And 2^m > k so we need a mask. Write k in its binary form: k = '101', 
  then k1 = 1, k2 = 0, k3 = 1, so we have mask = ~(x1 & ~x2 & x3).

If you like the Solution then upvote me.

Case->(k = 3, p = 1)

Code
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int x1=0,x2=0,mask=0;
        for(auto i:nums)
        {
            x2^=x1&i;
            x1^=i;
            mask=~(x2&x1);
            x2&=mask;
            x1&=mask;
        }
        return x1;
    }
};
