#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int lis( long long int arr[], int n )
{
    int *lis, i, j, max = 0;
    lis = (int*) malloc ( sizeof( long long int ) * n );

    /* Initialize LIS values for all indexes */
    for (i = 0; i < n; i++ )
        lis[i] = 1;

    /* Compute optimized LIS values in bottom up manner */
    for (i = 1; i < n; i++ )
        for (j = 0; j < i; j++ )
            if ( arr[i] % arr[j] == 0 && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;

    /* Pick maximum of all LIS values */
    for (i = 0; i < n; i++ )
        if (max < lis[i])
            max = lis[i];

    /* Free memory to avoid memory leak */
    free(lis);

    return max;
}

/* Driver program to test above function */
int main()
{

   int n;
   cin >> n;
   long long int arr[n];
   long long int element;
   for(int i = 0; i < n; i++)
   {
       cin >> element;
       arr[i] = element;
   }
   int m = sizeof(arr)/sizeof(arr[0]);
   printf("%ld\n", lis( arr, m ) );
   return 0;
}
