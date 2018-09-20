#include <iostream>
#include <cstring>
#include <algorithm>
#include<stdio.h>

using namespace std;

int n, m;
int matrix[70][70];
int dyn[70][70][70];


void input()
{
    memset(dyn, -1, sizeof(dyn));
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        scanf("%d", &matrix[i][j]);
}

int algo(int x1, int y1, int x2){
    if(x1 >= n || x2 >= n || y1 >= m || x1 + y1 - x2 >= m)
        return 0;

    if(dyn[x1][y1][x2] != -1)
        return dyn[x1][y1][x2];

    int result = 0;
    if(x1 == x2 && y1 == x1 + y1 - x2)
        result += matrix[x1][y1];
    else
        result = result + matrix[x1][y1] + matrix[x2][x1 + y1 - x2];

    int res1, res2, res3, res4;
    res1 = algo(x1, y1 + 1, x2);
    res2 = algo(x1 + 1, y1, x2 + 1);
    res3 = algo(x1 + 1, y1, x2);
    res4 = algo(x1, y1 + 1, x2 + 1);

    result += max(res1, max(res2, max(res3, res4)));

    return dyn[x1][y1][x2] = result;
}


int main()
{
    input();
    int result = algo(0,0,0);
    printf("%d\n", result);
}
