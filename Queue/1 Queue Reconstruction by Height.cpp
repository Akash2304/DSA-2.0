/**************************************************************************************************************************************************************************
You are given an array of people, people, which are the attributes of some people in a queue (not necessarily in order). Each people[i] = [hi, ki] 
represents the ith person of height hi with exactly ki other people in front who have a height greater than or equal to hi.

Reconstruct and return the queue that is represented by the input array people. The returned queue should be formatted as an array queue, 
where queue[j] = [hj, kj] is the attributes of the jth person in the queue (queue[0] is the person at the front of the queue).

 

Example 1:

Input: people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
Output: [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
Explanation:
Person 0 has height 5 with no other people taller or the same height in front.
Person 1 has height 7 with no other people taller or the same height in front.
Person 2 has height 5 with two persons taller or the same height in front, which is person 0 and 1.
Person 3 has height 6 with one person taller or the same height in front, which is person 1.
Person 4 has height 4 with four people taller or the same height in front, which are people 0, 1, 2, and 3.
Person 5 has height 7 with one person taller or the same height in front, which is person 1.
Hence [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] is the reconstructed queue.
Example 2:

Input: people = [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]
Output: [[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]
 

Constraints:

1 <= people.length <= 2000
0 <= hi <= 106
0 <= ki < people.length
It is guaranteed that the queue can be reconstructed.
***************************************************************************************************************************************************************************/
class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b)
    {
        if(a[0]==b[0])
        return a[1]<b[1];
        return a[0]>b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), comp);
        vector<vector<int>> ans;
        for(int i=0;i<people.size();i++)
        {
            ans.insert(ans.begin()+people[i][1], people[i]);
        }
        return ans;
    }
};




Let's dry run the code for the given input, people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]:

Step 1: Sorting the people vector using the comp function:
After sorting, the people vector will become:

css
Copy code
[[7, 0], [7, 1], [6, 1], [5, 0], [5, 2], [4, 4]]
The vector is sorted in descending order of height. For people with the same height, they are sorted in ascending order of the number of people in front of them.

Step 2: Initializing an empty 2D vector ans to store the reconstructed queue.

Step 3: Iterating through the sorted people vector and inserting them into the ans vector based on the second element (number of people in front).

1st iteration:

Inserting [7, 0] at index 0 in ans. ans becomes [[7, 0]].
2nd iteration:

Inserting [7, 1] at index 1 in ans. ans becomes [[7, 0], [7, 1]].
3rd iteration:

Inserting [6, 1] at index 1 in ans. ans becomes [[7, 0], [6, 1], [7, 1]].
4th iteration:

Inserting [5, 0] at index 0 in ans. ans becomes [[5, 0], [7, 0], [6, 1], [7, 1]].
5th iteration:

Inserting [5, 2] at index 2 in ans. ans becomes [[5, 0], [7, 0], [5, 2], [6, 1], [7, 1]].
6th iteration:

Inserting [4, 4] at index 4 in ans. ans becomes [[5, 0], [7, 0], [5, 2], [6, 1], [4, 4], [7, 1]].
Step 4: Return the ans vector as the reconstructed queue.

The final reconstructed queue is:

css
Copy code
[[5, 0], [7, 0], [5, 2], [6, 1], [4, 4], [7, 1]]
This is the correct order of the queue based on the heights and the number of taller people in front of each person.
