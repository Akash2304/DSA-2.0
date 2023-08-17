/**************************************************************************************************************************************************************************
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

 

Example 1:


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
Example 2:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
mat[i][j] is either 0 or 1.
There is at least one 0 in mat.
************************************************************************************************************************************************************************/

class Solution {
public:
    
    
    bool checkvalid(int i,int j,int m,int n)
    {
        if(i<0 || j<0 || i>=m || j>=n)
            return false;
        return true;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>>q;
        vector<vector<int>>v(mat.size(),vector<int>(mat[0].size(),-1));
        
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==0)
                {
                    v[i][j]=0;
                    q.push({i,j});
                }
            }
          }
        int m=mat.size();
        int n=mat[0].size();
        while(!(q.empty()))
        {
            int i=q.front().first;
            int j=q.front().second;
            
            //we have to check for all four neigbour left,right,top,bottom...
            if(checkvalid(i+1,j,m,n) && v[i+1][j]==-1){
                v[i+1][j]=v[i][j]+1;
                q.push({i+1,j});
            }
            if(checkvalid(i-1,j,m,n) && v[i-1][j]==-1){
                v[i-1][j]=v[i][j]+1;
                q.push({i-1,j});
            }
            if(checkvalid(i,j+1,m,n) && v[i][j+1]==-1){
                v[i][j+1]=v[i][j]+1;
                q.push({i,j+1});
            }
            if(checkvalid(i,j-1,m,n) && v[i][j-1]==-1){
                v[i][j-1]=v[i][j]+1;
                q.push({i,j-1});
            }
            
        q.pop();
            
        }
        
        return v;
    }
};
