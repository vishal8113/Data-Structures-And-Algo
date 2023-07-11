// find median in a row wsie sorted matrix

#include<bits/stdc++.h>
using namespace std;

int findSmallerElements(vector<vector<int>> &matrix,int assumedMedian){
    int cntSmallerEle = 0;
    for(int i = 0; i < matrix.size(); ++i)
    {
        int start = 0;
        int end = matrix[i].size() - 1;

        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(matrix[i][mid] <= assumedMedian){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        cntSmallerEle += start;
    }

    return cntSmallerEle;
}

int main()
{
    vector<vector<int>> matrix = {
        {1,3,5},
        {2,6,9},
        {3,6,9}
    };

    int n = matrix.size();
    int m = matrix[0].size();

    int N = n*m;

    int medianIndex = N/2;

    int start = 1;
    int end = 2000;

    while(start <= end)
    {
        int assumedMedian = start + (end - start)/2;
        int lessEle = findSmallerElements(matrix,assumedMedian);

        if(lessEle <= medianIndex)
        {
            start = assumedMedian + 1;
        }else{
            end = assumedMedian - 1;
        }
    }

    cout << start << endl;

    // T.C => O(log2000)*(log(n+m))
    // S.C => O(1)
    return 0;
}
