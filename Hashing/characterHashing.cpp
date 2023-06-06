#include<bits/stdc++.h>
using namespace std;
int main()
{
    // For lowercase letters
    int hash[26];
    // int hash[256];

    string s;
    cin >> s;

    for(int i = 0; i < s.size(); ++i)
    {
        hash[s[i] - 'a']++;
       //  hash[s[i]]++; case of uppercase as well
    }

    int q;
    cin >> q;
    while(q--)
    {
        char c;
        cin >> c;
        cout << hash[c - 'a'] << endl;
        // cout << hash[c] << endl;
    }
    return 0;
}