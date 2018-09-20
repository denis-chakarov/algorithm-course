#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 512;
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

int N;
unsigned long long  M, Q;

vector <State> v[MAXN];
vector<pair<int,int> > requests;
void input()
{
    int first, second;
    scanf("%d %lld", &N, &M);
    int x, y;
    unsigned long long w;
    for( int i = 0; i < M; i++ )
    {
        scanf("%d %d %lld", &x, &y, &w);
        v[x].push_back(State(y, w));
       // v[y].push_back(State(x, w));
    }
    scanf("%lld", &Q);
    for( int i = 0; i < Q; i++ )
    {
        scanf("%d %d", &first, &second);
        requests.push_back(make_pair(first, second));
    }
}

unsigned long long dist[MAXN];
bool used[MAXN];
int pred[MAXN];


void dijkstra(int from, int ends)
{
    memset(dist, 63, sizeof(dist));
    MAX_VAL = dist[0];
    memset(pred, -1, sizeof(pred));
    memset(used, 0, sizeof(used));
    used[from] = 1;
    dist[from] = 0;

    priority_queue <State> pq;
    for( int i = 0; i < v[from].size(); i++ )
    {
        dist[v[from][i].to] = v[from][i].price;
        pred[v[from][i].to] = from;
        pq.push(State(v[from][i].to, v[from][i].price));
    }

    while( !pq.empty() )
    {
        int vertex = pq.top().to;
        int price = pq.top().price;
        if(vertex == ends) break;
        pq.pop();
        if( used[vertex] ){
            continue;
        }
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
    if(dist[ends] > MAX_VAL) printf("unreachable\n");
    else printf("%lld\n", dist[ends]);
}

int main()
{
    input();
    for(vector<pair<int, int> >::iterator it = requests.begin(); it!= requests.end(); ++it)
    {
        if(it->first == it->second) printf("%d\n", 0);
        else dijkstra(it->first, it->second);
    }

    return 0;
}
