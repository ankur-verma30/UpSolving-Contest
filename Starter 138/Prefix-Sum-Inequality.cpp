/*
### Prefix Suffix Inequality

You are given an odd integer \( N \). Generate an array \( A \) of \( N \) positive integers such that:

1. \( 1 \leq A_i \leq 10^5 \)
2. Bitwise AND of each prefix array is greater than or equal to the bitwise XOR of the corresponding prefix array.
3. Bitwise AND of each suffix array is less than or equal to the bitwise XOR of the corresponding suffix array.

It can be proved that at least one solution exists. If multiple solutions exist, you may print any one.

**Note**:
- For an array of length \( N \), a prefix array of length \( i \) denotes the subarray from index 1 to \( i \).
- A suffix array of length \( i \) is the subarray from index \( (N - i + 1) \) to index \( N \).
- The output is large, so use fast input-output methods.

### Input Format

The first line of input will contain a single integer \( T \), denoting the number of test cases.

Each test case consists of a single integer \( N \), the length of the required array.

### Output Format

For each test case, output on a new line, \( N \) space-separated integers denoting the array satisfying the given conditions.

It can be proved that at least one solution exists. If multiple solutions exist, you may print any one.

### Constraints

- \( 1 \leq T \leq 1000 \)
- \( 1 \leq N \leq 10^5 \), \( N \) is odd.
- The sum of \( N \) over all test cases won't exceed \( 2 \cdot 10^6 \).

### Sample Input

```
3
1
3
5
```

### Sample Output

```
1
5 6 3
7 5 7 7 3
```

### Explanation

- **Test case 1**: For length 1, any array in the required range would satisfy all conditions.
  
- **Test case 2**: Consider the array \( A = [5, 6, 3] \) where all elements are in the required range:
    - Prefix arrays:
      - \([5]\): bitwise AND and XOR are the same.
      - \([5, 6]\): \( 5 \& 6 = 4 \) is greater than \( 5 \oplus 6 = 3 \).
      - \([5, 6, 3]\): \( 5 \& 6 \& 3 = 0 \) is equal to \( 5 \oplus 6 \oplus 3 = 0 \).
    - Suffix arrays:
      - \([3]\): bitwise AND and XOR are the same.
      - \([6, 3]\): \( 6 \& 3 = 2 \) is less than \( 6 \oplus 3 = 5 \).
      - \([5, 6, 3]\): \( 5 \& 6 \& 3 = 0 \) is equal to \( 5 \oplus 6 \oplus 3 = 0 \).

- **Test case 3**: Consider the array \( A = [7, 5, 7, 7, 3] \) where all elements are in the required range:
    - Prefix arrays:
      - \([7]\): bitwise AND and XOR are the same.
      - \([7, 5]\): \( 7 \& 5 = 5 \) is greater than \( 7 \oplus 5 = 2 \).
      - \([7, 5, 7]\): \( 7 \& 5 \& 7 = 5 \) is equal to \( 7 \oplus 5 \oplus 7 = 5 \).
      - \([7, 5, 7, 7]\): \( 7 \& 5 \& 7 \& 7 = 5 \) is greater than \( 7 \oplus 5 \oplus 7 \oplus 7 = 2 \).
      - \([7, 5, 7, 7, 3]\): \( 7 \& 5 \& 7 \& 7 \& 3 = 1 \) is equal to \( 7 \oplus 5 \oplus 7 \oplus 7 \oplus 3 = 1 \).
    - Suffix arrays:
      - \([3]\): bitwise AND and XOR are the same.
      - \([7, 3]\): \( 7 \& 3 = 3 \) is less than \( 7 \oplus 3 = 4 \).
      - \([7, 7, 3]\): \( 7 \& 7 \& 3 = 3 \) is equal to \( 7 \oplus 7 \oplus 3 = 3 \).
      - \([5, 7, 7, 3]\): \( 5 \& 7 \& 7 \& 3 = 1 \) is less than \( 5 \oplus 7 \oplus 7 \oplus 3 = 6 \).
      - \([7, 5, 7, 7, 3]\): \( 7 \& 5 \& 7 \& 7 \& 3 = 1 \) is equal to \( 7 \oplus 5 \oplus 7 \oplus 7 \oplus 3 = 1 \).
*/

#include<bits/stdc++.h>
using namespace std;
//Ankur Verma
#define ll long long
#define MOD 1000000007

vector<int> solve(int n){
    vector<int>res;
    if(n==1) res.push_back(1);
    for(int i=0;i<n-2;i++){
        res.push_back(3);
    }
    res.push_back(2);
    res.push_back(1);

return res ;
}

//STARTING OF THE CODE

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int test;
cin>>test;
for(int i=0;i<test;i++){
int n;
cin>>n;
vector<int>arr=solve(n);

for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
}
return 0;
}

//END OF THE CODE

