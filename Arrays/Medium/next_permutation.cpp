// find the next permutation of given array
// ex : [3,1,2] ,ans = 3,2,1

// Better Solution using c++ stl

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {3,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    next_permutation(arr,arr+n);  // O(n)

    for(int ele : arr)
    {
        cout << ele << " ";
    }
    return 0;
}


// Implementation of next_permutation

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {3,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    int idx = -1;

    for(int i = n - 2; i >= 0; --i)
    {
        if(arr[i] < arr[i+1])
        {
            idx = i;
            break;
        }
    }

    for(int i = n - 1; i > idx; --i)
    {
        if(arr[i] > arr[idx]){
            swap(arr[i],arr[idx]);
            break;
        }
    }

    reverse(arr + (idx+1),arr+n);

    if(idx == -1)
    {
        reverse(arr,arr+n);
    }

    for(int ele : arr)
    {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}


