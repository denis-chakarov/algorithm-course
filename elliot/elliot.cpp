#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;

int n,k,q;

int LowerBound(long long *arr, long long value)
{
    int low = 0;
    int high = n - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] >= value) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    scanf("%d %d %d",&n,&k,&q);

    int prices[n];
    long long quantities[q];
        long long sum=0;
    int  numbers;
    int i=0;
    while (i<n){
        scanf("%d",&numbers);
        prices[i]=numbers;
        i++;
    }

    long long prices2[n-k+1];
    //memset(prices2, 0, sizeof(prices2));
    short j=0;
    i=0;

        while(i<k)
        {
                sum += prices[i];
                i++;
        }
        i=0;
        while(i<=n-k)
        {
                prices2[i] = sum;
                if (i < n-k)
                {
                        sum = sum- prices[i] + prices[i + k];
                }
                if (i>0)
                {
                        if (prices2[i - 1]>prices2[i])
                                prices2[i] = prices2[i - 1];
                }
                i++;
        }

    j=0;
    long long quantity;
    int result=-1;
    while (j<q){
        scanf("%lld",&quantity);
        quantities[j]=quantity;
        j++;
    }

    for(i=0;i<q;i++)
    {
        result=LowerBound(prices2,quantities[i]);
        if(result>=n-k+1)
            printf("%d\n",-1);
        else
            printf("%d\n",result);
    }
}
