#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 5;
    int arr[] = {8,0,7,1,3};

    for(int i = 0; i < n - 1; ++i)
    {
        int min = i;
        for(int j = i; j < n; ++j)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[min],arr[i]);
    }

    for(int ele : arr)
    {
        cout << ele << endl;
    }
    return 0;
}