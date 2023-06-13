#include<bits/stdc++.h>
using namespace std;
void bSort(int* arr,int n)
{
    if(n == 1)
    {
        return;
    }
    for(int i = 0; i < n - 1; ++i)
    {
        if(arr[i] > arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }

    bSort(arr,n-1);
}
int main()
{
    int arr[] = {5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    bSort(arr,n);

    for(int e : arr)
    {
        cout << e << " ";
    }
    cout << endl;
    
    return 0;
}