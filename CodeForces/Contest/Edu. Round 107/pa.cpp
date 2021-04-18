#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int x = 0 ; x < t; x++)
    {
        int m, tmp;
        int cnt = 0;
        cin >> m;


        for(int i = 0; i < m; i++)
        {
            cin >> tmp;
            if(tmp == 1 || tmp == 3)
                cnt++;
        }
        cout << cnt << endl;
    }

}
