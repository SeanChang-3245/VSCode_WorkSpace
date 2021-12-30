#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>

#define MOD 998244353

using namespace std;



int main()
{

    string str;
    int num;
    stringstream ss;

    cin >> num;
    (ss << num);
    ss >> str;
    cout << str << endl;

    ss.clear();
    ss.str("");

    cin >> num;
    ss << num;
    str += ' ';
    ss >> str;
    cout << str;

    
}