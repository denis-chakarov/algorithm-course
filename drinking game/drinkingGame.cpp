#include<iostream>
#include<queue>
#include<string>
#include<stdlib.h>
#include<cstdio>
using namespace std;

int main()
{
    priority_queue<int> a;
    string result = "";

    char func;
    int value;
    while(func != 'Q')
    {
        scanf("%c" ,&func);
        if(func == 'A')
        {
            cin >> value;
            a.push(value);
        }
        if(func == 'R')
        {
            if(a.empty()) result += "Not available\n";
            else{
                int temp = a.top();
                a.pop();
                result += to_string(temp);
                result += '\n';
            }
        }
        if(func == 'L')
        {
            if(a.empty()) result += "Not available\n";
            else{
                result += to_string(a.top());
                result += '\n';
            }
        }
    }
    cout << result;
}
