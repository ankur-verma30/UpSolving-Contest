/*
B. Maximum Multiple Sum

Given an integer n, find an integer x  such that: 2≤x≤n.
The sum of multiples of x that are less than or equal to is maximized. Formally, x+2x+3x+⋯+kx where kx≤n is maximized over all possible values of x.
Input
The first line contains t(1≤t≤100) — the number of test cases.

Each test case contains a single integer n
 (2≤n≤100).

Output
For each test case, output an integer, the optimal value of x. It can be shown there is only one unique answer.

Example
input
2
3
15
output
3
2

For n=3, the possible values of x are 2 and 3
. The sum of all multiples of 2 less than or equal to n is just 2, and the sum of all multiples of 3 less than or equal to nis 3. Therefore, 3 is the optimal value of x.

For n=15, the optimal value of x is 2. The sum of all multiples of 2 less than or equal to n is 2+4+6+8+10+12+14=56, which can be proven to be the maximal over all other possible values of x.

*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 3)
            cout << 3 << endl;
        else
            cout << 2 << endl;
    }
    return 0;
}
