// Remove duplicate inplace from sorted array
// Ex: arr[] = {1,1,2,2,2,3,3};
// ans = {1,2,3,2,2,3,3}, return unique elements which is 3

// Brute Force
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int arr[] = {1,1,2,2,2,3,3};
//     int n = sizeof(arr)/sizeof(arr[0]);

//     set<int> s;
//     for(int i = 0; i < n; ++i)
//     {
//         s.insert(arr[i]);    // (n log n)
//     }

//     int index = 0;
//     set<int> :: iterator it;
//     for(it = s.begin(); it != s.end(); it++)   // O(n)
//     {
//         arr[index] = (*it);
//         index++;
//     }

//     for(int ele : arr)
//     {
//         cout << ele << " ";
//     }
//     cout << endl;

//     // T.C => O(n log n) + O(n) 
//     // S.C => O(n) (worst case if all are unique)

//     cout << index << endl;
// }

// Optimized Approach (Two pointer Approach)
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1,1,2,2,2,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    int i = 0;
    for(int j = 1;j < n; ++j)  // O(n)
    {
        if(arr[j] != arr[i]){
            arr[i+1] = arr[j];
            i++;
        }
    }

    // T.C => O(n)

    cout << i + 1 << endl;
    return 0;
}