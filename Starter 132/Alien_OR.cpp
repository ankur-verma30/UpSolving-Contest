/*
ALIEN-OR
You are given:positive integers 𝑁 and 𝐾 (𝐾≤𝑁)an array A of size N, where each element of the array is a binary string of length K;
 For each 1≤𝑗<2^𝐾, your task is to find whether there exists a set of indices {𝑖1,𝑖2,…,𝑖𝑚}{i1,i2,…,im}(1≤i,j,m≤N) such that:

The decimal value of (𝐴𝑖1∣ Ai2| Ai3|....|Aim) equals j, where ∣ denotes bitwise OR operation.
Print YES if a set of indices satisfying the given condition exists for all 1<=j<2^k Otherwise, print NO.

Input Format
The first line contains an integer T denoting the number of test cases.
The first line of each test case contains two integers N and K.
The i-th of the next 𝑁 lines contains the binary string Ai.

Output Format
For each test case, print YES if a set of indices satisfying the given condition exists for all 1<j<2^k. Otherwise, print NO.

You may print each character of the string in uppercase or lowercase (for example, the strings YES, yEs, yes, and yeS will all be treated as identical).

Constraints
1<=T<=50
1<=N<=100
1<=K<=N
|Ai|=K
Ai belongs to {0,1}
The sum o N all over the testcases won't exceed 500.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int testcase;
    cin >> testcase;

    for (int i = 0; i < testcase; i++)
    {
        int n, k;
        cin >> n >> k;

        vector<int> check(k, 0);

        for (int i = 0; i < n; i++)
        {
            string str;
            cin >> str;

            int count = 0;
            for (auto x : str)
            {
                if (x == '1')
                    count++;
            }

            if (count == 1)
            {
                int x = -1;
                for (int j = 0; j < k; j++)
                {
                    if (str[j] == '1')
                        x = j;
                }
                check[x] = true;
            }
        }

        int f = 1;
        for (auto x : check)
        {
            if (!x)
            {
                cout << "NO" << endl;
                f = 0;
                break;
            }
        }
        if (f)
            cout << "YES" << endl;
    }
}
