/*
Sure, here's the refined version of the question:

### A power B mod C

You are given an integer \( A \) (\(2 \leq A \leq 10^9\)). Find two integers \( B \) and \( C \) such that:

- \( 2 \leq A < B < C \leq 10^{18} \)
- \( A^B \% C = 0 \)
- \( B \% A = 0 \)

It can be proved that at least one solution exists. If multiple solutions exist, print any.

### Input Format

The first line of input will contain a single integer \( T \), denoting the number of test cases.

Each test case consists of a single integer \( A \) as mentioned in the statement.

### Output Format

For each test case, output two space-separated integers \( B \) and \( C \) satisfying the conditions.

### Constraints

- \( 1 \leq T \leq 10^4 \)
- \( 2 \leq A \leq 10^9 \)

### Sample 1:

#### Input

```
2
6
10
```

#### Output

```
12 16
30 32
```

### Explanation

- **Test case 1**: Consider \( B = 12 \) and \( C = 16 \):
  - \( 2 \leq A < B < C \leq 10^{18} \)
  - \( 6^{12} \% 16 = 0 \)
  - \( 12 \% 6 = 0 \)

- **Test case 2**: Consider \( B = 30 \) and \( C = 32 \):
  - \( 2 \leq A < B < C \leq 10^{18} \)
  - \( 10^{30} \% 32 = 0 \)
  - \( 30 \% 10 = 0 \)
*/
#include<bits/stdc++.h>
using namespace std;
//Ankur Verma
#define ll long long
#define MOD 1000000007

//STARTING OF THE CODE

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int test;
cin>>test;

for(int i=0;i<test;i++){
ll a;
cin>>a;

if(a==2) cout<<4<<" "<<8<<endl;
else 
cout<<2*a <<" "<<a*a<<endl;
}
return 0;
}

//END OF THE CODE



