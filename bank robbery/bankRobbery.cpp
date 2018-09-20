#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

struct Combination
{
    int code1, code2, code3, code4, code5;
    Combination(int c1, int c2, int c3, int c4, int c5): code1(c1),code2(c2),code3(c3),code4(c4),code5(c5){}
    Combination() : code1(0), code2(0), code3(0), code4(0), code5(0){}

    bool operator==(const Combination& comb) const
    {
        return code1 == comb.code1 && code2 == comb.code2 && code3 == comb.code3 && code4 == comb.code4 && code5 == comb.code5;
    }
};

int n;
vector<Combination> combinations;
bool used[10][10][10][10][10];
Combination last;
int step[10][5] = {{1, 0, 0, 0, 0}, {-1, 0, 0, 0, 0}, {0, 1, 0, 0, 0}, {0, -1, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, -1, 0, 0},
                    {0, 0, 0, 1, 0}, {0, 0, 0, -1, 0}, {0, 0, 0, 0, 1}, {0, 0, 0, 0, -1}};
void input()
{
    for(int i = 0; i < 10; i++)
    for(int j = 0; j < 10; j++)
    for(int k = 0; k < 10; k++)
    for(int t = 0; t < 10; t++)
    for(int p = 0; p < 10; p++)
        used[i][j][k][t][p] = false;

    int temp1, temp2, temp3, temp4, temp5;
    char codes[5];
    scanf("%s", &codes);
    temp1 = codes[0] - '0';
    temp2 = codes[1] - '0';
    temp3 = codes[2] - '0';
    temp4 = codes[3] - '0';
    temp5 = codes[4] - '0';

    combinations.push_back(Combination(temp1, temp2, temp3, temp4, temp5));

    scanf("%s", &codes);
    last.code1 = codes[0] - '0';
    last.code2 = codes[1] - '0';
    last.code3 = codes[2] - '0';
    last.code4 = codes[3] - '0';
    last.code5 = codes[4] - '0';


    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%s", &codes);
        temp1 = codes[0] - '0';
        temp2 = codes[1] - '0';
        temp3 = codes[2] - '0';
        temp4 = codes[3] - '0';
        temp5 = codes[4] - '0';
        Combination comb(temp1, temp2, temp3, temp4, temp5);
        used[temp1][temp2][temp3][temp4][temp5] = true;
    }
}

void bfs()
{
    bool stop = false;
    queue<Combination> q;
    int c1, c2, c3, c4, c5;
    int level = 0;

    for(int i = 0; i < combinations.size(); i++)
    {
        c1 = combinations[i].code1;
        c2 = combinations[i].code2;
        c3 = combinations[i].code3;
        c4 = combinations[i].code4;
        c5 = combinations[i].code5;
        q.push(Combination(c1, c2, c3, c4, c5));
        used[c1][c2][c3][c4][c5] = true;
    }
    int br = q.size();
    while(!q.empty())
    {
        int c1, c2, c3, c4, c5;
        c1 = q.front().code1;
        c2 = q.front().code2;
        c3 = q.front().code3;
        c4 = q.front().code4;
        c5 = q.front().code5;

        q.pop();
        br--;

        for(int i = 0; i < 10; i++)
        {
            int new_c1 = c1 + step[i][0];
            int new_c2 = c2 + step[i][1];
            int new_c3 = c3 + step[i][2];
            int new_c4 = c4 + step[i][3];
            int new_c5 = c5 + step[i][4];

            if(new_c1 < 0) new_c1 = 9;
            if(new_c1 > 9) new_c1 = 0;

            if(new_c2 < 0) new_c2 = 9;
            if(new_c2 > 9) new_c2 = 0;

            if(new_c3 < 0) new_c3 = 9;
            if(new_c3 > 9) new_c3 = 0;

            if(new_c4 < 0) new_c4 = 9;
            if(new_c4 > 9) new_c4 = 0;

            if(new_c5 < 0) new_c5 = 9;
            if(new_c5 > 9) new_c5 = 0;

            Combination comb(new_c1, new_c2, new_c3, new_c4, new_c5);

            if(comb == last)
            {
                stop = true;
                break;
            }

            if(used[new_c1][new_c2][new_c3][new_c4][new_c5] == false)
            {
                used[new_c1][new_c2][new_c3][new_c4][new_c5] = true;
                q.push(comb);
            }
        }

        if(stop == true) break;
        if(br == 0)
        {
            br = q.size();
            level++;
        }
    }

    if(stop == false) cout << -1 << endl;
    else printf("%d\n", level + 1);
}


int main()
{
    input();
    bfs();

}
