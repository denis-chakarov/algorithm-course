#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include<string.h>
using namespace std;

const int MAXN = 20000;

struct Edge
{
    int from;
    int to;
    int price;
    Edge( int f, int t, int p ) : from(f), to(t), price(p) {}
    bool operator<( const Edge& e ) const
    {
        return price > e.price;
    }
};


struct node
{
    int to;
    int price;
    node( int t, int p ) : to(t), price(p) {}
};

int N, M;
vector <node> graph[MAXN];

void input()
{
    scanf("%d %d", &N, &M);
    int f, t, p;
    for( int i = 0; i < M; i++ )
    {
        scanf("%d %d %d", &f, &t, &p);
        graph[f].push_back(node(t, p));
        graph[t].push_back(node(f, p));
    }

    for(int i = 0; i < N; i++)
    {
        graph[i].push_back(node(i, 0));
    }

}

int used[MAXN];
void prim()
{
    int total = 0;
    priority_queue <Edge> pq;
    for( int i = 0; i < graph[0].size(); i++ )
        pq.push(Edge(0, graph[0][i].to, graph[0][i].price));
    used[0] = 1;

    while( !pq.empty() )
    {
        int from = pq.top().from;
        int to = pq.top().to;
        int edgePrice = pq.top().price;
        pq.pop();
        if( used[from] && used[to] )
            continue;
        total += edgePrice;
        used[to] = 1;

        for( int i = 0; i < graph[to].size(); i++ )
        {
            int next = graph[to][i].to;
            int price = graph[to][i].price;
            if( !used[next] )
            {
                pq.push(Edge(to, next, price));
            }
        }
    }
    printf("%d\n", total);
}


int main()
{
    input();
    prim();

    return 0;
}
