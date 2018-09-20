#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 10000;

struct Edge
{
    int from, to, price;
    Edge( int f, int t, int p ) : from(f), to(t), price(p) {}
    bool operator<( const Edge& e ) const
    {
        return price > e.price;
    }
};


struct State
{
    int to, price;
    State( int t, int p ) : to(t), price(p) {}
};

int N, M;
vector <State> v[MAXN];

void input()
{
    scanf("%d %d", &N, &M);
    int f, t, p;
    for( int i = 0; i < M; i++ )
    {
        scanf("%d %d %d", &f, &t, &p);

        v[f-1].push_back(State(t-1, p));
        v[t-1].push_back(State(f-1, p));
    }
}

int used[MAXN];
void prim()
{
    priority_queue <Edge> pq;
    for( int i = 0; i < v[0].size(); i++ )
        pq.push(Edge(0, v[0][i].to, v[0][i].price));
    used[0] = 1;

    //cout << endl;

    int totalCost = 0;
    while( !pq.empty() )
    {
        int from = pq.top().from;
        int to = pq.top().to;
        int edgePrice = pq.top().price;
        pq.pop();
        if( used[from] && used[to] )
            continue;

        //cout << from+1 << " " << to+1 << " " << edgePrice << endl;

        used[to] = 1;
        totalCost += edgePrice;

        for( int i = 0; i < v[to].size(); i++ )
        {
            int next = v[to][i].to;
            int price = v[to][i].price;
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
