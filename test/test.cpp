#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int ans = 0;
void sol(vector<int> &person, vector<bool> &use, int cnt)
{
    if(cnt == 5)
    {
        if(person[0] >= 2 && person[1] >= 2)
            ans++;
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (use[j] == false)
            {
                use[j] = true;
                person[i]++;
                sol(person, use, cnt+1);
                person[i]--;
                use[j] = false;
            }
        }
    }
}

int main()
{
    vector<int> person(3);
    vector<bool> use(5, false);

    sol(person, use, 0);
    cout << ans;
}