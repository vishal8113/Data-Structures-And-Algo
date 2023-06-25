// Binary Search (works only in sorted array)
// T.C => O(logn)
// S.C => o(1)

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {3,6,8,9,10,12,15};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 13;

    int start = 0;
    int end = n - 1;

    bool isFound = false;

    while(start <= end)
    {
        int mid = start + (end - start) / 2;
        if(arr[mid] == target){
            cout << mid << endl;
            isFound = true;
            break;
        } else if(arr[mid] < target){
            start = mid + 1;
        }else {
            end = mid - 1;
        }
    }

    if(!isFound)
    {
        cout << -1 << endl;
    }
    return 0;
}