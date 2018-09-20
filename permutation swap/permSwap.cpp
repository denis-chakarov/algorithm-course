#include <iostream>
#include <cstdio>
using namespace std;

int N, a[2000000];
long long inversions;

void input()
{
    scanf("%d", &N);
    for( int i = 0; i < N; i++ )
        scanf("%d", &a[i]);
}
int b[2000000];
void Merge( int left, int right )
{
    int k = 0;
    int mid = (left+right)/2;
    int i = left, j = mid+1;
    while( i <= mid && j <= right )
    {
        if( a[i] < a[j] )
            b[k++] = a[i++];
        else
        {
            b[k++] = a[j++];
            inversions += (long long)(mid-i+1);
        }
    }
    while( i <= mid )
        b[k++] = a[i++];
    while( j <= right )
        b[k++] = a[j++];

    for( int i = left; i <= right; i++ )
        a[i] = b[i-left];
}

void mergeSort( int left, int right )
{
    if( right-left <= 0 )
        return;
    if( right-left == 1 )
    {
        if( a[left] > a[right] )
        {
            swap(a[left], a[right]);
            inversions++;
        }
        return;
    }

    int mid = (left+right)/2;
    mergeSort(left, mid);
    mergeSort(mid+1, right);

    Merge(left, right);
}

void print()
{

    printf("%lld\n", inversions);
}

int main()
{
    input();
    mergeSort(0, N-1);
    print();

    return 0;
}
