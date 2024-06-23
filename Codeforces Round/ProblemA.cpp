#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &a)
{
    int res = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (res < (a[i] + a[n - 1]))
            res = a[i] + a[n - 1];
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << solve(n, a) << endl;
    }
}

