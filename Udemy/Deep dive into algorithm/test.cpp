#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
#define pii pair<int, int>

int main()
{
    int a = 3, b = 5;
    int *pa = &a, *pb = &b;

    cout << pa << ' ' << pb << endl;
    *pa = *pb;
    cout << pa << ' ' << pb;

}