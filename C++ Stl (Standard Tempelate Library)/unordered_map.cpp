// Inbuilt implementation -> Hash table
// Insertion and deletion complexity - O(1)
// keys not stored in sorted order

#include<bits/stdc++.h>
using namespace std;
int main()
{
    // Declaration
    unordered_map<int,string> m;

    m[1] = "ABC";
    m[2] = "CDE";

    for(auto &pr : m)
    {
        cout << pr.first << " " << pr.second << endl;
    }

    return 0;
}