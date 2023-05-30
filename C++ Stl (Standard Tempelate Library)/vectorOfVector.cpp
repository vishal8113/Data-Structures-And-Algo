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
    vector<vector<int>> v;

    // Taking input with th help of temp vector
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        int n;
        cin >> n;
        vector<int> temp; // creating a temp vector
        for(int j = 0; j < n; ++j)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }

    // Output
    for(int i = 0; i < N; ++i)
    {
        printVec(v[i]);
    }

    return 0;
}