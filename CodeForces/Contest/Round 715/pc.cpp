#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define endl '\n'

using namespace std;

struct x
{
    long long num;
    long long sum;
};

bool cmp(x l, x r)
{
    return l.sum < r.sum;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long m;
    cin >> m;

    vector<x> vec(m);

    int tmp;
    for(int i = 0; i < m; i++)
    {
        cin >> tmp;
        vec[i].num = tmp;
    }


    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            vec[i].sum += abs(vec[i].num - vec[j].num);
        }
    }


    sort(vec.begin(), vec.end(), cmp);


    long long maxx = vec[0].num;
    long long minn = vec[0].num;
    long long ans = 0;

    for(int i = 1; i < m; i++)
    {
        if(vec[i].num > maxx)
            maxx = vec[i].num;
        if(vec[i].num < minn)
            minn = vec[i].num;

        ans += maxx -minn;

    }

    cout << ans;

    return 0;

}
