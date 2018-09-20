#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 10000;
int MAX_VAL;

struct State
{
    int to, price;
    State( int t, int p ): to(t), price(p) {}
    bool operator<( const State& s ) const
    {
        if( price == s.price )
            return to < s.to;
        return price > s.price;
    }
};

int N, M, K;
vector <State> v[MAXN];

void input()
{
    scanf("%d %d %d", &N, &M, &K);
    int x, y, w;
    for( int i = 0; i < M; i++ )
    {
        scanf("%d %d", &x, &y);
        v[x].push_back(State(y, 0));
        v[y].push_back(State(x, 0));
    }
    for(int i = 0; i < K; i++)
    {
        scanf("%d %d", &x, &y);
        v[x].push_back(State(y, 1));
        v[y].push_back(State(x, 1));
    }
}

int dist[MAXN];
bool used[MAXN];
int pred[MAXN];

void dijkstra(int start)
{
    memset(dist, 63, sizeof(dist));
    MAX_VAL = dist[0];
    memset(pred, -1, sizeof(pred));
    used[start] = 1;
    //dist[start] = 0;

    priority_queue <State> pq;
    for( int i = 0; i < v[start].size(); i++ )
    {
        dist[v[start][i].to] = v[start][i].price;
        pred[v[start][i].to] = start;
        pq.push(State(v[start][i].to, v[start][i].price));
    }

    while( !pq.empty() )
    {
        int vertex = pq.top().to;
        int price = pq.top().price;
        pq.pop();
        if( used[vertex] )
            continue;
        used[vertex] = 1;

        for( int i = 0; i < v[vertex].size(); i++ )
        {
            int curr_vertex = v[vertex][i].to;
            int curr_price = v[vertex][i].price;
            if( !used[curr_vertex] && dist[curr_vertex] > dist[vertex] + v[vertex][i].price )
            {
                dist[curr_vertex] = dist[vertex] + v[vertex][i].price;
                pred[curr_vertex] = vertex;
                pq.push(State(curr_vertex, dist[curr_vertex]));
            }
        }
    }
    if(dist[0] == MAX_VAL) printf("%d\n", -1);
    else printf("%d\n", dist[0]);
}

int main()
{
    input();
    dijkstra(N - 1);

    return 0;
}
