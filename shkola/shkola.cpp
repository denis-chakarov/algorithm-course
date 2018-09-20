#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int N, M;
vector <int> v[500];
int start;
int counter = 0;
void input()
{
    scanf("%d %d", &N, &M);
    int x, y;
    for( int i = 0; i < M; i++ )
    {
        scanf("%d %d", &x, &y);
        v[x-1].push_back(y-1);
        v[y-1].push_back(x-1);
    }
}

bool used[500];
void dfs( int i )
{
    ///counter++;
    used[i] = 1;
    for( int j = 0; j < v[i].size(); j++ )
        if( !used[v[i][j]] )
        dfs(v[i][j]);
}

int main()
{
    input();
    //dfs(start-1);
    for(int i = 0; i < N; i++)
    {
        if(!used[i])
        {
            counter++;
            dfs(i);
        }
    }
    cout << counter << endl;

    return 0;
}
