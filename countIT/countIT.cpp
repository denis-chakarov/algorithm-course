#include<iostream>
#include <stdio.h>
#include<algorithm>
using namespace std;

int N;
int seq[1000000];

void input()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &seq[i]);
    sort(seq, seq + N);
}




int main()
{
    input();
    int counter = 1;
    int current = seq[0];
    bool in = false;
    for(int i = 1; i < N; i++)
    {
        if(current == seq[i]) counter++;
        else
        {
            in == true;
            printf("%d %d\n",seq[i - 1], counter);
            counter = 1;
            current = seq[i];
        }
    }
    if(in == false) printf("%d %d\n", current, counter);
}
