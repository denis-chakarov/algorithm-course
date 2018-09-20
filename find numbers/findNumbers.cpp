#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main()
{
    int n, m, a, b, num;
    queue<int> result;
    cin >> n;
    vector<int> seq;
    for(int i = 0; i < n; i++)
    {
        cin >> num;
        seq.push_back(num);
    }
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        std::vector<int>::iterator low,up;
        low = lower_bound (seq.begin(), seq.end(), a);
        up = upper_bound (seq.begin(), seq.end(), b);
        result.push((int)(up - low));
    }
    while(!result.empty())
    {
        cout << result.front() << endl;
        result.pop();
    }
}
