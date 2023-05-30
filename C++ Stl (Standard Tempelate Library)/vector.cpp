#include<bits/stdc++.h>
using namespace std;
int main()
{
    // declaration of vector
    vector<int> v;

    // Taking input in vector
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        int x;
        cin >> x;
        v.push_back(x);  // push_back used for pushing the element in vector
    }

    // Output in Vector
    for(int i = 0; i < N; ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}