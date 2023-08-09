/*********************************************************************************************************************************************************************
You are given an integer array arr.

We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.

Return the largest number of chunks we can make to sort the array.

 

Example 1:

Input: arr = [5,4,3,2,1]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [5, 4], [3, 2, 1] will result in [4, 5, 1, 2, 3], which isn't sorted.
Example 2:

Input: arr = [2,1,3,4,4]
Output: 4
Explanation:
We can split into two chunks, such as [2, 1], [3, 4, 4].
However, splitting into [2, 1], [3], [4], [4] is the highest number of chunks possible.
 

Constraints:

1 <= arr.length <= 2000
0 <= arr[i] <= 108
**************************************************************************************************************************************************************************/

int maxChunksToSorted(vector<int>& v) 
    {
        vector<int> v1=v;
		
        sort(v1.begin(),v1.end());
		
        int n=v.size(),i,j,ans=0;
		//sum1 stores sum of original array while sum2 stores sum of sorted array
        long long sum1=0,sum2=0;
        for(i=0;i<n;i++)
        {
            sum1+=v[i];
            sum2+=v1[i];
            if(sum1==sum2)
                ans++;
        }
        return ans;
    }

/***********************************************************************************************************************************************************************/
class Solution {
public:
   int maxChunksToSorted(vector<int>& arr) {
       
        int n = arr.size();
        vector<int> rightmin(n+1,INT_MAX);
        for(int i=n-1;i>=0;i--)
        {
            rightmin[i] = min(arr[i],rightmin[i+1]);
        }
        int count = 0;
        int leftmax = INT_MIN;
        for(int i=0;i<n;i++)
        {
            leftmax = max(leftmax,arr[i]);
            if(leftmax <= rightmin[i+1])
            {
                count++;
            }
        }
        return count;
        
    }
};

/*************************************************************************************************************************************************************************/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
             vector<int>rightmin(n);
             vector<int>leftmax(n);
             // calculate maximum elements from left side
             leftmax[0]=arr[0];
             for(int i=1;i<n;i++)
             {
                leftmax[i]=max(leftmax[i-1],arr[i]);
             }
            // calculate minimum elements from right side
          rightmin[n-1]=arr[n-1];
          for(int i=n-2;i>=0;i--)
          {
              rightmin[i]=min(arr[i],rightmin[i+1]);
          }
         /*atleast there will be one chunk 
          the total array can be considered as a chunk */
          int chunks=1;
          for(int i=0;i<n-1;i++)
          {
                 if(leftmax[i]<=rightmin[i+1]) chunks++;
          }
          return chunks;

    }
};
