/************************************************************************************************************************************************************************
Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

 

Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100
 

Follow up: Could you find an O(n + m) solution?
****************************************************************************************************************************************************************************/
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        int i=m-1;
        int j=0;
		// to start from the grid[m-1][0] position
        int count=0;
        
        while(i>=0 && i<m && j>=0 && j<n){
            if(grid[i][j] < 0){
                count = count + (n-j); //when the first occurrence of a number in a row is -ve, all following numbers will be -ve. So, add their count.
                i=i-1; //then move to the above row
            }
            else{
                j=j+1; //else move to the right (i.e. to the next column)
            }
                
        }       
        
        return count;
    }
};
