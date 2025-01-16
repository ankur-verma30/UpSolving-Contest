/*
## Problem Statement: Sum of Modes

For a binary string \(T\), let \(f(T)\) denote the number of modes of string \(T\). The mode of a string is the character with maximum frequency. If multiple characters have the same maximum frequency, all of them are said to be modes. For example, \(f(101) = 1\) because it has a unique mode '1', while \(f(01) = 2\) because both '0' and '1' are modes.

Given a binary string \(S\) of length \(N\), compute the value of:

\[
\sum_{L=1}^{N} \sum_{R=L}^{N} f(S[L,R])
\]

where \(S[L,R]\) denotes the substring of \(S\) from index \(L\) to \(R\).

### Input Format
- The first line of input contains a single integer \(T\), denoting the number of test cases.
- Each test case consists of multiple lines:
  - The first line contains one integer \(N\) — the length of the string.
  - The second line contains a binary string \(S\) of length \(N\).

### Output Format
For each test case, output on a new line the required sum.

### Constraints
- \(1 \leq T \leq 10^4\)
- \(1 \leq N \leq 10^5\)
- \(S_i \in \{0, 1\}\)
- The sum of \(N\) over all test cases does not exceed \(10^5\).

### Sample Input
```
3
2
01
4
0011
5
10101
```

### Sample Output
```
4
12
21
```

### Explanation:
**Test case 1:**
- \(f(0) = 1\)
- \(f(1) = 1\)
- \(f(01) = 2\)
The total sum is \(4\).

**Test case 2:**
- \(f(0) = 1\), two occurrences.
- \(f(1) = 1\), two occurrences.
- \(f(00) = 1\)
- \(f(01) = 2\)
- \(f(11) = 1\)
- \(f(001) = 1\)
- \(f(011) = 1\)
- \(f(0011) = 2\)
The total sum is \(12\).

### Solution Approach:
1. **Count Prefix Frequencies:** Use prefix arrays to count the number of '0's and '1's up to each index.
2. **Calculate Modes for Subarrays:** Using the prefix counts, determine the frequency of '0's and '1's in any subarray \(S[L,R]\).
3. **Efficient Summation:** Use the prefix counts to compute \(f(S[L,R])\) for all possible \(L\) and \(R\) in an efficient manner.
*/

#include <bits/stdc++.h>
using namespace std;

//can be done using prefix sum also 

// Function to calculate the number of modes in a substring
int SumofModes(const string& ans) {
    unordered_map<char, int> mpp;
    int maxlen = 0;
    for (char ch : ans) {
        mpp[ch]++;
        maxlen = max(maxlen, mpp[ch]);
    }
    int modes = 0;
    for (auto x : mpp) {
        if (maxlen == x.second) modes++;
    }
    return modes;
}

// Main function to solve the problem
int main() {
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        string str;
        cin >> str;
        int total = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string temp = str.substr(i, j - i + 1);
                total += SumofModes(temp);
            }
        }
        cout << total << endl;
    }
    return 0;
}
