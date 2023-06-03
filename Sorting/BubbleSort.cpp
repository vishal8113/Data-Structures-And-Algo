// Bubble sort
// 4 3 7 1 5
// for(int i = 0; i < n; ++i)
//    for(int j = 0; j < n - i - 1; ++j)
//         if(arr[j+ 1] < arr[j]){
//             swap(arr[j+1],arr[j])
           //}
//       };          

// swap(a,b)//
// i = 0,j = 0,arr[1] < arr[0],3 4 7 1 5
// i = 0,j = 1, arr[2] < arr[1],No swap
// i = 0, j = 2, arr[3] < arr[2],3 4 1 7 5
// i = 0, j = 3, arr[4] < arr[3],3 4 1 5 7

// i = 1,j = 0, arr[1] < arr[0],No swap
// i = 1, j = 1, arr[2] < arr[1],3 1 4 5 7
// i = 1, j = 2, arr[3] < arr[2],No swap

// i = 2,j = 0,arr[1] < arr[0],1 3 4 5 7
// i = 2,j = 1, arr[2] < arr[1],No swap

// i = 3,j = 0,arr[1] < arr[0],No swap
// 1 3 4 5 7

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 5;
    int arr[] = {4,3,7,1,5};

    for(int i = 0; i < n; ++i)
    {
        bool isSwapped = false;
        for(int j = 0; j < n - i - 1; ++j)
        {
            if(arr[j + 1] < arr[j])
            {
                swap(arr[j + 1],arr[j]);
                isSwapped = true;
            }
        }

        if(isSwapped == false)
        {
            break;
        }
    }

    for(auto k : arr)
    {
        cout << k << endl;
    }

    return 0;
}