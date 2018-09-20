#include<iostream>
#include<stdio.h>

using namespace std;

const int MAX = 100000;
int n, m;
int seq[MAX];
int delicious[MAX];

void input()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &seq[i]);

    scanf("%d", &m);
    for(int i = 0; i < m; i++)
        scanf("%d", &delicious[i]);

    for(int i = 1; i < n; i++)
        seq[i] += seq[i - 1];
}

int lowerBound(int value)
{
    int low = 0;
    int high = n - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (seq[mid] >= value)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}
int main()
{
    input();

    int index;

    for(int i = 0; i < m; i++)
    {
        index = lowerBound(delicious[i]);
        printf("%d\n", index + 1);
    }
}
