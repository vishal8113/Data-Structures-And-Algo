// Find missing number in an array , n = 5, n-1 (numbers)
// arr = {1,2,4,5};, 1 to N Numbers

// // Brute force
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n = 5;
//     int arr[] = {1,2,4,5};
//     for(int i = 1; i <= n; ++i)
//     {
//         int flag = 0;
//         for(int j = 0; j < n - 1; ++j)
//         {
//             if(arr[j] == i){
//                 flag = 1;
//                 break;
//             }
//         }

//         if(flag == 0)
//         {
//             cout << i << endl;
//         }
//     }

//     // T.C => O(n^2)
//

// Optimal Solution
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int arr[] = {1,2,4,5};
//     int n = 5;

//     int hash[n+1] ={0};  // o(N)
//     for(int i = 0; i < n - 1; ++i)  // O(N)
//     {
//         hash[arr[i]] = 1;
//     }

//     for(int i = 1; i <= n; ++i)  // O(N)
//     {
//         if(hash[i] == 0)
//         {
//             cout << i << endl;
//         }
//     }

//     // T.C => O(2N)
//     // S.C => O(N)
//     return 0;
// }

// Optimized Approach
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n = 5;
//     int arr[] = {1,2,4,5};

//     int sum = (n*(n+1))/2;

//     int arrSum = 0;
//     for(int i = 0; i < n - 1; ++i)  // O(n)
//     {
//         arrSum+=arr[i];
//     }

//     int diff = sum - arrSum;
//     cout << diff << endl;

//     // T.C => O(n)
//     // S.C => O(1)
//     return 0;
// }

// More optimized approach
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n = 5;
//     int arr[] = {1,2,4,5};

//     int xor1 = 0;
//     // for(int i = 1; i <= n; ++i)
//     // {
//     //     xor1^=i;
//     // }

//     int xor2 = 0;
//     for(int i = 0; i < n - 1; ++i)
//     {
//         xor2^=arr[i];
//         xor1^=(i+1);
//     }
//     xor1^=n;

//     int ans = xor1^xor2;
//     cout << ans << endl;

//     // T.C => O(2N) => O(N) (More better because never exceed int limit)
//     // s.C => O(1)
//     return 0;
// }

// Cyclic Sort Approach
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 5;
    int arr[] = {4,3,1,2};

    int i = 0;
    while(i < n-1)  // O(n)
    {
        if(arr[i] == n)
        {
            i++;
        }
        int correctIndex = arr[i] - 1;
        if(i != correctIndex)
        {
            swap(arr[i],arr[correctIndex]);
        }else {
            i++;
        }

    }
    
    int count = 0;
    int k;
    bool printed = false;
    for(k = 0; k < n- 1; ++k) // On
    {
        if(arr[i] != n)
        {
            count++;
        }

        if(arr[k] == k + 1)
        {
            continue;
        }else {
            cout << k + 1 << endl;
            printed = true;
        }
        
    }

    if(count == k && printed == false)
    {
        cout << n << endl;
    }

    // T.C => O(n) + O(n) => O(2n)
    // S.C => O(1)

    return 0;
}