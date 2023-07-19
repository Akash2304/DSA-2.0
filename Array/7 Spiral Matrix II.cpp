/*************************************************************************************************************************************************************************
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

 

Example 1:


Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
Example 2:

Input: n = 1
Output: [[1]]
 

Constraints:

1 <= n <= 20
*****************************************************************************************************************************************************************************/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
         int r1 = 0, r2 = n-1;
        int c1 = 0, c2 = n-1;
        int val = 0;
		
		// result matrix
        vector<vector<int>> v(n, vector<int> (n));
        while(r1 <= r2 && c1 <= c2)
        {
            // left to right (row will be fixed)
            for(int i = c1; i <= c2; ++i)
                v[r1][i] = ++val;
				
				// move down(col will be fixed)
            for(int i = r1+1; i <= r2; ++i)
                v[i][c2] = ++val;
				
            // move right to left
            // move  up
            if(r1 < r2 && c1 < c2)
            {
                // move right to left (row will be fixed)
                for(int i = c2-1; i>c1; --i)
                    v[r2][i] = ++val;
					
					// move up (col will be fixed)
					for(int i = r2; i>r1; --i) 
                    v[i][c1] = ++val;
            }
            ++r1;
            --r2;
            ++c1;
            --c2;
        }
        return v;
    }
};
