// Set Matrix Zeroes

Input

// 1 1 1 1
// 1 0 0 1
// 1 1 0 1
// 1 1 1 1

output 

// 1 0 0 1
// 0 0 0 0 
// 0 0 0 0
// 1 0 0 1

// Brute Force Approach

#include<bits/stdc++.h>
using namespace std;

void markRow(vector<vector<int>> &matrix,int n,int m,int i);
void markColumn(vector<vector<int>> &matrix,int n,int m,int j);
vector<vector<int>> setZeroes(vector<vector<int>> &matrix);

void markRow(vector<vector<int>> &matrix,int n,int m,int i)
{
    for(int j = 0; j < m; ++j)
    {
        if(matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}

void markColumn(vector<vector<int>> &matrix,int n,int m,int j)
{
    for(int i = 0; i < n; ++i)
    {
        if(matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}

vector<vector<int>> setZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(matrix[i][j] == 0)
            {
                markRow(matrix,n,m,i);
                markColumn(matrix,n,m,j);
            }
        }
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

int main()
{
    vector<vector<int>> matrix = {{1,1,1,1},{1,0,0,1},{1,1,0,1},{1,1,1,1}};

    vector<vector<int>> ans = setZeroes(matrix);

    for(auto ele : ans)
    {
        for(int k : ele)
        {
            cout << k << " ";
        }
        cout << endl;
    }

    // T.C => O((N*M)*(N + M)) + O(N*M)
    // S.C => O(1)

    return 0;
}

// Better Approach

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {

    int row[n] = {0}; 
    int col[m] = {0}; 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                row[i] = 1;

                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);

    
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << endl;
    }

    // T.C => O(2*(N*M))
    // S.C => O(N) + O(M)
    return 0;
}


// Optimal Approach

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {

    // int row[n] = {0}; --> matrix[..][0]
    // int col[m] = {0}; --> matrix[0][..]

    int col0 = 1;
    // step 1: Traverse the matrix and
    // mark 1st row & col accordingly:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // mark i-th row:
                matrix[i][0] = 0;

                // mark j-th column:
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] != 0) {
                // check for col & row:
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    //step 3: Finally mark the 1st col & then 1st row:
    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

    return matrix;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);

    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << endl;
    }

    // T.C => O(2*(N*M))
    // S.C => O(1)
    return 0;
}
