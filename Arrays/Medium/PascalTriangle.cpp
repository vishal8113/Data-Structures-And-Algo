// 1                        1
// 2                     1      1
// 3                 1      2       1  
// 4              1     3       3      1
// 5           1     4      6       4      1
// 6        1     5      10     10      5      1                 

// 3types of questions:
// 1) find the element at given row and column
// 2) print the nth row
// 3) print the whole pascal triangle

// 1)
#include<bits/stdc++.h>
using namespace std;
int ncr(int n,int r)
{
    int res = 1;
    for(int i = 0; i < r; ++i)  // O(r)
    {
        res = res * (n-i);
        res = res/(i+1);
    }

    return res;
}
int main()
{
    int n = 6;
    int r = 5;
    cout << ncr(n-1,r-1);
    return 0;

    // T.C => O(r)
    // S.C => O(1)
}

// 2)
// Brute Force

#include<bits/stdc++.h>
using namespace std;
int ncr(int n,int r)
{
    int res = 1;
    for(int i = 0; i < r; ++i)  // O(r)
    {
        res = res * (n-i);
        res = res/(i+1);
    }

    return res;
}
int main()
{
    int n = 5;
    for(int c = 1; c <= n; ++c)  // O(n)
    {
        cout << ncr(n-1,c-1) << " ";
    }

    // T.C => O(n*r)
    // S.C => O(1)
    return 0;
}

// Optimal Solution

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 8;
    int ans = 1;
    cout << ans << " ";
    for(int i = 1; i < n; ++i)  // O(n)
    {
        ans = ans * (n-i);
        ans = ans / i;
        cout << ans << " ";
    }

    // T.C => O(n)
    // S.C => O(1)
    return 0;
}


// 3)

#include<bits/stdc++.h>
using namespace std;
vector<int> generateRow(int row)
{
    int ans = 1;
    vector<int> ans_row;
    ans_row.push_back(ans);
    for(int col = 1; col < row; ++col) // O(n)
    {
        ans = ans * (row - col);
        ans = ans/col;
        ans_row.push_back(ans);
    }

    return ans_row;
}
int main()
{
    vector<vector<int>> ans;
    int n = 8;
    for(int i = 1; i <= n; ++i) // O(n)
    {
        vector<int> temp = generateRow(i);
        ans.push_back(temp);
    }

    for(auto it : ans)
    {
        for(auto k : it)
        {
            cout << k << " ";
        }
        cout << endl;
    }

    // T.C => O(n*n)
    // S.C => O(1)

    return 0;

}