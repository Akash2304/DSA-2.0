/*********************************************************************************************************************************************************************
A positive integer is magical if it is divisible by either a or b.

Given the three integers n, a, and b, return the nth magical number. Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: n = 1, a = 2, b = 3
Output: 2
Example 2:

Input: n = 4, a = 2, b = 3
Output: 6
 

Constraints:

1 <= n <= 109
2 <= a, b <= 4 * 104
*******************************************************************************************************************************************************************/

class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long A=a,B=b;
        long mod=(long)(pow(10,9)+7);
        
        long left=min(A,B);
        long right=(long)n*min(A,B);
         long lcm=(A*B)/(__gcd(A,B));
        
        while(left<right)
        {
            
            long mid=left+(right-left)/2; // for prevent overflow condition if we have high right value and (left+right) will getoverflow condition that why we do this
           
            //(mid/A)+(mid/B)-(mid/lcm) ..mid/a gives no.before n divided by a same for mid/b,and that mid/lcm is for common no.which are divisible by a,b
          //after minus we get thier count
            if((mid/A)+(mid/B)-(mid/lcm) < (long)n)
                left=mid+1;
            else
                right=mid;
        }
        return (int)(left%mod);
    }
};
