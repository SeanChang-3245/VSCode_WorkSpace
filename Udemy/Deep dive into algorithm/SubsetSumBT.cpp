#include <bits/stdc++.h>
using namespace std;

vector<bool> use;
vector<int> ans;

void sol(vector<int>& num, int k)
{
    if(k == 0)
    {
        for(int i : ans)
            cout << i << ' ';
        cout << endl;
        return;
    }

    for(int i = 0; i < num.size(); i++)
    {
        if(k - num[i] >= 0 && use[i] == false && (ans.empty() ||num[i] > *ans.rbegin()))
        {
            ans.push_back(num[i]);
            use[i] = true;
            sol(num, k - num[i]);
            use[i] = false;
            ans.erase(--ans.end());
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int len, k;
    cin >> len >> k;
    vector<int> num(len);

    use.resize(len);
    for(bool i : use) i = false;

    for(int& i : num) cin >> i;

    sol(num, k);
    return 0;

}