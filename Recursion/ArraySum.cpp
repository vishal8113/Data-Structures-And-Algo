#include<bits/stdc++.h>
using namespace std;
int arraySum(int* arr,int n)
{
    if(n == 0)
    {
        return 0;
    }
    return arraySum(arr,n-1) + n;
}
int main()
{
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << arraySum(arr,n);
    return 0;
}