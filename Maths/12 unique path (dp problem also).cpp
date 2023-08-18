/*************************************************************************************************************************************************************************
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner 
(i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
 

Constraints:

1 <= m, n <= 100
************************************************************************************************************************************************************************/

FOR BETTER UNDERSTANDING VISIT : https://www.youtube.com/watch?v=t_f0nwwdg5o....



TLE.....
class Solution {
public:
    
    int countpath(int i,int j,int m,int n){
        if((i==(m-1)) && (j==(n-1)))
            return 1;
        
        if(i>=m || j>=n)
            return 0;
        
        else
            return countpath(i+1,j,m,n)+countpath(i,j+1,m,n);
        
    }
    int uniquePaths(int m, int n) {
        int i=0,j=0;
        return countpath(i,j,m,n);
        
    }
};
exponential time complexity...
/***********************************************************************************************************************************************************************/
class Solution {
public:
    
    int countpath(int i,int j,int m,int n,vector<vector<int>>&dp){
        if((i==(m-1)) && (j==(n-1)))
            return 1;
        
        if(i>=m || j>=n)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        else
            return dp[i][j]=countpath(i+1,j,m,n,dp)+countpath(i,j+1,m,n,dp);
        
    }
    int uniquePaths(int m, int n) {
        int i=0,j=0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return countpath(i,j,m,n,dp);
        
    }
};

O(m*n)...
/**********************************************************************************************************************************************************************/
Complexity
Time complexity:$$O(min(m-1, n-1))$$
Space complexity:$$O(1)$$
Code
// method : combinatorics
class Solution {
    public:
    int uniquePaths(int m, int n) {
        int N = m + n - 2; // m-1 + n-1 =m+n-2
        int r = (m-1 < n-1) ? m-1 : n-1;
        double res = 1;
        for(int i = 1; i <= r; i++) {
            res = res * (N - r + i)/i;
        }
        return (int)res;
    }
};
