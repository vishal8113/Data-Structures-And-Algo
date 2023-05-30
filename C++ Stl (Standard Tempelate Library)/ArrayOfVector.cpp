#include<bits/stdc++.h>
using namespace std;
// Function for printing a vector
void printVec(vector<int> v)
{
    for(int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main()
{
    // Declaration
    vector<int> v[10]; // 10 vectors of 0 size

    // Taking input
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        int n;
        cin >> n;
        for(int j = 0; j < n; ++j)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }

    // Output
    for(int i = 0; i < N; ++i)
    {
        printVec(v[i]);
    }


    return 0;
}