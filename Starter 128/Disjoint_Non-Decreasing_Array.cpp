/*
Disjoint Non-Decreasing Array

You are given an array A of length N. You can do the following operation at most once:
Select any non-empty subsequence such that no two consecutive elements are chosen;
Add any positive integer X to all the chosen elements.
Find whether you can make the array non-decreasing by doing at most one such operation.

Input Format
The first line of input will contain a single integer T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains an integer N — the number of elements in the array A.
The second line of input contains N space-separated integers A1,A2,.....,An-the elements of the array A.

Output Format
For each testcase - print YES, if it is possible to sort the array
�
A in non-decreasing order using at most one operation.

You may print each character of the string in uppercase or lowercase (for example, the strings YES, yEs, yes, and yeS will all be treated as identical).
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        long long len;
        cin >> len;
        vector<long long> a(len);
        for (int i = 0; i < len; i++)
            cin >> a[i];
        // taking input

        int breakPoint = -1;
        for (int i = 0; i < len - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                breakPoint = i;
                break;
            }
        }

        if (breakPoint == -1 || breakPoint + 2 >= len) // if array is sorted already
        // or breakpoint exists at n-2 location
        {
            cout << "YES" << endl;
            continue;
        }

        long long lowerLimit = a[breakPoint] - a[breakPoint + 1]; // lower limit
        long long upperLimit = -1;                                // intially -1

        if (breakPoint + 2 < len)
            upperLimit = a[breakPoint + 2] - a[breakPoint + 1]; // if possible now define this

        long long i = breakPoint; // start point

        while (i < len - 1)
        {
            if (a[i] > a[i + 1])
            {
                lowerLimit = max(lowerLimit, a[i] - a[i + 1]);
                if (i + 2 < len)
                    upperLimit = min(upperLimit, a[i + 2] - a[i + 1]);
                i += 2;
            }
            else
            {
                i++;
            }
        }

        if (lowerLimit <= upperLimit)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

// tc - O(n)
// sc - O(n)