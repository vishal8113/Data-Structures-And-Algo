// Quick Sort
// Time Complexity -> O(nlogn) -> Best,Average
// Worst -> O(n^2)
// Space Complexity -> O(1)

#include<bits/stdc++.h>
using namespace std;
int findPartitionIndex(int* arr,int low,int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i < j)
    {
        while(arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }

        while(arr[j] > pivot && j >= low + 1)
        {
            j--;
        }

        if(i < j)
        {
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[low],arr[j]);
    return j;
}
void quickSort(int* arr,int low,int high)
{
    if(low >= high)
    {
        return;
    }

    int partitionIndex = findPartitionIndex(arr,low,high);
    quickSort(arr,low,partitionIndex-1);
    quickSort(arr,partitionIndex+1,high);

}
int main()
{
    int arr[] = {5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int low = 0;
    int high = n - 1;

    quickSort(arr,low,high);

    for(int ele : arr)
    {
        cout << ele << " ";
    }

    return 0;
}