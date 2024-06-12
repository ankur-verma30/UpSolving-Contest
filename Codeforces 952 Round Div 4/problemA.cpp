/*
A. Creating Words


Matthew is given two strings and b, both of length 3. He thinks it's particularly funny to create two new words by swapping the first character of a with the first character of b. He wants you to output a and b after the swap.

Note that the new words may not necessarily be different.

Input
The first line contains t(1≤t≤100)  — the number of test cases.
The first and only line of each test case contains two space-separated strings, a
 and b, both of length 3. The strings only contain lowercase Latin letters.

Output
For each test case, after the swap, output a and b, separated by a space.

Example
input
6
bit set
cat dog
hot dog
uwu owo
cat cat
zzz zzz

output
sit bet
dat cog
dot hog
owu uwo
cat cat
zzz zzz

*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s, t;
        cin >> s >> t;
        swap(s[0], t[0]);
        cout << s << " " << t << endl;
    }
}