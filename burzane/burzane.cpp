#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include<string>
using namespace std;

const int MAXN = 1000;
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

int N, M, start = 0;
vector <State> v[MAXN];

void input()
{
    scanf("%d %d", &N, &M);
    int x, y, w;
    for( int i = 0; i < M; i++ )
    {
        scanf("%d %d %d", &x, &y, &w);
        v[x-1].push_back(State(y-1, w));
        v[y-1].push_back(State(x-1, w));
    }
    //scanf("%d", &start);
    //start--;
}

int dist[MAXN];
bool used[MAXN];
int pred[MAXN];
string result = "";
void print_path( int vertex )
{
    if( pred[vertex] == -1 )
    {
        printf("%d ", vertex+1);
        return;
    }
    print_path(pred[vertex]);
    ///printf("%d ", vertex+1);
    result += to_string(vertex + 1) + " ";
}

void dijkstra()
{
    memset(dist, 63, sizeof(dist));
    MAX_VAL = dist[0];
    memset(pred, -1, sizeof(pred));
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

    ///for( int i = 0; i < N; i++ )
        if( dist[N - 1] != MAX_VAL )
        {
            printf("%d\n", dist[N - 1]);
            print_path(N - 1);
            ///printf(" ");
        }
        result.pop_back();

        cout << result << endl;
}

int main()
{
    input();
    dijkstra();

    return 0;
}
