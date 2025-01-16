/*

### Distinct Substring

A binary string is a string consisting of `0` and `1`. We define an island as a substring consisting of all `0`s bounded by `1`s (or the ends of the string).

For example, in the string `100010000`, there are 2 islands: `000` (bounded by `1`s) and `0000` (bounded by `1` and the end of the string). Note that the substring `00` in the above string is not an island.

You are given positive integers `N` and `K`. Find whether there exists a binary string of length `N` such that:

- There are exactly `K` islands in the string.
- Each island has a distinct length.

### Input Format
The first line of input will contain a single integer `T`, denoting the number of test cases.

Each test case consists of two space-separated integers `N` and `K` — the length of the binary string and the required number of islands.

### Output Format
For each test case, output on a new line, `YES` if there exists a valid binary string, otherwise print `NO`.

You may print each character of the string in uppercase or lowercase (for example, the strings `YES`, `yEs`, `yes`, and `yeS` will all be treated as identical).

### Constraints
- \(1 \leq T \leq 10^4\)
- \(1 \leq N \leq 10^5\)
- \(1 \leq K \leq 500\)
- The sum of \(N\) over all test cases won't exceed \(2 \cdot 10^6\).

### Sample 1:

#### Input
```
4
1 1
3 1
6 3
7 2
```

#### Output
```
YES
YES
NO
YES
```

### Explanation:

- **Test case 1**: The only binary string satisfying the conditions is `0` as it has length 1 and contains one island, i.e., `0` itself.

- **Test case 2**: Consider the binary string `001` of length 3. The only island in this string is `00`. Some other valid binary strings under conditions are `000`, `101`, and `110`. The strings `111`, `010` are not valid.

- **Test case 3**: It is not possible to generate a binary string under given conditions.

- **Test case 4**: Consider the binary string `1011000` of length 7. There are exactly two islands with lengths 1 and 3. Note that strings like `0001000`, `1010010` are not valid.
*/

#include <bits/stdc++.h>
using namespace std;
// Ankur Verma
#define ll long long
#define MOD 1000000007

bool solve(int n, int k)
{
    int ZeroCount = (k * (k + 1)) / 2;
    int OnesCount = k - 1;
    if (ZeroCount + OnesCount <= n)
        return true;
    else
        return false;
}

// STARTING OF THE CODE

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    for (int i = 0; i < test; i++)
    {
        int n, k;
        cin >> n >> k;
        if (solve(n, k))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

// END OF THE CODE
