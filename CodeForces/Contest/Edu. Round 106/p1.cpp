#include <iostream>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int x = 0; x < t; x++)
    {
        int k1, k2, w, b, n;
        cin >> n >> k1 >> k2 >> w >> b;

        if(k1 + k2 < w * 2 || 2*n - k1 - k2 < 2 *b)
        {
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
    }


}
