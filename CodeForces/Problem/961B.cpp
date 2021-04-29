#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int len, k;
    cin >> len >> k;
    int sum = 0;

    vector<int> num(len);
    vector<int> sleep(len, 0);

    for(int& i : num)
        cin >> i;
    
    for(int i = 0; i < len; i++)
    {
        int tmp;
        cin >> tmp;

        if(tmp == 1)
            sum += num[i];
        else
            sleep[i] = num[i];
    }

    int cnt = 0;
    for(int i = 0; i < k; i++)
    {
        cnt += sleep[i];
    }

    int ans = sum + cnt;
    for(int i = k; i < len; i++)
    {
        cnt = cnt + sleep[i] - sleep[i-k];
        ans = max(sum+cnt, ans);
    }
    cout << ans;
    return 0;
    



}