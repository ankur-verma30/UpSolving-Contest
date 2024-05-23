/*
Change A to B
You are given positive integers A,B, and K.

For a variable 𝑥 with an initial value 𝐴, you need to achieve the target value B. In one operation, you can:

Either change x to x+1 or
Change x to k*x.
Find the minimum number of operations needed to go from x=A to x=B.

Input Format
The first line of input will contain a single integer T, denoting the number of test cases.
Each test case contains three space-separated integers A,B,K — the initial and target values of the variable x and the constant.
Output Format
For each test case, output on a new line, the minimum number of operations needed to go from x=A to x=B.

Constraints
1<=T<=10^4
1<=A,B<=10^9
2<=K<=10^9
*/

#include <bits/stdc++.h>
using namespace std;

long long solve(long long A, long long B, long long K)
{
    long long count = 0;
    while (B != A)
    {
        if (B % K != 0)
        {
            long long quotient = B / K;
            long long nearestMultiple = K * quotient;
            count += (B - nearestMultiple);
            B = nearestMultiple;
        }

        else if (B / K >= A)
        {
            B = B / K;
            count++;
        }
        else
        {
            count += (B - A);
        }
    }
    return count;
}

int main()
{
    int testcase;
    cin >> testcase;
    for (int i = 0; i < testcase; i++)
    {
        long long int A, B, K;
        cin >> A >> B >> K;
        cout << solve(A, B, K) << endl;
    }
}