// Inbuilt implementation -> Red Black trees
// Insertion and deletion complexity - O(log n)
// keys are stored in sorted order
// Keys are not required to be unique

#include<bits/stdc++.h>
using namespace std;
int main()
{
    multimap<int,string> m;

    m[1] = "ABC";
    m[1] = "CDE";

    for(auto &pr : m)
    {
        cout << pr.first << " " << pr.second << endl;
    }
    return 0;
}
