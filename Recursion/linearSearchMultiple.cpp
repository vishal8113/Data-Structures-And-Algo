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

    return search(arr,n,target,++i);
}
int main()
{
    int arr[] = {12,45,67,45,55,67,11};
    int n = 7;
    int target = 45;
    int i = 0;

    cout << search(arr,n,target,i);
    return 0;
}