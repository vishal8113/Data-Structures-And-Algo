// Inbuilt implementation -> Red Black tress
// keys Stored in a sorted manner
// Time complexity of insertion,deletion,find and other operations(log n)
// Duplicate key was not allowed

#include<bits/stdc++.h>
using namespace std;
int main()
{
    // Declaration
    map<int,string> m;

    Insertion
    m[1] = "abc"
    m[2] = "cde"
    m[3] = "efg"

    // Another way for insertion
    // m.insert(6,"vishal");

    // Taking Input
    // int N;
    // cin >> N;
    // for(int i = 0; i < N; ++i)
    // {
    //     int a;
    //     cin >> a;
    //     string s;
    //     cin >> s;
    //     m.insert({a,s});
    // }

    // Printing Output
    // Declaring iterator
    map<in<t,string> :: iterator it;

    for(it = m.begin(); it != m.end(); ++it)
    {
        cout << (it -> first) << " " << (it -> second) << endl;
    }

    // short way to iterate
    // for(auto &pr : m)
    // {
    //     cout << pr.first << " " << pr.second << endl;
    // }

    // find operation
    // find() -> returns the iterator

    auto it = m.find(3);
    if(it == m.end())
    {
        cout << "No Value" << endl;
    } else {
        cout << (*it).first << " " << (*it).second << endl;
    }

    // m.clear() -> clear the map
    // m.erase(3) -> remove the element(Take key or iterator as parameter)

    return 0;
}