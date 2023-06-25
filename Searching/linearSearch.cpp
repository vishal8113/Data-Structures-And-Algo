// linear search in an array
// T.C => O(n)
// S.C => O(1)

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {5,3,9,8,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    int target = 8;

    for(int i = 0; i < n; ++i)
    {
        if(arr[i] == target){
            cout << i << endl;
            break;
        }
    }

    
    return 0;
}