#include<iostream>
#include <cstdio>
#include<algorithm>
using namespace std;

int K;
int a[12];
void input()
{
    scanf("%d", &K);

    for(int i = 0; i < 12; i++)
        scanf("%d", &a[i]);

}
int main()
{
    input();
    int counter = 0;
    int sum = 0;
    if(K == 0) cout << 0;
    else
    {
        sort(a, a + 12);
        int i = 11;
        while(sum < K && i > -1)
        {
            sum += a[i];
            i--;
            counter++;
        }
        if(sum < K) cout << -1;
        else cout << counter;
    }
}
