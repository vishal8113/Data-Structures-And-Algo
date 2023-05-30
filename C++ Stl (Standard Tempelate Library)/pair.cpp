#include<bits/stdc++.h>
using namespace std;
int main()
{
    pair <int,string> p; // declaration syntax of pair

    // Taking input in pairs
        int a;
        cin >> a;
        string s;
        cin >> s;
        // p = {a,s} // one way to take input in pair
        p = make_pair(a,s); // Another way to take inout in pair

    // Printing Output
        cout << p.first << " " << p.second << endl;

    return 0;
}