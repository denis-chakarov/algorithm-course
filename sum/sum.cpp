#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;


int N, M;
int A[1000000];
int seq[10];
void input()
{
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    for(int i = 0; i < M; i++)
        scanf("%d", &seq[i]);
}

void algo()
{
    sort(A, A + N);
    int first;
    int last;
    bool temp;
    for(int i = 0; i < M; i++)
    {
        first = 0;
        last = N - 1;
        temp = false;
        while(first != last)
        {
            if(A[first] + A[last] > seq[i])
            {
                last--;
            }
            else if(A[first] + A[last] < seq[i])
            {
                first++;
            }
            else if(A[first] + A[last] == seq[i])
            {
                temp = true;
                break;
            }
        }
        if(temp == true) printf("YES\n");
        else printf("NO\n");
    }
    //cout << result;
}

int main()
{
    input();
    algo();
}
