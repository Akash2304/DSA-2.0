/************************************************************************************************************************************************************************
Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer in the array, return 0.

 

Example 1:

Input: nums = [21,4,7]
Output: 32
Explanation: 
21 has 4 divisors: 1, 3, 7, 21
4 has 3 divisors: 1, 2, 4
7 has 2 divisors: 1, 7
The answer is the sum of divisors of 21 only.
Example 2:

Input: nums = [21,21]
Output: 64
Example 3:

Input: nums = [1,2,3,4,5]
Output: 0
 

Constraints:

1 <= nums.length <= 104
1 <= nums[i] <= 105
***********************************************************************************************************************************************************************/

class Solution {
public:
    int sumOfAllDivisorsOfANum(int num) {
        int sum = 0;
        int count = 0;
        for(int i = 1; i * i <= num; i++) {
            if(num % i == 0) {
                sum += i;
                count++;
                if(i * i != num) {  // same value do baar add na ho isiliye  ye cond checkkkkk.....
                    sum += num / i;
                    count++;
                }
            }
            if(count > 4) break;
        }
        if(count == 4) return sum;
        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            ans += sumOfAllDivisorsOfANum(nums[i]);
        }
        return ans;
    }
};

/*************************************************************************************************************************************************************************/

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
         int i,j,k,sum=0;
        for(i=0;i<nums.size();i++)
        {   
            // bsum: bsum stores the sum of default divisors i.e. 1 and the number itself
            // t: used to count the number of divisors present 
            // n: used to store half of the number (no divisors will be present if the control exceeds n)
            // sn: used to store 1/4th of the number (or half of n)
            int bsum=1+nums[i], t=0, n=nums[i]/2, sn=n/2;

            //Calculating remaining divisors
            for(j=2;j<=n;j++)
            {  
                if(nums[i]%j==0){
                t++;
                bsum+=j;
                }
                //Condition t>2: If the total number of diviors exceeds 2 then number will be discarded, values of t and bsum will be initialized again
                //Condition t==0&&j>=sn: If 2 diviors are not found within the 1st half of the range, then 2 diviors wont be present in the 2nd half  
                if(t>2||(t==0&&j>=sn))
                break;
            }
            //Checking if the number of divisors obtained are exactly 2
            if(t==2)
                //Adding bsum into final sum, as bsum contains the soultion for 1 number but we are presented with an array of numbers
                    sum+=bsum;
        }
        return sum;
    }
};
