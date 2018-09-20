#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 50000;
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

int n, m, x, y;
vector <State> v[MAXN];

void input()
{
    scanf("%d %d %d %d", &n, &m, &x, &y);
    int a, b, c;
    for( int i = 0; i < m; i++ )
    {
        scanf("%d %d %d", &a, &b, &c);
        v[a-1].push_back(State(b-1, c));
        v[b-1].push_back(State(a-1, c));
    }
    //scanf("%d", &x - 1);
    //x - 1--;
}

int dist[MAXN];
bool used[MAXN];
int pred[MAXN];

void dijkstra()
{
    memset(dist, 63, sizeof(dist));
    MAX_VAL = dist[0];
    memset(pred, -1, sizeof(pred));
    used[x - 1] = 1;


    priority_queue <State> pq;
    for( int i = 0; i < v[x - 1].size(); i++ )
    {
        dist[v[x - 1][i].to] = v[x - 1][i].price;
        pred[v[x - 1][i].to] = x - 1;
        pq.push(State(v[x - 1][i].to, v[x - 1][i].price));
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

    for( int i = 0; i < n; i++ )
    {
        if( dist[i] == MAX_VAL  && i == y - 1)
            cout << -1;
        if(i == y - 1 && dist[i] < MAX_VAL){
            cout << dist[y - 1];
            break;
        }
    }
}

int main()
{
    input();
    dijkstra();

    return 0;
}
