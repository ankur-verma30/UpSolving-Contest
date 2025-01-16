#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int solve(int n, int k, vector<int> &arr)
{
    vector<int> mpp(21, 0);

    for (const auto &it : arr)
        mpp[it]++;

    // If k is already the most frequent element
    if (*max_element(mpp.begin(), mpp.end()) == mpp[k])
        return 0;

    // Check from the prefix
    auto temp = mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]--;
        if (mpp[k] == 0)
            break;
        if (*max_element(mpp.begin(), mpp.end()) == mpp[k])
            return 1;
    }

    // check the suffix
    mpp = temp;
    for (int i = n - 1; i >= 0; i--)
    {
        mpp[arr[i]]--;
        if (mpp[k] == 0)
            break;
        if (*max_element(mpp.begin(), mpp.end()) == mpp[k])
            return 1;
    }

    return 2; 
}

int main()
{
    int testcase;
    cin >> testcase;
    for (int i = 0; i < testcase; i++)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << solve(n, k, arr) << endl;
    }
    return 0;
}