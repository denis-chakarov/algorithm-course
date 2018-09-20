#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include<algorithm>
using namespace std;

const int MAXN = 10000;

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

int N, M, H;
int hospital;
vector <State> v[MAXN];
int hospitals[100];
void input()
{
    scanf("%d %d %d", &N, &M, &H);
    int f, s, d;
    for(int i = 0; i < H; i++)
    {
        scanf("%d", &hospital);
        hospitals[i] = hospital - 1;
    }
    sort(hospitals, hospitals + H);
    for( int i = 0; i < M; i++ )
    {
        scanf("%d %d %d", &f, &s, &d);
        v[f-1].push_back(State(s-1, d));
        v[s-1].push_back(State(f-1, d));
    }
}

int dist[MAXN];
bool used[MAXN];
int pred[MAXN];


int dijkstra(int start)
{
    int cost = 0;
    memset(dist,63, sizeof(dist));
    memset(pred, -1, sizeof(pred));
    memset(used, 0, sizeof(used));
    used[start] = 1;

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
        if( used[vertex])
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
    for( int i = 0; i < N; i++ )
    {
            cost += dist[i];
    }
    for(int i = 0; i < H; i++)
    {
        cost -= dist[hospitals[i]];
    }
    return cost;

}

int main()
{
    input();
    int min;
    int result[H + 1];
    int temp;

    for(int i = 0; i < H; i++)
    {
        result[i] = dijkstra(hospitals[i]);

    }
    min = *min_element(result, result + H);
   printf("%d\n", min);

}
