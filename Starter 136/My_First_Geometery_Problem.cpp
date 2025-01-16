/*
## Problem Statement: My First Geometry Problem

You are on a 2-dimensional grid, starting at \((0,0)\). You are given a binary string \(S\) of length 4 where:

- \(S_1\) refers to the left direction;
- \(S_2\) refers to the right direction;
- \(S_3\) refers to the up direction;
- \(S_4\) refers to the down direction.

\(S_i = 1\) denotes that you are allowed to move in the respective direction, and \(S_i = 0\) denotes that you are not allowed to move in that direction.

Your task is to find the number of cells \((x, y)\) you can possibly visit which satisfy \(-10 \leq x, y \leq 10\).

### Note:
- You always include the cell \((0,0)\) in your count.
- If you can visit cells \((A_1, B_1)\) and \((A_2, B_2)\) individually, but not both at the same time, you still include both of them in your count.
- Moves are defined as:
  - A move in the left direction is a move from cell \((A, B)\) to \((A-1, B)\).
  - A move in the right direction is a move from cell \((A, B)\) to \((A+1, B)\).
  - A move in the up direction is a move from cell \((A, B)\) to \((A, B+1)\).
  - A move in the down direction is a move from cell \((A, B)\) to \((A, B-1)\).

### Input Format:
- The first line of input will contain a single integer \(T\), denoting the number of test cases.
- Each test case consists of a binary string \(S\) of length 4, denoting the directions in which moves are allowed.

### Output Format:
For each test case, output on a new line, the number of cells you can visit as mentioned in the statement.

### Constraints:
- \(1 \leq T \leq 15\)
- \(|S| = 4\)
- \(S_i \in \{0,1\}\)
- \(S_i = 1\) for at least one \(1 \leq i \leq 4\).

### Sample Input:
```
5
0010
1100
0110
1110
1111
```

### Sample Output:
```
11
21
121
231
441
```

### Explanation:
**Test case 1**: The only allowed direction is up. Thus, you can only visit cells \((0,0)\), \((0,1)\), \((0,2)\), ..., \((0,10)\), which are a total of 11 cells.

**Test case 2**: The allowed directions are left and right. Thus, you can visit cells \((-10,0)\), \((-9,0)\), ..., \((0,0)\), ..., \((9,0)\), \((10,0)\), which are a total of 21 cells.

**Test case 3**: The allowed directions are right and up. You can visit all cells \((x, y)\) such that \(x \geq 0\) and \(y \geq 0\), which are a total of 121 cells.
*/

#include<bits/stdc++.h>

using namespace std;

int count(string &str){
    int count=0;
    for(char c:str){
        if(c=='1') count++;
    }

    if(count==0) return 0;
    else if(count==1) return 11;
    else if((count==2 && str[0]=='1' && str[1]=='1') || (count==2 && str[1]=='1' && str[2])) return 21;
    else if(count==3) return 231;
    else if (count==4) return 441;
    else return 121;
}

int main(){
    int test;
    cin >> test;
    for(int i=0;i<test;i++){
        string str;
        cin >> str;
        cout<<count(str)<<endl;
    }
}