/**************************************************************************************************************************************************************************
Given the API rand7() that generates a uniform random integer in the range [1, 7], write a function rand10() that generates a uniform random integer in the range [1, 10]. 
You can only call the API rand7(), and you shouldn't call any other API. Please do not use a language's built-in random API.

Each test case will have one internal argument n, the number of times that your implemented function rand10() will be called while testing. Note that this is not an argument
passed to rand10().

 

Example 1:

Input: n = 1
Output: [2]
Example 2:

Input: n = 2
Output: [2,8]
Example 3:

Input: n = 3
Output: [3,8,10]
 

Constraints:

1 <= n <= 105
 

Follow up:

What is the expected value for the number of calls to rand7() function?
Could you minimize the number of calls to rand7()?
**************************************************************************************************************************************************************************/

// problem is like throwing a dice having 7 outcome
    // we want a total of 10 outcome
    // so we throw two time=> total outcome=>7*7=49
    // map first 40 outcome to 1 to 10
    // we can also map first 10,20,30 outcome to 1 to 10 but to get outcome in range (1 to 20) we may     // need to throw much more time
    // getting a number in range 1to40 is 40/49
    // if we take first 20 outcome ...then probability of getting a number in range 1to20 is 20/49
	
	class Solution {
public:
    int rand10() {
        int num=40;
        while(num>=40){
            num=7*(rand7()-1)+rand7()-1;
        }
        
        num=num%10+1;
        return num;
    }
};
