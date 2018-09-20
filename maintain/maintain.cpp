#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include<string.h>
#include<set>
using namespace std;

const int MAXN = 200;

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

int N, W;
vector <State> graph[MAXN];
queue<int> result;
set<int> vertices;

bool used[MAXN];
void prim()
{
    memset(used, 0, sizeof(used));
    priority_queue <Edge> pq;
    for( int i = 0; i < graph[0].size(); i++ )
        pq.push(Edge(0, graph[0][i].to, graph[0][i].price));
    used[0] = 1;

    int totalCost = 0;
    while( !pq.empty() )
    {
        int from = pq.top().from;
        int to = pq.top().to;
        int edgePrice = pq.top().price;
        pq.pop();
        if( used[from] && used[to] )
            continue;

        used[to] = 1;
        totalCost += edgePrice;

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
    bool temp = true;
    for(int i = 0; i < N; i++)
    {
        if(!used[i])
        {
            temp = false;
            break;
        }
    }
    if(temp == false) result.push(-1);
    else result.push(totalCost);
}

void input()
{
    scanf("%d %d", &N, &W);
    int f, t, p;
    for( int i = 0; i < W; i++ )
    {
        scanf("%d %d %d", &f, &t, &p);

        graph[f-1].push_back(State(t-1, p));
        graph[t-1].push_back(State(f-1, p));
        vertices.insert(t - 1);
        vertices.insert(f - 1);
        if(vertices.size() < N) result.push(-1);
        else prim();
    }
}

int main()
{
       input();
       while(!result.empty())
       {
           printf("%d\n", result.front());
           result.pop();
       }

    return 0;
}
