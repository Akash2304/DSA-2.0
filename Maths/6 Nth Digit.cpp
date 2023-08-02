/************************************************************************************************************************************************************************
Given an integer n, return the nth digit of the infinite integer sequence [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].

 

Example 1:

Input: n = 3
Output: 3
Example 2:

Input: n = 11
Output: 0
Explanation: The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
 

Constraints:

1 <= n <= 231 - 1
***************************************************************************************************************************************************************************/

class Solution {
public:
    int findNthDigit(int n) {
        long long Length = 1, Number = 9, Used = 1;
		/*
				"Length" stores the length of the number,
			for example: length of 9 is 1, 23 is 2, 234 is 3.
				"Number" is used as a template to find the
			number of digits you need to write all Length
			digit words. The formula is Length * Number.
				"Used" stores the numbers written plus one,
			for example: if Used == 5, we have written 4 
			numbers.
		*/
        while (n > Length * Number)
        {
            n -= Length * Number;
            Number *= 10;
            Used *=10;
            Length++;
			/*
					Writing numbers...
			*/
        }
        --n; 
        Used += n / Length; // Write down all the digits left...
        string Template = to_string(Used);
        return Template[n % Length] - '0'; // And the solution.
		// Cheers!
    }
};
