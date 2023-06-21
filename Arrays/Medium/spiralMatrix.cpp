// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// 13 14 15 16

// spiral form -> 1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10

#include<bits/stdc++.h>
using namespace std;

vector<int> spiral(vector<vector<int>> &matrix){

    vector<int> ans;
    int n = matrix.size();
    int m = matrix[0].size();

    int top = 0;
    int left = 0;
    int bottom = n - 1;
    int right = m - 1;

    while(left <= right && top <= bottom)
    {
        for(int i = left; i <= right; ++i)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;

        for(int i = top; i <= bottom; ++i)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;

        if(top <= bottom)
        {
            for(int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        if(left <= right)
        {
            for(int i = bottom; i >= top; --i)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> matrix = {
        {1,2,3,4,5,6},
        {20,21,22,23,24,7},
        {19,32,33,34,25,8},
        {18,31,36,35,26,9},
        {17,30,29,28,27,10},
        {16,15,14,13,12,11}
    };

    vector<int> ans = spiral(matrix);

    for(int i : ans)
    {
        cout << i << " ";
    }

    return 0;
}