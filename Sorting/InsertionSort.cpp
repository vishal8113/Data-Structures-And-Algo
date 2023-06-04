#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {5,3,4,1,2};
    int n = 5;

    for(int i = 0; i < n - 1; ++i)
    {
        for(int j = i + 1; j > 0; --j)
        {
            if(arr[j] < arr[j - 1])
            {
                swap(arr[j],arr[j-1]);
            }else {
                break;
            }
        }
    }

    for(int ele : arr)
    {
        cout << ele << endl;
    }
    return 0;
}
