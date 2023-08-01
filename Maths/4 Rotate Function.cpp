/****************************************************************************************************************************************************************************
You are given an integer array nums of length n.

Assume arrk to be an array obtained by rotating nums by k positions clock-wise. We define the rotation function F on nums as follow:

F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1].
Return the maximum value of F(0), F(1), ..., F(n-1).

The test cases are generated so that the answer fits in a 32-bit integer.

 

Example 1:

Input: nums = [4,3,2,6]
Output: 26
Explanation:
F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
Example 2:

Input: nums = [100]
Output: 0
 

Constraints:

n == nums.length
1 <= n <= 105
-100 <= nums[i] <= 100
***************************************************************************************************************************************************************************/

Intuition
If you carefully observe the steps involved in calculating sum of rotated array,
for ith rotation, you will notice that
for sum calculated at rotation-(i-1) (it is called as pre), we are adding sum of array elements to it(sum) & subtracting (n*element of nums)

(element of nums) is element from its reversed array (rev)
For rotation-1, element to be subtracted is rev[0],
for rotation-2, element to be subtracted is rev[1]
ans so on

Approach
Let's take nums=[4,3,2,6]. So, rev=[6,2,3,4]

Initialize sum=15, res=25(for rotation-0), pre=25 (pre is sum of previous rotated array)
For 1st rotaion: temp = pre+sum-(4*6) = 25+15-24 = 16.
pre becomes 16
For 2nd rotation: temp = pre+sum-(4*2) = 16+15-8 = 23.
Update res=23
pre=23
For 3rd rotation: temp=pre+sum-(4*3) = 23+15-12 = 26.
Update res=26
Keep doing this, till rotation<=(n-1)
At the end, return res

;;;;;;;;;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=INT_MIN;
        int n=nums.size();
        
        int sum1=0,sum2=0;
        for(int i=0;i<n;i++)
        {
            sum1+=nums[i];
            sum2+=i*nums[i];
        }
        
        for(int i=n-1;i>=0;i--)
        {
             sum2=sum2-(nums[i]*(n-1))+(sum1-nums[i]);
             sum=max(sum2,sum);
        }

       
        return sum;
        
    }
};

/********************************************************************************************************************************************************************/
