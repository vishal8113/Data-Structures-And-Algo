// count the no. of subsequences with sum k

// int f()
// base case , return 1 , if satisfied
// return 0 , if not satisfied

// l = f()
// r = f()

// return l + r;

// n function calls
// s = 0
// for(i = 1 -> n)
// {
  // s = f();
// }
// return s;

#include<bits/stdc++.h>
using namespace std;

int sequenceSum(int index,int s,int sum,int arr[],int n)
{
    // Base case
    if(index == n)
    {
        if(s == sum){
            return 1;
        }

        return 0;
    }

    s += arr[index];

    int left = sequenceSum(index+1,s,sum,arr,n);

    s -= arr[index];

    int right = sequenceSum(index+1,s,sum,arr,n);

    return left + right;
}

int main()
{
    int arr[] = {1,2,1};
    int n = 3;
    int sum = 2;
    int ans = sequenceSum(0,0,sum,arr,n);
    cout << ans << endl;

    // T.C => O(2^N)
    // S.C => O(N)
    return 0;
}