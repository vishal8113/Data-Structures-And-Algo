// search in a 2d matrix

#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> matrix = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };

    bool ans = false;

    int n = matrix.size();
    int m = matrix[0].size();

    int target = 34;

    int start = 0;
    int end = (n*m)-1;

    while(start <= end)
    {
        int mid = start + (end - start)/2;

        if(matrix[mid/m][mid%m] == target)
        {
            ans = true;
            break;
        }else if(matrix[mid/m][mid%m] < target)
        {
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }

    if(ans)
    {
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }

    // T.C => O(log(n*m))
    // S.C => O(1)
    return 0;
}