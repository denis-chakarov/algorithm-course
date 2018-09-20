#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<map>
#include<vector>

const int cap  = 1000000;
using namespace std;

bool sortFunc(pair<string,string> s1, pair<string,string> s2)
{
    return lexicographical_compare(s1.second.begin(),s1.second.end(),s2.second.begin(),s2.second.end());
}
pair<string,string> names[50];
int n;
char cname[cap];
void input()
{
    string sname;
   // pair<string,string> p;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%s", &cname);
        string name(cname);
        sname = name;
        sort(sname.begin(), sname.end());
        //names[name] = sname;
        //p.first = name;
        //p.second = sname;
        names[i] = make_pair(name, sname);
    }
}

int main()
{
    input();
    stable_sort(names, names + n,sortFunc);
    for(int i = 0; i < n; i++)
    {
        printf("%s\n", names[i].first.c_str());
    }

}
