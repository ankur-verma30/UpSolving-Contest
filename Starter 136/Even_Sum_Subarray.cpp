/*
## Problem Statement: Even Sum Subarray

Given an array \( A \) of size \( N \), the goal is to find the size of the largest subarray of \( A \) which has an even sum.

### Definition
A subarray is a contiguous part of an array. For example, given the array \([1, 3, 2]\), possible subarrays include \([1]\), \([3]\), \([2]\), \([1, 3]\), \([3, 2]\), and \([1, 3, 2]\). However, \([1, 2]\) is not a subarray since it is not contiguous.

### Example
For the array \([2, 1, 2]\), the largest subarray with an even sum is \([2]\) with a size of 1. For the array \([1, 3, 2]\), the entire array \([1, 3, 2]\) has an even sum and its size is 3.

### Input Format
- The first line of input will contain a single integer \( T \), denoting the number of test cases.
- Each test case consists of multiple lines:
  - The first line contains a single integer \( N \) — the size of the array.
  - The next line contains \( N \) space-separated integers \( A_1, A_2, \ldots, A_N \).

### Output Format
For each test case, output on a new line the size of the largest subarray with an even sum.

### Constraints
- \( 1 \leq T \leq 50 \)
- \( 1 \leq N \leq 50 \)
- \( 1 \leq A_i \leq 10^4 \)

### Sample Input
```
4
3
2 1 2
3
1 3 2
6
2 2 1 1 1 2
1
1
```

 Sample Output
1
3
4
0
### Explanation:
**Test Case 1**: The largest subarray with even sum is \([2]\) having size 1.

**Test Case 2**: The largest subarray with even sum is \([1, 3, 2]\) having size 3.

**Test Case 3**: The largest subarray with even sum is \([2, 2, 1, 1]\) having size 4.

**Test Case 4**: No subarray has an even sum.
*/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int N)
{
    int total_sum = 0;
    for (int i = 0; i < N; ++i)
    {
        total_sum += A[i];
    }

    int first_odd_index = -1;
    int last_odd_index = -1;
    if (total_sum % 2 == 0)
    {
        return N;
    }
    else
    {
        for (int i = 0; i < N; ++i)
        {
            if (A[i] % 2 != 0)
            {
                if (first_odd_index == -1)
                {
                    first_odd_index = i;
                }
                last_odd_index = i;
            }
        }
    }

    int max_length = 0;
    if (first_odd_index != -1)
    {
        max_length = max(N - first_odd_index - 1, last_odd_index);
    }
    return max_length;
}

int main()
{
    int test;
    cin >> test;
    for (int i = 0; i < test; i++)
    {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int j = 0; j < n; j++)
        {
            cin >> A[j];
        }
        cout << solve(A, n) << endl;
    }
    return 0;
}
