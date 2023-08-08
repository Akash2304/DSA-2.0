/**************************************************************************************************************************************************************************
Given a string s containing an out-of-order English representation of digits 0-9, return the digits in ascending order.

 

Example 1:

Input: s = "owoztneoer"
Output: "012"
Example 2:

Input: s = "fviefuro"
Output: "45"
 

Constraints:

1 <= s.length <= 105
s[i] is one of the characters ["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"].
s is guaranteed to be valid.
************************************************************************************************************************************************************************/


//https://www.youtube.com/watch?v=oD2KnJdUCYI do watch this for better understanding....
class Solution {
public:
    string originalDigits(string s) {
       vector<int>v(26,0);
       for(auto i:s){

           v[i-'a']++;
       }

       vector<int>num(10);
       //unique cases
       num[0]=v['z'-'a'];
       num[2]=v['w'-'a'];
       num[4]=v['u'-'a'];
       num[6]=v['x'-'a'];
       num[8]=v['g'-'a'];

       //derived cases
         num[1]=v['o'-'a']-num[0]-num[2]-num[4];
         num[3]=v['h'-'a']-num[8];
         num[5]=v['f'-'a']-num[4];
         num[7]=v['s'-'a']-num[6];
         num[9]=v['i'-'a']-num[5]-num[6]-num[8];

         string str;
         for(int i=0;i<num.size();i++)
         {
             while(num[i]-- > 0)
             {
                 str+=to_string(i);
             }

         }
         return str;

    }
};
