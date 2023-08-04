/***************************************************************************************************************************************************************************
Given an integer num, return a string representing its hexadecimal representation. For negative integers, two’s complement method is used.

All the letters in the answer string should be lowercase characters, and there should not be any leading zeros in the answer except for the zero itself.

Note: You are not allowed to use any built-in library method to directly solve this problem.

 

Example 1:

Input: num = 26
Output: "1a"
Example 2:

Input: num = -1
Output: "ffffffff"
 

Constraints:

-231 <= num <= 231 - 1
**************************************************************************************************************************************************************************/

class Solution {
public:
    string toHex(int num) {
        unsigned int ourNum = num;
        // Implicitly cast negative numbers.
        // -1 turns to the maximum number representable
        // as an unsigned int.
        
        string str; // Our result
        char ourArray[17] = "0123456789abcdef"; // We will pick from this set of characters

        // While our number exists, convert it into base 16.
        // We are going from left to right, so we need to reverse our result
        // when we return it.
        do {
            str += ourArray[ourNum % 16];
            ourNum /= 16;
        } while (ourNum); 

        return {str.rbegin(), str.rend()};
    }
};
