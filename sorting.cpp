#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;


int main()
{
    int n;
    int temp;
    int nums[100000];
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        nums[i] = temp;
    }
    sort(nums, nums + n);
    for(int i = 0; i < n - 1; i++)
    {
        cout << nums[i] << " ";
    }
    cout << nums[n - 1];
}
