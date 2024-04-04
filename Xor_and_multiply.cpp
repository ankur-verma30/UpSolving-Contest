/*

XOR And Multiply
Chef has a favourite positive integer X.
He wondered if there are two positive integers a and b such that:
1<=a,b<=8*10^18;
The values a&b and a⊕b are positive and divisible by X. Note that &and ⊕ denote bitwise and and bitwise xor operations respectively.
You need to help Chef find these two numbers.

If there are multiple solutions, you can output any of them. Under the given constraints, it can be proven that at least one solution always exists.

Input Format
The first line of input will contain a single integer T, denoting the number of test cases.
The first line of each test case contains an integer X — Chef's favourite number.
Output Format
For each test case, output on a new line, two space-separated integers a and b satisfying the given constraint.

If there are multiple solutions, you can output any of them.

Constraints

1<=T<=2*10^5
1<=X<=10^9

*/

#include<bits/stdc++.h>
using namespace std;

pair<long long int, long long int>solve(int x){
    long long int a,b;
    a=x;
    b=2*x;
    while(((b|x)^x)%x!=0){
        b=b*2;
    }
    return {a,b};
}

int main(){
    int testcase;
    cin>>testcase;
    for(int i=0; i<testcase;i++){
        int x;
        cin>>x;
        pair<long long int, long long int> result=solve(x);
        cout<<result.first<<" "<<result.second<<endl;
    }
}