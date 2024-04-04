/*
Binary Substring

You are given a binary string S of even length N.
You can perform the following operation on string S any number of times:
Select two indices i and j where 1≤i<j<N, and both i and j are odd;
Swap Si with Sj;
Swap Si+1 with Sj+1;
Find the maximum length of a non-decreasing substring of the string you can obtain using any (possibly zero) number of operations.

Input Format
The first line of input will contain a single integer T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains an integer N — denoting length of the binary string.
The next line contains a binary string S of length N.


Output Format

For each test case, output on a new line, the maximum length of a non-decreasing substring of the string you can obtain using any (possibly zero) number of operations.

Constraints
1<=T<=1.5*10^5
2<=N<=3*10^5, N is even
Si belongs {0,1}
The sum of N over all test cases won't exceed 3*10^5.
*/

#include <bits/stdc++.h>
using namespace std;

long long int solve(string str)
{

    long long int zo = 0, zz = 0, oz = 0, oo = 0;
    long long int ans = 0;
    long long int len = str.length();
    for (long long int i = 0; i < len - 1; i = i += 2)
    {
        if (str[i] == '0' && str[i + 1] == '0')
            zz++;
        if (str[i] == '0' && str[i + 1] == '1')
            zo++;
        if (str[i] == '1' && str[i + 1] == '0')
            oz++;
        if (str[i] == '1' && str[i + 1] == '1')
            oo++;
    }
    ans += (zz * 2);
    if (zo)
        ans += 2;
    ans += (2 * oo);

    ans += min((int)oz, 2);

    return ans;
}
int main()
{
    int tesecase;
    cin >> tesecase;
    for (int i = 0; i < tesecase; i++)
    {
        string str;
        cin >> str;
        cout << "The total length of the string is " << str.length() << endl;
        cout << "The total non decreasing binary substring can be made of length is " << solve(str) << endl;
    }

    return 0;
}
