// search in row wise and column wise sorted matrix

// Brute Force Approach
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> matrix = {
        {10,20,30,40},
        {11,21,36,43},
        {25,29,39,50},
        {50,62,70,80}
    };

    int target = 29;

    int n = matrix.size();
    int m = matrix[0].size();

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(matrix[i][j] == target)
            {
                cout << i << " " << j << endl;
                break;
            }
        }
    }
    return 0;

    // T.C => O(n^2)
    // S.C => O(1)
}

// Optimal Approach
#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> matrix = {
        {10,20,30,40},
        {11,21,36,43},
        {25,29,39,50},
        {50,62,70,80}
    };

    int target = 29;

    int n = matrix.size();
    int m = matrix[0].size();

    int i = 0;
    int j = m-1;

    while(i < n && j >= 0)
    {
        if(matrix[i][j] == target)
        {
            cout << i << " " << j << endl;
            break;
        }else if(matrix[i][j] > target)
        {
            j--;
        }else{
            i++;
        }
    }

    // T.C => log(N*M)
    // S.C => O(1)
    return 0;
}