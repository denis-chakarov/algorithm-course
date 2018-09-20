#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const short MAXN = 10000;

struct Edge
{
    short from, to, price;
    Edge( short f, short t, short p ) : from(f), to(t), price(p) {}
    bool operator<( const Edge& e ) const
    {
        return price > e.price;
    }
};


struct State
{
    short to, price;
    State( short t, short p ) : to(t), price(p) {}
};

int N, M, K;
vector <State> v[MAXN];

void input()
{
    scanf("%d %d %d", &N, &M, &K);
    int f, t, p;
    for( int i = 0; i < M; i++ )
    {
        scanf("%d %d %d", &f, &t, &p);

        v[f-1].push_back(State(t-1, p));
        v[t-1].push_back(State(f-1, p));
    }
    if(K != 0)
    {
        for(int i = 0; i < K; i++)
        {
            scanf("%d %d", &f, &t);
            v[f-1].push_back(State(t-1, 0));
            v[t-1].push_back(State(f-1, 0));
        }
    }
}

int used[MAXN];
void prim()
{
    priority_queue <Edge> pq;
    for( int i = 0; i < v[0].size(); i++ )
        pq.push(Edge(0, v[0][i].to, v[0][i].price));
    used[0] = 1;

    int totalCost = 0;
    while( !pq.empty() )
    {
        short from = pq.top().from;
        short to = pq.top().to;
        short edgePrice = pq.top().price;
        pq.pop();
        if( used[from] && used[to] )
            continue;

        used[to] = 1;
        totalCost += edgePrice;

        for( int i = 0; i < v[to].size(); i++ )
        {
            short next = v[to][i].to;
            short price = v[to][i].price;
            if( !used[next] )
            {
                pq.push(Edge(to, next, price));
            }
        }
    }
    printf("%d\n", totalCost);
}


int main()
{
    input();
    prim();

    return 0;
}
