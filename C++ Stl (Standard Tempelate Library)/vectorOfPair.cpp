#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<pair<int,int> > v_p; // Declaration

    // Taking input
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        int x,y;
        cin >> x >> y;
        v_p.push_back({x,y});
    }

    // Declaring Iterator
    vector<pair<int,int>> :: iterator it;

    // For Output
    for(it = v_p.begin(); it != v_p.end(); it++)
    {
        // cout << (*it).first << " " << (*it).second << endl;<
        // Another way
        cout << (it -> first) << " " << (it -> second) << endl;
    }

    return 0;
}