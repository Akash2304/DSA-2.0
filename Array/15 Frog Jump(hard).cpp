/*************************************************************************************************************************************************************************
A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone,
but it must not jump into the water.

Given a list of stones' positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone. Initially,
the frog is on the first stone and assumes the first jump must be 1 unit.

If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.

 

Example 1:

Input: stones = [0,1,3,5,6,8,12,17]
Output: true
Explanation: The frog can jump to the last stone by jumping 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 2 units to the 4th stone,
then 3 units to the 6th stone, 4 units to the 7th stone, and 5 units to the 8th stone.
Example 2:

Input: stones = [0,1,2,3,4,8,9,11]
Output: false
Explanation: There is no way to jump to the last stone as the gap between the 5th and 6th stone is too large.
 

Constraints:

2 <= stones.length <= 2000
0 <= stones[i] <= 231 - 1
stones[0] == 0
stones is sorted in a strictly increasing order.
**************************************************************************************************************************************************************************/
class Solution {
public:

// visit vedio on youtube and try to understand there https://youtu.be/1V8gRXh1qbU and do dry run this...... after that do analyse dp and recursion
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> map;
        int n = stones.size();
        
        for (int i = 0; i < n; i++) {
            map[stones[i]] = unordered_set<int>();
        }
        
        map[stones[0]].insert(0);
        
        for (int i = 0; i < n; i++) {
            int stone = stones[i];
            unordered_set<int>& set = map[stone];
            
            for (int val : set) {
                if (val - 1 > 0 && map.find(stone + val - 1) != map.end()) {
                    map[stone + val - 1].insert(val - 1);
                }
                if (map.find(stone + val) != map.end()) {
                    map[stone + val].insert(val);
                }
                if (map.find(stone + val + 1) != map.end()) {
                    map[stone + val + 1].insert(val + 1);
                }
            }
        }
        
        return !map[stones[n - 1]].empty();
    }
};
/*************************************************************************************************************************************************************************/

-> Approach 1 : Recursion (TLE)

  
class Solution {
public:
    bool canCross(vector<int>& stones) {
        if(stones[1]-stones[0]>1)
            return false;
        
        return func(0, 1, stones);
    }
    
    bool func(int i, int jumps, vector<int> &stones){
        if(i==stones.size()-1)
            return true;
            
        bool ans=false;
        for(int ind=i+1; ind<stones.size(); ind++){
            if(stones[ind]-stones[i]>jumps+1)
                break;
            for(int t=-1; t<2; t++){
                if(stones[ind]-stones[i]==jumps+t)
                    ans = func(ind, jumps+t, stones) || ans;
            }
        }
    
        return ans;
    }
};


-> Approach 2 : Memoisation (MLE)

  
class Solution {
public:
    bool canCross(vector<int>& stones) {
        if(stones[1]-stones[0]>1)
            return false;
        
        if(stones.size()==2)
            return (stones[1]-stones[0]==1);
        
        vector<vector<int>> dp(stones.size(), vector<int> (stones[stones.size()-1]-stones[0], -1));
        return func(0, 1, stones, dp);
    }
    
    bool func(int i, int jumps, vector<int> &stones, vector<vector<int>> &dp){
        if(i==stones.size()-1)
            return true;
            
        if(dp[i][jumps] != -1)
            return dp[i][jumps];
        
        bool ans=false;
        for(int ind=i+1; ind<stones.size(); ind++){
            if(stones[ind]-stones[i]>jumps+1)
                break;
            for(int t=-1; t<2; t++){
                if(stones[ind]-stones[i]==jumps+t)
                    ans = func(ind, jumps+t, stones, dp) || ans;
            }
        }
    
        return dp[i][jumps] = ans;
    }
};


-> Approach 3 : Tabulation using 2D vector (accepted)


class Solution {
public:
    bool canCross(vector<int>& stones) {
        int N = stones.size();
        vector<vector<bool>> dp(N, vector<bool> (N+1, false));
        dp[0][1] = true;
        
        for(int i = 1; i < N; ++i){
            for(int j = 0; j < i; ++j){
                int diff = stones[i] - stones[j];
                if(diff > N || !dp[j][diff]) 
                    continue;
                
                if(i == N - 1) 
                    return true;
                
                dp[i][diff] = true;
                if(diff - 1 >= 0) dp[i][diff - 1] = true;
                if(diff + 1 <= N) dp[i][diff + 1] = true;
            }
        }

        return false;
    }
};


-> Approach 4 : Tabulation using Map (Accepted)


class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int , unordered_set<int>> hashMap;    
        hashMap[stones[0] + 1] = {1};       
        for(int i = 1 ; i < stones.size() ; ++i){      
            int position = stones[i];               
            for(auto it : hashMap[position]){           
                hashMap[position + it].insert(it);      
                hashMap[position + it + 1].insert(it + 1);
                hashMap[position + it - 1].insert(it - 1);
            }
        }
        return hashMap[stones.back()].size() != 0;    
    }
};

-> Approach 5 : Tabulation + Binary Search (Accepted)


class Solution {
public:
    int dp[2001][2001];
    bool find(vector<int> &stones, int i, int k){
      if(i==stones.size()-1)
          return true;

      if(i>=stones.size()) 
          return false;

      if(dp[i][k]!=-1) 
          return dp[i][k]; 

      bool res = false;
      for(int j=-1;j<=1;j++){
          int next_jump=k+j;
          if(next_jump>0){
                int in= lower_bound(stones.begin(),stones.end(),stones[i]+next_jump)-stones.begin();
                if(in == stones.size() || stones[in]!=stones[i]+next_jump) 
                  continue;

                res=res||find(stones,in,next_jump);
          }
      }

      return dp[i][k]=res;

  }
  
  bool canCross(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        return find(stones, 0, 0);
  }
};
