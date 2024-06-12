/*
E. Secret Box

Ntarsis has a box B with side lengths x, y, and z. It lies in the 3D coordinate plane, extending from (0,0,0) to (x,y,z).

Ntarsis has a secret box S. He wants to choose its dimensions such that all side lengths are positive integers, and the volume of S is k. He can place S somewhere within B such that:

S is parallel to all axes.every corner of S lies on an integer coordinate.S is magical, so when placed at an integer location inside B, it will not fall to the ground.

Among all possible ways to choose the dimensions of S, determine the maximum number of distinct locations he can choose to place his secret box S inside B. Ntarsis does not rotate S once its side lengths are selected.

Input
The first line consists of an integer t, the number of test cases (1≤t≤2000). The description of the test cases follows.

The first and only line of each test case contains four integers x,y, and k (1≤x,y,z≤2000, 1≤k≤x⋅y⋅z).

It is guaranteed the sum of all x, sum of all y, and sum of all z do not exceed 2000 over all test cases.

Note that k may not fit in a standard 32-bit integer data type.

Output
For each test case, output the answer as an integer on a new line. If there is no way to select the dimensions of S
 so it fits in B, output 0.

Example
input
7
3 3 3 8
3 3 3 18
5 1 1 1
2 2 2 7
3 4 2 12
4 3 1 6
1800 1800 1800 4913000000

output
8
2
5
0
4
4
1030301
Note
For the first test case, it is optimal to choose S with side lengths 2, 2, and 2, which has a volume of 2⋅2⋅2=8. It can be shown there are 8 ways to put S inside B.

The coordinate with the least x, y, and z values for each possible arrangement of S are:

(0,0,0)
(1,0,0)
(0,1,0)
(0,0,1)
(1,0,1)
(1,1,0)
(0,1,1)
(1,1,1)
The arrangement of S with a coordinate of (0,0,0) is depicted below:

For the second test case, S with side lengths 2, 3, and 3 are optimal.

*/
#include <bits/stdc++.h>
using namespace std;

long long solve(long long x, long long y, long long z, long long k)
{
    long long count = 0;

    for (long long i = 1; i <= x; i++)
    {
        if (i * i > k)
            break; // Early break to prevent unnecessary iterations
        for (long long j = 1; j <= y; j++)
        {
            if (i * j > k)
                break; // Early break to prevent unnecessary iterations
            long long ModulusFlag = 0;
            long long RemainderFlag = 0;
            if (k % (i * j) == 0)
                ModulusFlag = 1;
            if (k / (i * j) <= z)
                RemainderFlag = 1;
            if (ModulusFlag && RemainderFlag)
            {
                long long lengthvalue = i;
                long long breadthvalue = j;
                long long heightValue = k / (i * j);
                long long distinctPlaces = (x - lengthvalue + 1);
                distinctPlaces *= (y - breadthvalue + 1);
                distinctPlaces *= (z - heightValue + 1);
                count = max(count, distinctPlaces);
            }
        }
    }
    return count;
}

int main()
{
    int test;
    cin >> test;
    for (int i = 0; i < test; i++)
    {
        long long x, y, z, k;
        cin >> x >> y >> z >> k;
        cout << solve(x, y, z, k) << endl;
    }
    return 0;
}
