#include<bits/stdc++.h>
using namespace std;
void reverse(int* arr,int n,int start,int end)
{
    if(start > end)
    {
        return;
    }

    swap(arr[start],arr[end]);
    reverse(arr,n,++start,--end);
}
int main()
{
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int start = 0;
    int end = n - 1;

    reverse(arr,n,start,end);

    for(int ele : arr)
    {
        cout << ele << " ";
    }
    return 0;
}