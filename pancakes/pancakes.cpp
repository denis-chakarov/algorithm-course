#include<iostream>
#include <cstdio>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;
int main()
{
    int T, N, K;
    scanf("%d", &T);
    struct info
    {
        pair<int,int> p;
        vector<long> seq;
    };
    info elements[T];
    for(int i = 0; i < T; i++)
    {
        scanf("%d%d", &N, &K);
        elements[i].p.first = N;
        elements[i].p.second = K;
        for(int j = 0; j < elements[i].p.first; j++)
        {
            long num;
            scanf("%ld", &num);
            elements[i].seq.push_back(num);
        }
        sort(elements[i].seq.begin(), elements[i].seq.end());

    }

    for(int i = 0; i < T ; i++)
    {
        cout << elements[i].seq[elements[i].p.second - 1] << endl;
    }
}
