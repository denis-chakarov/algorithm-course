#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include<string.h>
using namespace std;

const int MAXN = 10001;

struct Edge
{
    int from;
    int to;
    int price;
    char code;
    Edge( int f, int t, int p, char c ) : from(f), to(t), price(p), code(c) {}
    bool operator<( const Edge& e ) const
    {
        if(code == e.code) return price > e.price;
        return code < e.code;
    }
};


struct node
{
    int to;
    int price;
    char code;
    node( int t, int p, char c ) : to(t), price(p), code(c) {}
};

int N, M;
vector <node> graph[MAXN];

void input()
{
    scanf("%d %d", &N, &M);
    int f, t, p;
    char ch;
    for( int i = 0; i < M; i++ )
    {
        scanf("%d %d %d %c", &f, &t, &p, &ch);
        graph[f - 1].push_back(node(t - 1, p, ch));
        graph[t - 1].push_back(node(f - 1, p, ch));
    }
}

int used[MAXN];
void prim()
{
    int total = 0;
    priority_queue <Edge> pq;
    for( int i = 0; i < graph[0].size(); i++ )
        pq.push(Edge(0, graph[0][i].to, graph[0][i].price, graph[0][i].code));
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
            int vcode = graph[to][i].code;
            if( !used[next] )
            {
                pq.push(Edge(to, next, price, vcode));
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
