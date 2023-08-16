/**************************************************************************************************************************************************************************
Given an array A[] (1<=A_i        <=10^9        ) of size N (1<=N<=10^5        ), find the number of subsequences of length 3 whose sum is divisible by M (1<=M<=10^3   ). 

Examples: 

Input  : A[] = {1, 2, 4, 3}
           M = 3 
Output : 2
Explanation : We can choose two such 
subsequence of length 3 such that its 
sum is divisible by 3 -> {1, 2, 3} ans 
{2, 4, 3} 
**************************************************************************************************************************************************************************/

Here we will use index mapping (hashing technique) to solve the problem. As we need to check if the sum of the chosen three numbers is divisible by M,
  we store each value under modulo M. We use a frequency array to store the number of occurrences of each element using index mapping techniques.

Three cases may occur: 

Firstly, if thrice of a number is divisible by M then we will add {{N}\choose{3}}        to answer where N is frequency of that number. 
Secondly, if twice of some number A added with sum number B is divisible by M then we will add {{Freq[A]}\choose{2}}        * Freq[B] to the answer. 
Thirdly, if all the numbers A, B, C that sum up to S which is divisible by M then we will add Freq[A] * Freq[B] * Freq[C] to the answer.
With this approach, we can solve the problem in O(M^2        ) which is executable in the given time. 

Implementation:


// O(M^2) time complexity C++ program to find
// count of subsequences of size three
// divisible by M.
#include <iostream>
 
using namespace std;
 
int countSubSeq(int A[], int N, int M)
{
    int ans = 0;
 
    // Storing frequencies of all remainders
    // when divided by M.
    int h[M] = { 0 };
    for (int i = 0; i < N; i++) {
        A[i] = A[i] % M;
        h[A[i]]++;
    }
 
    for (int i = 0; i < M; i++) {
        for (int j = i; j < M; j++) {
 
            // including i and j in the sum rem
            // calculate the remainder required
            // to make the sum divisible by M
            int rem = (M - (i + j) % M) % M;
 
            // if the required number is less than
            // j, we skip as we have already calculated
            // for that value before. As j here starts
            // with i and rem is less than j.
            if (rem < j)
                continue;
 
            // if satisfies the first case.
            if (i == j && rem == j)
                ans += h[i] * (h[i] - 1) * (h[i] - 2) / 6;
 
            // if satisfies the second case
            else if (i == j)
                ans += h[i] * (h[i] - 1) * h[rem] / 2;
 
            else if (i == rem)
                ans += h[i] * (h[i] - 1) * h[j] / 2;
            else if (rem == j)
                ans += h[j] * (h[j] - 1) * h[i] / 2;
 
            // if satisfies the third case
            else
                ans = ans + h[i] * h[j] * h[rem];
        }
    }
    return ans;
}
 
// Driver code
int main()
{  
    int M = 3;
    int A[] = { 1, 2, 4, 3 };
    int N = sizeof(A)/sizeof(A[0]);
    cout << countSubSeq(A, N, M);
    return 0;
}




Certainly, I'll explain each of the if-else conditions within the nested loops in the countSubSeq function.


if (i == j && rem == j)
    ans += h[i] * (h[i] - 1) * (h[i] - 2) / 6;
This condition checks if both i and j are the same, and if the required third remainder rem is also equal to j. If all these conditions are satisfied, 
it means that you have found a sequence of three identical remainders. In this case, you can calculate the number of distinct subsequences of length three
that can be formed using these identical remainders. The formula used (h[i] * (h[i] - 1) * (h[i] - 2)) / 6 calculates the number of combinations (nCr) of
choosing 3 items from h[i] identical remainders.


else if (i == j)
    ans += h[i] * (h[i] - 1) * h[rem] / 2;

In this condition, if i is equal to j but rem is not equal to j, it means you have two identical remainders (i and j) and one different remainder (rem). 
You can form a subsequence by choosing the two identical remainders in h[i] * (h[i] - 1) / 2 ways (as they're identical), and then selecting one different
remainder from h[rem]. So, this case calculates the count of subsequences with two identical remainders and one different remainder.



else if (i == rem)
    ans += h[i] * (h[i] - 1) * h[j] / 2;

Similarly, in this condition, if i is equal to rem but not equal to j, you have two identical remainders (i and rem) and one different remainder (j). 
The calculation is the same as the previous case.




else if (rem == j)
    ans += h[j] * (h[j] - 1) * h[i] / 2;
This condition handles the scenario where rem is equal to j, but i is different. It's symmetric to the previous two conditions.




else
    ans = ans + h[i] * h[j] * h[rem];
This else condition handles the general case where all three remainders are different. You multiply the frequencies of remainders i, j, and rem to get the count of
subsequences formed by selecting one remainder from each group.

Overall, the if-else conditions account for all possible combinations of remainders i, j, and rem to calculate the count of subsequences of size three that are
divisible by M. The conditions ensure that all cases are handled correctly to avoid overcounting and calculate the valid subsequences accurately.







The division by 6 in the formula (h[i] * (h[i] - 1) * (h[i] - 2)) / 6 is used to calculate the number of distinct combinations (nCr) of choosing 3 items from a 
group of h[i] identical items. Let's break down the logic behind this division:

When you have h[i] identical items (in this case, remainders) and you want to count the number of ways to choose 3 of them, you would traditionally use the formula 
for combinations:

nCr = n! / (r! * (n - r)!)

where n is the total number of items and r is the number of items to choose.

In your context, n is h[i], and r is 3. Therefore, the formula becomes:

h[i]C3 = h[i]! / (3! * (h[i] - 3)!)

However, notice that the denominator simplifies to:

3! * (h[i] - 3)! = 6 * (h[i] - 3)!

When you expand the factorial terms, you get:

h[i]! / (6 * (h[i] - 3)!) = (h[i] * (h[i] - 1) * (h[i] - 2)) / 6

So, the division by 6 in the formula accounts for the fact that you're counting combinations and adjusting the calculation to suit the specific context of choosing 
3 items from h[i] identical items. It ensures that you're counting the distinct combinations accurately without overcounting or undercounting.
