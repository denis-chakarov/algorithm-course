#include <iostream>
#include <cstdio>
#include <vector>
#include<algorithm>
#include<string.h>
using namespace std;

struct State;
int N, M, K;
vector <State> v[1000];
int start;
struct State
{
    int to, price;
    State(int t, int p) : to(t), price(p) {}

};
void input()
{
    scanf("%d", &N);
    int x, y, w;
    for( int i = 0; i < N - 1; i++ )
    {
        scanf("%d %d %d", &x, &y, &w);
        v[x-1].push_back(State(y-1, w));
        v[y-1].push_back(State(x-1, w));
    }
}

bool used[1000];
int dist[1000];
void dfs( int i )
{
    used[i] = 1;
    for( int j = 0; j < v[i].size(); j++ )
    {
        if( !used[v[i][j].to] )
        {
            dist[v[i][j].to] = v[i][j].price + dist[i];
            dfs(v[i][j].to);
        }
    }


}

int main()
{
    input();
    int max = -2;
    int result[1000];
    //memset(dist, 0, sizeof(dist));

    for(int i = 0; i < N; i++)
    {
        dfs(i);
        int maxEl = *max_element(dist, dist + N);
        if(maxEl > max) max = maxEl;
        memset(dist, 0, sizeof(dist));
        memset(used,0,sizeof(used));
    }

    printf("%d\n", max);
    return 0;
}
