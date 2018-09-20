#include<iostream>
#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
int n;
int seq[750000];
queue<int> requests;
int temp = -1;

int binarySearch(int arr[], int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;
        if (arr[mid] == x)  return mid;
        if (arr[mid] > x) return binarySearch(arr, l, mid-1, x);
        return binarySearch(arr, mid+1, r, x);
   }
   return -1;
}

void input()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &seq[i]);

    while(temp != 0)
    {
        scanf("%d", &temp);
        if(temp == 0) continue;
        requests.push(temp);
    }
}

int main()
{
    input();
    int result;
    sort(seq,  seq + n);
    while(!requests.empty())
    {
        result = binarySearch(seq, 0, n - 1, requests.front());
        requests.pop();
        if(result == -1) printf("-1\n");
        else printf("%d\n", result + 1);
    }
}
