// Inbuilt implementation -> Red Black tress
// Time complexity - O(log n)
// Unique values and elements are stored in sorted order

#include<bits/stdc++.h>
using namespace std;
int main()
{
    // Declaration
    set<int> s;

    // Insertion
    s.insert(1);
    s.insert(2);

    //Taking input
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        int k;
        cin >> k;
        s.insert(k);
    }

    auto it = s.find(1); // returns an iterator
    if(it == s.end())
    {
        cout << "No value" << endl;
    } else {
        cout << (*it) << endl;
    }

    // For Output
    for(auto &item : s)
    {
        cout << item << endl;
    }

    // s.erase() -> For removing an element
    // s.clear() -> For clearing the set
    return 0;
}