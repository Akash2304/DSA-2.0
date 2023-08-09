/************************************************************************************************************************************************************************
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character.
You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achive this answer too.
 

Constraints:

1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length
***************************************************************************************************************************************************************************/

Intution : We traverse from each char of the string if the curr char exists on the map we increase the count else we put it in the map .
Now since we can only replace at most K no of items so if at any time the curr window has more than k replacable items we have to shrink that window .

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int i=0;//->window start
        int j=0;//->window end
        int maxC=0;//->max no of repeating elements 
        int ans=-1;
        unordered_map<char,int> mp;
        while(j<n)
        {
            mp[s[j]]++;
            maxC=max(maxC,mp[s[j]]);
            
            int curr_len=j-i+1;//Curr Len of the window
            if(curr_len-maxC>k) //the curr window has more than k replacable items case
            {
                mp[s[i]]--;
                i++;// shrinking the window
            }
            curr_len=j-i+1;// just in case i is changed
            ans=max(ans,curr_len);
            j++;
        }
        
        return ans;
    }
};

/***********************************************************************************************************************************************************************/
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int ans=0, j=0, mx=0;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
            mx=max(mx, mp[s[i]]);
            if(i-j+1-mx > k)
            {
                mp[s[j]]--;
                j++;
            }
            ans=max(ans, i-j+1);
        }
        return ans;
    }
};
/***********************************************************************************************************************************************************************/

// Time Complexity :  O(n)
// Space Complexity : O(1)
class Solution {
public:
    int characterReplacement(string s, int k) {
        // Base case...
        if (s.size() == 0) return 0;
        // Make an array...
        vector <int> arr(128);
        // Initialize largestCount & beg pointer...
        int beg = 0, largestCount = 0;
        // Traverse all characters through the loop...
        for (int end = 0; end < s.size(); end++) {
            // Get the largest count of a single, unique character in the current window...
            largestCount = max(largestCount, ++arr[s[end]]);
            // We are allowed to have at most k replacements in the window...
            // So, if max character frequency + distance between beg and end is greater than k...
            // That means we have met a largest possible sequence, we can move the window to right...
            if (end - beg + 1 - largestCount > k)       // The main equation is: end - beg + 1 - largestCount...
                arr[s[beg++]]--;
        }
        // Return the sequence we have passes, which is s.length() - beg...
        return s.length() - beg;
    }
};
