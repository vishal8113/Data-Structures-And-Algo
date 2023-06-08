// arr = {1,1,0,1,1,1,0,1,1};
// ans = 3

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1,1,0,1,1,1,0,1,1};  // O(n)
    int n = sizeof(arr)/sizeof(arr[0]);

    int cnt = 0;
    int maxi = 0;
    for(int i = 0; i < n; ++i)
    {
        if(arr[i] == 1)
        {
            cnt++;
            maxi = max(maxi,cnt);
        } else {
            cnt = 0;
        }
        
    }

    // T.C => O(n)
    // S.C => O(1)

    cout << maxi << endl;
    return 0;
}