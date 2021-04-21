#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>

#define endl '\n'

using namespace std;


string max(string& s1, string& s2)
{
    if(s1.size() > s2.size())
        return s1;
    return s2;
}

string trace_with_string(string str1, string str2)
{
    int s1 = str1.size(), s2 = str2.size();

    vector<vector<string>> table(s1+1, vector<string>(s2+1, ""));

    for(int i = 0; i <= s1; i++)
    {
        for(int j = 0; j <= s2; j++)
        {
            if(i * j == 0)
                continue;

            if(str1[i-1] == str2[j-1])
                table[i][j] = table[i-1][j-1] + str1[i-1];
            else
                table[i][j] = max(table[i-1][j], table[i][j-1]);
        }

    }

    return table[s1][s2];
}


string trace_with_cnt(string str1, string str2)
{
    string ans;
    int s1 = str1.size(), s2 = str2.size();

    vector<vector<int>> table(s1+1, vector<int>(s2+1, 0));

    for(int i = 0; i <= s1;  i++)
    {
        for(int j = 0; j <= s2; j++)
        {
            if(i * j == 0)
                continue;

            if(str1[i-1] == str2[j-1])
                table[i][j] = table[i-1][j-1] + 1;
            else
                table[i][j] = max(table[i-1][j], table[i][j-1]);


        }

    }

    int i = s1, j = s2;

    while(1)
    {
        if (i == 0 || j == 0)
            break;

        if(str1[i-1] == str2[j-1])
        {
            ans += str1[i-1];
            --i;
            --j;
        }
        else
        {
            if(table[i-1][j] > table[i][j-1])
                --i;
            else
                --j;
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int tabulation(string str1, string str2)
{
    int len1 = str1.size();
    int len2 = str2.size();

    vector<vector<int>> table(len1+1, vector<int>(len2+1, 0));


    for(int i = 0; i <= len1; i++)
    {
        for(int j = 0; j <= len2; j++)
        {
            if(i * j == 0)
                table[i][j] = 0;
            else
            {
                if(str1[i-1] == str2[j-1])
                {
                    table[i][j] = 1 + table[i-1][j-1];
                }
                else
                {
                    table[i][j] = max(table[i][j-1], table[i-1][j]);
                }
            }
        }
    }
    return table[len1][len2];

}

int memoization(string& str1, string& str2, int i, int j)
{
    static int len1 = str1.size(), len2 = str2.size();
    static vector<vector<int>> table(len1+1, vector<int>(len2+1, -1));

    if(i * j == 0)
        return 0;
    
    if(table[i][j] != -1)
        return table[i][j];

    if(str1[i-1] == str2[j-1])
    {
        return table[i][j] = 1 + memoization(str1, str2, i-1, j-1);
    }
    else
    {
        return table[i][j] = max(memoization(str1, str2, i-1, j), memoization(str1, str2, i, j-1));
    }



}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str1, str2, ans;
    cin >> str1 >> str2;

    cout << trace_with_cnt(str1, str2).size() << endl;

    cout << tabulation(str1, str2) << endl;
    cout << memoization(str1, str2, str1.size(), str2.size());

    return 0;
    system("pause");



}
