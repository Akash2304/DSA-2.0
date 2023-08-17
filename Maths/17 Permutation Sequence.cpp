/**************************************************************************************************************************************************************************
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

 

Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
Example 3:

Input: n = 3, k = 1
Output: "123"
 

Constraints:

1 <= n <= 9
1 <= k <= n!
*************************************************************************************************************************************************************************/
https://www.youtube.com/watch?v=wT7gcXLYoao&t=127s


class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>v;
        int fact=1;
        
        for(int i=1;i<n;i++)
        {
            fact*=i;
            v.push_back(i);
        }
        v.push_back(n);
        
        string str="";
        
        k=k-1; //0-based indexing 
        
        while(true)
        {
            str+=to_string(v[k/fact]);
            v.erase(v.begin()+ k/fact);
            
            if(v.size()==0)
                break;
            
            k=k%fact;
            fact=fact/v.size();
        }
        
        return str;
        
    }
};

/*******************************************************************************************************************************************************************/
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> vec;
        for(int i=0;i<n;i++) vec.push_back(i+1);
        for(int i=0;i<k-1;i++)  // less thank k-1 cause 1st permution is the original pattern itself... 
          next_permutation(vec.begin(),vec.end());
        string s;
        for(int i=0;i<n;i++) s+='0'+vec[i];
        return s;
    }
};

/****************************************************************************************************************************************************************/
class Solution {
  public:
    //function to generate all possible permutations of a string
    void solve(string & s, int index, vector < string > & res) {
      if (index == s.size()) {
        res.push_back(s);
        return;
      }
      for (int i = index; i < s.size(); i++) {
        swap(s[i], s[index]);
        solve(s, index + 1, res);
        swap(s[i], s[index]);
      }
    }
string getPermutation(int n, int k) {
    string s;
    vector < string > res;
    //create string
    for (int i = 1; i <= n; i++) {
      s.push_back(i + '0');
    }
    solve(s, 0, res);
    //sort the generated permutations
    sort(res.begin(), res.end());
    //make k 0-based indexed to point to kth sequence
    auto it = res.begin() + (k - 1);
    return *it;
  }
};
Time complexity: O(N! N) +O(N! Log N!)

Reason: The recursion takes O(N!) time because we generate every possible permutation and another O(N) time is required to make a deep copy and store every
sequence in the data structure. Also, O(N! Log N!) time required to sort the data structure

Space complexity: O(N)

Reason: Result stored in a vector, we are auxiliary space taken by recursion
