/*
D. Manhattan Circle

Given a n by m grid consisting of '.' and '#' characters, there exists a whole manhattan circle on the grid. The top left corner of the grid has coordinates (1,1), and the bottom right corner has coordinates (n,m).

Point (a,b) belongs to the manhattan circle centered at (h,k) if |h−a|+|k−b|<r, where r is a positive constant.

On the grid, the set of points that are part of the manhattan circle is marked as '#'. Find the coordinates of the center of the circle.

Input
The first line contains t (1≤t≤1000)  — the number of test cases.

The first line of each test case contains n and m (1≤n⋅m≤2⋅105) — the height and width of the grid, respectively.

The next n lines contains m characters '.' or '#'. If the character is '#', then the point is part of the manhattan circle.

It is guaranteed the sum of n⋅m over all test cases does not exceed 2⋅105, and there is a whole manhattan circle on the grid.

Output
For each test case, output the two integers, the coordinates of the center of the circle.

Example
input
6
5 5
.....
.....
..#..
.....
.....
5 5
..#..
.###.
#####
.###.
..#..
5 6
......
......
.#....
###...
.#....
1 1
#
5 6
...#..
..###.
.#####
..###.
...#..
2 10
..........
...#......

output
3 3
3 3
4 2
1 1
3 4
2 4
*/

#include <bits/stdc++.h>
using namespace std;

pair<int, int> solve(const vector<vector<char>> &arr, int n, int m)
{
    int firstRow = -1, lastRow = -1;
    int firstCol = -1, lastCol = -1;

    // Find the first and last rows containing '#'
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '#')
            {
                if (firstRow == -1)
                {
                    firstRow = i;
                }
                lastRow = i;
            }
        }
    }

    // Find the first and last columns containing '#'
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i][j] == '#')
            {
                if (firstCol == -1)
                {
                    firstCol = j;
                }
                lastCol = j;
            }
        }
    }

    // Calculating the center of the Manhattan circle
    int row = (firstRow + lastRow) / 2 + 1;
    int col = (firstCol + lastCol) / 2 + 1;

    return {row, col};
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> arr(n, vector<char>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        pair<int, int> res = solve(arr, n, m);
        cout << res.first << " " << res.second << endl;
    }
    return 0;
}