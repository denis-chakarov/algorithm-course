#include<iostream>
#include<math.h>
using namespace std;

void qSort(int* a, int n)
{
    int i = 0, j = n - 1;
    int x = a[j / 2], y;
    do
    {
        while(a[i] < x) i++;
        while(a[j] > x) j--;
        if(i < j)
        {
            y = a[i]; a[i] = a[j]; a[j] = y;
            i++; j--;
        }
        else
            if(i == j)
        {
            i++;
            j--;
        }
    }while(i <= j);
    if(j > 0) qSort(a, j + 1);
    if(i < n - 1) qSort(a + i, n - i);
}

int main()
{
    int N; cin >> N;
    int number;
    int a[N + 2];

    for(int i = 0; i < N; i++)
    {
            cin >> number;
            a[i] = number;
    }

    qSort(a,N);

    for(int i = 0; i < N - 1; i++)
    {
        cout << a[i] << " ";
    }
    cout << a[N-1];

    return 0;
}
