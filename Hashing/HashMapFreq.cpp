#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<int,int> mp;

    // Taking inputs
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }

    // for(auto it : mp)
    // {
    //     cout << it.first << " " << it.second << endl;
    // }

    int q;
    cin >> q;
    while(q--)
    {
        int x;
        cin >> x;
        cout << mp[x] << endl;
    }


    return 0;
}