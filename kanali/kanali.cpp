#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include<string.h>
using namespace std;

const int MAXN = 1001;

struct Node
{
    int from, to, price;
    Node( int f, int t, int p ) : from(f), to(t), price(p) {}
    bool operator<( const Node& n ) const
    {
        return price < n.price;
    }
};


struct edge
{
    int to;
    int price;
    edge(int t, int p) : to(t), price(p) {}
};

int N, M, K;
vector <edge> graph[MAXN];
void input()
{
    scanf("%d %d", &N, &M);
    int f, t, p;
    for( int i = 0; i < M; i++ )
    {
        scanf("%d %d %d", &f, &t, &p);

        graph[f-1].push_back(edge(t-1, p));
        graph[t-1].push_back(edge(f-1, p));
    }
    scanf("%d", &K);
}

bool used[MAXN];
void prim()
{
    int counter = 0;
    memset(used, 0, sizeof(used));
    priority_queue <Node> pq;
    for( int i = 0; i < graph[0].size(); i++ )
        pq.push(Node(0, graph[0][i].to, graph[0][i].price));
    used[0] = 1;

    while( !pq.empty() )
    {
        int from = pq.top().from;
        int to = pq.top().to;
        int NodePrice = pq.top().price;
        pq.pop();
        if( used[from] && used[to])
            continue;
        used[to] = true;
        if(NodePrice < K)
        {
            counter++;
        }

        for(int i = 0; i < graph[to].size(); i++)
        {
            int next = graph[to][i].to;
            int price = graph[to][i].price;
            if(!used[next])
            {
                pq.push(Node(to, next, price));
            }
        }
    }
    printf("%d\n", counter);
}


int main()
{
    input();
    prim();

    return 0;
}
