#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;
int kravarnik[100000];

void input(int N, int K, int num)
{
    scanf("%d",&N);
    scanf("%d",&K);
    for(int i = 0; i < N; i++)
    {
        scanf("%d",&kravarnik[i]);
    }
    sort(kravarnik, kravarnik + N);
}
bool func1(int cows,int cabins, int d)
{
    int counter = 1;
    int tmp = kravarnik[0];
    for(int i = 1; i < cabins; i++)
    {
        if(kravarnik[i] - tmp >= d)
        {
            counter++;
            tmp = kravarnik[i];
        }

    }
    return counter >= cows;
}
int func2(int cows, int cabins)
{
    if (cows == 2)
        return kravarnik[cabins - 1] - kravarnik[0];

    int interval = kravarnik[1] - kravarnik[0];

    for (int i = 2 ; i != cabins ; i++)
    {

        interval = min(interval, kravarnik[i] - kravarnik[i-1]);
    }
    if(cows == cabins)
        return interval;

    else
    {
        int lowerbound = 1;
        int upperbound = (kravarnik[cabins - 1] - kravarnik[0]) / (cows - 2);
        while(upperbound - lowerbound > 1)
        {

            if(func1(cows, cabins, (upperbound + lowerbound) / 2))
            lowerbound  = (lowerbound + upperbound) / 2;
            else
            upperbound = (lowerbound + upperbound) / 2;
        }
        return lowerbound;
    }
}
int main()
{
    int N, K;
    int num;
    scanf("%d",&N);
    scanf("%d",&K);
    for(int i = 0; i < N; i++)
    {
        scanf("%d",&kravarnik[i]);
    }
    sort(kravarnik, kravarnik + N);
    cout << func2(K, N) << endl;
  return 0;
}
