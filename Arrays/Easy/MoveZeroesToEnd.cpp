// Move all zeroes to the end of the array
// arr = {2,0,1,5,0,3,0,9,5,0,1};
// {2,1,5,3,9,5,1,0,0,0,0}

// Brute Force
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {2,0,1,5,0,3,0,9,5,0,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    // vector<int> temp;
    // for(int i = 0; i < n; ++i)  // O(n)
    // {
    //     if(arr[i] != 0)
    //     {
    //         temp.push_back(arr[i]);
    //     }
    // }
    
    // int nz = 0;
    // for(int i = 0; i < temp.size(); ++i)  // O(x)
    // {
    //     arr[i] = temp[i];
    //     nz++;
    // }

    // for(int i = nz; i < n; ++i)  //O(n-x)
    // {
    //     arr[i] = 0;
    // }

    // T.C => O(n) + O(x) + O(n-x) => O(2N)
    // S.C => O(x)


    // Optimal Solution

    int j = -1;
    for(int i = 0; i < n; ++i)  // O(x)
    {
        if(arr[i] == 0) 
        {
            j = i;
            break;
        }
    }

    for(int i = j + 1;i < n; ++i)  // O(n-x)
    {
        if(arr[i] != 0)
        {
            swap(arr[i],arr[j]);
            j++;
        }
    }

    // T.C => O(x) + O(n-x) => O(n)
    // S.C => O(1)

    for(int ele : arr)
    {
        cout << ele << " ";
    }



    return 0;
}

// 2 0 1 5 0 3 0 9 5 0 1
//   j i
// 2 1 0 5 0 3 0 9 5 0 1
//     j i
// 2 1 5 0 0 3 0 9 5 0 1
//       j i    
// 2 1 5 0 0 3 0 9 5 0 1
//       j   i    
// 2 1 5 3 0 0 0 9 5 0 1
//         j   i  
// 2 1 5 3 0 0 0 9 5 0 1  
//         j     i
// 2 1 5 3 9 0 0 0 5 0 1
//           j     i  
// 2 1 5 3 9 5 0 0 0 0 1
//             j     i  
// 2 1 5 3 9 5 0 0 0 0 1
//             j       i
// 2 1 5 3 9 5 1 0 0 0 0