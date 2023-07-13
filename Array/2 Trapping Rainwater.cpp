/***************************************************************************************************************************************************************************

*************************************************************************************************************************************************************************/

TLE
class Solution {
public:
    int trap(vector<int>& height) {

        int maxs=height[0];
        int ans=0;
        int maxend=INT_MIN;
       

        for(int i=1;i<height.size()-1;i++)
        {

           
            maxend=*max_element(height.begin()+i+1,height.end());

          

              

                 
                 int val=min(maxs,maxend);

                 if(val-height[i] >0)
                 ans+=val-height[i];

                 if(height[i]>maxs)
                 maxs=height[i];
             
        }
        return ans;
        
    }
};

/**************************************************************************************************************************************************************************/
optimal solution
class Solution {
public:
    int trap(vector<int>& height) {
        int left=0; int right=height.size()-1;
        int res=0;
        int maxleft=0, maxright=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=maxleft) maxleft=height[left];
                else res+=maxleft-height[left];
                left++;
            }
            else{
                if(height[right]>=maxright) maxright= height[right];
                else res+=maxright-height[right];
                right--;
            }
        }
        return res;
    }
};
