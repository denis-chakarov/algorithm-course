#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

int N;
int seq[100000];
int k;
int result[100000];
void input()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &seq[i]);
    k = *max_element(seq, seq + N);
}


void countingSort(int len, int result[])
{
    int counter[k + 1];
    for(int i = 0; i <= k; i++)
    {
        counter[i] = 0;
    }
    for(int j = 0; j < len; j++)
    {
        counter[seq[j]]++;
    }
    for(int i = 1; i <= k; i++)
    {
        counter[i] += counter[i - 1];
    }
    for(int j = 0; j < len; j++)
    {
        result[counter[seq[j]]] = seq[j];
        counter[seq[j]]--;
    }
}



double median(int index)
{
    memset(result,0, sizeof(int));
    int len = index + 1;
    if(index == 0) return (double)seq[0];
    if(index == 1) return (double)(seq[0] + seq[1]) / 2;
    ///sort(seq, seq + len);
    countingSort(len, result);
    for(int i = 0; i < len; i++)
    {
        seq[i] = result[i + 1];
    }
    if((index + 1) % 2 == 0)
    {
        int first = (index + 1) / 2;
        return (double)(seq[first] + seq[first - 1]) / 2;
    }
    else
    {
        return (double)seq[(index + 1) / 2];
    }

}

int main()
{
    input();

    for(int i = 0; i < N - 1; i++)
    {
        printf("%.1f ", median(i));
    }
    printf("%.1f", median(N - 1));

}
