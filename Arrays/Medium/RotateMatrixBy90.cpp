// Rotate Matrix By 90 degrees

// Ex
// 1 2 3 4          
// 5 6 7 8  
// 9 10 11 12
// 13 14 15 16

// ans
// 13 9 5 1
// 14 10 6 2
// 15 11 7 3
// 16 12 8 4

// Brute Force Approach

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<vector<int>> ans (n,vector<int> (n,0));

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            ans[j][n-i-1] = matrix[i][j];
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

    vector<vector<int>> ans = rotate(matrix);

    for(auto arr : ans)
    {
        for(int i : arr)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    // T.C => O(n*n)
    // S.C => O(n*n)
    return 0;
}

// Optimal Approach

#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for(int i = 0; i < n- 1; ++i)  // O(n)
    {
        for(int j = i + 1; j < n; ++j)  // O(n/2)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
    }

    for(int i = 0; i < n; ++i)  // O(n)
    {
        reverse(matrix[i].begin(),matrix[i].end());  // O(n)
    }
}

int main()
{
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

    rotate(matrix);

    for(auto arr : matrix)
    {
        for(auto i : arr)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    // T.C => O(n*n/2) + O(n*n)
    // S.C => O(1)

    return 0;
}