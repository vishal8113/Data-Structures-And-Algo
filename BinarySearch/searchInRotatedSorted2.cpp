// search in rotated sorted array , (unique elements)
// ex: arr[] = {3,1,3,3,3,3}
// target = 3 
// ans = yes

#include<bits/stdc++.h>
using namespace std;

bool isFound(int* arr,int n,int target)
{
    int start = 0;
    int end = n - 1;

    while(start <= end)
    {
        int mid = start + (end - start)/2;

        if(arr[mid] == target)
        {
            return true;
        }

        if(arr[start] == arr[mid] && arr[mid] == arr[end])
        {
            start++;
            end--;
        } else if(arr[start] <= arr[mid])
        {
            if(arr[start] <= target && target <= arr[mid])
            {
                end = mid - 1;
            }else {
                start = mid + 1;
            }
        }else {
            if(arr[mid] <= target && target <= arr[end])
            {
                start = mid + 1;
            }else {
                end = mid - 1;
            }
        }

        
    }

    return false;
}

int main()
{
    int arr[] = {3,1,3,3,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    bool ans = isFound(arr,n,3);

    cout << ans << endl;

    // T.C => O(n) (worst case)
    // S.C => O(1)
    return 0;
}
