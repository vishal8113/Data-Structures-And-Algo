// Inbuilt implementation -> Hash Tables
// Time complexity - O(1)
// Unique values and elements are stored in non-sorted order

#include<bits/stdc++.h>
using namespace std;
int main()
{
    unordered_set<int> s;

    // Insertion
    s.insert(1);
    s.insert(2);

    // For output
    for(auto &item : s)
    {
        cout << item << endl;
    }
    return 0;
}