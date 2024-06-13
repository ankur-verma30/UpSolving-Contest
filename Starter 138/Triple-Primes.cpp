/*
Sure, here's the refined version of the question:

### Triple Primes

Chef has given you an even integer \( N \). Find whether there exist 3 distinct integers \( a, b, c \) such that:

- \( a, b, c \) are primes.
- \( a^2 + b^2 + c^2 = N \)

### Input Format

The first line of input will contain a single integer \( T \), denoting the number of test cases.

Each test case consists of a single even integer \( N \).

### Output Format

For each test case, output on a new line `YES` if there exist valid \( a, b, c \) otherwise print `NO`.

You may print each character of the string in uppercase or lowercase (for example, the strings YES, yEs, yes, and yeS will all be treated as identical).

### Constraints

- \( 1 \leq T \leq 500 \)
- \( 0 \leq N \leq 10^{10} \), \( N \) is even

### Subtasks

- **Subtask 1 (30 points):** \( 0 \leq N \leq 10^5 \)
- **Subtask 2 (70 points):** No further constraints.

### Sample Input

```
3
6
38
78
```

### Sample Output

```
No
Yes
Yes
```

### Explanation

- **Test case 1:** It can be shown that no three distinct primes satisfy the condition.
- **Test case 2:** Consider three distinct primes \( 2, 3, 5 \), satisfying \( 2^2 + 3^2 + 5^2 = 38 \).
- **Test case 3:** A possible set of primes might be \( 5, 7, 4 \), satisfying \( 5^2 + 7^2 + 4^2 = 78 \).

Make sure to find such primes efficiently to handle the large constraints effectively.
*/
#include <bits/stdc++.h>
using namespace std;
// Ankur Verma
#define ll long long
#define MOD 1000000007

bool CheckPrime(ll num)
{
    if (num <= 1)
        return false;
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;
    for (ll i = 3; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

vector<ll> prime;
vector<ll> primes(int n)
{

    for (ll i = 2; i <= n; i++)
    {
        if (CheckPrime(i))
            prime.push_back(i);
    }
    sort(prime.begin(), prime.end());
    return prime;
}

bool solve(ll n)
{
    n=n-4;
    for (auto& x : prime)
    {
        ll a = n  - (x * x);
        if (a <= 0)
            continue;
        int p = sqrt(a);
        if (binary_search(prime.begin(), prime.end(), p) && p * p == a && p != 2 && p != x)
            return true;
    }
    return false;
}

// STARTING OF THE CODE

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    primes(100000);
    int test;
    cin >> test;
    for (int i = 0; i < test; i++)
    {
        ll n;
        cin >> n;
        if (solve(n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

// END OF THE CODE
