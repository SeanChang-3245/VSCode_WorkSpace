#include <iostream>
#include <cmath>
#include <list>

#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int colors;
    int q;
    cin >> colors >> q;


    list<int> card;

    int tmp;
    for(int i = 0; i < colors; i++)
    {
        cin >> tmp;
        card.push_back(tmp);
    }

    for(int i = 0; i < q; i++)
    {
        int ask;
        cin >> ask;

        auto it = card.begin();

        int cnt = 1;
        while(*it != ask)
        {
            ++it;
            ++cnt;
        }

        cout << cnt << ' ';

        card.push_front(*it);
        it = card.erase(it);
    }


}
