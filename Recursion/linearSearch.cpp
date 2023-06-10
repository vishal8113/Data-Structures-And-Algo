#include<bits/stdc++.h>
using namespace std;
int search(int arr[],int n,int target,int i)
{
    if(i >= n)
    {
        return -1;
    }
    if(arr[i] == target)
    {
        return i;
    }

    return search(arr,n,target,i+1);
}
int main()
{
    int arr[] = {23,11,89,33,10};
    int n = 5;
    int target = 33;
    int i = 0;

    cout << search(arr,n,target,i);
    return 0;
}