/************************************************************************************************************************************************************************
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
 

Example 1:


Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true
Example 2:


Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= n, m <= 300
-109 <= matrix[i][j] <= 109
All the integers in each row are sorted in ascending order.
All the integers in each column are sorted in ascending order.
-109 <= target <= 109
***************************************************************************************************************************************************************************/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        

        int n=matrix.size();
        int m=matrix[0].size();

        int rowind=-2,colind=-2;

        for(int i=0;i<n;i++)
        {
            if(matrix[i][0]==target)
            return true;
            if(matrix[i][0]>target)
            {
                rowind=i-1;
                break;
            }
        }

        if(rowind==-2)
        rowind=n-1;

         for(int i=0;i<m;i++)
        {
            if(matrix[0][i]==target)
            return true;
            if(matrix[0][i]>target)
            {
                colind=i-1;
                break;
            }
        }
        if(colind==-2)
        colind=m-1;
             
             if(colind<0)
             colind=0;
             if(rowind<0)
             rowind=0;

        if(matrix[0][colind]>=matrix[rowind][0])
        {
            for(int j=colind;j>=0;j--)
            {
                for(int i=0;i<=rowind;i++)
                {
                    if(matrix[i][j]==target)
                    return true;
                }
            }
        }
        else{
             for(int i=rowind;i>=0;i--)
            {
                for(int j=0;j<=colind;j++)
                {
                    if(matrix[i][j]==target)
                    return true;
                }
            }
        }

        return false;

    }
};

/********************************************************************************************************************************************************************/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        

        int n=matrix.size();
        int m=matrix[0].size()-1;

       int row=0;
       while(row<n  && m>=0)
       {
           if(matrix[row][m]==target)
           return true;
           else if(matrix[row][m]<target)
           row++;
           else
           m--;
       }

       return false;
    }
};

/***********************************************************************************************************************************************************/
class Solution {
public:
    bool binarysearch(int x, vector<int> &a) {
        int l = 0, r = a.size() - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(a[mid] == x) {
                return true;
            }
            else if(a[mid] < x) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0; i<matrix.size(); i++) {
            if(binarysearch(target, matrix[i])) {
                return true;
            }
        }
        return false;
    }
};
