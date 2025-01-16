// https://codeforces.com/contest/1986/problem/0

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


ll test;
cin>>test;

for(ll i=0;i<test;i++){
int x1,x2,x3;
cin>>x1>>x2>>x3;
int mini=INT_MAX;
for(int i=1;i<=10;i++){
    int total=abs(x1-i)+abs(x2-i)+abs(x3-i);
    mini=min(mini,total);
}
cout<<mini<<endl;
}

return 0;
}

//END OF THE CODE

